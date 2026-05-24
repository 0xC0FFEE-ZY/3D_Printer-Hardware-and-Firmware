/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
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
#pragma once


/*
==============================================================================================================
===============================================   前   言   ==================================================
==============================================================================================================

*本工程为Marlin 2.1.3-beta3的中文翻译版本，由0xC0FFEE_ZY翻译。原版工程来自https://github.com/MarlinFirmware/Marlin
*本工程各项参数已配置完成，适用于本人自制的3D打印机（基于UM架构），
*该3D打印机设计图纸，硬件原理图，PCB已全部开源,未来预计更新制作教程至抖音/B站。
*开源项目见本人Github主页：https://github.com/0xC0FFEE-ZY
*欢迎关注本人抖音：（抖音号:Technophilic)，昵称：0xC0FFEE_ZY，里面有一些电子科技创作相关的视频，欢迎大家点赞关注！谢谢！
*B站UID:481302692，昵称：0xC0FFEE_ZY
*up为2024级本科生，热爱电子科技，欢迎和我一起进行讨论和交流！

本页为Marlin固件进阶配置

                                                                                  2026.5.21     By 0xC0FFEE_ZY

==============================================================================================================
*/

/**
 * Configuration_adv.h
 *
 * Advanced settings.
 * Only change these if you know exactly what you're doing.
 * Some of these settings can damage your printer if improperly set!
 *
 * Basic settings can be found in Configuration.h
 * 
 * 高级设置文件。
 * 仅在你完全清楚自己在做什么时，才修改这些参数。
 * 其中部分参数如果设置不当，可能会损坏你的打印机！
 *
 * 基础设置请在 Configuration_h 文件中查找。
 */
#define CONFIGURATION_ADV_H_VERSION 02010300

// @section develop

/**
 * Configuration Export
 *
 * Export the configuration as part of the build. (See signature.py)
 * Output files are saved with the build (e.g., .pio/build/mega2560).
 *
 * See `build_all_examples --ini` as an example of config.ini archiving.
 *
 *  1 = marlin_config.json - Dictionary containing the configuration.
 *      This file is also generated for CONFIGURATION_EMBEDDING.
 *  2 = config.ini - File format for PlatformIO preprocessing.
 *  3 = schema.json - The entire configuration schema. (13 = pattern groups)
 *  4 = schema.yml - The entire configuration schema.
 *  5 = Config.h - Minimal configuration by popular demand.
 * 
 * *配置导出
 *
 * 在编译固件时，将当前配置参数一起导出保存。（查看 signature.py）
 * 导出的文件会保存在固件编译目录中（例如：.pio/build/mega2560）。
 *
 * 参考 build_all_examples --ini 可查看 config.ini 归档示例。
 *
 *  1 = marlin_config.json - 包含完整配置参数的字典文件
 *      开启 CONFIGURATION_EMBEDDING 时也会生成此文件
 *  2 = config.ini - 用于 PlatformIO 预处理的配置文件格式
 *  3 = schema.json - 完整的配置参数规则定义（13 = 带分组模式）
 *  4 = schema.yml - 完整的配置参数规则定义
 *  5 = Config.h - 按常用需求生成的精简配置文件
 * 
 */
//#define CONFIG_EXPORT 105 // :[1:'JSON', 2:'config.ini', 3:'schema.json', 4:'schema.yml', 5:'Config.h']

//===========================================================================
//============================= Thermal Settings ============================
//===========================================================================
// 温度相关设置
// @section temperature

/**
 * Thermocouple sensors are quite sensitive to noise.  Any noise induced in
 * the sensor wires, such as by stepper motor wires run in parallel to them,
 * may result in the thermocouple sensor reporting spurious errors.  This
 * value is the number of errors which can occur in a row before the error
 * is reported.  This allows us to ignore intermittent error conditions while
 * still detecting an actual failure, which should result in a continuous
 * stream of errors from the sensor.
 *
 * Set this value to 0 to fail on the first error to occur.
 * 
 * 热电偶传感器对干扰非常敏感。
 * 传感器线路中产生的任何干扰（例如，步进电机电线与传感器线并行布线）
 * 都可能导致热电偶传感器报告虚假错误。
 * 该数值表示：在报告错误之前，允许**连续**发生多少次错误。
 * 这使我们能够忽略间歇性的干扰，同时仍能检测到真正的传感器故障
 * （真正的故障会导致传感器持续输出一连串错误）。
 *
 * 将此值设置为 0 表示：只要发生第一次错误就立即停机。
 */
#define THERMOCOUPLE_MAX_ERRORS 15

//
// Custom Thermistor 1000 parameters  // 自定义热敏电阻 1000 参数
//
#if TEMP_SENSOR_0 == 1000
  #define HOTEND0_PULLUP_RESISTOR_OHMS    4700 // Pullup resistor  // 上拉电阻
  #define HOTEND0_RESISTANCE_25C_OHMS   100000 // Resistance at 25C  // 25摄氏度时的电阻值
  #define HOTEND0_BETA                    3950 // Beta value  // Beta 值 (是温度探头（热敏电阻）最重要的参数之一)
  #define HOTEND0_SH_C_COEFF                 0 // Steinhart-Hart C coefficient  // 斯坦哈特-哈特 C 系数(高级温度曲线参数，用于让温度探头读数极度准确)
#endif

#if TEMP_SENSOR_1 == 1000
  #define HOTEND1_PULLUP_RESISTOR_OHMS    4700 // Pullup resistor  // 上拉电阻
  #define HOTEND1_RESISTANCE_25C_OHMS   100000 // Resistance at 25C  // 25摄氏度时的电阻值
  #define HOTEND1_BETA                    3950 // Beta value  // Beta 值 (是温度探头（热敏电阻）最重要的参数之一)
  #define HOTEND1_SH_C_COEFF                 0 // Steinhart-Hart C coefficient  // 斯坦哈特-哈特 C 系数(高级温度曲线参数，用于让温度探头读数极度准确)
#endif

#if TEMP_SENSOR_2 == 1000
  #define HOTEND2_PULLUP_RESISTOR_OHMS    4700 // Pullup resistor  // 上拉电阻
  #define HOTEND2_RESISTANCE_25C_OHMS   100000 // Resistance at 25C  // 25摄氏度时的电阻值
  #define HOTEND2_BETA                    3950 // Beta value  // Beta 值 (是温度探头（热敏电阻）最重要的参数之一)
  #define HOTEND2_SH_C_COEFF                 0 // Steinhart-Hart C coefficient  // 斯坦哈特-哈特 C 系数(高级温度曲线参数，用于让温度探头读数极度准确)
#endif

#if TEMP_SENSOR_3 == 1000
  #define HOTEND3_PULLUP_RESISTOR_OHMS    4700 // Pullup resistor  // 上拉电阻
  #define HOTEND3_RESISTANCE_25C_OHMS   100000 // Resistance at 25C  // 25摄氏度时的电阻值
  #define HOTEND3_BETA                    3950 // Beta value  // Beta 值 (是温度探头（热敏电阻）最重要的参数之一)
  #define HOTEND3_SH_C_COEFF                 0 // Steinhart-Hart C coefficient  // 斯坦哈特-哈特 C 系数(高级温度曲线参数，用于让温度探头读数极度准确)
#endif

#if TEMP_SENSOR_4 == 1000
  #define HOTEND4_PULLUP_RESISTOR_OHMS    4700 // Pullup resistor  // 上拉电阻
  #define HOTEND4_RESISTANCE_25C_OHMS   100000 // Resistance at 25C  // 25摄氏度时的电阻值
  #define HOTEND4_BETA                    3950 // Beta value  // Beta 值 (是温度探头（热敏电阻）最重要的参数之一)
  #define HOTEND4_SH_C_COEFF                 0 // Steinhart-Hart C coefficient  // 斯坦哈特-哈特 C 系数(高级温度曲线参数，用于让温度探头读数极度准确)
#endif

#if TEMP_SENSOR_5 == 1000
  #define HOTEND5_PULLUP_RESISTOR_OHMS    4700 // Pullup resistor  // 上拉电阻
  #define HOTEND5_RESISTANCE_25C_OHMS   100000 // Resistance at 25C  // 25摄氏度时的电阻值
  #define HOTEND5_BETA                    3950 // Beta value  // Beta 值 (是温度探头（热敏电阻）最重要的参数之一)
  #define HOTEND5_SH_C_COEFF                 0 // Steinhart-Hart C coefficient  // 斯坦哈特-哈特 C 系数(高级温度曲线参数，用于让温度探头读数极度准确)
#endif

#if TEMP_SENSOR_6 == 1000
  #define HOTEND6_PULLUP_RESISTOR_OHMS    4700 // Pullup resistor  // 上拉电阻
  #define HOTEND6_RESISTANCE_25C_OHMS   100000 // Resistance at 25C  // 25摄氏度时的电阻值
  #define HOTEND6_BETA                    3950 // Beta value  // Beta 值 (是温度探头（热敏电阻）最重要的参数之一)
  #define HOTEND6_SH_C_COEFF                 0 // Steinhart-Hart C coefficient  // 斯坦哈特-哈特 C 系数(高级温度曲线参数，用于让温度探头读数极度准确)
#endif

#if TEMP_SENSOR_7 == 1000
  #define HOTEND7_PULLUP_RESISTOR_OHMS    4700 // Pullup resistor  // 上拉电阻
  #define HOTEND7_RESISTANCE_25C_OHMS   100000 // Resistance at 25C  // 25摄氏度时的电阻值
  #define HOTEND7_BETA                    3950 // Beta value  // Beta 值 (是温度探头（热敏电阻）最重要的参数之一)
  #define HOTEND7_SH_C_COEFF                 0 // Steinhart-Hart C coefficient  // 斯坦哈特-哈特 C 系数(高级温度曲线参数，用于让温度探头读数极度准确)
#endif

#if TEMP_SENSOR_BED == 1000
  #define BED_PULLUP_RESISTOR_OHMS        4700 // Pullup resistor  // 上拉电阻
  #define BED_RESISTANCE_25C_OHMS       100000 // Resistance at 25C  // 25摄氏度时的电阻值
  #define BED_BETA                        3950 // Beta value  // Beta 值 (是温度探头（热敏电阻）最重要的参数之一)
  #define BED_SH_C_COEFF                     0 // Steinhart-Hart C coefficient  // 斯坦哈特-哈特 C 系数(高级温度曲线参数，用于让温度探头读数极度准确)
#endif

#if TEMP_SENSOR_CHAMBER == 1000
  #define CHAMBER_PULLUP_RESISTOR_OHMS    4700 // Pullup resistor  // 上拉电阻
  #define CHAMBER_RESISTANCE_25C_OHMS   100000 // Resistance at 25C  // 25摄氏度时的电阻值
  #define CHAMBER_BETA                    3950 // Beta value  // Beta 值 (是温度探头（热敏电阻）最重要的参数之一)
  #define CHAMBER_SH_C_COEFF                 0 // Steinhart-Hart C coefficient  // 斯坦哈特-哈特 C 系数(高级温度曲线参数，用于让温度探头读数极度准确)
#endif

#if TEMP_SENSOR_COOLER == 1000
  #define COOLER_PULLUP_RESISTOR_OHMS     4700 // Pullup resistor  // 上拉电阻
  #define COOLER_RESISTANCE_25C_OHMS    100000 // Resistance at 25C  // 25摄氏度时的电阻值
  #define COOLER_BETA                     3950 // Beta value  // Beta 值 (是温度探头（热敏电阻）最重要的参数之一)
  #define COOLER_SH_C_COEFF                  0 // Steinhart-Hart C coefficient  // 斯坦哈特-哈特 C 系数(高级温度曲线参数，用于让温度探头读数极度准确)
#endif

#if TEMP_SENSOR_PROBE == 1000
  #define PROBE_PULLUP_RESISTOR_OHMS      4700 // Pullup resistor  // 上拉电阻
  #define PROBE_RESISTANCE_25C_OHMS     100000 // Resistance at 25C  // 25摄氏度时的电阻值
  #define PROBE_BETA                      3950 // Beta value  // Beta 值 (是温度探头（热敏电阻）最重要的参数之一)
  #define PROBE_SH_C_COEFF                   0 // Steinhart-Hart C coefficient  // 斯坦哈特-哈特 C 系数(高级温度曲线参数，用于让温度探头读数极度准确)
#endif

#if TEMP_SENSOR_BOARD == 1000
  #define BOARD_PULLUP_RESISTOR_OHMS      4700 // Pullup resistor  // 上拉电阻
  #define BOARD_RESISTANCE_25C_OHMS     100000 // Resistance at 25C  // 25摄氏度时的电阻值
  #define BOARD_BETA                      3950 // Beta value  // Beta 值 (是温度探头（热敏电阻）最重要的参数之一)
  #define BOARD_SH_C_COEFF                   0 // Steinhart-Hart C coefficient  // 斯坦哈特-哈特 C 系数(高级温度曲线参数，用于让温度探头读数极度准确)
#endif

#if TEMP_SENSOR_REDUNDANT == 1000
  #define REDUNDANT_PULLUP_RESISTOR_OHMS  4700 // Pullup resistor  // 上拉电阻
  #define REDUNDANT_RESISTANCE_25C_OHMS 100000 // Resistance at 25C  // 25摄氏度时的电阻值
  #define REDUNDANT_BETA                  3950 // Beta value  // Beta 值 (是温度探头（热敏电阻）最重要的参数之一)
  #define REDUNDANT_SH_C_COEFF               0 // Steinhart-Hart C coefficient  // 斯坦哈特-哈特 C 系数(高级温度曲线参数，用于让温度探头读数极度准确)
#endif

/**
 * Thermocouple Options — for MAX6675 (-2), MAX31855 (-3), and MAX31865 (-5).  // 热电偶选项 —— 适用于 MAX6675（型号-2）、MAX31855（型号-3）和 MAX31865（型号-5）。
 */
//#define TEMP_SENSOR_FORCE_HW_SPI                // Ignore SCK/MOSI/MISO pins; use CS and the default SPI bus.  // 忽略 SCK/MOSI/MISO 引脚定义；直接使用 CS 引脚和默认 SPI 总线。
//#define MAX31865_SENSOR_WIRES_0   2             // (2-4) Number of wires for the probe connected to a MAX31865 board.  // (2-4) 连接到 MAX31865 模块的探头 引线数量。
//#define MAX31865_SENSOR_WIRES_1   2
//#define MAX31865_SENSOR_WIRES_2   2
//#define MAX31865_SENSOR_WIRES_BED 2

//#define MAX31865_50HZ_FILTER                    // Use a 50Hz filter instead of the default 60Hz.  // 使用 50Hz 滤波器，替代默认的 60Hz 滤波器。
// 注（译者注）：上面是温度传感器的抗干扰滤波设置，和你所在国家的市电频率有关。

//#define MAX31865_USE_READ_ERROR_DETECTION       // Treat value spikes (20°C delta in under 1s) as read errors.  // 将温度值突变（1秒内变化20°C）视为读取错误。

//#define MAX31865_USE_AUTO_MODE                  // Read faster and more often than 1-shot; bias voltage always on; slight effect on RTD temperature.  // 比单次读取模式更快、更频繁地读取温度；偏置电压始终开启；对 RTD 温度测量有轻微影响。
// 注（译者注）：上面是 MAX31865 + PT100/PT1000 高温探头 的专用设置：读取更快、更频繁：温度采样速度提升，反应更灵敏；偏置电压始终开启：电路一直保持通电状态；轻微影响 RTD 温度：会让温度读数稍微偏高一点点（可以忽略）

//#define MAX31865_MIN_SAMPLING_TIME_MSEC     100 // (ms) 1-shot: minimum read interval. Reduces bias voltage effects by leaving sensor unpowered for longer intervals.// (毫秒) 单次读取模式：最小读取间隔。通过延长传感器断电时间来减少偏置电压带来的误差。
//#define MAX31865_IGNORE_INITIAL_FAULTY_READS 10 // Ignore some read faults (keeping the temperature reading) to work around a possible issue (#23439).  // 忽略部分读取故障（继续读取温度），以规避一个已知问题（#23439）。

//#define MAX31865_WIRE_OHMS_0              0.95f // For 2-wire, set the wire resistances for more accurate readings.  // 对于两线制探头，设置导线电阻以获得更准确的读数。
//#define MAX31865_WIRE_OHMS_1              0.0f                                                                       // （译者注）：两线制探头因为线比较长，电线本身会有电阻，这会让测出来的温度偏高、不准。在这里填入你探头电线的实际电阻值，就能修正误差，让温度更准
//#define MAX31865_WIRE_OHMS_2              0.0f
//#define MAX31865_WIRE_OHMS_BED            0.0f

/**
 * Hephestos 2 24V heated bed upgrade kit.  // Hephestos 2 24V 热床升级套件
 * https://www.en3dstudios.com/product/bq-hephestos-2-heated-bed-kit/
 */
//#define HEPHESTOS2_HEATED_BED_KIT
#if ENABLED(HEPHESTOS2_HEATED_BED_KIT)
  #define HEATER_BED_INVERTING true
#endif

//
// Heated Bed Bang-Bang options  // 热床位式控温（通断式）相关选项(Bang-Bang控制)
//
#if DISABLED(PIDTEMPBED)
  #define BED_CHECK_INTERVAL 5000   // (ms) Interval between checks in bang-bang control  // (毫秒) 开关式（bang-bang）控温的 温度检测间隔
  #if ANY(BED_LIMIT_SWITCHING, PELTIER_BED)
    #define BED_HYSTERESIS 2        // (°C) Only set the relevant heater state when ABS(T-target) > BED_HYSTERESIS  // (°C) 仅当 绝对值(当前温度 - 目标温度) > 热床回差值 时，才切换加热器状态
  #endif                            // 这是热床开关控温（Bang-Bang）的防抖动参数，叫回差 / 滞后值。假设你热床设 60℃，回差设 2℃，温度降到 58℃ 才开始加热，温度升到 60℃ 才停止加热,不会在 60℃ 附近频繁开关、哒哒响。
#endif

//
// Heated Chamber options  // 恒温腔室加热相关配置
//

#if TEMP_SENSOR_CHAMBER
  //#define HEATER_CHAMBER_PIN      P2_04   // Required heater on/off pin (example: SKR 1.4 Turbo HE1 plug)  // 加热设备通断控制引脚（例：SKR 1.4 Turbo 主板HE1接口）
  //#define HEATER_CHAMBER_INVERTING false
  //#define FAN1_PIN                   -1   // Remove the fan signal on pin P2_04 (example: SKR 1.4 Turbo HE1 plug)  // 禁用（移除）引脚 P2_04 上的风扇信号（例：SKR 1.4 Turbo 主板 HE1 接口）

  #if DISABLED(PIDTEMPCHAMBER)
    #define CHAMBER_CHECK_INTERVAL 5000   // (ms) Interval between checks in bang-bang control  // (毫秒) 通断式控温的温度检测间隔  （译者注）：这是设置腔体加热器每隔多久检测一次温度，判断启停
    #if ENABLED(CHAMBER_LIMIT_SWITCHING)
      #define CHAMBER_HYSTERESIS 2        // (°C) Only set the relevant heater state when ABS(T-target) > CHAMBER_HYSTERESIS  // (°C) 仅当 绝对值(当前温度 - 目标温度) > 腔体回差值 时，才切换加热器状态
    #endif
  #endif

  //#define CHAMBER_FAN               // Enable a fan on the chamber  // 启用腔体散热/循环风扇
  #if ENABLED(CHAMBER_FAN)
    //#define CHAMBER_FAN_INDEX   2   // Index of a fan to repurpose as the chamber fan. (Default: first unused fan)  // 重新指定一个风扇作为腔体风扇使用。（默认：第一个未被使用的风扇）
    #define CHAMBER_FAN_MODE      2   // Fan control mode: 0=Static; 1=Linear increase when temp is higher than target; 2=V-shaped curve; 3=similar to 1 but fan is always on.
    // 上面为风扇控制模式：
    // 0 = 固定转速（静态）
    // 1 = 温度超过目标值后线性提速
    // 2 = V型曲线（两头快、中间慢）
    // 3 = 和模式1类似，但风扇始终保持运转
    #if CHAMBER_FAN_MODE == 0
      #define CHAMBER_FAN_BASE  255   // Chamber fan PWM (0-255)  // 腔体风扇 PWM 转速值（范围 0-255）
    #elif CHAMBER_FAN_MODE == 1
      #define CHAMBER_FAN_BASE  128   // Base chamber fan PWM (0-255); turns on when chamber temperature is above the target  // 腔体风扇基础 PWM 转速 (0-255)；当腔体温度超过目标温度时启动
      #define CHAMBER_FAN_FACTOR 25   // PWM increase per °C above target  // 温度每超出目标 1°C，PWM 增加的数值
    #elif CHAMBER_FAN_MODE == 2
      #define CHAMBER_FAN_BASE  128   // Minimum chamber fan PWM (0-255)  // 腔体风扇最小 PWM 转速 (0-255)
      #define CHAMBER_FAN_FACTOR 25   // PWM increase per °C difference from target  // 温度与目标值每相差 1°C，PWM 增加的数值
    #elif CHAMBER_FAN_MODE == 3
      #define CHAMBER_FAN_BASE  128   // Base chamber fan PWM (0-255)  // 腔体风扇基础 PWM 转速 (0-255)
      #define CHAMBER_FAN_FACTOR 25   // PWM increase per °C above target  // 温度每超出目标 1°C，PWM 增加的数值
    #endif
  #endif

  //#define CHAMBER_VENT              // Enable a servo-controlled vent on the chamber  // 启用舵机控制的腔体通风口
  #if ENABLED(CHAMBER_VENT)
    #define CHAMBER_VENT_SERVO_NR  1  // Index of the vent servo  // 通风口所用舵机的编号
    #define HIGH_EXCESS_HEAT_LIMIT 5  // How much above target temp to consider there is excess heat in the chamber  // 腔体温度超出目标值多少度，判定为热量过剩
    #define LOW_EXCESS_HEAT_LIMIT  3
    #define MIN_COOLING_SLOPE_TIME_CHAMBER_VENT 20
    #define MIN_COOLING_SLOPE_DEG_CHAMBER_VENT 1.5
  #endif
#endif

//
// Laser Cooler options
//
#if TEMP_SENSOR_COOLER
  #define COOLER_MINTEMP           8  // (°C)
  #define COOLER_MAXTEMP          26  // (°C)
  #define COOLER_DEFAULT_TEMP     16  // (°C)
  #define TEMP_COOLER_HYSTERESIS   1  // (°C) Temperature proximity considered "close enough" to the target  // (℃) 判定温度已接近目标值的误差范围
  #define COOLER_PIN               8  // Laser cooler on/off pin used to control power to the cooling element (e.g., TEC, External chiller via relay)  // 激光冷却器通断控制引脚,用于控制制冷元件供电（如半导体制冷TEC、继电器控制的外部冷水机）
  #define COOLER_INVERTING     false
  #define TEMP_COOLER_PIN         15  // Laser/Cooler temperature sensor pin. ADC is required.  // 激光/冷却器温度传感器引脚。必须支持 ADC 模拟输入。
  #define COOLER_FAN                  // Enable a fan on the cooler, Fan# 0,1,2,3 etc.  // 启用冷却器风扇，指定风扇编号 0、1、2、3 等
  #define COOLER_FAN_INDEX         0  // FAN number 0, 1, 2 etc. e.g.  // 风扇编号：0、1、2 等（示例）
  #if ENABLED(COOLER_FAN)
    #define COOLER_FAN_BASE      100  // Base Cooler fan PWM (0-255); turns on when Cooler temperature is above the target  // 冷却器风扇基础 PWM 转速 (0-255)；当冷却器温度超过目标温度时启动
    #define COOLER_FAN_FACTOR     25  // PWM increase per °C above target  // 温度每超出目标 1°C，PWM 增加的数值
  #endif
#endif

//
// Motherboard Sensor options
//
#if TEMP_SENSOR_BOARD
  #define THERMAL_PROTECTION_BOARD   // Halt the printer if the board sensor leaves the temp range below.  // 如果主板温度传感器检测到温度超出下方设定的范围，立即停止打印机
  #define BOARD_MINTEMP           8  // (°C)
  #define BOARD_MAXTEMP          70  // (°C)
  //#define TEMP_BOARD_PIN -1        // Board temp sensor pin override.  // 主板温度传感器引脚 强制覆盖/重定义
#endif

//
// SoC Sensor options
//
#if TEMP_SENSOR_SOC
  #define THERMAL_PROTECTION_SOC     // Halt the printer if the SoC sensor leaves the temp range below.  // 若系统主控芯片(SoC)温度超出下述范围，打印机立即停机
  #define SOC_MAXTEMP            85  // (°C)
#endif

/**
 * Thermal Protection provides additional protection to your printer from damage
 * and fire. Marlin always includes safe min and max temperature ranges which
 * protect against a broken or disconnected thermistor wire.
 *
 * The issue: If a thermistor falls out, it will report the much lower
 * temperature of the air in the room, and the the firmware will keep
 * the heater on.
 *
 * The solution: Once the temperature reaches the target, start observing.
 * If the temperature stays too far below the target (hysteresis) for too
 * long (period), the firmware will halt the machine as a safety precaution.
 *
 * If you get false positives for "Thermal Runaway", increase
 * THERMAL_PROTECTION_HYSTERESIS and/or THERMAL_PROTECTION_PERIOD
 * 
 * 热保护功能为你的打印机提供额外防护，避免损坏和火灾风险。
 * Marlin 固件内置了安全的最低/最高温度范围，
 * 用于保护因热敏电阻断线、接触不良导致的故障。
 *
 * 问题所在：如果热敏电阻脱落，它会检测到室温（远低于打印温度），
 * 固件就会**一直加热**，导致喷头/热床持续升温、过热甚至起火。
 *
 * 解决方法：当温度达到目标值后，固件开始监控。
 * 如果温度**长时间（period）低于目标值太多（hysteresis）**，
 * 固件会强制停机，作为安全防护。
 *
 * 如果你遇到“误报热失控”的情况，
 * 请增大 THERMAL_PROTECTION_HYSTERESIS 和/或 THERMAL_PROTECTION_PERIOD
 */
#if ALL(HAS_HOTEND, THERMAL_PROTECTION_HOTENDS)
  #define THERMAL_PROTECTION_PERIOD        40 // (seconds)
  #define THERMAL_PROTECTION_HYSTERESIS     4 // (°C)

  //#define ADAPTIVE_FAN_SLOWING              // Slow down the part-cooling fan if the temperature drops  // 当温度下降时，自动降低模型冷却风扇（part-cooling fan）的转速
  #if ENABLED(ADAPTIVE_FAN_SLOWING)
    //#define REPORT_ADAPTIVE_FAN_SLOWING     // Report fan slowing activity to the console  // 将风扇减速动作输出到控制台（日志/调试窗口）
    #if ANY(MPCTEMP, PIDTEMP)
      //#define TEMP_TUNING_MAINTAIN_FAN      // Don't slow down the fan speed during M303 or M306 T  // 在执行 M303 或 M306 T 命令期间，不执行风扇减速功能
    #endif
  #endif

  /**
   * Whenever an M104, M109, or M303 increases the target temperature, the
   * firmware will wait for the WATCH_TEMP_PERIOD to expire. If the temperature
   * hasn't increased by WATCH_TEMP_INCREASE degrees, the machine is halted and
   * requires a hard reset. This test restarts with any M104/M109/M303, but only
   * if the current temperature is far enough below the target for a reliable
   * test.
   *
   * If you get false positives for "Heating failed", increase WATCH_TEMP_PERIOD
   * and/or decrease WATCH_TEMP_INCREASE. WATCH_TEMP_INCREASE should not be set
   * below 2.
   * 
   * 
   * 每当使用 M104、M109 或 M303 命令提高目标温度时，
   * 固件会开始计时等待 WATCH_TEMP_PERIOD（秒）。
   * 如果在这段时间内，温度**没有上升达到 WATCH_TEMP_INCREASE（度）**，
   * 机器会立即停机，并需要手动硬重启才能恢复。
   *
   * 每次执行 M104/M109/M303 时，这个检测都会重新开始。
   * 但仅当当前温度远低于目标温度时，才会执行可靠检测。
   *
   * 如果你遇到 **“Heating failed”（加热失败）误报**，
   * 请增大 WATCH_TEMP_PERIOD（时间），和/或 **减小** WATCH_TEMP_INCREASE（温升）。
   * WATCH_TEMP_INCREASE 数值**不能低于 2**。
   * 
   * （译者注）：这个功能是防止加热器坏了、加热不工作，主控却一直发出继续加热指令。
   */
  #define WATCH_TEMP_PERIOD  40               // (seconds)
  #define WATCH_TEMP_INCREASE 2               // (°C)
#endif

/**
 * Thermal Protection parameters for the bed are just as above for hotends.  // 热床的热保护参数规则，和上述喷头热保护参数完全一致。
 */
#if TEMP_SENSOR_BED && ENABLED(THERMAL_PROTECTION_BED)
  #define THERMAL_PROTECTION_BED_PERIOD        20 // (seconds)
  #define THERMAL_PROTECTION_BED_HYSTERESIS     2 // (°C)

  /**
   * As described above, except for the bed (M140/M190/M303).  // 规则与上文一致，仅适配热床相关指令：M140/M190/M303
   */
  #define WATCH_BED_TEMP_PERIOD                60 // (seconds)
  #define WATCH_BED_TEMP_INCREASE               2 // (°C)
#endif

/**
 * Thermal Protection parameters for the heated chamber.  // 恒温仓保温腔专用热保护参数
 */
#if TEMP_SENSOR_CHAMBER && ENABLED(THERMAL_PROTECTION_CHAMBER)
  #define THERMAL_PROTECTION_CHAMBER_PERIOD    20 // (seconds)
  #define THERMAL_PROTECTION_CHAMBER_HYSTERESIS 2 // (°C)

  /**
   * Heated chamber watch settings (M141/M191).  // 加热恒温仓升温监测配置，对应指令：M141 / M191
   */
  #define WATCH_CHAMBER_TEMP_PERIOD            60 // (seconds)
  #define WATCH_CHAMBER_TEMP_INCREASE           2 // (°C)
#endif

/**
 * Thermal Protection parameters for the laser cooler.  // 激光冷却器专属热保护参数
 */
#if TEMP_SENSOR_COOLER && ENABLED(THERMAL_PROTECTION_COOLER)
  #define THERMAL_PROTECTION_COOLER_PERIOD     10 // (seconds)
  #define THERMAL_PROTECTION_COOLER_HYSTERESIS  3 // (°C)

  /**
   * Laser cooling watch settings (M143/M193).  // 激光冷却系统升温监测配置，对应指令：M143 / M193
   */
  #define WATCH_COOLER_TEMP_PERIOD             60 // (seconds)
  #define WATCH_COOLER_TEMP_INCREASE            3 // (°C)
#endif

#if ANY(THERMAL_PROTECTION_HOTENDS, THERMAL_PROTECTION_BED, THERMAL_PROTECTION_CHAMBER, THERMAL_PROTECTION_COOLER)
  /**
   * Thermal Protection Variance Monitor - EXPERIMENTAL
   * Kill the machine on a stuck temperature sensor.
   *
   * This feature may cause some thermally-stable systems to halt. Be sure to test it thoroughly under
   * a variety of conditions. Disable if you get false positives.
   *
   * This feature ensures that temperature sensors are updating regularly. If sensors die or get "stuck",
   * or if Marlin stops reading them, temperatures will remain constant while heaters may still be powered!
   * This feature only monitors temperature changes so it should catch any issue, hardware or software.
   *
   * By default it uses the THERMAL_PROTECTION_*_PERIOD constants (above) for the time window, within which
   * at least one temperature change must occur, to indicate that sensor polling is working. If any monitored
   * heater's temperature remains totally constant (without even a fractional change) during this period, a
   * thermal malfunction error occurs and the printer is halted.
   *
   * A very stable heater might produce a false positive and halt the printer. In this case, try increasing
   * the corresponding THERMAL_PROTECTION_*_PERIOD constant a bit. Keep in mind that uncontrolled heating
   * shouldn't be allowed to persist for more than a minute or two.
   *
   * Be careful to distinguish false positives from real sensor issues before disabling this feature. If the
   * heater's temperature appears even slightly higher than expected after restarting, you may have a real
   * thermal malfunction. Check the temperature graph in your host for any unusual bumps.
   * 
   * 温度偏差监测热保护 —— 实验性功能
   * 检测到温度传感器卡死不动时，直接紧急停机
   *
   * 该功能可能导致温控极度稳定的设备误停机，务必在多种工况下充分测试，
   * 出现频繁误报可直接关闭。
   *
   * 作用原理：确保所有温度传感器数据在持续刷新。
   * 一旦探头损坏、信号卡死、固件停止读取测温数据，温度数值会彻底静止，
   * 但加热元件仍可能持续通电加热，极易引发危险。 
   * 本功能只监测温度是否发生变动，软硬层面的测温异常都能精准捕获。
   *
   * 默认沿用上文各类热保护的**PERIOD监测时长**作为判定窗口，
   * 规定时长内温度必须出现至少微小波动，代表传感器正常轮询读数。
   * 若任意一路受控加热设备温度全程完全不变（无丝毫数值变动），
   * 立即触发温控故障报错并停机锁机。
   *
   * 加热工况过于平稳的设备容易触发误判停机，
   * 遇到此情况可适当加长对应类别的热保护监测时长。
   * 切记：失控加热状态绝对不能放任持续一两分钟以上。
   *
   * 关闭该功能前务必分清是误报还是真传感器故障；
   * 重启后若实际温度明显偏高，即为真实温控故障，优先排查硬件，
   * 可在上位机温度曲线图里查看异常温度波动佐证问题。
   */
  //#define THERMAL_PROTECTION_VARIANCE_MONITOR
  #if ENABLED(THERMAL_PROTECTION_VARIANCE_MONITOR)
    // Variance detection window to override the THERMAL_PROTECTION...PERIOD settings above.
    // Keep in mind that some heaters heat up faster than others.
    // 温度变化监测时间窗口（用于覆盖/替换上面的 THERMAL_PROTECTION...PERIOD 设置）
    // 注意：不同加热器的加热速度不一样（有的快、有的慢）。
    //#define THERMAL_PROTECTION_VARIANCE_MONITOR_PERIOD 30  // (s) Override all watch periods  // (秒) 覆盖【所有】加热区的监测周期
  #endif
#endif

#if ENABLED(PIDTEMP)
  // Add an additional term to the heater power, proportional to the extrusion speed.
  // A well-chosen Kc value should add just enough power to melt the increased material volume.
  // 向加热器功率添加一个额外项，该值与挤出速度成正比。
  // 选择合适的 Kc 值，应刚好补充足够的功率，以熔化更多体积的材料。 （译者注）：Kc值是补偿强度
  //#define PID_EXTRUSION_SCALING
  #if ENABLED(PID_EXTRUSION_SCALING)
    #define DEFAULT_Kc (100) // heating power = Kc * e_speed  // 加热功率 = Kc × 挤出速度
    #define LPQ_MAX_LEN 50
  #endif

  /**
   * Add an additional term to the heater power, proportional to the fan speed.
   * A well-chosen Kf value should add just enough power to compensate for power-loss from the cooling fan.
   * You can either just add a constant compensation with the DEFAULT_Kf value
   * or follow the instruction below to get speed-dependent compensation.
   *
   * Constant compensation (use only with fan speeds of 0% and 100%)
   * ---------------------------------------------------------------------
   * A good starting point for the Kf-value comes from the calculation:
   *   kf = (power_fan * eff_fan) / power_heater * 255
   * where eff_fan is between 0.0 and 1.0, based on fan-efficiency and airflow to the nozzle / heater.
   *
   * Example:
   *   Heater: 40W, Fan: 0.1A * 24V = 2.4W, eff_fan = 0.8
   *   Kf = (2.4W * 0.8) / 40W * 255 = 12.24
   *
   * Fan-speed dependent compensation
   * --------------------------------
   * 1. To find a good Kf value, set the hotend temperature, wait for it to settle, and enable the fan (100%).
   *    Make sure PID_FAN_SCALING_LIN_FACTOR is 0 and PID_FAN_SCALING_ALTERNATIVE_DEFINITION is not enabled.
   *    If you see the temperature drop repeat the test, increasing the Kf value slowly, until the temperature
   *    drop goes away. If the temperature overshoots after enabling the fan, the Kf value is too big.
   * 2. Note the Kf-value for fan-speed at 100%
   * 3. Determine a good value for PID_FAN_SCALING_MIN_SPEED, which is around the speed, where the fan starts moving.
   * 4. Repeat step 1. and 2. for this fan speed.
   * 5. Enable PID_FAN_SCALING_ALTERNATIVE_DEFINITION and enter the two identified Kf-values in
   *    PID_FAN_SCALING_AT_FULL_SPEED and PID_FAN_SCALING_AT_MIN_SPEED. Enter the minimum speed in PID_FAN_SCALING_MIN_SPEED
   * 
   * 向加热器功率添加一个额外项，该值与风扇转速成正比。
   * 选择合适的 Kf 值，应刚好补充足够的功率，以补偿冷却风扇带走的热量。
   * 你可以直接使用 DEFAULT_Kf 值进行固定补偿，
   * 或按照下面的说明设置随风扇转速变化的动态补偿。
   *
   * 固定补偿（仅在风扇 0% 和 100% 两档使用）
   * ---------------------------------------------------------------------
   * Kf 值推荐初始计算公式：
   *   kf = (风扇功率 * 风扇效率) / 加热头功率 * 255
   * 其中 eff_fan（风扇效率）在 0.0~1.0 之间，取决于风扇效率和吹向喷头的风量。
   *
   * 示例：
   *   加热头：40W，风扇：0.1A * 24V = 2.4W，eff_fan = 0.8
   *   Kf = (2.4W * 0.8) / 40W * 255 = 12.24
   *
   * 随风扇转速动态补偿
   * --------------------------------
   * 1. 设置喷头温度，等待稳定，然后开启风扇（100%）。
   *    确保 PID_FAN_SCALING_LIN_FACTOR = 0，PID_FAN_SCALING_ALTERNATIVE_DEFINITION 未开启。
   *    如果温度下降，慢慢增大 Kf，直到温度不再下降。
   *    如果开启风扇后温度冲太高，说明 Kf 太大。
   * 2. 记录 100% 风扇转速下的最佳 Kf 值。
   * 3. 设置 PID_FAN_SCALING_MIN_SPEED（风扇开始转动的最低转速）。
   * 4. 对这个最低转速重复步骤 1 和 2。
   * 5. 开启 PID_FAN_SCALING_ALTERNATIVE_DEFINITION，
   *    把两个 Kf 值填入对应参数，最低转速也填入。
   * 
   * （译者注）：功能简介：
   * 风扇吹喷头 → 喷头温度会掉 → 打印质量变差
      这个功能让固件：
      风扇转得越快 → 自动给喷头加越多加热功率
   */
  //#define PID_FAN_SCALING
  #if ENABLED(PID_FAN_SCALING)
    //#define PID_FAN_SCALING_ALTERNATIVE_DEFINITION
    #if ENABLED(PID_FAN_SCALING_ALTERNATIVE_DEFINITION)
      // The alternative definition is used for an easier configuration.  // 使用这种替代定义方式可以让配置更简单。
      // Just figure out Kf at full speed (255) and PID_FAN_SCALING_MIN_SPEED.  // 只需要算出【风扇全速(255)】和【最低风扇转速(PID_FAN_SCALING_MIN_SPEED)】对应的 Kf 值即可。
      // DEFAULT_Kf and PID_FAN_SCALING_LIN_FACTOR are calculated accordingly.  // DEFAULT_Kf 和 PID_FAN_SCALING_LIN_FACTOR 会自动计算出来。

      #define PID_FAN_SCALING_AT_FULL_SPEED 13.0        //=PID_FAN_SCALING_LIN_FACTOR*255+DEFAULT_Kf  // 计算公式 = PID_FAN_SCALING_LIN_FACTOR * 255 + DEFAULT_Kf
      #define PID_FAN_SCALING_AT_MIN_SPEED   6.0        //=PID_FAN_SCALING_LIN_FACTOR*PID_FAN_SCALING_MIN_SPEED+DEFAULT_Kf  // 计算公式 = PID_FAN_SCALING_LIN_FACTOR * PID_FAN_SCALING_MIN_SPEED + DEFAULT_Kf
      #define PID_FAN_SCALING_MIN_SPEED     10.0        // Minimum fan speed at which to enable PID_FAN_SCALING  // 启用 PID 风扇散热补偿功能的【最低风扇转速阈值】

      #define DEFAULT_Kf (255.0*PID_FAN_SCALING_AT_MIN_SPEED-PID_FAN_SCALING_AT_FULL_SPEED*PID_FAN_SCALING_MIN_SPEED)/(255.0-PID_FAN_SCALING_MIN_SPEED)
      #define PID_FAN_SCALING_LIN_FACTOR (PID_FAN_SCALING_AT_FULL_SPEED-DEFAULT_Kf)/255.0

    #else
      #define PID_FAN_SCALING_LIN_FACTOR (0)             // Power-loss due to cooling = Kf * (fan_speed)  // 风扇散热造成的功率损失 = Kf * 风扇转速
      #define DEFAULT_Kf 10                              // A constant value added to the PID-tuner  // 一个添加到 PID 调参器中的固定常量值
      #define PID_FAN_SCALING_MIN_SPEED 10               // Minimum fan speed at which to enable PID_FAN_SCALING  // 启用 PID 风扇散热补偿功能的【最低风扇转速阈值】
    #endif
  #endif
#endif

/**
 * Automatic Temperature Mode
 *
 * Dynamically adjust the hotend target temperature based on planned E moves.
 *
 * (Contrast with PID_EXTRUSION_SCALING, which tracks E movement and adjusts PID
 *  behavior using an additional kC value.)
 *
 * Autotemp is calculated by (mintemp + factor * mm_per_sec), capped to maxtemp.
 *
 * Enable Autotemp Mode with M104/M109 F<factor> S<mintemp> B<maxtemp>.
 * Disable by sending M104/M109 with no F parameter (or F0 with AUTOTEMP_PROPORTIONAL).
 * 
 * 自动温度模式
 *
 * 根据计划中的挤出运动（E轴移动），动态调整喷头目标温度。
 *
 * （与 PID_EXTRUSION_SCALING 不同，后者通过额外的 Kc 值跟踪挤出并调整 PID 输出。）
 *
 * 自动温度计算公式：
 *   目标温度 = 最低温度 + 系数 × 挤出速度(mm/秒)
 *   最终温度不会超过设定的最高温度。
 *
 * 使用 M104/M109 F<系数> S<最低温> B<最高温> 开启自动温度。
 * 发送不带 F 参数的 M104/M109 即可关闭（或使用 AUTOTEMP_PROPORTIONAL 时发送 F0）。
 * 
 * （译者注）：功能简介：
    固件动态变温。
     打印越快 → 温度自动越高
     打印越慢 → 温度自动越低
 */
#define AUTOTEMP
#if ENABLED(AUTOTEMP)
  #define AUTOTEMP_OLDWEIGHT    0.98  // Factor used to weight previous readings (0.0 < value < 1.0)  // 用于加权平均历史读数的系数（取值范围：0.0 ～ 1.0）
  #define AUTOTEMP_MIN          210
  #define AUTOTEMP_MAX          250
  #define AUTOTEMP_FACTOR       0.1f
  // Turn on AUTOTEMP on M104/M109 by default using proportions set here  // 默认使用此处设置的参数，在执行 M104/M109 时自动开启 自动温度模式（AUTOTEMP）
  //#define AUTOTEMP_PROPORTIONAL
  #if ENABLED(AUTOTEMP_PROPORTIONAL)
    #define AUTOTEMP_MIN_P      0 // (°C) Added to the target temperature  // (摄氏度) 在目标温度基础上额外增加的温度值
    #define AUTOTEMP_MAX_P      5 // (°C) Added to the target temperature  // (摄氏度) 在目标温度基础上额外增加的温度值
    #define AUTOTEMP_FACTOR_P   1 // Apply this F parameter by default (overridden by M104/M109 F)  // 默认使用此 F 参数（可被 M104/M109 指令中的 F 参数覆盖）
  #endif
#endif

// Show Temperature ADC value                                            // 显示温度 ADC 原始值
// Enable for M105 to include ADC values read from temperature sensors.  // 启用后，M105 指令会返回从温度传感器读取的 ADC 数值
//#define SHOW_TEMP_ADC_VALUES

/**
 * High Temperature Thermistor Support
 *
 * Thermistors able to support high temperature tend to have a hard time getting
 * good readings at room and lower temperatures. This means TEMP_SENSOR_X_RAW_LO_TEMP
 * will probably be caught when the heating element first turns on during the
 * preheating process, which will trigger a MINTEMP error as a safety measure
 * and force stop everything.
 * To circumvent this limitation, we allow for a preheat time (during which,
 * MINTEMP error won't be triggered) and add a min_temp buffer to handle
 * aberrant readings.
 *
 * If you want to enable this feature for your hotend thermistor(s)
 * uncomment and set values > 0 in the constants below
 * 
 * 高温热敏电阻支持
 *
 * 能够支持高温的热敏电阻，在室温及更低温度下往往很难获得准确读数。
 * 这意味着在预热过程中加热元件刚启动时，可能会触发 TEMP_SENSOR_X_RAW_LO_TEMP 检测，
 * 系统会出于安全触发 MINTEMP 错误并强制停机。
 *
 * 为了避开这个限制，我们设置了一个预热时间（在此期间不会触发 MINTEMP 错误），
 * 并增加了一个低温缓冲区间来处理异常读数。
 *
 * 如果你想为你的喷头热敏电阻启用此功能
 * 取消下面常量的注释，并设置 > 0 的数值
 */

// The number of consecutive low temperature errors that can occur  
// before a MINTEMP error is triggered. (Shouldn't be more than 10.)
// 在触发 MINTEMP 错误之前，允许连续出现多少次低温错误。（不应超过 10）
//#define MAX_CONSECUTIVE_LOW_TEMPERATURE_ERROR_ALLOWED 0

/**
 * The number of milliseconds a hotend will preheat before starting to check
 * the temperature. This value should NOT be set to the time it takes the
 * hot end to reach the target temperature, but the time it takes to reach
 * the minimum temperature your thermistor can read. The lower the better/safer.
 * This shouldn't need to be more than 30 seconds (30000)
 * 
 * 喷头在开始【温度检测】之前，预热的毫秒数。
 * 这个值【不要】设置为喷头达到目标温度的时间，
 * 而应设置为热敏电阻能读取到【最低有效温度】所需的时间。
 * 数值越小越好、越安全。
 * 通常不需要超过 30 秒（30000）。
 */
//#define PREHEAT_TIME_HOTEND_MS 0
//#define PREHEAT_TIME_BED_MS 0

// @section extruder

// ======================================== 挤出机相关的配置 =============================================

/**
 * Extruder runout prevention.                              // 挤出机防堵回抽/防空转溢料功能
 * If the machine is idle and the temperature over MINTEMP  // 设备处于待机状态且温度高于最低安全温度时
 * then extrude some filament every couple of SECONDS.      // 每隔设定秒数自动挤出一小段耗材
 */
//#define EXTRUDER_RUNOUT_PREVENT
#if ENABLED(EXTRUDER_RUNOUT_PREVENT)
  #define EXTRUDER_RUNOUT_MINTEMP 190    // 最低启动温度
  #define EXTRUDER_RUNOUT_SECONDS 30     // 间隔时间（秒）
  #define EXTRUDER_RUNOUT_SPEED 1500     // 出料速度（mm/分钟）
  #define EXTRUDER_RUNOUT_EXTRUDE 5      // 每次出料长度（mm）
#endif

/**
 * Hotend Idle Timeout
 * Prevent filament in the nozzle from charring and causing a critical jam.
 * 喷头待机超时功能
 * 防止喷嘴内耗材碳化发黑，进而引发严重堵头
 */
//#define HOTEND_IDLE_TIMEOUT
#if ENABLED(HOTEND_IDLE_TIMEOUT)
  #define HOTEND_IDLE_TIMEOUT_SEC (5*60)    // (seconds) Time without extruder movement to trigger protection  // (秒) 挤出机无动作的时间，达到后触发保护机制
  #define HOTEND_IDLE_MIN_TRIGGER   180     // (°C) Minimum temperature to enable hotend protection            // (°C) 启用喷头保护功能的最低温度
  #define HOTEND_IDLE_NOZZLE_TARGET   0     // (°C) Safe temperature for the nozzle after timeout              // (°C) 超时保护触发后，喷嘴会降到的安全温度
  #define HOTEND_IDLE_BED_TARGET      0     // (°C) Safe temperature for the bed after timeout                 // (℃) 超时触发后热床降至的安全待机温度
#endif

// @section temperature

//======================================= 温度控制模块 =======================================

// Calibration for AD595 / AD8495 sensor to adjust temperature measurements.     // AD595 / AD8495 温度传感器校准参数，用于修正温度测量值
// The final temperature is calculated as (measuredTemp * GAIN) + OFFSET.        // 最终温度计算公式：实际显示温度 = (测量温度 * 增益系数) + 偏移补偿
#define TEMP_SENSOR_AD595_OFFSET  0.0
#define TEMP_SENSOR_AD595_GAIN    1.0
#define TEMP_SENSOR_AD8495_OFFSET 0.0
#define TEMP_SENSOR_AD8495_GAIN   1.0






// @section fans
//========================================= 风扇模块 =========================================

/**
 * Controller Fan
 * To cool down the stepper drivers and MOSFETs.
 *
 * The fan turns on automatically whenever any driver is enabled and turns
 * off (or reduces to idle speed) shortly after drivers are turned off.
 * 
 * 主板主控散热风扇
 * 用于给步进驱动芯片与功率管MOS管散热降温
 *
 * 任意驱动模块启动工作时，风扇自动开启
 * 所有驱动停止工作后，风扇延时关闭或降至低速待机
 */
//#define USE_CONTROLLER_FAN
#if ENABLED(USE_CONTROLLER_FAN)
  //#define CONTROLLER_FAN_PIN -1           // Set a custom pin for the controller fan                                 // 为主板散热风扇（Controller Fan）设置自定义引脚
  //#define CONTROLLER_FAN2_PIN -1          // Set a custom pin for second controller fan                              // 为第二个主板散热风扇设置自定义引脚
  //#define CONTROLLER_FAN_USE_Z_ONLY       // With this option only the Z axis is considered                          // 启用该选项后，仅判定Z轴状态
  //#define CONTROLLER_FAN_IGNORE_Z         // Ignore Z stepper. Useful when stepper timeout is disabled.              // 忽略 Z 轴步进电机状态,// 在禁用了步进电机超时功能时使用非常有用
  #define CONTROLLERFAN_SPEED_MIN         0 // (0-255) Minimum speed. (If set below this value the fan is turned off.) // (0-255) 最低运行转速。（如果设置低于此值，风扇将直接关闭。）
  #define CONTROLLERFAN_SPEED_ACTIVE    255 // (0-255) Active speed, used when any motor is enabled                    // (0-255) 风扇运行转速（任意电机启用时使用）
  #define CONTROLLERFAN_SPEED_IDLE        0 // (0-255) Idle speed, used when motors are disabled                       // (0-255) 待机转速（电机全部禁用时使用）
  #define CONTROLLERFAN_IDLE_TIME        60 // (seconds) Extra time to keep the fan running after disabling motors     // (秒) 电机全部禁用后，风扇**额外持续运行的时间**

  // Use TEMP_SENSOR_BOARD as a trigger for enabling the controller fan  // 使用主板温度传感器（TEMP_SENSOR_BOARD）作为启用控制器风扇的触发条件
  //#define CONTROLLER_FAN_MIN_BOARD_TEMP 40  // (°C) Turn on the fan if the board reaches this temperature

  // Use TEMP_SENSOR_SOC as a trigger for enabling the controller fan   // 使用芯片（SOC）温度传感器作为启用控制器风扇的触发条件
  //#define CONTROLLER_FAN_MIN_SOC_TEMP 40  // (°C) Turn on the fan if the SoC reaches this temperature

  #define CONTROLLER_FAN_BED_HEATING        // Turn on the fan when heating the bed    // 热床启动加热时，自动开启该风扇

  //#define CONTROLLER_FAN_EDITABLE         // Enable M710 configurable settings       // 启用M710风扇自定义配置指令
  #if ENABLED(CONTROLLER_FAN_EDITABLE)
    #define CONTROLLER_FAN_MENU             // Enable the Controller Fan submenu       // 开启主板散热风扇专属设置子菜单
  #endif
#endif

/**
 * Fan Kickstart
 * When part cooling or controller fans first start, run at a speed that
 * gets it spinning reliably for a short time before setting the requested speed.
 * (Does not work on Sanguinololu with FAN_SOFT_PWM.)
 * 
 * 风扇启动加速功能
 * 当模型冷却风扇或主板散热风扇刚启动时，
 * 先以较高转速短时间运转，确保风扇可靠转动，
 * 之后再降至设定的转速。
 * （在使用软件PWM的Sanguinololu主板上无效。）
 */
//#define FAN_KICKSTART_TIME  100  // (ms)
//#define FAN_KICKSTART_POWER 180  // 64-255
//#define FAN_KICKSTART_LINEAR     // Set kickstart time linearly based on the speed, e.g., for 20% (51) it will be FAN_KICKSTART_TIME * 0.2.
                                   // Useful for quick speed up to low speed. Kickstart power must be set to 255.
                                   // 根据风扇转速线性设置启动加速时间，
                                   // 例如：转速 20% (51) 时，启动时间 = FAN_KICKSTART_TIME × 0.2。
                                   // 适用于快速低速启动。
                                   // 启动功率必须设为 255（全速）。

// Some coolers may require a non-zero "off" state.   // 部分散热器/风扇可能需要一个【非零的“关闭”状态】。
//（译者注）：上面这句话的意思是有些风扇不能用 0 转速来关闭，必须给一点点微小电压 / 转速才能真正 “关” 或进入待机状态。
//#define FAN_OFF_PWM  1

/**
 * PWM Fan Scaling
 *
 * Define the min/max speeds for PWM fans (as set with M106).
 *
 * With these options the M106 0-255 value range is scaled to a subset
 * to ensure that the fan has enough power to spin, or to run lower
 * current fans with higher current. (e.g., 5V/12V fans with 12V/24V)
 * Value 0 always turns off the fan.
 *
 * Define one or both of these to override the default 0-255 range.
 * 
 * PWM风扇转速映射
 *
 * 定义PWM风扇的最低/最高转速（通过M106指令设置）。
 *
 * 使用这些选项后，M106指令的 0-255 数值范围会被映射到一个更小的区间内，
 * 以确保风扇有足够的启动动力，或者让低电流风扇在高电流下安全运行。
 *（例如：用12V/24V电压驱动5V/12V风扇）
 * 数值 0 始终会关闭风扇。 
 *
 * 定义其中一个或两个参数，即可覆盖默认的 0-255 范围。
 */
//#define FAN_MIN_PWM 50
//#define FAN_MAX_PWM 128

/**
 * Fan Fast PWM   // 风扇高速 PWM 调速
 *
 * Combinations of PWM Modes, prescale values and TOP resolutions are used internally
 * to produce a frequency as close as possible to the desired frequency.
 * 内部自动组合 PWM 模式、预分频值、分辨率
 * 生成尽可能接近你设定目标的 PWM 频率
 *
 * FAST_PWM_FAN_FREQUENCY  // 设定风扇高速 PWM 的工作频率
 *   Set this to your desired frequency.
 *   For AVR, if left undefined this defaults to F = F_CPU/(2*255*1)
 *            i.e., F = 31.4kHz on 16MHz micro-controllers or F = 39.2kHz on 20MHz micro-controllers.
 *   For non AVR, if left undefined this defaults to F = 1Khz.
 *   This F value is only to protect the hardware from an absence of configuration
 *   and not to complete it when users are not aware that the frequency must be specifically set to support the target board.
 * 
 * *   在此设置你想要的PWM频率。
 *   对于AVR主板（如Arduino Mega2560）：如果不定义，默认使用公式 F = F_CPU/(2*255*1)
 *            即：16MHz芯片 → 31.4kHz | 20MHz芯片 → 39.2kHz
 *   对于非AVR主板（STM32/ESP32等）：不定义则默认为 1kHz
 *   这个默认频率**仅用于防止硬件无配置损坏**，
 *   并不是最优值，用户必须根据自己的主板与风扇手动设置正确频率。
 *
 *   NOTE: Setting very low frequencies (< 10 Hz) may result in unexpected timer behavior.
 *         Setting very high frequencies can damage your hardware.
 *   注意: 设置极低频率（<10赫兹）可能导致定时器运行异常。
 *         设置过高频率可能损坏你的硬件。
 *
 * USE_OCR2A_AS_TOP [undefined by default]
 *   Boards that use TIMER2 for PWM have limitations resulting in only a few possible frequencies on TIMER2:
 *   16MHz MCUs: [62.5kHz, 31.4kHz (default), 7.8kHz, 3.92kHz, 1.95kHz, 977Hz, 488Hz, 244Hz, 60Hz, 122Hz, 30Hz]
 *   20MHz MCUs: [78.1kHz, 39.2kHz (default), 9.77kHz, 4.9kHz, 2.44kHz, 1.22kHz, 610Hz, 305Hz, 153Hz, 76Hz, 38Hz]
 *   A greater range can be achieved by enabling USE_OCR2A_AS_TOP. But note that this option blocks the use of
 *   PWM on pin OC2A. Only use this option if you don't need PWM on 0C2A. (Check your schematic.)
 *   USE_OCR2A_AS_TOP sacrifices duty cycle control resolution to achieve this broader range of frequencies.
 * 
 * USE_OCR2A_AS_TOP [默认未开启]
 *   使用 TIMER2 做 PWM 的主板，频率只能从固定几个值里选：
 *   16MHz 芯片: [62.5kHz, 31.4kHz(默认), 7.8kHz, 3.92kHz...]
 *   20MHz 芯片: [78.1kHz, 39.2kHz(默认), 9.77kHz...]
 *
 *   开启 USE_OCR2A_AS_TOP 可以解锁**更多频率**，
 *   但代价是：**占用 OC2A 引脚，该引脚无法再用于 PWM**。
 *   只有你确定不用 OC2A 引脚时才能开（查主板图纸）。
 *
 *   同时，开启后会**损失一点 PWM 转速调节精度**。
 */
//#define FAST_PWM_FAN    // Increase the fan PWM frequency. Removes the PWM noise but increases heating in the FET/Arduino
// 提高风扇 PWM 调速频率。可消除 PWM 噪音，但会增加 FET 场效应管 / 主板的发热。
#if ENABLED(FAST_PWM_FAN)
  //#define FAST_PWM_FAN_FREQUENCY 31400  // Define here to override the defaults below // 在此处定义参数，以覆盖下方的默认设置
  //#define USE_OCR2A_AS_TOP
  #ifndef FAST_PWM_FAN_FREQUENCY
    #ifdef __AVR__
      #define FAST_PWM_FAN_FREQUENCY ((F_CPU) / (2 * 255 * 1))
    #else
      #define FAST_PWM_FAN_FREQUENCY 1000U
    #endif
  #endif
#endif

/**
 * Assign more PWM fans for part cooling, synchronized with Fan 0
 * 分配更多PWM风扇用于模型冷却，并与0号风扇保持同步运转
 */
//#define REDUNDANT_PART_COOLING_FAN 1  // Index of the first fan to synchronize with Fan 0  // 与0号风扇同步的第一个风扇的编号
#ifdef REDUNDANT_PART_COOLING_FAN
  //#define NUM_REDUNDANT_FANS 1        // Number of sequential fans to synchronize with Fan 0  // 要与0号风扇同步运行的连续风扇数量
#endif

/**
 * Extruder cooling fans
 *
 * Extruder auto fans automatically turn on when their extruders'
 * temperatures go above EXTRUDER_AUTO_FAN_TEMPERATURE.
 *
 * Your board's pins file specifies the recommended pins. Override those here
 * or set to -1 to disable completely.
 *
 * Multiple extruders can be assigned to the same pin in which case
 * the fan will turn on when any selected extruder is above the threshold.
 * 
 * 挤出机散热风扇
 *
 * 当挤出机温度超过 EXTRUDER_AUTO_FAN_TEMPERATURE 设定值时，
 * 对应的散热风扇会**自动开启**。
 *
 * 主板引脚文件已定义推荐引脚，可在此处覆盖，
 * 或设置为 -1 完全禁用该风扇。
 *
 * 多个挤出机可共用同一个风扇引脚，
 * 此时**任意一个挤出机超温**，风扇就会启动。
 */
#define E0_AUTO_FAN_PIN -1
#define E1_AUTO_FAN_PIN -1
#define E2_AUTO_FAN_PIN -1
#define E3_AUTO_FAN_PIN -1
#define E4_AUTO_FAN_PIN -1
#define E5_AUTO_FAN_PIN -1
#define E6_AUTO_FAN_PIN -1
#define E7_AUTO_FAN_PIN -1
#define CHAMBER_AUTO_FAN_PIN -1
#define COOLER_AUTO_FAN_PIN -1

#define EXTRUDER_AUTO_FAN_TEMPERATURE 50
#define EXTRUDER_AUTO_FAN_SPEED 255   // 255 == full speed（全速运行）
#define CHAMBER_AUTO_FAN_TEMPERATURE 30
#define CHAMBER_AUTO_FAN_SPEED 255
#define COOLER_AUTO_FAN_TEMPERATURE 18
#define COOLER_AUTO_FAN_SPEED 255

/**
 * Hotend Cooling Fans tachometers
 *
 * Define one or more tachometer pins to enable fan speed
 * monitoring, and reporting of fan speeds with M123.
 *  喷头散热风扇转速计
 *
 * 定义一个或多个转速计引脚，以启用风扇转速监控功能，
 * 并可通过 M123 指令报告实时风扇转速。
 *
 * NOTE: Only works with fans up to 7000 RPM.  // 注意：该测速功能仅支持转速不超过7000转/分钟的风扇
 */
//#define FOURWIRES_FANS      // Needed with AUTO_FAN when 4-wire PWM fans are installed  // 当安装 4线 PWM 风扇并使用 AUTO_FAN（自动风扇）功能时，需要启用此项
//#define E0_FAN_TACHO_PIN -1
//#define E0_FAN_TACHO_PULLUP
//#define E0_FAN_TACHO_PULLDOWN
//#define E1_FAN_TACHO_PIN -1
//#define E1_FAN_TACHO_PULLUP
//#define E1_FAN_TACHO_PULLDOWN
//#define E2_FAN_TACHO_PIN -1
//#define E2_FAN_TACHO_PULLUP
//#define E2_FAN_TACHO_PULLDOWN
//#define E3_FAN_TACHO_PIN -1
//#define E3_FAN_TACHO_PULLUP
//#define E3_FAN_TACHO_PULLDOWN
//#define E4_FAN_TACHO_PIN -1
//#define E4_FAN_TACHO_PULLUP
//#define E4_FAN_TACHO_PULLDOWN
//#define E5_FAN_TACHO_PIN -1
//#define E5_FAN_TACHO_PULLUP
//#define E5_FAN_TACHO_PULLDOWN
//#define E6_FAN_TACHO_PIN -1
//#define E6_FAN_TACHO_PULLUP
//#define E6_FAN_TACHO_PULLDOWN
//#define E7_FAN_TACHO_PIN -1
//#define E7_FAN_TACHO_PULLUP
//#define E7_FAN_TACHO_PULLDOWN

/**
 * Part-Cooling Fan Multiplexer
 *
 * This feature allows you to digitally multiplex the fan output.
 * The multiplexer is automatically switched at tool-change.
 * Set FANMUX[012]_PINs below for up to 2, 4, or 8 multiplexed fans.
 * * 模型冷却风扇多路选择器
 *
 * 该功能允许你对风扇输出进行数字多路复用控制。
 * 多路选择器会在**切换工具头（换挤出机）**时自动切换风扇。
 * 在下方设置 FANMUX[012]_PIN 引脚，最多可支持 2、4 或 8 个复用风扇。
 */
#define FANMUX0_PIN -1
#define FANMUX1_PIN -1
#define FANMUX2_PIN -1


//=========================================== 机箱氛围灯 / 机箱照明设置区 =============================================
/**
 * @section caselight
 * M355 Case Light on-off / brightness  // M355 指令：机箱灯开关控制与亮度调节
 */
//#define CASE_LIGHT_ENABLE
#if ENABLED(CASE_LIGHT_ENABLE)
  //#define CASE_LIGHT_PIN 4                  // Override the default pin if needed                        // 如果需要，可以在这里重新定义（覆盖）默认的机箱灯引脚
  #define INVERT_CASE_LIGHT false             // Set true if Case Light is ON when pin is LOW              // 如果机箱灯在引脚为 LOW（低电平）时点亮，请设置为 true
  #define CASE_LIGHT_DEFAULT_ON true          // Set default power-up state on                             // 设置机箱灯-开机默认状态为开启
  #define CASE_LIGHT_DEFAULT_BRIGHTNESS 105   // Set default power-up brightness (0-255, requires PWM pin) // 设置开机默认亮度（0-255，需要使用 PWM 引脚）
  //#define CASE_LIGHT_NO_BRIGHTNESS          // Disable brightness control. Enable for non-PWM lighting.  // 关闭亮度调节功能，非PWM普通灯光请开启此项
  //#define CASE_LIGHT_MAX_PWM 128            // Limit PWM duty cycle (0-255)                              // 限制 PWM 占空比（0-255）
  //#define CASE_LIGHT_MENU                   // Add Case Light options to the LCD menu                    // 将机箱灯控制选项添加到 LCD 屏幕菜单中
  #if ENABLED(NEOPIXEL_LED)
    //#define CASE_LIGHT_USE_NEOPIXEL         // Use NeoPixel LED as case light                            // 使用 NeoPixel LED 灯条作为机箱照明灯
  #endif
  #if ANY(RGB_LED, RGBW_LED)
    //#define CASE_LIGHT_USE_RGB_LED          // Use RGB / RGBW LED as case light                          // 使用 RGB / RGBW LED 作为机箱照明灯
  #endif
  #if ANY(CASE_LIGHT_USE_NEOPIXEL, CASE_LIGHT_USE_RGB_LED)
    #define CASE_LIGHT_DEFAULT_COLOR { 255, 255, 255, 255 } // { Red, Green, Blue, White }                 // {红，绿，蓝，白}
  #endif
#endif


//============================================ 限位开关配置 =========================================================

// @section endstops

// If you want endstops to stay on (by default) even when not homing
// enable this option. Override at any time with M120, M121.
// 如果你希望限位开关**即使不在回零过程中也保持生效（默认开启）**
// 启用此选项。可随时通过 M120 / M121 指令覆盖此设置。
//#define ENDSTOPS_ALWAYS_ON_DEFAULT


//================================================ 附加功能 / 扩展功能配置区 ===========================================
// @section extras

//#define Z_LATE_ENABLE // Enable Z the last moment. Needed if your Z driver overheats. // 临近运动结束时再启用Z轴驱动，Z轴驱动易过热需开启此项

// Employ an external closed loop controller. Override pins here if needed.             // 使用外部闭环控制器。如需自定义引脚可在此处覆盖。
//#define EXTERNAL_CLOSED_LOOP_CONTROLLER
#if ENABLED(EXTERNAL_CLOSED_LOOP_CONTROLLER)
  //#define CLOSED_LOOP_ENABLE_PIN        -1
  //#define CLOSED_LOOP_MOVE_COMPLETE_PIN -1
#endif


//================================================== IDEX 独立双喷头配置区==============================================
// @section idex

/**
 * Dual X Carriage  // 双X滑座 / 双X托架结构
 *
 * This setup has two X carriages that can move independently, each with its own hotend.
 * The carriages can be used to print an object with two colors or materials, or in
 * "duplication mode" it can print two identical or X-mirrored objects simultaneously.
 * The inactive carriage is parked automatically to prevent oozing.
 * X1 is the left carriage, X2 the right. They park and home at opposite ends of the X axis.
 * By default the X2 stepper is assigned to the first unused E plug on the board.
 *
 * The following Dual X Carriage modes can be selected with M605 S<mode>:
 *
 *   0 : (FULL_CONTROL) The slicer has full control over both X-carriages and can achieve optimal travel
 *       results as long as it supports dual X-carriages. (M605 S0)
 *
 *   1 : (AUTO_PARK) The firmware automatically parks and unparks the X-carriages on tool-change so
 *       that additional slicer support is not required. (M605 S1)
 *
 *   2 : (DUPLICATION) The firmware moves the second X-carriage and extruder in synchronization with
 *       the first X-carriage and extruder, to print 2 copies of the same object at the same time.
 *       Set the constant X-offset and temperature differential with M605 S2 X[offs] R[deg] and
 *       follow with M605 S2 to initiate duplicated movement.
 *
 *   3 : (MIRRORED) Formbot/Vivedino-inspired mirrored mode in which the second extruder duplicates
 *       the movement of the first except the second extruder is reversed in the X axis.
 *       Set the initial X offset and temperature differential with M605 S2 X[offs] R[deg] and
 *       follow with M605 S3 to initiate mirrored movement.
 * 
 * 这种结构有两个可以**独立移动**的X轴滑座，每个滑座都带一个独立喷头。
 * 你可以用它打印双色/双材料模型，或者开启
 * "复制模式" 同时打印两个完全一样、或X轴镜像的模型。
 * 不工作的喷头会**自动归位停靠**，防止漏料。
 * X1 = 左边滑座，X2 = 右边滑座。它们分别在X轴两端回零、停靠。
 * 默认情况下，X2 步进电机接在主板上**第一个空闲的E（挤出）接口**。
 *
 * 可以用指令 M605 S<模式> 切换以下双X滑座模式：
 *
 * 0 : (FULL_CONTROL) 切片软件完全控制两个滑座，
 *     只要切片支持双X轴，就能达到最佳运动效果。(M605 S0)
 *
 * 1 : (AUTO_PARK) 固件在切换喷头时**自动停靠/启用**滑座，
 *     切片软件不需要特殊支持。(M605 S1)
 *
 * 2 : (DUPLICATION) 固件同步控制第二个滑座，
 *     同时打印**两个一模一样**的模型。
 *     用 M605 S2 X[偏移] R[温差] 设置间距和温度，
 *     再发 M605 S2 启动复制打印。
 *
 * 3 : (MIRRORED) 镜像模式，
 *     第二个喷头和第一个动作完全一样，只是**X轴方向相反**。
 *     用 M605 S2 X[偏移] R[温差] 设置初始间距，
 *     再发 M605 S3 启动镜像打印。
 */
//#define DUAL_X_CARRIAGE
#if ENABLED(DUAL_X_CARRIAGE)
  #define X1_MIN_POS X_MIN_POS    // Set to X_MIN_POS                                                       // 设置为 X_MIN_POS 的值
  #define X1_MAX_POS X_BED_SIZE   // A max coordinate so the X1 carriage can't hit the parked X2 carriage   // 设置一个最大坐标限制，让 X1 滑座不会撞到停靠状态的 X2 滑座
  #define X2_MIN_POS    80        // A min coordinate so the X2 carriage can't hit the parked X1 carriage   // 设置一个最小坐标限制，让 X2 滑座不会撞到停靠状态的 X1 滑座
  #define X2_MAX_POS   353        // The max position of the X2 carriage, typically also the home position  // X2 滑座的最大位置，通常也是它的回零（原点）位置
  #define X2_HOME_POS X2_MAX_POS  // Default X2 home position. Set to X2_MAX_POS.                           // 默认 X2 回零位置。设置为 X2_MAX_POS 的值。
                                  // NOTE: For Dual X Carriage use M218 T1 Xn to override the X2_HOME_POS.
                                  // This allows recalibration of endstops distance without a rebuild.
                                  // Remember to set the second extruder's X-offset to 0 in your slicer.
                                  // 注意：对于双X滑座结构，请使用指令 M218 T1 Xn 来覆盖 X2_HOME_POS。
                                  // 这样可以**无需重新编译固件**就能重新校准两个限位开关之间的距离。
                                  // 记得在切片软件里，将第二个挤出机的 X 偏移量设置为 0。

  // This is the default power-up mode which can be changed later using M605 S<mode>. // 这是开机默认的工作模式，后续可通过指令 M605 S<模式> 随时修改。
  #define DEFAULT_DUAL_X_CARRIAGE_MODE DXC_AUTO_PARK_MODE

  // Default x offset in duplication mode (typically set to half print bed width)     // 复制模式下的默认 X 轴偏移量（通常设置为打印平台宽度的一半）
  #define DEFAULT_DUPLICATION_X_OFFSET 100

  // Default action to execute following M605 mode change commands. Typically G28X to apply new mode.
  // 切换 M605 双X轴模式后，默认执行的动作。
  // 通常设置为 G28X（X轴回零），使新模式生效。
  //#define EVENT_GCODE_IDEX_AFTER_MODECHANGE "G28X"
#endif


//============================================ 多步进电机配置区 ====================================================
// @section multi stepper

/**
 * Multi-Stepper / Multi-Endstop
 *
 * When X2_DRIVER_TYPE is defined, this indicates that the X and X2 motors work in tandem.
 * The following explanations for X also apply to Y and Z multi-stepper setups.
 * Endstop offsets may be changed by 'M666 X<offset> Y<offset> Z<offset>' and stored to EEPROM.
 *
 * - Enable INVERT_X2_VS_X_DIR if the X2 motor requires an opposite DIR signal from X.
 *
 * - Enable X_DUAL_ENDSTOPS if the second motor has its own endstop, with adjustable offset.
 *
 *   - Extra endstops are included in the output of 'M119'.
 *
 *   - Set X_DUAL_ENDSTOP_ADJUSTMENT to the known error in the X2 endstop.
 *     Applied to the X2 motor on 'G28' / 'G28 X'.
 *     Get the offset by homing X and measuring the error.
 *     Also set with 'M666 X<offset>' and stored to EEPROM with 'M500'.
 *
 *   - Define the extra endstop pins here to override defaults. No auto-assignment.
 * 
 * 多步进电机 / 双限位开关
 *
 * 当定义了 X2_DRIVE_TYPE 时，表示 X 和 X2 电机会**同步一起运动**。
 * 下面关于 X 轴的说明，同样适用于 Y 轴和 Z 轴的多电机配置。
 *
 * 限位偏移量可以通过指令 'M666 X<偏移值> Y<偏移值> Z<偏移值>' 修改，并保存到 EEPROM。
 *
 * - 如果 X2 电机需要与 X 电机**方向相反**，启用 INVERT_X2_VS_X_DIR。
 *
 * - 如果第二个电机带有**独立限位开关**，启用 X_DUAL_ENDSTOPS，支持偏移校准。
 *
 *   - 额外的限位开关会在 'M119' 指令中显示状态。
 *
 *   - 设置 X_DUAL_ENDSTOP_ADJUSTMENT 修正 X2 限位的误差。
 *     执行 'G28' / 'G28 X' 回零时会自动应用。
 *     偏移值通过回零后测量误差获得。
 *     也可以用 'M666 X<偏移>' 设置，并用 'M500' 保存。
 *
 *   - 在此定义额外的限位引脚以覆盖默认值，**不会自动分配**。
 */
#if HAS_X2_STEPPER && DISABLED(DUAL_X_CARRIAGE)
  //#define INVERT_X2_VS_X_DIR        // X2 direction signal is the opposite of X    // X2 方向信号与 X 轴相反
  //#define X_DUAL_ENDSTOPS           // X2 has its own endstop                      // X2 拥有独立的限位开关
  #if ENABLED(X_DUAL_ENDSTOPS)
    //#define X2_STOP_PIN X_MAX_PIN   // X2 endstop pin override                     // 自定义 / 重定义 X2 限位开关的引脚
    #define X2_ENDSTOP_ADJUSTMENT  0  // X2 offset relative to X endstop             // X2 相对于 X 限位开关的偏移量
  #endif                              //（译者注）：
                                      // 这是双电机 + 双限位（双 X / 双 Z 最常用）的校准参数：
                                      // X 和 X2 是带动同一根轴的两个电机
                                      // 因为机械安装不可能完美对齐，所以两个限位开关触发位置会有微小差距
                                      // 这个值就是用来补偿那个误差，让轴回零后完全水平、不歪、不斜
#endif

#if HAS_Y2_STEPPER
  //#define INVERT_Y2_VS_Y_DIR        // Y2 direction signal is the opposite of Y    // Y2 方向信号与 Y 轴相反
  //#define Y_DUAL_ENDSTOPS           // Y2 has its own endstop                      // Y2 拥有独立的限位开关
  #if ENABLED(Y_DUAL_ENDSTOPS)
    //#define Y2_STOP_PIN Y_MAX_PIN   // Y2 endstop pin override                     // 自定义 / 重定义 Y2 限位开关的引脚
    #define Y2_ENDSTOP_ADJUSTMENT  0  // Y2 offset relative to Y endstop             // Y2 相对于 Y 限位开关的偏移量(用于补偿两个限位开关安装位置的微小差距)
  #endif
#endif

//
// Multi-Z steppers
//
#ifdef Z2_DRIVER_TYPE
  //#define INVERT_Z2_VS_Z_DIR        // Z2 direction signal is the opposite of Z    // Z2 方向信号与 Z 轴相反

  //#define Z_MULTI_ENDSTOPS          // Other Z axes have their own endstops        // 其余Z轴均配备独立限位开关
  #if ENABLED(Z_MULTI_ENDSTOPS)
    //#define Z2_STOP_PIN X_MAX_PIN   // Z2 endstop pin override                     // 自定义 / 重定义 Z2 限位开关的引脚
    #define Z2_ENDSTOP_ADJUSTMENT 0   // Z2 offset relative to Z endstop             // Z2限位相对主Z限位的偏移补偿值(用于补偿两个限位开关安装位置的微小差距)
  #endif
  #ifdef Z3_DRIVER_TYPE
    //#define INVERT_Z3_VS_Z_DIR      // Z3 direction signal is the opposite of Z    // Z3 方向信号与 Z 轴相反
    #if ENABLED(Z_MULTI_ENDSTOPS)
      //#define Z3_STOP_PIN Y_MAX_PIN // Z3 endstop pin override                     // 自定义 / 重定义 Z3 限位开关的引脚
      #define Z3_ENDSTOP_ADJUSTMENT 0 // Z3 offset relative to Z endstop             // Z3限位相对主Z限位的偏移补偿值(用于补偿两个限位开关安装位置的微小差距)
    #endif
  #endif
  #ifdef Z4_DRIVER_TYPE
    //#define INVERT_Z4_VS_Z_DIR      // Z4 direction signal is the opposite of      // Z4 方向信号与 Z 轴相反
    #if ENABLED(Z_MULTI_ENDSTOPS)
      //#define Z4_STOP_PIN Z_MAX_PIN // Z4 endstop pin override                     // 自定义 / 重定义 Z4 限位开关的引脚
      #define Z4_ENDSTOP_ADJUSTMENT 0 // Z4 offset relative to Z endstop             // Z4限位相对主Z限位的偏移补偿值(用于补偿两个限位开关安装位置的微小差距)
    #endif
  #endif
#endif

// Drive the E axis with two synchronized steppers                                   // 使用两台同步步进电机驱动挤出E轴
//#define E_DUAL_STEPPER_DRIVERS
#if ENABLED(E_DUAL_STEPPER_DRIVERS)
  //#define INVERT_E1_VS_E0_DIR       // E direction signals are opposites           // 两路挤出电机转动方向相反
#endif


//============================================= 挤出机配置区 ======================================================
// @section extruder

// Activate a solenoid on the active extruder with M380. Disable all with M381.
// Define SOL0_PIN, SOL1_PIN, etc., for each extruder that has a solenoid.
// 使用指令 M380 激活当前挤出机上的电磁阀；使用 M381 禁用所有电磁阀。
// 为每个配备了电磁阀的挤出机定义引脚：SOL0_PIN、SOL1_PIN 等。
//#define EXT_SOLENOID

//============================================= 回零 / 归位配置区 ==================================================
// @section homing

/**
 * Homing Procedure
 * Homing (G28) does an indefinite move towards the endstops to establish
 * the position of the toolhead relative to the workspace.
 * 回零工作流程
 * 回零（G28）会让喷头朝限位开关方向持续移动，
 * 以此确定喷头相对于打印平台的初始位置。
 */

//#define SENSORLESS_BACKOFF_MM  { 2, 2, 0 }  // (linear=mm, rotational=°) Backoff from endstops before sensorless homing
                                              // （直线轴单位：毫米 / 旋转轴单位：度）
                                              // 无传感器回零（sensorless homing）时，离开限位开关的回退距离

#define HOMING_BUMP_MM      { 5, 5, 2 }       // (linear=mm, rotational=°) Backoff from endstops after first bump  // 直线轴单位毫米，旋转轴单位度，首次撞限位后回退距离
                                              // （译者注）：上面是配置轴第一次碰撞限位停下后，自动反向退回设定距离，用于二次精准找零，避免硬顶限位卡死，提升回零定位精度。
#define HOMING_BUMP_DIVISOR { 2, 2, 4 }       // Re-Bump Speed Divisor (Divides the Homing Feedrate)               // 二次碰撞回零速度系数（将回零进给速度除以该值）
                                              // （译者注）：这是二次精准回零时用的速度设置：第一次撞限位是快速的，退开后第二次再撞时，速度会变得很慢,这个数值就是减速倍数：二次回零速度 = 原回零速度 ÷ 这个数

//#define HOMING_BACKOFF_POST_MM { 2, 2, 2 }  // (linear=mm, rotational=°) Backoff from endstops after homing      // （直线轴：毫米 / 旋转轴：度）回零完成后，从限位开关处回退的距离
//#define XY_COUNTERPART_BACKOFF_MM 0         // (mm) Backoff X after homing Y, and vice-versa                     // （毫米）Y轴回零后X轴的回退距离，反之亦然

//#define QUICK_HOME                          // If G28 contains XY do a diagonal move first                       // 执行G28同时回零XY轴时，先进行斜向联动移动
                                              // （译者注）：上方选项勾选启用后，一键回零 XY 时，喷头不再单独先后走 X、走 Y，而是斜着同步移动靠近原点，适配 CoreXY 等联动结构，减少皮带拉扯，回零更顺滑。
//#define HOME_Y_BEFORE_X                     // If G28 contains XY home Y before X                                // 执行G28同时回零XY时，优先先回零Y轴，再回零X轴
                                              // （译者注）：开启后一键 XY 回零顺序变为：先归位 Y 轴到位，再执行 X 轴回零，适配部分机械结构避免走位干涉，按需调换 XY 回零先后次序。
//#define HOME_Z_FIRST                        // Home Z first. Requires a real endstop (not a probe).              // 优先先回零Z轴，此功能需使用实体限位开关，不可用调平探头替代
                                              // （译者注）：开启后整机回零最先抬升 Z 轴，避免喷头刮蹭热床造成磕碰损伤；注意必须接独立 Z 物理限位，仅靠自动调平探头无法启用该模式。
//#define CODEPENDENT_XY_HOMING               // If X/Y can't home without homing Y/X first                        // 若X轴/ Y轴无法单独回零，必须先完成另一轴回零才可执行
                                              // （译者注）：部分机型机械结构存在走位干涉，单独回 X 或单独回 Y 会撞机，开启后强制互锁：必须先归位其中一轴，另一轴才能正常完成回零，规避硬件碰撞。

// @section bltouch

//========================================= BLTouch自动调平探头配置区 =============================================

#if ENABLED(BLTOUCH)
  /**
   * Either: Use the defaults (recommended) or: For special purposes, use the following DEFINES
   * Do not activate settings that the probe might not understand. Clones might misunderstand
   * advanced commands.
   *
   * Note: If the probe is not deploying, do a "Reset" and "Self-Test" and then check the
   *       wiring of the BROWN, RED and ORANGE wires.
   *
   * Note: If the trigger signal of your probe is not being recognized, it has been very often
   *       because the BLACK and WHITE wires needed to be swapped. They are not "interchangeable"
   *       like they would be with a real switch. So please check the wiring first.
   *
   * Settings for all BLTouch and clone probes:
   * 
   * 两种选择：使用默认配置（推荐）；若有特殊需求，可使用下方自定义宏定义
   * 切勿启用探头不兼容的配置，仿制版探头大概率无法识别高阶指令
   * 注意：探头无法伸出时，先执行复位与自检，再检查棕、红、橙三色接线
   * 注意：探头无法识别触发信号，大多是黑白线接反所致。这两根线不像普通限位开关可随意互换，务必优先核对接线
   * 以下为所有正版及仿制 BLTouch 探头通用配置项
   */

  // Safety: The probe needs time to recognize the command.
  //         Minimum command delay (ms). Enable and increase if needed.
  // 安全项：探头需要时间来识别指令
  // 最小指令延迟时间（毫秒）。如出现异常可启用并增大该值。
  //#define BLTOUCH_DELAY 500

  /**
   * Settings for BLTOUCH Classic 1.2, 1.3 or BLTouch Smart 1.0, 2.0, 2.2, 3.0, 3.1, and most clones:
   * 适用于经典版BLTouch 1.2、1.3，以及智能版BLTouch 1.0、2.0、2.2、3.0、3.1，同时兼容绝大多数仿制探头的通用配置。
   */

  // Feature: Switch into SW mode after a deploy. It makes the output pulse longer. Can be useful
  //          in special cases, like noisy or filtered input configurations.
  // 功能：探头伸出后切换到 SW 模式，延长信号输出脉冲的时长。
  // 在某些特殊场景下很有用，例如信号有干扰、经过滤波电路的输入配置。
  //#define BLTOUCH_FORCE_SW_MODE

  /**
   * Settings for BLTouch Smart 3.0 and 3.1
   * Summary:
   *   - Voltage modes: 5V and OD (open drain - "logic voltage free") output modes
   *   - High-Speed mode
   *   - Disable LCD voltage options
   * 
   * 以下是 BLTouch Smart 3.0 和 3.1 专用设置
   * 功能概览：
   *   - 电压模式：5V 模式 和 OD 开漏模式（兼容任意逻辑电压）
   *   - 高速模式
   *   - 禁用 LCD 屏幕上的电压选项
   *
   */

  /**
   * Danger: Don't activate 5V mode unless attached to a 5V-tolerant controller!
   * V3.0 or 3.1: Set default mode to 5V mode at Marlin startup.
   * If disabled, OD mode is the hard-coded default on 3.0
   * On startup, Marlin will compare its EEPROM to this value. If the selected mode
   * differs, a mode set EEPROM write will be completed at initialization.
   * Use the option below to force an EEPROM write to a V3.1 probe regardless.
   * 
   * 危险：除非你的控制器**支持5V电压**，否则绝对不要开启5V模式！
   * V3.0 / 3.1 版本：在 Marlin 启动时将默认模式设为 5V 模式。
   * 如果关闭此选项，3.0 版本探头将默认使用 OD 模式。
   * 启动时，Marlin 会将 EEPROM 中的设置与此值对比。
   * 如果模式不一致，初始化时会自动更新 EEPROM。
   * 可使用下方选项强制将 V3.1 探头写入 EEPROM 模式。
   */
  //#define BLTOUCH_SET_5V_MODE

  // Safety: Enable voltage mode settings in the LCD menu.  // 安全设置：在液晶显示屏菜单中开放电压模式调节选项
  //#define BLTOUCH_LCD_VOLTAGE_MENU

  /**
   * Safety: Activate if connecting a probe with an unknown voltage mode.
   * V3.0: Set a probe into mode selected above at Marlin startup. Required for 5V mode on 3.0
   * V3.1: Force a probe with unknown mode into selected mode at Marlin startup ( = Probe EEPROM write )
   * To preserve the life of the probe, use this once then turn it off and re-flash.
   * 
   * 安全功能：当连接的探头电压模式未知时启用。
   * V3.0 版本：在 Marlin 启动时，将探头设置为上方选择的模式。
   *          若要在 3.0 上使用 5V 模式，此项必须开启。
   * V3.1 版本：在 Marlin 启动时强制将未知模式的探头设为选定模式（= 写入探头 EEPROM）。
   * 为延长探头寿命：仅使用一次，成功后关闭此项并重新刷固件。
   */
  //#define BLTOUCH_FORCE_MODE_SET

  /**
   * Enable "HIGH SPEED" option for probing.
   * Danger: Disable if your probe sometimes fails. Only suitable for stable well-adjusted systems.
   * This feature was designed for Deltabots with very fast Z moves; however, higher speed Cartesians
   * might be able to use it. If the machine can't raise Z fast enough the BLTouch may go into ALARM.
   *
   * Set the default state here, change with 'M401 S' or UI, use M500 to save, M502 to reset.
   * 
   * 启用探头的“高速模式”
   * 危险警告：如果你的探头偶尔失效，请关闭此功能。仅适合稳定、调试良好的设备。
   * 此功能专为 Z 轴移动极快的三角洲（Delta）机型设计；
   * 不过速度较高的笛卡尔结构机型也可能使用。
   * 如果机器 Z 轴抬升速度不够快，BLTouch 可能会触发报警。
   *
   * 在此处设置默认状态，可通过指令 M401 S 或屏幕界面修改，
   * 使用 M500 保存，M502 重置。
   */
  //#define BLTOUCH_HS_MODE true

  #ifdef BLTOUCH_HS_MODE
    // The probe Z offset (M851 Z) is the height at which the probe triggers.
    // This must be large enough to keep the probe pin off the bed and prevent
    // it from snagging on the bed clips.
    // 探头 Z 偏移值（M851 Z）是探头触发时的高度。
    // 该值必须足够大，确保探针针脚不会碰到热床，
    // 并避免针脚勾到床夹、打印件边缘等障碍物。

    // （译者注）：
    // 这是在说 BLTouch 的 Z 偏移（Z Offset）：
    // Z 偏移 = 探头触发高度
    // 必须设置得足够大，保证：
    // 探针不会刮到热床
    // 移动时不会勾到夹子、打印件
    // 设太小 → 探针撞床、勾坏、报警
    #define BLTOUCH_HS_EXTRA_CLEARANCE    7 // Extra Z Clearance  // 额外 Z 安全间隙 / 抬升余量
  #endif

#endif // BLTOUCH


//========================================== 校准配置区 =============================================
// @section calibrate

/**
 * Z Steppers Auto-Alignment
 * Add the G34 command to align multiple Z steppers using a bed probe.
 * Z 电机自动对齐
 * 添加 G34 指令，通过调平探头自动校准多 Z 轴电机（双Z / 三Z 机器）
 * 
 * （译者注）：
 * 这是双 Z 轴 / 三 Z 轴打印机专用功能：
 * 很多打印机有 2 个或 3 个 Z 电机
 * 如果两边高度不一样 → 热床倾斜、打印一边高一边低
 * 开启后，可用指令 G34 让机器自动调平两侧 Z 轴，让热床完全水平
 */
//#define Z_STEPPER_AUTO_ALIGN
#if ENABLED(Z_STEPPER_AUTO_ALIGN)
  /**
   * Define probe X and Y positions for Z1, Z2 [, Z3 [, Z4]]
   * These positions are machine-relative and do not shift with the M206 home offset!
   * If not defined, probe limits will be used.
   * Override with 'M422 S<index> X<pos> Y<pos>'.
   * 
   * 为 Z1、Z2 [, Z3 [, Z4]] 定义调平探头的 X、Y 探测点坐标
   * 这些坐标是**机器绝对坐标**，不受 M206 回零偏移影响！
   * 如果不定义，将使用探头的安全边界坐标
   * 可通过指令 M422 S<序号> X<坐标> Y<坐标> 覆盖设置
   * 
   * （译者注）：
   * 这是双 Z / 三 Z 自动调平（G34） 用的参数：
   * 你要告诉固件：
   * 探测左 Z 电机时，探头要去哪个 XY 坐标
   * 探测右 Z 电机时，探头要去哪个 XY 坐标
   * 坐标是固定机器坐标，不会被其他设置改动
   */
  //#define Z_STEPPER_ALIGN_XY { {  10, 190 }, { 100,  10 }, { 190, 190 } }

  /**
   * Orientation for the automatically-calculated probe positions.
   * Override Z stepper align points with 'M422 S<index> X<pos> Y<pos>'
   * 设置自动计算的探头探测点方向/布局
   * 可使用指令 M422 S<序号> X<坐标> Y<坐标> 手动覆盖 Z 电机对齐点
   * 
   * （译者注）：
   * 这个选项是给 双 Z / 四 Z 自动调平（G34） 用的：
   * 让固件自动帮你算探测点放在哪里
   * 你只需要选方向 / 布局（比如左右、四角）
   * 不想用自动的，就用 M422 指令手动改位置
   *
   * 2 Steppers:  (0)     (1)
   *               |       |   2   |
   *               | 1   2 |       |
   *               |       |   1   |
   *
   * 3 Steppers:  (0)     (1)     (2)     (3)
   *               |   3   | 1     | 2   1 |     2 |
   *               |       |     3 |       | 3     |
   *               | 1   2 | 2     |   3   |     1 |
   *
   * 4 Steppers:  (0)     (1)     (2)     (3)
   *               | 4   3 | 1   4 | 2   1 | 3   2 |
   *               |       |       |       |       |
   *               | 1   2 | 2   3 | 3   4 | 4   1 |
   */
  #ifndef Z_STEPPER_ALIGN_XY
    //#define Z_STEPPERS_ORIENTATION 0
  #endif

  /**
   * Z Stepper positions for more rapid convergence in bed alignment.
   * Requires 3 or 4 Z steppers.
   *
   * Define Stepper XY positions for Z1, Z2, Z3... corresponding to the screw
   * positions in the bed carriage, with one position per Z stepper in stepper
   * driver order.
   * 
   * Z 电机物理坐标，用于让热床对齐更快、更精准地收敛
   * 需要 3 个或 4 个 Z 电机
  
   * 定义 Z1、Z2、Z3... 电机对应的 XY 坐标
   * 坐标必须与热床/框架上的**调节螺丝实际位置**一致
   * 按电机驱动顺序，每个 Z 电机对应一个坐标点
   */
  //#define Z_STEPPER_ALIGN_STEPPER_XY { { 210.7, 102.5 }, { 152.6, 220.0 }, { 94.5, 102.5 } }

  #ifndef Z_STEPPER_ALIGN_STEPPER_XY
    // Amplification factor. Used to scale the correction step up or down in case                   // 放大系数。当步进电机（丝杆）的实际位置比测试点更远时，
    // the stepper (spindle) position is farther out than the test point.                           // 用这个系数来放大或缩小每一步的修正量。
    #define Z_STEPPER_ALIGN_AMP 1.0       // Use a value > 1.0 NOTE: This may cause instability!    // 使用大于 1.0 的数值。注意：这可能会导致系统不稳定！
  #endif

  // On a 300mm bed a 5% grade would give a misalignment of ~1.5cm                                    // 以300毫米尺寸热床为例，5%的倾斜坡度会造成约1.5厘米的高度偏差
  #define G34_MAX_GRADE              5    // (%) Maximum incline that G34 will handle                 // G34 指令能处理的**最大热床倾斜百分比**
  #define Z_STEPPER_ALIGN_ITERATIONS 5    // Number of iterations to apply during alignment           // 自动对齐过程中的迭代次数（修正循环次数）
  #define Z_STEPPER_ALIGN_ACC        0.02 // Stop iterating early if the accuracy is better than this // 当精度高于（小于等于）此值时，停止修正

  #define RESTORE_LEVELING_AFTER_G34      // Restore leveling after G34 is done?                      // G34多Z轴对齐完成后，是否恢复原有调平数据

  // After G34, re-home Z (G28 Z) or just calculate it from the last probe heights?
  // Re-homing might be more precise in reproducing the actual 'G28 Z' homing height, especially on an uneven bed.
  // G34 完成后，重新执行 Z 轴回零 (G28 Z)？还是仅根据最后一次探测高度直接计算？
  // 重新回零（G28 Z）能更精准地复现真实的回零高度，尤其在热床不平整的机器上效果更好。
  #define HOME_AFTER_G34

  /**
   * Commands to execute at the start of G34 probing,
   * after switching to the PROBING_TOOL.
   * G34探测流程开始时执行的自定义指令
   * 切换至探测专用工具模式后运行
   */
  //#define EVENT_GCODE_BEFORE_G34 "M300 P440 S200"

  /**
   * Commands to execute at the end of G34 probing.
   * Useful to retract or move the Z probe out of the way.
   * G34探测结束后执行自定义G代码指令
   * 适合收回探针、移动探头避让等收尾动作
   */
  //#define EVENT_GCODE_AFTER_G34 "G1 Z10 F12000\nG1 X15 Y330\nG1 Z0.5\nG1 Z10"

#endif // Z_STEPPER_AUTO_ALIGN

/**
 * Assisted Tramming   // 辅助调平（手动丝杆辅助找平）
 *
 * Add the G35 command to measure bed corners and help adjust screws. Requires a bed probe.         // 启用G35指令，探测热床四角高度，辅助手动调节调平螺丝，需搭配床面探针使用
 *                                                                                                  //（译者注）：运行G35后机器自动测四个角高度差，直观提示哪颗螺丝该调高 / 调低，手动拧螺丝找平热床，是辅助校平专用指令。
 */
//#define ASSISTED_TRAMMING
#if ENABLED(ASSISTED_TRAMMING)

  // Define from 3 to 9 points to probe.      // 定义3至9个探测采样点位
  #define TRAMMING_POINT_XY { {  20, 20 }, { 180,  20 }, { 180, 180 }, { 20, 180 } }

  // Define position names for probe points.  // 为各个探测点位自定义命名
  #define TRAMMING_POINT_NAME_1 "Front-Left"
  #define TRAMMING_POINT_NAME_2 "Front-Right"
  #define TRAMMING_POINT_NAME_3 "Back-Right"
  #define TRAMMING_POINT_NAME_4 "Back-Left"

  #define RESTORE_LEVELING_AFTER_G35    // Enable to restore leveling setup after operation             // 开启后，操作结束自动恢复原有调平配置
  //#define REPORT_TRAMMING_MM          // Report Z deviation (mm) for each point relative to the first // 报告每个探测点相对于第一个点的 Z 轴高度偏差（单位：毫米）

  //#define ASSISTED_TRAMMING_WIZARD    // Add a Tramming Wizard to the LCD menu                        // 在液晶屏幕菜单中加入热床调平向导功能

  //#define ASSISTED_TRAMMING_WAIT_POSITION { X_CENTER, Y_CENTER, 30 } // Move the nozzle out of the way for adjustment // 调平操作时移动喷头避让，方便手动调节螺丝

  /**
   * Screw Thread. Use one of the following defines:        // 螺丝螺纹规格（螺距）。使用以下定义中的一种：
   *
   *   M3_CW = M3 Clockwise, M3_CCW = M3 Counter-Clockwise  // M3_CW  = M3螺丝 顺时针拧紧（升高）  M3_CCW = M3螺丝 逆时针拧紧（升高）
   *   M4_CW = M4 Clockwise, M4_CCW = M4 Counter-Clockwise  // M4_CW  = M4螺丝 顺时针拧紧（升高）  M4_CCW = M4螺丝 逆时针拧紧（升高）
   *   M5_CW = M5 Clockwise, M5_CCW = M5 Counter-Clockwise  // M5_CW  = M5螺丝 顺时针拧紧（升高）  M5_CCW = M5螺丝 逆时针拧紧（升高）
   *
   * :{'M3_CW':'M3 Clockwise','M3_CCW':'M3 Counter-Clockwise','M4_CW':'M4 Clockwise','M4_CCW':'M4 Counter-Clockwise','M5_CW':'M5 Clockwise','M5_CCW':'M5 Counter-Clockwise'}
   */
  #define TRAMMING_SCREW_THREAD M3_CW

#endif


//=============================================== 运动控制 ===================================================
// @section motion control

/**
 * Fixed-time-based Motion Control -- BETA FEATURE
 * Enable/disable and set parameters with G-code M493.
 * See ft_types.h for named values used by FTM options.
 * 基于固定时间的运动控制 -- 测试功能（BETA）
 * 使用 G 代码 M493 启用/禁用并设置参数。
 * 查看 ft_types.h 文件获取 FTM 选项使用的命名参数值。
 */
//#define FT_MOTION
#if ENABLED(FT_MOTION)
  //#define FTM_IS_DEFAULT_MOTION                 // Use FT Motion as the factory default?                                                 // 是否将 FT 运动控制设置为出厂默认模式？
  #define FTM_DEFAULT_DYNFREQ_MODE dynFreqMode_DISABLED // Default mode of dynamic frequency calculation. (DISABLED, Z_BASED, MASS_BASED)  // 动态频率计算的默认模式（可选：关闭、基于Z轴、基于质量）
  #define FTM_DEFAULT_SHAPER_X      ftMotionShaper_NONE // Default shaper mode on X axis (NONE, ZV, ZVD, ZVDD, ZVDDD, EI, 2HEI, 3HEI, MZV) // X 轴默认振动抑制模式（可选：关闭、ZV、ZVD、ZVDD、ZVDDD、EI、2HEI、3HEI、MZV）
  #define FTM_DEFAULT_SHAPER_Y      ftMotionShaper_NONE // Default shaper mode on Y axis                                // Y 轴默认振动抑制模式
  #define FTM_SHAPING_DEFAULT_FREQ_X   37.0f      // (Hz) Default peak frequency used by input shapers                  // (赫兹) 输入整形器使用的默认峰值频率
  #define FTM_SHAPING_DEFAULT_FREQ_Y   37.0f      // (Hz) Default peak frequency used by input shapers                  // (赫兹) 输入整形器使用的默认峰值频率
                                                                                                                        //（译者注）：数值 = 你的机架一秒钟震动多少次，固件根据这个频率抵消抖动，让打印没有波纹
  #define FTM_LINEAR_ADV_DEFAULT_ENA   false      // Default linear advance enable (true) or disable (false)            // 默认是否启用 线性推进 (Linear Advance)（作用：让出料更精准，消除打印边角鼓包、拉丝。）
  #define FTM_LINEAR_ADV_DEFAULT_K      0.0f      // Default linear advance gain. (Acceleration-based scaling factor.)  // 默认线性推进增益系数（基于加速度的比例系数）
  #define FTM_SHAPING_ZETA_X            0.1f      // Zeta used by input shapers for X axis                              // X 轴输入整形器使用的阻尼系数（Zeta）
  #define FTM_SHAPING_ZETA_Y            0.1f      // Zeta used by input shapers for Y axis                              // Y 轴输入整形器使用的阻尼系数（Zeta）

  #define FTM_SHAPING_V_TOL_X           0.05f     // Vibration tolerance used by EI input shapers for X axis            // X 轴 EI 型振动抑制器 使用的 振动容差值
  #define FTM_SHAPING_V_TOL_Y           0.05f     // Vibration tolerance used by EI input shapers for Y axis            // Y 轴 EI 型振动抑制器 使用的 振动容差值

  //#define FT_MOTION_MENU                        // Provide a MarlinUI menu to set M493 parameters                     // 在屏幕菜单中提供设置 M493 参数的选项

  /**
   * Advanced configuration     // 高级配置项
   */
  #define FTM_UNIFIED_BWS                         // DON'T DISABLE unless you use Ulendo FBS (not implemented)         // 不要禁用此选项，除非你使用 Ulendo FBS（本固件尚未支持）（Ulendo FBS：一种第三方的振动补偿软件 / 算法）
  #if ENABLED(FTM_UNIFIED_BWS)
    #define FTM_BW_SIZE               100         // Unified Window and Batch size with a ratio of 2                   // 统一窗口大小与批处理大小，采用 2 倍比例关系
  #else
    #define FTM_WINDOW_SIZE           200         // Custom Window size for trajectory generation needed by Ulendo FBS // 为 Ulendo FBS 系统所需的轨迹生成自定义窗口大小
    #define FTM_BATCH_SIZE            100         // Custom Batch size for trajectory generation needed by Ulendo FBS  // 为 Ulendo FBS 系统所需的轨迹生成自定义批处理大小
  #endif

  #define FTM_FS                     1000         // (Hz) Frequency for trajectory generation. (Reciprocal of FTM_TS)  // (赫兹) 轨迹生成频率（是 FTM_TS 的倒数）
  #define FTM_TS                        0.001f    // (s) Time step for trajectory generation. (Reciprocal of FTM_FS)   // (秒) 轨迹生成的时间步长（是 FTM_FS 的倒数）

  #if DISABLED(COREXY)
    #define FTM_STEPPER_FS          20000         // (Hz) Frequency for stepper I/O update                             // (赫兹) 步进电机 I/O 更新频率

    // Use this to adjust the time required to consume the command buffer.               // 用于调整消耗命令缓冲区所需的时间。
    // Try increasing this value if stepper motion is choppy.                            // 如果步进电机运动出现卡顿、不流畅，尝试增大这个值。
    #define FTM_STEPPERCMD_BUFF_SIZE 3000         // Size of the stepper command buffers // 步进电机指令缓冲区大小

  #else
    // CoreXY motion needs a larger buffer size. These values are based on our testing.  // CoreXY 结构需要更大的缓冲区大小。这些数值是基于我们的测试得出的。
    #define FTM_STEPPER_FS          30000
    #define FTM_STEPPERCMD_BUFF_SIZE 6000
  #endif

  #define FTM_STEPS_PER_UNIT_TIME (FTM_STEPPER_FS / FTM_FS)       // Interpolated stepper commands per unit time      // 单位时间内的插补步进指令数量
  #define FTM_CTS_COMPARE_VAL (FTM_STEPS_PER_UNIT_TIME / 2)       // Comparison value used in interpolation algorithm // 插补算法中使用的对比基准值
  #define FTM_MIN_TICKS ((STEPPER_TIMER_RATE) / (FTM_STEPPER_FS)) // Minimum stepper ticks between steps              // 步进电机 两步之间的最小时间间隔（最小脉冲间隔）

  #define FTM_MIN_SHAPE_FREQ           10         // Minimum shaping frequency                                        // 最小整形频率
  #define FTM_RATIO (FTM_FS / FTM_MIN_SHAPE_FREQ) // Factor for use in FTM_ZMAX. DON'T CHANGE.                        // 用于计算 FTM_ZMAX 的系数。禁止修改。
  #define FTM_ZMAX (FTM_RATIO * 2)                // Maximum delays for shaping functions (even numbers only!)        // 整形功能（振动抑制）的最大延迟值（必须是偶数！）
                                                  // Calculate as:                       // 计算方式如下：
                                                  //   ZV       : FTM_RATIO / 2          //   ZV      振动抑制类型：使用 FTM_RATIO / 2
                                                  //   ZVD, MZV : FTM_RATIO              //   ZVD、MZV 振动抑制类型：使用 FTM_RATIO
                                                  //   2HEI     : FTM_RATIO * 3 / 2      //   2HEI    振动抑制类型：使用 FTM_RATIO * 3 / 2
                                                  //   3HEI     : FTM_RATIO * 2          //   3HEI    振动抑制类型：使用 FTM_RATIO * 2
#endif

/**
 * Input Shaping
 *
 * Zero Vibration (ZV) Input Shaping for X and/or Y movements.
 *
 * This option uses a lot of SRAM for the step buffer. The buffer size is
 * calculated automatically from SHAPING_FREQ_[XYZ], DEFAULT_AXIS_STEPS_PER_UNIT,
 * DEFAULT_MAX_FEEDRATE and ADAPTIVE_STEP_SMOOTHING. The default calculation can
 * be overridden by setting SHAPING_MIN_FREQ and/or SHAPING_MAX_FEEDRATE.
 * The higher the frequency and the lower the feedrate, the smaller the buffer.
 * If the buffer is too small at runtime, input shaping will have reduced
 * effectiveness during high speed movements.
 *
 * Tune with M593 D<factor> F<frequency>
 * 
 *  输入整形（振动抑制）
 *
 * 零振动（ZV）输入整形：用于 X / Y 轴运动
 *
 * 该功能会占用大量的步进缓存内存。
 * 缓存大小由以下参数自动计算：
 *   SHAPING_FREQ_[XYZ]、
 *   DEFAULT_AXIS_STEPS_PER_UNIT、
 *   DEFAULT_MAX_FEEDRATE、
 *   ADAPTIVE_STEP_SMOOTHING
 *
 * 你可以手动设置 SHAPING_MIN_FREQ 和/或 SHAPING_MAX_FEEDRATE 来覆盖默认值。
 * 频率越高、速度越低，占用的缓存就越小。
 * 如果运行时缓存太小，高速运动下振动抑制效果会下降。
 *
 * 使用指令 M593 D<系数> F<频率> 进行调试
 */
//#define INPUT_SHAPING_X
//#define INPUT_SHAPING_Y
//#define INPUT_SHAPING_Z
#if ANY(INPUT_SHAPING_X, INPUT_SHAPING_Y, INPUT_SHAPING_Z)
  #if ENABLED(INPUT_SHAPING_X)
    #define SHAPING_FREQ_X  40.0        // (Hz) The default dominant resonant frequency on the X axis.                               // (Hz) X 轴的默认主共振频率
    #define SHAPING_ZETA_X   0.15       // Damping ratio of the X axis (range: 0.0 = no damping to 1.0 = critical damping).          // X 轴阻尼比（取值范围：0.0 = 无阻尼，1.0 = 临界阻尼）
  #endif
  #if ENABLED(INPUT_SHAPING_Y)
    #define SHAPING_FREQ_Y  40.0        // (Hz) The default dominant resonant frequency on the Y axis.                               // (Hz) Y 轴的默认主共振频率
    #define SHAPING_ZETA_Y   0.15       // Damping ratio of the Y axis (range: 0.0 = no damping to 1.0 = critical damping).          // Y 轴阻尼比（取值范围：0.0 = 无阻尼，1.0 = 临界阻尼）。
  #endif
  #if ENABLED(INPUT_SHAPING_Z)
    #define SHAPING_FREQ_Z  40.0        // (Hz) The default dominant resonant frequency on the Z axis.                               // (Hz) Z 轴默认主共振频率
    #define SHAPING_ZETA_Z   0.15       // Damping ratio of the Z axis (range: 0.0 = no damping to 1.0 = critical damping).          // Z 轴阻尼比（取值范围：0.0 = 无阻尼，1.0 = 临界阻尼）。
  #endif
  //#define SHAPING_MIN_FREQ  20.0      // (Hz) By default the minimum of the shaping frequencies. Override to affect SRAM usage.    // (Hz) 默认使用整形频率中的最小值。可修改此值以影响内存（SRAM）占用。
  //#define SHAPING_MAX_STEPRATE 10000  // By default the maximum total step rate of the shaped axes. Override to affect SRAM usage. // 默认使用整形轴的最大总步进速率。可修改此值以影响内存（SRAM）占用。
  //#define SHAPING_MENU                // Add a menu to the LCD to set shaping parameters.                                          // 在液晶屏菜单中添加选项，用于设置振动抑制（Input Shaping）参数。
#endif

// @section motion

#define AXIS_RELATIVE_MODES { false, false, false, false }

// Add a Duplicate option for well-separated conjoined nozzles
// 为间距合适的连体双喷/独立双喷头添加“重复打印”模式选项

// （译者注）：
// 这个功能是给双喷头打印机用的：
// 开启后，打印机屏幕 / 软件里会多出一个 Duplicate（重复模式）
// 两个喷头会打印完全一样的模型
// 相当于一次打印 2 个相同模型，效率翻倍

//#define MULTI_NOZZLE_DUPLICATION

// By default stepper drivers require an active-HIGH signal but some high-power drivers require an active-LOW signal to step.
// 步进驱动默认采用高电平有效脉冲信号，部分大功率驱动器需使用低电平有效脉冲信号
#define STEP_STATE_X HIGH
#define STEP_STATE_Y HIGH
#define STEP_STATE_Z HIGH
#define STEP_STATE_I HIGH
#define STEP_STATE_J HIGH
#define STEP_STATE_K HIGH
#define STEP_STATE_U HIGH
#define STEP_STATE_V HIGH
#define STEP_STATE_W HIGH
#define STEP_STATE_E HIGH

/**
 * Idle Stepper Shutdown
 * Enable DISABLE_IDLE_* to shut down axis steppers after an idle period.
 * The default timeout duration can be overridden with M18 and M84. Set to 0 for No Timeout.
 * 步进电机空闲断电功能
 * 开启 DISABLE_IDLE_* 相关选项，可让轴电机空闲一段时间后自动断电休眠
 * 空闲超时默认时长可通过 M18、M84 指令自定义，设为0则关闭超时永不断电
 */
#define DEFAULT_STEPPER_TIMEOUT_SEC 120
#define DISABLE_IDLE_X
#define DISABLE_IDLE_Y
#define DISABLE_IDLE_Z    // Disable if the nozzle could fall onto your printed part!             // 若喷头容易下坠砸到打印件，请关闭此功能！
//#define DISABLE_IDLE_I
//#define DISABLE_IDLE_J
//#define DISABLE_IDLE_K
//#define DISABLE_IDLE_U
//#define DISABLE_IDLE_V
//#define DISABLE_IDLE_W
#define DISABLE_IDLE_E    // Shut down all idle extruders                                         // 空闲时关闭所有挤出机电机

// Default Minimum Feedrates for printing and travel moves                                        // 打印运动和空程移动的默认最低速度
#define DEFAULT_MINIMUMFEEDRATE       0.0     // (mm/s) Minimum feedrate. Set with M205 S.        // (mm/s) 最低运动速度。可通过 M205 S 指令设置。
#define DEFAULT_MINTRAVELFEEDRATE     0.0     // (mm/s) Minimum travel feedrate. Set with M205 T. // (mm/s) 最低空程移动速度（不吐丝的快速移动）。可通过 M205 T 指令设置。

// Minimum time that a segment needs to take as the buffer gets emptied                           // 当运动缓冲即将耗尽时，单个运动段必须保持的最短时间
               // （译者注）：下面是固件保护打印机不抖、不丢步的高级参数
               // 作用：
               // 当指令来不及处理、缓存快空了
               // 固件会强制让每一小段运动多走一点点时间
               // 防止突然卡顿、抖动、撞响、丢步
#define DEFAULT_MINSEGMENTTIME        20000   // (µs) Set with M205 B.   // (µs) 可通过 M205 B 指令设置。（这是上面运动缓冲保护时间的具体数值）

// Slow down the machine if the lookahead buffer is (by default) half full.
// Increase the slowdown divisor for larger buffer sizes.
// 当前瞻缓冲达到（默认）一半时开始降低机器速度。
// 缓冲更大时，请增大这个减速除数。
#define SLOWDOWN
#if ENABLED(SLOWDOWN)
  #define SLOWDOWN_DIVISOR 2
#endif

/**
 * XY Frequency limit
 * Reduce resonance by limiting the frequency of small zigzag infill moves.
 * See https://hydraraptor.blogspot.com/2010/12/frequency-limit.html
 * Use M201 F<freq> S<min%> to change limits at runtime.
 * XY 频率限制
 * 通过限制小锯齿填充运动的频率来减少共振。
 * 详情见：https://hydraraptor.blogspot.com/2010/12/frequency-limit.html
 * 使用 M201 F<频率> S<最小百分比> 在运行时修改限制。
 */
//#define XY_FREQUENCY_LIMIT      10 // (Hz) Maximum frequency of small zigzag infill moves. Set with M201 F<hertz>.  // (Hz) 小锯齿填充运动的最大频率。使用 M201 F<赫兹> 设置。
#ifdef XY_FREQUENCY_LIMIT
  #define XY_FREQUENCY_MIN_PERCENT 5 // (%) Minimum FR percentage to apply. Set with M201 S<min%>.                    // (%) 应用频率限制时的最小进给速度百分比。使用 M201 S<百分比> 设置。
#endif

//
// Backlash Compensation
// Adds extra movement to axes on direction-changes to account for backlash.
// 间隙补偿（Backlash Compensation）
// 在轴改变运动方向时，增加一段额外的补偿移动，用来抵消机械间隙。
//
//#define BACKLASH_COMPENSATION
#if ENABLED(BACKLASH_COMPENSATION)
  // Define values for backlash distance and correction.
  // If BACKLASH_GCODE is enabled these values are the defaults.
  // 定义间隙补偿的距离和校正参数
  // 如果启用了 BACKLASH_GCODE，这些值将作为默认参数
  #define BACKLASH_DISTANCE_MM { 0, 0, 0 } // (linear=mm, rotational=°) One value for each linear axis // (linear=mm, rotational=°) 每个直线轴对应一个参数值
  #define BACKLASH_CORRECTION    0.0       // 0.0 = no correction; 1.0 = full correction               // 0.0 = 不校正；1.0 = 完全校正

  // Add steps for motor direction changes on CORE kinematics              // 对于CORE结构机型（如CoreXY/CoreXZ），在电机换向时添加补偿步数
  //#define CORE_BACKLASH

  // Set BACKLASH_SMOOTHING_MM to spread backlash correction over multiple segments
  // to reduce print artifacts. (Enabling this is costly in memory and computation!)
  // 将间隙补偿分摊到多个运动段中，减少打印瑕疵。
  // 开启此项会大幅消耗内存和运算能力！
  //#define BACKLASH_SMOOTHING_MM 3 // (mm)

  // Add runtime configuration and tuning of backlash values (M425)        // 启用间隙补偿值的实时配置与调谐功能（指令：M425）
  //#define BACKLASH_GCODE

  #if ENABLED(BACKLASH_GCODE)
    // Measure the Z backlash when probing (G29) and set with "M425 Z"     // 在自动调平（G29）时测量Z轴间隙，并通过 M425 Z 指令应用
    #define MEASURE_BACKLASH_WHEN_PROBING

    #if ENABLED(MEASURE_BACKLASH_WHEN_PROBING)
      // When measuring, the probe will move up to BACKLASH_MEASUREMENT_LIMIT
      // mm away from point of contact in BACKLASH_MEASUREMENT_RESOLUTION
      // increments while checking for the contact to be broken.
      // 测量时，探针会以 BACKLASH_MEASUREMENT_RESOLUTION
      // 为步距，向上移动最多 BACKLASH_MEASUREMENT_LIMIT 毫米
      // 同时检测触点是否断开，以此测量间隙。
      #define BACKLASH_MEASUREMENT_LIMIT       0.5   // (mm)
      #define BACKLASH_MEASUREMENT_RESOLUTION  0.005 // (mm)
      #define BACKLASH_MEASUREMENT_FEEDRATE    Z_PROBE_FEEDRATE_SLOW // (mm/min)
    #endif
  #endif
#endif

/**
 * Automatic backlash, position, and hotend offset calibration
 *
 * Enable G425 to run automatic calibration using an electrically-
 * conductive cube, bolt, or washer mounted on the bed.
 *
 * G425 uses the probe to touch the top and sides of the calibration object
 * on the bed and measures and/or correct positional offsets, axis backlash
 * and hotend offsets.
 *
 * Note: HOTEND_OFFSET and CALIBRATION_OBJECT_CENTER must be set to within
 *       ±5mm of true values for G425 to succeed.
 * 
 * 自动间隙、位置和喷头偏移量校准
 *
 * 启用 G425 指令，使用安装在热床上的导电金属块、螺丝或垫片进行自动校准。
 * G425 会让探头触碰热床上校准物的顶面和侧面，
 * 测量并修正：位置偏移、轴间隙、喷头偏移量。
 *
 * 注意：HOTEND_OFFSET（喷头偏移）和 CALIBRATION_OBJECT_CENTER（校准物中心）
 *       必须设置在真实值的 ±5mm 范围内，G425 才能正常工作。
 */
//#define CALIBRATION_GCODE
#if ENABLED(CALIBRATION_GCODE)

  //#define CALIBRATION_SCRIPT_PRE  "M117 Starting Auto-Calibration\nT0\nG28\nG12\nM117 Calibrating..."
  //#define CALIBRATION_SCRIPT_POST "M500\nM117 Calibration data saved"

  #define CALIBRATION_FEEDRATE_SLOW             60    // (mm/min)
  #define CALIBRATION_FEEDRATE_FAST           1200    // (mm/min)
  #define CALIBRATION_FEEDRATE_TRAVEL         3000    // (mm/min)

  // The following parameters refer to the conical section of the nozzle tip.   // 以下参数均对应喷嘴头部的锥面结构
  #define CALIBRATION_NOZZLE_TIP_HEIGHT          1.0  // (mm)
  #define CALIBRATION_NOZZLE_OUTER_DIAMETER      2.0  // (mm)

  // Uncomment to enable reporting (required for "G425 V", but consumes flash). // 取消注释开启数据上报功能（G425 V指令必备），会占用闪存空间
  //#define CALIBRATION_REPORTING

  // The true location and dimension the cube/bolt/washer on the bed.           // 热床上校准用金属方块、螺栓、垫片的实际位置与尺寸
  #define CALIBRATION_OBJECT_CENTER     { 264.0, -22.0,  -2.0 } // (mm)
  #define CALIBRATION_OBJECT_DIMENSIONS {  10.0,  10.0,  10.0 } // (mm)

  // Comment out any sides which are unreachable by the probe. For best
  // auto-calibration results, all sides must be reachable.
  // 注释掉探头无法触碰到的任何面。
  // 为获得最佳自动校准效果，探头必须能触碰到所有面。
  #define CALIBRATION_MEASURE_RIGHT
  #define CALIBRATION_MEASURE_FRONT
  #define CALIBRATION_MEASURE_LEFT
  #define CALIBRATION_MEASURE_BACK

  //#define CALIBRATION_MEASURE_IMIN
  //#define CALIBRATION_MEASURE_IMAX
  //#define CALIBRATION_MEASURE_JMIN
  //#define CALIBRATION_MEASURE_JMAX
  //#define CALIBRATION_MEASURE_KMIN
  //#define CALIBRATION_MEASURE_KMAX
  //#define CALIBRATION_MEASURE_UMIN
  //#define CALIBRATION_MEASURE_UMAX
  //#define CALIBRATION_MEASURE_VMIN
  //#define CALIBRATION_MEASURE_VMAX
  //#define CALIBRATION_MEASURE_WMIN
  //#define CALIBRATION_MEASURE_WMAX

  // Probing at the exact top center only works if the center is flat. If
  // probing on a screw head or hollow washer, probe near the edges.
  // 仅当校准物顶部中心位置是平面时，才能在正中心进行探测。
  // 如果探测点在螺丝头或空心垫片上，请在边缘位置探测。
  //#define CALIBRATION_MEASURE_AT_TOP_EDGES

  // Define the pin to read during calibration
  #ifndef CALIBRATION_PIN
    //#define CALIBRATION_PIN -1            // Define here to override the default pin  // 在此处定义，以覆盖默认引脚
    #define CALIBRATION_PIN_INVERTING false // Set to true to invert the custom pin     // 设置为 true 反转自定义引脚的电平信号
    //#define CALIBRATION_PIN_PULLDOWN
    #define CALIBRATION_PIN_PULLUP
  #endif
#endif

/**
 * Multi-stepping sends steps in bursts to reduce MCU usage for high step-rates.
 * This allows higher feedrates than the MCU could otherwise support.
 * 多步脉冲模式：批量发送步进脉冲，降低高步数速率下的 MCU（主控芯片）占用率。
 * 这能实现比主控芯片常规支持更高的打印进给速度。
 */
#define MULTISTEPPING_LIMIT   16  // :[1, 2, 4, 8, 16, 32, 64, 128]

/**
 * Adaptive Step Smoothing increases the resolution of multi-axis moves, particularly at step frequencies
 * below 1kHz (for AVR) or 10kHz (for ARM), where aliasing between axes in multi-axis moves causes audible
 * vibration and surface artifacts. The algorithm adapts to provide the best possible step smoothing at the
 * lowest stepping frequencies.
 * 自适应步进平滑处理：提升多轴运动的分辨率，尤其在步进频率
 * 低于 1kHz（AVR 主板）或 10kHz（ARM 主板）时，多轴运动中的轴间信号混叠
 * 会产生可听见的振动和打印面瑕疵。该算法会自适应调整，
 * 在最低步进频率下提供最佳的步进平滑效果。
 */
//#define ADAPTIVE_STEP_SMOOTHING

/**
 * Custom Microstepping
 * Override as-needed for your setup. Up to 3 MS pins are supported.
 * 自定义细分模式（Custom Microstepping）
 * 根据你的设备需求覆盖默认设置。最多支持 3 个细分（MS）引脚。
 */
//#define MICROSTEP1 LOW,LOW,LOW
//#define MICROSTEP2 HIGH,LOW,LOW
//#define MICROSTEP4 LOW,HIGH,LOW
//#define MICROSTEP8 HIGH,HIGH,LOW
//#define MICROSTEP16 LOW,LOW,HIGH
//#define MICROSTEP32 HIGH,LOW,HIGH

// Microstep settings (Requires a board with pins named X_MS1, X_MS2, etc.)
// 电机细分设置 (需要主板带有 X_MS1, X_MS2 等专用引脚)
#define MICROSTEP_MODES { 16, 16, 16, 16, 16, 16 } // [1,2,4,8,16]
// 上面宏定义里面的 6 个数字，依次对应：X、Y、Z、E0、E1、E2 电机
// 16 代表 16 细分（最常用、最平衡的设置）


//======================================= 步进电机电流参数区 =========================================
/**
 * @section stepper motor current
 *
 * Some boards have a means of setting the stepper motor current via firmware.
 *
 * The power on motor currents are set by:
 *   PWM_MOTOR_CURRENT - used by MINIRAMBO & ULTIMAIN_2
 *                        known compatible chips: A4982
 *   DIGIPOT_MOTOR_CURRENT - used by BQ_ZUM_MEGA_3D, RAMBO & SCOOVO_X9H
 *                        known compatible chips: AD5206
 *   DAC_MOTOR_CURRENT_DEFAULT - used by PRINTRBOARD_REVF & RIGIDBOARD_V2
 *                        known compatible chips: MCP4728
 *   DIGIPOT_I2C_MOTOR_CURRENTS - used by 5DPRINT, AZTEEG_X3_PRO, AZTEEG_X5_MINI_WIFI, MIGHTYBOARD_REVE
 *                        known compatible chips: MCP4451, MCP4018
 *
 * Motor currents can also be set by M907 - M910 and by the LCD.
 *   M907 - applies to all.
 *   M908 - BQ_ZUM_MEGA_3D, RAMBO, PRINTRBOARD_REVF, RIGIDBOARD_V2 & SCOOVO_X9H
 *   M909, M910 & LCD - only PRINTRBOARD_REVF & RIGIDBOARD_V2
 * 
 * 部分主板可通过固件直接设置步进电机电流。
 * 开机电机电流由以下参数设置：
 *   PWM_MOTOR_CURRENT - 用于 MINIRAMBO & ULTIMAIN_2
 *                        兼容芯片：A4982
 *   DIGIPOT_MOTOR_CURRENT - 用于 BQ_ZUM_MEGA_3D, RAMBO & SCOOVO_X9H
 *                        兼容芯片：AD5206
 *   DAC_MOTOR_CURRENT_DEFAULT - 用于 PRINTRBOARD_REVF & RIGIDBOARD_V2
 *                        兼容芯片：MCP4728
 *   DIGIPOT_I2C_MOTOR_CURRENTS - 用于 5DPRINT, AZTEEG_X3_PRO, AZTEEG_X5_MINI_WIFI, MIGHTYBOARD_REVE
 *                        兼容芯片：MCP4451, MCP4018
 *
 * 电机电流也可通过 G 代码 M907~M910 或液晶屏设置：
 *   M907 - 对所有主板生效
 *   M908 - 用于 BQ_ZUM_MEGA_3D, RAMBO, PRINTRBOARD_REVF, RIGIDBOARD_V2 & SCOOVO_X9H
 *   M909, M910 & 液晶屏 - 仅 PRINTRBOARD_REVF & RIGIDBOARD_V2
 */
//#define PWM_MOTOR_CURRENT { 1300, 1300, 1250 }          // Values in milliamps                          // 数值单位：毫安 (mA)
//#define DIGIPOT_MOTOR_CURRENT { 135,135,135,135,135 }   // Values 0-255 (RAMBO 135 = ~0.75A, 185 = ~1A) // 数值范围 0-255 (RAMBO 主板参考：135 ≈ 0.75A, 185 ≈ 1A)
//#define DAC_MOTOR_CURRENT_DEFAULT { 70, 80, 90, 80 }    // Default drive percent - X, Y, Z, E axis      // 默认驱动电流百分比 - X、Y、Z、挤出机轴

/**
 * I2C-based DIGIPOTs (e.g., Azteeg X3 Pro)    * 基于 I2C 通讯的数字电位器（例如：Azteeg X3 Pro 主板）
 */
//#define DIGIPOT_MCP4018             // Requires https://github.com/felias-fogg/SlowSoftI2CMaster
//#define DIGIPOT_MCP4451
#if ANY(DIGIPOT_MCP4018, DIGIPOT_MCP4451)
  #define DIGIPOT_I2C_NUM_CHANNELS 8  // 5DPRINT:4   AZTEEG_X3_PRO:8   MKS_SBASE:5   MIGHTYBOARD_REVE:5

  // Actual motor currents in Amps. The number of entries must match DIGIPOT_I2C_NUM_CHANNELS.
  // These correspond to the physical drivers, so be mindful if the order is changed.
  // 实际电机电流值，单位为安培(A)。填写的项数必须与 DIGIPOT_I2C_NUM_CHANNELS 定义的通道数一致。
  // 这些数值对应物理驱动芯片的顺序，如果顺序改变请务必注意。
  #define DIGIPOT_I2C_MOTOR_CURRENTS { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 } // AZTEEG_X3_PRO

  //#define DIGIPOT_USE_RAW_VALUES    // Use DIGIPOT_MOTOR_CURRENT raw wiper values (instead of A4988 motor currents)  // 使用 DIGIPOT_MOTOR_CURRENT 原始数值（而非 A4988 电机电流）

  /**
   * Common slave addresses:   // 常用从机设备地址
   *
   *                        A   (A shifted)   B   (B shifted)  IC
   * Smoothie              0x2C (0x58)       0x2D (0x5A)       MCP4451
   * AZTEEG_X3_PRO         0x2C (0x58)       0x2E (0x5C)       MCP4451
   * AZTEEG_X5_MINI        0x2C (0x58)       0x2E (0x5C)       MCP4451
   * AZTEEG_X5_MINI_WIFI         0x58              0x5C        MCP4451
   * MIGHTYBOARD_REVE      0x2F (0x5E)                         MCP4018
   */
  //#define DIGIPOT_I2C_ADDRESS_A 0x2C  // Unshifted slave address for first DIGIPOT
  //#define DIGIPOT_I2C_ADDRESS_B 0x2D  // Unshifted slave address for second DIGIPOT
#endif

//===========================================================================
//=============================Additional Features===========================
//===========================================================================
// 附加功能 / 扩展功能区


//============================================ 显示屏配置板块 ===============================================
// @section lcd

#if HAS_MANUAL_MOVE_MENU
  #define MANUAL_FEEDRATE { 50*60, 50*60, 4*60, 2*60 } // (mm/min) Feedrates for manual moves along X, Y, Z, E from panel // (mm/min) 从操作面板手动移动 X、Y、Z、E 轴的速度
  #define FINE_MANUAL_MOVE 0.025    // (mm) Smallest manual move (< 0.1mm) applying to Z on most machines                 // (mm) 手动模式下最小移动距离 (< 0.1mm)，大多数机器仅对 Z 轴生效
  #if IS_ULTIPANEL
    #define MANUAL_E_MOVES_RELATIVE // Display extruder move distance rather than "position"      // 显示挤出机的移动距离，而非“绝对坐标位置”（开启后显示相对位置，关闭后显示绝对位置）
    #define ULTIPANEL_FEEDMULTIPLY  // Encoder sets the feedrate multiplier on the Status Screen  // 旋钮可在状态屏幕直接调整【打印速度倍率】
    //#define ULTIPANEL_FLOWPERCENT // Encoder sets the flow percentage on the Status Screen      // 旋钮可在状态屏幕直接调整【挤出流量/出料百分比】
  #endif
#endif

// Change values more rapidly when the encoder is rotated faster                     // 旋钮转动越快，参数数值变化幅度越大
#define ENCODER_RATE_MULTIPLIER
#if ENABLED(ENCODER_RATE_MULTIPLIER)
  #define ENCODER_10X_STEPS_PER_SEC   30  // (steps/s) Encoder rate for 10x speed    // (步/秒) 旋钮十倍速调节触发阈值
  #define ENCODER_100X_STEPS_PER_SEC  80  // (steps/s) Encoder rate for 100x speed   // (步/秒) 旋钮百倍速调节触发阈值
#endif

// Play a beep when the feedrate is changed from the Status Screen                   // 在状态界面调整打印速度时，蜂鸣器发出提示音
//#define BEEP_ON_FEEDRATE_CHANGE
#if ENABLED(BEEP_ON_FEEDRATE_CHANGE)
  #define FEEDRATE_CHANGE_BEEP_DURATION   10   // 提示音时长
  #define FEEDRATE_CHANGE_BEEP_FREQUENCY 440   // 提示音频率
#endif

/**
 * Probe Offset Wizard
 * Add a Probe Z Offset calibration option to the LCD menu.
 * Use this helper to get a perfect 'M851 Z' probe offset.
 * When launched this powerful wizard:
 *  - Measures the bed height at the configured position with the probe.
 *  - Moves the nozzle to the same position for a "paper" measurement.
 *  - The difference is used to set the probe Z offset.

 * 探针偏移校准向导
 * 在显示屏菜单新增探针Z轴偏移校准选项
 * 借助该功能可精准获取M851 Z探针偏移参数
 * 启动后自动完成校准流程：
 * - 探针在指定点位测量热床高度
 * - 打印嘴移动至同位置，以纸片法手动校验间隙
 * - 依据高度差值自动设定探针Z轴偏移值
 */
#if HAS_BED_PROBE && ANY(HAS_MARLINUI_MENU, HAS_TFT_LVGL_UI)
  //#define PROBE_OFFSET_WIZARD
  #if ENABLED(PROBE_OFFSET_WIZARD)
    /**
     * Enable to init the Probe Z-Offset when starting the Wizard.
     * Use a height slightly above the estimated nozzle-to-probe Z offset.
     * For example, with an offset of -5, consider a starting height of -4.

     * 开启后，启动校准向导时初始化探针Z轴偏移值
     * 初始高度取值略高于预估的喷嘴与探针Z向偏移量
     * 示例：实际偏移为-5时，初始高度可设为-4
     */
    //#define PROBE_OFFSET_WIZARD_START_Z -4.0

    // Set a convenient position to do the calibration (probing point and nozzle/bed-distance)  // 设置校准点位（探针检测与喷嘴测间隙共用位置）
    //#define PROBE_OFFSET_WIZARD_XY_POS { X_CENTER, Y_CENTER }
  #endif
#endif

#if HAS_MARLINUI_MENU

  #if HAS_BED_PROBE

    // Show Deploy / Stow Probe options in the Motion menu.                                // 在运动菜单显示探针伸出/收回操作选项
    #define PROBE_DEPLOY_STOW_MENU

    // Add calibration in the Probe Offsets menu to compensate for X-axis twist.           // 在探针偏移菜单添加校准项，用于补偿X轴形变偏差
    //#define X_AXIS_TWIST_COMPENSATION
    #if ENABLED(X_AXIS_TWIST_COMPENSATION)
      /**
       * Enable to init the Probe Z-Offset when starting the Wizard.
       * Use a height slightly above the estimated nozzle-to-probe Z offset.
       * For example, with an offset of -5, consider a starting height of -4.
       * 启用此项可在启动校准向导时自动初始化探针 Z 偏移值
       * 初始值请设置为**略高于**你预估的喷嘴 - 探针 Z 偏移量
       * 示例：若实际偏移值为 -5，建议初始高度设为 -4
       */
      #define XATC_START_Z 0.0
      #define XATC_MAX_POINTS 3             // Number of points to probe in the wizard    // 校准向导中使用的探针采样点数（译者注）：这个参数设置 Z 轴偏移校准向导 会用多少个点去测量热床，然后取平均值计算最终的 Z 偏移。
      #define XATC_Y_POSITION Y_CENTER      // (mm) Y position to probe                   // (mm) 探针采样的 Y 轴坐标位置（译者注）：这个参数用来设置自动调平探针在进行测量时，移动到的Y 轴坐标点。
      #define XATC_Z_OFFSETS { 0, 0, 0 }    // Z offsets for X axis sample points         // X 轴采样点对应的 Z 轴偏移量
    #endif

  #endif

  // Include a page of printer information in the LCD Main Menu                                    // 在液晶主菜单中加入打印机信息页面
  //#define LCD_INFO_MENU
  #if ENABLED(LCD_INFO_MENU)
    //#define LCD_PRINTER_INFO_IS_BOOTSCREEN // Show bootscreen(s) instead of Printer Info pages   // 开机展示启动画面，替代打印机信息页面
    //#define BUILD_INFO_MENU_ITEM           // Add a menu item to display the build date and time // 在菜单中添加一项，用于显示固件编译的日期与时间
  #endif

  /**
   * MarlinUI "Move Axis" menu distances. Comma-separated list.
   * Values are displayed as-defined, so always use plain numbers here.
   * Axis moves <= 1/2 the axis length and Extruder moves <= EXTRUDE_MAXLENGTH
   * will be shown in the move submenus.
   * MarlinUI “移动轴”菜单的移动距离。用逗号分隔的列表。
   * 数值会按定义直接显示，因此这里必须使用纯数字。
   * 轴移动距离 <= 轴长度的 1/2，挤出机移动距离 <= EXTRUDE_MAXLENGTH
   * 才会在移动子菜单中显示。
   */

  #define MANUAL_MOVE_DISTANCE_MM                    10, 1.0, 0.1  // (mm)
  //#define MANUAL_MOVE_DISTANCE_MM         100, 50, 10, 1.0, 0.1  // (mm)
  //#define MANUAL_MOVE_DISTANCE_MM    500, 100, 50, 10, 1.0, 0.1  // (mm)

  // Manual move distances for INCH_MODE_SUPPORT
  #define MANUAL_MOVE_DISTANCE_IN                          0.100, 0.010, 0.001  // (in)
  //#define MANUAL_MOVE_DISTANCE_IN          1.000, 0.500, 0.100, 0.010, 0.001  // (in)
  //#define MANUAL_MOVE_DISTANCE_IN   5.000, 1.000, 0.500, 0.100, 0.010, 0.001  // (in)

  // Manual move distances for rotational axes                                      // 旋转轴的手动移动距离（快捷移动步距）
  #define MANUAL_MOVE_DISTANCE_DEG             90, 45, 22.5, 5, 1  // (°)

  // BACK menu items keep the highlight at the top                                  // 返回（BACK）菜单项会保持高亮选中状态在顶部
  //#define TURBO_BACK_MENU_ITEM

  // BACK menu items show "Back" instead of the previous menu name                  // 返回菜单项显示 "Back" 文字，而不是上一级菜单的名称
  //#define GENERIC_BACK_MENU_ITEM

  // Insert a menu for preheating at the top level to allow for quick access        // 在一级菜单嵌入预热选项，方便快速调用
  //#define PREHEAT_SHORTCUT_MENU_ITEM

  // Add Configuration > Debug Menu > Endstop Test for endstop/probe/runout testing // 在配置-调试菜单添加限位开关测试项，可检测限位、探针、断料传感器
  //#define LCD_ENDSTOP_TEST

#endif // HAS_MARLINUI_MENU

#if HAS_DISPLAY
  /**
   * *** VENDORS PLEASE READ ***   // 厂商须知
   *
   * Marlin allows you to add a custom boot image for Graphical LCDs.
   * With this option Marlin will first show your custom screen followed
   * by the standard Marlin logo with version number and web URL.
   *
   * We encourage you to take advantage of this new feature and we also
   * respectfully request that you retain the unmodified Marlin boot screen.
   * Marlin支持为图形液晶屏幕添加自定义开机画面
   * 开启后会先展示自定义画面，再显示默认Marlin标识、版本号与官网地址
   * 官方建议使用该自定义功能，同时保留原版开机界面不作删减
   */
  #define SHOW_BOOTSCREEN                 // Show the Marlin bootscreen on startup. ** ENABLE FOR PRODUCTION **    // 开机显示Marlin默认启动画面，量产机型建议启用
  #if ENABLED(SHOW_BOOTSCREEN)
    #define BOOTSCREEN_TIMEOUT 3000       // (ms) Total Duration to display the boot screen(s)                     // (毫秒) 开机画面总共显示时长
    #if ANY(HAS_MARLINUI_U8GLIB, TFT_COLOR_UI)
      #define BOOT_MARLIN_LOGO_SMALL      // Show a smaller Marlin logo on the Boot Screen (saving lots of flash)  // 在启动画面上显示更小的 Marlin Logo（可节省大量闪存空间）
    #endif
    #if HAS_MARLINUI_U8GLIB
      //#define BOOT_MARLIN_LOGO_ANIMATED // Animated Marlin logo. Costs ~3260 (or ~940) bytes of flash.           // 动态 Marlin Logo。会消耗约 3260（或约 940）字节的闪存
    #endif
    #if ANY(HAS_MARLINUI_U8GLIB, TOUCH_UI_FTDI_EVE, HAS_MARLINUI_HD44780)
      //#define SHOW_CUSTOM_BOOTSCREEN    // Show the bitmap in Marlin/_Bootscreen.h on startup.                   // 开机加载Marlin/_Bootscreen.h内的位图画面
    #endif
  #endif

  #if HAS_MARLINUI_U8GLIB
    //#define CUSTOM_STATUS_SCREEN_IMAGE  // Show the bitmap in Marlin/_Statusscreen.h on the status screen.       // 在打印机状态屏幕上显示 Marlin/_Statusscreen.h 中的位图
  #endif

  //#define SOUND_MENU_ITEM   // Add a mute option to the LCD menu                        // 在液晶屏菜单中添加静音选项
  #define SOUND_ON_DEFAULT    // Buzzer/speaker default enabled state                     // 蜂鸣器/扬声器 默认开启状态

  #if ENABLED(U8GLIB_SSD1309)
    //#define LCD_DOUBLE_BUFFER           // Optimize display updates. Costs ~1K of SRAM. // 优化屏幕显示刷新效率，消耗约 1K 字节的静态内存
  #endif

  #if HAS_WIRED_LCD
    //#define DOUBLE_LCD_FRAMERATE        // Not recommended for slow boards.             // 不推荐在低速/老旧主板上使用
  #endif

  // The timeout to return to the status screen from sub-menus               // 菜单闲置超时自动返回主状态屏幕的时间
  //#define LCD_TIMEOUT_TO_STATUS 15000   // (ms)

  // Scroll a longer status message into view                                // 滚动显示较长的状态信息（文字太长时自动滚动展示）
  //#define STATUS_MESSAGE_SCROLLING

  // Apply a timeout to low-priority status messages                         // 对低优先级的状态提示信息应用超时自动消失功能
  //#define STATUS_MESSAGE_TIMEOUT_SEC 30 // (seconds)

  // On the Info Screen, display XY with one decimal place when possible     // 在信息界面，XY坐标尽可能显示一位小数
  //#define LCD_DECIMAL_SMALL_XY

  // Show the E position (filament used) during printing                     // 打印时显示 E 轴位置（耗材消耗量）
  //#define LCD_SHOW_E_TOTAL

  // Display a negative temperature instead of "err"                         // 显示负温度值，而不是显示 "err" 错误
  //#define SHOW_TEMPERATURE_BELOW_ZERO

  /**
   * LED Control Menu
   * Add LED Control to the LCD menu
   * LED灯光控制菜单
   * 在液晶屏菜单中添加灯光控制选项
   */
  //#define LED_CONTROL_MENU
  #if ENABLED(LED_CONTROL_MENU)
    #define LED_COLOR_PRESETS                 // Enable the Preset Color menu option                // 启用预设色彩菜单选项
    //#define NEO2_COLOR_PRESETS              // Enable a second NeoPixel Preset Color menu option  // 启用第二组 NeoPixel 预设色彩菜单选项
    #if ENABLED(LED_COLOR_PRESETS)
      #define LED_USER_PRESET_RED        255  // User defined RED value                             // 用户自定义红色数值
      #define LED_USER_PRESET_GREEN      128  // User defined GREEN value                           // 用户自定义绿色数值
      #define LED_USER_PRESET_BLUE         0  // User defined BLUE value                            // 用户自定义蓝色数值
      #define LED_USER_PRESET_WHITE      255  // User defined WHITE value                           // 用户自定义白色数值
      #define LED_USER_PRESET_BRIGHTNESS 255  // User defined intensity                             // 用户自定义亮度强度
      //#define LED_USER_PRESET_STARTUP       // Have the printer display the user preset color on startup
    #endif
    #if ENABLED(NEO2_COLOR_PRESETS)
      #define NEO2_USER_PRESET_RED        255 // User defined RED value                             // 用户自定义红色通道数值
      #define NEO2_USER_PRESET_GREEN      128 // User defined GREEN value                           // 用户自定义绿色数值
      #define NEO2_USER_PRESET_BLUE         0 // User defined BLUE value                            // 用户自定义蓝色数值
      #define NEO2_USER_PRESET_WHITE      255 // User defined WHITE value                           // 用户自定义白色数值
      #define NEO2_USER_PRESET_BRIGHTNESS 255 // User defined intensity                             // 用户自定义亮度强度
      //#define NEO2_USER_PRESET_STARTUP      // Have the printer display the user preset color on startup for the second strip // 打印机启动时，自动显示第二组灯条的用户预设颜色
    #endif
  #endif

#endif // HAS_DISPLAY

// Some displays offer Feedrate / Flow editing. // 部分屏幕支持进给速度、挤出流量手动编辑调节
#if ANY(HAS_MARLINUI_MENU, DWIN_CREALITY_LCD, DWIN_LCD_PROUI, MALYAN_LCD, TOUCH_SCREEN, ULTIPANEL_FEEDMULTIPLY)
  #define SPEED_EDIT_MIN    10  // (%) Feedrate percentage edit range minimum  // 进给速率（Feedrate）调整百分比的最小值
  #define SPEED_EDIT_MAX   999  // (%) Feedrate percentage edit range maximum  // 进给速率（Feedrate）调整百分比的最大值
#endif
#if ANY(HAS_MARLINUI_MENU, DWIN_CREALITY_LCD, DWIN_LCD_PROUI, MALYAN_LCD, TOUCH_SCREEN)
  #define FLOW_EDIT_MIN     10  // (%) Flow percentage edit range minimum      // 挤出流量（Flow）百分比调整范围的最小值
  #define FLOW_EDIT_MAX    999  // (%) Flow percentage edit range maximum      // 挤出流量（Flow）百分比调整范围的最大值
#endif

// Add 'M73' to set print job progress, overrides Marlin's built-in estimate   // 添加 M73 指令用于设置打印任务进度，覆盖 Marlin 内置的估算功能
//#define SET_PROGRESS_MANUALLY
#if ENABLED(SET_PROGRESS_MANUALLY)
  #define SET_PROGRESS_PERCENT            // Add 'P' parameter to set percentage done   // 为指令添加 'P' 参数，用于设置【打印完成百分比】
  #define SET_REMAINING_TIME              // Add 'R' parameter to set remaining time    // 为指令添加 'R' 参数，用于设置【剩余打印时间】
  //#define SET_INTERACTION_TIME          // Add 'C' parameter to set time until next filament change or other user interaction  // 为指令添加 'C' 参数，用于设置【距离下一次换料/用户操作的剩余时间】
  //#define M73_REPORT                    // Report M73 values to host                  // 将 M73 指令的进度数据（打印百分比、剩余时间等）上报给上位机
  #if ALL(M73_REPORT, HAS_MEDIA)
    #define M73_REPORT_SD_ONLY            // Report only when printing from SD          // 仅在从SD卡打印时，才上报打印进度数据
  #endif
#endif

// LCD Print Progress options. Multiple times may be displayed in turn.        // LCD 打印进度显示选项。可循环显示多项时间/进度信息
#if HAS_DISPLAY && ANY(HAS_MEDIA, SET_PROGRESS_MANUALLY)
  #define SHOW_PROGRESS_PERCENT           // Show print progress percentage (doesn't affect progress bar)       // 显示打印进度百分比（不影响进度条）
  #define SHOW_ELAPSED_TIME               // Display elapsed printing time (prefix 'E')                         // 显示已打印时间（前缀标记为 E = Elapsed）
  //#define SHOW_REMAINING_TIME           // Display estimated time to completion (prefix 'R')                  // 显示预计剩余打印时间（前缀标记为 R = Remaining）
  #if ENABLED(SET_INTERACTION_TIME)
    #define SHOW_INTERACTION_TIME         // Display time until next user interaction ('C' = filament change)   // 显示距下次手动操作的剩余时间，C标识代表换料提醒
  #endif
  //#define PRINT_PROGRESS_SHOW_DECIMALS  // Show/report progress with decimal digits, not all UIs support this // 以带小数点的精度显示/上报打印进度（并非所有界面都支持）

  #if ANY(HAS_MARLINUI_HD44780, IS_TFTGLCD_PANEL)
    //#define LCD_PROGRESS_BAR            // Show a progress bar on HD44780 LCDs for SD printing           // 在 HD44780 字符屏上显示 SD 打印进度条
    #if ENABLED(LCD_PROGRESS_BAR)
      #define PROGRESS_BAR_BAR_TIME 2000  // (ms) Amount of time to show the bar                           // (毫秒) 进度条在屏幕上显示的持续时间
      #define PROGRESS_BAR_MSG_TIME 3000  // (ms) Amount of time to show the status message                // (毫秒) 状态信息显示的持续时间
      #define PROGRESS_MSG_EXPIRE      0  // (ms) Amount of time to retain the status message (0=forever)  // (ms) 状态信息的保持显示时间（0=永久显示）
      //#define PROGRESS_MSG_ONCE         // Show the message for MSG_TIME then clear it                   // 显示 MSG_TIME（时间信息）后自动清除该消息
      //#define LCD_PROGRESS_BAR_TEST     // Add a menu item to test the progress bar                      // 添加一个菜单项，用于【测试进度条】是否正常显示
    #endif
  #endif
#endif

#if HAS_MEDIA
  /**
   * SD Card SPI Speed
   * May be required to resolve "volume init" errors.
   *
   * Enable and set to SPI_HALF_SPEED, SPI_QUARTER_SPEED, or SPI_EIGHTH_SPEED
   *  otherwise full speed will be applied.
   *
   * :['SPI_HALF_SPEED', 'SPI_QUARTER_SPEED', 'SPI_EIGHTH_SPEED']
   * SD 卡 SPI 通信速率
   * 可用于解决卷分区初始化失败报错
   * 启用后可设为半速、四分之一速或八分之一速
   * 未设置则默认采用全速模式
   * 可选值：半速、四分之一速、八分之一速
   */
  //#define SD_SPI_SPEED SPI_HALF_SPEED

  // The standard SD detect circuit reads LOW when media is inserted and HIGH when empty.
  // Enable this option and set to HIGH if your SD cards are incorrectly detected.
  // 标准SD卡检测电路：插入SD卡时读取为低电平，无卡时为高电平。
  // 如果你的SD卡检测异常（误判有无卡），启用此选项并设置为 HIGH。
  //#define SD_DETECT_STATE HIGH

  //#define SD_IGNORE_AT_STARTUP            // Don't mount the SD card when starting up                   // 开机时不自动挂载 SD 卡
  //#define SDCARD_READONLY                 // Read-only SD card (to save over 2K of flash)               // SD 卡设为只读模式（可节省超过 2K 的固件存储空间）

  //#define GCODE_REPEAT_MARKERS            // Enable G-code M808 to set repeat markers and do looping    // 启用 G-code 指令 M808，用于设置重复标记并执行循环打印（译者注：此功能适用于批量重复打印）

  #define SD_PROCEDURE_DEPTH 1              // Increase if you need more nested M32 calls                 // 如果需要更多层嵌套的 M32 调用，请增大此数值

  #define SD_FINISHED_STEPPERRELEASE true   // Disable steppers when SD Print is finished                 // SD卡打印完成后关闭步进电机
  #define SD_FINISHED_RELEASECOMMAND "M84"  // Use "M84XYE" to keep Z enabled so your bed stays in place  // 使用指令 "M84XYE" 仅关闭 X、Y、E 轴电机，保持 Z 轴电机通电，这样平台/打印头会保持在原位不会下落

  // Reverse SD sort to show "more recent" files first, according to the card's FAT.
  // Since the FAT gets out of order with usage, SDCARD_SORT_ALPHA is recommended.
  // 根据SD卡的FAT文件分配表，反转SD卡文件排序，让“最新的”文件优先显示。
  // 由于长期使用后FAT表会变得无序，推荐配合开启 SDCARD_SORT_ALPHA（字母排序）功能。
  #define SDCARD_RATHERRECENTFIRST

  #define SD_MENU_CONFIRM_START             // Confirm the selected SD file before printing                    // 选中SD卡文件后，打印前弹窗确认

  //#define NO_SD_AUTOSTART                 // Remove auto#.g file support completely to save some Flash, SRAM // 完全移除 auto#.g 文件的支持，以节省部分闪存和内存
  //#define MENU_ADDAUTOSTART               // Add a menu option to run auto#.g files                          // 添加一个菜单选项，用于手动运行 auto#.g 自动脚本文件

  //#define ONE_CLICK_PRINT                 // Prompt to print the newest file on inserted media               // 插入存储卡后，弹窗提示是否打印最新文件
  //#define BROWSE_MEDIA_ON_INSERT          // Open the file browser when media is inserted                    // 插入SD卡/存储介质时，自动打开文件浏览器

  //#define MEDIA_MENU_AT_TOP               // Force the media menu to be listed on the top of the main menu   // 将存储介质菜单固定置顶在主菜单首位

  #define EVENT_GCODE_SD_ABORT "G28XY"      // G-code to run on SD Abort Print (e.g., "G28XY" or "G27")        // SD卡打印中止时执行的G-code指令（例如："G28XY" 或 "G27"）
                                            // 上面是打印中途取消 / 中止时，打印机自动执行的指令
                                            // 你可以在这里填一行 G-code，比如：
                                            // G27：归位喷头，清洁喷嘴
                                            // G28XY：XY 轴回原点
                                            // 作用：打印取消后，让机器自动归位、清理，不用手动操作

  #if ENABLED(PRINTER_EVENT_LEDS)
    #define PE_LEDS_COMPLETED_TIME  (30*60) // (seconds) Time to keep the LED "done" color before restoring normal illumination  //（秒）打印完成指示灯色维持时长，之后恢复常规灯光
  #endif

  /**
   * Continue after Power-Loss (Creality3D)
   *
   * Store the current state to the SD Card at the start of each layer
   * during SD printing. If the recovery file is found at boot time, present
   * an option on the LCD screen to continue the print from the last-known
   * point in the file.
   * 断电续打功能（创想三维机型适配）
   * SD 卡打印时，每层打印开始都会将设备当前状态保存至存储卡。
   * 开机若检测到恢复记录文件，显示屏会弹出选项，可从断电位置接续打印。
   */
  //#define POWER_LOSS_RECOVERY
  #if ENABLED(POWER_LOSS_RECOVERY)
    #define PLR_ENABLED_DEFAULT       false // Power-Loss Recovery enabled by default. (Set with 'M413 Sn' & M500)         // 默认启用断电续打功能。（可通过指令 'M413 Sn' 开启/关闭，并使用 M500 保存设置）
    //#define PLR_BED_THRESHOLD BED_MAXTEMP // (°C) Skip user confirmation at or above this bed temperature (0 to disable) //（摄氏度）热床温度达到及该数值时，跳过人工确认步骤，设为0则关闭此功能

    //#define POWER_LOSS_PIN             44 // Pin to detect power-loss. Set to -1 to disable default pin on boards without module, or comment to use board default.
                                            // 上面配置断电检测引脚。在不带断电检测模块的主板上，设为 -1 以禁用默认引脚；或直接注释掉上面一行，以使用主板默认配置。

    //#define POWER_LOSS_STATE         HIGH // State of pin indicating power-loss                   // 用于指示断电状态的引脚电平
    //#define POWER_LOSS_PULLUP             // Set pullup / pulldown as appropriate for your sensor // 根据你的传感器/断电检测模块，正确设置上拉电阻或下拉电阻
    //#define POWER_LOSS_PULLDOWN

    //#define POWER_LOSS_ZRAISE        2    // (mm) Z axis raise on resume (on power-loss with UPS) //（单位：毫米）使用UPS断电续打时，Z轴抬升的高度
    //#define POWER_LOSS_PURGE_LEN    20    // (mm) Length of filament to purge on resume           //（单位：毫米）断电续打恢复打印时，预挤出（回抽补料）的耗材长度

    // Without a POWER_LOSS_PIN the following option helps reduce wear on the SD card,              // 在未使用 POWER_LOSS_PIN 断电检测引脚时，以下选项有助于减少SD卡擦写损耗，
    // especially with "vase mode" printing. Set too high and vases cannot be continued.            // 尤其在“花瓶模式”打印时效果明显。数值设置过高，会导致花瓶模式打印无法正常续打。（花瓶模式：一层一层螺旋上升，层特别多、保存特别频繁）
    #define POWER_LOSS_MIN_Z_CHANGE    0.05 // (mm) Minimum Z change before saving power-loss data  //（单位：毫米）保存断电续打数据前，Z轴至少需要移动的最小高度

    //#define BACKUP_POWER_SUPPLY           // Backup power / UPS to move the steppers on power-loss // 断电时依靠备用电源/UPS驱动步进电机动作
    #if ENABLED(BACKUP_POWER_SUPPLY)
      //#define POWER_LOSS_RETRACT_LEN   10 // (mm) Length of filament to retract on fail            //（单位：毫米）断电/打印失败时，耗材回抽长度
    #endif

    // Enable if Z homing is needed for proper recovery. 99.9% of the time this should be disabled!  // 若断电续打恢复时需要重新Z轴归位，则启用。99.9% 的情况下都应该关闭！
    //#define POWER_LOSS_RECOVER_ZHOME
    #if ENABLED(POWER_LOSS_RECOVER_ZHOME)
      //#define POWER_LOSS_ZHOME_POS { 0, 0 } // Safe XY position to home Z while avoiding objects on the bed  // 安全XY坐标位置：用于Z轴归位，同时避开打印平台上的模型
    #endif
  #endif

  /**
   * Sort SD file listings in alphabetical order.
   *
   * With this option enabled, items on SD cards will be sorted
   * by name for easier navigation.
   *
   * By default...
   *
   *  - Use the slowest -but safest- method for sorting.
   *  - Folders are sorted to the top.
   *  - The sort key is statically allocated.
   *  - No added G-code (M34) support.
   *  - 40 item sorting limit. (Items after the first 40 are unsorted.)
   *
   * SD sorting uses static allocation (as set by SDSORT_LIMIT), allowing the
   * compiler to calculate the worst-case usage and throw an error if the SRAM
   * limit is exceeded.
   *
   *  - SDSORT_USES_RAM provides faster sorting via a static directory buffer.
   *  - SDSORT_USES_STACK does the same, but uses a local stack-based buffer.
   *  - SDSORT_CACHE_NAMES will retain the sorted file listing in RAM. (Expensive!)
   *  - SDSORT_DYNAMIC_RAM only uses RAM when the SD menu is visible. (Use with caution!)
   * 
   * 对 SD 卡文件列表按字母顺序排序。
   * 启用此选项后，SD 卡上的文件 / 文件夹
   * 会按名称排序，方便查找。
   * 默认配置说明：
   * 使用最慢但最安全的排序方式。
   * 文件夹优先排在最上方。
   * 排序缓存使用静态内存。
   * 不额外支持 G-code 指令 (M34)。
   * 最多只排序前 40 个项目。（超出部分不排序）
   * SD 排序使用静态分配内存（由 SDSORT_LIMIT 定义），
   * 编译器会计算最大内存占用，如果超出主板 RAM 限制会直接报错。
   * 高级选项说明：
   * SDSORT_USES_RAM：用静态目录缓存，排序更快。
   * SDSORT_USES_STACK：同上，但基于栈区缓存。
   * SDSORT_CACHE_NAMES：把排序结果常驻内存（非常耗内存！）。
   * SDSORT_DYNAMIC_RAM：仅打开 SD 菜单时才占用内存（谨慎使用！）。
   */
  //#define SDCARD_SORT_ALPHA

  // SD Card Sorting options    // SD 卡文件排序选项
  #if ENABLED(SDCARD_SORT_ALPHA)
    #define SDSORT_REVERSE     false  // Default to sorting file names in reverse order.                                                // 默认以 倒序 方式排序文件名
    #define SDSORT_LIMIT       40     // Maximum number of sorted items (10-256). Costs 27 bytes each.                                  // 最大可排序的项目数量（10-256）。每增加一项占用 27 字节内存。
    #define SDSORT_FOLDERS     -1     // -1=above  0=none  1=below                                                                      // -1=显示在上方  0=不显示  1=显示在下方
    #define SDSORT_GCODE       false  // Enable G-code M34 to set sorting behaviors: M34 S<-1|0|1> F<-1|0|1>                            // 启用 G-code 指令 M34 用于设置排序规则：M34 S<-1|0|1> F<-1|0|1>
    #define SDSORT_USES_RAM    false  // Pre-allocate a static array for faster pre-sorting.                                            // 预分配静态数组，用于提升排序速度。
    #define SDSORT_USES_STACK  false  // Prefer the stack for pre-sorting to give back some SRAM. (Negated by next 2 options.)          // 优先使用栈区进行预排序，以释放部分静态内存。(会被接下来的两个选项抵消效果)
    #define SDSORT_CACHE_NAMES false  // Keep sorted items in RAM longer for speedy performance. Most expensive option.                 // 将已排序的文件列表长期保存在内存中，以提升响应速度。这是**最耗内存**的选项！
    #define SDSORT_DYNAMIC_RAM false  // Use dynamic allocation (within SD menus). Least expensive option. Set SDSORT_LIMIT before use! // 使用动态内存分配（仅在SD菜单内生效）。占用内存最小的选项。使用前请先设置 SDSORT_LIMIT！
    #define SDSORT_CACHE_VFATS 2      // Maximum number of 13-byte VFAT entries to use for sorting.                                     // 用于排序的最大13字节VFAT文件条目数量。
                                      // Note: Only affects SCROLL_LONG_FILENAMES with SDSORT_CACHE_NAMES but not SDSORT_DYNAMIC_RAM.   
                                      // 注意：仅在 启用SDSORT_CACHE_NAMES 且 未启用SDSORT_DYNAMIC_RAM 时，才会影响 SCROLL_LONG_FILENAMES（长文件名滚动显示）功能。
  #endif

  // Allow international symbols in long filenames. To display correctly, the
  // LCD's font must contain the characters. Check your selected LCD language.
  // 允许在长文件名中使用国际字符（如中文、日文、西欧重音符号等）。
  // 要正常显示，LCD 屏幕的字库必须包含这些字符。请检查你选择的 LCD 语言设置。
  //#define UTF_FILENAME_SUPPORT

  //#define LONG_FILENAME_HOST_SUPPORT    // Get the long filename of a file/folder with 'M33 <dosname>' and list long filenames with 'M20 L' // 使用指令 'M33 <dosname>' 获取文件/文件夹的长文件名；使用指令 'M20 L' 列出所有长文件名。
  //#define LONG_FILENAME_WRITE_SUPPORT   // Create / delete files with long filenames via M28, M30, and Binary Transfer Protocol             // 通过 M28、M30 指令及二进制传输协议，支持创建/删除长文件名文件
  //#define M20_TIMESTAMP_SUPPORT         // Include timestamps by adding the 'T' flag to M20 commands                   // 在 M20 指令中添加 'T' 参数（M20 T），使文件列表包含时间戳信息

  //#define SCROLL_LONG_FILENAMES         // Scroll long filenames in the SD card menu                 // SD卡菜单内超长文件名滚动显示

  //#define SD_ABORT_NO_COOLDOWN          // Leave the heaters on after Stop Print (not recommended!)  // 停止打印后保持加热部件持续通电（不推荐开启）

  /**
   * Abort SD printing when any endstop is triggered.
   * This feature is enabled with 'M540 S1' or from the LCD menu.
   * Endstops must be activated for this option to work.
   * 任一限位开关（行程开关）被触发时，立即中止SD卡打印。
   * 可通过指令 'M540 S1' 或 LCD 菜单启用此功能。
   * 此功能生效的前提是：限位开关必须已启用。
   */
  //#define SD_ABORT_ON_ENDSTOP_HIT
  #if ENABLED(SD_ABORT_ON_ENDSTOP_HIT)
    //#define SD_ABORT_ON_ENDSTOP_HIT_GCODE "G28XY" // G-code to run on endstop hit (e.g., "G28XY" or "G27")  // 触发限位开关时执行的G-code指令（例如："G28XY" 或 "G27"）
  #endif

  //#define SD_REPRINT_LAST_SELECTED_FILE // On print completion open the LCD Menu and select the same file   // 打印结束后自动打开屏幕菜单，并选中当前打印文件

  //#define AUTO_REPORT_SD_STATUS         // Auto-report media status with 'M27 S<seconds>'                   // 通过指令M27 S<秒数>，自动上报存储介质运行状态

  /**
   * Support for USB thumb drives using an Arduino USB Host Shield or
   * equivalent MAX3421E breakout board. The USB thumb drive will appear
   * to Marlin as an SD card.
   *
   * The MAX3421E can be assigned the same pins as the SD card reader, with
   * the following pin mapping:
   *
   *    SCLK, MOSI, MISO --> SCLK, MOSI, MISO
   *    INT              --> SD_DETECT_PIN [1]
   *    SS               --> SD_SS_PIN
   *
   * [1] On AVR an interrupt-capable pin is best for UHS3 compatibility.
   * 
   * 支持通过 Arduino USB Host Shield 或
   * 等效的 MAX3421E 扩展板 使用 USB 闪存盘（U盘）。
   * USB 闪存盘会被 Marlin 固件识别为 SD 卡。
   * MAX3421E 可与 SD 卡读卡器共用相同引脚，引脚对应关系：
   *
   *    SCLK, MOSI, MISO --> SCLK, MOSI, MISO
   *    INT              --> SD_DETECT_PIN [1]
   *    SS               --> SD_SS_PIN
   *
   * [1] 在 AVR 主板上，为兼容 UHS3，最好使用支持中断的引脚。
   */

  //#define USB_FLASH_DRIVE_SUPPORT
  #if ENABLED(USB_FLASH_DRIVE_SUPPORT)
    /**
     * USB Host Shield Library
     *
     * - UHS2 uses no interrupts and has been production-tested
     *   on a LulzBot TAZ Pro with a 32-bit Archim board.
     *
     * - UHS3 is newer code with better USB compatibility. But it
     *   is less tested and is known to interfere with Servos.
     *   [1] This requires USB_INTR_PIN to be interrupt-capable.
     * 
     * 
     * 
     * USB 主机盾库（USB Host Shield Library）
     *
     * - UHS2：不使用中断，已在 LulzBot TAZ Pro（32位 Archim 主板）上
     *   通过量产级测试，稳定可靠。
     *
     * - UHS3：较新版本，USB 兼容性更好。
     *   但测试较少，且已知会与**舵机（Servos）**功能冲突。
     *   [1] 此模式需要 USB_INTR_PIN 必须是**支持中断功能**的引脚。
     */
    //#define USE_UHS2_USB
    //#define USE_UHS3_USB

    #define DISABLE_DUE_SD_MMC // Disable USB Host access to USB Drive to prevent hangs on block access for DUE platform // 禁用 USB 主机对U盘的访问，防止 DUE 平台在块访问时出现死机/卡死问题

    /**
     * Native USB Host supported by some boards (USB OTG)  // 部分主板支持的原生 USB 主机功能（USB OTG）
     */
    //#define USE_OTG_USB_HOST

    #if DISABLED(USE_OTG_USB_HOST)
      #define USB_CS_PIN    SD_SS_PIN
      #define USB_INTR_PIN  SD_DETECT_PIN
    #endif
  #endif

  /**
   * When using a bootloader that supports SD-Firmware-Flashing,
   * add a menu item to activate SD-FW-Update on the next reboot.
   *
   * Requires ATMEGA2560 (Arduino Mega)
   *
   * Tested with this bootloader:
   *   https://github.com/FleetProbe/MicroBridge-Arduino-ATMega2560
   * 
   * 
   * 当使用支持 SD卡刷写固件的 bootloader（引导程序）时，
   * 添加一个菜单项，用于在**下次重启时执行 SD 卡固件升级**。
   *
   * 仅支持 ATMEGA2560 (Arduino Mega) 主板
   *
   * 已在该引导程序上测试：
   *   https://github.com/FleetProbe/MicroBridge-Arduino-ATMega2560
   */
  //#define SD_FIRMWARE_UPDATE
  #if ENABLED(SD_FIRMWARE_UPDATE)
    #define SD_FIRMWARE_UPDATE_EEPROM_ADDR    0x1FF
    #define SD_FIRMWARE_UPDATE_ACTIVE_VALUE   0xF0
    #define SD_FIRMWARE_UPDATE_INACTIVE_VALUE 0xFF
  #endif

  /**
   * Enable this option if you have more than ~3K of unused flash space.
   * Marlin will embed all settings in the firmware binary as compressed data.
   * Use 'M503 C' to write the settings out to the SD Card as 'mc.zip'.
   * See docs/ConfigEmbedding.md for details on how to use 'mc-apply.py'.
   * 
   * 若你的固件有超过约 3K 的空闲闪存空间，可启用此选项。
   * Marlin 会将所有配置参数以压缩数据形式嵌入固件二进制文件中。
   * 使用指令 'M503 C' 可将这些配置写入 SD 卡，生成 'mc.zip' 文件。
   * 用法详情请查看文档 docs/ConfigEmbedding.md 以及 mc-apply.py 工具。
   */
  //#define CONFIGURATION_EMBEDDING

  // Add an optimized binary file transfer mode, initiated with 'M28 B1'  // 添加一种优化的二进制文件传输模式，通过指令 'M28 B1' 启动
  //#define BINARY_FILE_TRANSFER

  #if ENABLED(BINARY_FILE_TRANSFER)
    // Include extra facilities (e.g., 'M20 F') supporting firmware upload via BINARY_FILE_TRANSFER
    // 包含额外辅助功能（例如 M20 F），用于支持通过二进制文件传输协议上传固件
    //#define CUSTOM_FIRMWARE_UPLOAD
  #endif

  // "Over-the-air" Firmware Update with M936 - Required to set EEPROM flag
  // 通过 M936 指令实现“无线/远程”固件更新 —— 必须设置 EEPROM 标志位
  //#define OTA_FIRMWARE_UPDATE

  /**
   * Set this option to one of the following (or the board's defaults apply):  * 将此选项设置为以下值之一（否则将使用主板的默认配置）：
   *
   *           LCD - Use the SD drive in the external LCD controller.
   *       ONBOARD - Use the SD drive on the control board.
   *  CUSTOM_CABLE - Use a custom cable to access the SD (as defined in a pins file).
   *
   * :[ 'LCD', 'ONBOARD', 'CUSTOM_CABLE' ]
   * 
   *           LCD - 使用外置液晶屏上的 SD 卡插槽。
   *       ONBOARD - 使用主板上的 SD 卡插槽。
   *  CUSTOM_CABLE - 使用自定义排线连接 SD 卡（定义在引脚文件中）。
   *
   * :[ 'LCD', 'ONBOARD', 'CUSTOM_CABLE' ]
   */
  //#define SDCARD_CONNECTION LCD

  // Enable if SD detect is rendered useless (e.g., by using an SD extender)   // 若SD卡检测功能失效（例如使用了SD卡延长线），请启用此项
  //#define NO_SD_DETECT

  /**
   * Multiple volume support - EXPERIMENTAL.
   * Adds 'M21 Pm' / 'M21 S' / 'M21 U' to mount SD Card / USB Drive.
   * 多存储设备支持 - 实验性功能。
   * 添加指令 M21 Pm / M21 S / M21 U 用于挂载 SD 卡 / U盘。
   */
  //#define MULTI_VOLUME
  #if ENABLED(MULTI_VOLUME)
    #define VOLUME_SD_ONBOARD
    #define VOLUME_USB_FLASH_DRIVE
    #define DEFAULT_VOLUME        SD_ONBOARD       // :[ 'SD_ONBOARD', 'USB_FLASH_DRIVE' ]
    #define DEFAULT_SHARED_VOLUME USB_FLASH_DRIVE  // :[ 'SD_ONBOARD', 'USB_FLASH_DRIVE' ]
  #endif

#endif // HAS_MEDIA

/**
 * By default an onboard SD card reader may be shared as a USB mass-
 * storage device. This option hides the SD card from the host PC.
 * 默认情况下，板载 SD 读卡器可能会被共享为 USB 大容量存储设备。
 * 这个选项会让 SD 卡对主机电脑隐藏。
 */
//#define NO_SD_HOST_DRIVE   // Disable SD Card access over USB (for security).  // 禁用 USB 访问 SD 卡（出于安全考虑）。

/**
 * Additional options for Graphical Displays
 *
 * Use the optimizations here to improve printing performance,
 * which can be adversely affected by graphical display drawing,
 * especially when doing several short moves, and when printing
 * on DELTA and SCARA machines.
 *
 * Some of these options may result in the display lagging behind
 * controller events, as there is a trade-off between reliable
 * printing performance versus fast display updates.
 * 
 * === 图形显示屏的额外优化选项 ===
 *
 * 使用这些优化可以提升打印性能，
 * 因为图形界面的绘制操作可能会影响打印速度，
 * 尤其是在执行大量短距离移动，
 * 以及在三角洲（DELTA）、SCARA 机型上打印时。
 *
 * 其中某些选项可能会导致屏幕显示滞后于控制器事件，
 * 因为这是在【稳定打印性能】和【屏幕快速刷新】之间做权衡。
 */
#if HAS_MARLINUI_U8GLIB
  // Save many cycles by drawing a hollow frame or no frame on the Info Screen    // 在信息界面上使用空心边框或不显示边框，以此节省大量 CPU 运算资源。
  //#define XYZ_NO_FRAME
  #define XYZ_HOLLOW_FRAME

  // A bigger font is available for edit items. Costs 3120 bytes of flash.        // 编辑项可使用更大的字体。会占用 3120 字节闪存。
  // Western only. Not available for Cyrillic, Kana, Turkish, Greek, or Chinese.  // 仅适用于西方字符。不支持 Cyrillic（俄文）、日文假名、土耳其文、希腊文或中文。
  //#define USE_BIG_EDIT_FONT

  // A smaller font may be used on the Info Screen. Costs 2434 bytes of flash.    // 可在信息屏幕上使用更小的字体。占用 2434 字节闪存。
  // Western only. Not available for Cyrillic, Kana, Turkish, Greek, or Chinese.  // 仅适用于西方字符。不支持俄文、日文、土耳其文、希腊文或中文。
  //#define USE_SMALL_INFOFONT

  /**
   * ST7920-based LCDs can emulate a 16 x 4 character display using
   * the ST7920 character-generator for very fast screen updates.
   * Enable LIGHTWEIGHT_UI to use this special display mode.
   *
   * Since LIGHTWEIGHT_UI has limited space, the position and status
   * message occupy the same line. Set STATUS_EXPIRE_SECONDS to the
   * length of time to display the status message before clearing.
   *
   * Set STATUS_EXPIRE_SECONDS to zero to never clear the status.
   * This will prevent position updates from being displayed.
   * 
   * 基于 ST7920 芯片的液晶屏（最常见的 12864 屏）
   * 可以使用内置字符生成器来模拟 16x4 的纯字符显示，
   * 这种模式**屏幕刷新速度极快**。
   * 开启 LIGHTWEIGHT_UI 即可启用这个特殊模式。
   *
   * 因为轻量级UI空间有限，坐标位置和状态信息会挤在同一行。
   * 用 STATUS_EXPIRE_SECONDS 设置状态信息显示多久后消失。
   *
   * 设置为 0 表示永远不清除状态信息，
   * 这样坐标位置就不会显示出来了。
   */
  #if IS_U8GLIB_ST7920
    // Enable this option and reduce the value to optimize screen updates.                 // 启用此选项并减小数值以优化屏幕刷新速度。
    // The normal delay is 10µs. Use the lowest value that still gives a reliable display. // 默认延迟为 10µs（微秒）。使用能保证屏幕正常显示、不花屏、不闪烁的**最低稳定值**。
    //#define DOGM_SPI_DELAY_US      5  // (µs) Delay after each SPI transfer              // 每次 SPI 通信传输后的延迟时间（单位：微秒 µs）

    //#define LIGHTWEIGHT_UI
    #if ENABLED(LIGHTWEIGHT_UI)
      #define STATUS_EXPIRE_SECONDS 20
    #endif
  #endif

  /**
   * Status (Info) Screen customization
   * These options may affect code size and screen render time.
   * Custom status screens can forcibly override these settings.
   * 
   * 状态屏幕（信息屏幕）自定义设置
   * 这些选项可能会影响固件体积和屏幕渲染速度。
   * 自定义状态屏幕可以强制覆盖这些设置。
   */
  //#define STATUS_COMBINE_HEATERS    // Use combined heater images instead of separate ones                                       // 使用组合式加热图标，而非独立分开的图标
  //#define STATUS_HOTEND_NUMBERLESS  // Use plain hotend icons instead of numbered ones (with 2+ hotends)                         // 使用简易热端图标，而非带数字编号的图标（适用于 2 个及以上喷头）
  #define STATUS_HOTEND_INVERTED      // Show solid nozzle bitmaps when heating (Requires STATUS_HOTEND_ANIM for numbered hotends) // 加热时显示实心喷嘴图标（带编号的热端需同时开启 STATUS_HOTEND_ANIM 才能生效）
  #define STATUS_HOTEND_ANIM          // Use a second bitmap to indicate hotend heating                                            // 使用第二组图标来表示热端（喷嘴）正在加热
  #define STATUS_BED_ANIM             // Use a second bitmap to indicate bed heating                                               // 使用第二组图标来表示热床正在加热
  #define STATUS_CHAMBER_ANIM         // Use a second bitmap to indicate chamber heating                                           // 使用第二组图标示意腔体正在加热
  //#define STATUS_CUTTER_ANIM        // Use a second bitmap to indicate spindle / laser active                                    // 使用第二组图标来表示 主轴/激光器 处于工作状态
  //#define STATUS_COOLER_ANIM        // Use a second bitmap to indicate laser cooling                                             // 使用第二组图标标识激光冷却状态
  //#define STATUS_FLOWMETER_ANIM     // Use multiple bitmaps to indicate coolant flow                                             // 使用多组图标标识冷却液流动状态
  //#define STATUS_ALT_BED_BITMAP     // Use the alternative bed bitmap                                                            // 启用备用样式的热床图标
  //#define STATUS_ALT_FAN_BITMAP     // Use the alternative fan bitmap                                                            // 启用备用样式的风扇图标
  //#define STATUS_FAN_FRAMES 3       // :[0,1,2,3,4] Number of fan animation frames                                               // :[0,1,2,3,4] 风扇动画帧数档位

  // Only one STATUS_HEAT_* option can be enabled                                    // 只能启用 **一个** STATUS_HEAT_* 类选项
  //#define STATUS_HEAT_PERCENT       // Show heating in a progress bar              // 以进度条形式展示加热进程
  //#define STATUS_HEAT_POWER         // Show heater output power as a vertical bar  // 以竖条柱状图显示加热器输出功率

#endif // HAS_MARLINUI_U8GLIB

#if HAS_MARLINUI_U8GLIB || IS_DWIN_MARLINUI
  #define MENU_HOLLOW_FRAME           // Enable to save many cycles by drawing a hollow frame on Menu Screens  // 菜单界面绘制空心边框，减少运算开销、节省运行周期
  //#define OVERLAY_GFX_REVERSE       // Swap the CW/CCW indicators in the graphics overlay                    // 调换图形层里顺时针、逆时针转向标识

  // Frivolous Game Options
  //#define MARLIN_BRICKOUT
  //#define MARLIN_INVADERS
  //#define MARLIN_SNAKE
  //#define GAMES_EASTER_EGG          // Add extra blank lines above the "Games" sub-menu                      // 在游戏子菜单上方增加空白行间距
#endif

//
// Additional options for DGUS / DWIN displays  // 针对 DGUS / DWIN 彩色触摸屏的额外配置选项
//
#if HAS_DGUS_LCD
  #define LCD_BAUDRATE 115200

  #define DGUS_RX_BUFFER_SIZE 128
  #define DGUS_TX_BUFFER_SIZE 48
  //#define SERIAL_STATS_RX_BUFFER_OVERRUNS  // Fix Rx overrun situation (Currently only for AVR)  // 修复串口接收溢出问题（目前仅适用于 AVR 架构主板）

  #define DGUS_UPDATE_INTERVAL_MS  500    // (ms) Interval between automatic screen updates        // 屏幕自动刷新的时间间隔（单位：毫秒）

  #if DGUS_UI_IS(FYSETC, MKS, HIPRECY)
    #define DGUS_PRINT_FILENAME           // Display the filename during printing                  // 打印时在屏幕上显示文件名
    #define DGUS_PREHEAT_UI               // Display a preheat screen during heatup                // 加热过程中显示专用预热界面

    #if DGUS_UI_IS(FYSETC, MKS)
      //#define DGUS_UI_MOVE_DIS_OPTION   // Disabled by default for FYSETC and MKS                // FYSETC 和 MKS 屏幕默认是关闭的
    #else
      #define DGUS_UI_MOVE_DIS_OPTION     // Enabled by default for UI_HIPRECY                     // 对于 UI_HIPRECY 屏幕，该功能**默认启用**
    #endif

    #define DGUS_FILAMENT_LOADUNLOAD
    #if ENABLED(DGUS_FILAMENT_LOADUNLOAD)
      #define DGUS_FILAMENT_PURGE_LENGTH 10
      #define DGUS_FILAMENT_LOAD_LENGTH_PER_TIME 0.5 // (mm) Adjust in proportion to DGUS_UPDATE_INTERVAL_MS  // 需与屏幕刷新间隔按比例调整
    #endif

    #define DGUS_UI_WAITING               // Show a "waiting" screen between some screens            // 在部分界面切换过程中显示“等待/加载中”界面
    #if ENABLED(DGUS_UI_WAITING)
      #define DGUS_UI_WAITING_STATUS 10
      #define DGUS_UI_WAITING_STATUS_PERIOD 8 // Increase to slower waiting status looping           // 数值越大，等待状态的动画循环越慢
    #endif

  #elif DGUS_UI_IS(E3S1PRO)
    /**
     * The stock Ender-3 S1 Pro/Plus display firmware has rather poor SD file handling.
     *
     * The autoscroll is mainly useful for status messages, filenames, and the "About" page.
     *
     * NOTE: The Advanced SD Card option is affected by the stock touchscreen firmware, so
     *       pages 5 and up will display "4/4". This may get fixed in a screen firmware update.
     * 
     * 原厂 Ender-3 S1 Pro/Plus 触屏固件对 SD 卡文件的兼容性欠佳。
     * 自动滚动功能仅适用于状态信息、文件名及关于页面。
     * 提示：高级 SD 卡功能受原厂触屏固件限制，第五页及之后页面都会显示为 4/4 分页，该问题有望通过后续屏幕固件更新修复。
     */
    #define DGUS_SOFTWARE_AUTOSCROLL        // Enable long text software auto-scroll                              // 启用长文本软件自动滚动（文字太长会自动滚动显示）
    #define DGUS_AUTOSCROLL_START_CYCLES 1  // Refresh cycles without scrolling at the beginning of text strings  // 文本开头停留的刷新次数（让文字先停一会儿，再开始滚动）
    #define DGUS_AUTOSCROLL_END_CYCLES 1    // ... at the end of text strings                                     // 文本滚动到末尾时的停留刷新次数

    #define DGUS_ADVANCED_SDCARD            // Allow more than 20 files and navigating directories                // 允许显示超过20个文件，并支持浏览文件夹目录
    #define DGUS_USERCONFIRM                // Reuse the SD Card page to show various messages                    // 重复使用 SD 卡页面来显示各种提示信息
  #endif
#endif // HAS_DGUS_LCD

//
// Additional options for AnyCubic Chiron TFT displays       // 纵维立方Chiron机型TFT触控屏专属拓展配置
//
#if ENABLED(ANYCUBIC_LCD_CHIRON)
  // By default the type of panel is automatically detected.
  // Enable one of these options if you know the panel type.
  // 默认情况下，面板类型会被自动检测。
  // 如果你确定自己的屏幕类型，就启用其中一个选项。
  //#define CHIRON_TFT_STANDARD
  //#define CHIRON_TFT_NEW

  // Enable the longer Anycubic powerup startup tune  // 开启纵维立方机型加长版开机提示音
  //#define AC_DEFAULT_STARTUP_TUNE

  /**
   * Display Folders
   * By default the file browser lists all G-code files (including those in subfolders) in a flat list.
   * Enable this option to display a hierarchical file browser.
   * 
   * 文件夹显示功能
   * 默认文件浏览页会将所有 G 代码文件（含子文件夹内文件）平铺展示
   * 开启该选项即可切换为层级式文件夹浏览视图
   *
   * NOTES:
   * - Without this option it helps to enable SDCARD_SORT_ALPHA so files are sorted before/after folders.
   * - When used with the "new" panel, folder names will also have '.gcode' appended to their names.
   *   This hack is currently required to force the panel to show folders.
   * 
   * 注意事项
   * 未开启文件夹功能时，建议开启文件字母排序功能，让文件与文件夹有序排布
   * 搭配新款屏幕使用时，文件夹名称后缀会额外附带.gcode标识
   * 该特殊处理是当前让屏幕正常识别显示文件夹的必要方式
   */
  #define AC_SD_FOLDER_VIEW
#endif

//
// Specify additional languages for the UI. Default specified by LCD_LANGUAGE.   // 为界面指定额外的语言支持。默认语言由 LCD_LANGUAGE 定义。
//
#if ANY(DOGLCD, TFT_COLOR_UI, TOUCH_UI_FTDI_EVE, IS_DWIN_MARLINUI, ANYCUBIC_LCD_VYPER)
  //#define LCD_LANGUAGE_2 fr
  //#define LCD_LANGUAGE_3 de
  //#define LCD_LANGUAGE_4 es
  //#define LCD_LANGUAGE_5 it
  #ifdef LCD_LANGUAGE_2
    //#define LCD_LANGUAGE_AUTO_SAVE // Automatically save language to EEPROM on change  // 切换语言后自动存入断电保存区域
  #endif
#endif

//
// Touch UI for the FTDI Embedded Video Engine (EVE)
//
#if ENABLED(TOUCH_UI_FTDI_EVE)
  // Display board used
  //#define LCD_FTDI_VM800B35A        // FTDI 3.5" with FT800 (320x240)        // 适配3.5英寸FT800主控FTDI显示屏，分辨率320×240
  //#define LCD_4DSYSTEMS_4DLCD_FT843 // 4D Systems 4.3" (480x272)             // 适配 4D Systems 品牌 4.3英寸显示屏，分辨率 480×272
  //#define LCD_HAOYU_FT800CB         // Haoyu with 4.3" or 5" (480x272)       // 适配 浩悦（Haoyu）4.3寸 / 5寸显示屏，分辨率 480×272
  //#define LCD_HAOYU_FT810CB         // Haoyu with 5" (800x480)               // 适配 浩悦（Haoyu）5寸高清显示屏，分辨率 800×480
  //#define LCD_LULZBOT_CLCD_UI       // LulzBot Color LCD UI                  // 适配 LulzBot 品牌 彩色液晶显示屏 的界面配置
  //#define LCD_FYSETC_TFT81050       // FYSETC with 5" (800x480)              // 适配 FYSETC 品牌 5寸高清显示屏，分辨率 800×480
  //#define LCD_EVE3_50G              // Matrix Orbital 5.0", 800x480, BT815   // 适配 Matrix Orbital 品牌 5寸 800x480 显示屏（BT815 主控）
  //#define LCD_EVE2_50G              // Matrix Orbital 5.0", 800x480, FT813   // 适配 Matrix Orbital 品牌 5寸 800x480 显示屏（FT813 主控）

  // Correct the resolution if not using the stock TFT panel.                  // 如果没有使用原装 TFT 屏幕，请在这里修正分辨率。
  //#define TOUCH_UI_320x240
  //#define TOUCH_UI_480x272
  //#define TOUCH_UI_800x480

  // Mappings for boards with a standard RepRapDiscount Display connector      // 针对带有标准 RepRapDiscount 显示屏接口的主板的引脚定义
  //#define AO_EXP1_PINMAP      // LulzBot CLCD UI EXP1 mapping                // LulzBot 品牌彩色显示屏 EXP1 接口引脚定义
  //#define AO_EXP2_PINMAP      // LulzBot CLCD UI EXP2 mapping                // LulzBot 品牌彩色显示屏 EXP2 接口引脚定义
  //#define CR10_TFT_PINMAP     // Rudolph Riedel's CR10 pin mapping           // Rudolph Riedel 定制版 CR-10 引脚映射（修正官方屏接口定义）
  //#define S6_TFT_PINMAP       // FYSETC S6 pin mapping                       // 富源盛S6主板屏幕引脚定义
  //#define F6_TFT_PINMAP       // FYSETC F6 pin mapping                       // 富源盛F6主板屏幕引脚定义

  //#define OTHER_PIN_LAYOUT  // Define pins manually below                    // 下方可手动自定义引脚参数
  #if ENABLED(OTHER_PIN_LAYOUT)
    // Pins for CS and MOD_RESET (PD) must be chosen                           // 必须为 CS 引脚 和 MOD_RESET (PD) 复位引脚 指定引脚号
    #define CLCD_MOD_RESET  9
    #define CLCD_SPI_CS    10

    // If using software SPI, specify pins for SCLK, MOSI, MISO                // 若使用软件SPI通信，需指定时钟、主发、主收引脚
    //#define CLCD_USE_SOFT_SPI
    #if ENABLED(CLCD_USE_SOFT_SPI)
      #define CLCD_SOFT_SPI_MOSI 11
      #define CLCD_SOFT_SPI_MISO 12
      #define CLCD_SOFT_SPI_SCLK 13
    #endif
  #endif

  // Display Orientation. An inverted (i.e. upside-down) display
  // is supported on the FT800. The FT810 and beyond also support
  // portrait and mirrored orientations.
  // 屏幕显示方向。FT800芯片支持倒置显示；FT810及后续芯片还支持竖屏、镜像显示
  //#define TOUCH_UI_INVERTED
  //#define TOUCH_UI_PORTRAIT
  //#define TOUCH_UI_MIRRORED

  // UTF8 processing and rendering.
  // Unsupported characters are shown as '?'.
  // 开启后，屏幕可以处理 UTF8 格式的文字
  // 如果屏幕不支持某个字符，会自动显示成 ? 代替
  //#define TOUCH_UI_USE_UTF8
  #if ENABLED(TOUCH_UI_USE_UTF8)
    // Western accents support. These accented characters use   // 西欧语言重音符号支持（法语/德语/西班牙语等特殊字符）
    // combined bitmaps and require relatively little storage.  // 这些重音字符采用合并位图格式，占用的存储空间非常小。
    #define TOUCH_UI_UTF8_WESTERN_CHARSET
    #if ENABLED(TOUCH_UI_UTF8_WESTERN_CHARSET)
      // Additional character groups. These characters require
      // full bitmaps and take up considerable storage:
      // 拓展字符集，这类字符需独立完整位图，占用存储空间较多
      //#define TOUCH_UI_UTF8_SUPERSCRIPTS  // ¹ ² ³
      //#define TOUCH_UI_UTF8_COPYRIGHT     // © ®
      //#define TOUCH_UI_UTF8_GERMANIC      // ß
      //#define TOUCH_UI_UTF8_SCANDINAVIAN  // Æ Ð Ø Þ æ ð ø þ
      //#define TOUCH_UI_UTF8_PUNCTUATION   // « » ¿ ¡
      //#define TOUCH_UI_UTF8_CURRENCY      // ¢ £ ¤ ¥
      //#define TOUCH_UI_UTF8_ORDINALS      // º ª
      //#define TOUCH_UI_UTF8_MATHEMATICS   // ± × ÷
      //#define TOUCH_UI_UTF8_FRACTIONS     // ¼ ½ ¾
      //#define TOUCH_UI_UTF8_SYMBOLS       // µ ¶ ¦ § ¬
    #endif

    // Cyrillic character set, costs about 27KiB of flash    // 西里尔字符集（俄语等），会占用约 27KiB 的闪存空间
    //#define TOUCH_UI_UTF8_CYRILLIC_CHARSET
  #endif

  // Use a smaller font when labels don't fit buttons        // 当按钮标签文字显示不下时，自动使用更小的字体
  #define TOUCH_UI_FIT_TEXT

  // Use a numeric passcode for "Screen lock" keypad.
  // (recommended for smaller displays)
  // 锁屏界面使用数字密码键盘，小尺寸屏幕建议启用
  //#define TOUCH_UI_PASSCODE

  // Output extra debug info for Touch UI events             // 输出触摸UI事件的额外调试信息
  //#define TOUCH_UI_DEBUG

  // Developer menu (accessed by touching "About Printer" copyright text)  // 开发者菜单，点击打印机关于页面版权文字即可调出
  //#define TOUCH_UI_DEVELOPER_MENU
#endif // TOUCH_UI_FTDI_EVE

//
// Classic UI Options     // 经典界面相关设置
//
#if TFT_SCALED_DOGLCD
  //#define TFT_MARLINUI_COLOR 0xFFFF // White         // 白色
  //#define TFT_MARLINBG_COLOR 0x0000 // Black         // 黑色
  //#define TFT_DISABLED_COLOR 0x0003 // Almost black  // 近乎纯黑色
  //#define TFT_BTCANCEL_COLOR 0xF800 // Red           // 红色
  //#define TFT_BTARROWS_COLOR 0xDEE6 // 11011 110111 00110 Yellow  // 黄色
  //#define TFT_BTOKMENU_COLOR 0x145F // 00010 100010 11111 Cyan    // 青色
#endif

/**
 * Display Sleep
 * Enable this option to save energy and prevent OLED pixel burn-in.
 * 
 * 显示屏休眠
 * 启用该选项可节约电量，并防止 OLED 屏幕出现像素烧屏。
 */
//#define DISPLAY_SLEEP_MINUTES 2       // (minutes) Timeout before turning off the screen     // （分钟）屏幕自动关闭的超时时间

/**
 * LCD Backlight Timeout
 * Requires a display with a controllable backlight
 * 
 * LCD 背光超时
 * 需要显示屏支持背光控制功能
 */
//#define LCD_BACKLIGHT_TIMEOUT_MINS 1  // (minutes) Timeout before turning off the backlight  // （分钟）背光自动关闭的超时时间

#if defined(DISPLAY_SLEEP_MINUTES) || defined(LCD_BACKLIGHT_TIMEOUT_MINS)
  #define EDITABLE_DISPLAY_TIMEOUT      // Edit sleep / backlight timeout with M255 S<minutes> and a menu item  // 通过 M255 S<分钟数> 指令和菜单选项，修改休眠 / 背光超时时间
#endif

//
// ADC Button Debounce    // ADC按键消抖
//
#if HAS_ADC_BUTTONS
  #define ADC_BUTTON_DEBOUNCE_DELAY 16  // (count) Increase if buttons bounce or repeat too fast  // (计数) 如果按键出现抖动或重复触发过快，可增大该数值
#endif

//#define FAST_BUTTON_POLLING           // Poll buttons at ~1kHz on 8-bit AVR. Set to 'false' for slow polling on 32-bit.  // 8位AVR主板上以约1kHz频率检测按键。32位主板请设为 false，使用低速检测。


//========================================== 安全设置 ===========================================
// @section safety

/**
 * The watchdog hardware timer will do a reset and disable all outputs
 * if the firmware gets too overloaded to read the temperature sensors.
 *
 * If you find that watchdog reboot causes your AVR board to hang forever,
 * enable WATCHDOG_RESET_MANUAL to use a custom timer instead of WDTO.
 * NOTE: This method is less reliable as it can only catch hangups while
 * interrupts are enabled.
 * 
 * 看门狗硬件定时器功能：
 * 如果固件因负载过高，无法读取温度传感器，
 * 看门狗会自动复位主板，并关闭所有输出端口。
 *
 * 如果发现看门狗复位导致你的 AVR 主板无限卡死，
 * 启用 WATCHDOG_RESET_MANUAL，使用自定义定时器替代默认的 WDTO。
 * 注意：这种方式可靠性稍低，它只能在**中断启用**的状态下检测死机。
 */
#define USE_WATCHDOG
#if ENABLED(USE_WATCHDOG)
  //#define WATCHDOG_RESET_MANUAL
#endif

// @section lcd

/**
 * Babystepping enables movement of the axes by tiny increments without changing
 * the current position values. This feature is used primarily to adjust the Z
 * axis in the first layer of a print in real-time.
 *
 * Warning: Does not respect endstops!
 * 
 * 微步微调功能
 * 可在不改动坐标数值的前提下，小幅移动坐标轴，主要用于打印首层时实时微调 Z 轴高度
 * 警告：该功能不受限位开关约束限制

 */
//#define BABYSTEPPING
#if ENABLED(BABYSTEPPING)
  //#define EP_BABYSTEPPING                 // M293/M294 babystepping with EMERGENCY_PARSER support                // 支持紧急解析器的 M293 / M294 微步调节指令
  //#define BABYSTEP_WITHOUT_HOMING
  //#define BABYSTEP_ALWAYS_AVAILABLE       // Allow babystepping at all times (not just during movement)          // 允许随时进行微步调节（不局限于打印头移动过程中）
  //#define BABYSTEP_XY                     // Also enable X/Y Babystepping. Not supported on DELTA!               // 同时启用 X / Y 轴微步调节。三角洲（DELTA）机型不支持！
  //#define BABYSTEP_INVERT_Z               // Enable if Z babysteps should go the other way                       // 若Z轴微步调节方向相反，可开启此选项
  //#define BABYSTEP_MILLIMETER_UNITS       // Specify BABYSTEP_MULTIPLICATOR_(XY|Z) in mm instead of micro-steps  // 以毫米（mm）为单位设置 BABYSTEP_MULTIPLICATOR_(XY|Z)，而非微步
  #define BABYSTEP_MULTIPLICATOR_Z  1       // (steps or mm) Steps or millimeter distance for each Z babystep      // (步数 或 毫米) 每次 Z 轴微步调节的移动距离
  #define BABYSTEP_MULTIPLICATOR_XY 1       // (steps or mm) Steps or millimeter distance for each XY babystep     // (步数 或 毫米) 每次 X / Y 轴微步调节的移动距离

  //#define DOUBLECLICK_FOR_Z_BABYSTEPPING  // Double-click on the Status Screen for Z Babystepping.               // 双击状态屏幕调出Z轴微步调节界面
  #if ENABLED(DOUBLECLICK_FOR_Z_BABYSTEPPING)
    #define DOUBLECLICK_MAX_INTERVAL 1250   // (ms) Maximum interval between clicks.                               // (毫秒) 双击操作的最大间隔时间
                                            // Note: Extra time may be added to mitigate controller latency.       // 注意：为了抵消控制器延迟，系统可能会自动额外增加一点时间。
    //#define MOVE_Z_WHEN_IDLE              // Jump to the move Z menu on double-click when printer is idle.       // 打印机空闲时，双击屏幕直接跳转至Z轴移动菜单
    #if ENABLED(MOVE_Z_WHEN_IDLE)
      #define MOVE_Z_IDLE_MULTIPLICATOR 1   // Multiply 1mm by this factor for the move step size.                 // 将 1mm 乘以该系数，作为 Z 轴移动的步长大小
    #endif
  #endif

  //#define BABYSTEP_DISPLAY_TOTAL          // Display total babysteps since last G28                              // 显示上次回零后累计的微步调节总量

  //#define BABYSTEP_ZPROBE_OFFSET          // Combine M851 Z and Babystepping                                     // 将M851Z轴偏移参数与微步调节数值合并计算
  #if ENABLED(BABYSTEP_ZPROBE_OFFSET)
    //#define BABYSTEP_HOTEND_Z_OFFSET      // For multiple hotends, babystep relative Z offsets                   // 多喷头机型时，微步调节将基于相对Z轴偏移量进行
    //#define BABYSTEP_GFX_OVERLAY          // Enable graphical overlay on Z-offset editor                         // 开启Z偏移编辑界面图形叠加显示
  #endif
#endif

// @section extruder

/**
 * Linear Pressure Control v1.5
 *
 * Assumption: advance [steps] = k * (delta velocity [steps/s])
 * K=0 means advance disabled.
 *
 * NOTE: K values for LIN_ADVANCE 1.5 differ from earlier versions!
 *
 * Set K around 0.22 for 3mm PLA Direct Drive with ~6.5cm between the drive gear and heatbreak.
 * Larger K values will be needed for flexible filament and greater distances.
 * If this algorithm produces a higher speed offset than the extruder can handle (compared to E jerk)
 * print acceleration will be reduced during the affected moves to keep within the limit.
 *
 * See https://marlinfw.org/docs/features/lin_advance.html for full instructions.
 * 
 * 线性压力控制 v1.5
 *
 * 计算公式：挤出提前量 [步数] = K × (速度变化量 [步数/秒])
 * K=0 表示关闭此功能。
 *
 * 注意：LIN_ADVANCE 1.5 版本的 K 值与旧版本不通用！
 *
 * 3mm PLA 直驱挤出机（齿轮到热断距离约6.5厘米）推荐 K 值约 0.22。
 * 柔性耗材或距离更长时，需要更大的 K 值。
 * 如果算法计算出的速度偏移超过挤出机承受能力（超过E轴 jerk），
 * 打印机会在相关移动时自动降低加速度以保证不超限。
 *
 * 完整教程：https://marlinfw.org/docs/features/lin_advance.html
 */
//#define LIN_ADVANCE
#if ENABLED(LIN_ADVANCE)
  #if ENABLED(DISTINCT_E_FACTORS)
    #define ADVANCE_K { 0.22 }    // (mm) Compression length per 1mm/s extruder speed, per extruder   // (毫米) 每1mm/s挤出速度对应的压缩长度，按每个挤出机单独设置
  #else
    #define ADVANCE_K 0.22        // (mm) Compression length applying to all extruders                // (毫米) 应用于所有挤出机的压缩长度
  #endif
  //#define ADVANCE_K_EXTRA       // Add a second linear advance constant, configurable with M900 L.  // 添加第二组线性推进系数，可通过 M900 L 指令进行配置
                                  //（译者注：上面的用途：切换软硬耗材时不用重新编译固件直驱 + 远程双模式挤出机，高级打印质量微调）
  //#define LA_DEBUG              // Print debug information to serial during operation. Disable for production use. // 运行时通过串口输出调试信息。正式使用（成品机/日常打印）时请关闭。
  //#define EXPERIMENTAL_I2S_LA   // Allow I2S_STEPPER_STREAM to be used with LA. Performance degrades as the LA step rate reaches ~20kHz.
                                  // 允许 I2S 步进流与线性推进(LA)同时使用。
                                  // 当 LA 步进速率接近 20kHz 时，系统性能会下降。

  //#define SMOOTH_LIN_ADVANCE    // Remove limits on acceleration by gradual increase of nozzle pressure  // 通过逐步增加喷嘴压力来消除加速度限制
  #if ENABLED(SMOOTH_LIN_ADVANCE)
    /**
     * ADVANCE_TAU is also the time ahead that the smoother needs to look
     * into the planner, so the planner needs to have enough blocks loaded.
     * For k=0.04 at 10k acceleration and an "Orbiter 2" extruder it can be as low as 0.0075.
     * Adjust by lowering the value until you observe the extruder skipping, then raise slightly.
     * Higher k and higher XY acceleration may require larger ADVANCE_TAU to avoid skipping steps.
     * 
     * ADVANCE_TAU 也是平滑算法需要提前“预判”的时间长度，
     * 因此运动规划器需要加载足够的运动段。
     * 对于 Orbiter 2 挤出机，加速度 10k、K=0.04 的情况下，
     * 此值最低可设为 0.0075。
     *
     * 调整方法：逐渐降低数值，直到出现挤出机丢步，
     * 然后再稍微调高一点。
     *
     * 更高的 K 值 和 更高的 XY 加速度，
     * 可能需要更大的 ADVANCE_TAU 来避免丢步。
     */
    #if ENABLED(DISTINCT_E_FACTORS)
      #define ADVANCE_TAU { 0.02 }   // (s) Smoothing time to reduce extruder acceleration, per extruder  // (秒) 单个挤出机的平滑时间，用于降低挤出机加速度
    #else
      #define ADVANCE_TAU 0.02       // (s) Smoothing time to reduce extruder acceleration                // (秒) 全局平滑时间，用于降低挤出机加速度
    #endif
    #define SMOOTH_LIN_ADV_HZ 1000   // (Hz) How often to update extruder speed                           // (赫兹) 挤出机速度的更新频率
    #define INPUT_SHAPING_E_SYNC     // Synchronize the extruder-shaped XY axes (to increase precision)   // 同步受挤出机影响的XY轴运动（用于提升精度）
  #endif
#endif

/**
 * Nonlinear Extrusion Control
 *
 * Control extrusion rate based on instantaneous extruder velocity. Can be used to correct for
 * underextrusion at high extruder speeds that are otherwise well-behaved (i.e., not skipping).
 * For better results also enable ADAPTIVE_STEP_SMOOTHING.
 * 
 * 非线性挤出控制
 *
 * 根据挤出机的实时速度来调整挤出量。
 * 可用于修正**高速挤出时出现的缺料**问题（前提是挤出机未发生丢步）。
 * 想要更好的效果，建议同时开启 ADAPTIVE_STEP_SMOOTHING。
 */
//#define NONLINEAR_EXTRUSION
#if ENABLED(NONLINEAR_EXTRUSION)
  //#define NONLINEAR_EXTRUSION_DEFAULT_ON    // Enable if NLE should be ON by default   // 设置非线性挤出控制默认开启状态
#endif


//======================================= 调平相关设置 =========================================
// @section leveling

/**
 * Use Safe Bed Leveling coordinates to move axes to a useful position before bed probing.
 * For example, after homing a rotational axis the Z probe might not be perpendicular to the bed.
 * Choose values the orient the bed horizontally and the Z-probe vertically.
 * 
 * 启用安全调平坐标，探针检测前将轴移动至合适位置
 * 旋转轴回零后，探针可能无法垂直贴合热床
 * 设置参数使热床保持水平、探针垂直向下检测
 */
//#define SAFE_BED_LEVELING_START_X 0.0
//#define SAFE_BED_LEVELING_START_Y 0.0
//#define SAFE_BED_LEVELING_START_Z 0.0
//#define SAFE_BED_LEVELING_START_I 0.0
//#define SAFE_BED_LEVELING_START_J 0.0
//#define SAFE_BED_LEVELING_START_K 0.0
//#define SAFE_BED_LEVELING_START_U 0.0
//#define SAFE_BED_LEVELING_START_V 0.0
//#define SAFE_BED_LEVELING_START_W 0.0

/**
 * Points to probe for all 3-point Leveling procedures.
 * Override if the automatically selected points are inadequate.
 * 三点调平模式的检测采样点
 * 自动点位效果不佳时可手动自定义设置
 */
#if NEEDS_THREE_PROBE_POINTS
  //#define PROBE_PT_1 {  15, 180 }   // (mm) { x, y }
  //#define PROBE_PT_2 {  15,  20 }
  //#define PROBE_PT_3 { 170,  20 }
#endif

/**
 * Probing Margins
 *
 * Override PROBING_MARGIN for each side of the build plate
 * Useful to get probe points to exact positions on targets or
 * to allow leveling to avoid plate clamps on only specific
 * sides of the bed. With NOZZLE_AS_PROBE negative values are
 * allowed, to permit probing outside the bed.
 *
 * If you are replacing the prior *_PROBE_BED_POSITION options,
 * LEFT and FRONT values in most cases will map directly over
 * RIGHT and REAR would be the inverse such as
 * (X/Y_BED_SIZE - RIGHT/BACK_PROBE_BED_POSITION)
 *
 * This will allow all positions to match at compilation, however
 * should the probe position be modified with M851XY then the
 * probe points will follow. This prevents any change from causing
 * the probe to be unable to reach any points.
 * 
 * 调平边界余量
 *
 * 可单独设定热床四边的探测边界偏移值
 * 便于精准定位探测点位，也可规避单侧床板夹具
 * 喷头兼作探针时支持负值，可在热床范围外探测
 *
 * 替换旧版点位参数参考：左侧、前侧数值可直接沿用
 * 右侧、后侧需按床体尺寸换算反向数值
 * 编译参数可保持点位一致，通过M851XY指令调整探针偏移后
 * 探测点位会同步跟随变化，避免出现探测点位超出行程的问题
 */
#if PROBE_SELECTED && !IS_KINEMATIC
  //#define PROBING_MARGIN_LEFT PROBING_MARGIN
  //#define PROBING_MARGIN_RIGHT PROBING_MARGIN
  //#define PROBING_MARGIN_FRONT PROBING_MARGIN
  //#define PROBING_MARGIN_BACK PROBING_MARGIN
#endif

#if ANY(MESH_BED_LEVELING, AUTO_BED_LEVELING_UBL)
  // Override the mesh area if the automatic (max) area is too large   // 当自动生成的最大网格区域过大时，使用此项手动覆盖网格区域
  //#define MESH_MIN_X MESH_INSET
  //#define MESH_MIN_Y MESH_INSET
  //#define MESH_MAX_X X_BED_SIZE - (MESH_INSET)
  //#define MESH_MAX_Y Y_BED_SIZE - (MESH_INSET)
#endif

#if ALL(AUTO_BED_LEVELING_UBL, EEPROM_SETTINGS)
  //#define OPTIMIZED_MESH_STORAGE  // Store mesh with less precision to save EEPROM space   // 使用较低精度存储网格数据，以节省 EEPROM 空间
#endif

/**
 * Repeatedly attempt G29 leveling until it succeeds.
 * Stop after G29_MAX_RETRIES attempts.
 * 
 * 自动重试调平操作，直至探测成功
 * 达到最大重试次数后停止尝试
 */
//#define G29_RETRY_AND_RECOVER
#if ENABLED(G29_RETRY_AND_RECOVER)
  #define G29_MAX_RETRIES 3
  #define G29_HALT_ON_FAILURE
  /**
   * Specify the GCODE commands that will be executed when leveling succeeds,
   * between attempts, and after the maximum number of retries have been tried.
   * 
   * 指定在以下场景时执行的自定义 GCode 指令：
   * 1. 调平成功时
   * 2. 每次重试之间
   * 3. 达到最大重试次数后（调平最终失败）
   */
  #define G29_SUCCESS_COMMANDS "M117 Bed leveling done."
  #define G29_RECOVER_COMMANDS "M117 Probe failed. Rewiping.\nG28\nG12 P0 S12 T0"
  #define G29_FAILURE_COMMANDS "M117 Bed leveling failed.\nG0 Z10\nM300 P25 S880\nM300 P50 S0\nM300 P25 S880\nM300 P50 S0\nM300 P25 S880\nM300 P50 S0\nG4 S1"

#endif


// 探针配置区
// @section probes

/**
 * Thermal Probe Compensation
 *
 * Adjust probe measurements to compensate for distortion associated with the temperature
 * of the probe, bed, and/or hotend.
 * Use G76 to automatically calibrate this feature for probe and bed temperatures.
 * (Extruder temperature/offset values must be calibrated manually.)
 * Use M871 to set temperature/offset values manually.
 * For more details see https://marlinfw.org/docs/features/probe_temp_compensation.html
 * 
 * 热探针补偿功能
 *
 * 根据探针、热床、/ 或喷头的温度，
 * 自动修正探针测量的高度偏差，消除温度带来的测量误差。
 *
 * 可使用 G76 指令自动校准探针与热床的温度补偿参数。
 * （喷头温度与偏移量必须手动校准）
 * 可使用 M871 指令手动设置温度/偏移参数。
 *
 * 详细说明见：https://marlinfw.org/docs/features/probe_temp_compensation.html
 * 
 * 
 * （译者注：）
 * 这是高精度打印的温度补偿功能：
 * 很多探针（如 BLTouch、电感、电容）温度变了，测量高度就会飘
 * 热床加热、喷头加热 → 探针受热 → Z 高度不准 → 打印第一层不平
 * 开启后，打印机会根据温度自动修正 Z 值，让第一层稳定
 */
//#define PTC_PROBE    // Compensate based on probe temperature   // 基于探针自身温度进行补偿
//#define PTC_BED      // Compensate based on bed temperature     // 基于热床温度进行补偿
//#define PTC_HOTEND   // Compensate based on hotend temperature  // 基于喷头（热端）温度进行补偿

#if ANY(PTC_PROBE, PTC_BED, PTC_HOTEND)
  /**
   * If the probe is outside the defined range, use linear extrapolation with the closest
   * point and the point with index PTC_LINEAR_EXTRAPOLATION. e.g., If set to 4 it will use the
   * linear extrapolation between data[0] and data[4] for values below PTC_PROBE_START.
   * 
   * 当探针温度超出预设校准范围时，使用最近点 + 指定索引点做线性外推计算
   * 示例：若设置为 4，则低于校准起始温度时，使用 data[0] 与 data[4] 两点进行外推补偿
   */
  //#define PTC_LINEAR_EXTRAPOLATION 4

  #if ENABLED(PTC_PROBE)
    // Probe temperature calibration generates a table of values starting at PTC_PROBE_START
    // (e.g., 30), in steps of PTC_PROBE_RES (e.g., 5) with PTC_PROBE_COUNT (e.g., 10) samples.
    // 探针温度校准会生成一张数值表
    // 起始温度：PTC_PROBE_START（例如 30℃）
    // 温度步长：PTC_PROBE_RES（例如 5℃）
    // 采样点数：PTC_PROBE_COUNT（例如 10 个点）
    #define PTC_PROBE_START   30    // (°C)
    #define PTC_PROBE_RES      5    // (°C)
    #define PTC_PROBE_COUNT   10
    #define PTC_PROBE_ZOFFS   { 0 } // (µm) Z adjustments per sample  // (微米) 每个采样点的 Z 轴补偿值
  #endif

  #if ENABLED(PTC_BED)
    // Bed temperature calibration builds a similar table.            // 热床温度校准会生成一张结构相同的补偿数据表
    #define PTC_BED_START     60    // (°C)
    #define PTC_BED_RES        5    // (°C)
    #define PTC_BED_COUNT     10
    #define PTC_BED_ZOFFS     { 0 } // (µm) Z adjustments per sample  // (微米) 每个采样点的 Z 轴补偿值
  #endif

  #if ENABLED(PTC_HOTEND)
    // Note: There is no automatic calibration for the hotend. Use M871. // 注意：热端（喷头）温度补偿不支持自动校准，必须使用 M871 指令手动设置
    #define PTC_HOTEND_START 180    // (°C)
    #define PTC_HOTEND_RES     5    // (°C)
    #define PTC_HOTEND_COUNT  20
    #define PTC_HOTEND_ZOFFS  { 0 } // (µm) Z adjustments per sample  // (微米) 每个采样点的 Z 轴补偿值
  #endif

  // G76 options
  #if ALL(PTC_PROBE, PTC_BED)
    // Park position to wait for probe cooldown  // 探针冷却等待停靠位置
    #define PTC_PARK_POS   { 0, 0, 100 }

    // Probe position to probe and wait for probe to reach target temperature       // 探测定位点位，在此等待探针温度达标
    //#define PTC_PROBE_POS  { 12.0f, 7.3f } // Example: MK52 magnetic heatbed      // 示例：MK52磁吸热床
    #define PTC_PROBE_POS  { 90, 100 }

    // The temperature the probe should be at while taking measurements during
    // bed temperature calibration.                                                 // 热床校准时，探针需达到的测量温度
    #define PTC_PROBE_TEMP    30  // (°C)

    // Height above Z=0.0 to raise the nozzle. Lowering this can help the probe to heat faster.
    // Note: The Z=0.0 offset is determined by the probe Z offset (e.g., as set with M851 Z).
    // 喷头抬升高度（相对于 Z=0.0 的位置）
    // 降低此值可以让探针更快被加热
    // 注意：Z=0.0 基准由探针 Z 偏移量决定（例如通过 M851 Z 设置）
    #define PTC_PROBE_HEATING_OFFSET 0.5  // (mm)
  #endif
#endif // PTC_PROBE || PTC_BED || PTC_HOTEND


//=============================================== 附加功能 / 扩展配置 ============================================
// @section extras

//
// G60/G61 Position Save and Return   // G60/G61 坐标位置保存与复位
//
//#define SAVED_POSITIONS 1         // Each saved position slot costs 12 bytes  // 每个保存的位置槽位占用 12 字节内存

//
// G2/G3 Arc Support
//
#define ARC_SUPPORT                   // Requires ~3226 bytes      // 启用该功能大约需要占用 3226 字节的固件存储空间
#if ENABLED(ARC_SUPPORT)
  #define MIN_ARC_SEGMENT_MM      0.1 // (mm) Minimum length of each arc segment                           // (毫米) 圆弧每一小段的最小长度
  #define MAX_ARC_SEGMENT_MM      1.0 // (mm) Maximum length of each arc segment                           // (毫米) 圆弧每一小段的最大长度
  #define MIN_CIRCLE_SEGMENTS    72   // Minimum number of segments in a complete circle                   // 一个完整圆形的最小分段数量
  //#define ARC_SEGMENTS_PER_SEC 50   // Use the feedrate to choose the segment length                     // 根据打印速度（进给率）自动计算圆弧分段长度
  #define N_ARC_CORRECTION       25   // Number of interpolated segments between corrections               // 校正间隔之间的插补段数
  //#define ARC_P_CIRCLES             // Enable the 'P' parameter to specify complete circles              // 启用 'P' 参数，用于指定绘制完整的圆圈数量
  //#define SF_ARC_FIX                // Enable only if using SkeinForge with "Arc Point" fillet procedure // 仅当使用带有 "Arc Point" 圆角功能的 SkeinForge 切片软件时才启用
#endif

// G5 Bézier Curve Support with XYZE destination and IJPQ offsets   // G5 贝塞尔曲线支持（包含 XYZE 目标点与 IJPQ 偏移参数）
//#define BEZIER_CURVE_SUPPORT        // Requires ~2666 bytes       // 启用该功能大约需要占用 2666 字节的固件存储空间

#if ANY(ARC_SUPPORT, BEZIER_CURVE_SUPPORT)
  //#define CNC_WORKSPACE_PLANES      // Allow G2/G3/G5 to operate in XY, ZX, or YZ planes    // 允许 G2/G3/G5 在 XY、ZX 或 YZ 平面上执行曲线运动
#endif

/**
 * Direct Stepping
 *
 * Comparable to the method used by Klipper, G6 direct stepping significantly
 * reduces motion calculations, increases top printing speeds, and results in
 * less step aliasing by calculating all motions in advance.
 * Preparing your G-code: https://github.com/colinrgodsey/step-daemon
 * 
 * 直接步进控制
 *
 * 与 Klipper 固件使用的技术类似，G6 直接步进能显著
 * 减少运动计算量、提升最高打印速度，
 * 并通过预先计算所有运动来减少步进丢步问题。
 * 准备你的 G-code：https://github.com/colinrgodsey/step-daemon
 */
//#define DIRECT_STEPPING

/**
 * G38 Probe Target
 *
 * This option adds G38.2 and G38.3 (probe towards target)
 * and optionally G38.4 and G38.5 (probe away from target).
 * Set MULTIPLE_PROBING for G38 to probe more than once.
 * 
 * 此选项启用 G38.2 和 G38.3（向目标方向探测）
 * 并可选择启用 G38.4 和 G38.5（远离目标方向探测）。
 * 设置 MULTIPLE_PROBING 可让 G38 进行多次探测以提高精度。
 */
//#define G38_PROBE_TARGET
#if ENABLED(G38_PROBE_TARGET)
  //#define G38_PROBE_AWAY        // Include G38.4 and G38.5 to probe away from target  // 包含 G38.4 和 G38.5 指令，用于**反向/远离目标**进行探测
  #define G38_MINIMUM_MOVE 0.0275 // (mm) Minimum distance that will produce a move.    // (毫米) 能触发电机移动的最小距离
#endif

// @section motion   // 运动控制

// Moves (or segments) with fewer steps than this will be joined with the next move     // 如果移动（或分段）的步数少于此数值，将会与下一个移动合并执行
#define MIN_STEPS_PER_SEGMENT 6

/**
 * Minimum delay before and after setting the stepper DIR (in ns)
 *     0 : No delay (Expect at least 10µS since one Stepper ISR must transpire)
 *    20 : Minimum for TMC2xxx drivers
 *   200 : Minimum for A4988 drivers
 *   400 : Minimum for A5984 drivers
 *   500 : Minimum for LV8729 drivers (guess, no info in datasheet)
 *   650 : Minimum for DRV8825 drivers
 *  1500 : Minimum for TB6600 drivers (guess, no info in datasheet)
 * 15000 : Minimum for TB6560 drivers (guess, no info in datasheet)
 *
 * Override the default value based on the driver type set in Configuration.h.
 * 
 * 设置步进电机方向（DIR）前后的最小延时（单位：纳秒 ns）
 *     0 : 无延时（至少需要 10µS，因为必须执行一次步进中断）
 *    20 : TMC2xxx 系列驱动最低要求
 *   200 : A4988 驱动最低要求
 *   400 : A5984 驱动最低要求
 *   500 : LV8729 驱动最低要求（估算，手册无数据）
 *   650 : DRV8825 驱动最低要求
 *  1500 : TB6600 驱动最低要求（估算，手册无数据）
 * 15000 : TB6560 驱动最低要求（估算，手册无数据）
 *
 * 根据 Configuration.h 中设置的驱动类型自动覆盖默认值。
 */
//#define MINIMUM_STEPPER_POST_DIR_DELAY 650
//#define MINIMUM_STEPPER_PRE_DIR_DELAY 650

/**
 * Minimum stepper driver pulse width (in ns)
 * If undefined, these defaults (from Conditionals-4-adv.h) apply:
 *     100 : Minimum for TMC2xxx stepper drivers
 *     500 : Minimum for LV8729
 *    1000 : Minimum for A4988 and A5984 stepper drivers
 *    2000 : Minimum for DRV8825 stepper drivers
 *    3000 : Minimum for TB6600 stepper drivers
 *   30000 : Minimum for TB6560 stepper drivers
 *
 * Override the default value based on the driver type set in Configuration.h.
 * 
 * 步进驱动最小脉冲宽度（单位：纳秒 ns）
 * 如果未自定义，将使用默认值（来自 Conditionals-4-adv.h）：
 *     100 : TMC2xxx 系列驱动最小要求
 *     500 : LV8729 驱动最小要求
 *    1000 : A4988 / A5984 驱动最小要求
 *    2000 : DRV8825 驱动最小要求
 *    3000 : TB6600 驱动最小要求
 *   30000 : TB6560 驱动最小要求
 *
 * 根据 Configuration.h 中设置的驱动类型自动覆盖默认值。
 */
//#define MINIMUM_STEPPER_PULSE_NS 2000

/**
 * Maximum stepping rate (in Hz) the stepper driver allows
 * If undefined, these defaults (from Conditionals-4-adv.h) apply:
 *  5000000 : Maximum for TMC2xxx stepper drivers
 *  1000000 : Maximum for LV8729 stepper driver
 *   500000 : Maximum for A4988 stepper driver
 *   250000 : Maximum for DRV8825 stepper driver
 *   150000 : Maximum for TB6600 stepper driver
 *    15000 : Maximum for TB6560 stepper driver
 *
 * Override the default value based on the driver type set in Configuration.h.
 * 
 * 步进驱动允许的最大步进频率（单位：赫兹 Hz）
 * 如果未自定义，将使用默认值（来自 Conditionals-4-adv.h）：
 *  5000000：TMC2xxx 系列驱动最大值
 *  1000000：LV8729 驱动最大值
 *   500000：A4988 驱动最大值
 *   250000：DRV8825 驱动最大值
 *   150000：TB6600 驱动最大值
 *    15000：TB6560 驱动最大值
 *
 * 根据 Configuration.h 中设置的驱动类型自动覆盖默认值。
 */
//#define MAXIMUM_STEPPER_RATE 250000

// @section temperature  温度设置

// Control heater 0 and heater 1 in parallel.   // 并联同步控制0号与1号加热设备
//#define HEATERS_PARALLEL

//===========================================================================
//================================= Buffers =================================
//===========================================================================
// 缓冲区配置

// @section gcode

// The number of linear moves that can be in the planner at once.  //  planner 中可同时缓存的直线运动指令数量
#if ALL(HAS_MEDIA, DIRECT_STEPPING)
  #define BLOCK_BUFFER_SIZE  8
#elif HAS_MEDIA
  #define BLOCK_BUFFER_SIZE 16
#else
  #define BLOCK_BUFFER_SIZE 16
#endif

// @section serial

// The ASCII buffer for serial input  // 串口输入的 ASCII 指令缓冲区
#define MAX_CMD_SIZE 96
#define BUFSIZE 4

/**
 * Host Transmit Buffer Size
 *  - Costs 386 bytes of flash and TX_BUFFER_SIZE+3 bytes of SRAM (if not 0).
 *  - 4 bytes required to buffer a simple "ok".
 *  - 32 bytes for ADVANCED_OK (M105).
 *  - 128 bytes for the optimal speed of 'debug-echo:'
 *  - Other output doesn't need to be that speedy.
 * :[0, 2, 4, 8, 16, 32, 64, 128, 256]
 * 
 * 主机发送缓冲区大小
 *  - 消耗 386 字节闪存 + TX_BUFFER_SIZE+3 字节内存 (不为 0 时)
 *  - 简单的 "ok" 响应需要 4 字节
 *  - 高级状态反馈 (M105) 需要 32 字节
 *  - debug-echo 调试输出最优速度需要 128 字节
 *  - 其他输出不需要这么快
 * :[0, 2, 4, 8, 16, 32, 64, 128, 256]
 */
#define TX_BUFFER_SIZE 0

/**
 * Host Receive Buffer Size
 * Without XON/XOFF flow control (see SERIAL_XON_XOFF below) 32 bytes should be enough.
 * To use flow control, set this buffer size to at least 1024 bytes.
 * :[0, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048]
 * 
 * 主机接收缓冲区大小
 * 如果不使用 XON/XOFF 流控（见下方 SERIAL_XON_XOFF），32 字节通常足够。
 * 如果要使用流控，此缓冲区必须设置为至少 1024 字节。
 * 可选值：[0, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048]
 */
//#define RX_BUFFER_SIZE 1024

#if RX_BUFFER_SIZE >= 1024
  // Enable to have the controller send XON/XOFF control characters to
  // the host to signal the RX buffer is becoming full.
  // 启用后，控制器会向主机发送 XON/XOFF 控制字符
  // 用于通知主机：接收缓冲区（RX buffer）即将满了。
  //#define SERIAL_XON_XOFF
#endif

#if HAS_MEDIA
  // Enable this option to collect and display the maximum
  // RX queue usage after transferring a file to SD.
  // 启用此选项后，在文件传输到 SD 卡完成后，
  // 会统计并显示接收缓冲区（RX队列）的**最高使用率**。
  //#define SERIAL_STATS_MAX_RX_QUEUED

  // Enable this option to collect and display the number
  // of dropped bytes after a file transfer to SD.
  // 启用此选项后，在文件传输到 SD 卡完成后，
  // 会统计并显示传输过程中**丢失的字节数量**。
  //#define SERIAL_STATS_DROPPED_RX
#endif

// Monitor RX buffer usage
// Dump an error to the serial port if the serial receive buffer overflows.
// If you see these errors, increase the RX_BUFFER_SIZE value.
// Not supported on all platforms.
// 监控接收缓冲区（RX）使用情况
// 如果串口接收缓冲区溢出，会向串口输出错误信息。
// 如果你看到这类错误，请增大 RX_BUFFER_SIZE 的值。
// 并非所有平台都支持此功能。
//#define RX_BUFFER_MONITOR

/**
 * Emergency Command Parser
 *
 * Add a low-level parser to intercept certain commands as they
 * enter the serial receive buffer, so they cannot be blocked.
 * Currently handles M108, M112, M410, M876
 * NOTE: Not yet implemented for all platforms.
 * 
 * 紧急指令解析器
 *
 * 添加一个底层解析器，在指令进入串口接收缓冲区时**直接拦截特定紧急指令**，
 * 确保这些指令**永远不会被阻塞、延迟**。
 * 当前支持：M108、M112、M410、M876
 * 注意：并非所有平台都已实现此功能。
 */
//#define EMERGENCY_PARSER

/**
 * Realtime Reporting (requires EMERGENCY_PARSER)
 *
 * - Report position and state of the machine (like Grbl).
 * - Auto-report position during long moves.
 * - Useful for CNC/LASER.
 *
 * Adds support for commands:
 *  S000 : Report State and Position while moving.
 *  P000 : Instant Pause / Hold while moving.
 *  R000 : Resume from Pause / Hold.
 *
 * - During Hold all Emergency Parser commands are available, as usual.
 * - Enable NANODLP_Z_SYNC and NANODLP_ALL_AXIS for move command end-state reports.
 * 
 * 实时状态报告（需要先开启 EMERGENCY_PARSER）
 *
 * - 报告机器位置和状态（类似 Grbl 控制系统）。
 * - 在长距离移动过程中自动报告位置。
 * - 对 CNC / 激光切割机 非常有用。
 *
 * 添加支持的指令：
 *  S000 : 移动时实时报告状态与位置
 *  P000 : 移动中立即暂停 / 保持
 *  R000 : 从暂停状态恢复
 *
 * - 暂停期间，所有紧急解析器指令均可正常使用。
 * - 若需要移动指令结束状态报告，请启用 NANODLP_Z_SYNC 和 NANODLP_ALL_AXIS。
 */
//#define REALTIME_REPORTING_COMMANDS
#if ENABLED(REALTIME_REPORTING_COMMANDS)
  //#define FULL_REPORT_TO_HOST_FEATURE   // Auto-report the machine status like Grbl CNC  // 像 Grbl 数控系统一样，自动报告机器状态
#endif

/**
 * Bad Serial-connections can miss a received command by sending an 'ok'
 * Therefore some clients abort after 30 seconds in a timeout.
 * Some other clients start sending commands while receiving a 'wait'.
 * This "wait" is only sent when the buffer is empty. 1 second is a good value here.
 * 
 * 不稳定的串口连接可能会在发送 'ok' 响应后丢失接收到的指令
 * 因此部分控制软件会在 30 秒超时后中止传输
 * 另一些软件在收到 'wait' 响应时会开始重新发送指令
 * 这个 "wait" 仅在缓冲区为空时发送，设置为 1 秒是个合适的值
 */
//#define NO_TIMEOUTS 1000 // (ms)

// Some clients will have this feature soon. This could make the NO_TIMEOUTS unnecessary.
// 部分上位机软件后续将适配该机制，届时无需再启用超时禁用选项
//#define ADVANCED_OK

// Printrun may have trouble receiving long strings all at once.
// This option inserts short delays between lines of serial output.
// Printrun 上位机可能无法一次性接收过长的字符串。
// 该选项会在串口输出的每行信息之间插入短暂延时。
#define SERIAL_OVERRUN_PROTECTION

// For serial echo, the number of digits after the decimal point   // 串口回显时，小数点后的数字位数
//#define SERIAL_FLOAT_PRECISION 4

/**
 * This feature is EXPERIMENTAL so use with caution and test thoroughly.
 * Enable this option to receive data on the serial ports via the onboard DMA
 * controller for more stable and reliable high-speed serial communication.
 * Support is currently limited to some STM32 MCUs and all HC32 MCUs.
 * Note: This has no effect on emulated USB serial ports.
 * 
 * 此功能属于**实验性特性**，使用请谨慎，并进行全面测试。
 * 启用该选项后，将通过板载 DMA 控制器在串口接收数据，
 * 以实现更稳定、可靠的高速串口通信。
 * 目前仅支持部分 STM32 主控芯片 及 全部 HC32 主控芯片。
 * 注意：该功能对**虚拟 USB 串口**无效。
 */
//#define SERIAL_DMA

/**
 * Set the number of proportional font spaces required to fill up a typical character space.
 * This can help to better align the output of commands like 'G29 O' Mesh Output.
 *
 * For clients that use a fixed-width font (like OctoPrint), leave this set to 1.0.
 * Otherwise, adjust according to your client and font.
 * 
 * 设置比例字体下单个字符占位宽度
 * 可优化G29 O等网格数据输出的排版对齐效果
 * 固定宽度字体（如OctoPrint）保持1.0即可
 * 其余场景按上位机字体样式微调数值
 */
#define PROPORTIONAL_FONT_RATIO 1.0

// @section extras

/**
 * Extra Fan Speed
 * Adds a secondary fan speed for each print-cooling fan.
 *   'M106 P<fan> T3-255' : Set a secondary speed for <fan>
 *   'M106 P<fan> T2'     : Use the set secondary speed
 *   'M106 P<fan> T1'     : Restore the previous fan speed
 * 
 * 额外风扇转速
 * 为每个打印冷却风扇增加一个备用转速档位。
 *   'M106 P<风扇编号> T3-255' ：设置该风扇的备用转速
 *   'M106 P<风扇编号> T2'     ：启用备用转速
 *   'M106 P<风扇编号> T1'     ：恢复原来的风扇转速
 */
//#define EXTRA_FAN_SPEED

// @section gcode

/**
 * Firmware-based and LCD-controlled retract
 *
 * Add G10 / G11 commands for automatic firmware-based retract / recover.
 * Use M207 and M208 to define parameters for retract / recover.
 *
 * Use M209 to enable or disable auto-retract.
 * With auto-retract enabled, all G1 E moves within the set range
 * will be converted to firmware-based retract/recover moves.
 *
 * Be sure to turn off auto-retract during filament change.
 *
 * Note that M207 / M208 / M209 settings are saved to EEPROM.
 * 
 * 基于固件 & 由LCD控制的回抽（退料）功能
 *
 * 添加 G10 / G11 指令，用于自动执行固件级回抽 / 回抽恢复
 * 使用 M207 和 M208 来设置回抽 / 恢复的参数
 *
 * 使用 M209 开启或关闭自动回抽
 * 开启自动回抽后，所有在设定范围内的 G1 E 挤出移动
 * 都会被转换为固件级的回抽 / 恢复动作
 *
 * 更换耗材时，请务必关闭自动回抽
 *
 * 注意：M207 / M208 / M209 的设置会被保存到 EEPROM
 */
//#define FWRETRACT
#if ENABLED(FWRETRACT)
  #define FWRETRACT_AUTORETRACT             // Override slicer retractions         // 覆盖（替换）切片软件生成的回抽指令
  #if ENABLED(FWRETRACT_AUTORETRACT)
    #define MIN_AUTORETRACT             0.1 // (mm) Don't convert E moves under this length   // (毫米) 小于此长度的 E 轴移动，不转换为固件回抽
    #define MAX_AUTORETRACT            10.0 // (mm) Don't convert E moves over this length    // (毫米) 超过此长度的 E 轴移动，不转换为固件回抽
  #endif
  #define RETRACT_LENGTH                3   // (mm) Default retract length (positive value)   // (毫米) 默认回抽长度（请使用正数）
  #define RETRACT_LENGTH_SWAP          13   // (mm) Default swap retract length (positive value)  // (毫米) 默认交换回抽长度（使用正值）
  #define RETRACT_FEEDRATE             45   // (mm/s) Default feedrate for retracting             // (毫米/秒) 默认回抽速度
  #define RETRACT_ZRAISE                0   // (mm) Default retract Z-raise                       // (毫米) 回抽同步Z轴抬升高度
  #define RETRACT_RECOVER_LENGTH        0   // (mm) Default additional recover length (added to retract length on recover)                       // (毫米) 默认额外恢复长度（恢复时，在回抽长度基础上额外增加的长度）
  #define RETRACT_RECOVER_LENGTH_SWAP   0   // (mm) Default additional swap recover length (added to retract length on recover from toolchange)  // (毫米) 切换喷头后的额外恢复长度（在回抽长度基础上额外增加）
  #define RETRACT_RECOVER_FEEDRATE      8   // (mm/s) Default feedrate for recovering from retraction                                            // (毫米/秒) 回抽恢复（补料）的默认速度
  #define RETRACT_RECOVER_FEEDRATE_SWAP 8   // (mm/s) Default feedrate for recovering from swap retraction                                       // (毫米/秒) 切换喷头后回抽恢复的默认补料速度
  #if ENABLED(MIXING_EXTRUDER)
    //#define RETRACT_SYNC_MIXING           // Retract and restore all mixing steppers simultaneously   // 同步回抽与复位所有混色挤出步进电机
  #endif
#endif

// @section tool change

/**
 * Universal tool change settings.
 * Applies to all types of extruders except where explicitly noted.
 * 
 * 通用喷头切换设置。
 * 适用于所有类型的挤出机，除非有特别注明。
 */
#if HAS_MULTI_EXTRUDER
  // Z raise distance for tool-change, as needed for some extruders     // 切换喷头时Z轴抬升高度，部分挤出机构需此项设置
  #define TOOLCHANGE_ZRAISE                 2 // (mm)
  //#define TOOLCHANGE_ZRAISE_BEFORE_RETRACT  // Apply raise before swap retraction (if enabled)    // 切换回抽前先执行Z轴抬升（功能开启时生效）
  //#define TOOLCHANGE_NO_RETURN              // Never return to previous position on tool-change   // 切换喷头后不回归原先坐标位置
  #if ENABLED(TOOLCHANGE_NO_RETURN)
    //#define EVENT_GCODE_AFTER_TOOLCHANGE "G12X"   // Extra G-code to run after tool-change        // 喷头切换完成后额外执行的G代码
  #endif

  /**
   * Extra G-code to run while executing tool-change commands. Can be used to use an additional
   * stepper motor (e.g., I axis in Configuration.h) to drive the tool-changer.
   * 
   * 执行喷头切换指令时，额外运行的自定义G代码。
   * 可用于驱动额外的步进电机（例如 Configuration.h 中的 I 轴）
   * 来控制自动换刀/换头装置。
   */
  //#define EVENT_GCODE_TOOLCHANGE_T0 "G28 A\nG1 A0"  // Extra G-code to run while executing tool-change command T0  // 执行T0喷头切换指令时额外运行的G代码
  //#define EVENT_GCODE_TOOLCHANGE_T1 "G1 A10"        // Extra G-code to run while executing tool-change command T1  // 执行T1喷头切换指令时额外运行的G代码
  //#define EVENT_GCODE_TOOLCHANGE_ALWAYS_RUN         // Always execute above G-code sequences. Use with caution!    // 始终执行上述G代码序列，谨慎启用！

  /**
   * Consider coordinates for EVENT_GCODE_TOOLCHANGE_Tx as relative to T0
   * so that moves in the specified axes are the same for all tools.
   * 
   * 将换头事件G代码（EVENT_GCODE_TOOLCHANGE_Tx）的坐标视为相对于 T0 喷头
   * 使所有喷头在指定轴上的移动行为保持一致
   */
  //#define TC_GCODE_USE_GLOBAL_X   // Use X position relative to Tool 0  // X轴位置使用相对于 0 号喷头（T0）的坐标
  //#define TC_GCODE_USE_GLOBAL_Y   // Use Y position relative to Tool 0  // Y轴位置使用相对于 0 号喷头（T0）的坐标
  //#define TC_GCODE_USE_GLOBAL_Z   // Use Z position relative to Tool 0  // Z轴位置使用相对于 0 号喷头（T0）的坐标

  /**
   * Tool Sensors detect when tools have been picked up or dropped.
   * Requires the pins TOOL_SENSOR1_PIN, TOOL_SENSOR2_PIN, etc.
   * 
   * 工具传感器用于检测喷头抓取与释放状态
   * 需要配置TOOL_SENSOR1_PIN、TOOL_SENSOR2_PIN等引脚
   */
  //#define TOOL_SENSOR

  /**
   * Retract and prime filament on tool-change to reduce
   * ooze and stringing and to get cleaner transitions.
   * 切换喷头时回缩并预挤出耗材，减少拉丝溢料，提升换料过渡效果
   */
  //#define TOOLCHANGE_FILAMENT_SWAP
  #if ENABLED(TOOLCHANGE_FILAMENT_SWAP)
    // Load / Unload                              // 进料 / 退料 相关参数
    #define TOOLCHANGE_FS_LENGTH              12  // (mm) Load / Unload length                                        // (毫米) 耗材装入 / 退出长度
    #define TOOLCHANGE_FS_EXTRA_RESUME_LENGTH  0  // (mm) Extra length for better restart. Adjust with LCD or M217 B. //（毫米）补料余量，优化重启出料效果，可通过屏幕或M217 B指令调整
    #define TOOLCHANGE_FS_RETRACT_SPEED   (50*60) // (mm/min) (Unloading)                                             // (毫米/分钟) 退料速度（卸载耗材）
    #define TOOLCHANGE_FS_UNRETRACT_SPEED (25*60) // (mm/min) (On SINGLENOZZLE or Bowden loading must be slowed down) // (毫米/分钟) 进料速度    (单喷嘴机型 或 鲍登管结构 必须降低进料速度)

    // Longer prime to clean out a SINGLENOZZLE   // 加长预挤出行程，清理单喷嘴残留耗材
    #define TOOLCHANGE_FS_EXTRA_PRIME          0  // (mm) Extra priming length
    #define TOOLCHANGE_FS_PRIME_SPEED    (4.6*60) // (mm/min) Extra priming feedrate
    #define TOOLCHANGE_FS_WIPE_RETRACT         0  // (mm) Cutting retraction out of park, for less stringing, better wipe, etc. Adjust with LCD or M217 G.

    // Cool after prime to reduce stringing       // 预挤出后冷却喷嘴，减少拉丝
    #define TOOLCHANGE_FS_FAN                 -1  // Fan index or -1 to skip
    #define TOOLCHANGE_FS_FAN_SPEED          255  // 0-255
    #define TOOLCHANGE_FS_FAN_TIME            10  // (seconds)

    // Use TOOLCHANGE_FS_PRIME_SPEED feedrate the first time each extruder is primed   // 每个挤出机首次预挤出时，使用 TOOLCHANGE_FS_PRIME_SPEED 设定的进给速度
    //#define TOOLCHANGE_FS_SLOW_FIRST_PRIME

    /**
     * Prime T0 the first time T0 is sent to the printer:
     *  [ Power-On -> T0 { Activate & Prime T0 } -> T1 { Retract T0, Activate & Prime T1 } ]
     * If disabled, no priming on T0 until switching back to T0 from another extruder:
     *  [ Power-On -> T0 { T0 Activated } -> T1 { Activate & Prime T1 } -> T0 { Retract T1, Activate & Prime T0 } ]
     * Enable with M217 V1 before printing to avoid unwanted priming on host connect.
     * 
     * 首次发送 T0 指令到打印机时，对 T0 喷头进行预挤出（Prime）：
     *  【开机 -> T0 { 激活并预挤出 T0 } -> T1 { 回抽 T0，激活并预挤出 T1 }】
     * 如果禁用：
     *  从其他挤出机切回 T0 之前，T0 不会执行预挤出
     *  【开机 -> T0 { 仅激活 T0 } -> T1 { 激活并预挤出 T1 } -> T0 { 回抽 T1，激活并预挤出 T0 }】
     * 打印前可用 M217 V1 启用，避免连接主机时产生不必要的预挤出动作
     */
    //#define TOOLCHANGE_FS_PRIME_FIRST_USED

    /**
     * Tool Change Migration
     * This feature provides G-code and LCD options to switch tools mid-print.
     * All applicable tool properties are migrated so the print can continue.
     * Tools must be closely matching and other restrictions may apply.
     * Useful to:
     *   - Change filament color without interruption
     *   - Switch spools automatically on filament runout
     *   - Switch to a different nozzle on an extruder jam
     * 
     * 工具切换迁移功能
     * 该功能提供G代码和屏幕菜单选项，支持打印中途切换喷头/工具
     * 切换时会自动迁移所有相关的喷头参数，确保打印可无缝继续
     * 要求各喷头/工具参数高度匹配，且可能存在其他使用限制
     * 适用场景：
     *   - 不中断打印更换耗材颜色
     *   - 耗材断料时自动切换线轴
     *   - 挤出机堵头时切换到备用喷嘴
     */
    #define TOOLCHANGE_MIGRATION_FEATURE
    #if ENABLED(TOOLCHANGE_MIGRATION_FEATURE)
      // Override toolchange settings
      // By default tool migration uses regular toolchange settings.
      // With a prime tower, tool-change swapping/priming occur inside the bed.
      // When migrating to a new unprimed tool you can set override values below.
      // 覆盖工具切换参数
      // 默认情况下，工具迁移功能使用常规的工具切换设置。
      // 使用打印塔（Prime Tower）时，工具切换、换料、预挤出会在打印平台区域内完成。
      // 当切换到一个未进行过预挤出的新工具时，你可以在下方设置覆盖值。
      //#define MIGRATION_ZRAISE            0 // (mm)

      // Longer prime to clean out
      //#define MIGRATION_FS_EXTRA_PRIME    0 // (mm) Extra priming length                                         //（毫米）额外预挤出长度
      //#define MIGRATION_FS_WIPE_RETRACT   0 // (mm) Retract before cooling for less stringing, better wipe, etc. //（毫米）冷却前回抽耗材，减少拉丝、提升抹料效果

      // Cool after prime to reduce stringing                   // 预挤出后降温，削减拉丝现象
      //#define MIGRATION_FS_FAN_SPEED    255 // 0-255
      //#define MIGRATION_FS_FAN_TIME       0 // (seconds)
    #endif
  #endif

  /**
   * Position to park head during tool change.
   * Doesn't apply to SWITCHING_TOOLHEAD, DUAL_X_CARRIAGE, or PARKING_EXTRUDER
   * 
   * 换刀时机头停靠位置
   * 不适用于可切换喷头、双X轴滑座、可收纳挤出机机型
   */
  //#define TOOLCHANGE_PARK
  #if ENABLED(TOOLCHANGE_PARK)
    #define TOOLCHANGE_PARK_XY    { X_MIN_POS + 10, Y_MIN_POS + 10 }
    #define TOOLCHANGE_PARK_XY_FEEDRATE 6000  // (mm/min)
    //#define TOOLCHANGE_PARK_X_ONLY          // X axis only move  // 仅沿 X 轴移动
    //#define TOOLCHANGE_PARK_Y_ONLY          // Y axis only move  // 仅沿 Y 轴移动
    #if ENABLED(TOOLCHANGE_MIGRATION_FEATURE)
      //#define TOOLCHANGE_MIGRATION_DO_PARK  // Force park (or no-park) on migration  // 工具迁移时强制停靠（或不停靠）喷头
    #endif
  #endif
#endif // HAS_MULTI_EXTRUDER

// @section advanced pause
// 高级暂停

/**
 * Advanced Pause for Filament Change
 *  - Adds the G-code M600 Filament Change to initiate a filament change.
 *  - This feature is required for the default FILAMENT_RUNOUT_SCRIPT.
 *
 * Requirements:
 *  - For Filament Change parking enable and configure NOZZLE_PARK_FEATURE.
 *  - For user interaction enable an LCD display, HOST_PROMPT_SUPPORT, or EMERGENCY_PARSER.
 *
 * Enable PARK_HEAD_ON_PAUSE to add the G-code M125 Pause and Park.
 * 
 * 高级暂停 - 更换耗材
 *  - 添加 G 代码 M600 用于触发耗材更换
 *  - 默认的断料检测脚本（FILAMENT_RUNOUT_SCRIPT）必须依赖此功能
 *
 * 要求：
 *  - 如需更换耗材时喷头自动停靠，必须启用并配置 NOZZLE_PARK_FEATURE
 *  - 如需用户交互操作，必须启用 LCD 屏幕、上位机提示支持 或 紧急指令解析器
 *
 * 启用 PARK_HEAD_ON_PAUSE 可添加 G 代码 M125 暂停并停靠喷头
 */
//#define ADVANCED_PAUSE_FEATURE
#if ENABLED(ADVANCED_PAUSE_FEATURE)
  #define PAUSE_PARK_RETRACT_FEEDRATE         60  // (mm/s) Initial retract feedrate.                                   // (毫米/秒) 初始回抽速度
  #define PAUSE_PARK_RETRACT_LENGTH            2  // (mm) Initial retract.                                              // (mm) 初始回抽长度（移动喷头前先抽一点）
                                                  // This short retract is done immediately, before parking the nozzle.
  #define FILAMENT_CHANGE_UNLOAD_FEEDRATE     10  // (mm/s) Unload filament feedrate. This can be pretty fast.          // (mm/s) 退料速度（可以快）
  #define FILAMENT_CHANGE_UNLOAD_ACCEL        25  // (mm/s^2) Lower acceleration may allow a faster feedrate.           // (mm/s²) 退料加速度
  #define FILAMENT_CHANGE_UNLOAD_LENGTH      100  // (mm) The length of filament for a complete unload.                 // (mm) 完全退料长度
                                                  //   For Bowden, the full length of the tube and nozzle.              // 鲍登管：管长 + 喷嘴长
                                                  //   For direct drive, the full length of the nozzle.                 // 直驱：喷嘴内部长度
                                                  //   Set to 0 for manual unloading.                                   // 设 0 = 手动退料
  #define FILAMENT_CHANGE_SLOW_LOAD_FEEDRATE   6  // (mm/s) Slow move when starting load.                               // (mm/s) 开始插入时的慢速进料
  #define FILAMENT_CHANGE_SLOW_LOAD_LENGTH     0  // (mm) Slow length, to allow time to insert material.                // (mm) 慢速进料长度（0=直接快进）
                                                  // 0 to disable start loading and skip to fast load only
  #define FILAMENT_CHANGE_FAST_LOAD_FEEDRATE   6  // (mm/s) Load filament feedrate. This can be pretty fast.            // (mm/s) 快速进料速度
  #define FILAMENT_CHANGE_FAST_LOAD_ACCEL     25  // (mm/s^2) Lower acceleration may allow a faster feedrate.           // (mm/s²) 进料加速度
  #define FILAMENT_CHANGE_FAST_LOAD_LENGTH     0  // (mm) Load length of filament, from extruder gear to nozzle.        // (mm) 快进长度（送料到喷嘴）
                                                  //   For Bowden, the full length of the tube and nozzle.
                                                  //   For direct drive, the full length of the nozzle.
  //#define ADVANCED_PAUSE_CONTINUOUS_PURGE       // Purge continuously up to the purge length until interrupted.
  #define ADVANCED_PAUSE_PURGE_FEEDRATE        3  // (mm/s) Extrude feedrate (after loading). Should be slower than load feedrate. // (mm/s) 挤料排残料速度（必须慢）
  #define ADVANCED_PAUSE_PURGE_LENGTH         50  // (mm) Length to extrude after loading.                              // (mm) 换料后自动挤料长度（0=手动挤料）
                                                  //   Set to 0 for manual extrusion.
                                                  //   Filament can be extruded repeatedly from the Filament Change menu
                                                  //   until extrusion is consistent, and to purge old filament.
  #define ADVANCED_PAUSE_RESUME_PRIME          0  // (mm) Extra distance to prime nozzle after returning from park.     // (mm) 恢复打印前额外补料
  //#define ADVANCED_PAUSE_FANS_PAUSE             // Turn off print-cooling fans while the machine is paused.           // 暂停时关闭散热风扇

                                                  // Filament Unload does a Retract, Delay, and Purge first:
  #define FILAMENT_UNLOAD_PURGE_RETRACT       13  // (mm) Unload initial retract length.                                // (mm) 退料前回抽长度
  #define FILAMENT_UNLOAD_PURGE_DELAY       5000  // (ms) Delay for the filament to cool after retract.                 // (ms) 回抽后等待冷却时间
  #define FILAMENT_UNLOAD_PURGE_LENGTH         8  // (mm) An unretract is done, then this length is purged.             // (mm) 退料前挤料长度
  #define FILAMENT_UNLOAD_PURGE_FEEDRATE      25  // (mm/s) feedrate to purge before unload                             // (mm/s) 退料前挤料速度

  #define PAUSE_PARK_NOZZLE_TIMEOUT           45  // (seconds) Time limit before the nozzle is turned off for safety.   // (秒) 超时自动关喷嘴（安全保护）
  #define FILAMENT_CHANGE_ALERT_BEEPS         10  // Number of alert beeps to play when a response is needed.           // 需要操作时的提示蜂鸣次数
  #define PAUSE_PARK_NO_STEPPER_TIMEOUT           // Enable for XYZ steppers to stay powered on during filament change.
  //#define FILAMENT_CHANGE_RESUME_ON_INSERT      // Automatically continue / load filament when runout sensor is triggered again.  // 检测到耗材插入后自动继续
  //#define PAUSE_REHEAT_FAST_RESUME              // Reduce number of waits by not prompting again post-timeout before continuing.  // 重升温后快速恢复，不重复提示

  //#define PARK_HEAD_ON_PAUSE                    // Park the nozzle during pause and filament change.                              // 暂停/换料时喷头自动停靠到安全位置
  //#define HOME_BEFORE_FILAMENT_CHANGE           // If needed, home before parking for filament change                             // 换料前如果未归原点，自动归位

  //#define FILAMENT_LOAD_UNLOAD_GCODES           // Add M701/M702 Load/Unload G-codes, plus Load/Unload in the LCD Prepare menu.    // 添加 M701 进料 / M702 退料 指令
  //#define FILAMENT_UNLOAD_ALL_EXTRUDERS         // Allow M702 to unload all extruders above a minimum target temp (as set by M302) // M702 可退掉所有挤出机耗材
  #define CONFIGURE_FILAMENT_CHANGE               // Add M603 G-code and menu items. Requires ~1.3K bytes of flash.                  // 添加 M603 配置指令与菜单（占用闪存）
#endif


//========================================= TMC 静音驱动 ==========================================
// @section tmc_smart

/**
 * Trinamic Smart Drivers
 *
 * To use TMC2130, TMC2160, TMC2240, TMC2660, TMC5130, TMC5160 stepper drivers in SPI mode:
 *  - Connect your SPI pins to the Hardware SPI interface on the board.
 *    Some boards have simple jumper connections! See your board's documentation.
 *  - Define the required Stepper CS pins in your `pins_MYBOARD.h` file.
 *    (See the RAMPS pins, for example.)
 *  - You can also use Software SPI with GPIO pins instead of Hardware SPI.
 *
 * To use TMC220x stepper drivers with Serial UART:
 *  - Connect PDN_UART to the #_SERIAL_TX_PIN through a 1K resistor.
 *    For reading capabilities also connect PDN_UART to #_SERIAL_RX_PIN with no resistor.
 *    Some boards have simple jumper connections! See your board's documentation.
 *  - These drivers can also be used with Hardware Serial.
 *
 * The TMCStepper library is required for other TMC stepper drivers.
 *   https://github.com/teemuatlut/TMCStepper
 *
 * @section tmc/config
 * 
 * Trinamic 智能驱动
 *
 * 使用 SPI 模式的 TMC2130、TMC2160、TMC2240、TMC2660、TMC5130、TMC5160 驱动时：
 *  - 将 SPI 引脚连接到主板的硬件 SPI 接口。
 *    部分主板只需简单跳线即可！详见主板说明书。
 *  - 在你的 `pins_你的主板.h` 文件中定义所需的步进电机 CS 引脚。
 *    （例如参考 RAMPS 主板的引脚定义）
 *  - 也可以使用 GPIO 引脚实现软件 SPI，替代硬件 SPI。
 *
 * 使用串口 UART 模式的 TMC220x 系列驱动（TMC2208/2209）时：
 *  - 通过 1K 电阻将 PDN_UART 引脚连接到 #_SERIAL_TX_PIN 发送引脚。
 *    如需读取驱动数据，还需将 PDN_UART 直接连接到 #_SERIAL_RX_PIN 接收引脚（无电阻）。
 *    部分主板只需简单跳线即可！详见主板说明书。
 *  - 这类驱动也可以使用硬件串口。
 *
 * 使用所有 TMC 系列步进驱动，都需要安装 TMCStepper 库。
 *   https://github.com/teemuatlut/TMCStepper
 */
#if HAS_TRINAMIC_CONFIG

  #define HOLD_MULTIPLIER    0.5  // Scales down the holding current from run current       // 将待机保持电流 从 运行电流 按比例缩小

  //#define EDITABLE_HOMING_CURRENT   // Add a G-code and menu to modify the Homing Current // 添加 G 代码和屏幕菜单，用于修改 回零电流（寻原点电流）

  /**
   * Interpolate microsteps to 256
   * Override for each driver with <driver>_INTERPOLATE settings below
   * 
   * 微步细分插值到 256 细分
   * 可通过下方的 <driver>_INTERPOLATE 设置为每个驱动单独覆盖此功能
   */
  #define INTERPOLATE      true

  #if HAS_DRIVER(TMC2240)
    #define TMC2240_RREF        12000   // (Ω) 12000 .. 60000. (FLY TMC2240 = 12300)  // (欧姆) 取值范围 12000 ~ 60000。(FLY 主板使用 TMC2240 驱动 = 12300)
    // Max Current. Lower for more internal resolution. Raise to run cooler.          // 最大电流设置。数值越低 → 内部分辨率越高  数值越高 → 驱动运行温度越低（更凉快）

    #define TMC2240_CURRENT_RANGE   1   // :{ 0:'RMS=690mA PEAK=1A', 1:'RMS=1410mA PEAK=2A', 2:'RMS=2120mA PEAK=3A', 3:'RMS=2110mA PEAK=3A' }
// 可选档位对照表：
// 0: 有效值电流 690mA / 峰值电流 1A
// 1: 有效值电流 1410mA / 峰值电流 2A
// 2: 有效值电流 2120mA / 峰值电流 3A
// 3: 有效值电流 2110mA / 峰值电流 3A


    // Slope Control: Lower is more silent. Higher runs cooler.                                         // 斜率控制：数值越低越静音，数值越高散热越好（运行更凉）
    #define TMC2240_SLOPE_CONTROL   0   // :{ 0:'100V/µs', 1:'200V/µs', 2:'400V/µs', 3:'800V/µs' }
// 可选档位：
// 0: 100V/µs（最静音）
// 1: 200V/µs
// 2: 400V/µs
// 3: 800V/µs（发热最低、声音最大）
  #endif

  #if AXIS_IS_TMC_CONFIG(X)
    #define X_CURRENT       800        // (mA) RMS current. Multiply by 1.414 for peak current.            // (毫安) 有效值电流 (RMS)。乘以 1.414 即可得到峰值电流 (Peak Current)。
    #define X_CURRENT_HOME  X_CURRENT  // (mA) RMS current for homing. (Typically lower than *_CURRENT.)   // (毫安) 回零（寻原点）时使用的有效值电流（RMS）。通常设置为 **低于** 正常运行电流 (*_CURRENT)。
    #define X_MICROSTEPS     16        // 0..256
    #define X_RSENSE          0.11
    #define X_CHAIN_POS      -1        // -1..0: Not chained. 1: MCU MOSI connected. 2: Next in chain, ...// -1 ~ 0：不串联（独立驱动） 1：连接到主控 MCU 的 MOSI 引脚； 2：串联链中的下一个驱动...
    //#define X_INTERPOLATE  true      // Enable to override 'INTERPOLATE' for the X axis                 // 启用此项以单独覆盖 X 轴的微步插值（INTERPOLATE）设置
    //#define X_HOLD_MULTIPLIER 0.5    // Enable to override 'HOLD_MULTIPLIER' for the X axis             // 启用此项以单独覆盖 X 轴的待机电流比例（HOLD_MULTIPLIER）设置
  #endif


  //（译者注）：
  // 这是所有轴（X/Y/Z/E）的电流、细分、插值配置
  // 注释同上。
  #if AXIS_IS_TMC_CONFIG(X2)
    #define X2_CURRENT      X_CURRENT
    #define X2_CURRENT_HOME X_CURRENT_HOME
    #define X2_MICROSTEPS   X_MICROSTEPS
    #define X2_RSENSE       X_RSENSE
    #define X2_CHAIN_POS     -1
    //#define X2_INTERPOLATE true
    //#define X2_HOLD_MULTIPLIER 0.5
  #endif

  #if AXIS_IS_TMC_CONFIG(Y)
    #define Y_CURRENT       800
    #define Y_CURRENT_HOME  Y_CURRENT
    #define Y_MICROSTEPS     16
    #define Y_RSENSE          0.11
    #define Y_CHAIN_POS      -1
    //#define Y_INTERPOLATE  true
    //#define Y_HOLD_MULTIPLIER 0.5
  #endif

  #if AXIS_IS_TMC_CONFIG(Y2)
    #define Y2_CURRENT      Y_CURRENT
    #define Y2_CURRENT_HOME Y_CURRENT_HOME
    #define Y2_MICROSTEPS   Y_MICROSTEPS
    #define Y2_RSENSE       Y_RSENSE
    #define Y2_CHAIN_POS     -1
    //#define Y2_INTERPOLATE true
    //#define Y2_HOLD_MULTIPLIER 0.5
  #endif

  #if AXIS_IS_TMC_CONFIG(Z)
    #define Z_CURRENT       800
    #define Z_CURRENT_HOME  Z_CURRENT
    #define Z_MICROSTEPS     16
    #define Z_RSENSE          0.11
    #define Z_CHAIN_POS      -1
    //#define Z_INTERPOLATE  true
    //#define Z_HOLD_MULTIPLIER 0.5
  #endif

  #if AXIS_IS_TMC_CONFIG(Z2)
    #define Z2_CURRENT      Z_CURRENT
    #define Z2_CURRENT_HOME Z_CURRENT_HOME
    #define Z2_MICROSTEPS   Z_MICROSTEPS
    #define Z2_RSENSE       Z_RSENSE
    #define Z2_CHAIN_POS     -1
    //#define Z2_INTERPOLATE true
    //#define Z2_HOLD_MULTIPLIER 0.5
  #endif

  #if AXIS_IS_TMC_CONFIG(Z3)
    #define Z3_CURRENT      Z_CURRENT
    #define Z3_CURRENT_HOME Z_CURRENT_HOME
    #define Z3_MICROSTEPS   Z_MICROSTEPS
    #define Z3_RSENSE       Z_RSENSE
    #define Z3_CHAIN_POS     -1
    //#define Z3_INTERPOLATE true
    //#define Z3_HOLD_MULTIPLIER 0.5
  #endif

  #if AXIS_IS_TMC_CONFIG(Z4)
    #define Z4_CURRENT      Z_CURRENT
    #define Z4_CURRENT_HOME Z_CURRENT_HOME
    #define Z4_MICROSTEPS   Z_MICROSTEPS
    #define Z4_RSENSE       Z_RSENSE
    #define Z4_CHAIN_POS     -1
    //#define Z4_INTERPOLATE true
    //#define Z4_HOLD_MULTIPLIER 0.5
  #endif

  #if AXIS_IS_TMC_CONFIG(I)
    #define I_CURRENT      800
    #define I_CURRENT_HOME I_CURRENT
    #define I_MICROSTEPS    16
    #define I_RSENSE         0.11
    #define I_CHAIN_POS     -1
    //#define I_INTERPOLATE  true
    //#define I_HOLD_MULTIPLIER 0.5
  #endif

  #if AXIS_IS_TMC_CONFIG(J)
    #define J_CURRENT      800
    #define J_CURRENT_HOME J_CURRENT
    #define J_MICROSTEPS    16
    #define J_RSENSE         0.11
    #define J_CHAIN_POS     -1
    //#define J_INTERPOLATE  true
    //#define J_HOLD_MULTIPLIER 0.5
  #endif

  #if AXIS_IS_TMC_CONFIG(K)
    #define K_CURRENT      800
    #define K_CURRENT_HOME K_CURRENT
    #define K_MICROSTEPS    16
    #define K_RSENSE         0.11
    #define K_CHAIN_POS     -1
    //#define K_INTERPOLATE  true
    //#define K_HOLD_MULTIPLIER 0.5
  #endif

  #if AXIS_IS_TMC_CONFIG(U)
    #define U_CURRENT      800
    #define U_CURRENT_HOME U_CURRENT
    #define U_MICROSTEPS     8
    #define U_RSENSE         0.11
    #define U_CHAIN_POS     -1
    //#define U_INTERPOLATE  true
    //#define U_HOLD_MULTIPLIER 0.5
  #endif

  #if AXIS_IS_TMC_CONFIG(V)
    #define V_CURRENT      800
    #define V_CURRENT_HOME V_CURRENT
    #define V_MICROSTEPS     8
    #define V_RSENSE         0.11
    #define V_CHAIN_POS     -1
    //#define V_INTERPOLATE  true
    //#define V_HOLD_MULTIPLIER 0.5
  #endif

  #if AXIS_IS_TMC_CONFIG(W)
    #define W_CURRENT      800
    #define W_CURRENT_HOME W_CURRENT
    #define W_MICROSTEPS     8
    #define W_RSENSE         0.11
    #define W_CHAIN_POS     -1
    //#define W_INTERPOLATE  true
    //#define W_HOLD_MULTIPLIER 0.5
  #endif

  #if AXIS_IS_TMC_CONFIG(E0)
    #define E0_CURRENT      800
    #define E0_MICROSTEPS    16
    #define E0_RSENSE         0.11
    #define E0_CHAIN_POS     -1
    //#define E0_INTERPOLATE true
    //#define E0_HOLD_MULTIPLIER 0.5
  #endif

  #if AXIS_IS_TMC_CONFIG(E1)
    #define E1_CURRENT      E0_CURRENT
    #define E1_MICROSTEPS   E0_MICROSTEPS
    #define E1_RSENSE       E0_RSENSE
    #define E1_CHAIN_POS     -1
    //#define E1_INTERPOLATE true
    //#define E1_HOLD_MULTIPLIER 0.5
  #endif

  #if AXIS_IS_TMC_CONFIG(E2)
    #define E2_CURRENT      E0_CURRENT
    #define E2_MICROSTEPS   E0_MICROSTEPS
    #define E2_RSENSE       E0_RSENSE
    #define E2_CHAIN_POS     -1
    //#define E2_INTERPOLATE true
    //#define E2_HOLD_MULTIPLIER 0.5
  #endif

  #if AXIS_IS_TMC_CONFIG(E3)
    #define E3_CURRENT      E0_CURRENT
    #define E3_MICROSTEPS   E0_MICROSTEPS
    #define E3_RSENSE       E0_RSENSE
    #define E3_CHAIN_POS     -1
    //#define E3_INTERPOLATE true
    //#define E3_HOLD_MULTIPLIER 0.5
  #endif

  #if AXIS_IS_TMC_CONFIG(E4)
    #define E4_CURRENT      E0_CURRENT
    #define E4_MICROSTEPS   E0_MICROSTEPS
    #define E4_RSENSE       E0_RSENSE
    #define E4_CHAIN_POS     -1
    //#define E4_INTERPOLATE true
    //#define E4_HOLD_MULTIPLIER 0.5
  #endif

  #if AXIS_IS_TMC_CONFIG(E5)
    #define E5_CURRENT      E0_CURRENT
    #define E5_MICROSTEPS   E0_MICROSTEPS
    #define E5_RSENSE       E0_RSENSE
    #define E5_CHAIN_POS     -1
    //#define E5_INTERPOLATE true
    //#define E5_HOLD_MULTIPLIER 0.5
  #endif

  #if AXIS_IS_TMC_CONFIG(E6)
    #define E6_CURRENT      E0_CURRENT
    #define E6_MICROSTEPS   E0_MICROSTEPS
    #define E6_RSENSE       E0_RSENSE
    #define E6_CHAIN_POS     -1
    //#define E6_INTERPOLATE true
    //#define E6_HOLD_MULTIPLIER 0.5
  #endif

  #if AXIS_IS_TMC_CONFIG(E7)
    #define E7_CURRENT      E0_CURRENT
    #define E7_MICROSTEPS   E0_MICROSTEPS
    #define E7_RSENSE       E0_RSENSE
    #define E7_CHAIN_POS     -1
    //#define E7_INTERPOLATE true
    //#define E7_HOLD_MULTIPLIER 0.5
  #endif

  /**
   * Use the homing current for all probing. (e.g., Current may be reduced to the
   * point where a collision makes the motor skip instead of damaging the bed,
   * though this is unlikely to save delicate probes from being damaged.
   * 
   * 探测动作全部沿用回零档位电流
   * 适当降低电流，发生磕碰时电机易丢步打滑，可减少热床受损风险
   * 但无法避免精密探针硬件损坏
   */
  //#define PROBING_USE_CURRENT_HOME

  // @section tmc/spi

  /**
   * Override default SPI pins for TMC2130, TMC2160, TMC2240, TMC2660, TMC5130 and TMC5160 drivers here.
   * The default pins can be found in your board's pins file.
   * 
   * 在此处覆盖 TMC2130 / TMC2160 / TMC2240 / TMC2660 / TMC5130 / TMC5160 驱动的默认 SPI 引脚
   * 默认引脚定义可以在你主板的引脚文件（pins_xxx.h）中找到
   */

   //（译者注）：
   // 如果你用的是 TMC2208 / TMC2209（UART 模式），可以直接忽略这些了。
  //#define X_CS_PIN      -1
  //#define Y_CS_PIN      -1
  //#define Z_CS_PIN      -1
  //#define X2_CS_PIN     -1
  //#define Y2_CS_PIN     -1
  //#define Z2_CS_PIN     -1
  //#define Z3_CS_PIN     -1
  //#define Z4_CS_PIN     -1
  //#define I_CS_PIN      -1
  //#define J_CS_PIN      -1
  //#define K_CS_PIN      -1
  //#define U_CS_PIN      -1
  //#define V_CS_PIN      -1
  //#define W_CS_PIN      -1
  //#define E0_CS_PIN     -1
  //#define E1_CS_PIN     -1
  //#define E2_CS_PIN     -1
  //#define E3_CS_PIN     -1
  //#define E4_CS_PIN     -1
  //#define E5_CS_PIN     -1
  //#define E6_CS_PIN     -1
  //#define E7_CS_PIN     -1

  /**
   * Software option for SPI driven drivers (TMC2130, TMC2160, TMC2240, TMC2660, TMC5130 and TMC5160).
   * The default SW SPI pins are defined the respective pins files,
   * but you can override or define them here.
   * 针对 SPI 驱动（TMC2130、TMC2160、TMC2240、TMC2660、TMC5130、TMC5160）的软件SPI配置选项。
   * 默认的软件 SPI 引脚已在对应的主板引脚文件中定义，
   * 但你可以在这里覆盖或重新定义它们。
   */
  //#define TMC_USE_SW_SPI
  //#define TMC_SPI_MOSI  -1
  //#define TMC_SPI_MISO  -1
  //#define TMC_SPI_SCK   -1


  //================================== TMC 串口（UART）配置区域 =========================================
  // @section tmc/serial

  /**
   * Four TMC2209 drivers can use the same HW/SW serial port with hardware configured addresses.
   * Set the address using jumpers on pins MS1 and MS2.
   * 
   * 最多可将 4 个 TMC2209 驱动共用同一个硬件/软件串口，
   * 只需通过硬件配置不同的地址即可。
   * 使用驱动上的 MS1 和 MS2 引脚跳线来设置地址。
   * Address | MS1  | MS2
   *       0 | LOW  | LOW
   *       1 | HIGH | LOW
   *       2 | LOW  | HIGH
   *       3 | HIGH | HIGH
   *
   * Set *_SERIAL_TX_PIN and *_SERIAL_RX_PIN to match for all drivers
   * on the same serial port, either here or in your board's pins file.
   * 
   * 设置 *_SERIAL_TX_PIN 和 *_SERIAL_RX_PIN，
   * 让同一串口中的所有驱动都使用相同的 TX / RX 引脚。
   * 可以在这里设置，也可以在主板的引脚文件中设置。
   */
  //#define  X_SLAVE_ADDRESS 0
  //#define  Y_SLAVE_ADDRESS 0
  //#define  Z_SLAVE_ADDRESS 0
  //#define X2_SLAVE_ADDRESS 0
  //#define Y2_SLAVE_ADDRESS 0
  //#define Z2_SLAVE_ADDRESS 0
  //#define Z3_SLAVE_ADDRESS 0
  //#define Z4_SLAVE_ADDRESS 0
  //#define  I_SLAVE_ADDRESS 0
  //#define  J_SLAVE_ADDRESS 0
  //#define  K_SLAVE_ADDRESS 0
  //#define  U_SLAVE_ADDRESS 0
  //#define  V_SLAVE_ADDRESS 0
  //#define  W_SLAVE_ADDRESS 0
  //#define E0_SLAVE_ADDRESS 0
  //#define E1_SLAVE_ADDRESS 0
  //#define E2_SLAVE_ADDRESS 0
  //#define E3_SLAVE_ADDRESS 0
  //#define E4_SLAVE_ADDRESS 0
  //#define E5_SLAVE_ADDRESS 0
  //#define E6_SLAVE_ADDRESS 0
  //#define E7_SLAVE_ADDRESS 0

  // @section tmc/smart
  // TMC 智能功能配置区

  /**
   * Software enable
   *
   * Use for drivers that do not use a dedicated enable pin, but rather handle the same
   * function through a communication line such as SPI or UART.
   * 
   * 软件使能功能
   * 适用于没有专用使能引脚，而是通过 SPI 或 UART 这类通信线来实现相同（电机启停）功能的驱动模块。
   */
  //#define SOFTWARE_DRIVER_ENABLE

  // @section tmc/stealthchop
  //  TMC 静音驱动模式

  /**
   * TMC2130, TMC2160, TMC2208, TMC2209, TMC2240, TMC5130 and TMC5160 only
   * Use Trinamic's ultra quiet stepping mode.
   * When disabled, Marlin will use spreadCycle stepping mode.
   * 
   * 仅适用于 TMC2130、TMC2160、TMC2208、TMC2209、TMC2240、TMC5130、TMC5160 驱动
   * 启用 Trinamic 官方的超静音步进模式（StealthChop）。
   * 禁用时，Marlin 会使用 spreadCycle 步进模式（普通模式，声音更大、动力更强）。
   */
  #if HAS_STEALTHCHOP
    #define STEALTHCHOP_XY
    #define STEALTHCHOP_Z
    #define STEALTHCHOP_I
    #define STEALTHCHOP_J
    #define STEALTHCHOP_K
    #define STEALTHCHOP_U
    #define STEALTHCHOP_V
    #define STEALTHCHOP_W
    #define STEALTHCHOP_E
  #endif

  /**
   * Optimize spreadCycle chopper parameters by using predefined parameter sets
   * or with the help of an example included in the library.
   * Provided parameter sets are
   * CHOPPER_DEFAULT_12V
   * CHOPPER_DEFAULT_19V
   * CHOPPER_DEFAULT_24V
   * CHOPPER_DEFAULT_36V
   * CHOPPER_09STEP_24V   // 0.9 degree steppers (24V)
   * CHOPPER_PRUSAMK3_24V // Imported parameters from the official Průša firmware for MK3 (24V)
   * CHOPPER_MARLIN_119   // Old defaults from Marlin v1.1.9
   *
   * Define your own with:
   * { <off_time[1..15]>, <hysteresis_end[-3..12]>, hysteresis_start[1..8] }
   * 
   * 通过预定义参数组优化 spreadCycle 斩波参数
   * 或者使用库中提供的示例自行配置
   * 提供的参数组包括：
   * CHOPPER_DEFAULT_12V   12V 默认
   * CHOPPER_DEFAULT_19V   19V 默认
   * CHOPPER_DEFAULT_24V   24V 默认（最常用）
   * CHOPPER_DEFAULT_36V   36V 默认
   * CHOPPER_09STEP_24V    0.9度步进电机专用（24V）
   * CHOPPER_PRUSAMK3_24V  Prusa MK3 专用参数
   * CHOPPER_MARLIN_119    老版本Marlin默认参数
   * 
   * 自定义参数格式（极复杂，新手绝对不要碰）：
   * { <off_time[1..15]>, <hysteresis_end[-3..12]>, hysteresis_start[1..8] }
   */
  #define CHOPPER_TIMING CHOPPER_DEFAULT_12V        // All axes (override below)       // 所有轴统一设置（下方可单独覆盖）
  //#define CHOPPER_TIMING_X  CHOPPER_TIMING        // For X Axes (override below)     // 用于 X 轴（可在下方单独覆盖设置）
  //#define CHOPPER_TIMING_X2 CHOPPER_TIMING_X
  //#define CHOPPER_TIMING_Y  CHOPPER_TIMING        // For Y Axes (override below)     // 用于 Y 轴（可在下方单独覆盖设置）
  //#define CHOPPER_TIMING_Y2 CHOPPER_TIMING_Y
  //#define CHOPPER_TIMING_Z  CHOPPER_TIMING        // For Z Axes (override below)     // 用于 Z 轴（可在下方单独覆盖设置）
  //#define CHOPPER_TIMING_Z2 CHOPPER_TIMING_Z
  //#define CHOPPER_TIMING_Z3 CHOPPER_TIMING_Z
  //#define CHOPPER_TIMING_Z4 CHOPPER_TIMING_Z
  //#define CHOPPER_TIMING_I  CHOPPER_TIMING        // For I Axis
  //#define CHOPPER_TIMING_J  CHOPPER_TIMING        // For J Axis
  //#define CHOPPER_TIMING_K  CHOPPER_TIMING        // For K Axis
  //#define CHOPPER_TIMING_U  CHOPPER_TIMING        // For U Axis
  //#define CHOPPER_TIMING_V  CHOPPER_TIMING        // For V Axis
  //#define CHOPPER_TIMING_W  CHOPPER_TIMING        // For W Axis
  //#define CHOPPER_TIMING_E  CHOPPER_TIMING        // For Extruders (override below)  // 用于挤出机（可在下方单独覆盖设置）
  //#define CHOPPER_TIMING_E1 CHOPPER_TIMING_E
  //#define CHOPPER_TIMING_E2 CHOPPER_TIMING_E
  //#define CHOPPER_TIMING_E3 CHOPPER_TIMING_E
  //#define CHOPPER_TIMING_E4 CHOPPER_TIMING_E
  //#define CHOPPER_TIMING_E5 CHOPPER_TIMING_E
  //#define CHOPPER_TIMING_E6 CHOPPER_TIMING_E
  //#define CHOPPER_TIMING_E7 CHOPPER_TIMING_E

  // @section tmc/status
  // TMC 驱动状态监控

  /**
   * Monitor Trinamic drivers
   * for error conditions like overtemperature and short to ground.
   * To manage over-temp Marlin can decrease the driver current until the error condition clears.
   * Other detected conditions can be used to stop the current print.
   * Relevant G-codes:
   * M906 - Set or get motor current in milliamps using axis codes X, Y, Z, E. Report values if no axis codes given.
   * M911 - Report stepper driver overtemperature pre-warn condition.
   * M912 - Clear stepper driver overtemperature pre-warn condition flag.
   * M122 - Report driver parameters (Requires TMC_DEBUG)
   * 
   * 监控 Trinamic（TMC）驱动状态
   * 检测诸如过热、对地短路等故障。
   * 当检测到过热时，Marlin 会自动降低电机电流，直到故障解除。
   * 其他检测到的故障会触发停止当前打印的保护机制。
   * 相关G代码指令：
   * M906 - 设置或读取电机电流（单位：毫安），使用 X/Y/Z/E 指定轴，无参数则报告所有轴电流。
   * M911 - 报告驱动是否处于过热预警状态。
   * M912 - 清除驱动过热预警标志。
   * M122 - 报告驱动详细参数（需要开启 TMC_DEBUG 调试模式）。
   */
  //#define MONITOR_DRIVER_STATUS

  #if ENABLED(MONITOR_DRIVER_STATUS)
    #define CURRENT_STEP_DOWN     50  // [mA]
    #define REPORT_CURRENT_CHANGE
    #define STOP_ON_ERROR
  #endif

  // @section tmc/hybrid
  // TMC 混合模式配置

  /**
   * TMC2130, TMC2160, TMC2208, TMC2209, TMC2240, TMC5130 and TMC5160 only
   * The driver will switch to spreadCycle when stepper speed is over HYBRID_THRESHOLD.
   * This mode allows for faster movements at the expense of higher noise levels.
   * STEALTHCHOP_(XY|Z|E) must be enabled to use HYBRID_THRESHOLD.
   * M913 X/Y/Z/E to live tune the setting
   * 
   * 仅适用于 TMC2130、TMC2160、TMC2208、TMC2209、TMC2240、TMC5130、TMC5160 驱动
   * 当步进电机速度超过 HYBRID_THRESHOLD（混合阈值）时，驱动会自动切换到 spreadCycle 模式。
   * 此模式支持更快的运动速度，但代价是噪音会变大。
   * 必须启用 STEALTHCHOP_(XY|Z|E)（静音模式）才能使用混合阈值功能。
   * 可使用 M913 X/Y/Z/E 指令实时调参。
   */
  //#define HYBRID_THRESHOLD

  #define X_HYBRID_THRESHOLD     100  // [mm/s]
  #define X2_HYBRID_THRESHOLD    100
  #define Y_HYBRID_THRESHOLD     100
  #define Y2_HYBRID_THRESHOLD    100
  #define Z_HYBRID_THRESHOLD       3
  #define Z2_HYBRID_THRESHOLD      3
  #define Z3_HYBRID_THRESHOLD      3
  #define Z4_HYBRID_THRESHOLD      3
  #define I_HYBRID_THRESHOLD       3  // [linear=mm/s, rotational=°/s]  //直线轴（X、Y、Z）的单位是：毫米 / 秒，旋转轴 / 挤出机的单位是：度 / 秒
  #define J_HYBRID_THRESHOLD       3  // [linear=mm/s, rotational=°/s]  //直线轴（X、Y、Z）的单位是：毫米 / 秒，旋转轴 / 挤出机的单位是：度 / 秒
  #define K_HYBRID_THRESHOLD       3  // [linear=mm/s, rotational=°/s]  //直线轴（X、Y、Z）的单位是：毫米 / 秒，旋转轴 / 挤出机的单位是：度 / 秒
  #define U_HYBRID_THRESHOLD       3  // [mm/s]
  #define V_HYBRID_THRESHOLD       3
  #define W_HYBRID_THRESHOLD       3
  #define E0_HYBRID_THRESHOLD     30
  #define E1_HYBRID_THRESHOLD     30
  #define E2_HYBRID_THRESHOLD     30
  #define E3_HYBRID_THRESHOLD     30
  #define E4_HYBRID_THRESHOLD     30
  #define E5_HYBRID_THRESHOLD     30
  #define E6_HYBRID_THRESHOLD     30
  #define E7_HYBRID_THRESHOLD     30

  /**
   * Use StallGuard to home / probe X, Y, Z.
   *
   * TMC2130, TMC2160, TMC2209, TMC2240, TMC2660, TMC5130, and TMC5160 only
   * Connect the stepper driver's DIAG1 pin to the X/Y endstop pin.
   * X, Y, and Z homing will always be done in spreadCycle mode.
   *
   * X/Y/Z_STALL_SENSITIVITY is the default stall threshold.
   * Use M914 X Y Z to set the stall threshold at runtime:
   *
   *  Sensitivity  TMC2209        Others
   *    HIGHEST        255         -64    (Too sensitive => False positive)
   *    LOWEST          0           63    (Too insensitive => No trigger)
   *
   * It is recommended to set HOMING_BUMP_MM to { 0, 0, 0 }.
   *
   * SPI_ENDSTOPS  *** TMC2130, TMC2240, and TMC5160 Only ***
   * Poll the driver through SPI to determine load when homing.
   * Removes the need for a wire from DIAG1 to an endstop pin.
   *
   * IMPROVE_HOMING_RELIABILITY tunes acceleration and jerk when
   * homing and adds a guard period for endstop triggering.
   *
   * Comment *_STALL_SENSITIVITY to disable sensorless homing for that axis.
   * @section tmc/stallguard
   * 
   * 使用 StallGuard （无传感器归位）功能 进行 X、Y、Z 轴的回零 / 探点
   *
   * 仅支持 TMC2130, TMC2160, TMC2209, TMC2240, TMC2660, TMC5130, TMC5160
   * 需要将驱动的 DIAG1 引脚连接到 X/Y 限位开关引脚
   * X、Y、Z 轴回零时，会强制使用 spreadCycle 模式（声音变大）
   *
   * X/Y/Z_STALL_SENSITIVITY 是堵转检测灵敏度
   * 使用 M914 X Y Z 指令在运行时设置灵敏度：
   *
   *  灵敏度      TMC2209      其他驱动
   *    最高        255         -64    (太灵敏 => 容易误触发)
   *    最低         0           63    (太迟钝 => 无法触发)
   *
   * 推荐将 HOMING_BUMP_MM 设置为 { 0, 0, 0 }
   *
   * SPI_ENDSTOPS  *** 仅 TMC2130 / TMC2240 / TMC5160 支持 ***
   * 通过 SPI 轮询驱动负载，无需 DIAG1 接线
   *
   * IMPROVE_HOMING_RELIABILITY 优化回零参数，提高可靠性
   *
   * 注释掉对应轴的 *_STALL_SENSITIVITY 即可关闭该轴无传感器归位
   */
  //#define SENSORLESS_HOMING // StallGuard capable drivers only   // 仅适用于支持 StallGuard (无传感器归位）功能的驱动

  #if ANY(SENSORLESS_HOMING, SENSORLESS_PROBING)
    // TMC2209: 0...255. TMC2130: -64...63
    #define X_STALL_SENSITIVITY  8
    #define X2_STALL_SENSITIVITY X_STALL_SENSITIVITY
    #define Y_STALL_SENSITIVITY  8
    #define Y2_STALL_SENSITIVITY Y_STALL_SENSITIVITY
    //#define Z_STALL_SENSITIVITY  8
    //#define Z2_STALL_SENSITIVITY Z_STALL_SENSITIVITY
    //#define Z3_STALL_SENSITIVITY Z_STALL_SENSITIVITY
    //#define Z4_STALL_SENSITIVITY Z_STALL_SENSITIVITY
    //#define I_STALL_SENSITIVITY  8
    //#define J_STALL_SENSITIVITY  8
    //#define K_STALL_SENSITIVITY  8
    //#define U_STALL_SENSITIVITY  8
    //#define V_STALL_SENSITIVITY  8
    //#define W_STALL_SENSITIVITY  8
    //#define SPI_ENDSTOPS              // TMC2130, TMC2240, and TMC5160
    //#define IMPROVE_HOMING_RELIABILITY
  #endif

  // @section tmc/config

  /**
   * TMC Homing stepper phase.
   *
   * Improve homing repeatability by homing to stepper coil's nearest absolute
   * phase position. Trinamic drivers use a stepper phase table with 1024 values
   * spanning 4 full steps with 256 positions each (ergo, 1024 positions).
   * Full step positions (128, 384, 640, 896) have the highest holding torque.
   *
   * Values from 0..1023, -1 to disable homing phase for that axis.
   * 
   * TMC 回零步进电机相位
   *
   * 通过回零到步进电机线圈最近的绝对相位位置，
   * 提高回零的重复精度。
   * Trinamic 驱动使用包含 1024 个值的步进相位表，
   * 覆盖 4 个完整步进，每个步进 256 个位置（总共 1024 个位置）。
   * 整步位置（128, 384, 640, 896）具有最大的保持扭矩。
   *
   * 取值范围 0..1023，设置为 -1 则关闭该轴的回零相位功能。
   */
   //#define TMC_HOME_PHASE { 896, 896, 896 }

  /**
   * Step on both rising and falling edge signals (as with a square wave).  // 在信号的上升沿和下降沿都执行步进（如同方波信号）
   */
  #define EDGE_STEPPING

  /**
   * Enable M122 debugging command for TMC stepper drivers.
   * M122 S0/1 will enable continuous reporting.
   * 启用 TMC 步进驱动的 M122 调试命令。
   * M122 S0/1 用于开启/关闭持续状态上报。
   */
  //#define TMC_DEBUG

  /**
   * You can set your own advanced settings by filling in predefined functions.
   * A list of available functions can be found on the library github page
   * https://github.com/teemuatlut/TMCStepper
   *
   * Example:
   * #define TMC_ADV() { \
   *   stepperX.diag0_otpw(1); \
   *   stepperY.intpol(0); \
   * 
   * 你可以通过填写预定义函数来自定义高级设置。
   * 可用函数列表请查看库的 GitHub 页面：
   * https://github.com/teemuatlut/TMCStepper
   *
   * 示例：
   * #define TMC_ADV() { \
   *   stepperX.diag0_otpw(1); \
   *   stepperY.intpol(0); \
 
   * }
   */
  #define TMC_ADV() {  }

#endif // HAS_TRINAMIC_CONFIG

// @section i2cbus
// I2C 总线相关设置

//
// I2C Master ID for LPC176x LCD and Digital Current control
// Does not apply to other peripherals based on the Wire library.
// LPC176x 主控芯片的显示屏与数字电流控制所用的 I2C 主机 ID
// 不适用于其他基于 Wire 库的外设
//
//#define I2C_MASTER_ID  1  // Set a value from 0 to 2  // 设置一个 0 到 2 之间的数值

/**
 * TWI/I2C BUS
 *
 * This feature is EXPERIMENTAL but may be useful for custom I2C peripherals.
 * Enable this to send and receive I2C data from slave devices on the bus.
 *
 * ; Example #1
 * ; This macro send the string "Marlin" to the slave device with address 0x63 (99)
 * ; It uses multiple M260 commands with one B<base 10> arg
 * M260 A99  ; Target slave address
 * M260 B77  ; M
 * M260 B97  ; a
 * M260 B114 ; r
 * M260 B108 ; l
 * M260 B105 ; i
 * M260 B110 ; n
 * M260 S1   ; Send the current buffer
 *
 * ; Example #2
 * ; Request 6 bytes from slave device with address 0x63 (99)
 * M261 A99 B5
 *
 * ; Example #3
 * ; Example serial output of a M261 request
 * echo:i2c-reply: from:99 bytes:5 data:hello
 * 
 * 
 * TWI/I2C 总线
 * 该功能尚处于测试阶段，可适配自定义 I2C 外接设备。
 * 开启后能够与总线中的从设备收发 I2C 数据。
 * 示例 1
 * 该指令向地址为 0x63（十进制 99）的从设备发送字符串 Marlin
 * 通过多条带十进制参数的 M260 指令组合实现
 * M260 A99 ; 指定目标设备地址
 * M260 B77 ; 字符 M
 * M260 B97 ; 字符 a
 * M260 B114 ; 字符 r
 * M260 B108 ; 字符 l
 * M260 B105 ; 字符 i
 * M260 B110 ; 字符 n
 * M260 S1 ; 发送缓存内数据
 * 示例 2
 * 向地址 99 的从设备请求读取 6 字节数据
 * M261 A99 B5
 * 示例 3
 * 读取指令的串口返回示例
 * 回显：I2C 应答，来源地址 99，数据长度 5，内容 hello
 */

//#define EXPERIMENTAL_I2CBUS
#if ENABLED(EXPERIMENTAL_I2CBUS)
  #define I2C_SLAVE_ADDRESS  0  // Set a value from 8 to 127 to act as a slave  // 设置一个 8 到 127 之间的数值，用作从机地址
#endif

// @section photo
// 拍照功能配置区

/**
 * Photo G-code
 * Add the M240 G-code to take a photo.
 * The photo can be triggered by a digital pin or a physical movement.
 * 拍照 G 代码
 * 添加 M240 G 代码用于触发拍照。
 * 可通过数字引脚信号或机械运动来触发拍照动作。
 */
//#define PHOTO_GCODE
#if ENABLED(PHOTO_GCODE)
  // A position to move to (and raise Z) before taking the photo  // 拍照前移动到的目标位置（并抬升 Z 轴）
  //#define PHOTO_POSITION { X_MAX_POS - 5, Y_MAX_POS, 0 }  // { xpos, ypos, zraise } (M240 X Y Z)                  // {X 坐标，Y 坐标，Z 抬升高度} (M240 X Y Z)
  //#define PHOTO_DELAY_MS   100                            // (ms) Duration to pause before moving back (M240 P)   // （毫秒）移动回原位前的暂停时长（M240 P）
  //#define PHOTO_RETRACT_MM   6.5                          // (mm) E retract/recover for the photo move (M240 R S) // （毫米）拍照移动时的挤出机回抽/回抽恢复量（M240 R S）

  // Canon RC-1 or homebrew digital camera trigger          // 佳能 RC‑1 或自制数码相机触发器
  // Data from: https://www.doc-diy.net/photo/rc-1_hacked/
  //#define PHOTOGRAPH_PIN 23

  // Canon Hack Development Kit   // 佳能固件开发工具包（CHDK）
  // https://web.archive.org/web/20200920094805/captain-slow.dk/2014/03/09/3d-printing-timelapses/
  //#define CHDK_PIN        4

  // Optional second move with delay to trigger the camera shutter    // 可选的第二次移动，并配合延时触发相机快门
  //#define PHOTO_SWITCH_POSITION { X_MAX_POS, Y_MAX_POS }  // { xpos, ypos } (M240 I J)

  // Duration to hold the switch or keep CHDK_PIN high   // 保持开关闭合或保持 CHDK_PIN 引脚为高电平的持续时间
  //#define PHOTO_SWITCH_MS   50 // (ms) (M240 D)

  /**
   * PHOTO_PULSES_US may need adjustment depending on board and camera model.
   * Pin must be running at 48.4kHz.
   * Be sure to use a PHOTOGRAPH_PIN which can rise and fall quick enough.
   * (e.g., MKS SBase temp sensor pin was too slow, so used P1.23 on J8.)
   *
   *  Example pulse data for Nikon: https://bit.ly/2FKD0Aq
   *                     IR Wiring: https://git.io/JvJf7
   * 
   * 拍照脉冲时长需根据主板与相机型号微调
   * 引脚工作频率必须为48.4千赫兹
   * 选用升降速足够快的拍照触发引脚
   * 例：MKS SBase温度传感器引脚响应迟缓，改用J8接口的P1.23引脚
   */
  //#define PHOTO_PULSES_US { 2000, 27850, 400, 1580, 400, 3580, 400 }  // (µs) Durations for each 48.4kHz oscillation  // （微秒）每个 48.4kHz 振荡周期的持续时间
  #ifdef PHOTO_PULSES_US
    #define PHOTO_PULSE_DELAY_US 13 // (µs) Approximate duration of each HIGH and LOW pulse in the oscillation          // （微秒）振荡中每个高电平、低电平脉冲的大致持续时长
  #endif
#endif

// @section cnc
// CNC 功能配置区

/**
 * Spindle & Laser control
 *
 * Add the M3, M4, and M5 commands to turn the spindle/laser on and off, and
 * to set spindle speed, spindle direction, and laser power.
 *
 * SuperPID is a router/spindle speed controller used in the CNC milling community.
 * Marlin can be used to turn the spindle on and off. It can also be used to set
 * the spindle speed from 5,000 to 30,000 RPM.
 *
 * You'll need to select a pin for the ON/OFF function and optionally choose a 0-5V
 * hardware PWM pin for the speed control and a pin for the rotation direction.
 *
 * See https://marlinfw.org/docs/configuration/2.0.9/laser_spindle.html for more config details.
 * 
 * 主轴与激光控制
 *
 * 添加 M3、M4、M5 指令，用于控制主轴/激光的开启与关闭，并
 * 设置主轴转速、主轴旋转方向以及激光功率。
 *
 * SuperPID 是 CNC 数控铣削领域常用的路由器/主轴转速控制器。
 * Marlin 固件可控制主轴启停，也能设置
 * 5000 至 30000 转/分钟的主轴转速。
 *
 * 你需要为启停功能指定一个引脚，还可额外选择一个 0-5V
 * 硬件 PWM 引脚用于转速控制，以及一个引脚用于旋转方向控制。
 */
//#define SPINDLE_FEATURE
//#define LASER_FEATURE
#if ANY(SPINDLE_FEATURE, LASER_FEATURE)
  #define SPINDLE_LASER_ACTIVE_STATE    LOW    // Set to "HIGH" if SPINDLE_LASER_ENA_PIN is active HIGH                            // 若主轴/激光使能引脚为高电平有效，请设置为 "HIGH"

  #define SPINDLE_LASER_USE_PWM                // Enable if your controller supports setting the speed/power                       // 若控制器支持调节转速/功率，则启用此选项
  #if ENABLED(SPINDLE_LASER_USE_PWM)
    #define SPINDLE_LASER_PWM_INVERT    false  // Set to "true" if the speed/power goes up when you want it to go slower           // 若实际转速/功率与设置方向相反（想减速却变快），请设为 "true"
    #define SPINDLE_LASER_FREQUENCY     2500   // (Hz) Spindle/laser frequency (only on supported HALs: AVR, ESP32, and LPC)
                                               // ESP32: If SPINDLE_LASER_PWM_PIN is onboard then <=78125Hz. For I2S expander
                                               //  the frequency determines the PWM resolution. 2500Hz = 0-100, 977Hz = 0-255, ...
                                               //  (250000 / SPINDLE_LASER_FREQUENCY) = max value.
                                               //（赫兹）主轴/激光频率（仅支持以下硬件抽象层：AVR、ESP32 和 LPC）
                                               // ESP32 说明：若主轴/激光 PWM 引脚为板载引脚，频率需 ≤78125Hz。
                                               // 若是 I2S 扩展引脚，频率决定 PWM 分辨率：
                                               // 2500Hz = 0-100 档位，977Hz = 0-255 档位……
                                               // 计算公式：(250000 / 主轴/激光频率) = 最大档位值
  #endif

  //#define AIR_EVACUATION                     // Cutter Vacuum / Laser Blower motor control with G-codes M10-M11 // 通过 G 代码 M10-M11 控制切割吸尘器 / 激光鼓风机电机
  #if ENABLED(AIR_EVACUATION)
    #define AIR_EVACUATION_ACTIVE       LOW    // Set to "HIGH" if the on/off function is active HIGH             // 若启停功能为**高电平有效**，请设置为 "HIGH"
    //#define AIR_EVACUATION_PIN        42     // Override the default Cutter Vacuum or Laser Blower pin          // 覆盖默认的切割吸尘器 / 激光鼓风机引脚
  #endif

  //#define AIR_ASSIST                         // Air Assist control with G-codes M8-M9                           // 通过 G 代码 M8-M9 控制空气辅助吹气装置
  #if ENABLED(AIR_ASSIST)
    #define AIR_ASSIST_ACTIVE           LOW    // Active state on air assist pin                                  // 空气辅助引脚的有效电平状态
    //#define AIR_ASSIST_PIN            44     // Override the default Air Assist pin                             // 自定义空气辅助引脚，覆盖默认引脚配置
  #endif

  //#define SPINDLE_SERVO                      // A servo converting an angle to spindle power                    // 舵机角度映射为主轴功率
  #ifdef SPINDLE_SERVO
    #define SPINDLE_SERVO_NR   0               // Index of servo used for spindle control                         // 用于控制主轴的舵机序号
    #define SPINDLE_SERVO_MIN 10               // Minimum angle for servo spindle                                 // 主轴控制舵机的最小角度
  #endif

  /**
   * Speed / Power can be set ('M3 S') and displayed in terms of:
   *  - PWM255  (S0 - S255)
   *  - PERCENT (S0 - S100)
   *  - RPM     (S0 - S50000)  Best for use with a spindle
   *  - SERVO   (S0 - S180)
   * 
   * 转速 / 功率可通过 M3 S 指令设置，并支持以下单位显示：
   * PWM255 （数值范围 S0 ~ S255）
   * 百分比（S0 ~ S100）
   * 转速 （S0 ~ S50000 转 / 分钟）最适合主轴使用
   * 舵机角度（S0 ~ S180 度）
   */
  #define CUTTER_POWER_UNIT PWM255

  /**
   * Relative Cutter Power
   * Normally, 'M3 O<power>' sets
   * OCR power is relative to the range SPEED_POWER_MIN...SPEED_POWER_MAX.
   * so input powers of 0...255 correspond to SPEED_POWER_MIN...SPEED_POWER_MAX
   * instead of normal range (0 to SPEED_POWER_MAX).
   * Best used with (e.g.) SuperPID router controller: S0 = 5,000 RPM and S255 = 30,000 RPM
   * 
   * 相对切割功率
   * 通常情况下，使用 'M3 O <功率>' 指令进行设置
   * O 参数对应的功率是基于 SPEED_POWER_MIN（最小功率）~ SPEED_POWER_MAX（最大功率） 范围的相对值
   * 因此输入功率 0~255 会直接映射为 SPEED_POWER_MIN ~ SPEED_POWER_MAX
   * 而非常规的 0 ~ SPEED_POWER_MAX 范围
   * 最适合搭配 SuperPID 主轴控制器使用：
   * 例如 S0 = 5000 转 / 分钟，S255 = 30000 转 / 分钟
   *
   */
  //#define CUTTER_POWER_RELATIVE              // Set speed proportional to [SPEED_POWER_MIN...SPEED_POWER_MAX]    // 将转速按比例映射到 [最小转速/功率 ... 最大转速/功率] 区间

  #if ENABLED(SPINDLE_FEATURE)
    //#define SPINDLE_CHANGE_DIR               // Enable if your spindle controller can change spindle direction   // 若你的主轴控制器支持切换主轴旋转方向，则启用此项
    #define SPINDLE_CHANGE_DIR_STOP            // Enable if the spindle should stop before changing spin direction // 若主轴在切换旋转方向前需要先停止运转，则启用此项
    #define SPINDLE_INVERT_DIR          false  // Set to "true" if the spin direction is reversed                  // 若主轴旋转方向与预期相反，请设为 "true"（反转方向）

    #define SPINDLE_LASER_POWERUP_DELAY   5000 // (ms) Delay to allow the spindle/laser to come up to speed/power  //（毫秒）主轴/激光达到设定转速/功率所需的延迟时间
    #define SPINDLE_LASER_POWERDOWN_DELAY 5000 // (ms) Delay to allow the spindle to stop                          //（毫秒）主轴完全停止所需的延迟时间

    /**
     * M3/M4 Power Equation
     *
     * Each tool uses different value ranges for speed / power control.
     * These parameters are used to convert between tool power units and PWM.
     *
     * Speed/Power = (PWMDC / 255 * 100 - SPEED_POWER_INTERCEPT) / SPEED_POWER_SLOPE
     * PWMDC = (spdpwr - SPEED_POWER_MIN) / (SPEED_POWER_MAX - SPEED_POWER_MIN) / SPEED_POWER_SLOPE
     * 
     * M3/M4 功率计算公式
     *
     * 不同设备（主轴/激光）的转速/功率控制范围不同，
     * 这些参数用于在设备功率单位与 PWM 信号之间进行换算。
     *
     * 转速/功率 = (PWM占空比 / 255 * 100 - 功率截距) / 功率斜率
     * PWM占空比 = (设定转速/功率 - 最小转速/功率) / (最大转速/功率 - 最小转速/功率) / 功率斜率
     */
    #if ENABLED(SPINDLE_LASER_USE_PWM)
      #define SPEED_POWER_INTERCEPT       0    // (%) 0-100 i.e., Minimum power percentage      // (%) 0-100 i.e., Minimum power percentage
      #define SPEED_POWER_MIN          5000    // (RPM)
      #define SPEED_POWER_MAX         30000    // (RPM) SuperPID router controller 0 - 30,000 RPM
      #define SPEED_POWER_STARTUP     25000    // (RPM) M3/M4 speed/power default (with no arguments)   // (转/分钟) 不带参数执行 M3/M4 时，默认使用的转速/功率值

      //#define DEFAULT_ACCELERATION_SPINDLE   1000 // (°/s/s) Default spindle acceleration (speed change with time)  // (度/秒²) 默认主轴加速度（转速随时间的变化率）
    #endif

  #else

    #if ENABLED(SPINDLE_LASER_USE_PWM)
      #define SPEED_POWER_INTERCEPT       0    // (%) 0-100 i.e., Minimum power percentage     // (%) 0-100 i.e., Minimum power percentage
      #define SPEED_POWER_MIN             0    // (%) 0-100
      #define SPEED_POWER_MAX           100    // (%) 0-100
      #define SPEED_POWER_STARTUP        80    // (%) M3/M4 speed/power default (with no arguments)     // (%) 不带参数执行 M3/M4 时，默认使用的转速/功率值
    #endif

    // Define the minimum and maximum test pulse time values for a laser test fire function          // 定义激光测试点火功能的最小、最大测试脉冲时间值
    #define LASER_TEST_PULSE_MIN           1   // (ms) Used with Laser Control Menu                  // (毫秒) 配合激光控制菜单使用
    #define LASER_TEST_PULSE_MAX         999   // (ms) Caution: Menu may not show more than 3 characters  // (毫秒) 注意：控制面板菜单可能无法显示超过3位的数字

    #define SPINDLE_LASER_POWERUP_DELAY   50   // (ms) Delay to allow the spindle/laser to come up to speed/power  //（毫秒）启动延时：等待主轴/激光达到设定的转速/功率后再开始加工
    #define SPINDLE_LASER_POWERDOWN_DELAY 50   // (ms) Delay to allow the spindle to stop            //（毫秒）停机延时：等待主轴完全停止转动后再执行后续操作

   /**
    * Laser Safety Timeout
    *
    * The laser should be turned off when there is no movement for a period of time.
    * Consider material flammability, cut rate, and G-code order when setting this
    * value. Too low and it could turn off during a very slow move; too high and
    * the material could ignite.
    * 
    * 激光安全超时（自动断电）
    *
    * 当设备长时间无任何移动时，激光将自动关闭。
    *
    * 设置此值时，请综合考虑材料易燃性、切割速度和 G-code 执行顺序。
    * 数值设置过小：可能在极慢速移动过程中意外关闭激光；
    * 数值设置过大：可能因激光长时间停留在一点，导致材料起火燃烧。
    */
    #define LASER_SAFETY_TIMEOUT_MS     1000   // (ms)

    /**
     * Any M3 or G1/2/3/5 command with the 'I' parameter enables continuous inline power mode.
     *
     * e.g., 'M3 I' enables continuous inline power which is processed by the planner.
     * Power is stored in move blocks and applied when blocks are processed by the Stepper ISR.
     *
     * 'M4 I' sets dynamic mode which uses the current feedrate to calculate a laser power OCR value.
     *
     * Any move in dynamic mode will use the current feedrate to calculate the laser power.
     * Feed rates are set by the F parameter of a move command e.g. G1 X0 Y10 F6000
     * Laser power would be calculated by bit shifting off 8 LSB's. In binary this is div 256.
     * The calculation gives us ocr values from 0 to 255, values over F65535 will be set as 255 .
     * More refined power control such as compensation for accel/decel will be addressed in future releases.
     *
     * M5 I clears inline mode and set power to 0, M5 sets the power output to 0 but leaves inline mode on.
     * 
     * 任意带有 'I' 参数的 M3 或 G1/2/3/5 指令，将启用**连续联机功率模式**。
     *
     * 例如：'M3 I' 启用连续联机功率模式，由运动规划器处理。
     * 功率值会存储在运动段中，并在步进中断服务程序处理运动段时同步施加。
     *
     * 'M4 I' 设置**动态功率模式**，该模式根据当前进给速率计算激光的 PWM 功率值。
     *
     * 动态模式下的所有运动，都会使用当前进给速率计算激光功率。
     * 进给速率由运动指令中的 F 参数设定，例如：G1 X0 Y10 F6000
     * 激光功率通过**右移 8 位**计算得出（二进制运算，等同于除以 256）。
     * 该计算得出的 PWM 值范围为 0~255，F 值超过 65535 时，功率固定为 255（最大值）。
     * 更精细的功率控制（如加减速补偿）将在后续版本中实现。
     *
     * M5 I：清除联机模式，并将功率设为 0。
     * M5：仅将功率输出设为 0，但**保留**联机模式开启状态。
     */

    /**
     * Enable M3 commands for laser mode inline power planner syncing.
     * This feature enables any M3 S-value to be injected into the block buffers while in
     * CUTTER_MODE_CONTINUOUS. The option allows M3 laser power to be committed without waiting
     * for a planner synchronization
     * 
     * 启用 M3 指令用于激光模式 联机功率规划器同步
     *
     * 该功能启用后，在连续切割模式（CUTTER_MODE_CONTINUOUS）下，
     * 任意 M3 S参数 设定的功率值可直接注入运动缓冲队列。
     * 此选项允许 M3 激光功率立即生效，无需等待运动规划器同步。
     */
    //#define LASER_POWER_SYNC

    /**
     * Scale the laser's power in proportion to the movement rate.
     *
     * - Sets the entry power proportional to the entry speed over the nominal speed.
     * - Ramps the power up every N steps to approximate the speed trapezoid.
     * - Due to the limited power resolution this is only approximate.
     * 
     * 根据运动速率 按比例调节激光功率
     *
     * - 根据实际运动速度与额定速度的比例，设置激光起始功率
     * - 每隔 N 个步进脉冲提升一次功率，模拟速度梯形曲线变化
     * - 受限于功率分辨率，此调节仅为近似匹配
     */
    //#define LASER_POWER_TRAP

    //
    // Laser I2C Ammeter (High precision INA226 low/high side module)  // 激光 I2C 电流表（高精度 INA226 高 / 低侧模块）
    //
    //#define I2C_AMMETER
    #if ENABLED(I2C_AMMETER)
      #define I2C_AMMETER_IMAX            0.1    // (Amps) Calibration value for the expected current range  // (安培) 预期电流范围的校准值
      #define I2C_AMMETER_SHUNT_RESISTOR  0.1    // (Ohms) Calibration shunt resistor value                  // (欧姆) 校准用分流电阻（采样电阻）阻值
    #endif

    //
    // Laser Coolant Flow Meter    // 激光冷却液流量计
    //
    //#define LASER_COOLANT_FLOW_METER
    #if ENABLED(LASER_COOLANT_FLOW_METER)
      #define FLOWMETER_PIN         20  // Requires an external interrupt-enabled pin (e.g., RAMPS 2,3,18,19,20,21)  // 需要一个支持外部中断的引脚（例如：RAMPS 主板的 2、3、18、19、20、21 号引脚）
      #define FLOWMETER_PPL       5880  // (pulses/liter) Flow meter pulses-per-liter on the input pin               // (脉冲/升) 输入引脚连接的流量计，每升水对应的脉冲数量
      #define FLOWMETER_INTERVAL  1000  // (ms) Flow rate calculation interval in milliseconds                       // (毫秒) 水流量计算的时间间隔
      #define FLOWMETER_SAFETY          // Prevent running the laser without the minimum flow rate set below         // 如果未达到下面设置的最小水流速度，则禁止开启激光
      #if ENABLED(FLOWMETER_SAFETY)
        #define FLOWMETER_MIN_LITERS_PER_MINUTE 1.5 // (liters/min) Minimum flow required when enabled               // (升/分钟) 启用保护后，系统要求的**最小水流速度**
      #endif
    #endif

  #endif
#endif // SPINDLE_FEATURE || LASER_FEATURE

/**
 * Synchronous Laser Control with M106/M107
 *
 * Marlin normally applies M106/M107 fan speeds at a time "soon after" processing
 * a planner block. This is too inaccurate for a PWM/TTL laser attached to the fan
 * header (as with some add-on laser kits). Enable this option to set fan/laser
 * speeds with much more exact timing for improved print fidelity.
 *
 * NOTE: This option sacrifices some cooling fan speed options.
 * 
 * 基于M106/M107指令实现激光同步控制
 *
 * Marlin默认在运动规划块处理完成后，延迟一小段时间才执行M106/M107风扇调速指令。
 * 若将PWM/TTL激光模块外接至风扇接口（常见改装激光套件用法），该时序偏差会造成控制精度不足。
 * 开启此项后，风扇/激光功率指令可精准时序执行，提升雕刻成型质量。
 *
 * 注意：启用该功能会缩减部分散热风扇的调速可用选项。
 */
//#define LASER_SYNCHRONOUS_M106_M107

/**
 * Coolant Control
 *
 * Add the M7, M8, and M9 commands to turn mist or flood coolant on and off.
 *
 * Note: COOLANT_MIST_PIN and/or COOLANT_FLOOD_PIN must also be defined.
 * 
 * 冷却液控制
 *
 * 添加 M7、M8、M9 指令，用于开启或关闭喷雾式冷却液 / 洪水式冷却液。
 *
 * 注意：必须同时定义 COOLANT_MIST_PIN 和/或 COOLANT_FLOOD_PIN 引脚。
 */
//#define COOLANT_CONTROL
#if ENABLED(COOLANT_CONTROL)
  #define COOLANT_MIST                // Enable if mist coolant is present             // 如果安装了喷雾冷却装置，则启用此项
  #define COOLANT_FLOOD               // Enable if flood coolant is present            // 如果安装了洪水式冷却装置，则启用此项
  #define COOLANT_MIST_INVERT  false  // Set "true" if the on/off function is reversed // 如果开关功能是反向的，请设置为 "true"
  #define COOLANT_FLOOD_INVERT false  // Set "true" if the on/off function is reversed // 如果开关功能是反向的，请设置为 "true"
#endif

// @section filament width
//================================== 耗材直径 / 耗材宽度 ====================================

/**
 * Filament Width Sensor
 *
 * Measures the filament width in real-time and adjusts
 * flow rate to compensate for any irregularities.
 *
 * Also allows the measured filament diameter to set the
 * extrusion rate, so the slicer only has to specify the
 * volume.
 *
 * Only a single extruder is supported at this time.
 *
 *  34 RAMPS_14    : Analog input 5 on the AUX2 connector
 *  81 PRINTRBOARD : Analog input 2 on the Exp1 connector (version B,C,D,E)
 * 301 RAMBO       : Analog input 3
 *
 * Note: May require analog pins to be defined for other boards.
 * 
 * 耗材直径传感器
 *
 * 实时测量耗材直径，并自动调整
 * 挤出流量以补偿直径不均匀的问题。
 *
 * 也可以使用测得的直径来设定
 * 挤出速率，因此切片软件只需指定挤出体积即可。
 *
 * 目前仅支持单个挤出机。
 *
 *  34 RAMPS_14    : AUX2 接口上的模拟输入 5
 *  81 PRINTRBOARD : Exp1 接口上的模拟输入 2（版本 B,C,D,E）
 * 301 RAMBO       : 模拟输入 3
 *
 * 注意：其他主板可能需要定义模拟引脚。
 */
//#define FILAMENT_WIDTH_SENSOR

#if ENABLED(FILAMENT_WIDTH_SENSOR)
  #define FILAMENT_SENSOR_EXTRUDER_NUM 0    // Index of the extruder that has the filament sensor. :[0,1,2,3,4]   // 安装了耗材直径传感器的挤出机序号（可选值：0、1、2、3、4）
  #define MEASUREMENT_DELAY_CM        14    // (cm) The distance from the filament sensor to the melting chamber  // (厘米) 从耗材传感器到加热腔的距离

  #define FILWIDTH_ERROR_MARGIN        1.0  // (mm) If a measurement differs too much from nominal width ignore it // (毫米) 如果测量值与标称直径偏差过大，则忽略该数据
  #define MAX_MEASUREMENT_DELAY       20    // (bytes) Buffer size for stored measurements (1 byte per cm). Must be larger than MEASUREMENT_DELAY_CM.  // (字节) 存储测量数据的缓冲区大小（每厘米占用1个字节）。必须大于 MEASUREMENT_DELAY_CM 的值。

  #define DEFAULT_MEASURED_FILAMENT_DIA DEFAULT_NOMINAL_FILAMENT_DIA // Set measured to nominal initially      // 初始时，将测量到的耗材直径设定为标称直径

  // Display filament width on the LCD status line. Status messages will expire after 5 seconds.    // 在液晶屏状态栏显示耗材直径数值，状态信息5秒后自动消失
  //#define FILAMENT_LCD_DISPLAY
#endif


//======================================= 电源 ===============================================
// @section power

/**
 * Power Monitor
 * Monitor voltage (V) and/or current (A), and -when possible- power (W)
 *
 * Read and configure with M430
 *
 * The current sensor feeds DC voltage (relative to the measured current) to an analog pin
 * The voltage sensor feeds DC voltage (relative to the measured voltage) to an analog pin
 * 
 * 电源监测
 * 监测电压、电流，条件满足时可监测功率
 * 可通过 M430 指令读取与配置相关参数
 * 电流传感器将对应电流值转换成直流电压，传输至模拟引脚
 * 电压传感器将对应电压值转换成直流电压，传输至模拟引脚
 */
//#define POWER_MONITOR_CURRENT   // Monitor the system current   // 监测系统电流
//#define POWER_MONITOR_VOLTAGE   // Monitor the system voltage   // 监测系统电压

#if ENABLED(POWER_MONITOR_CURRENT)
  #define POWER_MONITOR_VOLTS_PER_AMP    0.05000  // Input voltage to the MCU analog pin per amp  - DO NOT apply more than ADC_VREF!  // 每安培电流对应的输入到MCU模拟引脚的电压，注意：绝对不要超过 ADC_VREF（参考电压）！
  #define POWER_MONITOR_CURRENT_OFFSET   0        // Offset (in amps) applied to the calculated current    // 应用到计算电流值上的偏移量（单位：安培）
  #define POWER_MONITOR_FIXED_VOLTAGE   13.6      // Voltage for a current sensor with no voltage sensor (for power display)  // 在未安装电压传感器时，为电流传感器设定的电压值（用于功率计算显示）
#endif

#if ENABLED(POWER_MONITOR_VOLTAGE)
  #define POWER_MONITOR_VOLTS_PER_VOLT  0.077933  // Input voltage to the MCU analog pin per volt - DO NOT apply more than ADC_VREF!  // 每伏特电压对应的、输入到MCU模拟引脚的电压值。注意：绝对不要超过 ADC_VREF（参考电压）！
  #define POWER_MONITOR_VOLTAGE_OFFSET  0         // Offset (in volts) applied to the calculated voltage     // 应用到计算电压值上的偏移量（单位：伏特）
#endif

// @section safety

/**
 * Stepper Driver Anti-SNAFU Protection
 *
 * If the SAFE_POWER_PIN is defined for your board, Marlin will check
 * that stepper drivers are properly plugged in before applying power.
 * Disable protection if your stepper drivers don't support the feature.
 * 
 * 步进驱动防故障保护
 * 若主板定义了安全电源引脚，Marlin 上电前会检测步进驱动是否正常插接。
 * 驱动芯片不支持该功能时，可关闭此项保护。
 */
//#define DISABLE_DRIVER_SAFE_POWER_PROTECT

// @section cnc

/**
 * CNC Coordinate Systems
 *
 * Enables G53 and G54-G59.3 commands to select coordinate systems
 * and G92.1 to reset the workspace to native machine space.
 * 
 * CNC 坐标系
 * 启用 G53、G54-G59.3 坐标系切换指令，以及 G92.1 机床坐标复位指令
 */
//#define CNC_COORDINATE_SYSTEMS

// @section security

/**
 * Expected Printer Check
 * Add the M16 G-code to compare a string to the MACHINE_NAME.
 * M16 with a non-matching string causes the printer to halt.
 * 
 * 预期打印机校验
 *
 * 添加 M16 G代码，用于将字符串与固件中设置的打印机名称（MACHINE_NAME）进行比对。
 * 如果 M16 指令携带的字符串与固件名称不匹配，打印机将立即停止运行。
 */
//#define EXPECTED_PRINTER_CHECK

// @section volumetrics

/**
 * Disable all Volumetric extrusion options  // 禁用所有体积挤出功能选项
 */
//#define NO_VOLUMETRICS

#if DISABLED(NO_VOLUMETRICS)
  /**
   * Volumetric extrusion default state
   * Activate to make volumetric extrusion the default method,
   * with DEFAULT_NOMINAL_FILAMENT_DIA as the default diameter.
   *
   * M200 D0 to disable, M200 Dn to set a new diameter (and enable volumetric).
   * M200 S0/S1 to disable/enable volumetric extrusion.
   * 
   * 体积挤出默认状态
   * 启用后，将体积挤出设为默认方式，
   * 并使用 DEFAULT_NOMINAL_FILAMENT_DIA 作为默认耗材直径。
   *
   * M200 D0 ：关闭体积挤出
   * M200 Dn ：设置新的耗材直径（并启用体积挤出）
   * M200 S0/S1 ：关闭 / 启用体积挤出
   */
  //#define VOLUMETRIC_DEFAULT_ON

  //#define VOLUMETRIC_EXTRUDER_LIMIT
  #if ENABLED(VOLUMETRIC_EXTRUDER_LIMIT)
    /**
     * Default volumetric extrusion limit in cubic mm per second (mm^3/sec).
     * This factory setting applies to all extruders.
     * Use 'M200 [T<extruder>] L<limit>' to override and 'M502' to reset.
     * A non-zero value activates Volume-based Extrusion Limiting.
     * 
     * 默认体积挤出速度限制，单位：立方毫米/秒 (mm^3/sec)
     * 此出厂设置适用于所有挤出机
     * 使用 'M200 [T<挤出机序号>] L<限制值>' 覆盖设置，使用 'M502' 恢复默认
     * 设置为**非0值**时，将启用**基于体积的挤出限速**功能
     */
    #define DEFAULT_VOLUMETRIC_EXTRUDER_LIMIT  0.00     // (mm^3/sec)
    #define VOLUMETRIC_EXTRUDER_LIMIT_MAX     20        // (mm^3/sec)
  #endif
#endif

// @section reporting

/**
 * Extra options for the M114 "Current Position" report  // M114 "当前位置" 报告的额外选项
 */
//#define M114_DETAIL         // Use 'M114 D' for details to check planner calculations     // 使用 "M114 D" 指令可查看详细信息，用于检查规划器（运动计算）的运算结果
//#define M114_REALTIME       // Real current position based on forward kinematics          // 基于正向运动学计算的 **真实实时位置**
//#define M114_LEGACY         // M114 used to synchronize on every call. Enable if needed.  // 以往 M114 指令每次调用时都会执行同步操作。如需要此功能可启用。

/**
 * Auto-report fan speed with M123 S<seconds>
 * Requires fans with tachometer pins
 * 
 * 通过M123 S<秒数>自动上报风扇转速
 * 需配备带测速引脚的风扇
 */
//#define AUTO_REPORT_FANS

//#define REPORT_FAN_CHANGE   // Report the new fan speed when changed by M106 (and others) // 当风扇转速通过 M106 指令（或其他方式）修改时，上报新的风扇转速

/**
 * Auto-report temperatures with M155 S<seconds>     // 使用 M155 S<秒数> 自动上报温度
 */
#define AUTO_REPORT_TEMPERATURES
#if ENABLED(AUTO_REPORT_TEMPERATURES) && TEMP_SENSOR_REDUNDANT
  //#define AUTO_REPORT_REDUNDANT // Include the "R" sensor in the auto-report     // 在自动温度报告中包含 R 传感器的数据
#endif

/**
 * Auto-report position with M154 S<seconds>   // 使用 M154 S<秒数> 自动上报当前位置
 */
//#define AUTO_REPORT_POSITION
#if ENABLED(AUTO_REPORT_POSITION)
  //#define AUTO_REPORT_REAL_POSITION // Auto-report the real position    // 自动报告 **真实实时位置**
#endif

/**
 * M115 - Report capabilites. Disable to save ~1150 bytes of flash.
 *        Some hosts (and serial TFT displays) rely on this feature.
 * 
 * M115 - 报告打印机固件的功能与配置。禁用此项可节省约 1150 字节的闪存空间。
 *        部分上位机软件（如串口屏、控制软件）依赖此功能正常工作。
 */
#define CAPABILITIES_REPORT
#if ENABLED(CAPABILITIES_REPORT)
  // Include capabilities in M115 output  // 在 M115 指令的返回信息中包含打印机完整功能列表
  #define EXTENDED_CAPABILITIES_REPORT
  #if ENABLED(EXTENDED_CAPABILITIES_REPORT)
    //#define M115_GEOMETRY_REPORT
  #endif
#endif

// @section gcode

/**
 * Spend 28 bytes of SRAM to optimize the G-code parser
 */
#define FASTER_GCODE_PARSER
#if ENABLED(FASTER_GCODE_PARSER)
  //#define GCODE_QUOTED_STRINGS  // Support for quoted string parameters
#endif

/**
 * Support for MeatPack G-code compression (https://github.com/scottmudge/OctoPrint-MeatPack)
 */
//#define MEATPACK_ON_SERIAL_PORT_1
//#define MEATPACK_ON_SERIAL_PORT_2

//#define GCODE_CASE_INSENSITIVE  // Accept G-code sent to the firmware in lowercase

//#define REPETIER_GCODE_M360     // Add commands originally from Repetier FW

/**
 * Enable M111 debug flags 1=ECHO, 2=INFO, 4=ERRORS (unimplemented).
 * Disable to save some flash. Some hosts (Repetier Host) may rely on this feature.
 */
#define DEBUG_FLAGS_GCODE

/**
 * Enable this option for a leaner build of Marlin that removes
 * workspace offsets to slightly optimize performance.
 * G92 will revert to its behavior from Marlin 1.0.
 */
//#define NO_WORKSPACE_OFFSETS

/**
 * Disable M206 and M428 if you don't need home offsets.
 */
//#define NO_HOME_OFFSETS

/**
 * CNC G-code options
 * Support CNC-style G-code dialects used by laser cutters, drawing machine cams, etc.
 * Note that G0 feedrates should be used with care for 3D printing (if used at all).
 * High feedrates may cause ringing and harm print quality.
 */
//#define PAREN_COMMENTS      // Support for parentheses-delimited comments
//#define GCODE_MOTION_MODES  // Remember the motion mode (G0 G1 G2 G3 G5 G38.X) and apply for X Y Z E F, etc.

// Enable and set a (default) feedrate for all G0 moves
//#define G0_FEEDRATE 3000 // (mm/min)
#ifdef G0_FEEDRATE
  //#define VARIABLE_G0_FEEDRATE // The G0 feedrate is set by F in G0 motion mode
#endif

/**
 * Startup commands
 *
 * Execute certain G-code commands immediately after power-on.
 */
//#define STARTUP_COMMANDS "M17 Z"

/**
 * G-code Macros
 *
 * Add G-codes M810-M819 to define and run G-code macros.
 * Macros are not saved to EEPROM.
 */
//#define GCODE_MACROS
#if ENABLED(GCODE_MACROS)
  #define GCODE_MACROS_SLOTS       5  // Up to 10 may be used
  #define GCODE_MACROS_SLOT_SIZE  50  // Maximum length of a single macro
#endif

/**
 * User-defined menu items to run custom G-code.
 * Up to 25 may be defined, but the actual number is LCD-dependent.
 */

// @section custom main menu

// Custom Menu: Main Menu
//#define CUSTOM_MENU_MAIN
#if ENABLED(CUSTOM_MENU_MAIN)
  //#define CUSTOM_MENU_MAIN_TITLE "Custom Commands"
  #define CUSTOM_MENU_MAIN_SCRIPT_DONE "M117 User Script Done"
  #define CUSTOM_MENU_MAIN_SCRIPT_AUDIBLE_FEEDBACK
  //#define CUSTOM_MENU_MAIN_SCRIPT_RETURN   // Return to status screen after a script
  #define CUSTOM_MENU_MAIN_ONLY_IDLE         // Only show custom menu when the machine is idle

  #define MAIN_MENU_ITEM_1_DESC "Home & UBL Info"
  #define MAIN_MENU_ITEM_1_GCODE "G28\nG29 W"
  //#define MAIN_MENU_ITEM_1_CONFIRM          // Show a confirmation dialog before this action

  #define MAIN_MENU_ITEM_2_DESC "Preheat for " PREHEAT_1_LABEL
  #define MAIN_MENU_ITEM_2_GCODE "M140 S" STRINGIFY(PREHEAT_1_TEMP_BED) "\nM104 S" STRINGIFY(PREHEAT_1_TEMP_HOTEND)
  //#define MAIN_MENU_ITEM_2_CONFIRM

  //#define MAIN_MENU_ITEM_3_DESC "Preheat for " PREHEAT_2_LABEL
  //#define MAIN_MENU_ITEM_3_GCODE "M140 S" STRINGIFY(PREHEAT_2_TEMP_BED) "\nM104 S" STRINGIFY(PREHEAT_2_TEMP_HOTEND)
  //#define MAIN_MENU_ITEM_3_CONFIRM

  //#define MAIN_MENU_ITEM_4_DESC "Heat Bed/Home/Level"
  //#define MAIN_MENU_ITEM_4_GCODE "M140 S" STRINGIFY(PREHEAT_2_TEMP_BED) "\nG28\nG29"
  //#define MAIN_MENU_ITEM_4_CONFIRM

  //#define MAIN_MENU_ITEM_5_DESC "Home & Info"
  //#define MAIN_MENU_ITEM_5_GCODE "G28\nM503"
  //#define MAIN_MENU_ITEM_5_CONFIRM
#endif

// @section custom config menu

// Custom Menu: Configuration Menu
//#define CUSTOM_MENU_CONFIG
#if ENABLED(CUSTOM_MENU_CONFIG)
  //#define CUSTOM_MENU_CONFIG_TITLE "Custom Commands"
  #define CUSTOM_MENU_CONFIG_SCRIPT_DONE "M117 Wireless Script Done"
  #define CUSTOM_MENU_CONFIG_SCRIPT_AUDIBLE_FEEDBACK
  //#define CUSTOM_MENU_CONFIG_SCRIPT_RETURN  // Return to status screen after a script
  #define CUSTOM_MENU_CONFIG_ONLY_IDLE        // Only show custom menu when the machine is idle

  #define CONFIG_MENU_ITEM_1_DESC "Wifi ON"
  #define CONFIG_MENU_ITEM_1_GCODE "M118 [ESP110] WIFI-STA pwd=12345678"
  //#define CONFIG_MENU_ITEM_1_CONFIRM        // Show a confirmation dialog before this action

  #define CONFIG_MENU_ITEM_2_DESC "Bluetooth ON"
  #define CONFIG_MENU_ITEM_2_GCODE "M118 [ESP110] BT pwd=12345678"
  //#define CONFIG_MENU_ITEM_2_CONFIRM

  //#define CONFIG_MENU_ITEM_3_DESC "Radio OFF"
  //#define CONFIG_MENU_ITEM_3_GCODE "M118 [ESP110] OFF pwd=12345678"
  //#define CONFIG_MENU_ITEM_3_CONFIRM

  //#define CONFIG_MENU_ITEM_4_DESC "Wifi ????"
  //#define CONFIG_MENU_ITEM_4_GCODE "M118 ????"
  //#define CONFIG_MENU_ITEM_4_CONFIRM

  //#define CONFIG_MENU_ITEM_5_DESC "Wifi ????"
  //#define CONFIG_MENU_ITEM_5_GCODE "M118 ????"
  //#define CONFIG_MENU_ITEM_5_CONFIRM
#endif

// @section custom buttons

/**
 * User-defined buttons to run custom G-code.
 * Up to 25 may be defined.
 */
//#define CUSTOM_USER_BUTTONS
#if ENABLED(CUSTOM_USER_BUTTONS)
  //#define BUTTON1_PIN -1
  #if PIN_EXISTS(BUTTON1)
    #define BUTTON1_HIT_STATE     LOW       // State of the triggered button. NC=LOW. NO=HIGH.
    #define BUTTON1_WHEN_PRINTING false     // Button allowed to trigger during printing?
    #define BUTTON1_GCODE         "G28"
    #define BUTTON1_DESC          "Homing"  // Optional string to set the LCD status
  #endif

  //#define BUTTON2_PIN -1
  #if PIN_EXISTS(BUTTON2)
    #define BUTTON2_HIT_STATE     LOW
    #define BUTTON2_WHEN_PRINTING false
    #define BUTTON2_GCODE         "M140 S" STRINGIFY(PREHEAT_1_TEMP_BED) "\nM104 S" STRINGIFY(PREHEAT_1_TEMP_HOTEND)
    #define BUTTON2_DESC          "Preheat for " PREHEAT_1_LABEL
  #endif

  //#define BUTTON3_PIN -1
  #if PIN_EXISTS(BUTTON3)
    #define BUTTON3_HIT_STATE     LOW
    #define BUTTON3_WHEN_PRINTING false
    #define BUTTON3_GCODE         "M140 S" STRINGIFY(PREHEAT_2_TEMP_BED) "\nM104 S" STRINGIFY(PREHEAT_2_TEMP_HOTEND)
    #define BUTTON3_DESC          "Preheat for " PREHEAT_2_LABEL
  #endif
#endif

// @section host

/**
 * Host Action Commands
 *
 * Define host streamer action commands in compliance with the standard.
 *
 * See https://reprap.org/wiki/G-code#Action_commands
 * Common commands ........ poweroff, pause, paused, resume, resumed, cancel
 * G29_RETRY_AND_RECOVER .. probe_rewipe, probe_failed
 *
 * Some features add reason codes to extend these commands.
 *
 * Host Prompt Support enables Marlin to use the host for user prompts so
 * filament runout and other processes can be managed from the host side.
 */
//#define HOST_ACTION_COMMANDS
#if ENABLED(HOST_ACTION_COMMANDS)
  //#define HOST_PAUSE_M76                // Tell the host to pause in response to M76
  //#define HOST_PROMPT_SUPPORT           // Initiate host prompts to get user feedback
  #if ENABLED(HOST_PROMPT_SUPPORT)
    //#define HOST_STATUS_NOTIFICATIONS   // Send some status messages to the host as notifications
  #endif
  //#define HOST_START_MENU_ITEM          // Add a menu item that tells the host to start
  //#define HOST_SHUTDOWN_MENU_ITEM       // Add a menu item that tells the host to shut down
#endif

// @section extras

/**
 * Cancel Objects
 *
 * Implement M486 to allow Marlin to skip objects
 */
//#define CANCEL_OBJECTS
#if ENABLED(CANCEL_OBJECTS)
  #define CANCEL_OBJECTS_REPORTING // Emit the current object as a status message
#endif

/**
 * I2C position encoders for closed loop control.
 * Developed by Chris Barr at Aus3D.
 *
 * Wiki: https://wiki.aus3d.com.au/Magnetic_Encoder
 * Github: https://github.com/Aus3D/MagneticEncoder
 *
 * Supplier: https://aus3d.com.au/products/magnetic-encoder-module
 * Alternative Supplier: https://reliabuild3d.com/
 *
 * Reliabuild encoders have been modified to improve reliability.
 * @section i2c encoders
 */

//#define I2C_POSITION_ENCODERS
#if ENABLED(I2C_POSITION_ENCODERS)

  #define I2CPE_ENCODER_CNT         1                       // The number of encoders installed; max of 5
                                                            // encoders supported currently.

  #define I2CPE_ENC_1_ADDR          I2CPE_PRESET_ADDR_X     // I2C address of the encoder. 30-200.
  #define I2CPE_ENC_1_AXIS          X_AXIS                  // Axis the encoder module is installed on.  <X|Y|Z|E>_AXIS.
  #define I2CPE_ENC_1_TYPE          I2CPE_ENC_TYPE_LINEAR   // Type of encoder:  I2CPE_ENC_TYPE_LINEAR -or-
                                                            // I2CPE_ENC_TYPE_ROTARY.
  #define I2CPE_ENC_1_TICKS_UNIT    2048                    // 1024 for magnetic strips with 2mm poles; 2048 for
                                                            // 1mm poles. For linear encoders this is ticks / mm,
                                                            // for rotary encoders this is ticks / revolution.
  //#define I2CPE_ENC_1_TICKS_REV     (16 * 200)            // Only needed for rotary encoders; number of stepper
                                                            // steps per full revolution (motor steps/rev * microstepping)
  //#define I2CPE_ENC_1_INVERT                              // Invert the direction of axis travel.
  #define I2CPE_ENC_1_EC_METHOD     I2CPE_ECM_MICROSTEP     // Type of error error correction.
  #define I2CPE_ENC_1_EC_THRESH     0.10                    // Threshold size for error (in mm) above which the
                                                            // printer will attempt to correct the error; errors
                                                            // smaller than this are ignored to minimize effects of
                                                            // measurement noise / latency (filter).

  #define I2CPE_ENC_2_ADDR          I2CPE_PRESET_ADDR_Y     // Same as above, but for encoder 2.
  #define I2CPE_ENC_2_AXIS          Y_AXIS
  #define I2CPE_ENC_2_TYPE          I2CPE_ENC_TYPE_LINEAR
  #define I2CPE_ENC_2_TICKS_UNIT    2048
  //#define I2CPE_ENC_2_TICKS_REV   (16 * 200)
  //#define I2CPE_ENC_2_INVERT
  #define I2CPE_ENC_2_EC_METHOD     I2CPE_ECM_MICROSTEP
  #define I2CPE_ENC_2_EC_THRESH     0.10

  #define I2CPE_ENC_3_ADDR          I2CPE_PRESET_ADDR_Z     // Encoder 3.  Add additional configuration options
  #define I2CPE_ENC_3_AXIS          Z_AXIS                  // as above, or use defaults below.

  #define I2CPE_ENC_4_ADDR          I2CPE_PRESET_ADDR_E     // Encoder 4.
  #define I2CPE_ENC_4_AXIS          E_AXIS

  #define I2CPE_ENC_5_ADDR          34                      // Encoder 5.
  #define I2CPE_ENC_5_AXIS          E_AXIS

  // Default settings for encoders which are enabled, but without settings configured above.
  #define I2CPE_DEF_TYPE            I2CPE_ENC_TYPE_LINEAR
  #define I2CPE_DEF_ENC_TICKS_UNIT  2048
  #define I2CPE_DEF_TICKS_REV       (16 * 200)
  #define I2CPE_DEF_EC_METHOD       I2CPE_ECM_NONE
  #define I2CPE_DEF_EC_THRESH       0.1

  //#define I2CPE_ERR_THRESH_ABORT  100.0                   // Threshold size for error (in mm) error on any given
                                                            // axis after which the printer will abort. Comment out to
                                                            // disable abort behavior.

  #define I2CPE_TIME_TRUSTED        10000                   // After an encoder fault, there must be no further fault
                                                            // for this amount of time (in ms) before the encoder
                                                            // is trusted again.

  /**
   * Position is checked every time a new command is executed from the buffer but during long moves,
   * this setting determines the minimum update time between checks. A value of 100 works well with
   * error rolling average when attempting to correct only for skips and not for vibration.
   */
  #define I2CPE_MIN_UPD_TIME_MS     4                       // (ms) Minimum time between encoder checks.

  // Use a rolling average to identify persistent errors that indicate skips, as opposed to vibration and noise.
  #define I2CPE_ERR_ROLLING_AVERAGE

#endif // I2C_POSITION_ENCODERS

/**
 * Analog Joystick(s)
 * @section joystick
 */
//#define JOYSTICK
#if ENABLED(JOYSTICK)
  #define JOY_X_PIN    5  // RAMPS: Suggested pin A5  on AUX2
  #define JOY_Y_PIN   10  // RAMPS: Suggested pin A10 on AUX2
  #define JOY_Z_PIN   12  // RAMPS: Suggested pin A12 on AUX2
  #define JOY_EN_PIN  44  // RAMPS: Suggested pin D44 on AUX2

  //#define INVERT_JOY_X  // Enable if X direction is reversed
  //#define INVERT_JOY_Y  // Enable if Y direction is reversed
  //#define INVERT_JOY_Z  // Enable if Z direction is reversed

  // Use M119 with JOYSTICK_DEBUG to find reasonable values after connecting:
  #define JOY_X_LIMITS { 5600, 8190-100, 8190+100, 10800 } // min, deadzone start, deadzone end, max
  #define JOY_Y_LIMITS { 5600, 8250-100, 8250+100, 11000 }
  #define JOY_Z_LIMITS { 4800, 8080-100, 8080+100, 11550 }
  //#define JOYSTICK_DEBUG
#endif

/**
 * Mechanical Gantry Calibration
 * Modern replacement for the Průša TMC_Z_CALIBRATION.
 * Adds capability to work with any adjustable current drivers.
 * Implemented as G34 because M915 is deprecated.
 * @section calibrate
 */
//#define MECHANICAL_GANTRY_CALIBRATION
#if ENABLED(MECHANICAL_GANTRY_CALIBRATION)
  #define GANTRY_CALIBRATION_CURRENT          600     // Default calibration current in ma
  #define GANTRY_CALIBRATION_EXTRA_HEIGHT      15     // Extra distance in mm past Z_###_POS to move
  #define GANTRY_CALIBRATION_FEEDRATE         500     // Feedrate for correction move
  //#define GANTRY_CALIBRATION_TO_MIN                 // Enable to calibrate Z in the MIN direction

  //#define GANTRY_CALIBRATION_SAFE_POSITION XY_CENTER // Safe position for nozzle
  //#define GANTRY_CALIBRATION_XY_PARK_FEEDRATE 3000  // XY Park Feedrate - MMM
  //#define GANTRY_CALIBRATION_COMMANDS_PRE   ""
  #define GANTRY_CALIBRATION_COMMANDS_POST  "G28"     // G28 highly recommended to ensure an accurate position
#endif

/**
 * Instant freeze / unfreeze functionality
 * Potentially useful for rapid stop that allows being resumed. Halts stepper movement.
 * Note this does NOT pause spindles, lasers, fans, heaters or any other auxiliary device.
 * @section interface
 */
//#define FREEZE_FEATURE
#if ENABLED(FREEZE_FEATURE)
  //#define FREEZE_PIN 41   // Override the default (KILL) pin here
  #define FREEZE_STATE LOW  // State of pin indicating freeze
#endif

/**
 * MAX7219 Debug Matrix
 *
 * Add support for a low-cost 8x8 LED Matrix based on the Max7219 chip as a realtime status display.
 * Requires 3 signal wires. Some useful debug options are included to demonstrate its usage.
 * @section debug matrix
 */
//#define MAX7219_DEBUG
#if ENABLED(MAX7219_DEBUG)
  #define MAX7219_CLK_PIN   64
  #define MAX7219_DIN_PIN   57
  #define MAX7219_LOAD_PIN  44

  //#define MAX7219_GCODE          // Add the M7219 G-code to control the LED matrix
  #define MAX7219_INIT_TEST    2   // Test pattern at startup: 0=none, 1=sweep, 2=spiral
  #define MAX7219_NUMBER_UNITS 1   // Number of Max7219 units in chain.
  #define MAX7219_ROTATE       0   // Rotate the display clockwise (in multiples of +/- 90°)
                                   // connector at:  right=0   bottom=-90  top=90  left=180
  //#define MAX7219_REVERSE_ORDER  // The order of the LED matrix units may be reversed
  //#define MAX7219_REVERSE_EACH   // The LEDs in each matrix unit row may be reversed
  //#define MAX7219_SIDE_BY_SIDE   // Big chip+matrix boards can be chained side-by-side

  /**
   * Sample debug features
   * If you add more debug displays, be careful to avoid conflicts!
   */
  #define MAX7219_DEBUG_PRINTER_ALIVE     // Blink corner LED of 8x8 matrix to show that the firmware is functioning
  #define MAX7219_DEBUG_PLANNER_HEAD  2   // Show the planner queue head position on this and the next LED matrix row
  #define MAX7219_DEBUG_PLANNER_TAIL  4   // Show the planner queue tail position on this and the next LED matrix row

  #define MAX7219_DEBUG_PLANNER_QUEUE 0   // Show the current planner queue depth on this and the next LED matrix row
                                          // If you experience stuttering, reboots, etc. this option can reveal how
                                          // tweaks made to the configuration are affecting the printer in real-time.
  #define MAX7219_DEBUG_PROFILE       6   // Display the fraction of CPU time spent in profiled code on this LED matrix
                                          // row. By default idle() is profiled so this shows how "idle" the processor is.
                                          // See class CodeProfiler.
  //#define MAX7219_DEBUG_MULTISTEPPING 6 // Show multi-stepping 1 to 128 on this LED matrix row.
  //#define MAX7219_DEBUG_SLOWDOWN      6 // Count (mod 16) how many times SLOWDOWN has reduced print speed.
  //#define MAX7219_REINIT_ON_POWERUP     // Re-initialize MAX7129 when power supply turns on
#endif

/**
 * NanoDLP Sync support
 *
 * Support for Synchronized Z moves when used with NanoDLP. G0/G1 axis moves will
 * output a "Z_move_comp" string to enable synchronization with DLP projector exposure.
 * This feature allows you to use [[WaitForDoneMessage]] instead of M400 commands.
 * @section nanodlp
 */
//#define NANODLP_Z_SYNC
#if ENABLED(NANODLP_Z_SYNC)
  //#define NANODLP_ALL_AXIS  // Send a "Z_move_comp" report for any axis move (not just Z).
#endif

/**
 * Ethernet. Use M552 to enable and set the IP address.
 * @section network
 */
#if HAS_ETHERNET
  #define MAC_ADDRESS { 0xDE, 0xAD, 0xBE, 0xEF, 0xF0, 0x0D }  // A MAC address unique to your network
#endif

/**
 * Native ESP32 board with WiFi or add-on ESP32 WiFi-101 module
 */
//#define WIFISUPPORT         // Marlin embedded WiFi management. Not needed for simple WiFi serial port.
//#define ESP3D_WIFISUPPORT   // ESP3D Library WiFi management (https://github.com/luc-github/ESP3DLib)

/**
 * Extras for an ESP32-based motherboard with WIFISUPPORT
 * These options don't apply to add-on WiFi modules based on ESP32 WiFi101.
 */
#if ANY(WIFISUPPORT, ESP3D_WIFISUPPORT)
  //#define WEBSUPPORT          // Start a webserver (which may include auto-discovery) using SPIFFS
  //#define OTASUPPORT          // Support over-the-air firmware updates
  //#define WIFI_CUSTOM_COMMAND // Accept feature config commands (e.g., WiFi ESP3D) from the host

  /**
   * To set a default WiFi SSID / Password, create a file called Configuration_Secure.h with
   * the following defines, customized for your network. This specific file is excluded via
   * .gitignore to prevent it from accidentally leaking to the public.
   *
   *   #define WIFI_SSID "WiFi SSID"
   *   #define WIFI_PWD  "WiFi Password"
   */
  //#include "Configuration_Secure.h" // External file with WiFi SSID / Password
#endif

// @section multi-material

/**
 * Průša Multi-Material Unit (MMU)
 * Enable in Configuration.h
 *
 * These devices allow a single stepper driver on the board to drive
 * multi-material feeders with any number of stepper motors.
 */
#if HAS_PRUSA_MMU1
  /**
   * This option only allows the multiplexer to switch on tool-change.
   * Additional options to configure custom E moves are pending.
   *
   * Override the default DIO selector pins here, if needed.
   * Some pins files may provide defaults for these pins.
   */
  //#define E_MUX0_PIN 40  // Always Required
  //#define E_MUX1_PIN 42  // Needed for 3 to 8 inputs
  //#define E_MUX2_PIN 44  // Needed for 5 to 8 inputs

#elif HAS_PRUSA_MMU2 || HAS_PRUSA_MMU3
  // Common settings for MMU2/MMU2S/MMU3
  // Serial port used for communication with MMU2/MMU2S/MMU3.
  #define MMU_SERIAL_PORT 2
  #define MMU_BAUD 115200

  //#define MMU_RST_PIN 23    // Define this pin to use Hardware Reset for MMU2/MMU2S/MMU3

  //#define MMU_MENUS         // Add an LCD menu for MMU2/MMU2S/MMU3

  //#define MMU_DEBUG         // Write debug info to serial output

  // Options pertaining to MMU2 and MMU2S
  #if HAS_PRUSA_MMU2
    // Enable if the MMU2 has 12V stepper motors (MMU2 Firmware 1.0.2 and up)
    //#define MMU2_MODE_12V

    // Settings for filament load / unload from the LCD menu.
    // This is for Průša MK3-style extruders. Customize for your hardware.
    #define MMU2_FILAMENTCHANGE_EJECT_FEED 80.0

    // G-code to execute when MMU2 F.I.N.D.A. probe detects filament runout
    #define MMU2_FILAMENT_RUNOUT_SCRIPT "M600"

    // MMU2 sequences use mm/min. Not compatible with MMU3, which use mm/sec.
    #define MMU2_LOAD_TO_NOZZLE_SEQUENCE \
      {  4.4,  871 }, \
      { 10.0, 1393 }, \
      {  4.4,  871 }, \
      { 10.0,  198 }

    #define MMU2_RAMMING_SEQUENCE \
      {   1.0, 1000 }, \
      {   1.0, 1500 }, \
      {   2.0, 2000 }, \
      {   1.5, 3000 }, \
      {   2.5, 4000 }, \
      { -15.0, 5000 }, \
      { -14.0, 1200 }, \
      {  -6.0,  600 }, \
      {  10.0,  700 }, \
      { -10.0,  400 }, \
      { -50.0, 2000 }

  #endif // HAS_PRUSA_MMU2

  /**
   * Options pertaining to MMU2S devices
   * Requires the MK3S extruder with a sensor at the extruder idler, like the MMU2S.
   * See https://help.prusa3d.com/guide/3b-mk3s-mk2-5s-extruder-upgrade_41560#42048, step 11
   */
  #if HAS_PRUSA_MMU2S
    #define MMU2_C0_RETRY   5             // Number of retries (total time = timeout*retries)

    /**
     * This is called after the filament runout sensor is triggered to check if
     * the filament has been loaded properly by moving the filament back and
     * forth to see if the filament runout sensor is going to get triggered
     * again, which should not occur if the filament is properly loaded.
     *
     * Thus, the MMU2_CAN_LOAD_SEQUENCE should contain some forward and
     * backward moves. The forward moves should be greater than the backward
     * moves.
     *
     * This is useless if your filament runout sensor is way behind the gears.
     * In that case use {0, MMU2_CAN_LOAD_FEEDRATE}
     *
     * Adjust MMU2_CAN_LOAD_SEQUENCE according to your setup.
     */
    #define MMU2_CAN_LOAD_FEEDRATE 800    // (mm/min)
    #define MMU2_CAN_LOAD_SEQUENCE \
      {   5.0, MMU2_CAN_LOAD_FEEDRATE }, \
      {  15.0, MMU2_CAN_LOAD_FEEDRATE }, \
      { -10.0, MMU2_CAN_LOAD_FEEDRATE }

    #define MMU2_CAN_LOAD_RETRACT   6.0   // (mm) Keep under the distance between Load Sequence values
    #define MMU2_CAN_LOAD_DEVIATION 0.8   // (mm) Acceptable deviation

    #define MMU2_CAN_LOAD_INCREMENT 0.2   // (mm) To reuse within MMU2 module
    #define MMU2_CAN_LOAD_INCREMENT_SEQUENCE \
      { -MMU2_CAN_LOAD_INCREMENT, MMU2_CAN_LOAD_FEEDRATE }

    // Continue unloading if sensor detects filament after the initial unload move
    //#define MMU_IR_UNLOAD_MOVE

  #elif HAS_PRUSA_MMU3

    // MMU3 settings

    #define MMU3_HAS_CUTTER     // Enable cutter related functionality

    #define MMU3_MAX_RETRIES 3  // Number of retries (total time = timeout*retries)

    // As discussed with our PrusaSlicer profile specialist
    // - ToolChange shall not try to push filament into the very tip of the nozzle
    // to have some space for additional G-code to tune the extruded filament length
    // in the profile
    // Beware - this value is used to initialize the MMU logic layer - it will be sent to the MMU upon line up (written into its 8bit register 0x0b)
    // However - in the G-code we can get a request to set the extra load distance at runtime to something else (M708 A0xb Xsomething).
    // The printer intercepts such a call and sets its extra load distance to match the new value as well.
    #define MMU3_FILAMENT_SENSOR_E_POSITION  0   // (mm)
    #define _MMU3_LOAD_DISTANCE_PAST_GEARS   5   // (mm)
    #define MMU3_TOOL_CHANGE_LOAD_LENGTH (MMU3_FILAMENT_SENSOR_E_POSITION + _MMU3_LOAD_DISTANCE_PAST_GEARS) // (mm)

    #define MMU3_LOAD_TO_NOZZLE_FEED_RATE        20.0 // (mm/s)

    #define MMU3_VERIFY_LOAD_TO_NOZZLE_FEED_RATE 50.0 // (mm/s)
    #define _MMU3_VERIFY_LOAD_TO_NOZZLE_TWEAK    -5.0 // (mm) Amount to adjust the length for verifying load-to-nozzle

    // The first thing the MMU does is initialize its axis.
    // Meanwhile the E-motor will unload 20mm of filament in about 1 second.
    #define MMU3_RETRY_UNLOAD_TO_FINDA_LENGTH    80.0 // (mm)
    #define MMU3_RETRY_UNLOAD_TO_FINDA_FEED_RATE 80.0 // (mm/s)

    // After loading a new filament, the printer will extrude this length of filament
    // then retract to the original position. This is used to check if the filament sensor
    // reading flickers or filament is jammed.
    #define _MMU_EXTRUDER_PTFE_LENGTH            42.3 // (mm)
    #define _MMU_EXTRUDER_HEATBREAK_LENGTH       17.7 // (mm)
    #define MMU3_CHECK_FILAMENT_PRESENCE_EXTRUSION_LENGTH (MMU3_FILAMENT_SENSOR_E_POSITION + _MMU_EXTRUDER_PTFE_LENGTH + _MMU_EXTRUDER_HEATBREAK_LENGTH + _MMU3_VERIFY_LOAD_TO_NOZZLE_TWEAK) // (mm)

    /**
     * SpoolJoin Consumes All Filament -- EXPERIMENTAL
     *
     * SpoolJoin normally triggers when FINDA sensor untriggers while printing.
     * This is the default behaviour and it doesn't consume all the filament
     * before triggering a filament change. This leaves some filament in the
     * current slot and before switching to the next slot it is unloaded.
     *
     * Enabling this option will trigger the filament change when both FINDA
     * and Filament Runout Sensor triggers during the print and it allows the
     * filament in the current slot to be completely consumed before doing the
     * filament change. But this can cause problems as a little bit of filament
     * will be left between the extruder gears (thinking that the filament
     * sensor is triggered through the gears) and the end of the PTFE tube and
     * can cause filament load issues.
     */
    //#define MMU3_SPOOL_JOIN_CONSUMES_ALL_FILAMENT

    // MMU3 sequences use mm/sec. Not compatible with MMU2 which use mm/min.
    #define MMU3_LOAD_TO_NOZZLE_SEQUENCE \
      { _MMU_EXTRUDER_PTFE_LENGTH,      MMM_TO_MMS(810) }, /* (13.5 mm/s) Fast load ahead of heatbreak */ \
      { _MMU_EXTRUDER_HEATBREAK_LENGTH, MMM_TO_MMS(198) }  /* ( 3.3 mm/s) Slow load after heatbreak */

    #define MMU3_RAMMING_SEQUENCE \
      { 0.2816,  MMM_TO_MMS(1339.0) }, \
      { 0.3051,  MMM_TO_MMS(1451.0) }, \
      { 0.3453,  MMM_TO_MMS(1642.0) }, \
      { 0.3990,  MMM_TO_MMS(1897.0) }, \
      { 0.4761,  MMM_TO_MMS(2264.0) }, \
      { 0.5767,  MMM_TO_MMS(2742.0) }, \
      { 0.5691,  MMM_TO_MMS(3220.0) }, \
      { 0.1081,  MMM_TO_MMS(3220.0) }, \
      { 0.7644,  MMM_TO_MMS(3635.0) }, \
      { 0.8248,  MMM_TO_MMS(3921.0) }, \
      { 0.8483,  MMM_TO_MMS(4033.0) }, \
      { -15.0,   MMM_TO_MMS(6000.0) }, \
      { -24.5,   MMM_TO_MMS(1200.0) }, \
      {  -7.0,   MMM_TO_MMS( 600.0) }, \
      {  -3.5,   MMM_TO_MMS( 360.0) }, \
      {  20.0,   MMM_TO_MMS( 454.0) }, \
      { -20.0,   MMM_TO_MMS( 303.0) }, \
      { -35.0,   MMM_TO_MMS(2000.0) }

  #else // MMU2 (not MMU2S)

    /**
     * MMU2 Extruder Sensor
     *
     * Support for a Průša (or other) IR Sensor to detect filament near the extruder
     * and make loading more reliable. Suitable for an extruder equipped with a filament
     * sensor less than 38mm from the gears.
     *
     * During loading the extruder will stop when the sensor is triggered, then do a last
     * move up to the gears. If no filament is detected, the MMU2 can make some more attempts.
     * If all attempts fail, a filament runout will be triggered.
     */
    //#define MMU2_EXTRUDER_SENSOR
    #if ENABLED(MMU2_EXTRUDER_SENSOR)
      #define MMU2_LOADING_ATTEMPTS_NR 5  // Number of times to try loading filament before failure
    #endif

  #endif

#endif // HAS_PRUSA_MMU2 || HAS_PRUSA_MMU3

/**
 * Advanced Print Counter settings
 * @section stats
 */
#if ENABLED(PRINTCOUNTER)
  #define SERVICE_WARNING_BUZZES  3
  // Activate up to 3 service interval watchdogs
  //#define SERVICE_NAME_1      "Service S"
  //#define SERVICE_INTERVAL_1  100 // print hours
  //#define SERVICE_NAME_2      "Service L"
  //#define SERVICE_INTERVAL_2  200 // print hours
  //#define SERVICE_NAME_3      "Service 3"
  //#define SERVICE_INTERVAL_3    1 // print hours
#endif

// @section develop

//
// M100 Free Memory Watcher to debug memory usage
//
//#define M100_FREE_MEMORY_WATCHER

//
// M42 - Set pin states
//
//#define DIRECT_PIN_CONTROL

//
// M43 - display pin status, toggle pins, watch pins, watch endstops & toggle LED, test servo probe
//
//#define PINS_DEBUGGING

// Enable Tests that will run at startup and produce a report
//#define MARLIN_TEST_BUILD

// Enable Marlin dev mode which adds some special commands
//#define MARLIN_DEV_MODE

#if ENABLED(MARLIN_DEV_MODE)
  /**
   * D576 - Buffer Monitoring
   * To help diagnose print quality issues stemming from empty command buffers.
   */
  //#define BUFFER_MONITORING
#endif

/**
 * Postmortem Debugging captures misbehavior and outputs the CPU status and backtrace to serial.
 * When running in the debugger it will break for debugging. This is useful to help understand
 * a crash from a remote location. Requires ~400 bytes of SRAM and 5Kb of flash.
 */
//#define POSTMORTEM_DEBUGGING

/**
 * Software Reset options
 */
//#define SOFT_RESET_VIA_SERIAL         // 'KILL' and '^X' commands will soft-reset the controller
//#define SOFT_RESET_ON_KILL            // Use a digital button to soft-reset the controller after KILL

// Report uncleaned reset reason from register r2 instead of MCUSR. Supported by Optiboot on AVR.
//#define OPTIBOOT_RESET_REASON

// Shrink the build for smaller boards by sacrificing some serial feedback
//#define MARLIN_SMALL_BUILD
