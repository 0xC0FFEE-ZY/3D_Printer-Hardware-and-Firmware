  /**
   * Marlin 3D Printer Firmware
   * Copyright (c) 2022 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
   *
   * Based on Sprinter and grbl.
   * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
   *
   * This program is free software: you can redistribute it and/or modify
   * it under the terms of the GNU General Public License as published by
   * the Free Software Foundation, either version 3 of the License, or
   * (at your option) any later version.
   *
   * This program is distributed in the hope that it will be useful,
   * but WITHOUT ANY WARRANTY; without even the implied warranty of
   * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   * GNU General Public License for more details.
   *
   * You should have received a copy of the GNU General Public License
   * along with this program.  If not, see <https://www.gnu.org/licenses/>.
   *
   */
// ================================== 上方为 Marlin原始版权声明 ==================================
  /**
 * Copyright (C) 2026 [0xC0FFEE_ZY]
 * 此为本人自制的3D打印机主板的引脚文件。
 * 主板的引脚资源分配均为自定义，没有使用商品主板方案，因此需要在Marlin中新建引脚映射头文件。
 * 基于Marlin固件（Copyright (C)  Camiel Gubbels / Erik van der Zalm / MarlinFirmware ，GPLv3许可）
 * 本文件同样遵循GPLv3许可
 * 如引用、转载或分发，须保留本版权声明和署名 
 * 本人项目开源仓库：https://github.com/0xC0FFEE-ZY/3D_Printer-Hardware-and-Firmware
 *                                                
 *                                                                      2026.6.30  By 0xC0FFEE_ZY
 * 
 * 
 * 0xC0FFEE_ZY 主板引脚定义
 * ============================
 * 硬件平台:  STM32F407VET6 (LQFP-100, 512KB Flash)
 * 运动架构:  UM 双轴 (X/X2, Y/Y2, Z/Z2 独立使能)
 * 挤出机:    1 个 (E0)
 * 驱动器:    7 × TMC2209 (UART模式, 软件串口)
 * 归零方式:  XY轴无传感器归零，Z轴使用限位开关归零
 * 屏幕:      MKS TFT35 串口屏 (USART6: PC6/PC7, 4线: RX/TX/5V/GND)
 * 调平:      3DTouch (5*5网格补偿, 探针信号 PD10)
 *
 * 引脚分配概览:
 *   串口: USB_CDC(调试) + USART1(WiFi) + USART6(TFT35)
 *   加热: HEATER_0(PB1) + HEATER_BED(PB10)
 *   测温: TEMP_0(PC1) + TEMP_BED(PC0)
 *   风扇: FAN0(PA2) + FAN1(PA1)
 *   SD卡: SPI3 (PC9-PC12, PC4检测)
 *   EEPROM:
 * 
 */





#pragma once                // 头文件保护指令

#define ALLOW_STM32DUINO    // 主板基于 STM32 ，使用 STM32duino 核心库
#include "env_validate.h"   // 引入环境验证头文件，在编译时做合法性检查


#if HOTENDS > 1 || E_STEPPERS > 1
    #error "0xC0FFEE_ZY supports up to 1 hotends and 1 E steppers."  // 我的自制主板只支持一个喷嘴和一个挤出机
#elif HAS_FSMC_TFT
    #error "0xC0FFEE_ZY doesn't support FSMC-based TFT displays."
#endif

//串口屏TX PA9 RX PA10
//=============================================================================
// 步进电机驱动引脚(双X 双Y 双Z 一个挤出机E0)
//=============================================================================
// 注意：我的自制主板专门为 TMC2209 等驱动设计，使用 UART 模式，不支持 TMC5130 等驱动使用SPI通讯功能，主板硬件电路没有引出SPI通讯走线。
#define X_ENABLE_PIN                         PC15
#define X_STEP_PIN                           PC13
#define X_DIR_PIN                            PE4
#define X_SERIAL_TX_PIN                      PC14

#define X2_ENABLE_PIN                        PE2
#define X2_STEP_PIN                          PE0
#define X2_DIR_PIN                           PB9
#define X2_SERIAL_TX_PIN                     PE1

