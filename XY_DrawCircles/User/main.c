
/*=================================测试程序================================*/
/*
* 本程序用于测试3D打印机XY轴联动功能。
* 它可以让XY轴重复画圆圈。如果打印机XY轴安装不合理可能会导致电机卡住。
*
* 本程序实现了一个基于DDA算法的圆弧插补，控制两轴步进电机绘制一个半径为50mm的圆。
* 
* 使用STM32F103C8T6单片机，搭配A4988步进电机驱动模块，连接X、Y轴步进电机。
* 步进电机步距角是0.9°，驱动采用全步进（无细分，A4988的MS1、MS2、MS3引脚直接悬空
* 就行，减少繁琐的接线）。SLEEP，RESET和VDD接3.3V高电平，VMOT接24V电源。单片机3.3V供电。
* 注意单片机和驱动模块的电源共地。
* Keil5工程，基于标准库。下方所有程序均由AI生成。
*                                                       0xC0FFEE_ZY
*                                                       2026.5.18
*/

#include "stm32f10x.h"

/* ---------- 引脚定义 ---------- */
#define X_STEP_PIN    GPIO_Pin_0
#define X_DIR_PIN     GPIO_Pin_1
#define X_EN_PIN      GPIO_Pin_2
#define X_PORT        GPIOA

#define Y_STEP_PIN    GPIO_Pin_3
#define Y_DIR_PIN     GPIO_Pin_4
#define Y_EN_PIN      GPIO_Pin_5
#define Y_PORT        GPIOA

/* ---------- 机械参数 ---------- */
#define RADIUS_MM     50
#define PULSE_PER_MM  10            // 0.1mm/脉冲
#define RADIUS_PULSE  (RADIUS_MM * PULSE_PER_MM) // 500
#define ACC_MAX       1024          // 累加器上限（2^10，需 > 2*R）
#define TIM_PERIOD    750          // 插补频率 ≈ 1333.33 Hz

/* 方向电平宏（根据实际接线可调整） */
#define X_DIR_POSITIVE   Bit_SET
#define X_DIR_NEGATIVE   Bit_RESET
#define Y_DIR_POSITIVE   Bit_SET
#define Y_DIR_NEGATIVE   Bit_RESET

/* ---------- 全局变量（全部 volatile） ---------- */
volatile int32_t X = RADIUS_PULSE;   // 当前X坐标（脉冲数）
volatile int32_t Y = 0;              // 当前Y坐标
volatile int32_t X_acc = 0;          // X积分累加器
volatile int32_t Y_acc = 0;          // Y积分累加器
volatile uint8_t quadrant = 0;       // 当前象限：0=I,1=II,2=III,3=IV
volatile uint8_t started = 0;        // 是否离开起点

/* 简易微秒延时 */
static void delay_us(uint32_t us) {
    while (us--) {
        for (volatile int i = 0; i < 8; i++) __NOP();
    }
}

/* 根据象限设置X、Y的方向（在脉冲输出前调用） */
static void set_dir_by_quadrant(void) {
    switch (quadrant) {
        case 0: // 第一象限：X负，Y正
            GPIO_WriteBit(X_PORT, X_DIR_PIN, X_DIR_NEGATIVE);
            GPIO_WriteBit(Y_PORT, Y_DIR_PIN, Y_DIR_POSITIVE);
            break;
        case 1: // 第二象限：X负，Y负
            GPIO_WriteBit(X_PORT, X_DIR_PIN, X_DIR_NEGATIVE);
            GPIO_WriteBit(Y_PORT, Y_DIR_PIN, Y_DIR_NEGATIVE);
            break;
        case 2: // 第三象限：X正，Y负
            GPIO_WriteBit(X_PORT, X_DIR_PIN, X_DIR_POSITIVE);
            GPIO_WriteBit(Y_PORT, Y_DIR_PIN, Y_DIR_NEGATIVE);
            break;
        case 3: // 第四象限：X正，Y正
            GPIO_WriteBit(X_PORT, X_DIR_PIN, X_DIR_POSITIVE);
            GPIO_WriteBit(Y_PORT, Y_DIR_PIN, Y_DIR_POSITIVE);
            break;
    }
}

/* 根据当前坐标更新象限（坐标更新后调用） */
static void update_quadrant(int32_t x, int32_t y) {
    if (x > 0 && y >= 0)        quadrant = 0;
    else if (x <= 0 && y > 0)   quadrant = 1;
    else if (x < 0 && y <= 0)   quadrant = 2;
    else if (x >= 0 && y < 0)   quadrant = 3;
    // 在坐标轴上归属明确，避免歧义
}

/* 定时器2中断：DDA圆弧插补 */
void TIM2_IRQHandler(void) {
    if (TIM_GetITStatus(TIM2, TIM_IT_Update) == RESET) return;
    TIM_ClearITPendingBit(TIM2, TIM_IT_Update);

    // 1. 读取当前坐标
    int32_t x_now = X;
    int32_t y_now = Y;

    // 2. 被积函数：Jx = |Y|，Jy = |X|
    int32_t Jx = (y_now >= 0) ? y_now : -y_now;
    int32_t Jy = (x_now >= 0) ? x_now : -x_now;

    // 3. 累加并检测溢出
    uint8_t x_pulse = 0, y_pulse = 0;
    X_acc += Jx;
    if (X_acc >= ACC_MAX) {
        X_acc -= ACC_MAX;
        x_pulse = 1;
    }
    Y_acc += Jy;
    if (Y_acc >= ACC_MAX) {
        Y_acc -= ACC_MAX;
        y_pulse = 1;
    }

    // 4. 输出脉冲（先设置方向，再发脉冲）
    if (x_pulse || y_pulse) {
        set_dir_by_quadrant();  // 基于旧象限的方向

        if (x_pulse) {
            GPIO_SetBits(X_PORT, X_STEP_PIN);
            delay_us(2);
            GPIO_ResetBits(X_PORT, X_STEP_PIN);
        }
        if (y_pulse) {
            GPIO_SetBits(Y_PORT, Y_STEP_PIN);
            delay_us(2);
            GPIO_ResetBits(Y_PORT, Y_STEP_PIN);
        }

        // 5. 更新坐标（根据当前象限方向）
        if (x_pulse) {
            if (quadrant == 0 || quadrant == 1)  x_now--;  // 负方向
            else                                  x_now++;
        }
        if (y_pulse) {
            if (quadrant == 0 || quadrant == 3)  y_now++;  // 正方向
            else                                  y_now--;
        }

        X = x_now;
        Y = y_now;

        // 6. 更新象限，供下次使用
        update_quadrant(x_now, y_now);
    }

    // 7. 检测整圆完成（回到起点）
    if (X != RADIUS_PULSE || Y != 0) started = 1;
    if (started && X == RADIUS_PULSE && Y == 0) {
        TIM_Cmd(TIM2, DISABLE);  // 停止插补
    }
}

/* GPIO初始化 */
static void GPIO_Config(void) {
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitTypeDef g = {
        .GPIO_Speed = GPIO_Speed_50MHz,
        .GPIO_Mode = GPIO_Mode_Out_PP,
        .GPIO_Pin = X_STEP_PIN | X_DIR_PIN | X_EN_PIN
    };
    GPIO_Init(GPIOA, &g);
    g.GPIO_Pin = Y_STEP_PIN | Y_DIR_PIN | Y_EN_PIN;
    GPIO_Init(GPIOA, &g);

    // 初始状态：STEP低，EN低（使能）
    GPIO_ResetBits(X_PORT, X_STEP_PIN | X_EN_PIN);
    GPIO_ResetBits(Y_PORT, Y_STEP_PIN | Y_EN_PIN);
}

/* 定时器2初始化 */
static void TIM2_Config(void) {
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
    TIM_TimeBaseInitTypeDef t = {
        .TIM_Period = TIM_PERIOD - 1,
        .TIM_Prescaler = 72 - 1,     // 72MHz -> 1MHz
        .TIM_ClockDivision = TIM_CKD_DIV1,
        .TIM_CounterMode = TIM_CounterMode_Up
    };
    TIM_TimeBaseInit(TIM2, &t);
    TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);

    NVIC_InitTypeDef n = {
        .NVIC_IRQChannel = TIM2_IRQn,
        .NVIC_IRQChannelPreemptionPriority = 0,
        .NVIC_IRQChannelSubPriority = 1,
        .NVIC_IRQChannelCmd = ENABLE
    };
    NVIC_Init(&n);
    TIM_Cmd(TIM2, ENABLE);
}

int main(void) {
    GPIO_Config();
    TIM2_Config();
    while (1) __WFI();
}