#define Y_ENABLE_PIN                         PB8
#define Y_STEP_PIN                           PB6
#define Y_DIR_PIN                            PB5
#define Y_SERIAL_TX_PIN                      PB7

#define Y2_ENABLE_PIN                        PB3
#define Y2_STEP_PIN                          PD6
#define Y2_DIR_PIN                           PD5
#define Y2_SERIAL_TX_PIN                     PD7

#define Z_ENABLE_PIN                         PD4
#define Z_STEP_PIN                           PD2
#define Z_DIR_PIN                            PD1
#define Z_SERIAL_TX_PIN                      PD3

#define Z2_ENABLE_PIN                        PC12
#define Z2_STEP_PIN                          PC10
#define Z2_DIR_PIN                           PA15
#define Z2_SERIAL_TX_PIN                     PC11

#define E0_ENABLE_PIN                        PC9
#define E0_STEP_PIN                          PD15
#define E0_DIR_PIN                           PD14
#define E0_SERIAL_TX_PIN                     PC8

  #ifndef TMC_BAUD_RATE
    #define TMC_BAUD_RATE                  19200  // 波特率
  #endif
// TMC2209 数据手册的默认 UART 波特率是 115200，但是我的自制主板上的 TMC2209 UART模式 使用软件模拟串口，在高速下时序不够精准，容易通信失败。所以波特率降到 19200
// 关于软件串口和硬件串口，可以去看看Chinese_Version_Configured_Marlin2.1.3\Marlin\Configuration.h 第309-316行的 “译者注” ，或许会对你有些帮助。


//=============================================================================
// DIAG 无传感器归零以及限位开关引脚
//=============================================================================
#define X_STOP_PIN                          PE3    // X 轴我使用 TMC2209 的 DIAG 功能归零
#define Y_STOP_PIN                          PB4    // Y 轴我使用 TMC2209 的 DIAG 功能归零
#define Z_MIN_PIN                           PA8    // Z 轴我使用限位开关检测归零
#define Z2_MIN_PIN                          PD13



//=============================================================================
// 喷嘴、热床、风扇
//=============================================================================
#define HEATER_0_PIN                        PC7   // 喷嘴加热控制 (PWM)
#define HEATER_BED_PIN                      PC6   // 热床加热控制 (PWM)

#define TEMP_0_PIN                          PC0   // 喷嘴处温度传感器
#define TEMP_1_PIN                          PC1   // 腔体温度传感器
#define TEMP_BED_PIN                        PC2   // 热床处温度传感器

#define FAN0_PIN                            PE5  // 模型冷却风扇
#define FAN1_PIN                            PE6  // 喷嘴喉管风扇
#define FAN2_PIN                            PA7  // 腔体风扇




//=============================================================================
// EEPROM
//=============================================================================
// Marlin 的配置数据（Z 偏移、PID 参数、E 步进校准值、调平网格等）需要非易失存储，断电不丢。配置参数我选择存在EEPROM里，自制主板中集成了一片
#define I2C_EEPROM
#define MARLIN_EEPROM_SIZE               0x1000U  // 4K
#define I2C_SCL_PIN                         PB10  // I2C_SCL
#define I2C_SDA_PIN                         PB11  // I2C_SDA



//=============================================================================
// BLTouch(3DTouch)
//=============================================================================
#define SERVO0_PIN                          PA6    // BLTouch 探针收放控制 (PWM)
#define Z_MIN_PROBE_PIN                     PA5   // 探针触发信号（独立引脚，不共用 Z 限位）
// 3DTOUCH 内部有一个小舵机来伸缩探针，Marlin 通过 SERVO0_PIN 这个引脚发送 PWM 信号来控制它
#if ENABLED(PROBE_ENABLE_DISABLE) && !defined(PROBE_ENABLE_PIN)
  #define PROBE_ENABLE_PIN            SERVO0_PIN
#endif



//=============================================================================
// 断料检测
//=============================================================================
#ifndef FIL_RUNOUT_PIN
  #define FIL_RUNOUT_PIN                    PA4
#endif



//=============================================================================
// 板子信息
//=============================================================================
#define BOARD_INFO_NAME "0xC0FFEE_ZY"
#define BOARD_NEOPIXEL_PIN                  P   