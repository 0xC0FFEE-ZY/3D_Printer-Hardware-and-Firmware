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

————————————————————————————————————————————————前言——————————————————————————————————————————————————————————

*本工程为Marlin 2.1.3-beta3的中文翻译版本，由0xC0FFEE_ZY翻译。原版工程来自https://github.com/MarlinFirmware/Marlin
*本工程各项参数已配置完成，适用于本人自制的3D打印机（基于UM架构），
*该3D打印机设计图纸，硬件原理图，PCB已全部开源,未来预计更新制作教程至抖音/B站。
*开源项目见本人Github主页：https://github.com/0xC0FFEE-ZY
*欢迎关注本人抖音：（抖音号:Technophilic)，昵称：0xC0FFEE_ZY，里面有一些电子科技创作相关的视频，欢迎大家点赞关注！谢谢！
*B站UID:481302692，昵称：0xC0FFEE_ZY
*up为2024级本科生，热爱电子科技，欢迎和我一起进行讨论和交流！

*控制板芯片型号为STM32F407,
*步进电机采用TMC2209驱动。

    2026.5.13     By 0xC0FFEE_ZY

——————————————————————————————————————————————————————————————————————————————————————————————————————————————
*/

/**
 * Configuration.h
 *
 * Basic settings such as:   本文件基础配置如下：
 *
 * - Type of electronics   控制板型号
 * - Type of temperature sensor   温度传感器类型
 * - Printer geometry   打印机结构
 * - Endstop configuration   限位开关配置
 * - LCD controller   屏幕控制
 * - Extra features  其他功能
 *
 * Advanced settings can be found in Configuration_adv.h   高级设置可以在 Configuration_adv.h 中找到
 */
#define CONFIGURATION_H_VERSION 02010300

//===========================================================================
//============================= Getting Started =============================
//===========================================================================

/**
 * Here are some useful links to help get your machine configured and calibrated:
 * 这里有一些有用的链接，可帮助您配置和校准您的机器
 * Example Configs:     https://github.com/MarlinFirmware/Configurations/branches/all
 *
 * Průša Calculator:    https://blog.prusa3d.com/calculator_3416/
 *
 * Calibration Guides:  https://reprap.org/wiki/Calibration
 *                      https://reprap.org/wiki/Triffid_Hunter%27s_Calibration_Guide
 *                      https://web.archive.org/web/20220907014303/sites.google.com/site/repraplogphase/calibration-of-your-reprap
 *                      https://youtu.be/wAL9d7FgInk
 *                      https://teachingtechyt.github.io/calibration.html
 *
 * Calibration Objects: https://www.thingiverse.com/thing:5573
 *                      https://www.thingiverse.com/thing:1278865
 */

// @section info

// Author info of this build printed to the host during boot and M115
#define STRING_CONFIG_H_AUTHOR "(none, default config)" // Original author or contributor.
//#define CUSTOM_VERSION_FILE Version.h // Path from the root directory (no quotes)
//定义作者信息（默认无，为原版配置）
// @section machine

// Choose the name from boards.h that matches your setup   从boards.h中选择与您的设备匹配的型号

#ifndef MOTHERBOARD
  #define MOTHERBOARD BOARD_RAMPS_14_EFB
#endif

// @section serial

/**
 * Select the serial port on the board to use for communication with the host.
 * This allows the connection of wireless adapters (for instance) to non-default port pins.
 * Serial port -1 is the USB emulated serial port, if available.
 * Note: The first serial port (-1 or 0) will always be used by the Arduino bootloader.
 *
 * :[-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
 * 
 * 
 * 选择主板上用于与上位机通信的串口。
  此举可将无线适配器等设备连接到非默认端口引脚。
  串口设为 -1 代表使用USB 虚拟串口（如硬件支持）。
  注意：Arduino 引导程序将始终占用第一个串口（-1 或 0）。
 */
#define SERIAL_PORT 0

/**
 * Serial Port Baud Rate
 * This is the default communication speed for all serial ports.
 * Set the baud rate defaults for additional serial ports below.
 *
 * 250000 works in most cases, but you might try a lower speed if
 * you commonly experience drop-outs during host printing.
 * You may try up to 1000000 to speed up SD file transfer.
 *
 * :[2400, 9600, 19200, 38400, 57600, 115200, 250000, 500000, 1000000]
 * 
 * 
 * 串口波特率
  此项为所有串口的默认通信速率。
  下方可设置其他附加串口的默认波特率。
  250000 波特在绝大多数场景下均可正常使用；
  若在上位机打印过程中经常出现断连丢包，可尝试调低速率。
  如需加快 SD 卡文件传输速度，最高可设至 1000000 波特。
  可选波特率：[2400, 9600, 19200, 38400, 57600, 115200, 250000, 500000, 1000000]
 */
#define BAUDRATE 250000

//#define BAUD_RATE_GCODE     // Enable G-code M575 to set the baud rate   启用 G 代码 M575 以设置波特率

/**
 * Select a secondary serial port on the board to use for communication with the host.
 * Currently Ethernet (-2) is only supported on Teensy 4.1 boards.
 * :[-2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
 * 
 * 选择主板上用于与上位机通信的第二串口。
  目前仅 Teensy 4.1 板支持以太网串口（-2）。
  可选串口：[-2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
 */
//#define SERIAL_PORT_2 -1
//#define BAUDRATE_2 250000   // :[2400, 9600, 19200, 38400, 57600, 115200, 250000, 500000, 1000000] Enable to override BAUDRATE


/**
 * Select a third serial port on the board to use for communication with the host.
 * Currently supported for AVR, DUE, SAMD51, LPC1768/9, STM32/STM32F1/HC32, and Teensy 4.x
 * :[-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
 * 
 * 选择主板上用于与上位机通信的第三串口。
  目前支持 AVR、DUE、SAMD51、LPC1768/9、STM32/STM32F1/HC32 和 Teensy 4.x 板。
  可选串口：[-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
 */
//#define SERIAL_PORT_3 1
//#define BAUDRATE_3 250000   // :[2400, 9600, 19200, 38400, 57600, 115200, 250000, 500000, 1000000] Enable to override BAUDRATE

/**
 * Select a serial port to communicate with RS485 protocol
 * :[-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
 * 
 * 选择一个串口用于 RS485 协议通信
  可选串口：[-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
 */
//#define RS485_SERIAL_PORT 1
#ifdef RS485_SERIAL_PORT
  //#define M485_PROTOCOL 1   // Check your host for protocol compatibility   检查你的上位机是否兼容当前通信协议
  //#define RS485_BUS_BUFFER_SIZE 128
#endif

// Enable the Bluetooth serial interface on AT90USB devices   启用 AT90USB 设备上的蓝牙串口接口
//#define BLUETOOTH

// Name displayed in the LCD "Ready" message and Info menu   在液晶显示屏的就绪提示和信息菜单中显示的设备名称

//#define CUSTOM_MACHINE_NAME "3D Printer"
//#define CONFIGURABLE_MACHINE_NAME // Add G-code M550 to set/report the machine name

// Printer's unique ID, used by some programs to differentiate between machines.
// Choose your own or use a service like https://www.uuidgenerator.net/version4

//#define MACHINE_UUID "00000000-0000-0000-0000-000000000000"

// @section stepper drivers

/**
 * Stepper Drivers
 *
 * These settings allow Marlin to tune stepper driver timing and enable advanced options for
 * stepper drivers that support them. You may also override timing options in Configuration_adv.h.
 *
 * Use TMC2208/TMC2208_STANDALONE for TMC2225 drivers and TMC2209/TMC2209_STANDALONE for TMC2226 drivers.
 *
 * Options: A4988, A5984, DRV8825, LV8729, TB6560, TB6600, TMC2100,
 *          TMC2130, TMC2130_STANDALONE, TMC2160, TMC2160_STANDALONE,
 *          TMC2208, TMC2208_STANDALONE, TMC2209, TMC2209_STANDALONE,
 *          TMC2240, TMC2660, TMC2660_STANDALONE,
 *          TMC5130, TMC5130_STANDALONE, TMC5160, TMC5160_STANDALONE
 * :['A4988', 'A5984', 'DRV8825', 'LV8729', 'TB6560', 'TB6600', 'TMC2100', 'TMC2130', 'TMC2130_STANDALONE', 'TMC2160', 'TMC2160_STANDALONE', 'TMC2208', 'TMC2208_STANDALONE', 'TMC2209', 'TMC2209_STANDALONE', 'TMC2240', 'TMC2660', 'TMC2660_STANDALONE', 'TMC5130', 'TMC5130_STANDALONE', 'TMC5160', 'TMC5160_STANDALONE']
 * 
 * 
 * 步进电机驱动器
  这些设置允许 Marlin 调整步进电机驱动器的时序，并为支持的驱动器启用高级选项。
  你也可以在 Configuration_adv.h 中覆盖时序选项。

  对于 TMC2225 驱动器，使用 TMC2208/TMC2208_STANDALONE；对于 TMC2226 驱动器，使用 TMC2209/TMC2209_STANDALONE。

  可选驱动器：A4988、A5984、DRV8825、LV8729、TB6560、TB6600、TMC2100、TMC2130、TMC2130_STANDALONE、TMC2160、
  TMC2160_STANDALONE、TMC2208、TMC2208_STANDALONE、TMC2209、TMC2209_STANDALONE、TMC2240、TMC2660、
  TMC2660_STANDALONE、TMC5130、TMC5130_STANDALONE、TMC5160、TMC5160_STANDALONE

  可选列表：['A4988', 'A5984', 'DRV8825', 'LV8729', 'TB6560', 'TB6600', 'TMC2100', 
  'TMC2130', 'TMC2130_STANDALONE', 'TMC2160', 'TMC2160_STANDALONE', 'TMC2208', 
  'TMC2208_STANDALONE', 'TMC2209', 'TMC2209_STANDALONE', 'TMC2240', 'TMC2660', 
  'TMC2660_STANDALONE', 'TMC5130', 'TMC5130_STANDALONE', 'TMC5160', 'TMC5160_STANDALONE']
 */
#define X_DRIVER_TYPE  A4988
#define Y_DRIVER_TYPE  A4988
#define Z_DRIVER_TYPE  A4988
//#define X2_DRIVER_TYPE A4988
//#define Y2_DRIVER_TYPE A4988
//#define Z2_DRIVER_TYPE A4988
//#define Z3_DRIVER_TYPE A4988
//#define Z4_DRIVER_TYPE A4988
//#define I_DRIVER_TYPE  A4988
//#define J_DRIVER_TYPE  A4988
//#define K_DRIVER_TYPE  A4988
//#define U_DRIVER_TYPE  A4988
//#define V_DRIVER_TYPE  A4988
//#define W_DRIVER_TYPE  A4988
#define E0_DRIVER_TYPE A4988
//#define E1_DRIVER_TYPE A4988
//#define E2_DRIVER_TYPE A4988
//#define E3_DRIVER_TYPE A4988
//#define E4_DRIVER_TYPE A4988
//#define E5_DRIVER_TYPE A4988
//#define E6_DRIVER_TYPE A4988
//#define E7_DRIVER_TYPE A4988

/**
 * Additional Axis Settings
 *
 * Define AXISn_ROTATES for all axes that rotate or pivot.
 * Rotational axis coordinates are expressed in degrees.
 *
 * AXISn_NAME defines the letter used to refer to the axis in (most) G-code commands.
 * By convention the names and roles are typically:
 *   'A' : Rotational axis parallel to X
 *   'B' : Rotational axis parallel to Y
 *   'C' : Rotational axis parallel to Z
 *   'U' : Secondary linear axis parallel to X
 *   'V' : Secondary linear axis parallel to Y
 *   'W' : Secondary linear axis parallel to Z
 *
 * Regardless of these settings the axes are internally named I, J, K, U, V, W.
 * 
 * 额外轴设置
  定义 AXISn_ROTATES 用于所有旋转或枢轴轴。
  旋转轴坐标以度为单位表示。

  AXISn_NAME 定义了在（大多数）G 代码命令中用于引用轴的字母。
  按惯例，名称和角色通常是：
    'A' : 与 X 平行的旋转轴
    'B' : 与 Y 平行的旋转轴
    'C' : 与 Z 平行的旋转轴
    'U' : 与 X 平行的第二线性轴
    'V' : 与 Y 平行的第二线性轴
    'W' : 与 Z 平行的第二线性轴

  无论这些设置如何，轴在内部命名为 I、J、K、U、V、W。
 */
#ifdef I_DRIVER_TYPE
  #define AXIS4_NAME 'A' // :['A', 'B', 'C', 'U', 'V', 'W']
  #define AXIS4_ROTATES
#endif
#ifdef J_DRIVER_TYPE
  #define AXIS5_NAME 'B' // :['B', 'C', 'U', 'V', 'W']
  #define AXIS5_ROTATES
#endif
#ifdef K_DRIVER_TYPE
  #define AXIS6_NAME 'C' // :['C', 'U', 'V', 'W']
  #define AXIS6_ROTATES
#endif
#ifdef U_DRIVER_TYPE
  #define AXIS7_NAME 'U' // :['U', 'V', 'W']
  //#define AXIS7_ROTATES
#endif
#ifdef V_DRIVER_TYPE
  #define AXIS8_NAME 'V' // :['V', 'W']
  //#define AXIS8_ROTATES
#endif
#ifdef W_DRIVER_TYPE
  #define AXIS9_NAME 'W' // :['W']
  //#define AXIS9_ROTATES
#endif

// @section extruder

// This defines the number of extruders   此项用于定义挤出机数量
// :[0, 1, 2, 3, 4, 5, 6, 7, 8]
#define EXTRUDERS 1 //我的打印机只用了一个挤出机（远程挤出）

// Generally expected filament diameter (1.75, 2.85, 3.0, ...). Used for Volumetric, Filament Width Sensor, etc.
//常规默认耗材直径（1.75、2.85、3.0 等）。用于体积挤出、耗材宽度传感器等功能。
#define DEFAULT_NOMINAL_FILAMENT_DIA 1.75

// For Cyclops or any "multi-extruder" that shares a single nozzle.
//适用于Cyclops 挤出头或任何共用单个喷嘴的多挤出机结构。
//#define SINGLENOZZLE

// Save and restore temperature and fan speed on tool-change.
// Set standby for the unselected tool with M104/106/109 T...
// 换喷头时保存并恢复温度与风扇转速。
// 使用 M104/106/109 T... 指令为未选中的喷头设置待机状态。
#if ENABLED(SINGLENOZZLE)
  //#define SINGLENOZZLE_STANDBY_TEMP
  //#define SINGLENOZZLE_STANDBY_FAN
#endif

// A dual extruder that uses a single stepper motor   采用单个步进电机的双挤出机
//#define SWITCHING_EXTRUDER
#if ENABLED(SWITCHING_EXTRUDER)
  #define SWITCHING_EXTRUDER_SERVO_NR 0
  #define SWITCHING_EXTRUDER_SERVO_ANGLES { 0, 90 } // Angles for E0, E1[, E2, E3]
  #if EXTRUDERS > 3
    #define SWITCHING_EXTRUDER_E23_SERVO_NR 1
  #endif
#endif

// Switch extruders by bumping the toolhead. Requires EVENT_GCODE_TOOLCHANGE_#.
//通过撞击喷头实现挤出机切换。需要配合 EVENT_GCODE_TOOLCHANGE_# 配置项使用。
//#define MECHANICAL_SWITCHING_EXTRUDER

/**
 * A dual-nozzle that uses a servomotor to raise/lower one (or both) of the nozzles.
 * Can be combined with SWITCHING_EXTRUDER.
 * 采用伺服电机升降单个或两个喷嘴的双喷嘴结构。
   可与切换式挤出机（SWITCHING_EXTRUDER）组合使用。
 * 
 */
//#define SWITCHING_NOZZLE
#if ENABLED(SWITCHING_NOZZLE)
  #define SWITCHING_NOZZLE_SERVO_NR 0
  //#define SWITCHING_NOZZLE_E1_SERVO_NR 1          // If two servos are used, the index of the second
  #define SWITCHING_NOZZLE_SERVO_ANGLES { 0, 90 }   // A pair of angles for { E0, E1 }.
                                                    // For Dual Servo use two pairs: { { lower, raise }, { lower, raise } }
  #define SWITCHING_NOZZLE_SERVO_DWELL 2500         // Dwell time to wait for servo to make physical move
  #define SWITCHING_NOZZLE_LIFT_TO_PROBE            // Lift toolheads out of the way while probing
#endif

// Switch nozzles by bumping the toolhead. Requires EVENT_GCODE_TOOLCHANGE_#.
//通过碰撞工具头完成喷嘴切换。需依赖 EVENT_GCODE_TOOLCHANGE_# 事件 G 代码。
//#define MECHANICAL_SWITCHING_NOZZLE

/**
 * Two separate X-carriages with extruders that connect to a moving part
 * via a solenoid docking mechanism. Requires SOL1_PIN and SOL2_PIN.
 * 
 * 两条独立的 X 轴滑架，挤出机通过电磁铁对接机构连接到移动部件。需要 SOL1_PIN 和 SOL2_PIN。
 */
//#define PARKING_EXTRUDER

/**
 * Two separate X-carriages with extruders that connect to a moving part
 * via a magnetic docking mechanism using movements and no solenoid
 *
 * project   : https://www.thingiverse.com/thing:3080893
 * movements : https://youtu.be/0xCEiG9VS3k
 *             https://youtu.be/Bqbcs0CU2FE
 * 
 * 两条独立的 X 轴滑架，挤出机通过运动实现的磁性对接机构连接到移动部件，无需电磁铁

  项目地址：https://www.thingiverse.com/thing:3080893
  运动演示：https://youtu.be/0xCEiG9VS3k
            https://youtu.be/Bqbcs0CU2FE
 */
//#define MAGNETIC_PARKING_EXTRUDER

#if ANY(PARKING_EXTRUDER, MAGNETIC_PARKING_EXTRUDER)

  #define PARKING_EXTRUDER_PARKING_X { -78, 184 }     // X positions for parking the extruders   //挤出机停放的 X 轴位置
  #define PARKING_EXTRUDER_GRAB_DISTANCE 1            // (mm) Distance to move beyond the parking point to grab the extruder   //（毫米）在停放点之外移动以抓取挤出机的距离

  #if ENABLED(PARKING_EXTRUDER)

    #define PARKING_EXTRUDER_SOLENOIDS_INVERT           // If enabled, the solenoid is NOT magnetized with applied voltage   //如果启用，电磁铁在施加电压时不会被磁化
    #define PARKING_EXTRUDER_SOLENOIDS_PINS_ACTIVE LOW  // LOW or HIGH pin signal energizes the coil   // LOW 或 HIGH 引脚信号激励线圈
    #define PARKING_EXTRUDER_SOLENOIDS_DELAY 250        // (ms) Delay for magnetic field. No delay if 0 or not defined.   //（毫秒）磁场延迟。设置为 0 或未定义则无延迟。
    //#define MANUAL_SOLENOID_CONTROL                   // Manual control of docking solenoids with M380 S / M381   //使用 M380 S / M381 手动控制对接电磁铁

  #elif ENABLED(MAGNETIC_PARKING_EXTRUDER)

    #define MPE_FAST_SPEED      9000      // (mm/min) Speed for travel before last distance point   //（毫米/分钟）最后距离点之前的移动速度
    #define MPE_SLOW_SPEED      4500      // (mm/min) Speed for last distance travel to park and couple   //（毫米/分钟）最后距离点的移动速度，用于停放和耦合
    #define MPE_TRAVEL_DISTANCE   10      // (mm) Last distance point    //（毫米）最后距离点
    #define MPE_COMPENSATION       0      // Offset Compensation -1 , 0 , 1 (multiplier) only for coupling   //补偿 -1、0、1（乘数），仅用于耦合

  #endif

#endif

/**
 * Switching Toolhead
 *
 * Support for swappable and dockable toolheads, such as
 * the E3D Tool Changer. Toolheads are locked with a servo.
 * 
 * 支持可交换和可停靠的工具头，例如 E3D Tool Changer。工具头通过伺服电机锁定。
 */
//#define SWITCHING_TOOLHEAD

/**
 * Magnetic Switching Toolhead
 *
 * Support swappable and dockable toolheads with a magnetic
 * docking mechanism using movement and no servo.
 * 
 * 支持通过运动实现的磁性对接机构的可交换和可停靠工具头，无需伺服电机。
 */
//#define MAGNETIC_SWITCHING_TOOLHEAD

/**
 * Electromagnetic Switching Toolhead
 *
 * Parking for CoreXY / HBot kinematics.
 * Toolheads are parked at one edge and held with an electromagnet.
 * Supports more than 2 Toolheads. See https://youtu.be/JolbsAKTKf4
 * 
 * 适用于 CoreXY / HBot 运动学的停靠。工具头停放在一侧，并通过电磁铁固定。支持多于 2 个工具头。详见 https://youtu.be/JolbsAKTKf4
 */
//#define ELECTROMAGNETIC_SWITCHING_TOOLHEAD

#if ANY(SWITCHING_TOOLHEAD, MAGNETIC_SWITCHING_TOOLHEAD, ELECTROMAGNETIC_SWITCHING_TOOLHEAD)
  #define SWITCHING_TOOLHEAD_Y_POS          235         // (mm) Y position of the toolhead dock  //工具头停靠的 Y 轴位置
  #define SWITCHING_TOOLHEAD_Y_SECURITY      10         // (mm) Security distance Y axis   // Y 轴安全距离
  #define SWITCHING_TOOLHEAD_Y_CLEAR         60         // (mm) Minimum distance from dock for unobstructed X axis   //（毫米）停靠处无障碍 X 轴的最小距离
  #define SWITCHING_TOOLHEAD_X_POS          { 215, 0 }  // (mm) X positions for parking the extruders   //挤出机停放的 X 轴位置
  #if ENABLED(SWITCHING_TOOLHEAD)
    #define SWITCHING_TOOLHEAD_SERVO_NR       2         // Index of the servo connector   //伺服连接器的索引
    #define SWITCHING_TOOLHEAD_SERVO_ANGLES { 0, 180 }  // (degrees) Angles for Lock, Unlock   //（度）锁定、解锁的角度
  #elif ENABLED(MAGNETIC_SWITCHING_TOOLHEAD)
    #define SWITCHING_TOOLHEAD_Y_RELEASE      5         // (mm) Security distance Y axis   // Y 轴安全距离
    #define SWITCHING_TOOLHEAD_X_SECURITY   { 90, 150 } // (mm) Security distance X axis (T0,T1)   // X 轴安全距离（T0、T1）
    //#define PRIME_BEFORE_REMOVE                       // Prime the nozzle before release from the dock   //在从停靠处释放之前为喷嘴预挤出
    #if ENABLED(PRIME_BEFORE_REMOVE)
      #define SWITCHING_TOOLHEAD_PRIME_MM           20  // (mm)   Extruder prime length     //挤出机预挤出长度
      #define SWITCHING_TOOLHEAD_RETRACT_MM         10  // (mm)   Retract after priming length   //预挤出后回抽长度
      #define SWITCHING_TOOLHEAD_PRIME_FEEDRATE    300  // (mm/min) Extruder prime feedrate   //挤出机预挤出进给速度
      #define SWITCHING_TOOLHEAD_RETRACT_FEEDRATE 2400  // (mm/min) Extruder retract feedrate   //挤出机回抽进给速度
    #endif
  #elif ENABLED(ELECTROMAGNETIC_SWITCHING_TOOLHEAD)
    #define SWITCHING_TOOLHEAD_Z_HOP          2         // (mm) Z raise for switching   //（毫米）切换时 Z 轴提升高度
  #endif
#endif

/**
 * "Mixing Extruder"
 *   - Adds G-codes M163 and M164 to set and "commit" the current mix factors.
 *   - Extends the stepping routines to move multiple steppers in proportion to the mix.
 *   - Optional support for Repetier Firmware's 'M164 S<index>' supporting virtual tools.
 *   - This implementation supports up to two mixing extruders.
 *   - Enable DIRECT_MIXING_IN_G1 for M165 and mixing in G1 (from Pia Taubert's reference implementation).
 * 
 *  "混合挤出机"
  - 添加 G 代码 M163 和 M164 来设置和“提交”当前的混合因子。
  - 扩展步进程序以按比例移动多个步进电机以实现混合。
  - 可选支持 Repetier
 */
//#define MIXING_EXTRUDER
#if ENABLED(MIXING_EXTRUDER)
  #define MIXING_STEPPERS 2        // Number of steppers in your mixing extruder  //混合挤出机中的步进电机数量
  #define MIXING_VIRTUAL_TOOLS 16  // Use the Virtual Tool method with M163 and M164  //使用 M163 和 M164 的虚拟工具方法
  //#define DIRECT_MIXING_IN_G1    // Allow ABCDHI mix factors in G1 movement commands  //允许在 G1 移动命令中使用 ABCDHI 混合因子
  //#define GRADIENT_MIX           // Support for gradient mixing with M166 and LCD  //支持使用 M166 和 LCD 的渐变混合
  //#define MIXING_PRESETS         // Assign 8 default V-tool presets for 2 or 3 MIXING_STEPPERS  //为 2 或 3 个 MIXING_STEPPERS 分配 8 个默认 V 工具预设
  #if ENABLED(GRADIENT_MIX)
    //#define GRADIENT_VTOOL       // Add M166 T to use a V-tool index as a Gradient alias  //添加 M166 T 以使用 V 工具索引作为渐变别名
  #endif
#endif

// Offset of the extruders (uncomment if using more than one and relying on firmware to position when changing).
// The offset has to be X=0, Y=0 for the extruder 0 hotend (default extruder).
// For the other hotends it is their distance from the extruder 0 hotend.
// 挤出机偏移量（若使用多挤出机且依赖固件在换刀时自动定位，请取消注释）
// 挤出机 0（默认挤出机）的热端偏移量必须设置为 X=0、Y=0。
// 其余热端的偏移量为其相对于挤出机 0 热端的距离。

//#define HOTEND_OFFSET_X { 0.0, 20.00 } // (mm) relative X-offset for each nozzle  
//#define HOTEND_OFFSET_Y { 0.0, 5.00 }  // (mm) relative Y-offset for each nozzle  
//#define HOTEND_OFFSET_Z { 0.0, 0.00 }  // (mm) relative Z-offset for each nozzle  
// @section multi-material

/**
 * Multi-Material Unit
 * Set to one of these predefined models:
 *
 *   PRUSA_MMU1           : Průša MMU1 (The "multiplexer" version)
 *   PRUSA_MMU2           : Průša MMU2
 *   PRUSA_MMU2S          : Průša MMU2S (Requires MK3S extruder with motion sensor, EXTRUDERS = 5)
 *   PRUSA_MMU3           : Průša MMU3  (Requires MK3S extruder with motion sensor and MMU firmware version 3.x.x, EXTRUDERS = 5)
 *   EXTENDABLE_EMU_MMU2  : MMU with configurable number of filaments (ERCF, SMuFF or similar with Průša MMU2 compatible firmware)
 *   EXTENDABLE_EMU_MMU2S : MMUS with configurable number of filaments (ERCF, SMuFF or similar with Průša MMU2 compatible firmware)
 *
 * Requires NOZZLE_PARK_FEATURE to park print head in case MMU unit fails.
 * See additional options in Configuration_adv.h.
 * :["PRUSA_MMU1", "PRUSA_MMU2", "PRUSA_MMU2S", "PRUSA_MMU3", "EXTENDABLE_EMU_MMU2", "EXTENDABLE_EMU_MMU2S"]
 * 
 * 多材料单元
  设置为以下预定义型号之一：

  PRUSA_MMU1           : Průša MMU1（“多路复用器”版本）
  PRUSA_MMU2           : Průša MMU2
  PRUSA_MMU2S          : Průša MMU2S（需要带有运动传感器的 MK3S 挤出机，EXTRUDERS = 5）
  PRUSA_MMU3           : Průša MMU3（需要带有运动传感器和 MMU 固件版本 3.x.x 的 MK3S 挤出机，EXTRUDERS = 5）
  EXTENDABLE_EMU_MMU2  : 配置可调节数量的耗材的 MMU（ERCF、SMuFF 或类似具有 Průša MMU2 兼容固件的设备）
  EXTENDABLE_EMU_MMU2S : 配置可调节数量的耗材的 MMUS（ERCF、SMuFF 或类似具有 Průša MMU2 兼容固件的设备）

  在 MMU 单元发生故障时，需要 NOZZLE_PARK_FEATURE 来停放打印头。
  更多选项请参见 Configuration_adv.h。
 */
//#define MMU_MODEL PRUSA_MMU3

// @section psu control

/**
 * Power Supply Control
 *
 * Enable and connect the power supply to the PS_ON_PIN.
 * Specify whether the power supply is active HIGH or active LOW.
 * 
 * 电源控制
  启用并将电源连接到 PS_ON_PIN。
  指定电源是高电平有效还是低电平有效。
 */
//#define PSU_CONTROL
//#define PSU_NAME "Power Supply"

#if ENABLED(PSU_CONTROL)
  //#define MKS_PWC                 // Using the MKS PWC add-on  //使用 MKS PWC 附加模块
  //#define PS_OFF_CONFIRM          // Confirm dialog when power off  //电源关闭时的确认对话框
  //#define PS_OFF_SOUND            // Beep 1s when power off  //电源关闭时蜂鸣 1 秒
  #define PSU_ACTIVE_STATE LOW      // Set 'LOW' for ATX, 'HIGH' for X-Box  //ATX 电源设置为 'LOW'，X-Box 电源设置为 'HIGH'

  //#define PSU_DEFAULT_OFF             // Keep power off until enabled directly with M80  //保持电源关闭，直到直接使用 M80 启用
  //#define PSU_POWERUP_DELAY      250  // (ms) Delay for the PSU to warm up to full power  //（毫秒）PSU 加热到全功率的延迟
  //#define LED_POWEROFF_TIMEOUT 10000  // (ms) Turn off LEDs after power-off, with this amount of delay  //（毫秒）电源关闭后关闭 LED 的延迟时间

  //#define PSU_OFF_REDUNDANT           // Second pin for redundant power control  //冗余电源控制的第二个引脚
  //#define PSU_OFF_REDUNDANT_INVERTED  // Redundant pin state is the inverse of PSU_ACTIVE_STATE  //冗余引脚状态与 PSU_ACTIVE_STATE 相反

  //#define PS_ON1_PIN               6  // Redundant pin required to enable power in combination with PS_ON_PIN  //与 PS_ON_PIN 组合使用时需要冗余引脚以启用电源

  //#define PS_ON_EDM_PIN            8  // External Device Monitoring pins for external power control relay feedback. Fault on mismatch.  //外部设备监控引脚，用于外部电源控制继电器反馈。不匹配时发生故障。
  //#define PS_ON1_EDM_PIN           9
  #define PS_EDM_RESPONSE          250  // (ms) Time to allow for relay action  //（毫秒）允许继电器动作的时间

  //#define POWER_OFF_TIMER               // Enable M81 D<seconds> to power off after a delay  //启用 M81 D<seconds> 以在延迟后关闭电源
  //#define POWER_OFF_WAIT_FOR_COOLDOWN   // Enable M81 S to power off only after cooldown   //启用 M81 S 以仅在冷却后关闭电源

  //#define PSU_POWERUP_GCODE  "M355 S1"  // G-code to run after power-on (e.g., case light on)  //电源开启后要运行的 G 代码（例如，打开机箱灯）
  //#define PSU_POWEROFF_GCODE "M355 S0"  // G-code to run before power-off (e.g., case light off)  //电源关闭前要运行的 G 代码（例如，关闭机箱灯）

  //#define AUTO_POWER_CONTROL      // Enable automatic control of the PS_ON pin  //启用 PS_ON 引脚的自动控制
  #if ENABLED(AUTO_POWER_CONTROL)
    #define AUTO_POWER_FANS           // Turn on PSU for fans    // 开启电源模块为风扇供电
    #define AUTO_POWER_E_FANS         // Turn on PSU for E Fans  //开启电源模块为挤出机风扇供电
    #define AUTO_POWER_CONTROLLERFAN  // Turn on PSU for Controller Fan  //开启电源模块为控制器风扇供电
    #define AUTO_POWER_CHAMBER_FAN    // Turn on PSU for Chamber Fan  //开启电源模块为机箱风扇供电
    #define AUTO_POWER_COOLER_FAN     // Turn on PSU for Cooler Fan  //开启电源模块为冷却风扇供电
    #define AUTO_POWER_SPINDLE_LASER  // Turn on PSU for Spindle/Laser  //开启电源模块为主轴/激光供电
    #define POWER_TIMEOUT              30 // (s) Turn off power if the machine is idle for this duration  //（秒）如果机器空闲超过此时间则关闭电源
    //#define POWER_OFF_DELAY          60 // (s) Delay of poweroff after M81 command. Useful to let fans run for extra time.  //（秒）M81 命令后关闭电源的延迟。用于让风扇额外运行一段时间。
  #endif
  #if ANY(AUTO_POWER_CONTROL, POWER_OFF_WAIT_FOR_COOLDOWN)
    //#define AUTO_POWER_E_TEMP        50 // (°C) PSU on if any extruder is over this temperature  //（°C）如果任何挤出机超过此温度则开启电源模块
    //#define AUTO_POWER_CHAMBER_TEMP  30 // (°C) PSU on if the chamber is over this temperature  //（°C）如果机箱超过此温度则开启电源模块
    //#define AUTO_POWER_COOLER_TEMP   26 // (°C) PSU on if the cooler is over this temperature  //（°C）如果冷却器超过此温度则开启电源模块
  #endif
#endif

//===========================================================================
//============================= Thermal Settings ============================
//===========================================================================
// @section temperature

/**
 * Temperature Sensors:
 *
 * NORMAL IS 4.7kΩ PULLUP! Hotend sensors can use 1kΩ pullup with correct resistor and table.
 * 默认配置为 4.7kΩ 上拉电阻！热端传感器若搭配正确的电阻与测温表，可使用 1kΩ 上拉电阻。
 *
 * ================================================================
 *  Analog Thermistors - 4.7kΩ pullup - Normal
 * ================================================================
 *     1 : 100kΩ EPCOS - Best choice for EPCOS thermistors
 *   331 : 100kΩ Same as #1, but 3.3V scaled for MEGA
 *   332 : 100kΩ Same as #1, but 3.3V scaled for DUE
 *     2 : 200kΩ ATC Semitec 204GT-2
 *   202 : 200kΩ Copymaster 3D
 *     3 : ???Ω  Mendel-parts thermistor
 *     4 : 10kΩ  Generic Thermistor !! DO NOT use for a hotend - it gives bad resolution at high temp. !!
 *     5 : 100kΩ ATC Semitec 104GT-2/104NT-4-R025H42G - Used in ParCan, J-Head, and E3D, SliceEngineering 300°C
 *   501 : 100kΩ Zonestar - Tronxy X3A
 *   502 : 100kΩ Zonestar - used by hot bed in Zonestar Průša P802M
 *   503 : 100kΩ Zonestar (Z8XM2) Heated Bed thermistor
 *   504 : 100kΩ Zonestar P802QR2 (Part# QWG-104F-B3950) Hotend Thermistor
 *   505 : 100kΩ Zonestar P802QR2 (Part# QWG-104F-3950) Bed Thermistor
 *   512 : 100kΩ RPW-Ultra hotend
 *     6 : 100kΩ EPCOS - Not as accurate as table #1 (created using a fluke thermocouple)
 *     7 : 100kΩ Honeywell 135-104LAG-J01
 *    71 : 100kΩ Honeywell 135-104LAF-J01
 *     8 : 100kΩ Vishay 0603 SMD NTCS0603E3104FXT
 *     9 : 100kΩ GE Sensing AL03006-58.2K-97-G1
 *    10 : 100kΩ RS PRO 198-961
 *    11 : 100kΩ Keenovo AC silicone mats, most Wanhao i3 machines - beta 3950, 1%
 *    12 : 100kΩ Vishay 0603 SMD NTCS0603E3104FXT (#8) - calibrated for Makibox hot bed
 *    13 : 100kΩ Hisens up to 300°C - for "Simple ONE" & "All In ONE" hotend - beta 3950, 1%
 *    14 : 100kΩ  (R25), 4092K (beta25), 4.7kΩ pull-up, bed thermistor as used in Ender-5 S1
 *    15 : 100kΩ Calibrated for JGAurora A5 hotend
 *    17 : 100kΩ Dagoma NTC white thermistor
 *    18 : 200kΩ ATC Semitec 204GT-2 Dagoma.Fr - MKS_Base_DKU001327
 *    22 : 100kΩ GTM32 Pro vB - hotend - 4.7kΩ pullup to 3.3V and 220Ω to analog input
 *    23 : 100kΩ GTM32 Pro vB - bed - 4.7kΩ pullup to 3.3v and 220Ω to analog input
 *    30 : 100kΩ Kis3d Silicone heating mat 200W/300W with 6mm precision cast plate (EN AW 5083) NTC100K - beta 3950
 *    60 : 100kΩ Maker's Tool Works Kapton Bed Thermistor - beta 3950
 *    61 : 100kΩ Formbot/Vivedino 350°C Thermistor - beta 3950
 *    66 : 4.7MΩ Dyze Design / Trianglelab T-D500 500°C High Temperature Thermistor
 *    67 : 500kΩ SliceEngineering 450°C Thermistor
 *    68 : PT100 Smplifier board from Dyze Design
 *    70 : 100kΩ bq Hephestos 2
 *    75 : 100kΩ Generic Silicon Heat Pad with NTC100K MGB18-104F39050L32
 *   666 : 200kΩ Einstart S custom thermistor with 10k pullup.
 *  2000 : 100kΩ Ultimachine Rambo TDK NTCG104LH104KT1 NTC100K motherboard Thermistor  
 * 
 * *     1 : 100kΩ EPCOS - EPCOS热敏电阻的最佳选型
*   331 : 100kΩ 与1号参数相同，适配MEGA主板3.3V分压
*   332 : 100kΩ 与1号参数相同，适配DUE主板3.3V分压
*     2 : 200kΩ ATC Semitec 204GT-2
*   202 : 200kΩ Copymaster 3D
*     3 : ???Ω  Mendel-parts 热敏电阻
*     4 : 10kΩ  通用热敏电阻！！禁止用于热端 - 高温段分辨率极差！！
*     5 : 100kΩ ATC Semitec 104GT-2/104NT-4-R025H42G - 用于ParCan、J-Head、E3D热端，SliceEngineering 300℃测温
*   501 : 100kΩ Zonestar - Tronxy X3A
*   502 : 100kΩ Zonestar - 用于Zonestar Průša P802M热床
*   503 : 100kΩ Zonestar (Z8XM2) 热床热敏电阻
*   504 : 100kΩ Zonestar P802QR2 (型号QWG-104F-B3950) 热端热敏电阻
*   505 : 100kΩ Zonestar P802QR2 (型号QWG-104F-3950) 热床热敏电阻
*   512 : 100kΩ RPW-Ultra 热端
*     6 : 100kΩ EPCOS - 精度低于1号表（基于福禄克热电偶校准）
*     7 : 100kΩ 霍尼韦尔 135-104LAG-J01
*    71 : 100kΩ 霍尼韦尔 135-104LAF-J01
*     8 : 100kΩ 威世 0603 贴片 NTCS0603E3104FXT
*     9 : 100kΩ 通用电气传感 AL03006-58.2K-97-G1
*    10 : 100kΩ RS PRO 198-961
*    11 : 100kΩ Keenovo交流硅胶加热垫、多数Wanhao i3机型 - B值3950，精度1%
*    12 : 100kΩ 威世 0603 贴片 NTCS0603E3104FXT（8号）- Makibox热床专用校准参数
*    13 : 100kΩ Hisens 耐高温300℃ - 用于"Simple ONE"和"All In ONE"热端 - B值3950，精度1%
*    14 : 100kΩ (25℃阻值)、4092K (25℃B值)、4.7kΩ上拉电阻 - 创想Ender-5 S1热床热敏电阻
*    15 : 100kΩ JGAurora A5热端专用校准参数
*    17 : 100kΩ Dagoma 白色NTC热敏电阻
*    18 : 200kΩ ATC Semitec 204GT-2 Dagoma.Fr - MKS_Base_DKU001327
*    22 : 100kΩ GTM32 Pro vB 主板 - 热端 - 3.3V 4.7kΩ上拉+模拟输入220Ω限流
*    23 : 100kΩ GTM32 Pro vB 主板 - 热床 - 3.3V 4.7kΩ上拉+模拟输入220Ω限流
*    30 : 100kΩ Kis3d 200W/300W硅胶加热垫（6mm精铸铝板EN AW 5083）NTC100K - B值3950
*    60 : 100kΩ Maker's Tool Works  Kapton热床热敏电阻 - B值3950
*    61 : 100kΩ Formbot/Vivedino 350℃热敏电阻 - B值3950
*    66 : 4.7MΩ Dyze Design / 三角翼 T-D500 500℃高温热敏电阻
*    67 : 500kΩ SliceEngineering 450℃热敏电阻
*    68 : PT100 放大板（Dyze Design出品）
*    70 : 100kΩ bq Hephestos 2
*    75 : 100kΩ 通用硅胶加热垫，搭配NTC100K MGB18-104F39050L32
*   666 : 200kΩ Einstart S 定制热敏电阻（10k上拉电阻）
*  2000 : 100kΩ Ultimachine Rambo 主板 TDK NTCG104LH104KT1 NTC100K 主板热敏电阻
 *  
 *
 * ================================================================
 *  Analog Thermistors - 1kΩ pullup
 *   Atypical, and requires changing out the 4.7kΩ pullup for 1kΩ.
 *   (but gives greater accuracy and more stable PID)
 * 
 * 模拟热敏电阻 - 1kΩ 上拉电阻
   非标准配置，需将 4.7kΩ 上拉电阻更换为 1kΩ。
   但能提升测温精度并让PID调节更稳定）
 * ================================================================
 *    51 : 100kΩ EPCOS (1kΩ pullup)
 *    52 : 200kΩ ATC Semitec 204GT-2 (1kΩ pullup)
 *    55 : 100kΩ ATC Semitec 104GT-2 - Used in ParCan & J-Head (1kΩ pullup)
 *
 *    51 : 100kΩ EPCOS 热敏电阻（1kΩ 上拉电阻）
      52 : 200kΩ ATC Semitec 204GT-2 热敏电阻（1kΩ 上拉电阻）
      55 : 100kΩ ATC Semitec 104GT-2 热敏电阻 - 用于 ParCan 和 J-Head 热端（1kΩ 上拉电阻）
 * ================================================================
 *  Analog Thermistors - 10kΩ pullup - Atypical    模拟热敏电阻 - 10kΩ 上拉电阻 - 非标准配置
 * ================================================================
 *    99 : 100kΩ Found on some Wanhao i3 machines with a 10kΩ pull-up resistor
 *    99 : 100kΩ  见于部分万好i3机型，搭配10kΩ上拉电阻
 * ================================================================
 *  Analog RTDs (Pt100/Pt1000)
 * ================================================================
 *   110 : Pt100  with 1kΩ pullup (atypical)
 *   147 : Pt100  with 4.7kΩ pullup
 *  1010 : Pt1000 with 1kΩ pullup (atypical)
 *  1022 : Pt1000 with 2.2kΩ pullup
 *  1047 : Pt1000 with 4.7kΩ pullup (E3D)
 *    20 : Pt100  with circuit in the Ultimainboard V2.x with mainboard ADC reference voltage = INA826 amplifier-board supply voltage.
 *                NOTE: (1) Must use an ADC input with no pullup. (2) Some INA826 amplifiers are unreliable at 3.3V so consider using sensor 147, 110, or 21.
 *    21 : Pt100  with circuit in the Ultimainboard V2.x with 3.3v ADC reference voltage (STM32, LPC176x....) and 5V INA826 amplifier board supply.
 *                NOTE: ADC pins are not 5V tolerant. Not recommended because it's possible to damage the CPU by going over 500°C.
 *   201 : Pt100  with circuit in Overlord, similar to Ultimainboard V2.x
 *
 * ================================================================
 *  SPI RTD/Thermocouple Boards
 * ================================================================
 *    -5 : MAX31865 with Pt100/Pt1000, 2, 3, or 4-wire  (only for sensors 0-2 and bed)
 *                  NOTE: You must uncomment/set the MAX31865_*_OHMS_n defines below.
 *    -3 : MAX31855 with Thermocouple, -200°C to +700°C (only for sensors 0-2 and bed)
 *    -2 : MAX6675  with Thermocouple, 0°C to +700°C    (only for sensors 0-2 and bed)
 *
 *  NOTE: Ensure TEMP_n_CS_PIN is set in your pins file for each TEMP_SENSOR_n using an SPI Thermocouple. By default,
 *        Hardware SPI on the default serial bus is used. If you have also set TEMP_n_SCK_PIN and TEMP_n_MISO_PIN,
 *        Software SPI will be used on those ports instead. You can force Hardware SPI on the default bus in the
 *        Configuration_adv.h file. At this time, separate Hardware SPI buses for sensors are not supported.
 *
 * ================================================================
 *  Analog Thermocouple Boards   模拟热电偶转接板
 * ================================================================
 *    -4 : AD8495 with Thermocouple
 *    -1 : AD595  with Thermocouple
 * 
 *    -4 : AD8495 热电偶转接板
      -1 : AD595  热电偶转接板
 *
 * ================================================================
 *  SoC internal sensor   SoC 内部传感器
 * ================================================================
 *   100 : SoC internal sensor  
 *
 * ================================================================
 *  Custom/Dummy/Other Thermal Sensors
 * ================================================================
 *     0 : not used
 *  1000 : Custom - Specify parameters in Configuration_adv.h
 *
 *   !!! Use these for Testing or Development purposes. NEVER for production machine. !!!
 *   998 : Dummy Table that ALWAYS reads 25°C or the temperature defined below.
 *   999 : Dummy Table that ALWAYS reads 100°C or the temperature defined below.
 *  !!! 仅用于测试或开发目的。切勿用于生产机器！！！
    998 : 始终读取 25°C 或下方定义的温度的虚拟表。
    999 : 始终读取 100°C 或下方定义的温度的虚拟表。
 */
#define TEMP_SENSOR_0 1
#define TEMP_SENSOR_1 0
#define TEMP_SENSOR_2 0
#define TEMP_SENSOR_3 0
#define TEMP_SENSOR_4 0
#define TEMP_SENSOR_5 0
#define TEMP_SENSOR_6 0
#define TEMP_SENSOR_7 0
#define TEMP_SENSOR_BED 1
#define TEMP_SENSOR_PROBE 0
#define TEMP_SENSOR_CHAMBER 0
#define TEMP_SENSOR_COOLER 0
#define TEMP_SENSOR_BOARD 0
#define TEMP_SENSOR_SOC 0
#define TEMP_SENSOR_REDUNDANT 0

// Dummy thermistor constant temperature readings, for use with 998 and 999   // 虚拟热敏电阻恒温读数，供 998 和 999 型号使用
#define DUMMY_THERMISTOR_998_VALUE  25
#define DUMMY_THERMISTOR_999_VALUE 100

// Resistor values when using MAX31865 sensors (-5) on TEMP_SENSOR_0 / 1 / 2 / BED
// 在 TEMP_SENSOR_0 / 1 / 2 / BED 上使用 MAX31865 传感器（型号-5）时的电阻值配置
#if TEMP_SENSOR_IS_MAX_TC(0)
  #define MAX31865_SENSOR_OHMS_0      100 // (Ω) Typically 100 or 1000 (PT100 or PT1000)  // (Ω) 通常为 100 或 1000（对应 PT100 或 PT1000 传感器）
  #define MAX31865_CALIBRATION_OHMS_0 430 // (Ω) Typically 430 for Adafruit PT100; 4300 for Adafruit PT1000  // (Ω) Adafruit PT100 通常为 430；Adafruit PT1000 通常为 4300
#endif
#if TEMP_SENSOR_IS_MAX_TC(1)
  #define MAX31865_SENSOR_OHMS_1      100
  #define MAX31865_CALIBRATION_OHMS_1 430
#endif
#if TEMP_SENSOR_IS_MAX_TC(2)
  #define MAX31865_SENSOR_OHMS_2      100
  #define MAX31865_CALIBRATION_OHMS_2 430
#endif
#if TEMP_SENSOR_IS_MAX_TC(BED)
  #define MAX31865_SENSOR_OHMS_BED      100
  #define MAX31865_CALIBRATION_OHMS_BED 430
#endif

#if HAS_E_TEMP_SENSOR
  #define TEMP_RESIDENCY_TIME         10  // (seconds) Time to wait for hotend to "settle" in M109  // (秒) M109 指令中等待热端温度稳定的延时时间
  #define TEMP_WINDOW                  1  // (°C) Temperature proximity for the "temperature reached" timer  // (°C) “温度达到”计时器的温度接近度
  #define TEMP_HYSTERESIS              3  // (°C) Temperature proximity considered "close enough" to the target  // (°C) 被认为“足够接近”目标的温度接近度
#endif

#if TEMP_SENSOR_BED
  #define TEMP_BED_RESIDENCY_TIME     10  // (seconds) Time to wait for bed to "settle" in M190  // (秒) M190 指令中等待热床温度稳定的延时时间
  #define TEMP_BED_WINDOW              1  // (°C) Temperature proximity for the "temperature reached" timer  // (°C) “温度达到”计时器的温度接近度
  #define TEMP_BED_HYSTERESIS          3  // (°C) Temperature proximity considered "close enough" to the target  // (°C) 被认为“足够接近”目标的温度接近度
#endif

#if TEMP_SENSOR_CHAMBER
  #define TEMP_CHAMBER_RESIDENCY_TIME 10  // (seconds) Time to wait for chamber to "settle" in M191  // (秒) M191 指令中等待机箱温度稳定的延时时间
  #define TEMP_CHAMBER_WINDOW          1  // (°C) Temperature proximity for the "temperature reached" timer  // (°C) “温度达到”计时器的温度接近度
  #define TEMP_CHAMBER_HYSTERESIS      3  // (°C) Temperature proximity considered "close enough" to the target  // (°C) 被认为“足够接近”目标的温度接近度
#endif

/**
 * Redundant Temperature Sensor (TEMP_SENSOR_REDUNDANT)
 *
 * Use a temp sensor as a redundant sensor for another reading. Select an unused temperature sensor, and another
 * sensor you'd like it to be redundant for. If the two thermistors differ by TEMP_SENSOR_REDUNDANT_MAX_DIFF (°C),
 * the print will be aborted. Whichever sensor is selected will have its normal functions disabled; i.e. selecting
 * the Bed sensor (-1) will disable bed heating/monitoring.
 *
 * For selecting source/target use: COOLER, PROBE, BOARD, CHAMBER, BED, E0, E1, E2, E3, E4, E5, E6, E7
 * 
 * 冗余温度传感器（TEMP_SENSOR_REDUNDANT）
  使用一个温度传感器作为另一个读数的冗余传感器。选择一个未使用的温度传感器，以及另一个你希望它冗余的传感器。
  如果两个热敏电阻的温度差异超过 TEMP_SENSOR_REDUNDANT_MAX_DIFF（°C），打印将被中止。
  无论选择哪个传感器，都将禁用其正常功能；例如，选择床传感器（-1）将禁用床加热/监测。
 */
#if TEMP_SENSOR_REDUNDANT
  #define TEMP_SENSOR_REDUNDANT_SOURCE    E1  // The sensor that will provide the redundant reading.  // 将提供冗余读数的传感器。
  #define TEMP_SENSOR_REDUNDANT_TARGET    E0  // The sensor that we are providing a redundant reading for.  // 我们正在为其提供冗余读数的传感器。
  #define TEMP_SENSOR_REDUNDANT_MAX_DIFF  10  // (°C) Temperature difference that will trigger a print abort.  //（°C）将触发打印中止的温度差异。
#endif

// Below this temperature the heater will be switched off
// because it probably indicates a broken thermistor wire.
// 低于该温度时，加热器将自动关闭
// 因为这种情况通常表明热敏电阻线路断路。
#define HEATER_0_MINTEMP   5
#define HEATER_1_MINTEMP   5
#define HEATER_2_MINTEMP   5
#define HEATER_3_MINTEMP   5
#define HEATER_4_MINTEMP   5
#define HEATER_5_MINTEMP   5
#define HEATER_6_MINTEMP   5
#define HEATER_7_MINTEMP   5
#define BED_MINTEMP        5
#define CHAMBER_MINTEMP    5

// Above this temperature the heater will be switched off.
// This can protect components from overheating, but NOT from shorts and failures.
// (Use MINTEMP for thermistor short/failure protection.)
// 高于该温度时，加热器将自动关闭。
// 可保护元件免受过热损坏，但无法防护短路与故障。
// （使用 MINTEMP 实现热敏电阻短路/故障保护。）
#define HEATER_0_MAXTEMP 275
#define HEATER_1_MAXTEMP 275
#define HEATER_2_MAXTEMP 275
#define HEATER_3_MAXTEMP 275
#define HEATER_4_MAXTEMP 275
#define HEATER_5_MAXTEMP 275
#define HEATER_6_MAXTEMP 275
#define HEATER_7_MAXTEMP 275
#define BED_MAXTEMP      150
#define CHAMBER_MAXTEMP  60

/**
 * Thermal Overshoot
 * During heatup (and printing) the temperature can often "overshoot" the target by many degrees
 * (especially before PID tuning). Setting the target temperature too close to MAXTEMP guarantees
 * a MAXTEMP shutdown! Use these values to forbid temperatures being set too close to MAXTEMP.
 * 
 * 热过冲
  在加热（和打印）过程中，温度通常会超过目标温度很多度（尤其是在 PID 调整之前）。
  将目标温度设置得太接近 MAXTEMP 会导致 MAXTEMP 关机！使用这些值禁止将温度设置得过于接近 MAXTEMP。
 */
#define HOTEND_OVERSHOOT 15   // (°C) Forbid temperatures over MAXTEMP - OVERSHOOT  //（°C）禁止设置超过 MAXTEMP - OVERSHOOT 的温度
#define BED_OVERSHOOT    10   // (°C) Forbid temperatures over MAXTEMP - OVERSHOOT  //（°C）禁止设置超过 MAXTEMP - OVERSHOOT 的温度
#define COOLER_OVERSHOOT  2   // (°C) Forbid temperatures closer than OVERSHOOT  //（°C）禁止设置接近 OVERSHOOT 的温度

//===========================================================================
//============================= PID Settings ================================
//===========================================================================
//PID参数设置

// @section hotend temp

/**
 * Temperature Control
 *
 *  (NONE) : Bang-bang heating
 * PIDTEMP : PID temperature control (~4.1K)
 * MPCTEMP : Predictive Model temperature control. (~1.8K without auto-tune)
 * 
 * 温度控制
  (NONE) : 开/关加热
  PIDTEMP : PID 温度控制（约占用4.1K字节）
  MPCTEMP : 预测模型温度控制（无自动调节时约占用1.8K字节）
 */
#define PIDTEMP           // See the PID Tuning Guide at https://reprap.org/wiki/PID_Tuning  // 参阅PID调参指南，网址：https://reprap.org/wiki/PID_Tuning
//#define MPCTEMP         // See https://marlinfw.org/docs/features/model_predictive_control.html  // 参阅：https://marlinfw.org/docs/features/model_predictive_control.html

#define PID_MAX  255      // Limit hotend current while PID is active (see PID_FUNCTIONAL_RANGE below); 255=full current  // PID激活时限制热端电流（见下文PID_FUNCTIONAL_RANGE）；255=全电流
#define PID_K1     0.95   // Smoothing factor within any PID loop  // PID循环内的平滑因子

#if ENABLED(PIDTEMP)
  //#define MIN_POWER 0           // Min power to improve PID stability (0..PID_MAX).  // 提升PID稳定性的最小功率输出（取值范围：0 到 PID_MAX）
                                  // Get the power from the temperature report ('M105' => @:nnn) and try P*2-20 to P*2-10.  // 从温度反馈指令中获取功率值（'M105' => @:nnn），尝试将P值设为 当前功率值×2-20 至 当前功率值×2-10 区间。
  //#define PID_DEBUG             // Print PID debug data to the serial port. Use 'M303 D' to enable/disable.  // 将PID调试数据打印到串口。使用 'M303 D' 命令启用/禁用。
  //#define PID_PARAMS_PER_HOTEND // Use separate PID parameters for each extruder (useful for mismatched extruders)  // 为每个挤出机使用单独的PID参数（适用于不匹配的挤出机）
                                  // Set/get with G-code: M301 E[extruder number, 0-2]  // 使用G-code设置/获取：M301 E[挤出机编号，0-2] P[KP] I[KI] D[KD]

  #if ENABLED(PID_PARAMS_PER_HOTEND)
    // Specify up to one value per hotend here, according to your setup.  // 根据你的设备配置，在此为每个热端分别指定一个参数值。
    // If there are fewer values, the last one applies to the remaining hotends.  // 如果值的数量较少，则最后一个值将适用于剩余的热端。
    #define DEFAULT_Kp_LIST {  22.20,  22.20 }
    #define DEFAULT_Ki_LIST {   1.08,   1.08 }
    #define DEFAULT_Kd_LIST { 114.00, 114.00 }
  #else
    #define DEFAULT_Kp  22.20
    #define DEFAULT_Ki   1.08
    #define DEFAULT_Kd 114.00
  #endif
#else
  #define BANG_MAX 255    // Limit hotend current while in bang-bang mode; 255=full current  // 在开/关模式下限制热端电流；255=全电流
#endif

/**
 * Model Predictive Control for hotend
 *
 * Use a physical model of the hotend to control temperature. When configured correctly this gives
 * better responsiveness and stability than PID and removes the need for PID_EXTRUSION_SCALING
 * and PID_FAN_SCALING. Enable MPC_AUTOTUNE and use M306 T to autotune the model.
 * @section mpc temp
 * 
 * 热端的模型预测控制
  使用热端的物理模型来控制温度。当正确配置时，这比PID具有更好的响应性和稳定性，并且不需要PID_EXTRUSION_SCALING和PID_FAN_SCALING。
  启用MPC_AUTOTUNE并使用M306 T进行自动调节模型。
  @section mpc temp
 */
#if ENABLED(MPCTEMP)
  #define MPC_AUTOTUNE                                // Include a method to do MPC auto-tuning (~6.3K bytes of flash)  // 启用MPC自动调参功能（约占用6.3KB闪存空间）
  #if ENABLED(MPC_AUTOTUNE)
    //#define MPC_AUTOTUNE_DEBUG                      // Enable MPC debug logging (~870 bytes of flash)  // 启用MPC调试日志记录（约占用870字节的闪存空间）
  #endif
  //#define MPC_EDIT_MENU                             // Add MPC editing to the "Advanced Settings" menu. (~1.3K bytes of flash)  // 在“高级设置”菜单中添加MPC编辑功能（约占用1.3KB的闪存空间）
  //#define MPC_AUTOTUNE_MENU                         // Add MPC auto-tuning to the "Advanced Settings" menu. (~350 bytes of flash)  // 在“高级设置”菜单中添加MPC自动调节功能（约占用350字节的闪存空间）

  #define MPC_MAX 255                                 // (0..255) Current to nozzle while MPC is active.  255=full current.  // MPC激活时喷嘴的电流（取值范围：0 到 255，255=全电流）
  #define MPC_HEATER_POWER { 40.0f }                  // (W) Nominal heat cartridge powers.    //（W）名义热卡功率。用于自动调节和作为模型的基础。
  //#define MPC_PTC                                   // Hotend power changes with temperature (e.g., PTC heat cartridges).  // 热端功率随温度变化（例如，PTC热卡）。启用后需要定义MPC_HEATER_ALPHA和MPC_HEATER_REFTEMP。
  #if ENABLED(MPC_PTC)
    #define MPC_HEATER_ALPHA { 0.0028f }              // Temperature coefficient of resistance of the heat cartridges.  // 热卡的电阻温度系数。用于自动调节和作为模型的基础。
    #define MPC_HEATER_REFTEMP { 20 }                 // (°C) Reference temperature for MPC_HEATER_POWER and MPC_HEATER_ALPHA.  // MPC_HEATER_POWER和MPC_HEATER_ALPHA的参考温度（°C）。通常为室温。
  #endif

  #define MPC_INCLUDE_FAN                             // Model the fan speed?  // 启用风扇速度建模？

  // Measured physical constants from M306
  #define MPC_BLOCK_HEAT_CAPACITY { 16.7f }           // (J/K) Heat block heat capacities.   //（J/K）热块热容量。
  #define MPC_SENSOR_RESPONSIVENESS { 0.22f }         // (K/s per ∆K) Rate of change of sensor temperature from heat block.  //（K/s per ∆K）热块温度变化引起的传感器温度变化率。用于自动调节和作为模型的基础。
  #define MPC_AMBIENT_XFER_COEFF { 0.068f }           // (W/K) Heat transfer coefficients from heat block to room air with fan off.  //（W/K）热块到室内空气的热传递系数，风扇关闭时。用于自动调节和作为模型的基础。
  #if ENABLED(MPC_INCLUDE_FAN)
    #define MPC_AMBIENT_XFER_COEFF_FAN255 { 0.097f }  // (W/K) Heat transfer coefficients from heat block to room air with fan on full.  //（W/K）热块到室内空气的热传递系数，风扇全速时。用于自动调节和作为模型的基础。
  #endif

  // For one fan and multiple hotends MPC needs to know how to apply the fan cooling effect.
  // 当使用单个风扇为多个热端散热时，MPC温控算法需要明确风扇的散热影响分配方式。
  #if ENABLED(MPC_INCLUDE_FAN)
    //#define MPC_FAN_0_ALL_HOTENDS
    //#define MPC_FAN_0_ACTIVE_HOTEND
  #endif

  // Filament Heat Capacity (joules/kelvin/mm)
  // Set at runtime with M306 H<value>
  #define FILAMENT_HEAT_CAPACITY_PERMM { 5.6e-3f }    // 0.0056 J/K/mm for 1.75mm PLA (0.0149 J/K/mm for 2.85mm PLA).  // 1.75mm PLA 耗材热容参数：0.0056 J/K/mm（2.85mm PLA 耗材热容参数：0.0149 J/K/mm）
                                                      // 0.0036 J/K/mm for 1.75mm PETG (0.0094 J/K/mm for 2.85mm PETG).  // 1.75mm PETG 耗材热容参数：0.0036 J/K/mm（2.85mm PETG 耗材热容参数：0.0094 J/K/mm）  
                                                      // 0.00515 J/K/mm for 1.75mm ABS (0.0137 J/K/mm for 2.85mm ABS).  // 1.75mm ABS 耗材热容参数：0.00515 J/K/mm（2.85mm ABS 耗材热容参数：0.0137 J/K/mm）
                                                      // 0.00522 J/K/mm for 1.75mm Nylon (0.0138 J/K/mm for 2.85mm Nylon).  // 1.75mm 尼龙 耗材热容参数：0.00522 J/K/mm（2.85mm 尼龙 耗材热容参数：0.0138 J/K/mm）

  // Advanced options  高级选项
  #define MPC_SMOOTHING_FACTOR 0.5f                   // (0.0...1.0) Noisy temperature sensors may need a lower value for stabilization.  //（0.0...1.0）// 温度传感器信号噪声较大时，可能需要降低该参数值以实现稳定。
  #define MPC_MIN_AMBIENT_CHANGE 1.0f                 // (K/s) Modeled ambient temperature rate of change, when correcting model inaccuracies.  //(开尔文/秒) 用于修正模型误差时，模拟环境温度的变化速率
  #define MPC_STEADYSTATE 0.5f                        // (K/s) Temperature change rate for steady state logic to be enforced.  // (开尔文/秒) 稳态逻辑生效所需的温度变化速率

  #define MPC_TUNING_POS { X_CENTER, Y_CENTER, 1.0f } // (mm) M306 Autotuning position, ideally bed center at first layer height.  // (毫米) M306 自动调参坐标，理想位置为第一层高度时的热床中心
  #define MPC_TUNING_END_Z 10.0f                      // (mm) M306 Autotuning final Z position.  // (毫米) M306 自动调参结束时的Z坐标位置
  //#define EVENT_GCODE_AFTER_MPC_TUNE "M84"          // G-code to execute after MPC tune finished and Z raised.  // M306自动调节完成并提升Z轴后执行的G-code
#endif

//===========================================================================
//====================== PID > Bed Temperature Control ======================
//===========================================================================
//热床温度PID控制

// @section bed temp

/**
 * Max Bed Power
 * Applies to all forms of bed control (PID, bang-bang, and bang-bang with hysteresis).
 * When set to any value below 255, enables a form of PWM to the bed that acts like a divider
 * so don't use it unless you are OK with PWM on your bed. (See the comment on enabling PIDTEMPBED)
 * 
 * 最大热床功率
  适用于所有形式的床控制（PID、开/关和带滞后的开/关）。
  当设置为255以下的任何值时，会启用一种对床进行PWM控制的方式，类似于一个分频器，所以除非你能接受对床进行PWM控制，否则不要使用它。（参见启用PIDTEMPBED的注释）
 */
#define MAX_BED_POWER 255 // limits duty cycle to bed; 255=full current

/**
 * PID Bed Heating
 *
 * The PID frequency will be the same as the extruder PWM.
 * If PID_dT is the default, and correct for the hardware/configuration, that means 7.689Hz,
 * which is fine for driving a square wave into a resistive load and does not significantly
 * impact FET heating. This also works fine on a Fotek SSR-10DA Solid State Relay into a 250W
 * heater. If your configuration is significantly different than this and you don't understand
 * the issues involved, don't use bed PID until someone else verifies that your hardware works.
 *
 * With this option disabled, bang-bang will be used. BED_LIMIT_SWITCHING enables hysteresis.
 * 
  *
 * 热床 PID 恒温控制
 *
 * PID 控制频率与挤出机 PWM 频率一致。
 * 如果使用默认的 PID_dT 参数且适配你的硬件/配置，则频率为 7.689Hz，
 * 该频率非常适合驱动电阻式加热负载（热床），且不会对 FET 场效应管造成明显发热。
 * 此参数在 Fotek SSR-10DA 固态继电器驱动 250W 加热器的配置下也能稳定运行。
 * 如果你的硬件配置与上述情况差异极大，且你不理解相关原理，
 * 请勿使用热床 PID 功能，直到其他专业人士验证你的硬件可行。
 *
 * 若禁用此选项，将使用【开关控制（bang-bang）】模式。
 * BED_LIMIT_SWITCHING 选项用于启用【回差控制】。
 */
 
//#define PIDTEMPBED

#if ENABLED(PIDTEMPBED)
  //#define MIN_BED_POWER 0   // Min power to improve PID stability (0..MAX_BED_POWER).  // 提升热床PID稳定性的最小输出功率（取值范围：0 到 MAX_BED_POWER）
                              // Get the power from the temperature report ('M105' => B@:nnn) and try P*2-20 to P*2-10.  // 从温度反馈指令中获取功率值（'M105' => B@:nnn），尝试将P值设为 当前功率值×2-20 至 当前功率值×2-10 区间。
  //#define PID_BED_DEBUG     // Print Bed PID debug data to the serial port. Use 'M303 D' to enable/disable.  // 将热床PID调试数据打印到串口。使用 'M303 D' 命令启用/禁用。

  // 120V 250W silicone heater into 4mm borosilicate (MendelMax 1.5+)  // 适配 120V 250W 硅胶加热板 + 4mm 硼硅玻璃热床（MendelMax 1.5+ 机型）
  // from FOPDT model - kp=.39 Tp=405 Tdead=66, Tc set to 79.2, aggressive factor of .15 (vs .1, 1, 10)  // 来自 FOPDT 模型 - kp=.39 Tp=405 Tdead=66，Tc 设置为 79.2，激进因子为 .15（相对于 .1、1、10）
  #define DEFAULT_bedKp  10.00
  #define DEFAULT_bedKi   0.023
  #define DEFAULT_bedKd 305.4

  // FIND YOUR OWN: "M303 E-1 C8 S90" to run autotune on the bed at 90 degreesC for 8 cycles.  // 运行自动调节命令 "M303 E-1 C8 S90"，在热床上以 90°C 进行 8 个周期的自动调节，来获取适合你设备的 PID 参数。
#else
  //#define BED_LIMIT_SWITCHING   // Keep the bed temperature within BED_HYSTERESIS of the target  // 将热床温度保持在目标温度的 BED_HYSTERESIS 范围内
#endif

/**
 * Peltier Bed - Heating and Cooling
 *
 * A Peltier device transfers heat from one side to the other in proportion to the amount of
 * current flowing through the device and the direction of current flow. So the same device
 * can both heat and cool.
 *
 * When "cooling" in addition to rejecting the heat transferred from the hot side to the cold
 * side, the dissipated power (voltage * current) must also be rejected. Be sure to set up a
 * fan that can be powered in sync with the Peltier unit.
 *
 * This feature is only set up to run in bang-bang mode because Peltiers don't handle PWM
 * well without filter circuitry.
 *
 * Since existing 3D printers are made to handle relatively high current for the heated bed,
 * we can use the heated bed power pins to control the Peltier power using the same G-codes
 * as the heated bed (M140, M190, etc.).
 *
 * A second GPIO pin is required to control current direction.
 * Two configurations are possible: Relay and H-Bridge
 *
 * (At this time only relay is supported. H-bridge requires 4 MOS switches configured in H-Bridge.)
 *
 * Power is handled by the bang-bang control loop: 0 or 255.
 * Cooling applications are more common than heating, so the pin states are commonly:
 *   LOW  = Heating = Relay Energized
 *   HIGH = Cooling = Relay in "Normal" state
 * 
 * 
 * 半导体制冷片热床 - 加热与制冷
 *
 * 半导体制冷片（Peltier）通过改变通过的电流大小与方向，
 * 实现热量从一侧转移到另一侧。因此同一个器件既能加热也能制冷。
 *
 * 当处于【制冷模式】时，除了要将热量从热端转移到冷端外，
 * 器件自身消耗的功率（电压 × 电流）产生的热量也必须一并散掉。
 * 务必配置一个与制冷片同步供电的散热风扇。
 *
 * 该功能仅设置为【开关控制】模式运行，
 * 因为在没有滤波电路的情况下，半导体制冷片不适合使用 PWM 控制。
 *
 * 由于现有3D打印机的热床电路本身就能承受较大电流，
 * 因此可以直接使用热床电源引脚，通过热床相同的G代码（M140、M190等）控制半导体制冷片。
 *
 * 需要额外一个GPIO引脚来控制电流方向。
 * 支持两种配置方式：继电器模式 和 H桥驱动模式
 *
 * （当前仅支持继电器模式。H桥模式需要配置4个MOS管组成H桥电路。）
 *
 * 功率由开关控制回路处理：只有全开（255）或全关（0）两种状态。
 * 制冷应用比加热更常见，因此引脚状态通常定义为：
 *   LOW  = 加热 = 继电器吸合
 *   HIGH = 制冷 = 继电器默认状态
 *
 */
//#define PELTIER_BED
#if ENABLED(PELTIER_BED)
  #define PELTIER_DIR_PIN           -1  // Relay control pin for Peltier  // 半导体制冷片的继电器控制引脚
  #define PELTIER_DIR_HEAT_STATE   LOW  // The relay pin state that causes the Peltier to heat  // 导致半导体制冷片加热的继电器引脚状态
#endif

// Add 'M190 R T' for more gradual M190 R bed cooling.
//#define BED_ANNEALING_GCODE

//===========================================================================
//==================== PID > Chamber Temperature Control ====================
//===========================================================================
// PID 腔体温控(这个是封闭打印机内部的环境温度)

/**
 * PID Chamber Heating
 *
 * If this option is enabled set PID constants below.
 * If this option is disabled, bang-bang will be used and CHAMBER_LIMIT_SWITCHING will enable
 * hysteresis.
 *
 * The PID frequency will be the same as the extruder PWM.
 * If PID_dT is the default, and correct for the hardware/configuration, that means 7.689Hz,
 * which is fine for driving a square wave into a resistive load and does not significantly
 * impact FET heating. This also works fine on a Fotek SSR-10DA Solid State Relay into a 200W
 * heater. If your configuration is significantly different than this and you don't understand
 * the issues involved, don't use chamber PID until someone else verifies that your hardware works.
 * @section chamber temp
 * 腔体加热 PID 控制
 *
 * 启用此选项后，请在下方设置 PID 参数。
 * 禁用此选项则使用【开关控制】，
 * 同时 CHAMBER_LIMIT_SWITCHING 用于启用回差保护。
 *
 * PID 频率与挤出机 PWM 频率一致。
 * 若使用默认的 PID_dT 且适配你的硬件/配置，则频率为 7.689Hz，
 * 该频率适用于电阻式加热负载，不会明显导致 FET 管发热。
 * 此参数在 Fotek SSR-10DA 固态继电器驱动 200W 加热器的配置下可稳定工作。
 * 如果你的硬件配置差异极大且你不了解相关原理，
 * 请勿使用腔体 PID，直到他人验证你的硬件可行。
 * @section 腔体温度
 */
//#define PIDTEMPCHAMBER
//#define CHAMBER_LIMIT_SWITCHING

/**
 * Max Chamber Power
 * Applies to all forms of chamber control (PID, bang-bang, and bang-bang with hysteresis).
 * When set to any value below 255, enables a form of PWM to the chamber heater that acts like a divider
 * so don't use it unless you are OK with PWM on your heater. (See the comment on enabling PIDTEMPCHAMBER)
 * 
 * 
 * 腔体最大加热功率
 * 适用于所有腔体控制方式（PID、开关控制、带回差的开关控制）。
 * 当设置为低于 255 的任意值时，会为腔体加热器启用一种 PWM 限流模式，
 * 相当于功率分频器。
 * 因此，除非你的加热器支持 PWM 控制，否则不要修改此值。
 * (详见启用 PIDTEMPCHAMBER 时的注释说明)
 *
 */
#define MAX_CHAMBER_POWER 255 // limits duty cycle to chamber heater; 255=full current  // 限制腔体加热器的工作占空比；255 = 满电流/满功率

#if ENABLED(PIDTEMPCHAMBER)
  //#define MIN_CHAMBER_POWER 0 // Min power to improve PID stability. (0..MAX_CHAMBER_POWER)  // 提升腔体 PID 稳定性的最小输出功率（取值范围：0 到 MAX_CHAMBER_POWER）
                                // Get the power from the temperature report ('M105' => C@:nnn) and try P*2-20 to P*2-10.  // 从温度反馈指令中获取功率值（'M105' => C@:nnn），尝试将P值设为 当前功率值×2-20 至 当前功率值×2-10 区间。
  //#define PID_CHAMBER_DEBUG   // Print Chamber PID debug data to the serial port. Use 'M303 D' to enable/disable.  // 将腔体 PID 调试数据打印到串口。使用 'M303 D' 命令启用/禁用。

  // Lasko "MyHeat Personal Heater" (200w) modified with a Fotek SSR-10DA to control only the heating element
  // and placed inside the small Creality printer enclosure tent.
  // 拉斯克“MyHeat”小型加热器（200W），改装了Fotek SSR-10DA固态继电器，仅用于控制加热芯，
  // 并放置在创想三维（Creality）小型打印机封闭保温罩内使用。
  #define DEFAULT_chamberKp  37.04
  #define DEFAULT_chamberKi   1.40
  #define DEFAULT_chamberKd 655.17
  // M309 P37.04 I1.04 D655.17

  // FIND YOUR OWN: "M303 E-2 C8 S50" to run autotune on the chamber at 50 degreesC for 8 cycles.
  // 自行获取适配参数：执行指令 "M303 E-2 C8 S50"
  // 即可在 50℃ 温度下对腔体加热器进行 8 次循环的自动调参。
#endif // PIDTEMPCHAMBER

// @section pid temp

#if ANY(PIDTEMP, PIDTEMPBED, PIDTEMPCHAMBER)
  //#define PID_OPENLOOP          // Puts PID in open loop. M104/M140 sets the output power from 0 to PID_MAX  // 将 PID 设置为开环模式。M104/M140 指令将输出功率设置为 0 到 PID_MAX 之间的值
  //#define SLOW_PWM_HEATERS      // PWM with very low frequency (roughly 0.125Hz=8s) and minimum state time of approximately 1s useful for heaters driven by a relay  // 通过继电器驱动的加热器适用的非常低频率（大约0.125Hz=8秒）和最小状态时间约为1秒的PWM
  #define PID_FUNCTIONAL_RANGE 20 // If the temperature difference between the target temperature and the actual temperature
                                  // is more than PID_FUNCTIONAL_RANGE then the PID will be shut off and the heater will be set to min/max.
                                  //当目标温度与实际温度之差超过 PID_FUNCTIONAL_RANGE 时，将关闭 PID 控制，并将加热器设置为最大/最小功率。

  //#define PID_EDIT_MENU         // Add PID editing to the "Advanced Settings" menu. (~700 bytes of flash)  // 在“高级设置”菜单中添加 PID 编辑功能（约占用700字节的闪存空间）
  //#define PID_AUTOTUNE_MENU     // Add PID auto-tuning to the "Advanced Settings" menu. (~250 bytes of flash)  // 在“高级设置”菜单中添加 PID 自动调节功能（约占用250字节的闪存空间）
#endif

// @section safety

/**
 * Prevent extrusion if the temperature is below EXTRUDE_MINTEMP.
 * Add M302 to set the minimum extrusion temperature and/or turn
 * cold extrusion prevention on and off.
 *
 * *** IT IS HIGHLY RECOMMENDED TO LEAVE THIS OPTION ENABLED! ***
 * 
 * 
 * 当温度低于 EXTRUDE_MINTEMP 时，禁止挤出耗材。
 * 可通过指令 M302 设置最低挤出温度，以及开启/关闭低温挤出保护功能。
 *
 * *** 强烈建议保持此选项开启！ ***
 *
 */
#define PREVENT_COLD_EXTRUSION
#define EXTRUDE_MINTEMP 170

/**
 * Prevent a single extrusion longer than EXTRUDE_MAXLENGTH.
 * Note: For Bowden Extruders make this large enough to allow load/unload.
 * 
 * 
 * 限制单次挤出操作的长度不超过 EXTRUDE_MAXLENGTH。
 * 注意：对于 Bowden 远程挤出机，需将此值设置得足够大，以支持耗材的装入与退出操作。
 *
 */
#define PREVENT_LENGTHY_EXTRUDE
#define EXTRUDE_MAXLENGTH 200

//===========================================================================
//======================== Thermal Runaway Protection =======================
//===========================================================================
//热失控保护

/**
 * Thermal Protection provides additional protection to your printer from damage
 * and fire. Marlin always includes safe min and max temperature ranges which
 * protect against a broken or disconnected thermistor wire.
 *
 * The issue: If a thermistor falls out, it will report the much lower
 * temperature of the air in the room, and the the firmware will keep
 * the heater on.
 *
 * If you get "Thermal Runaway" or "Heating failed" errors the
 * details can be tuned in Configuration_adv.h
 * 
 * 
 * 热保护功能为打印机提供额外防护，避免损坏和火灾风险。
 * Marlin 固件内置了安全的最低/最高温度范围，
 * 可防止热敏电阻断线、接触不良等故障引发危险。
 *
 * 存在的风险：
 * 如果热敏电阻脱落，它会检测到远低于实际的室温，
 * 固件会因此持续让加热器加热，导致温度失控、起火。
 *
 * 如果你出现“热失控（Thermal Runaway）”或“加热失败（Heating failed）”报错，
 * 可在 Configuration_adv.h 中调整相关参数。
 *
 */

#define THERMAL_PROTECTION_HOTENDS // Enable thermal protection for all extruders  // 为所有挤出机启用热保护功能
#define THERMAL_PROTECTION_BED     // Enable thermal protection for the heated bed  // 为热床启用热保护功能
#define THERMAL_PROTECTION_CHAMBER // Enable thermal protection for the heated chamber  // 为加热腔体启用热保护功能
#define THERMAL_PROTECTION_COOLER  // Enable thermal protection for the laser cooling  // 为激光冷却系统启用热保护功能

//===========================================================================
//============================= Mechanical Settings =========================
//===========================================================================
//机械参数设置

// @section kinematics

// Enable one of the options below for CoreXY, CoreXZ, or CoreYZ kinematics,
// either in the usual order or reversed
// @section 运动学架构

// 启用以下选项之一，以支持 CoreXY、CoreXZ 或 CoreYZ 运动学架构
// 支持标准布局或反向布局
//#define COREXY
//#define COREXZ
//#define COREYZ
//#define COREYX
//#define COREZX
//#define COREZY

//
// MarkForged Kinematics
// See https://reprap.org/forum/read.php?152,504042
//
//#define MARKFORGED_XY
//#define MARKFORGED_YX
#if ANY(MARKFORGED_XY, MARKFORGED_YX)
  //#define MARKFORGED_INVERSE  // Enable for an inverted Markforged kinematics belt path  // 启用反向 Markforged 运动学皮带路径
#endif

// Enable for a belt style printer with endless "Z" motion // 启用此选项：适用于采用皮带传动、可实现无限Z轴运动的打印机
//#define BELTPRINTER

// Articulated robot (arm). Joints are directly mapped to axes with no kinematics.  适用于机械臂式打印机，关节直接映射到轴，无运动学计算。
//#define ARTICULATED_ROBOT_ARM

// For a hot wire cutter with parallel horizontal axes (X, I) where the heights of the two wire
// ends are controlled by parallel axes (Y, J). Joints are directly mapped to axes (no kinematics).
// 适用于热线切割机，配备平行的水平轴 (X, I)，
// 切割线两端的高度由平行轴 (Y, J) 控制。
// 关节直接映射到坐标轴（无运动学算法转换）。
//#define FOAMCUTTER_XYUV

// @section polargraph

// Enable for Polargraph Kinematics  适用于 Polargraph 运动学
//#define POLARGRAPH
  // 下面这个选项是给绘图机、写字机用的
  // Pen Up = 抬笔（离开纸面）
  // Pen Down = 落笔（开始书写 / 绘画）
  // 普通 3D 打印机用不到
#if ENABLED(POLARGRAPH)
  #define POLARGRAPH_MAX_BELT_LEN  1035.0 // (mm) Belt length at full extension. Override with M665 H.  // 全伸展时的皮带长度（毫米）。可通过 M665 H 指令覆盖此值。
  #define DEFAULT_SEGMENTS_PER_SECOND 5   // Move segmentation based on duration  // 基于持续时间的运动分段（毫米/秒）。
  #define PEN_UP_DOWN_MENU                // Add "Pen Up" and "Pen Down" to the MarlinUI menu  // 在 MarlinUI 菜单中添加“Pen Up”和“Pen Down”选项
#endif

// @section delta

// Enable for DELTA kinematics and configure below
// 启用三角洲（DELTA）运动学架构，并在下方进行配置
//DELTA：三角洲打印机（那种三根立柱、吊一个喷头的并联臂打印机）
//kinematics：运动学算法（控制三个臂怎么动才能让喷头走直线）

//#define DELTA
#if ENABLED(DELTA)

  // Make delta curves from many straight lines (linear interpolation).
  // This is a trade-off between visible corners (not enough segments)
  // and processor overload (too many expensive sqrt calls).
  // 通过多条直线段拟合三角洲机型的曲线运动（线性插值）。
  // 这是一个折中设置：
  // 线段太少 → 打印件出现明显棱角；
  // 线段太多 → 处理器负载过高（大量耗时的平方根运算）。
  #define DEFAULT_SEGMENTS_PER_SECOND 200

  // After homing move down to a height where XY movement is unconstrained
  // 归位完成后，向下移动到一个 XY 轴可以自由移动、不受限制的高度

  //#define DELTA_HOME_TO_SAFE_ZONE

  // Delta calibration menu
  // Add three-point calibration to the MarlinUI menu.
  // See http://minow.blogspot.com/index.html#4918805519571907051
  // 三角洲打印机校准菜单
  // 在 Marlin 界面菜单中添加三点校准功能
  // 参考链接：http://minow.blogspot.com/index.html#4918805519571907051

  //#define DELTA_CALIBRATION_MENU

  // G33 Delta Auto-Calibration. Enable EEPROM_SETTINGS to store results.
  // G33 三角洲自动校准功能。需启用 EEPROM_SETTINGS 以保存校准结果。
  //#define DELTA_AUTO_CALIBRATION

  #if ENABLED(DELTA_AUTO_CALIBRATION)
    // Default number of probe points : n*n (1 -> 7)   // 默认探测点数量：n*n (1 -> 7)
    #define DELTA_CALIBRATION_DEFAULT_POINTS 4
  #endif

  #if ANY(DELTA_AUTO_CALIBRATION, DELTA_CALIBRATION_MENU)
    // Step size for paper-test probing  // 纸张测试探测的步进尺寸
    #define PROBE_MANUALLY_STEP 0.05      // (mm)
  #endif

  // Print surface diameter/2 minus unreachable space (avoid collisions with vertical towers).
  // 打印台面直径 / 2 减去不可到达的区域（避免与垂直立柱发生碰撞）
  #define PRINTABLE_RADIUS       140.0    // (mm)

  // Center-to-center distance of the holes in the diagonal push rods.
  // 对角线推杆上的孔位中心距
  #define DELTA_DIAGONAL_ROD 250.0        // (mm)

  // Distance between bed and nozzle Z home position  // 床面与喷嘴Z轴归位位置之间的距离
  #define DELTA_HEIGHT 250.00             // (mm) Get this value from G33 auto calibrate  //（毫米）从 G33 自动校准中获取此值

  #define DELTA_ENDSTOP_ADJ { 0.0, 0.0, 0.0 } // (mm) Get these values from G33 auto calibrate  // (mm) 从 G33 自动校准中获取这些值

  // Horizontal distance bridged by diagonal push rods when effector is centered.  
  // 当挤出机位于中心位置时，对角线推杆桥接的水平距离。
  #define DELTA_RADIUS 124.0              // (mm) Get this value from G33 auto calibrate  //（毫米）从 G33 自动校准中获取此值

  // Trim adjustments for individual towers
  // tower angle corrections for X and Y tower / rotate XYZ so Z tower angle = 0
  // measured in degrees anticlockwise looking from above the printer
  // 独立立柱的微调校正
  // X 立柱和 Y 立柱的角度校正 / 旋转 XYZ 使 Z 立柱角度 = 0
  // 从打印机顶部向下看，以逆时针方向测量角度（单位：度）
  #define DELTA_TOWER_ANGLE_TRIM { 0.0, 0.0, 0.0 } // (mm) Get these values from G33 auto calibrate  // (mm) 从 G33 自动校准中获取这些值

  // Delta radius and diagonal rod adjustments  // 三角洲半径与对角线推杆长度校正
  //#define DELTA_RADIUS_TRIM_TOWER       { 0.0, 0.0, 0.0 } // (mm)
  //#define DELTA_DIAGONAL_ROD_TRIM_TOWER { 0.0, 0.0, 0.0 } // (mm)
#endif

// @section scara

/**
 * MORGAN_SCARA was developed by QHARLEY in South Africa in 2012-2013.
 * Implemented and slightly reworked by JCERNY in June, 2014.
 *
 * Mostly Printed SCARA is an open source design by Tyler Williams. See:
 *   https://www.thingiverse.com/thing:2487048
 *   https://www.thingiverse.com/thing:1241491
 */
//#define MORGAN_SCARA
//#define MP_SCARA
#if ANY(MORGAN_SCARA, MP_SCARA)
  // If movement is choppy try lowering this value  // 如果运动不流畅，请尝试降低此值
  #define DEFAULT_SEGMENTS_PER_SECOND 200

  // Length of inner and outer support arms. Measure arm lengths precisely.  // 内外支撑臂的长度。请精确测量臂长。
  #define SCARA_LINKAGE_1 150       // (mm)
  #define SCARA_LINKAGE_2 150       // (mm)

  // SCARA tower offset (position of Tower relative to bed zero position) // SCARA 立柱偏移量（立柱相对于平台原点的位置）
  // This needs to be reasonably accurate as it defines the printbed position in the SCARA space.  // 这需要相当准确，因为它定义了 SCARA 空间中的打印床位置。
  #define SCARA_OFFSET_X  100       // (mm)
  #define SCARA_OFFSET_Y  -56       // (mm)

  #if ENABLED(MORGAN_SCARA)

    //#define DEBUG_SCARA_KINEMATICS
    #define FEEDRATE_SCALING        // Convert XY feedrate from mm/s to degrees/s on the fly  // 将 XY 轴的进给速度从 mm/s 转换为 degrees/s（角度/秒）以实时调整运动速度

    // Radius around the center where the arm cannot reach  // 机械臂无法到达的中心区域半径
    #define MIDDLE_DEAD_ZONE_R   0  // (mm)

  #elif ENABLED(MP_SCARA)

    #define SCARA_OFFSET_THETA1  12 // degrees
    #define SCARA_OFFSET_THETA2 131 // degrees

  #endif

#endif

// @section tpara

// Enable for TPARA kinematics and configure below  // 启用 TPARA 运动学架构，并在下方进行配置
//#define AXEL_TPARA
#if ENABLED(AXEL_TPARA)
  #define DEBUG_TPARA_KINEMATICS
  #define DEFAULT_SEGMENTS_PER_SECOND 200

  // Length of inner and outer support arms. Measure arm lengths precisely.  // 内外支撑臂的长度。请精确测量臂长。
  #define TPARA_LINKAGE_1 120     // (mm)
  #define TPARA_LINKAGE_2 120     // (mm)

  // TPARA tower offset (position of Tower relative to bed zero position)
  // This needs to be reasonably accurate as it defines the printbed position in the TPARA space.
  // TPARA 立柱偏移量（立柱相对于打印平台原点的位置）
  // 该参数需要设置得相对精准，因为它定义了打印平台在 TPARA 空间中的位置。
  #define TPARA_OFFSET_X    0     // (mm)
  #define TPARA_OFFSET_Y    0     // (mm)
  #define TPARA_OFFSET_Z    0     // (mm)

  #define FEEDRATE_SCALING        // Convert XY feedrate from mm/s to degrees/s on the fly  // 将 XY 轴的进给速度从 mm/s 转换为 degrees/s（角度/秒）以实时调整运动速度

  // Radius around the center where the arm cannot reach  // 机械臂无法到达的中心区域半径
  #define MIDDLE_DEAD_ZONE_R   0  // (mm)
#endif

// @section polar

/**
 * POLAR Kinematics
 *  developed by Kadir ilkimen for PolarBear CNC and babyBear
 *  https://github.com/kadirilkimen/Polar-Bear-Cnc-Machine
 *  https://github.com/kadirilkimen/babyBear-3D-printer
 *
 * A polar machine can have different configurations.
 * This kinematics is only compatible with the following configuration:
 *        X : Independent linear
 *   Y or B : Polar
 *        Z : Independent linear
 *
 * For example, PolarBear has CoreXZ plus Polar Y or B.
 *
 * Motion problem for Polar axis near center / origin:
 *
 * 3D printing:
 * Movements very close to the center of the polar axis take more time than others.
 * This brief delay results in more material deposition due to the pressure in the nozzle.
 *
 * Current Kinematics and feedrate scaling deals with this by making the movement as fast
 * as possible. It works for slow movements but doesn't work well with fast ones. A more
 * complicated extrusion compensation must be implemented.
 *
 * Ideally, it should estimate that a long rotation near the center is ahead and will cause
 * unwanted deposition. Therefore it can compensate the extrusion beforehand.
 *
 * Laser cutting:
 * Same thing would be a problem for laser engraving too. As it spends time rotating at the
 * center point, more likely it will burn more material than it should. Therefore similar
 * compensation would be implemented for laser-cutting operations.
 *
 * Milling:
 * This shouldn't be a problem for cutting/milling operations.
 * 
 * 
 * 极坐标运动学 (POLAR Kinematics)
 * 由 Kadır İlkimen 为 PolarBear CNC 和 babyBear 开发
 *  https://github.com/kadirilkimen/Polar-Bear-Cnc-Machine
 *  https://github.com/kadirilkimen/babyBear-3D-printer
 *
 * 极坐标机型可使用不同的配置，本运动学仅兼容以下配置：
 *        X : 独立直线轴
 *   Y 或 B : 极坐标旋转轴
 *        Z : 独立直线轴
 *
 * 例如：PolarBear 使用 CoreXZ + 极坐标 Y/B 轴
 *
 * 极坐标轴在原点/中心附近的运动问题：
 *
 * 3D 打印：
 * 靠近极坐标中心的旋转运动耗时更长，
 * 喷嘴内的压力会导致此处**挤出过多材料**。
 *
 * 当前运动学与速度缩放通过尽可能提高移动速度来缓解，
 * 低速打印有效，但高速效果不佳，需要更复杂的挤出补偿。
 *
 * 理想方案：
 * 提前预判中心长旋转会造成的多余挤出，
 * 并**预先进行挤出补偿**。
 *
 * 激光切割：
 * 中心旋转会导致激光**过度烧蚀材料**，
 * 同样需要类似补偿。
 *
 * 铣削/雕刻：
 * 此问题不影响铣削加工。
 *
 */
//#define POLAR
#if ENABLED(POLAR)
  #define DEFAULT_SEGMENTS_PER_SECOND 180   // If movement is choppy try lowering this value  // 如果运动不流畅，请尝试降低此值
  #define PRINTABLE_RADIUS 82.0f            // (mm) Maximum travel of X axis  (毫米) X轴最大行程

  // Movements fall inside POLAR_FAST_RADIUS are assigned the highest possible feedrate
  // to compensate unwanted deposition related to the near-origin motion problem.
  // 在 POLAR_FAST_RADIUS 半径范围内的移动，会以尽可能高的速度运行
  // 以补偿因靠近原点运动而产生的多余挤出（堆料）问题。
  #define POLAR_FAST_RADIUS 3.0f            // (mm)

  // Radius which is unreachable by the tool.
  // Needed if the tool is not perfectly aligned to the center of the polar axis.
  // 刀具无法到达的半径（禁区半径）
  // 当喷头/刀具无法与极坐标中心完全对准时，需要设置此值。
  #define POLAR_CENTER_OFFSET 0.0f          // (mm)

  #define FEEDRATE_SCALING                  // Convert XY feedrate from mm/s to degrees/s on the fly
#endif

//===========================================================================
//============================== Endstop Settings ===========================
//===========================================================================
//限位开关配置

// @section endstops

// Enable pullup for all endstops to prevent a floating state
// 为所有限位开关启用内部上拉电阻，防止信号处于浮动不确定状态
#define ENDSTOPPULLUPS
#if DISABLED(ENDSTOPPULLUPS)
  // Disable ENDSTOPPULLUPS to set pullups individually
  // 禁用全局限位开关上拉电阻，以便单独配置每个限位的上拉功能
  //#define ENDSTOPPULLUP_XMIN
  //#define ENDSTOPPULLUP_YMIN
  //#define ENDSTOPPULLUP_ZMIN
  //#define ENDSTOPPULLUP_IMIN
  //#define ENDSTOPPULLUP_JMIN
  //#define ENDSTOPPULLUP_KMIN
  //#define ENDSTOPPULLUP_UMIN
  //#define ENDSTOPPULLUP_VMIN
  //#define ENDSTOPPULLUP_WMIN
  //#define ENDSTOPPULLUP_XMAX
  //#define ENDSTOPPULLUP_YMAX
  //#define ENDSTOPPULLUP_ZMAX
  //#define ENDSTOPPULLUP_IMAX
  //#define ENDSTOPPULLUP_JMAX
  //#define ENDSTOPPULLUP_KMAX
  //#define ENDSTOPPULLUP_UMAX
  //#define ENDSTOPPULLUP_VMAX
  //#define ENDSTOPPULLUP_WMAX
  //#define ENDSTOPPULLUP_ZMIN_PROBE
#endif

// Enable pulldown for all endstops to prevent a floating state
// 为所有限位开关启用内部下拉电阻，防止信号处于浮动不确定状态
//#define ENDSTOPPULLDOWNS
#if DISABLED(ENDSTOPPULLDOWNS)
  // Disable ENDSTOPPULLDOWNS to set pulldowns individually
  // 禁用全局限位开关下拉电阻，以便单独配置每个限位的下拉功能
  //#define ENDSTOPPULLDOWN_XMIN
  //#define ENDSTOPPULLDOWN_YMIN
  //#define ENDSTOPPULLDOWN_ZMIN
  //#define ENDSTOPPULLDOWN_IMIN
  //#define ENDSTOPPULLDOWN_JMIN
  //#define ENDSTOPPULLDOWN_KMIN
  //#define ENDSTOPPULLDOWN_UMIN
  //#define ENDSTOPPULLDOWN_VMIN
  //#define ENDSTOPPULLDOWN_WMIN
  //#define ENDSTOPPULLDOWN_XMAX
  //#define ENDSTOPPULLDOWN_YMAX
  //#define ENDSTOPPULLDOWN_ZMAX
  //#define ENDSTOPPULLDOWN_IMAX
  //#define ENDSTOPPULLDOWN_JMAX
  //#define ENDSTOPPULLDOWN_KMAX
  //#define ENDSTOPPULLDOWN_UMAX
  //#define ENDSTOPPULLDOWN_VMAX
  //#define ENDSTOPPULLDOWN_WMAX
  //#define ENDSTOPPULLDOWN_ZMIN_PROBE
#endif

/**
 * Endstop "Hit" State
 * Set to the state (HIGH or LOW) that applies to each endstop.
 * 
 * 限位开关触发状态
 * 设置每个限位开关被触发时的信号状态（HIGH 高电平 或 LOW 低电平）。
 *
 */
#define X_MIN_ENDSTOP_HIT_STATE HIGH
#define X_MAX_ENDSTOP_HIT_STATE HIGH
#define Y_MIN_ENDSTOP_HIT_STATE HIGH
#define Y_MAX_ENDSTOP_HIT_STATE HIGH
#define Z_MIN_ENDSTOP_HIT_STATE HIGH
#define Z_MAX_ENDSTOP_HIT_STATE HIGH
#define I_MIN_ENDSTOP_HIT_STATE HIGH
#define I_MAX_ENDSTOP_HIT_STATE HIGH
#define J_MIN_ENDSTOP_HIT_STATE HIGH
#define J_MAX_ENDSTOP_HIT_STATE HIGH
#define K_MIN_ENDSTOP_HIT_STATE HIGH
#define K_MAX_ENDSTOP_HIT_STATE HIGH
#define U_MIN_ENDSTOP_HIT_STATE HIGH
#define U_MAX_ENDSTOP_HIT_STATE HIGH
#define V_MIN_ENDSTOP_HIT_STATE HIGH
#define V_MAX_ENDSTOP_HIT_STATE HIGH
#define W_MIN_ENDSTOP_HIT_STATE HIGH
#define W_MAX_ENDSTOP_HIT_STATE HIGH
#define Z_MIN_PROBE_ENDSTOP_HIT_STATE HIGH

// Enable this feature if all enabled endstop pins are interrupt-capable.
// This will remove the need to poll the interrupt pins, saving many CPU cycles.
// 如果所有已启用的限位开关引脚都支持中断功能，则启用此选项。
// 这将消除轮询检测中断引脚的需要，节省大量 CPU 运算周期。
//#define ENDSTOP_INTERRUPTS_FEATURE

/**
 * Endstop Noise Threshold
 *
 * Enable if your probe or endstops falsely trigger due to noise.
 *
 * - Higher values may affect repeatability or accuracy of some bed probes.
 * - To fix noise install a 100nF ceramic capacitor in parallel with the switch.
 * - This feature is not required for common micro-switches mounted on PCBs
 *   based on the Makerbot design, which already have the 100nF capacitor.
 *
 * :[2,3,4,5,6,7]
 * 
 * 
 * 限位开关噪声过滤阈值
 *
 * 如果你的探头或限位开关因信号干扰而误触发，请启用此功能。
 *
 * - 数值过高可能会影响某些调平探头的重复精度与准确度。
 * - 根治干扰问题：在开关两端并联一个 100nF 陶瓷电容。
 * - 基于 Makerbot 设计、带 PCB 板的普通机械限位开关无需此功能，
 *   因为它们已经自带 100nF 电容。
 *
 * 可选数值：[2,3,4,5,6,7]
 *
 */
//#define ENDSTOP_NOISE_THRESHOLD 2

// Check for stuck or disconnected endstops during homing moves.
// 在归位移动过程中，检测限位开关是否卡住或断线。
//#define DETECT_BROKEN_ENDSTOP

//=============================================================================
//============================== Movement Settings ============================
//=============================================================================
//运动参数设置
// @section motion

/**
 * Default Settings
 *
 * These settings can be reset by M502
 *
 * Note that if EEPROM is enabled, saved values will override these.
 * 
 * 
 * 默认参数设置
 *
 * 这些设置可通过 M502 指令恢复为默认值
 *
 * 注意：如果启用了 EEPROM（参数存储），保存到芯片中的参数会覆盖这些默认值。
 *
 */

/**
 * With this option each E stepper can have its own factors for the
 * following movement settings. If fewer factors are given than the
 * total number of extruders, the last value applies to the rest.
 * 
 * 
 * 启用此选项后，每个挤出机步进电机都可以拥有独立的运动参数系数。
 * 如果提供的系数数量少于挤出机总数，则最后一个系数将应用于剩余的挤出机。
 *
 */
//#define DISTINCT_E_FACTORS

/**
 * Default Axis Steps Per Unit (linear=steps/mm, rotational=steps/°)
 * Override with M92 (when enabled below)
 *                                      X, Y, Z [, I [, J [, K...]]], E0 [, E1[, E2...]]
 * 
 * 
 * 各轴默认单位步数（直线轴：步数/毫米，旋转轴：步数/度）
 * 可通过 M92 指令覆盖（需下方启用权限）
 *                                    X, Y, Z [, I [, J [, K...]]], E0 [, E1[, E2...]]
 *
 */
#define DEFAULT_AXIS_STEPS_PER_UNIT   { 80, 80, 400, 500 }

/**
 * Enable support for M92. Disable to save at least ~530 bytes of flash.
 * // 启用对 M92 指令的支持。禁用可节省至少约 530 字节的闪存空间。
 */
#define EDITABLE_STEPS_PER_UNIT

/**
 * Default Max Feed Rate (linear=mm/s, rotational=°/s)
 * Override with M203
 *                                      X, Y, Z [, I [, J [, K...]]], E0 [, E1[, E2...]]
 * 
 * 
 * 默认最大进给速度（直线轴：毫米/秒，旋转轴：度/秒）
 * 可通过 M203 指令覆盖
 *                                    X, Y, Z [, I [, J [, K...]]], E0 [, E1[, E2...]]
 *
 */
#define DEFAULT_MAX_FEEDRATE          { 300, 300, 5, 25 }

//#define LIMITED_MAX_FR_EDITING        // Limit edit via M203 or LCD to DEFAULT_MAX_FEEDRATE * 2// 限制通过 M203 指令或 LCD 屏幕修改的速度上限为 DEFAULT_MAX_FEEDRATE 的 2 倍
#if ENABLED(LIMITED_MAX_FR_EDITING)
  #define MAX_FEEDRATE_EDIT_VALUES    { 600, 600, 10, 50 } // ...or, set your own edit limits// ...或者，设置你自定义的修改上限
#endif

/**
 * Default Max Acceleration (speed change with time) (linear=mm/(s^2), rotational=°/(s^2))
 * (Maximum start speed for accelerated moves)
 * Override with M201
 *                                      X, Y, Z [, I [, J [, K...]]], E0 [, E1[, E2...]]
 * 
 * 默认最大加速度（速度随时间的变化率）
 * 直线轴单位：mm/(s²)，旋转轴单位：°/(s²)
 *（加速运动的最大启动速度）
 * 可通过 M201 指令覆盖
 *                                    X, Y, Z [, I [, J [, K...]]], E0 [, E1[, E2...]]
 *
 */
#define DEFAULT_MAX_ACCELERATION      { 3000, 3000, 100, 10000 }

//#define LIMITED_MAX_ACCEL_EDITING     // Limit edit via M201 or LCD to DEFAULT_MAX_ACCELERATION * 2  // 限制通过 M201 指令或 LCD 屏幕修改的加速度上限为 DEFAULT_MAX_ACCELERATION 的 2 倍
#if ENABLED(LIMITED_MAX_ACCEL_EDITING)
  #define MAX_ACCEL_EDIT_VALUES       { 6000, 6000, 200, 20000 } // ...or, set your own edit limits  // ...或者，设置你自定义的修改上限
#endif

/**
 * Default Acceleration (speed change with time) (linear=mm/(s^2), rotational=°/(s^2))
 * Override with M204
 *
 *   M204 P    Acceleration
 *   M204 R    Retract Acceleration
 *   M204 T    Travel Acceleration
 * 
 * 
 * 默认加速度（速度随时间的变化率）
 * 直线轴单位：mm/(s²)，旋转轴单位：°/(s²)
 * 可通过 M204 指令覆盖
 *
 *   M204 P    打印加速度
 *   M204 R    回抽加速度
 *   M204 T    空移加速度
 *
 */
#define DEFAULT_ACCELERATION          3000    // X, Y, Z and E acceleration for printing moves// 打印移动时 X、Y、Z、E 轴的加速度
#define DEFAULT_RETRACT_ACCELERATION  3000    // E acceleration for retracts  // 回抽时 E 轴（挤出机）的加速度
#define DEFAULT_TRAVEL_ACCELERATION   3000    // X, Y, Z acceleration for travel (non printing) moves  // 空移（非打印移动）时 X、Y、Z 轴的加速度

/**
 * Default Jerk limits (mm/s)
 * Override with M205 X Y Z . . . E
 *
 * "Jerk" specifies the minimum speed change that requires acceleration.
 * When changing speed and direction, if the difference is less than the
 * value set here, it may happen instantaneously.
 * 
 * 
 * 默认瞬时速度（Jerk）限制（单位：mm/s）
 * 可通过 M205 X Y Z E 指令覆盖
 *
 * “Jerk（瞬时速度）”定义了：无需经过加减速，可直接突变的最小速度变化值。
 * 在改变速度和方向时，如果速度差小于此处设置的值，
 * 电机将瞬间完成速度/方向切换，不做平滑加减速。
 * 
 *  附（译者注）：
 *
 *  Jerk是什么？
 * Jerk = 瞬间启停的 “爆发力”，它决定了：机器能不能瞬间启动、瞬间转向、瞬间停，而不用慢慢加速减速。
    数值越大：转向越干脆、打印越快，但震动大、抖边、丢步、撞头
    数值越小：移动越平滑、打印越稳，但速度慢、转角圆钝
 */
//#define CLASSIC_JERK
#if ENABLED(CLASSIC_JERK)
  #define DEFAULT_XJERK 10.0
  #define DEFAULT_YJERK 10.0
  #define DEFAULT_ZJERK  0.3
  #define DEFAULT_EJERK  5.0
  //#define DEFAULT_IJERK  0.3
  //#define DEFAULT_JJERK  0.3
  //#define DEFAULT_KJERK  0.3
  //#define DEFAULT_UJERK  0.3
  //#define DEFAULT_VJERK  0.3
  //#define DEFAULT_WJERK  0.3

  //#define TRAVEL_EXTRA_XYJERK 0.0     // Additional jerk allowance for all travel moves  // 所有空移（非打印移动）的额外 XY 轴瞬时速度允许值

  //#define LIMITED_JERK_EDITING        // Limit edit via M205 or LCD to DEFAULT_aJERK * 2  // 限制通过 M205 指令或 LCD 屏幕修改的瞬时速度上限为 DEFAULT_aJERK 的 2 倍
  #if ENABLED(LIMITED_JERK_EDITING)
    #define MAX_JERK_EDIT_VALUES { 20, 20, 0.6, 10 } // ...or, set your own edit limits  // ...或者，设置你自定义的修改上限
  #endif
#endif

/**
 * Junction Deviation Factor(拐角偏差因子)
 *
 * See:
 *   https://reprap.org/forum/read.php?1,739819
 *   https://blog.kyneticcnc.com/2018/10/computing-junction-deviation-for-marlin.html
 */
#if DISABLED(CLASSIC_JERK)
  #define JUNCTION_DEVIATION_MM 0.013 // (mm) Distance from real junction edge  // (mm) 距离真实拐角顶点的距离（圆弧偏移量）
  #define JD_HANDLE_SMALL_SEGMENTS    // Use curvature estimation instead of just the junction angle
                                      // for small segments (< 1mm) with large junction angles (> 135°).
                                      // 对于长度 < 1mm 的小段路径，且拐角角度 > 135° 的大角度拐角
                                      // 使用曲率估算算法，而非仅使用拐角角度计算。
#endif

/**
 * S-Curve Acceleration
 *
 * This option eliminates vibration during printing by fitting a Bézier
 * curve to move acceleration, producing much smoother direction changes.
 *
 * See https://github.com/synthetos/TinyG/wiki/Jerk-Controlled-Motion-Explained
 * 
 * 
 * S 型曲线加速度
 *
 * 此功能通过使用贝塞尔曲线控制加速度变化，
 * 消除打印过程中的震动，使方向变化更加平滑。
 *
 * 详见：https://github.com/synthetos/TinyG/wiki/Jerk-Controlled-Motion-Explained
 *
 */
//#define S_CURVE_ACCELERATION

//===========================================================================
//============================= Z Probe Options =============================
//===========================================================================
// Z 轴探头 / 自动调平探头 设置
// @section probes

//
// See https://marlinfw.org/docs/configuration/probes.html
//

/**
 * Enable this option for a probe connected to the Z-MIN pin.
 * The probe replaces the Z-MIN endstop and is used for Z homing.
 * (Automatically enables USE_PROBE_FOR_Z_HOMING.)
 * 
 * 
 * 如果你的探头连接到 Z-MIN 引脚，请启用此选项。
 * 该探头将替代 Z-MIN 限位开关，用于 Z 轴归位。
 * （启用后会自动开启 USE_PROBE_FOR_Z_HOMING 功能。）
 *
 */
#define Z_MIN_PROBE_USES_Z_MIN_ENDSTOP_PIN

// Force the use of the probe for Z-axis homing
// 强制使用探头进行 Z 轴归位
//#define USE_PROBE_FOR_Z_HOMING

/**
 * Z_MIN_PROBE_PIN
 *
 * Override this pin only if the probe cannot be connected to
 * the default Z_MIN_PROBE_PIN for the selected MOTHERBOARD.
 *
 *  - The simplest option is to use a free endstop connector.
 *  - Use 5V for powered (usually inductive) sensors.
 *
 *  - For simple switches...
 *    - Normally-closed (NC) also connect to GND.
 *    - Normally-open (NO) also connect to 5V.
 * 
 * 
 * Z_MIN_PROBE_PIN （Z轴探头信号引脚）
 *
 * 仅当你的探头无法连接到当前主板默认的 Z_MIN_PROBE_PIN 时，
 * 才需要手动修改这个引脚。
 *
 *  - 最简单的方法：使用一个空闲的限位开关接口。
 *  - 带供电的传感器（通常是电感式）需要接 5V。
 *
 *  - 普通机械开关探头:
 *    - 常闭型 (NC) 开关：另一脚接 GND。
 *    - 常开型 (NO) 开关：另一脚接 5V。
 *
 */
//#define Z_MIN_PROBE_PIN -1

/**
 * Probe Type
 *
 * Allen Key Probes, Servo Probes, Z-Sled Probes, FIX_MOUNTED_PROBE, etc.
 * Activate one of these to use Auto Bed Leveling below.
 * 
 * 
 * 探头类型选择
 *
 * 内六角探头、舵机探头、Z轴滑台探头、固定安装探头等
 * 启用其中一种，才能使用下方的自动调平功能。
 * 
 * 附（译者注）：
 * BLTouch、3D Touch、电感探头，选FIX_MOUNTED_PROBE
 * 小舵机、会伸缩 / 翻出的机械探头,选SERVO_PROBE(老机器用，现在很少见)
 *
 */

/**
 * The "Manual Probe" provides a means to do "Auto" Bed Leveling without a probe.
 * Use G29 repeatedly, adjusting the Z height at each point with movement commands
 * or (with LCD_BED_LEVELING) the LCD controller.
 * 
 * 
 * “手动探头”：无需物理探头，也能实现“自动”调平。
 * 反复执行 G29，通过移动指令或（配合 LCD 调平时）LCD 屏幕
 * 在每个点手动调整 Z 高度，完成调平。
 * 
 * 附（译者注）：
 *  这是 无探头也能用的 “手动调平模式”：
    没有 BLTouch ， 没有任何传感器
    也能使用固件里的 G29 自动调平功能
    原理：你自己用眼睛、纸张测试，手动点按调平
 */
//#define PROBE_MANUALLY

/**
 * A Fix-Mounted Probe either doesn't deploy or needs manual deployment.
 *   (e.g., an inductive probe or a nozzle-based probe-switch.)
 * 
 * 
 * 固定安装式探头：不会自动伸出，或需要手动伸出。
 *（例如：电感式接近探头、基于喷嘴的探头切换装置。）
 *
 */
//#define FIX_MOUNTED_PROBE

/**
 * Use the nozzle as the probe, as with a conductive
 * nozzle system or a piezo-electric smart effector.
 * 
 * 
 * 使用喷嘴本身作为探头，
 * 例如导电喷嘴系统、压电式智能效应器等。
 * 
 * 附（译者注）：
 * 这是一种特殊的探头模式：不用额外的探针、BLTouch，直接用喷嘴本身当探头。
   它适用于哪些设备？
    导电床 / 喷嘴系统
    喷嘴碰到热床 → 电路导通 → 触发信号
    压电传感器（Piezo）
    喷嘴一碰床 → 传感器感应压力 → 触发
    一些三角洲（Delta）3D 打印机的智能效应器

 *
 */
//#define NOZZLE_AS_PROBE

/**
 * Z Servo Probe, such as an endstop switch on a rotating arm.
 * // Z 轴舵机探头，例如安装在旋转机械臂上的限位开关。
 */
//#define Z_PROBE_SERVO_NR 0
#ifdef Z_PROBE_SERVO_NR
  //#define Z_SERVO_ANGLES { 70, 0 }      // Z Servo Deploy and Stow angles  // Z 轴舵机的伸出和收回角度
  //#define Z_SERVO_MEASURE_ANGLE 45      // Use if the servo must move to a "free" position for measuring after deploy  // 如果舵机必须在伸出后移动到一个“空闲”位置进行测量，请设置这个角度
  //#define Z_SERVO_INTERMEDIATE_STOW     // Stow the probe between points  // 在测量点之间收回探头
  //#define Z_SERVO_DEACTIVATE_AFTER_STOW // Deactivate the servo when probe is stowed  // 探头收回后停用舵机
#endif

/**
 * The BLTouch probe uses a Hall effect sensor and emulates a servo.
 * 
 * BLTouch 探头使用霍尔效应传感器，并模拟一个舵机工作。
 *
 */
//#define BLTOUCH

/**
 * MagLev V4 probe by MDD
 *
 * This probe is deployed and activated by powering a built-in electromagnet.
 * 
 * 该探头通过内置电磁铁通电来伸出并激活。
 *
 */
//#define MAGLEV4
#if ENABLED(MAGLEV4)
  //#define MAGLEV_TRIGGER_PIN 11     // Set to the connected digital output  // 设置为连接的数字输出引脚
  #define MAGLEV_TRIGGER_DELAY 15     // Changing this risks overheating the coil  // 修改这个值可能会导致线圈过热
#endif

/**
 * Touch-MI Probe by hotends.fr
 *
 * This probe is deployed and activated by moving the X-axis to a magnet at the edge of the bed.
 * By default, the magnet is assumed to be on the left and activated by a home. If the magnet is
 * on the right, enable and set TOUCH_MI_DEPLOY_XPOS to the deploy position.
 *
 * Also requires: BABYSTEPPING, BABYSTEP_ZPROBE_OFFSET, Z_SAFE_HOMING,
 *                and a minimum Z_CLEARANCE_FOR_HOMING of 10.
 * 
 * 
 * Touch-MI Probe (由 hotends.fr 设计的探头)
 *
 * 该探头需要将 X 轴移动到热床边缘的磁铁处，才能伸出并激活。
 * 默认情况下，磁铁位于左侧，并通过归位动作触发。如果磁铁位于右侧，
 * 请启用并设置 TOUCH_MI_DEPLOY_XPOS 为伸出位置。
 *
 * 同时还需要启用：BABYSTEPPING, BABYSTEP_ZPROBE_OFFSET, Z_SAFE_HOMING
 *                   并且 Z_CLEARANCE_FOR_HOMING 至少为 10。
 *
 */
//#define TOUCH_MI_PROBE
#if ENABLED(TOUCH_MI_PROBE)
  #define TOUCH_MI_RETRACT_Z 0.5                  // Height at which the probe retracts  // 探头收回时的 Z 高度
  //#define TOUCH_MI_DEPLOY_XPOS (X_MAX_BED + 2)  // For a magnet on the right side of the bed  // 磁铁位于热床右侧时的探头伸出 X 位置
  //#define TOUCH_MI_MANUAL_DEPLOY                // For manual deploy (LCD menu)  // 手动伸出（LCD 菜单）
#endif

/**
 * Bed Distance Sensor
 *
 * Measures the distance from bed to nozzle with accuracy of 0.01mm.
 * For information about this sensor https://github.com/markniu/Bed_Distance_sensor
 * Uses I2C port, so it requires I2C library markyue/Panda_SoftMasterI2C.
 * 
 * 
 * 热床距离传感器
 *
 * 以 0.01mm 的精度测量热床到喷嘴的距离。
 * 关于此传感器的信息：https://github.com/markniu/Bed_Distance_sensor
 * 使用 I2C 接口，因此需要 I2C 库：markyue/Panda_SoftMasterI2C。
 *
 */
//#define BD_SENSOR
#if ENABLED(BD_SENSOR)
  //#define BD_SENSOR_PROBE_NO_STOP // Probe bed without stopping at each probe point  // 在每个探测点不停止，直接探测热床
#endif

/**
 * BIQU MicroProbe
 *
 * A lightweight, solenoid-driven probe.
 * For information about this sensor https://github.com/bigtreetech/MicroProbe
 *
 * Also requires PROBE_ENABLE_DISABLE
 * 
 * 
 * BIQU MicroProbe （必趣电子的微型探头）
 *
 * 一种轻量化、由电磁螺线管驱动的探头。
 * 传感器相关信息：https://github.com/bigtreetech/MicroProbe
 *
 * 同时需要启用：PROBE_ENABLE_DISABLE
 *
 */
//#define BIQU_MICROPROBE_V1  // Triggers HIGH // 探头触发信号为 高电平（HIGH）
//#define BIQU_MICROPROBE_V2  // Triggers LOW  // 探头触发信号为 低电平（LOW）

// A probe that is deployed and stowed with a solenoid pin (SOL1_PIN)
// 通过螺线管引脚（SOL1_PIN）来伸出和收回的探头
/*
    附（译者注）：
    这是电磁螺线管驱动的专用探头：
    内部有一个小电磁铁
    给 SOL1_PIN 通电 → 探头伸出
    断电 → 探头收回
*/
//#define SOLENOID_PROBE

// A sled-mounted probe like those designed by Charles Bell.
// 一种安装在滑架上的探头，例如 Charles Bell 设计的那款。
/*
    附（译者注）：
    这是一种非常老、非常少见的机械滑台探头：
    靠 Z 轴滑架带动探头机械弹出 / 收回
    没有舵机、没有电磁铁
    纯机械结构
*/

//#define Z_PROBE_SLED
//#define SLED_DOCKING_OFFSET 5  // The extra distance the X axis must travel to pickup the sled. 0 should be fine but you can push it further if you'd like. 
                                 // X轴必须额外移动的距离，以拾取滑架。0应该就可以了，但如果你想的话，可以设置更大的值。

// A probe deployed by moving the x-axis, such as the Wilson II's rack-and-pinion probe designed by Marty Rice.
// 通过移动 X 轴来伸出/收回的探头，例如 Marty Rice 设计的 Wilson II 齿轮齿条式探头。
/*
  附（译者注）：  
  这又是一种极少见的老式纯机械探头：
  没有电机、没有舵机、没有电磁铁
  靠喷头左右撞一下机器边框
  用齿轮 / 齿条结构把探头顶出来、收回去

*/
//#define RACK_AND_PINION_PROBE
#if ENABLED(RACK_AND_PINION_PROBE)
  #define Z_PROBE_DEPLOY_X  X_MIN_POS
  #define Z_PROBE_RETRACT_X X_MAX_POS
#endif

/**
 * Magnetically Mounted Probe
 * For probes such as Euclid, Klicky, Klackender, etc.
 * 
 * 
 * 磁吸式探头
 * 适用于 Euclid、Klicky、Klackender 等类型的探头。
 *
 * 附（译者注）：
 * 这是现在比较流行的磁吸探头专用设置
  什么是磁吸探头？
  探头不是固定死在喷头架上，
  -靠磁铁吸在喷头旁边
  -调平时自动拾取探头
  -打印时自动放回支架，不挡空间
  代表型号：Euclid Probe、Klicky Probe
 */
//#define MAG_MOUNTED_PROBE
#if ENABLED(MAG_MOUNTED_PROBE)
  #define PROBE_DEPLOY_FEEDRATE (133*60)  // (mm/min) Probe deploy speed  // 探头伸出/展开速度（单位：毫米/分钟）
  #define PROBE_STOW_FEEDRATE   (133*60)  // (mm/min) Probe stow speed  // 探头收回/收起速度（单位：毫米/分钟）

  /**
   * Magnetically Mounted Probe with a Servo mechanism
   * Probe Deploy and Stow both follow the same basic sequence:
   *  - Rotate the SERVO to its Deployed angle
   *  - Perform XYZ moves to deploy or stow the PROBE
   *  - Rotate the SERVO to its Stowed angle
   * 
   * 
   * 带舵机结构的磁吸式探头
   * 探头伸出与收回遵循相同的基本流程：
   *  1. 将舵机旋转到【伸出角度】
   *  2. 执行 XYZ 运动来拾取/放回探头
   *  3. 将舵机旋转到【收回角度】
   *
   */
  //#define MAG_MOUNTED_PROBE_SERVO_NR 0             // Servo Number for this probe  // 用于此探头的舵机编号
  #ifdef MAG_MOUNTED_PROBE_SERVO_NR
    #define MAG_MOUNTED_PROBE_SERVO_ANGLES { 90, 0 } // Servo Angles for Deployed, Stowed  // 舵机的伸出和收回角度
    #define MAG_MOUNTED_PRE_DEPLOY { PROBE_DEPLOY_FEEDRATE, { 15, 160, 30 } }  // Safe position for servo activation  // 舵机激活的安全位置
    #define MAG_MOUNTED_PRE_STOW   { PROBE_DEPLOY_FEEDRATE, { 15, 160, 30 } }  // Safe position for servo deactivation  // 舵机停用的安全位置
  #endif

  #define MAG_MOUNTED_DEPLOY_1 { PROBE_DEPLOY_FEEDRATE, { 245, 114, 30 } }  // Move to side Dock & Attach probe  // 移动到侧边停靠点并吸附探头
  #define MAG_MOUNTED_DEPLOY_2 { PROBE_DEPLOY_FEEDRATE, { 210, 114, 30 } }  // Move probe off dock  // 将探头从停靠点移开
  #define MAG_MOUNTED_DEPLOY_3 { PROBE_DEPLOY_FEEDRATE, {   0,   0,  0 } }  // Extra move if needed  // 如有需要，额外的移动
  #define MAG_MOUNTED_DEPLOY_4 { PROBE_DEPLOY_FEEDRATE, {   0,   0,  0 } }  // Extra move if needed  // 如有需要，额外的移动
  #define MAG_MOUNTED_DEPLOY_5 { PROBE_DEPLOY_FEEDRATE, {   0,   0,  0 } }  // Extra move if needed  // 如有需要，额外的移动
  #define MAG_MOUNTED_STOW_1   { PROBE_STOW_FEEDRATE,   { 245, 114, 20 } }  // Move to dock  // 移动到停靠点
  #define MAG_MOUNTED_STOW_2   { PROBE_STOW_FEEDRATE,   { 245, 114,  0 } }  // Place probe beside remover  // 将探头放在移除器旁边
  #define MAG_MOUNTED_STOW_3   { PROBE_STOW_FEEDRATE,   { 230, 114,  0 } }  // Side move to remove probe  // 侧面移动以移除探头
  #define MAG_MOUNTED_STOW_4   { PROBE_STOW_FEEDRATE,   { 210, 114, 20 } }  // Side move to remove probe  // 侧面移动以移除探头
  #define MAG_MOUNTED_STOW_5   { PROBE_STOW_FEEDRATE,   {   0,   0,  0 } }  // Extra move if needed  // 如有需要，额外的移动
#endif

// Duet Smart Effector (for delta printers) - https://docs.duet3d.com/en/Duet3D_hardware/Accessories/Smart_Effector
// When the pin is defined you can use M672 to set/reset the probe sensitivity.

// Duet Smart Effector（用于三角洲/Delta打印机）- 官方文档链接https://docs.duet3d.com/en/Duet3D_hardware/Accessories/Smart_Effector
// 当引脚定义后，你可以使用 M672 指令来设置/重置探头灵敏度。
//#define DUET_SMART_EFFECTOR
#if ENABLED(DUET_SMART_EFFECTOR)
  #define SMART_EFFECTOR_MOD_PIN  -1  // Connect a GPIO pin to the Smart Effector MOD pin  // 将 GPIO 引脚连接到 Smart Effector 的 MOD 引脚
#endif

/**
 * Use StallGuard2 to probe the bed with the nozzle.
 * Requires stallGuard-capable Trinamic stepper drivers.
 * CAUTION: This can damage machines with Z lead screws.
 *          Take extreme care when setting up this feature.
 * 
 * 
 * 使用 StallGuard2 技术，让喷嘴直接探测热床。
 * 必须使用支持 stallGuard 功能的 Trinamic 步进电机驱动。
 * 注意：此功能可能会损坏带有 Z 轴丝杆的机器！
 *      设置时请务必极度小心。
 * 
 * 附（译者注）：
 * 这是一个无探头、无传感器的功能：
 * 不用 BLTouch、不用任何硬件
 * 直接让喷嘴撞热床
 * 靠电机堵转检测（StallGuard）判断是否接触
 *
 */
//#define SENSORLESS_PROBING

/**
 * Allen key retractable z-probe as seen on many Kossel delta printers - https://reprap.org/wiki/Kossel#Autolevel_probe
 * Deploys by touching z-axis belt. Retracts by pushing the probe down.
 * 
 * 内六角可伸缩Z轴探头，多见于多款Kossel三角洲打印机
 * 依靠触碰Z轴皮带完成伸出，下压探头即可收回
 *
 */
//#define Z_PROBE_ALLEN_KEY
#if ENABLED(Z_PROBE_ALLEN_KEY)
  // 2 or 3 sets of coordinates for deploying and retracting the spring loaded touch probe on G29,
  // if servo actuated touch probe is not defined. Uncomment as appropriate for your printer/probe.
  // 如果未定义舵机驱动式触控探头，
  // 则在此配置 2 组或 3 组坐标，用于 G29 时伸出/收回弹簧式触控探头。
  // 根据你的打印机/探头型号取消注释并使用。

  #define Z_PROBE_ALLEN_KEY_DEPLOY_1 { 30.0, PRINTABLE_RADIUS, 100.0 }
  #define Z_PROBE_ALLEN_KEY_DEPLOY_1_FEEDRATE XY_PROBE_FEEDRATE

  #define Z_PROBE_ALLEN_KEY_DEPLOY_2 { 0.0, PRINTABLE_RADIUS, 100.0 }
  #define Z_PROBE_ALLEN_KEY_DEPLOY_2_FEEDRATE (XY_PROBE_FEEDRATE)/10

  #define Z_PROBE_ALLEN_KEY_DEPLOY_3 { 0.0, (PRINTABLE_RADIUS) * 0.75, 100.0 }
  #define Z_PROBE_ALLEN_KEY_DEPLOY_3_FEEDRATE XY_PROBE_FEEDRATE

  #define Z_PROBE_ALLEN_KEY_STOW_1 { -64.0, 56.0, 23.0 } // Move the probe into position  // 移动探头至探测就位位置
  #define Z_PROBE_ALLEN_KEY_STOW_1_FEEDRATE XY_PROBE_FEEDRATE

  #define Z_PROBE_ALLEN_KEY_STOW_2 { -64.0, 56.0, 3.0 } // Push it down  // 下压探头
  #define Z_PROBE_ALLEN_KEY_STOW_2_FEEDRATE (XY_PROBE_FEEDRATE)/10

  #define Z_PROBE_ALLEN_KEY_STOW_3 { -64.0, 56.0, 50.0 } // Move it up to clear  // 将探头上移以避开障碍物
  #define Z_PROBE_ALLEN_KEY_STOW_3_FEEDRATE XY_PROBE_FEEDRATE

  #define Z_PROBE_ALLEN_KEY_STOW_4 { 0.0, 0.0, 50.0 }
  #define Z_PROBE_ALLEN_KEY_STOW_4_FEEDRATE XY_PROBE_FEEDRATE

#endif // Z_PROBE_ALLEN_KEY

/**
 * Nozzle-to-Probe offsets { X, Y, Z }
 *
 * X and Y offset
 *   Use a caliper or ruler to measure the distance from the tip of
 *   the Nozzle to the center-point of the Probe in the X and Y axes.
 *
 * Z offset
 * - For the Z offset use your best known value and adjust at runtime.
 * - Common probes trigger below the nozzle and have negative values for Z offset.
 * - Probes triggering above the nozzle height are uncommon but do exist. When using
 *   probes such as this, carefully set Z_CLEARANCE_DEPLOY_PROBE and Z_CLEARANCE_BETWEEN_PROBES
 *   to avoid collisions during probing.
 *
 * Tune and Adjust
 * -  Probe Offsets can be tuned at runtime with 'M851', LCD menus, babystepping, etc.
 * -  PROBE_OFFSET_WIZARD (Configuration_adv.h) can be used for setting the Z offset.
 *
 * Assuming the typical work area orientation:
 *  - Probe to RIGHT of the Nozzle has a Positive X offset
 *  - Probe to LEFT  of the Nozzle has a Negative X offset
 *  - Probe in BACK  of the Nozzle has a Positive Y offset
 *  - Probe in FRONT of the Nozzle has a Negative Y offset
 * 
 * 喷嘴到探头的偏移量 { X, Y, Z }
 *
 * X 和 Y 偏移量
 *   用卡尺或直尺测量喷嘴尖端到探头中心点
 *   在 X 轴和 Y 轴上的距离。
 *
 * Z 偏移量
 * - 使用你最准确的已知值作为初始值，后续可运行时微调。
 * - 常见探头触发点低于喷嘴，Z 偏移值为**负数**。
 * - 触发点高于喷嘴的探头很少见，但确实存在。
 *   使用此类探头时，请仔细设置 Z_CLEARANCE_DEPLOY_PROBE
 *   和 Z_CLEARANCE_BETWEEN_PROBES，避免探测时发生碰撞。
 *
 * 校准与调整
 * - 探头偏移量可通过指令 M851、LCD 菜单、微步调整等方式实时修改。
 * - 可使用 PROBE_OFFSET_WIZARD（配置文件）向导设置 Z 偏移量。
 *
 * 标准坐标系方向规则：
 *  - 探头在喷嘴**右侧** → X 偏移为**正数**
 *  - 探头在喷嘴**左侧** → X 偏移为**负数**
 *  - 探头在喷嘴**后方** → Y 偏移为**正数**
 *  - 探头在喷嘴**前方** → Y 偏移为**负数**
 *
 * 示例：
 * Some examples:
 *   #define NOZZLE_TO_PROBE_OFFSET { 10, 10, -1 }   // Example "1"
 *   #define NOZZLE_TO_PROBE_OFFSET {-10,  5, -1 }   // Example "2"
 *   #define NOZZLE_TO_PROBE_OFFSET {  5, -5, -1 }   // Example "3"
 *   #define NOZZLE_TO_PROBE_OFFSET {-15,-10, -1 }   // Example "4"
 * 
 * 
 *
 *     +-- BACK ---+
 *     |    [+]    |
 *   L |        1  | R <-- Example "1" (right+,  back+)
 *   E |  2        | I <-- Example "2" ( left-,  back+)
 *   F |[-]  N  [+]| G <-- Nozzle
 *   T |       3   | H <-- Example "3" (right+, front-)
 *     | 4         | T <-- Example "4" ( left-, front-)
 *     |    [-]    |
 *     O-- FRONT --+
 * 
 * 
 * 
 * 注（译者注）：
 * 这个设置是 BLTouch / 自动调平探头的参数，决定打印会不会刮床、悬空。
 * X 偏移：探头在喷嘴左边还是右边，差几毫米
 * Y 偏移：探头在喷嘴前边还是后边，差几毫米
 * Z 偏移：探头比喷嘴高还是低，差多少
 */
#define NOZZLE_TO_PROBE_OFFSET { 10, 10, 0 }

// Enable and set to use a specific tool for probing. Disable to allow any tool.
// 启用并设置【指定工具号】进行探测调平。
// 禁用此项 = 允许任意工具执行探测。
// 注（译者注）：这是给多喷头打印机用的设置（双喷头 / 三喷头）。如果你是单喷头打印机，保持关闭。
#define PROBING_TOOL 0
#ifdef PROBING_TOOL
  //#define PROBE_TOOLCHANGE_NO_MOVE  // Suppress motion on probe tool-change
#endif

// Most probes should stay away from the edges of the bed, but
// with NOZZLE_AS_PROBE this can be negative for a wider probing area.
// 大多数探头应远离热床边缘，
// 但如果使用喷嘴作为探头（NOZZLE_AS_PROBE），
// 可以设置为负值以获得更宽的探测区域。
#define PROBING_MARGIN 10

// X and Y axis travel speed between probes.
// Leave undefined to use the average of the current XY homing feedrate.
// 探测点之间 X 轴和 Y 轴的移动速度
// 不定义则使用当前 XY 归位速度的平均值
#define XY_PROBE_FEEDRATE    (133*60) // (mm/min)

// Feedrate for the first approach when double-probing (MULTIPLE_PROBING == 2)
// 双次探测模式下（MULTIPLE_PROBING == 2），第一次靠近热床的进给速度
// 注（译者注）：这是双次探测模式下第一次探测的速度，第二次探测会更慢，以提高精度。
#define Z_PROBE_FEEDRATE_FAST  (4*60) // (mm/min)

// Feedrate for the "accurate" probe of each point
// 每个探测点精准探测时的进给速度
#define Z_PROBE_FEEDRATE_SLOW (Z_PROBE_FEEDRATE_FAST / 2) // (mm/min)

/**
 * Probe Activation Switch
 * A switch indicating proper deployment, or an optical
 * switch triggered when the carriage is near the bed.
 * 
 * 探头激活开关
 * 一个用于检测探头是否正确展开的开关，
 * 或者是当喷头靠近热床时触发的光学开关。
 * 注（译者注）：
 * 这是给特殊机械探头（比如可收起的探针）加装一个小传感器 / 开关，用来确认：
 * 探头真的伸出来了，或者喷头确实靠近热床了
 * 只有开关检测到探头就绪，才会开始探测。
 * 只有带物理开关的特殊机械探头才需要。
 *
 */
//#define PROBE_ACTIVATION_SWITCH
#if ENABLED(PROBE_ACTIVATION_SWITCH)
  #define PROBE_ACTIVATION_SWITCH_STATE LOW // State indicating probe is active  // 探头处于激活状态时的信号状态
  //#define PROBE_ACTIVATION_SWITCH_PIN PC6 // Override default pin
#endif

/**
 * Tare Probe (determine zero-point) prior to each probe.
 * Useful for a strain gauge or piezo sensor that needs to factor out
 * elements such as cables pulling on the carriage.
 * 
 * 在每次探测前，对探头进行置零（确定零点）。
 * 对于应变片或压电传感器非常有用，因为它们需要排除诸如线缆拉扯喷头等干扰因素。
 *
 * 
 */
//#define PROBE_TARE
#if ENABLED(PROBE_TARE)
  #define PROBE_TARE_TIME  200    // (ms) Time to hold tare pin  // 保持置零引脚状态的时间（毫秒）
  #define PROBE_TARE_DELAY 200    // (ms) Delay after tare before  // 置零后到开始探测的延迟（毫秒）
  #define PROBE_TARE_STATE HIGH   // State to write pin for tare  // 置零时引脚的信号状态
  //#define PROBE_TARE_PIN PA5    // Override default pin  // 覆盖默认引脚
  //#define PROBE_TARE_MENU       // Display a menu item to tare the probe  // 显示一个菜单项来执行探头置零
  #if ENABLED(PROBE_ACTIVATION_SWITCH)
    //#define PROBE_TARE_ONLY_WHILE_INACTIVE  // Fail to tare/probe if PROBE_ACTIVATION_SWITCH is active  // 仅在探头未激活时执行置零/探测，如果 PROBE_ACTIVATION_SWITCH 处于激活状态则失败
  #endif
#endif

/**
 * Probe Enable / Disable
 * The probe only provides a triggered signal when enabled.
 * 
 * 探头启用 / 禁用
 * 仅在启用状态下，探头才会输出触发信号。
 *
 */
//#define PROBE_ENABLE_DISABLE
#if ENABLED(PROBE_ENABLE_DISABLE)
  //#define PROBE_ENABLE_PIN -1   // Override the default pin here  // 在此处覆盖默认引脚
#endif

/**
 * Multiple Probing
 *
 * You may get improved results by probing 2 or more times.
 * With EXTRA_PROBING the more atypical reading(s) will be disregarded.
 *
 * A total of 2 does fast/slow probes with a weighted average.
 * A total of 3 or more adds more slow probes, taking the average.
 * 
 * 
 * 多次探测（增强精度）
 *
 * 通过探测 2 次或更多次，可以获得更精准的结果。
 * 配合 EXTRA_PROBING 使用时，会自动忽略偏差较大的异常值。
 *
 * 总共探测 2 次：采用【快速粗探 + 慢速精探】，并加权平均。
 * 总共探测 3 次及以上：增加更多慢速精探，然后取平均值。
 *
 */
//#define MULTIPLE_PROBING 2
//#define EXTRA_PROBING    1

/**
 * Z probes require clearance when deploying, stowing, and moving between
 * probe points to avoid hitting the bed and other hardware.
 * Servo-mounted probes require extra space for the arm to rotate.
 * Inductive probes need space to keep from triggering early.
 *
 * Use these settings to specify the distance (mm) to raise the probe (or
 * lower the bed). The values set here apply over and above any (negative)
 * probe Z Offset set with NOZZLE_TO_PROBE_OFFSET, M851, or the LCD.
 * Only integer values >= 1 are valid here.
 *
 * Example: 'M851 Z-5' with a CLEARANCE of 4  =>  9mm from bed to nozzle.
 *     But: 'M851 Z+1' with a CLEARANCE of 2  =>  2mm from bed to nozzle.
 * 
 * 
 * Z轴探头在展开、收回、以及探测点之间移动时，
 * 需要预留安全间隙，避免撞击热床或其他部件。
 * 舵机安装式探头需要额外空间让机械臂旋转。
 * 电感式探头需要空间避免提前触发。
 *
 * 使用这些设置来指定抬高探头（或降低热床）的距离（毫米）。
 * 这里设置的值，是在通过 NOZZLE_TO_PROBE_OFFSET、M851 或 LCD 设置的
 * （负）探头Z偏移量基础上**额外增加**的高度。
 * 此处仅支持 >= 1 的整数值。
 *
 * 示例：
 * 'M851 Z-5' 配合间隙 4  => 喷嘴距热床总高度 9mm
 * 但是：
 * 'M851 Z+1' 配合间隙 2  => 喷嘴距热床总高度 2mm
 * 
 * 注（译者注）：
 * 这一段设置的是探头移动时的安全高度，防止探头在换点移动时撞坏热床
 * 探测完一个点后Z轴抬升到安全高度，再飞到下一个点，这个设置就是控制抬多高
 *
 */
#define Z_CLEARANCE_DEPLOY_PROBE   10 // (mm) Z Clearance for Deploy/Stow  //探头展开 / 收回时的 Z 轴安全间隙（毫米）
#define Z_CLEARANCE_BETWEEN_PROBES  5 // (mm) Z Clearance between probe points  // 探测点之间的 Z 轴安全间隙（毫米）
#define Z_CLEARANCE_MULTI_PROBE     5 // (mm) Z Clearance between multiple probes  // (mm) Z Clearance between multiple probes  // 多次探测之间的 Z 轴安全间隙（毫米）
#define Z_PROBE_ERROR_TOLERANCE     3 // (mm) Tolerance for early trigger (<= -probe.offset.z + ZPET)  // 过早触发的容差范围（毫米）。探头触发时，如果 Z 轴位置低于 -probe.offset.z + Z_PROBE_ERROR_TOLERANCE，则认为是过早触发。
//#define Z_AFTER_PROBING           5 // (mm) Z position after probing is done  // 探测完成后的 Z 轴位置（毫米）

#define Z_PROBE_LOW_POINT          -2 // (mm) Farthest distance below the trigger-point to go before stopping  // 探测时，探头触发点以下的最远距离（毫米）。如果探头在触发点以下继续下降超过这个距离，则停止探测并报告错误。

// For M851 provide ranges for adjusting the X, Y, and Z probe offsets  //// 用于 M851 指令：设置探头 X、Y、Z 偏移量的可调范围
//#define PROBE_OFFSET_XMIN -50   // (mm)
//#define PROBE_OFFSET_XMAX  50   // (mm)
//#define PROBE_OFFSET_YMIN -50   // (mm)
//#define PROBE_OFFSET_YMAX  50   // (mm)
//#define PROBE_OFFSET_ZMIN -20   // (mm)
//#define PROBE_OFFSET_ZMAX  20   // (mm)

// Enable the M48 repeatability test to test probe accuracy  // 启用 M48 重复性测试以测试探头的准确性
//#define Z_MIN_PROBE_REPEATABILITY_TEST

// Before deploy/stow pause for user confirmation  // 在伸出/收回探头之前暂停，等待用户确认
//#define PAUSE_BEFORE_DEPLOY_STOW
#if ENABLED(PAUSE_BEFORE_DEPLOY_STOW)
  //#define PAUSE_PROBE_DEPLOY_WHEN_TRIGGERED // For Manual Deploy Allenkey Probe //用于：手动展开式内六角探头（老式三角洲机械探头）
#endif

/**
 * Enable one or more of the following if probing seems unreliable.
 * Heaters and/or fans can be disabled during probing to minimize electrical
 * noise. A delay can also be added to allow noise and vibration to settle.
 * These options are most useful for the BLTouch probe, but may also improve
 * readings with inductive probes and piezo sensors.
 * 
 * 
 * 如果探测（调平）看起来不可靠，启用以下一个或多个选项。
 * 可以在探测期间关闭加热器和/或风扇，以最小化电气干扰。
 * 还可以添加延迟，让干扰和振动稳定下来。
 * 这些选项对 BLTouch 探头最有用，但也可能改善
 * 电感式探头和压电传感器的读数。
 * 
 * 注（译者注）：
 * 这是专门解决 BLTouch 误触、调平失败、乱跳的抗干扰设置
 * 打印机的加热棒、风扇工作时会产生电磁干扰，干扰可能会让 BLTouch 乱触发、假触发
 *
 */
//#define PROBING_HEATERS_OFF       // Turn heaters off when probing //探测调平时，关闭加热器
#if ENABLED(PROBING_HEATERS_OFF)
  //#define WAIT_FOR_BED_HEATER     // Wait for bed to heat back up between probes (to improve accuracy) //在探测间隙等待热床重新升温（以提高精度）
  //#define WAIT_FOR_HOTEND         // Wait for hotend to heat back up between probes (to improve accuracy & prevent cold extrude)  //在探测间隙等待热端重新升温（以提高精度并防止冷挤出）
#endif
//#define PROBING_FANS_OFF          // Turn fans off when probing  //探测调平时，关闭风扇
//#define PROBING_ESTEPPERS_OFF     // Turn all extruder steppers off when probing  //探测调平时，关闭所有挤出机电机
//#define PROBING_STEPPERS_OFF      // Turn all steppers off (unless needed to hold position) when probing (including extruders)  //探测调平时，关闭所有电机（除非需要保持位置）（包括挤出机电机）
//#define DELAY_BEFORE_PROBING 200  // (ms) To prevent vibrations from triggering piezo sensors  //探测前的延迟（毫秒），以防止振动触发压电传感器

// Require minimum nozzle and/or bed temperature for probing  // 要求探测时喷嘴和/或热床的最低温度
//#define PREHEAT_BEFORE_PROBING
#if ENABLED(PREHEAT_BEFORE_PROBING)
  #define PROBING_NOZZLE_TEMP 120   // (°C) Only applies to E0 at this time  // 探测时喷嘴的最低温度（摄氏度）。目前仅适用于 E0。
  #define PROBING_BED_TEMP     50
#endif

// @section stepper drivers

// For Inverting Stepper Enable Pins (Active Low) use 0, Non Inverting (Active High) use 1
// 对于【低电平有效】的步进电机使能引脚，使用 0
// 对于【高电平有效】的步进电机使能引脚，使用 1
// :['LOW', 'HIGH']
#define X_ENABLE_ON LOW
#define Y_ENABLE_ON LOW
#define Z_ENABLE_ON LOW
#define E_ENABLE_ON LOW // For all extruders //应用于所有挤出机（喷头电机）
//#define I_ENABLE_ON LOW
//#define J_ENABLE_ON LOW
//#define K_ENABLE_ON LOW
//#define U_ENABLE_ON LOW
//#define V_ENABLE_ON LOW
//#define W_ENABLE_ON LOW

// Disable axis steppers immediately when they're not being stepped.
// WARNING: When motors turn off there is a chance of losing position accuracy!
// 当轴电机不工作时，立即关闭其电源。
// 警告：电机断电后，有可能会丢失位置精度！
//#define DISABLE_X
//#define DISABLE_Y
//#define DISABLE_Z
//#define DISABLE_I
//#define DISABLE_J
//#define DISABLE_K
//#define DISABLE_U
//#define DISABLE_V
//#define DISABLE_W

// Turn off the display blinking that warns about possible accuracy reduction  // 关闭显示屏上关于可能降低精度的警告闪烁
//#define DISABLE_REDUCED_ACCURACY_WARNING

// @section extruder

//#define DISABLE_E               // Disable the extruder when not stepping  //挤出机电机不转动时，关闭电机电源
#define DISABLE_OTHER_EXTRUDERS   // Keep only the active extruder enabled  //仅保持当前活动挤出机启用，其他挤出机关闭

// @section motion

// Invert the stepper direction. Change (or reverse the motor connector) if an axis goes the wrong way.
// 反转步进电机方向。
// 如果某个轴移动方向反了，修改这里（或者反插电机线）即可。
#define INVERT_X_DIR false
#define INVERT_Y_DIR true
#define INVERT_Z_DIR false
//#define INVERT_I_DIR false
//#define INVERT_J_DIR false
//#define INVERT_K_DIR false
//#define INVERT_U_DIR false
//#define INVERT_V_DIR false
//#define INVERT_W_DIR false

// @section extruder

// For direct drive extruder v9 set to true, for geared extruder set to false.
// 直驱挤出机 v9 版本设置为 true，齿轮减速挤出机设置为 false。
#define INVERT_E0_DIR false
#define INVERT_E1_DIR false
#define INVERT_E2_DIR false
#define INVERT_E3_DIR false
#define INVERT_E4_DIR false
#define INVERT_E5_DIR false
#define INVERT_E6_DIR false
#define INVERT_E7_DIR false

// @section homing

//#define NO_MOTION_BEFORE_HOMING // Inhibit movement until all axes have been homed. Also enable HOME_AFTER_DEACTIVATE for extra safety.  在所有轴完成归位（回零）之前，禁止任何移动。同时建议启用 HOME_AFTER_DEACTIVATE 以获得额外的安全性。
//#define HOME_AFTER_DEACTIVATE   // Require rehoming after steppers are deactivated. Also enable NO_MOTION_BEFORE_HOMING for extra safety.  在步进电机断电后需要重新归位（回零）。同时建议启用 NO_MOTION_BEFORE_HOMING 以获得额外的安全性。

/**
 * Set Z_IDLE_HEIGHT if the Z-Axis moves on its own when steppers are disabled.
 *  - Use a low value (i.e., Z_MIN_POS) if the nozzle falls down to the bed.
 *  - Use a large value (i.e., Z_MAX_POS) if the bed falls down, away from the nozzle.
 * 
 * 如果步进电机禁用时 Z 轴会自己移动，请设置 Z_IDLE_HEIGHT。
 *  - 如果喷嘴会自己掉落到热床上，使用较小的值（例如 Z_MIN_POS）。
 *  - 如果热床会自己向下远离喷嘴，使用较大的值（例如 Z_MAX_POS）。
 * 注（译者注）：
 * 如果你的打印机电机断电后热床自己往下掉，或者喷头自己往下压，请进行这些设置。
 *
 */
//#define Z_IDLE_HEIGHT Z_HOME_POS

//#define Z_CLEARANCE_FOR_HOMING  4   // (mm) Minimal Z height before homing (G28) for Z clearance above the bed, clamps, ...
                                      // You'll need this much clearance above Z_MAX_POS to avoid grinding.
                                      // (mm) 归位 (G28) 前的最小 Z 高度
                                     // 确保喷嘴高于热床、夹子、支架等障碍物
                                     // 必须高于 Z_MAX_POS 这个距离，避免齿轮摩擦、撞机

//#define Z_AFTER_HOMING         10   // (mm) Height to move to after homing (if Z was homed)  // 归位后（如果 Z 轴完成归位）移动到的高度（毫米）
//#define XY_AFTER_HOMING { 10, 10 }  // (mm) Move to an XY position after homing (and raising Z)  // 归位后（并抬高 Z 轴）移动到的 XY 坐标（毫米）

//#define EVENT_GCODE_AFTER_HOMING "M300 P440 S200"  // Commands to run after G28 (and move to XY_AFTER_HOMING)  // G28 后（并移动到 XY_AFTER_HOMING）执行的指令

// Direction of endstops when homing; 1=MAX, -1=MIN
// 轴回零的方向（限位开关位置）
// 1 = 往 MAX 方向回零（最大位置/顶部）
// -1 = 往 MIN 方向回零（最小位置/原点）
// :[-1,1]
#define X_HOME_DIR -1
#define Y_HOME_DIR -1
#define Z_HOME_DIR -1
//#define I_HOME_DIR -1
//#define J_HOME_DIR -1
//#define K_HOME_DIR -1
//#define U_HOME_DIR -1
//#define V_HOME_DIR -1
//#define W_HOME_DIR -1

/**
 * Safety Stops
 * If an axis has endstops on both ends the one specified above is used for
 * homing, while the other can be used for things like SD_ABORT_ON_ENDSTOP_HIT.
 * 
 * 安全限位
 * 如果一个轴的两端都有限位开关：
 * 上面指定的那个（homing方向）用于回零，
 * 另一个可以用于安全功能，例如触发 SD 卡打印中断等。
 *
 */
//#define X_SAFETY_STOP
//#define Y_SAFETY_STOP
//#define Z_SAFETY_STOP
//#define I_SAFETY_STOP
//#define J_SAFETY_STOP
//#define K_SAFETY_STOP
//#define U_SAFETY_STOP
//#define V_SAFETY_STOP
//#define W_SAFETY_STOP

// @section geometry

// The size of the printable area  // 可打印区域的尺寸
#define X_BED_SIZE 200
#define Y_BED_SIZE 200

// Travel limits (linear=mm, rotational=°) after homing, corresponding to endstop positions.
// 回零后的运动限制（直线单位：mm，旋转单位：°），对应限位开关的位置。
// 注（译者注）：
// 它的意思是：
// 下面的 X、Y、Z 坐标限制，是打印机回零后能移动到的 最远/最高/最低位置
// 决定了喷头不能超出的安全范围，防止撞机、掉轴
#define X_MIN_POS 0
#define Y_MIN_POS 0
#define Z_MIN_POS 0
#define X_MAX_POS X_BED_SIZE
#define Y_MAX_POS Y_BED_SIZE
#define Z_MAX_POS 200
//#define I_MIN_POS 0
//#define I_MAX_POS 50
//#define J_MIN_POS 0
//#define J_MAX_POS 50
//#define K_MIN_POS 0
//#define K_MAX_POS 50
//#define U_MIN_POS 0
//#define U_MAX_POS 50
//#define V_MIN_POS 0
//#define V_MAX_POS 50
//#define W_MIN_POS 0
//#define W_MAX_POS 50

/**
 * Software Endstops
 *
 * - Prevent moves outside the set machine bounds.
 * - Individual axes can be disabled, if desired.
 * - X and Y only apply to Cartesian robots.
 * - Use 'M211' to set software endstops on/off or report current state
 * 
 * 软件限位开关
 *
 * - 防止移动超出设定的机器边界。
 * - 可根据需要单独禁用某个轴。
 * - X 和 Y 仅适用于笛卡尔结构打印机。
 * - 使用指令 'M211' 来开启/关闭软件限位或查看当前状态。
 *
 */

// Min software endstops constrain movement within minimum coordinate bounds
// 最小坐标软件限位：限制轴不能移动到最小坐标范围之外
#define MIN_SOFTWARE_ENDSTOPS
#if ENABLED(MIN_SOFTWARE_ENDSTOPS)
  #define MIN_SOFTWARE_ENDSTOP_X
  #define MIN_SOFTWARE_ENDSTOP_Y
  #define MIN_SOFTWARE_ENDSTOP_Z
  #define MIN_SOFTWARE_ENDSTOP_I
  #define MIN_SOFTWARE_ENDSTOP_J
  #define MIN_SOFTWARE_ENDSTOP_K
  #define MIN_SOFTWARE_ENDSTOP_U
  #define MIN_SOFTWARE_ENDSTOP_V
  #define MIN_SOFTWARE_ENDSTOP_W
#endif

// Max software endstops constrain movement within maximum coordinate bounds
// 最大坐标软件限位：限制轴不能移动超出最大坐标范围
#define MAX_SOFTWARE_ENDSTOPS
#if ENABLED(MAX_SOFTWARE_ENDSTOPS)
  #define MAX_SOFTWARE_ENDSTOP_X
  #define MAX_SOFTWARE_ENDSTOP_Y
  #define MAX_SOFTWARE_ENDSTOP_Z
  #define MAX_SOFTWARE_ENDSTOP_I
  #define MAX_SOFTWARE_ENDSTOP_J
  #define MAX_SOFTWARE_ENDSTOP_K
  #define MAX_SOFTWARE_ENDSTOP_U
  #define MAX_SOFTWARE_ENDSTOP_V
  #define MAX_SOFTWARE_ENDSTOP_W
#endif

#if ANY(MIN_SOFTWARE_ENDSTOPS, MAX_SOFTWARE_ENDSTOPS)
  //#define SOFT_ENDSTOPS_MENU_ITEM  // Enable/Disable software endstops from the LCD  
  // 从 LCD 菜单启用/禁用软件限位
  // 注（译者注）：开启后，能直接在打印机屏幕菜单里开关软件防撞限位，不用改固件重刷。
#endif

/**
 * @section filament runout sensors
 *
 * Filament Runout Sensors
 * Mechanical or opto endstops are used to check for the presence of filament.
 *
 * IMPORTANT: Runout will only trigger if Marlin is aware that a print job is running.
 * Marlin knows a print job is running when:
 *  1. Running a print job from media started with M24.
 *  2. The Print Job Timer has been started with M75.
 *  3. The heaters were turned on and PRINTJOB_TIMER_AUTOSTART is enabled.
 *
 * RAMPS-based boards use SERVO3_PIN for the first runout sensor.
 * For other boards you may need to define FIL_RUNOUT_PIN, FIL_RUNOUT2_PIN, etc.
 * 
 * 
 * @section 耗材检测传感器
 *
 * 耗材检测传感器
 * 机械或光电限位开关，用于检测耗材是否存在。
 *
 * 重要提示：仅当 Marlin 固件【识别到正在打印】时，断料检测才会触发。
 * 固件判定正在打印的条件：
 *  1. 通过 M24 指令开始从存储设备打印。
 *  2. 通过 M75 指令启动了打印计时器。
 *  3. 加热器已开启，且启用了 PRINTJOB_TIMER_AUTOSTART。
 *
 * RAMPS 系列主板使用 SERVO3_PIN 连接第一个断料传感器。
 * 其他主板可能需要手动定义 FIL_RUNOUT_PIN、FIL_RUNOUT2_PIN 等引脚。
 *
 */
//#define FILAMENT_RUNOUT_SENSOR
#if ENABLED(FILAMENT_RUNOUT_SENSOR)
  #define FIL_RUNOUT_ENABLED_DEFAULT true // Enable the sensor on startup. Override with M412 followed by M500.  // 启动时启用传感器。可以通过 M412 指令（之后跟 M500 保存）来覆盖默认设置。
  #define NUM_RUNOUT_SENSORS   1          // Number of sensors, up to one per extruder. Define a FIL_RUNOUT#_PIN for each.  // 传感器数量，每个挤出机最多一个。为每个传感器定义一个 FIL_RUNOUT#_PIN。

  #define FIL_RUNOUT_STATE     LOW        // Pin state indicating that filament is NOT present.  // 传感器引脚状态，表示没有耗材时的信号状态
  #define FIL_RUNOUT_PULLUP               // Use internal pullup for filament runout pins.  // 使用内部上拉电阻连接断料传感器引脚
  //#define FIL_RUNOUT_PULLDOWN           // Use internal pulldown for filament runout pins.  // 使用内部下拉电阻连接断料传感器引脚
  //#define WATCH_ALL_RUNOUT_SENSORS      // Execute runout script on any triggering sensor, not only for the active extruder.
                                          // This is automatically enabled for MIXING_EXTRUDERs.
                                          // 任意一个断料传感器触发时，都执行断料处理程序，而不仅仅是当前工作的挤出机。
                                          // 混合挤出机（多进一出）会自动启用此功能。

  // Override individually if the runout sensors vary  //// 如果各个断料传感器的状态不同，可单独覆盖设置
  //#define FIL_RUNOUT1_STATE LOW
  //#define FIL_RUNOUT1_PULLUP
  //#define FIL_RUNOUT1_PULLDOWN

  //#define FIL_RUNOUT2_STATE LOW
  //#define FIL_RUNOUT2_PULLUP
  //#define FIL_RUNOUT2_PULLDOWN

  //#define FIL_RUNOUT3_STATE LOW
  //#define FIL_RUNOUT3_PULLUP
  //#define FIL_RUNOUT3_PULLDOWN

  //#define FIL_RUNOUT4_STATE LOW
  //#define FIL_RUNOUT4_PULLUP
  //#define FIL_RUNOUT4_PULLDOWN

  //#define FIL_RUNOUT5_STATE LOW
  //#define FIL_RUNOUT5_PULLUP
  //#define FIL_RUNOUT5_PULLDOWN

  //#define FIL_RUNOUT6_STATE LOW
  //#define FIL_RUNOUT6_PULLUP
  //#define FIL_RUNOUT6_PULLDOWN

  //#define FIL_RUNOUT7_STATE LOW
  //#define FIL_RUNOUT7_PULLUP
  //#define FIL_RUNOUT7_PULLDOWN

  //#define FIL_RUNOUT8_STATE LOW
  //#define FIL_RUNOUT8_PULLUP
  //#define FIL_RUNOUT8_PULLDOWN

  // Commands to execute on filament runout.  //耗材断料时要执行的指令
  // With multiple runout sensors use the %c placeholder for the current tool in commands (e.g., "M600 T%c")//当使用多个断料传感器时，可在指令中使用 %c 占位符表示当前触发断料的喷头/工具。示例："M600 T%c"
  // NOTE: After 'M412 H1' the host handles filament runout and this script does not apply.  //注意：执行 'M412 H1' 后，主机将处理断料事件，此时此脚本不再适用。
  #define FILAMENT_RUNOUT_SCRIPT "M600"

  // After a runout is detected, continue printing this length of filament  
  // before executing the runout script. Useful for a sensor at the end of
  // a feed tube. Requires 4 bytes SRAM per sensor, plus 4 bytes overhead.
   // 检测到断料后，继续打印这段长度的耗材，然后再执行断料处理程序。对于安装在送料管末端的传感器非常有用。每个传感器需要 4 字节 SRAM，加上 4 字节的开销。
  //#define FILAMENT_RUNOUT_DISTANCE_MM 25

  #ifdef FILAMENT_RUNOUT_DISTANCE_MM
    // Enable this option to use an encoder disc that toggles the runout pin
    // as the filament moves. (Be sure to set FILAMENT_RUNOUT_DISTANCE_MM
    // large enough to avoid false positives.)  
     // 启用此选项以使用编码盘，随着耗材移动切换断料引脚状态。（请确保将 FILAMENT_RUNOUT_DISTANCE_MM 设置得足够大，以避免误报。）
    //#define FILAMENT_MOTION_SENSOR

    #if ENABLED(FILAMENT_MOTION_SENSOR)
      //#define FILAMENT_SWITCH_AND_MOTION      // Define separate pins below to sense motion  // 定义下面的单独引脚来检测运动
      #if ENABLED(FILAMENT_SWITCH_AND_MOTION)

        #define FILAMENT_MOTION_DISTANCE_MM 3.0 // (mm) Missing distance required to trigger runout // (毫米) 触发断料检测所需的【空跑距离】

        #define NUM_MOTION_SENSORS   1          // Number of sensors, up to one per extruder. Define a FIL_MOTION#_PIN for each.  // 运动传感器数量，每个挤出机最多一个。为每个传感器定义一个 FIL_MOTION#_PIN。
        //#define FIL_MOTION1_PIN    -1

        // Override individually if the motion sensors vary  // 如果各个运动传感器的状态不同，可单独覆盖设置
        //#define FIL_MOTION1_STATE LOW
        //#define FIL_MOTION1_PULLUP
        //#define FIL_MOTION1_PULLDOWN

        //#define FIL_MOTION2_STATE LOW
        //#define FIL_MOTION2_PULLUP
        //#define FIL_MOTION2_PULLDOWN

        //#define FIL_MOTION3_STATE LOW
        //#define FIL_MOTION3_PULLUP
        //#define FIL_MOTION3_PULLDOWN

        //#define FIL_MOTION4_STATE LOW
        //#define FIL_MOTION4_PULLUP
        //#define FIL_MOTION4_PULLDOWN

        //#define FIL_MOTION5_STATE LOW
        //#define FIL_MOTION5_PULLUP
        //#define FIL_MOTION5_PULLDOWN

        //#define FIL_MOTION6_STATE LOW
        //#define FIL_MOTION6_PULLUP
        //#define FIL_MOTION6_PULLDOWN

        //#define FIL_MOTION7_STATE LOW
        //#define FIL_MOTION7_PULLUP
        //#define FIL_MOTION7_PULLDOWN

        //#define FIL_MOTION8_STATE LOW
        //#define FIL_MOTION8_PULLUP
        //#define FIL_MOTION8_PULLDOWN
      #endif // FILAMENT_SWITCH_AND_MOTION
    #endif // FILAMENT_MOTION_SENSOR
  #endif // FILAMENT_RUNOUT_DISTANCE_MM
#endif // FILAMENT_RUNOUT_SENSOR

//===========================================================================
//=============================== Bed Leveling ==============================
//===========================================================================
// 热床调平相关配置
// @section calibrate

/**
 * Choose one of the options below to enable G29 Bed Leveling. The parameters
 * and behavior of G29 will change depending on your selection.
 *
 *  If using a Probe for Z Homing, enable Z_SAFE_HOMING also!
 *
 * - AUTO_BED_LEVELING_3POINT
 *   Probe 3 arbitrary points on the bed (that aren't collinear)
 *   You specify the XY coordinates of all 3 points.
 *   The result is a single tilted plane. Best for a flat bed.
 *
 * - AUTO_BED_LEVELING_LINEAR
 *   Probe several points in a grid.
 *   You specify the rectangle and the density of sample points.
 *   The result is a single tilted plane. Best for a flat bed.
 *
 * - AUTO_BED_LEVELING_BILINEAR
 *   Probe several points in a grid.
 *   You specify the rectangle and the density of sample points.
 *   The result is a mesh, best for large or uneven beds.
 *
 * - AUTO_BED_LEVELING_UBL (Unified Bed Leveling)
 *   A comprehensive bed leveling system combining the features and benefits
 *   of other systems. UBL also includes integrated Mesh Generation, Mesh
 *   Validation and Mesh Editing systems.
 *
 * - MESH_BED_LEVELING
 *   Probe a grid manually
 *   The result is a mesh, suitable for large or uneven beds. (See BILINEAR.)
 *   For machines without a probe, Mesh Bed Leveling provides a method to perform
 *   leveling in steps so you can manually adjust the Z height at each grid-point.
 *   With an LCD controller the process is guided step-by-step.
 * 
 * 
 * 选择以下其中一种模式启用 G29 热床调平。
 * G29 的参数和行为会根据你的选择而变化。
 *
 * 如果使用探头进行 Z 轴回零，还必须启用 Z_SAFE_HOMING！
 *
 * - AUTO_BED_LEVELING_3POINT
 *   在热床上探测 3 个不共线的点
 *   你需要指定这 3 个点的 XY 坐标
 *   生成一个倾斜平面，适合**平整的热床**
 *
 * - AUTO_BED_LEVELING_LINEAR
 *   网格探测多个点
 *   你指定探测范围和点密度
 *   生成一个倾斜平面，适合**平整的热床**
 *
 * - AUTO_BED_LEVELING_BILINEAR
 *   网格探测多个点
 *   你指定探测范围和点密度
 *   生成网格补偿，适合**大尺寸/不平整热床**
 *
 * - AUTO_BED_LEVELING_UBL (统一调平系统)
 *   最全面的调平系统，整合所有优点
 *   包含网格生成、验证、编辑功能
 *
 * - MESH_BED_LEVELING
 *   手动网格调平
 *   生成网格补偿，适合**无自动探头**的机器
 *   通过屏幕一步步手动调整每个点的 Z 高度
 *
 */
//#define AUTO_BED_LEVELING_3POINT
//#define AUTO_BED_LEVELING_LINEAR
//#define AUTO_BED_LEVELING_BILINEAR
//#define AUTO_BED_LEVELING_UBL
//#define MESH_BED_LEVELING

/**
 * Commands to execute at the start of G29 probing,
 * after switching to the PROBING_TOOL.
 * // 在 G29 探测开始时、切换到探测工具后执行的指令
 */
//#define EVENT_GCODE_BEFORE_G29 "M300 P440 S200"

/**
 * Commands to execute at the end of G29 probing.
 * Useful to retract or move the Z probe out of the way.
 * // G29调平探测结束后执行的指令
 * // 适合用来回抽耗材、移动Z轴探头避开工作区域
 */
//#define EVENT_GCODE_AFTER_G29 "G1 Z10 F12000\nG1 X15 Y330\nG1 Z0.5\nG1 Z10"

/**
 * Normally G28 leaves leveling disabled on completion. Enable one of
 * these options to restore the prior leveling state or to always enable
 * leveling immediately after G28.
 * 
 * 通常 G28（回零）完成后会自动关闭热床调平功能。
 * 启用以下任一选项，可以在 G28 结束后恢复之前的调平状态，
 * 或者始终在回零后立即启用调平。
 *
 */
//#define RESTORE_LEVELING_AFTER_G28
//#define ENABLE_LEVELING_AFTER_G28

/**
 * Auto-leveling needs preheating  // 自动调平前需要提前预热
 * 注（译者注）：
 * 调平前需要加热热床，因为升温会导致热床产生形变。模拟实际打印温度环境，贴合真实打印工况
 */
//#define PREHEAT_BEFORE_LEVELING
#if ENABLED(PREHEAT_BEFORE_LEVELING)
  #define LEVELING_NOZZLE_TEMP 120   // (°C) Only applies to E0 at this time  // 调平前喷嘴的预热温度（摄氏度）。目前仅适用于 E0。
  #define LEVELING_BED_TEMP     50
#endif

/**
 * Enable detailed logging of G28, G29, M48, etc.
 * Turn on with the command 'M111 S32'.
 * NOTE: Requires a lot of flash!
 * 
 * 启用 G28、G29、M48 等指令的详细日志记录
 * 使用指令 'M111 S32' 开启
 * 注意：会占用大量闪存空间！
 *
 */
//#define DEBUG_LEVELING_FEATURE

#if ANY(MESH_BED_LEVELING, AUTO_BED_LEVELING_UBL, PROBE_MANUALLY)
  // Set a height for the start of manual adjustment  // 设置手动调整开始的高度
  #define MANUAL_PROBE_START_Z 0.2  // (mm) Comment out to use the last-measured height  //（毫米）注释掉以使用上次测量的高度
#endif

#if ANY(MESH_BED_LEVELING, AUTO_BED_LEVELING_BILINEAR, AUTO_BED_LEVELING_UBL)
  /**
   * Gradually reduce leveling correction until a set height is reached,
   * at which point movement will be level to the machine's XY plane.
   * The height can be set with M420 Z<height>
   * 
   * 逐渐减小调平补偿量，直到达到设定高度，
   * 在该高度之后，打印机会完全按照机器的 XY 平面水平移动。
   * 可以使用指令 M420 Z<高度> 来设置这个高度。
   * 注（译者注）：
   * 这是一个非常实用的功能，能让打印机在底层（首层）全力使用热床调平补偿，确保打印粘牢不刮床。
   * 随着高度升高，补偿量慢慢变小，到达设定高度（比如 5mm）后，补偿完全消失，打印机按绝对水平打印。
   * 这样能兼顾底层的粘附和后续层的精度，避免过度补偿导致的后续层错位。
   *
   */
  #define ENABLE_LEVELING_FADE_HEIGHT
  #if ENABLED(ENABLE_LEVELING_FADE_HEIGHT)
    #define DEFAULT_LEVELING_FADE_HEIGHT 10.0 // (mm) Default fade height. //（毫米）默认淡出高度。(设置为 0 可禁用淡出。)
  #endif

  /**
   * For Cartesian machines, instead of dividing moves on mesh boundaries,
   * split up moves into short segments like a Delta. This follows the
   * contours of the bed more closely than edge-to-edge straight moves.  
   * 对于笛卡尔结构的机器，不要在网格边界上分割移动，而是将移动分成短段，就像 Delta 结构一样。这比边到边的直线移动更贴合热床的轮廓。
   * 注（译者注）：这是自动调平的高精度优化.
   * 它可以：
   * 普通网格调平：喷头在网格之间直线移动，可能跳变高度
   * 开启后：把移动切成5mm 小段，平滑贴合热床曲面
   * 让首层打印更平整、不刮床、不悬空
   */
  #define SEGMENT_LEVELED_MOVES
  #define LEVELED_SEGMENT_LENGTH 5.0 // (mm) Length of all segments (except the last one)  //（毫米）所有段的长度（最后一段除外）。设置为 0 可禁用分段。

  /**
   * Enable the G26 Mesh Validation Pattern tool. // 启用 G26 网格校验测试图案工具
   * 注（译者注）：开启后可使用G26指令，打印专用测试纹路，直观检查热床网格调平效果，快速判断高低落差、首层贴合好坏。
   */
  //#define G26_MESH_VALIDATION
  #if ENABLED(G26_MESH_VALIDATION)
    #define MESH_TEST_NOZZLE_SIZE    0.4  // (mm) Diameter of primary nozzle.  //（毫米）主喷嘴的直径。
    #define MESH_TEST_LAYER_HEIGHT   0.2  // (mm) Default layer height for G26.  //（毫米）G26 的默认层高。
    #define MESH_TEST_HOTEND_TEMP  205    // (°C) Default nozzle temperature for G26.  //（摄氏度）G26 的默认喷嘴温度。
    #define MESH_TEST_BED_TEMP      60    // (°C) Default bed temperature for G26.  //（摄氏度）G26 的默认热床温度。
    #define G26_XY_FEEDRATE         20    // (mm/s) Feedrate for G26 XY moves.  //（毫米/秒）G26 XY 移动的进给速度。
    #define G26_XY_FEEDRATE_TRAVEL 100    // (mm/s) Feedrate for G26 XY travel moves.  //（毫米/秒）G26 XY 跳跃移动的进给速度。
    #define G26_RETRACT_MULTIPLIER   1.0  // G26 Q (retraction) used by default between mesh test elements.  // G26 Q（回抽）默认用于网格测试元素之间。
  #endif

#endif

#if ANY(AUTO_BED_LEVELING_LINEAR, AUTO_BED_LEVELING_BILINEAR)

  // Set the number of grid points per dimension.  // 设置每个维度的网格点数量
  #define GRID_MAX_POINTS_X 3
  #define GRID_MAX_POINTS_Y GRID_MAX_POINTS_X

  // Probe along the Y axis, advancing X after each column  // 沿 Y 轴探测，每列完成后前进 X 轴
  //#define PROBE_Y_FIRST

  #if ENABLED(AUTO_BED_LEVELING_BILINEAR)

    // Beyond the probed grid, continue the implied tilt?  // 在探测网格之外，继续应用隐含的倾斜补偿吗？
    // Default is to maintain the height of the nearest edge.  // 默认是保持最近边缘的高度。
    //#define EXTRAPOLATE_BEYOND_GRID

    //
    // Subdivision of the grid by Catmull-Rom method.
    // Synthesizes intermediate points to produce a more detailed mesh.
    // 使用 Catmull-Rom 算法对网格进行细分
    // 自动生成中间插值点，让调平网格更细腻、更精准
    //
    //#define ABL_BILINEAR_SUBDIVISION
    #if ENABLED(ABL_BILINEAR_SUBDIVISION)
      // Number of subdivisions between probe points  // 探测点之间的细分数量
      #define BILINEAR_SUBDIVISIONS 3
    #endif

  #endif

#elif ENABLED(AUTO_BED_LEVELING_UBL)

  //===========================================================================
  //========================= Unified Bed Leveling ============================
  //===========================================================================
  // 统一热床调平系统（UBL）—— Marlin 里最强大、最完整的自动调平模式

  //#define MESH_EDIT_GFX_OVERLAY   // Display a graphics overlay while editing the mesh // 编辑调平网格时，屏幕显示图形可视化图层

  #define MESH_INSET 1              // Set Mesh bounds as an inset region of the bed  // 设置网格边界为热床内缩区域
  #define GRID_MAX_POINTS_X 10      // Don't use more than 15 points per axis, implementation limited.  // 每轴不要使用超过 15 个点，受实现限制
  #define GRID_MAX_POINTS_Y GRID_MAX_POINTS_X

  //#define UBL_HILBERT_CURVE       // Use Hilbert distribution for less travel when probing multiple points  // 使用 Hilbert 曲线分布，在探测多个点时减少移动距离

  //#define UBL_TILT_ON_MESH_POINTS         // Use nearest mesh points with G29 J for better Z reference  // 使用 G29 J 指令时，使用最近的网格点作为更好的 Z 参考
  //#define UBL_TILT_ON_MESH_POINTS_3POINT  // Use nearest mesh points with G29 J0 (3-point)  // 使用 G29 J0（3点）指令时，使用最近的网格点作为更好的 Z 参考

  #define UBL_MESH_EDIT_MOVES_Z     // Sophisticated users prefer no movement of nozzle  // 资深用户偏好：编辑网格时不让喷嘴移动

  #define UBL_SAVE_ACTIVE_ON_M500   // Save the currently active mesh in the current slot on M500  // 在 M500 时将当前活动的网格保存在当前槽位

  //#define UBL_Z_RAISE_WHEN_OFF_MESH 2.5 // When the nozzle is off the mesh, this value is used
                                          // as the Z-Height correction value.
                                          // 当喷头移动到【调平网格以外区域】时，使用该值作为 Z 高度补偿

  //#define UBL_MESH_WIZARD         // Run several commands in a row to get a complete mesh  // 运行一系列命令来获得完整的网格

  /**
   * Probing not allowed within the position of an obstacle.  // 在障碍物位置不允许探测
   * 注（译者注）：可划定热床上障碍物区域（如螺丝、接线柱、固定卡扣等），探头运行到这片区域时，自动跳过不进行测高，避免探头撞击硬物损坏、测量数据出错。
   */
  //#define AVOID_OBSTACLES
  #if ENABLED(AVOID_OBSTACLES)
    #define CLIP_W  23  // Bed clip width, should be padded a few mm over its physical size  // 床夹宽度，应该比实际尺寸多预留几毫米的安全边距
    #define CLIP_H  14  // Bed clip height, should be padded a few mm over its physical size  // 床夹高度，应该比实际尺寸多预留几毫米的安全边距
    //注（译者注）：上面是给热床夹子（固定热床的夹子）设置的避障区域。

    // Obstacle Rectangles defined as { X1, Y1, X2, Y2 }// 障碍物矩形区域，格式定义为 { X1, Y1, X2, Y2 }
    // 注（译者注）：下面是给热床四个角的夹子设置的避障区域。每个夹子占一个矩形区域。X1, Y1 = 矩形左上角坐标，X2, Y2 = 矩形右下角坐标
    #define OBSTACLE1 { (X_BED_SIZE) / 4     - (CLIP_W) / 2,                       0, (X_BED_SIZE) / 4     + (CLIP_W) / 2, CLIP_H }
    #define OBSTACLE2 { (X_BED_SIZE) * 3 / 4 - (CLIP_W) / 2,                       0, (X_BED_SIZE) * 3 / 4 + (CLIP_W) / 2, CLIP_H }
    #define OBSTACLE3 { (X_BED_SIZE) / 4     - (CLIP_W) / 2, (Y_BED_SIZE) - (CLIP_H), (X_BED_SIZE) / 4     + (CLIP_W) / 2, Y_BED_SIZE }
    #define OBSTACLE4 { (X_BED_SIZE) * 3 / 4 - (CLIP_W) / 2, (Y_BED_SIZE) - (CLIP_H), (X_BED_SIZE) * 3 / 4 + (CLIP_W) / 2, Y_BED_SIZE }

    // The probed grid must be inset for G29 J. This is okay, since it is
    // only used to compute a linear transformation for the mesh itself.
    // 对于 G29 J 指令，探测网格必须向内缩进。
    // 这是正常的，因为它仅用于计算网格自身的线性变换（倾斜校正）。
    // 注（译者注）：G29J_MESH_TILT_MARGIN 定义了在网格边缘留出的安全距离。
    // 简单说就是：
    // G29 J = UBL 里的倾斜校正 / 整平指令
    // 它工作时，会自动向内缩一点探测范围，不贴边
    // 因为它只用来修正整体倾斜，不需要测边缘
    // 缩进去是安全、正常、设计好的行为
    #define G29J_MESH_TILT_MARGIN ((CLIP_H) + 1)
  #endif

#elif ENABLED(MESH_BED_LEVELING)

  //===========================================================================
  //=================================== Mesh ==================================
  //===========================================================================
  // 热床调平网格相关配置

  #define MESH_INSET 10          // Set Mesh bounds as an inset region of the bed  // 设置网格边界为热床内缩区域
  #define GRID_MAX_POINTS_X 3
  #define GRID_MAX_POINTS_Y GRID_MAX_POINTS_X

  //#define MESH_G28_REST_ORIGIN // After homing all axes ('G28' or 'G28 XYZ') rest Z at Z_MIN_POS 
  // 回零所有轴（G28 或 G28 XYZ）之后，将 Z 轴重新归零到 Z_MIN_POS 位置
  // 注（译者注）：你发 G28 → XYZ 全部回零，探头触底 → 机械上找到 Z 最低点

#endif // BED_LEVELING  //热床调平 / 平台自动调平

/**
 * Add a bed leveling sub-menu for ABL or MBL.
 * Include a guided procedure if manual probing is enabled.
 * 
 * 为自动调平(ABL)或手动调平(MBL)添加一个【热床调平子菜单】
 * 如果启用了手动探测，会包含引导式操作流程。
 * 
 * 注（译者注）：这是屏幕菜单功能，
 * 在打印机液晶屏上，增加一个"热床调平"专用菜单
 * 不用发 G 代码，直接操作屏幕就能进行调平
 */
//#define LCD_BED_LEVELING

#if ENABLED(LCD_BED_LEVELING)
  #define MESH_EDIT_Z_STEP  0.025 // (mm) Step size while manually probing Z axis.  //（毫米）手动探测 Z 轴时的步进大小。设置得更小可以更精细地调整 Z 高度，但会增加调整时间。
  #define LCD_PROBE_Z_RANGE 4     // (mm) Z Range centered on Z_MIN_POS for LCD Z adjustment  //（毫米）以 Z_MIN_POS 为中心的 LCD Z 调整范围。设置为 0 将使用整个 Z 轴范围。
  //#define MESH_EDIT_MENU        // Add a menu to edit mesh points  // 添加一个菜单来编辑网格点
#endif

// Add a menu item to move between bed corners for manual bed adjustment  // 添加一个菜单项，在手动调平时可以在热床四个角之间移动
//#define LCD_BED_TRAMMING

#if ENABLED(LCD_BED_TRAMMING)
  #define BED_TRAMMING_INSET_LFRB { 30, 30, 30, 30 } // (mm) Left, Front, Right, Back insets  //（毫米）左、前、右、后边距。定义从热床边缘到调平点的距离，确保调平点在热床范围内，并避开夹具等障碍物。
  #define BED_TRAMMING_HEIGHT      0.0        // (mm) Z height of nozzle at tramming points  //（毫米）调平点喷嘴的 Z 高度。设置为 0 将使用当前 Z 位置。
  #define BED_TRAMMING_Z_HOP       4.0        // (mm) Z raise between tramming points  //（毫米）调平点之间的 Z 抬升高度。设置为 0 将禁用 Z 抬升。
  //#define BED_TRAMMING_INCLUDE_CENTER       // Move to the center after the last corner  // 在最后一个角落之后移动到中心
  //#define BED_TRAMMING_USE_PROBE
  #if ENABLED(BED_TRAMMING_USE_PROBE)
    #define BED_TRAMMING_PROBE_TOLERANCE 0.1  // (mm)
    #define BED_TRAMMING_VERIFY_RAISED        // After adjustment triggers the probe, re-probe to verify  // 调平后触发探针，重新探测以验证
    //#define BED_TRAMMING_AUDIO_FEEDBACK
  #endif

  /**
   * Corner Leveling Order
   *
   * Set 2 or 4 points. When 2 points are given, the 3rd is the center of the opposite edge.
   *
   *  LF  Left-Front    RF  Right-Front
   *  LB  Left-Back     RB  Right-Back
   * 
   * 
   * 四角调平顺序
   *
   * 可设置 2 个或 4 个点。
   * 当只设置 2 个点时，第 3 个点会自动使用对边的中心点。
   *
   *  LF  左前    RF  右前
   *  LB  左后    RB  右后
 
   *
   * Examples:(举例)
   *
   *      Default        {LF,RB,LB,RF}         {LF,RF}           {LB,LF}
   *  LB --------- RB   LB --------- RB    LB --------- RB   LB --------- RB
   *  |  4       3  |   | 3         2 |    |     <3>     |   | 1           |
   *  |             |   |             |    |             |   |          <3>|
   *  |  1       2  |   | 1         4 |    | 1         2 |   | 2           |
   *  LF --------- RF   LF --------- RF    LF --------- RF   LF --------- RF
   */
  #define BED_TRAMMING_LEVELING_ORDER { LF, RF, RB, LB }
#endif

// @section homing

// The center of the bed is at (X=0, Y=0)  // 热床中心位于 (X=0, Y=0)
//#define BED_CENTER_AT_0_0

// Manually set the home position. Leave these undefined for automatic settings.
// For DELTA this is the top-center of the Cartesian print volume.
// 手动设置原点（Home）位置。不定义这些参数则使用自动设置。
// 对于三角洲（Delta）机型，原点是笛卡尔打印空间的正中心顶部。
//#define MANUAL_X_HOME_POS 0
//#define MANUAL_Y_HOME_POS 0
//#define MANUAL_Z_HOME_POS 0
//#define MANUAL_I_HOME_POS 0
//#define MANUAL_J_HOME_POS 0
//#define MANUAL_K_HOME_POS 0
//#define MANUAL_U_HOME_POS 0
//#define MANUAL_V_HOME_POS 0
//#define MANUAL_W_HOME_POS 0

/**
 * Use "Z Safe Homing" to avoid homing with a Z probe outside the bed area.
 *
 * - Moves the Z probe (or nozzle) to a defined XY point before Z homing.
 * - Allows Z homing only when XY positions are known and trusted.
 * - If stepper drivers sleep, XY homing may be required again before Z homing.
 * 
 * 
 * 启用Z轴安全回零，避免Z探针处于热床区域外时执行Z回零
 *
 * 1. 执行Z回零前，先将探针/喷头移动到指定安全XY坐标
 * 2. 仅在XY坐标确定可靠时，才允许进行Z轴回零
 * 3. 若步进电机休眠断电，再次Z回零前需重新完成XY回零
 *
 */
//#define Z_SAFE_HOMING

#if ENABLED(Z_SAFE_HOMING)
  #define Z_SAFE_HOMING_X_POINT X_CENTER  // (mm) X point for Z homing //Z 轴回零所用的 X 轴坐标点
  #define Z_SAFE_HOMING_Y_POINT Y_CENTER  // (mm) Y point for Z homing //Z 轴回零所用的 Y 轴坐标点
  //#define Z_SAFE_HOMING_POINT_ABSOLUTE  // Ignore home offsets (M206) for Z homing position // Z 轴回零位置不受 M206 设置的原点偏移影响，始终使用绝对坐标
#endif

// Homing speeds (linear=mm/min, rotational=°/min)  //回零速度（直线轴单位：毫米/分钟，旋转轴单位：度/分钟）
#define HOMING_FEEDRATE_MM_M { (50*60), (50*60), (4*60) }

// Edit homing feedrates with M210 and MarlinUI menu items  // 通过 M210 指令和 MarlinUI 屏幕菜单 编辑回零速度
//#define EDITABLE_HOMING_FEEDRATE

// Validate that endstops are triggered on homing moves  // 校验：回零移动时，限位开关是否被正确触发
#define VALIDATE_HOMING_ENDSTOPS

// @section calibrate

/**
 * Bed Skew Compensation
 *
 * This feature corrects for misalignment in the XYZ axes.
 *
 * Take the following steps to get the bed skew in the XY plane:
 *  1. Print a test square (e.g., https://www.thingiverse.com/thing:2563185)
 *  2. For XY_DIAG_AC measure the diagonal A to C
 *  3. For XY_DIAG_BD measure the diagonal B to D
 *  4. For XY_SIDE_AD measure the edge A to D
 *
 * Marlin automatically computes skew factors from these measurements.
 * Skew factors may also be computed and set manually:
 *
 *  - Compute AB     : SQRT(2*AC*AC+2*BD*BD-4*AD*AD)/2
 *  - XY_SKEW_FACTOR : TAN(PI/2-ACOS((AC*AC-AB*AB-AD*AD)/(2*AB*AD)))
 *
 * If desired, follow the same procedure for XZ and YZ.
 * Use these diagrams for reference:
 *
 *    Y                     Z                     Z
 *    ^     B-------C       ^     B-------C       ^     B-------C
 *    |    /       /        |    /       /        |    /       /
 *    |   /       /         |   /       /         |   /       /
 *    |  A-------D          |  A-------D          |  A-------D
 *    +-------------->X     +-------------->X     +-------------->Y
 *     XY_SKEW_FACTOR        XZ_SKEW_FACTOR        YZ_SKEW_FACTOR
 * 
 * 
 * 
 * 热床歪斜补偿（机架歪轴校正）
 *
 * 该功能用于修正 XYZ 三轴装配错位、机架不正带来的走位偏移。
 *
 * 获取 XY 平面歪斜参数步骤：
 * 1. 打印方形校准测试件
 * 2. 测量对角线AC长度 → 填入XY_DIAG_AC
 * 3. 测量对角线BD长度 → 填入XY_DIAG_BD
 * 4. 测量侧边AD边长 → 填入XY_SIDE_AD
 *
 * 固件可自动算出歪斜补偿系数，也可手动计算设置。
 * 同理也可对 XZ、YZ 轴向做歪斜校正。
 *
 */
//#define SKEW_CORRECTION

#if ENABLED(SKEW_CORRECTION)
  // Input all length measurements here: // 在这里输入所有测量得到的长度数值：
  #define XY_DIAG_AC 282.8427124746
  #define XY_DIAG_BD 282.8427124746
  #define XY_SIDE_AD 200

  // Or, set the XY skew factor directly: // 或者，直接设置 XY 歪斜补偿系数：
  //#define XY_SKEW_FACTOR 0.0

  //#define SKEW_CORRECTION_FOR_Z
  #if ENABLED(SKEW_CORRECTION_FOR_Z)
    #define XZ_DIAG_AC 282.8427124746
    #define XZ_DIAG_BD 282.8427124746
    #define YZ_DIAG_AC 282.8427124746
    #define YZ_DIAG_BD 282.8427124746
    #define YZ_SIDE_AD 200

    // Or, set the Z skew factors directly:  // 或者，直接设置 Z 轴歪斜补偿系数：
    //#define XZ_SKEW_FACTOR 0.0
    //#define YZ_SKEW_FACTOR 0.0
  #endif

  // Enable this option for M852 to set skew at runtime  // 启用此选项以允许在运行时通过 M852 指令设置歪斜补偿
  //#define SKEW_CORRECTION_GCODE
#endif

//=============================================================================
//============================= Additional Features ===========================
//=============================================================================
// 附加功能 / 拓展功能区
// Marlin 固件里此板块存放各类非基础必备、可选开启的进阶实用功能

// @section eeprom

/**
 * EEPROM
 *
 * Persistent storage to preserve configurable settings across reboots.
 *
 *   M500 - Store settings to EEPROM.
 *   M501 - Read settings from EEPROM. (i.e., Throw away unsaved changes)
 *   M502 - Revert settings to "factory" defaults. (Follow with M500 to init the EEPROM.)
 * 
 * EEPROM 存储器
 *
 * 用于保存配置参数，断电/重启后不会丢失。
 *
 *   M500 - 保存当前设置到 EEPROM（永久保存）
 *   M501 - 从 EEPROM 读取设置（丢弃未保存的修改）
 *   M502 - 恢复设置为固件默认值（之后用 M500 初始化）
 *
 */
//#define EEPROM_SETTINGS     // Persistent storage with M500 and M501  //通过 M500 / M501 实现参数持久化存储（断电不丢设置）
//#define DISABLE_M503        // Saves ~2700 bytes of flash. Disable for release! //节省大约 2700 字节的闪存空间。正式发布固件时建议关闭！
#define EEPROM_CHITCHAT       // Give feedback on EEPROM commands. Disable to save flash.  //执行 EEPROM 指令（M500/M501/M502）时，给出提示信息。关闭它可以节省一点点闪存空间。
#define EEPROM_BOOT_SILENT    // Keep M503 quiet and only give errors during first load  //让 M503 指令输出保持静默，只在首次加载时显示错误信息。
#if ENABLED(EEPROM_SETTINGS)
  //#define EEPROM_AUTO_INIT  // Init EEPROM automatically on any errors.  //在发生任何错误时自动初始化 EEPROM。
  //#define EEPROM_INIT_NOW   // Init EEPROM on first boot after a new build.  //在新固件构建后第一次启动时初始化 EEPROM。
#endif

// @section host

//
// Host Keepalive
//
// When enabled Marlin will send a busy status message to the host
// every couple of seconds when it can't accept commands.

// 启用后，当打印机无法接收指令时
// 会每隔几秒向主机（电脑/上位机）发送忙碌状态消息
//
#define HOST_KEEPALIVE_FEATURE        // Disable this if your host doesn't like keepalive messages  //如果你的主机不喜欢接收 keepalive 消息，请禁用此功能
#define DEFAULT_KEEPALIVE_INTERVAL 2  // Number of seconds between "busy" messages. Set with M113.  // "busy" 消息之间的秒数。可以通过 M113 指令设置。
#define BUSY_WHILE_HEATING            // Some hosts require "busy" messages even during heating  // 一些主机要求在加热过程中也发送 "busy" 消息

// @section units

//
// G20/G21 Inch mode support  // G20/G21 英寸模式支持(注：G20 = 切换到英寸单位，G21 = 切换回毫米单位)
//
//#define INCH_MODE_SUPPORT

//
// M149 Set temperature units support  // M149 设置温度单位支持(摄氏度和华氏度)
//
//#define TEMPERATURE_UNITS_SUPPORT

// @section temperature

//
// Preheat Constants - Up to 10 are supported without changes  //预热参数配置区 —— 最多可直接设置 10 种预热模式，无需修改代码。
//
#define PREHEAT_1_LABEL       "PLA"
#define PREHEAT_1_TEMP_HOTEND 180
#define PREHEAT_1_TEMP_BED     70
#define PREHEAT_1_TEMP_CHAMBER 35
#define PREHEAT_1_FAN_SPEED     0 // Value from 0 to 255  // 风扇速度，范围从 0 到 255

#define PREHEAT_2_LABEL       "ABS"
#define PREHEAT_2_TEMP_HOTEND 240
#define PREHEAT_2_TEMP_BED    110
#define PREHEAT_2_TEMP_CHAMBER 35
#define PREHEAT_2_FAN_SPEED     0 // Value from 0 to 255  // 风扇速度，范围从 0 到 255

/**
 * @section nozzle park
 *
 * Nozzle Park
 *
 * Park the nozzle at the given XYZ position on idle or G27.
 *
 * The "P" parameter controls the action applied to the Z axis:
 *
 *    P0  (Default) If Z is below park Z raise the nozzle.
 *    P1  Raise the nozzle always to Z-park height.
 *    P2  Raise the nozzle by Z-park amount, limited to Z_MAX_POS.
 * 
 * * 喷嘴停靠功能
 *
 * 空闲状态或执行 G27 指令时，将喷头移动至设定的XYZ停靠坐标。
 *
 * 参数 P 用于控制Z轴的抬升动作：
 *
 *    P0（默认）：若当前Z轴高度低于停靠高度，才向上抬升至停靠高度。
 *    P1：无论当前位置如何，一律抬升至设定的Z轴停靠高度。
 *    P2：按设定数值向上抬升固定距离，最大不超过Z轴行程上限。
 */
//#define NOZZLE_PARK_FEATURE

#if ENABLED(NOZZLE_PARK_FEATURE)
  // Specify a park position as { X, Y, Z_raise }  // 以 { X, Y, Z抬升高度 } 的格式指定停靠位置
  #define NOZZLE_PARK_POINT { (X_MIN_POS + 10), (Y_MAX_POS - 10), 20 }
  #define NOZZLE_PARK_MOVE          0   // Park motion: 0 = XY Move, 1 = X Only, 2 = Y Only, 3 = X before Y, 4 = Y before X
 // 上方配置喷嘴停靠移动模式：
 // 0 = 同时移动 XY 轴
 // 1 = 仅移动 X 轴
 // 2 = 仅移动 Y 轴
 // 3 = 先移动 X 轴，再移动 Y 轴
 // 4 = 先移动 Y 轴，再移动 X 轴
  #define NOZZLE_PARK_Z_RAISE_MIN   2   // (mm) Always raise Z by at least this distance  //(毫米) Z 轴 至少 必须抬升的距离
  #define NOZZLE_PARK_XY_FEEDRATE 100   // (mm/s) X and Y axes feedrate (also used for delta Z axis)  //(毫米/秒) X 轴和 Y 轴的移动速度（也用于三角洲机型的 Z 轴）
  #define NOZZLE_PARK_Z_FEEDRATE    5   // (mm/s) Z axis feedrate (not used for delta printers)  //(毫米/秒) Z 轴的移动速度（不适用于三角洲机型）
#endif

/**
 * @section nozzle clean
 *
 * Clean Nozzle Feature
 *
 * Adds the G12 command to perform a nozzle cleaning process.
 *
 * Parameters:
 *   P  Pattern
 *   S  Strokes / Repetitions
 *   T  Triangles (P1 only)
 *
 * Patterns:
 *   P0  Straight line (default). This process requires a sponge type material
 *       at a fixed bed location. "S" specifies strokes (i.e. back-forth motions)
 *       between the start / end points.
 *
 *   P1  Zig-zag pattern between (X0, Y0) and (X1, Y1), "T" specifies the
 *       number of zig-zag triangles to do. "S" defines the number of strokes.
 *       Zig-zags are done in whichever is the narrower dimension.
 *       For example, "G12 P1 S1 T3" will execute:
 * 
 * * @section nozzle clean
 *
 * 喷嘴清洁功能
 *
 * 添加 G12 指令用于执行喷嘴清洁流程。
 *
 * 参数：
 *   P  清洁模式
 *   S  擦拭次数/重复次数
 *   T  三角数量（仅 P1 模式可用）
 *
 * 模式说明：
 *   P0  直线模式（默认）。该模式需要在热床固定位置安装海绵类清洁材料。
 *       参数 S 用于设置在起点和终点之间的往返擦拭次数。
 *
 *   P1  在 (X0, Y0) 和 (X1, Y1) 之间的锯齿模式，参数 T 用于设置锯齿三角数量。
 *       锯齿会在较窄的坐标轴方向上生成。
 *       例如：指令 "G12 P1 S1 T3" 会执行：
 *
 *          --
 *         |  (X0, Y1) |     /\        /\        /\     | (X1, Y1)
 *         |           |    /  \      /  \      /  \    |
 *       A |           |   /    \    /    \    /    \   |
 *         |           |  /      \  /      \  /      \  |
 *         |  (X0, Y0) | /        \/        \/        \ | (X1, Y0)
 *          --         +--------------------------------+
 *                       |________|_________|_________|
 *                           T1        T2        T3
 * 
 * 注（译者注）：上图是 P1 模式下，T=3 时的锯齿清洁路径示例。喷头会在 (X0, Y0) 和 (X1, Y1) 之间来回移动，形成 3 个锯齿三角形，每个三角形包含一个往返擦拭动作（由参数 S 定义）。
 *
 *
 *   P2  Circular pattern with middle at NOZZLE_CLEAN_CIRCLE_MIDDLE.
 *       "R" specifies the radius. "S" specifies the stroke count.
 *       Before starting, the nozzle moves to NOZZLE_CLEAN_START_POINT.
 *
 *   Caveats: The ending Z should be the same as starting Z.
 * 
 * *   P2  圆形清洁模式，圆心位于 NOZZLE_CLEAN_CIRCLE_MIDDLE（喷嘴清洁圆心）。
 *       参数 "R" 指定清洁半径。参数 "S" 指定擦拭次数。
 *       开始清洁前，喷嘴会先移动到 NOZZLE_CLEAN_START_POINT（喷嘴清洁起始点）。
 *
 *   注意事项：清洁结束时的Z高度必须与起始Z高度一致。
 */
//#define NOZZLE_CLEAN_FEATURE

#if ENABLED(NOZZLE_CLEAN_FEATURE)
  #define NOZZLE_CLEAN_PATTERN_LINE     // Provide 'G12 P0' - a simple linear cleaning pattern //启用 G12 P0 —— 简易直线式喷嘴清洁轨迹
  #define NOZZLE_CLEAN_PATTERN_ZIGZAG   // Provide 'G12 P1' - a zigzag cleaning pattern //启用G12 P1—— 锯齿形喷嘴清洁轨迹
  #define NOZZLE_CLEAN_PATTERN_CIRCLE   // Provide 'G12 P2' - a circular cleaning pattern  //启用 G12 P2 —— 圆形喷嘴清洁轨迹

  // Default pattern to use when 'P' is not provided to G12. One of the enabled options above.  // 当 G12 指令未提供 'P' 参数时使用的默认清洁模式。必须是上面启用的选项之一。
  #define NOZZLE_CLEAN_DEFAULT_PATTERN 0

  #define NOZZLE_CLEAN_STROKES     12   // Default number of pattern repetitions  // 默认的清洁模式重复次数

  #if ENABLED(NOZZLE_CLEAN_PATTERN_ZIGZAG)
    #define NOZZLE_CLEAN_TRIANGLES  3   // Default number of triangles  // 默认的锯齿三角数量
  #endif

  // Specify positions for each tool as { { X, Y, Z }, { X, Y, Z } }
  // Dual hotend system may use { {  -20, (Y_BED_SIZE / 2), (Z_MIN_POS + 1) },  {  420, (Y_BED_SIZE / 2), (Z_MIN_POS + 1) }}
  // 为每个喷头指定位置，格式为 { { X, Y, Z }, { X, Y, Z } }
  // 双喷头系统可使用以下配置示例：
  // { { -20, (热床Y尺寸 / 2), (Z最小位置 + 1) }, { 420, (热床Y尺寸 / 2), (Z最小位置 + 1) }}
  #define NOZZLE_CLEAN_START_POINT { {  30, 30, (Z_MIN_POS + 1) } }
  #define NOZZLE_CLEAN_END_POINT   { { 100, 60, (Z_MIN_POS + 1) } }

  #if ENABLED(NOZZLE_CLEAN_PATTERN_CIRCLE)
    #define NOZZLE_CLEAN_CIRCLE_RADIUS 6.5                      // (mm) Circular pattern radius  //（毫米）圆形清洁模式的半径
    #define NOZZLE_CLEAN_CIRCLE_FN 10                           // Circular pattern circle number of segments  // 圆形清洁模式的圆周分段数量
    #define NOZZLE_CLEAN_CIRCLE_MIDDLE NOZZLE_CLEAN_START_POINT // Middle point of circle  // 圆形清洁模式的圆心位置
  #endif

  // Move the nozzle to the initial position after cleaning  // 清洁完成后将喷头移回初始位置
  #define NOZZLE_CLEAN_GOBACK

  // For a purge/clean station that's always at the gantry height (thus no Z move)
  // 适用于始终处于龙门架高度的清洗/清洁站（因此无需移动Z轴）
  //注（译者注）：如果你的喷嘴清洁站设计成固定在龙门架高度，清洁过程中不需要移动Z轴，喷头直接过去擦就行，不用抬升 Z 轴，那么可以启用以下选项：
  //#define NOZZLE_CLEAN_NO_Z

  // For a purge/clean station mounted on the X axis
  // 适用于安装在 X 轴上的耗材清洗/清洁站
  //#define NOZZLE_CLEAN_NO_Y

  // Require a minimum hotend temperature for cleaning  // 要求清洁时喷头达到最低温度
  #define NOZZLE_CLEAN_MIN_TEMP 170
  //#define NOZZLE_CLEAN_HEATUP       // Heat up the nozzle instead of skipping wipe  // 加热喷头而不是跳过清洁

  // Explicit wipe G-code script applies to a G12 with no arguments.  // 当 G12 指令没有参数时，执行以下预设的清洁 G 代码脚本。
  //#define WIPE_SEQUENCE_COMMANDS "G1 X-17 Y25 Z10 F4000\nG1 Z1\nM114\nG1 X-17 Y25\nG1 X-17 Y95\nG1 X-17 Y25\nG1 X-17 Y95\nG1 X-17 Y25\nG1 X-17 Y95\nG1 X-17 Y25\nG1 X-17 Y95\nG1 X-17 Y25\nG1 X-17 Y95\nG1 X-17 Y25\nG1 X-17 Y95\nG1 Z15\nM400\nG0 X-10.0 Y-9.0"

#endif

// @section host

/**
 * Print Job Timer
 *
 * Automatically start and stop the print job timer on M104/M109/M140/M190/M141/M191.
 * The print job timer will only be stopped if the bed/chamber target temp is
 * below BED_MINTEMP/CHAMBER_MINTEMP.
 *
 *   M104 (hotend, no wait)  - high temp = none,        low temp = stop timer
 *   M109 (hotend, wait)     - high temp = start timer, low temp = stop timer
 *   M140 (bed, no wait)     - high temp = none,        low temp = stop timer
 *   M190 (bed, wait)        - high temp = start timer, low temp = none
 *   M141 (chamber, no wait) - high temp = none,        low temp = stop timer
 *   M191 (chamber, wait)    - high temp = start timer, low temp = none
 *
 * For M104/M109, high temp is anything over EXTRUDE_MINTEMP / 2.
 * For M140/M190, high temp is anything over BED_MINTEMP.
 * For M141/M191, high temp is anything over CHAMBER_MINTEMP.
 *
 * The timer can also be controlled with the following commands:
 *
 *   M75 - Start the print job timer
 *   M76 - Pause the print job timer
 *   M77 - Stop the print job timer
 * 
 * * 打印任务计时器
 *
 * 通过加热指令 M104/M109/M140/M190/M141/M191 自动开始和停止打印计时。
 * 仅当热床/机箱目标温度低于 BED_MINTEMP/CHAMBER_MINTEMP 时，计时器才会停止。
 *
 *   M104 (喷头, 不等待) - 高温 = 无操作, 低温 = 停止计时
 *   M109 (喷头, 等待)   - 高温 = 开始计时, 低温 = 停止计时
 *   M140 (热床, 不等待) - 高温 = 无操作, 低温 = 停止计时
 *   M190 (热床, 等待)   - 高温 = 开始计时, 低温 = 无操作
 *   M141 (机箱, 不等待) - 高温 = 无操作, 低温 = 停止计时
 *   M191 (机箱, 等待)   - 高温 = 开始计时, 低温 = 无操作
 *
 * 对于 M104/M109，超过挤出最低温度的一半即为高温。
 * 对于 M140/M190，超过热床最低温度即为高温。
 * 对于 M141/M191，超过机箱最低温度即为高温。
 *
 * 计时器也可通过以下指令手动控制：
 *
 *   M75 - 开始打印计时
 *   M76 - 暂停打印计时
 *   M77 - 停止打印计时
 * 
 * 注（译者注）：这是打印机自带的打印计时功能，用来记录打印用了多久：
 * 自动计时：你设置加热温度，打印机就自动开始计时；温度降回室温，自动停止。
 * 手动控制：也能直接发 M75/M76/M77 指令开始 / 暂停 / 停止计时。
 * 作用：在屏幕上显示本次打印已用时，方便你查看。
 */
#define PRINTJOB_TIMER_AUTOSTART

// @section stats

/**
 * Print Counter
 *
 * Track statistical data such as:
 *
 *  - Total print jobs
 *  - Total successful print jobs
 *  - Total failed print jobs
 *  - Total time printing
 *
 * View the current statistics with M78.
 * 
 * * 打印统计计数器
 *
 * 可统计以下数据：
 *
 *  - 总打印任务次数
 *  - 成功完成打印次数
 *  - 打印失败次数
 *  - 累计总打印时长
 *
 * 发送指令 M78 即可查看当前统计数据。
 */
//#define PRINTCOUNTER
#if ENABLED(PRINTCOUNTER)
  #define PRINTCOUNTER_SAVE_INTERVAL 60 // (minutes) EEPROM save interval during print. A value of 0 will save stats at end of print.  //（分钟）打印过程中统计数据保存到 EEPROM 的间隔。设置为 0 则在打印结束时保存统计数据。
#endif

// @section security

/**
 * Password
 *
 * Set a numerical password for the printer which can be requested:
 *
 *  - When the printer boots up
 *  - Upon opening the 'Print from Media' Menu
 *  - When SD printing is completed or aborted
 *
 * The following G-codes can be used:
 *
 *  M510 - Lock Printer. Blocks all commands except M511.
 *  M511 - Unlock Printer.
 *  M512 - Set, Change and Remove Password.
 *
 * If you forget the password and get locked out you'll need to re-flash
 * the firmware with the feature disabled, reset EEPROM, and (optionally)
 * re-flash the firmware again with this feature enabled.
 * 
 * // @section 安全设置


 * 密码锁功能
 *
 * 为打印机设置数字密码，可在以下场景启用密码验证：
 *
 *  - 打印机开机时
 *  - 打开“从存储设备打印”菜单时
 *  - SD卡打印完成或中断时
 *
 * 可使用以下G代码指令：
 *
 *  M510 - 锁定打印机，屏蔽所有指令，仅允许 M511
 *  M511 - 解锁打印机
 *  M512 - 设置、修改、删除密码
 *
 * 若忘记密码导致被锁定，解决方法：
 * 重新刷入关闭此功能的固件 → 重置EEPROM →（可选）再次刷入开启此功能的固件。
 *
 */
//#define PASSWORD_FEATURE
#if ENABLED(PASSWORD_FEATURE)
  #define PASSWORD_LENGTH 4                 // (#) Number of digits (1-9). 3 or 4 is recommended  //（数字）密码位数，范围 1-9。建议使用 3 位或 4 位密码。
  #define PASSWORD_ON_STARTUP
  #define PASSWORD_UNLOCK_GCODE             // Unlock with the M511 P<password> command. Disable to prevent brute-force attack.  //通过 M511 P<password> 指令解锁。禁用此功能可防止暴力破解攻击。
  #define PASSWORD_CHANGE_GCODE             // Change the password with M512 P<old> S<new>.  //通过 M512 P<old> S<new> 指令修改密码。
  //#define PASSWORD_ON_SD_PRINT_MENU       // This does not prevent G-codes from running  //该功能无法阻止 G 代码指令运行
  //#define PASSWORD_AFTER_SD_PRINT_END
  //#define PASSWORD_AFTER_SD_PRINT_ABORT
  //#include "Configuration_Secure.h"       // External file with PASSWORD_DEFAULT_VALUE  // 外部文件，包含默认密码值
#endif

// @section media

/**
 * SD CARD
 *
 * SD Card support is disabled by default. If your controller has an SD slot,
 * you must uncomment the following option or it won't work.
 * 
 * 存储卡功能
 * 固件默认关闭 SD 卡支持。若你的主控板带有 SD 卡槽，
 * 必须取消下方对应配置的注释，该功能才能正常使用。
 * 
 * 注（译者注）：SD卡作用：
 * 脱机打印（最主要）
     电脑不用一直连着打印机，把打印文件拷进 SD 卡，插打印机上直接打印。
 * 存固件、配置文件
     部分主板靠 SD 卡刷固件、保存参数。
 * 存打印日志、截图
     部分机型存打印记录、屏幕截图。
 * 离线运行脚本
     存放批量 G 代码脚本离线执行。
 */
//#define SDSUPPORT

/**
 * SD CARD: ENABLE CRC
 *
 * Use CRC checks and retries on the SD communication. //SD 卡通信启用 CRC 校验与重连重试机制
 * 注（译者注）：启用后，SD 卡通信会使用 CRC 校验来验证数据完整性，并在通信失败时自动重试。这可以提高 SD 卡读取的可靠性，尤其是在电磁干扰较大的环境中。
 * 不过启用此功能可能会略微降低 SD 卡的读写速度，因为每次通信都需要进行 CRC 计算和验证。
 */
#if ENABLED(SDSUPPORT)
  //#define SD_CHECK_AND_RETRY
#endif

// @section interface

/**
 * LCD LANGUAGE
 *
 * Select the language to display on the LCD. These languages are available:
 *
 *   en, an, bg, ca, cz, da, de, el, el_CY, es, eu, fi, fr, gl, hr, hu, it,
 *   jp_kana, ko_KR, nl, pl, pt, pt_br, ro, ru, sk, sv, tr, uk, vi, zh_CN, zh_TW
 *
 * :{ 'en':'English', 'an':'Aragonese', 'bg':'Bulgarian', 'ca':'Catalan', 'cz':'Czech', 'da':'Danish', 'de':'German', 'el':'Greek (Greece)', 'el_CY':'Greek (Cyprus)', 'es':'Spanish', 'eu':'Basque-Euskera', 'fi':'Finnish', 'fr':'French', 'gl':'Galician', 'hr':'Croatian', 'hu':'Hungarian', 'it':'Italian', 'jp_kana':'Japanese', 'ko_KR':'Korean (South Korea)', 'nl':'Dutch', 'pl':'Polish', 'pt':'Portuguese', 'pt_br':'Portuguese (Brazilian)', 'ro':'Romanian', 'ru':'Russian', 'sk':'Slovak', 'sv':'Swedish', 'tr':'Turkish', 'uk':'Ukrainian', 'vi':'Vietnamese', 'zh_CN':'Chinese (Simplified)', 'zh_TW':'Chinese (Traditional)' }
 * 
 * 显示屏语言设置
 * 选择液晶显示屏显示的语言，可用语种如下：
 * en 英文、阿拉贡语、保加利亚语、加泰罗尼亚语、捷克语、丹麦语、德语、希腊语、塞浦路斯希腊语、西班牙语、巴斯克语、芬兰语、法语、
 * 加利西亚语、克罗地亚语、匈牙利语、意大利语、日语假名、韩语、荷兰语、波兰语、葡萄牙语、巴西葡语、罗马尼亚语、俄语、斯洛伐克语、
 * 瑞典语、土耳其语、乌克兰语、越南语、简体中文、繁体中文
 */
#define LCD_LANGUAGE en

/**
 * LCD Character Set
 *
 * Note: This option is NOT applicable to Graphical Displays.
 *
 * All character-based LCDs provide ASCII plus one of these
 * language extensions:
 *
 *  - JAPANESE ... the most common
 *  - WESTERN  ... with more accented characters
 *  - CYRILLIC ... for the Russian language
 *
 * To determine the language extension installed on your controller:
 *
 *  - Compile and upload with LCD_LANGUAGE set to 'test'
 *  - Click the controller to view the LCD menu
 *  - The LCD will display Japanese, Western, or Cyrillic text
 *
 * See https://marlinfw.org/docs/development/lcd_language.html
 *
 * :['JAPANESE', 'WESTERN', 'CYRILLIC']
 * 
 * 液晶屏字符集设置
 * 注意：该选项不适用于图形彩屏。
 * 所有字符屏除基础 ASCII 字符外，还自带以下其中一种语言扩展字符集：
 * JAPANESE 日式字符集（最常用）
 * WESTERN 西欧字符集（含更多重音字母）
 * CYRILLIC 西里尔字符集（适配俄语）
 * 查看你的主板内置字符集方法：
 * 将显示屏语言临时设为 test 后编译刷入固件
 * 查看屏幕菜单显示文字样式
 * 即可判断是日式、西欧还是西里尔字符集
 * 参考文档：https://marlinfw.org/docs/development/lcd_language.html
 * 可选值：日式 / 西欧 / 西里尔
 */
#define DISPLAY_CHARSET_HD44780 JAPANESE

/**
 * Info Screen Style (0:Classic, 1:Průša, 2:CNC)
 *
 * :[0:'Classic', 1:'Průša', 2:'CNC']
 * 
 * 信息界面样式（0：经典样式，1：普鲁沙机型风格，2：数控机床风格）
 */
#define LCD_INFO_SCREEN_STYLE 0

/**
 * LCD Menu Items
 *
 * Disable all menus and only display the Status Screen, or
 * just remove some extraneous menu items to recover space.
 * 液晶显示屏菜单项目
 * 可关闭全部菜单，仅保留状态主页；也可删减多余菜单项，节省屏幕显示空间。
 */
//#define NO_LCD_MENUS
//#define SLIM_LCD_MENUS

//
// ENCODER SETTINGS
//
// This option overrides the default number of encoder pulses needed to
// produce one step. Should be increased for high-resolution encoders.

// 编码器设置
//
// 该选项用于覆盖默认的编码器脉冲数（每产生一步所需的脉冲）。
// 高分辨率编码器需要增大这个数值。

// 注（译者注）：编码器是旋转式输入设备，常用于 LCD 控制器上作为旋钮。
// 这个参数是调旋钮灵敏度的，
// 编码器转一格，屏幕跳多少个选项

//
//#define ENCODER_PULSES_PER_STEP 4

//
// Use this option to override the number of step signals required to
// move between next/prev menu items.

// 使用此选项，可自定义切换菜单上一个/下一个项目
// 所需要的步进信号数量。
//
//#define ENCODER_STEPS_PER_MENU_ITEM 1

/**
 * Encoder Direction Options
 *
 * Test your encoder's behavior first with both options disabled.
 *
 *  Reversed Value Edit and Menu Nav? Enable REVERSE_ENCODER_DIRECTION.
 *  Reversed Menu Navigation only?    Enable REVERSE_MENU_DIRECTION.
 *  Reversed Value Editing only?      Enable BOTH options.
 * 
 * * 编码器方向设置
 *
 * 先关闭这两个选项，测试你的旋钮实际转向是否正常。
 *
 *  数值调节 和 菜单上下 都反了？启用 REVERSE_ENCODER_DIRECTION。
 *  只有 菜单上下 反了？          启用 REVERSE_MENU_DIRECTION。
 *  只有 数值调节 反了？          两个选项 都启用。
 */

//
// This option reverses the encoder direction everywhere. // 该选项会 全局反转编码器方向。
//
//  Set this option if CLOCKWISE causes values to DECREASE  //如果顺时针旋转旋钮时，数值反而**减小**，就启用这个选项。
//
//#define REVERSE_ENCODER_DIRECTION

//
// This option reverses the encoder direction for navigating LCD menus.  // 该选项仅 反转LCD菜单中编码器的方向。
//
//  If CLOCKWISE normally moves DOWN this makes it go UP.  // 如果顺时针旋转原本是向下移动，开启后会变为向上移动。
//  If CLOCKWISE normally moves UP this makes it go DOWN.  // 如果顺时针旋转原本是向上移动，开启后会变为向下移动。
//
//#define REVERSE_MENU_DIRECTION

//
// This option reverses the encoder direction for Select Screen.  //此选项反转选择界面里旋钮的转动方向
//
//  If CLOCKWISE normally moves LEFT this makes it go RIGHT.  //  如果顺时针旋转原本是向左移动，开启后会变为向右移动。
//  If CLOCKWISE normally moves RIGHT this makes it go LEFT.  //  如果顺时针旋转原本是向右移动，开启后会变为向左移动。
//
//#define REVERSE_SELECT_DIRECTION

//
// Encoder EMI Noise Filter  // 旋钮电磁干扰噪声滤波
//
// This option increases encoder samples to filter out phantom encoder clicks caused by EMI noise.
// 该选项通过增加编码器信号采样次数，过滤由 EMI 电磁干扰引起的
// 编码器“幻影点击”（误触发、乱跳、虚转）。
//
//#define ENCODER_NOISE_FILTER
#if ENABLED(ENCODER_NOISE_FILTER)
  #define ENCODER_SAMPLES 10
#endif

//
// Individual Axis Homing  //独立轴回零
//
// Add individual axis homing items (Home X, Home Y, and Home Z) to the LCD menu.  //在LCD菜单中添加独立的回零选项（回零X轴、回零Y轴、回零Z轴）。
//
//#define INDIVIDUAL_AXIS_HOMING_MENU
//#define INDIVIDUAL_AXIS_HOMING_SUBMENU

//
// SPEAKER/BUZZER
//
// If you have a speaker that can produce tones, enable it here.
// By default Marlin assumes you have a buzzer with a fixed frequency.

// 扬声器 / 蜂鸣器
//
// 如果你的打印机带有扬声器，在这里启用。
// 默认情况下，Marlin 固件认为你使用的是固定频率的蜂鸣器。
//
//#define SPEAKER

//
// The duration and frequency for the UI feedback sound.
// Set these to 0 to disable audio feedback in the LCD menus.
//
// Note: Test audio output with the G-Code:
//  M300 S<frequency Hz> P<duration ms>

// 界面操作提示音的时长与频率
// 将两项均设为 0 可关闭 LCD 菜单中的声音反馈。
//
// 提示：使用以下 G-Code 测试声音输出：
//  M300 S<频率 Hz> P<时长 毫秒>
//
//#define LCD_FEEDBACK_FREQUENCY_DURATION_MS 2
//#define LCD_FEEDBACK_FREQUENCY_HZ 5000

//
// Tone queue size, used to keep beeps from blocking execution.
// Default is 4, or override here. Costs 4 bytes of SRAM per entry.
// 提示音队列长度，防止蜂鸣声阻塞程序运行
// 默认值为 4，也可在此处修改
// 每增加一个条目会占用 4 字节 内存
//
//#define TONE_QUEUE_LENGTH 4

//
// A sequence of tones to play at startup, in pairs of tone (Hz), duration (ms).  //开机启动提示音序列，格式为【音调(赫兹)、时长(毫秒)】成对设置
// Silence in-between tones.
//
//#define STARTUP_TUNE { 698, 300, 0, 50, 523, 50, 0, 25, 494, 50, 0, 25, 523, 100, 0, 50, 554, 300, 0, 100, 523, 300 }

//=============================================================================
//======================== LCD / Controller Selection =========================
//========================   (Character-based LCDs)   =========================
//=============================================================================
// LCD / 控制器选择

// 注（译者注）：以下是常见的字符屏 LCD 控制器选项，启用对应选项后，固件会包含适配该控制器的代码。
// 请根据你的打印机实际使用的 LCD 类型，取消对应选项的注释来启用支持。
// @section lcd

//
// RepRapDiscount Smart Controller.     //RepRapDiscount 智能控制器
// https://reprap.org/wiki/RepRapDiscount_Smart_Controller
//
// Note: Usually sold with a white PCB.     //备注：通常是白色电路板的那款屏幕。
//
//#define REPRAP_DISCOUNT_SMART_CONTROLLER

//
// GT2560 (YHCB2004) LCD Display      //GT2560 (YHCB2004) 型号 LCD 显示屏
//
// Requires Testato, Koepel softwarewire library and
// Andriy Golovnya's LiquidCrystal_AIP31068 library.      //需要依赖两个库：Testato、Koepel 的 softwarewire 库以及 Andriy Golovnya 的 LiquidCrystal_AIP31068 库
//
//#define YHCB2004

//
// Original RADDS LCD Display+Encoder+SDCardReader     // 原版RADDS配套显示屏+编码器旋钮+SD卡读卡器
// https://web.archive.org/web/20200719145306/doku.radds.org/dokumentation/lcd-display/
//
//#define RADDS_DISPLAY

//
// ULTIMAKER Controller.      // ULTIMAKAKER 控制器
//
//#define ULTIMAKERCONTROLLER

//
// ULTIPANEL as seen on Thingiverse.      // Thingiverse平台开源的ULTIPANEL控制面板
//
//#define ULTIPANEL

//
// PanelOne from T3P3 (via RAMPS 1.4 AUX2/AUX3)      // T3P3 公司的 PanelOne 显示屏（通过 RAMPS 1.4 的 AUX2/AUX3 接口连接）
// https://reprap.org/wiki/PanelOne
//
//#define PANEL_ONE

//
// GADGETS3D G3D LCD/SD Controller      // GADGETS3D G3D 液晶显示屏/SD卡控制器
// https://reprap.org/wiki/RAMPS_1.3/1.4_GADGETS3D_Shield_with_Panel
//
// Note: Usually sold with a blue PCB.      // 备注：该款屏幕电路板通常为蓝色PCB板
//
//#define G3D_PANEL

//
// RigidBot Panel V1.0      // RigidBot V1.0 专用控制面板
//
//#define RIGIDBOT_PANEL

//
// Makeboard 3D Printer Parts 3D Printer Mini Display 1602 Mini Controller        // Makeboard 3D打印机配件 1602迷你显示屏 迷你控制器
// https://www.aliexpress.com/item/32765887917.html
//
//#define MAKEBOARD_MINI_2_LINE_DISPLAY_1602

/**
 * ANET and Tronxy 20x4 Controller
 * LCD2004 display with 5 analog buttons.       // ANET爱能特、创星元Tronxy 2004控制面板    2004液晶显示屏，搭配5个模拟按键
 *
 * NOTE: Requires ADC_KEYPAD_PIN to be assigned to an analog pin.
 * This LCD is known to be susceptible to electrical interference which
 * scrambles the display. Press any button to clear it up.
 * 
 *  注意：需要将 ADC_KEYPAD_PIN 分配给一个模拟引脚。
 * 已知这款 LCD 容易受到电磁干扰导致屏幕花屏、乱码。
 * 按任意按键即可恢复正常显示。
 */
//#define ZONESTAR_LCD

//
// Generic 16x2, 16x4, 20x2, or 20x4 character-based LCD.  // 通用型 16x2、16x4、20x2 或 20x4 字符 LCD 显示屏。
//
//#define ULTRA_LCD

//=============================================================================
//======================== LCD / Controller Selection =========================
//=====================   (I2C and Shift-Register LCDs)   =====================
//=============================================================================
// I2C 总线 和 移位寄存器 型 LCD 显示屏

//
// CONTROLLER TYPE: I2C  // 控制器类型：I2C
//
// Note: These controllers require the installation of Arduino's LiquidCrystal_I2C
// library. For more info: https://github.com/kiyoshigawa/LiquidCrystal_I2C
// 注意：使用这类控制器，必须先安装 Arduino 的 LiquidCrystal_I2C 库。
//

//
// Elefu RA Board Control Panel  // Elefu RA 主板配套控制面板
// https://web.archive.org/web/20140823033947/www.elefu.com/index.php?route=product/product&product_id=53
//
//#define RA_CONTROL_PANEL

//
// Sainsmart (YwRobot) LCD Displays
//
// These require LiquidCrystal_I2C library:
//   https://github.com/MarlinFirmware/New-LiquidCrystal
//   https://github.com/fmalpartida/New-LiquidCrystal/wiki
//
//#define LCD_SAINSMART_I2C_1602
//#define LCD_SAINSMART_I2C_2004

//
// Generic LCM1602 LCD adapter  // 通用 LCM1602 液晶显示屏转接板
//
//#define LCM1602

//
// PANELOLU2 LCD with status LEDs,
// separate encoder and click inputs.
// PANELOLU2 LCD 显示屏（带状态指示灯）
// 独立编码器与点击按键输入。
//
// Note: This controller requires Arduino's LiquidTWI2 library v1.2.3 or later.
// For more info: https://github.com/lincomatic/LiquidTWI2
// 注意：此控制器需要安装 Arduino 的 LiquidTWI2 库 v1.2.3 或更高版本。
// 详细信息：https://github.com/lincomatic/LiquidTWI2
//
// Note: The PANELOLU2 encoder click input can either be directly connected to
// a pin (if BTN_ENC defined to != -1) or read through I2C (when BTN_ENC == -1).
// 注意：PANELOLU2 编码器的点击按键输入有两种连接方式：
// 1. 直接连接到一个引脚（当 BTN_ENC 定义为不等于 -1 时）
// 2. 通过 I2C 总线读取（当 BTN_ENC 等于 -1 时）
//
//#define LCD_I2C_PANELOLU2

//
// Panucatt VIKI LCD with status LEDs,
// integrated click & L/R/U/D buttons, separate encoder inputs.
// Panucatt VIKI LCD 显示屏（带状态指示灯）
// 集成确认/上/下/左/右按键，独立编码器输入。
//
//#define LCD_I2C_VIKI

//
// CONTROLLER TYPE: Shift register panels
//

//
// 2-wire Non-latching LCD SR from https://github.com/fmalpartida/New-LiquidCrystal/wiki/schematics#user-content-ShiftRegister_connection
// LCD configuration: https://reprap.org/wiki/SAV_3D_LCD
//
//#define SAV_3DLCD

//
// 3-wire SR LCD with strobe using 74HC4094
// https://github.com/mikeshub/SailfishLCD
// Uses the code directly from Sailfish
//
//#define FF_INTERFACEBOARD

//
// TFT GLCD Panel with Marlin UI
// Panel connected to main board by SPI or I2C interface.
// TFT GLCD 显示屏（带 Marlin 图形界面）
// 通过 SPI 或 I2C 接口连接到主板。
// See https://github.com/Serhiy-K/TFTGLCDAdapter
//
//#define TFTGLCD_PANEL_SPI
//#define TFTGLCD_PANEL_I2C

//=============================================================================
//=======================   LCD / Controller Selection  =======================
//=========================      (Graphical LCDs)      ========================
//=============================================================================
// 图形液晶显示器

//
// CONTROLLER TYPE: Graphical 128x64 (DOGM)  // 控制器类型：图形屏 128x64 (DOGM)
//
// IMPORTANT: The U8glib library is required for Graphical Display!
//            https://github.com/olikraus/U8glib_Arduino
// 重要提示：图形显示器必须安装 U8glib 库！
// 库地址：https://github.com/olikraus/U8glib_Arduino
//
// NOTE: If the LCD is unresponsive you may need to reverse the plugs.  // 注意：若液晶屏幕无任何反应，可尝试调换排线插头正反方向
//

//
// RepRapDiscount FULL GRAPHIC Smart Controller  // RepRapDiscount 全图形智能控制面板
// https://reprap.org/wiki/RepRapDiscount_Full_Graphic_Smart_Controller
//
//#define REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER

//
// K.3D Full Graphic Smart Controller  // K.3D 全图形智能控制面板
//
//#define K3D_FULL_GRAPHIC_SMART_CONTROLLER

//
// ReprapWorld Graphical LCD  // ReprapWorld 图形液晶显示屏 (128x64 SPI)
// https://reprapworld.com/electronics/3d-printer-modules/autonomous-printing/graphical-lcd-screen-v1-0/
//
//#define REPRAPWORLD_GRAPHICAL_LCD

//
// Activate one of these if you have a Panucatt Devices
// Viki 2.0 or mini Viki with Graphic LCD  // 若使用Panucatt品牌的Viki 2.0或迷你Viki图形屏，请启用以下对应选项之一
// https://www.panucatt.com
//
//#define VIKI2
//#define miniVIKI

//
// Alfawise Ex8 printer LCD marked as WYH L12864 COG  // Alfawise Ex8 原厂屏 WYH L12864 COG（ST7565/ST7567 SPI）
//
//#define WYH_L12864

//
// MakerLab Mini Panel with graphic  // MakerLab Mini Panel 迷你图形控制面板
// controller and SD support - https://reprap.org/wiki/Mini_panel
//
//#define MINIPANEL

//
// MaKr3d Makr-Panel with graphic controller and SD support.  // MaKr3d Makr-Panel 图形控制面板，支持SD卡读取
// https://reprap.org/wiki/MaKrPanel
//
//#define MAKRPANEL

//
// Adafruit ST7565 Full Graphic Controller.  // Adafruit ST7565 全图形控制面板
// https://github.com/eboston/Adafruit-ST7565-Full-Graphic-Controller/
//
//#define ELB_FULL_GRAPHIC_CONTROLLER

//
// BQ LCD Smart Controller shipped by
// default with the BQ Hephestos 2 and Witbox 2.
// BQ液晶智能控制面板
// 为BQ Hephestos 2、Witbox 2机型原厂标配屏幕
//
//#define BQ_LCD_SMART_CONTROLLER

//
// Cartesio UI
// https://web.archive.org/web/20180605050442/mauk.cc/webshop/cartesio-shop/electronics/user-interface
//
//#define CARTESIO_UI

//
// LCD for Melzi Card with Graphical LCD  // 适配Melzi主控板的图形液晶显示屏
//
//#define LCD_FOR_MELZI

//
// Original Ulticontroller from Ultimaker 2 printer with SSD1309 I2C display and encoder
// 适用于Ultimaker 2打印机原装Ulticontroller控制面板
// 搭载SSD1309 I2C显示屏与旋转编码器
// https://github.com/Ultimaker/Ultimaker2/tree/master/1249_Ulticontroller_Board_(x1)
//
//#define ULTI_CONTROLLER

//
// MKS MINI12864 with graphic controller and SD support  // MKS MINI12864 图形控制面板 带SD卡支持
// https://reprap.org/wiki/MKS_MINI_12864
//
//#define MKS_MINI_12864

//
// MKS MINI12864 V3 is an alias for FYSETC_MINI_12864_2_1. Type A/B. NeoPixel RGB Backlight.
// MKS MINI12864 V3 等同 FYSETC_MINI_12864_2_1
// 分A/B版本，搭载NeoPixel RGB彩色背光
//
//#define MKS_MINI_12864_V3

//
// MKS LCD12864A/B with graphic controller and SD support. Follows MKS_MINI_12864 pinout.
// MKS LCD12864A/B 图形控制面板 带SD卡支持
// 引脚定义与 MKS_MINI_12864 完全一致
// https://www.aliexpress.com/item/33018110072.html
//
//#define MKS_LCD12864A
//#define MKS_LCD12864B

//
// FYSETC variant of the MINI12864 graphic controller with SD support
// FYSETC 版 MINI12864 图形控制面板（带SD卡支持）
// https://wiki.fysetc.com/Mini12864_Panel/
//
//#define FYSETC_MINI_12864_X_X    // Type C/D/E/F. No tunable RGB Backlight by default  // Type C/D/E/F 版本默认无可调 RGB 背光
//#define FYSETC_MINI_12864_1_2    // Type C/D/E/F. Simple RGB Backlight (always on)  // C/D/E/F版本：简易RGB背光，默认常亮不可调
//#define FYSETC_MINI_12864_2_0    // Type A/B. Discreet RGB Backlight  // A/B版本：独立可控式RGB背光
//#define FYSETC_MINI_12864_2_1    // Type A/B. NeoPixel RGB Backlight  // 搭载 NeoPixel RGB 可编程背光
//#define FYSETC_GENERIC_12864_1_1 // Larger display with basic ON/OFF backlight.  // 大屏款，仅支持背光基础开关，无调色功能

//
// BigTreeTech Mini 12864 V1.0 / V2.0 is an alias for FYSETC_MINI_12864_2_1. Type A/B. NeoPixel RGB Backlight.
// BigTreeTech (BTT) Mini 12864 V1.0 / V2.0
// 等同于 FYSETC_MINI_12864_2_1
// Type A/B 版本，带 NeoPixel RGB 背光
// https://github.com/bigtreetech/MINI-12864
//
//#define BTT_MINI_12864

//
// BEEZ MINI 12864 is an alias for FYSETC_MINI_12864_2_1. Type A/B. NeoPixel RGB Backlight.
// BEEZ MINI 12864 等效 FYSETC_MINI_12864_2_1
// A/B型，搭载NeoPixel RGB可编程背光
//
//#define BEEZ_MINI_12864

//
// Factory display for Creality CR-10 / CR-7 / Ender-3
// Creality CR-10 / CR-7 / Ender-3 原厂屏
// 型号：Creality 12864 OEM LCD (非RGB，仅单色背光)
// 无NeoPixel，不可调色，仅基础开/关背光
// https://marlinfw.org/docs/hardware/controllers.html#cr10_stockdisplay
//
// Connect to EXP1 on RAMPS and compatible boards.  // 连接至 RAMPS 主板及兼容版型的 EXP1 接口
//
//#define CR10_STOCKDISPLAY

//
// Ender-2 OEM display, a variant of the MKS_MINI_12864  
// Ender-2 OEM 原厂屏
// 属于 MKS_MINI_12864 的衍生变体
// 驱动：UC1701，SPI 接口，单色背光（无 RGB）
//
//#define ENDER2_STOCKDISPLAY

//
// ANET and Tronxy 128×64 Full Graphics Controller as used on Anet A6
// ANET / Tronxy 128×64 全图形控制器 (Anet A6 原厂屏)
// 别名：ANET_FULL_GRAPHICS_LCD
// 驱动：ST7565，接口：并行（EXP1），单色背光，带旋转编码器
//
//#define ANET_FULL_GRAPHICS_LCD

//
// GUCOCO CTC 128×64 Full Graphics Controller as used on GUCOCO CTC A10S
// GUCOCO CTC 128×64 Full Graphics Controller (CTC A10S 原厂屏)
// 别名：CTC_A10S_FULL_GRAPHICS_LCD / 与 ANET A6/Tronxy 同源
// 驱动：ST7565，接口：并行（EXP1），单色背光，带旋转编码器
//
//#define CTC_A10S_A13

//
// AZSMZ 12864 LCD with SD
// 接口：SPI（软件/硬件），驱动：ST7565，带板载SD卡、编码器
// Marlin 宏：AZSMZ_12864（与 VIKI2 共用引脚）
// https://www.aliexpress.com/item/32837222770.html
//
//#define AZSMZ_12864

//
// Silvergate GLCD controller
// 接口：并行(EXP1)，驱动：ST7920，128×64，带编码器、蜂鸣器、SD
// Marlin 宏：SILVER_GATE_GLCD_CONTROLLER
// https://github.com/android444/Silvergate
//
//#define SILVER_GATE_GLCD_CONTROLLER

//
// eMotion Tech LCD with SD
// 专用图形LCD控制器，带SD卡、编码器
// 接口：并行 / SPI，适配 eMotion Tech 主板
// Marlin 宏：EMOTION_TECH_LCD
// https://www.reprap-france.com/produit/1234568748-ecran-graphique-128-x-64-points-2-1
//
//#define EMOTION_TECH_LCD

//=============================================================================
//==============================  OLED Displays  ==============================
//=============================================================================
// OLED显示屏
//
// SSD1306 OLED full graphics generic display  // SSD1306 OLED 全图形通用显示屏
//
//#define U8GLIB_SSD1306

//
// SAV OLEd LCD module support using either SSD1306 or SH1106 based LCD modules  // 支持 SSD1306 / SH1106 两种芯片的 OLED 显示模块
//
//#define SAV_3DGLCD
#if ENABLED(SAV_3DGLCD)
  #define U8GLIB_SSD1306
  //#define U8GLIB_SH1106
#endif

//
// TinyBoy2 128x64 OLED / Encoder Panel
//
//#define OLED_PANEL_TINYBOY2

//
// MKS OLED 1.3" 128×64 Full Graphics Controller
// 这是 MKS（Makerbase）出的1.3 寸、128×64、SPI 接口、带编码器 / 按键的 OLED 面板。
// https://reprap.org/wiki/MKS_12864OLED
//
// Tiny, but very sharp OLED display
//
//#define MKS_12864OLED          // Uses the SH1106 controller  //SH1106 驱动主控芯片
//#define MKS_12864OLED_SSD1306  // Uses the SSD1306 controller  // SSD1306 驱动主控芯片

//
// Zonestar OLED 128×64 Full Graphics Controller
// Zonestar（卓星）OLED 128×64 全图形控制器屏，是 Zonestar 3D 打印机常用的I2C 接口、带编码器的 128×64 OLED 面板，
// 和 TinyBoy2 高度兼容，驱动芯片分 SSD1306 / SH1106 两种。
//
//#define ZONESTAR_12864LCD           // Graphical (DOGM) with ST7920 controller  //带 ST7920 控制器的图形化 (DOGM) 显示屏
//#define ZONESTAR_12864OLED          // 1.3" OLED with SH1106 controller  // 1.3英寸 OLED 显示屏，采用 SH1106 驱动芯片
//#define ZONESTAR_12864OLED_SSD1306  // 0.96" OLED with SSD1306 controller  // 0.96英寸 OLED 显示屏，采用 SSD1306 驱动芯片

//
// Einstart S OLED SSD1306  // Einstart S 机型专用 OLED 屏，SSD1306 控制器
//
//#define U8GLIB_SH1106_EINSTART

//
// Overlord OLED display/controller with i2c buzzer and LEDs  // Overlord机型专用OLED显示控制器，搭载I2C蜂鸣器与状态指示灯
//
//#define OVERLORD_OLED

//
// FYSETC OLED 2.42" 128×64 Full Graphics Controller with WS2812 RGB  // FYSETC 2.42英寸 OLED 全图形控制器，带 WS2812 RGB 氛围灯
// Where to find : https://www.aliexpress.com/item/4000345255731.html
//#define FYSETC_242_OLED_12864   // Uses the SSD1309 controller

//
// K.3D SSD1309 OLED 2.42" 128×64 Full Graphics Controller  // K.3D 2.42英寸 OLED 全图形控制器，SSD1309 驱动芯片
//
//#define K3D_242_OLED_CONTROLLER   // Software SPI

//=============================================================================
//========================== Extensible UI Displays ===========================
//=============================================================================
// 可扩展用户界面显示屏
// 注（译者注）：
// Extensible UI（ExtUI） 是 Marlin 2.x 引入的可扩展显示框架，用于统一管理各类串行智能屏 / 串口屏 / 带独立控制器的屏幕（DWIN、DGUS、TFT 触摸、OLED 大屏等），
// 与传统直接驱动的 LCD/OLED（U8GLIB、HD44780）完全分开。

/**
 * DGUS Touch Display with DWIN OS. (Choose one.)  // 搭载迪文系统 (DWIN OS) 的 DGUS 触控显示屏（二者任选其一）
 *
 * ORIGIN (Marlin DWIN_SET)
 *  - Download https://github.com/coldtobi/Marlin_DGUS_Resources
 *  - Copy the downloaded DWIN_SET folder to the SD card.
 *  - Product: https://www.aliexpress.com/item/32993409517.html
 *
 * FYSETC (Supplier default)
 *  - Download https://github.com/FYSETC/FYSTLCD-2.0
 *  - Copy the downloaded SCREEN folder to the SD card.
 *  - Product: https://www.aliexpress.com/item/32961471929.html
 *
 * HIPRECY (Supplier default)
 *  - Download https://github.com/HiPrecy/Touch-Lcd-LEO
 *  - Copy the downloaded DWIN_SET folder to the SD card.
 *
 * MKS (MKS-H43) (Supplier default)
 *  - Download https://github.com/makerbase-mks/MKS-H43
 *  - Copy the downloaded DWIN_SET folder to the SD card.
 *  - Product: https://www.aliexpress.com/item/1005002008179262.html
 *
 * RELOADED (T5UID1)
 *  - Download https://github.com/Neo2003/DGUS-reloaded/releases
 *  - Copy the downloaded DWIN_SET folder to the SD card.
 *
 * IA_CREALITY (T5UID1)
 *  - Download https://github.com/InsanityAutomation/Marlin/raw/CrealityDwin_2.0/TM3D_Combined480272_Landscape_V7.7z
 *  - Copy the downloaded DWIN_SET folder to the SD card.
 *
 * E3S1PRO (T5L)
 *  - Download https://github.com/CrealityOfficial/Ender-3S1/archive/3S1_Plus_Screen.zip
 *  - Copy the downloaded DWIN_SET folder to the SD card.
 *
 * Flash display with DGUS Displays for Marlin:
 *  - Format the SD card to FAT32 with an allocation size of 4kb.
 *  - Download files as specified for your type of display.
 *  - Plug the microSD card into the back of the display.
 *  - Boot the display and wait for the update to complete.
 * 
 * 为 Marlin 刷写搭载 DGUS 的界面程序
 * 将 SD 卡格式化为FAT32 格式，分配单元大小设为4KB
 * 根据你的屏幕型号下载对应固件文件
 * 把 Micro SD 卡插入显示屏背面卡槽
 * 上电启动屏幕，等待自动升级完成
 *
 * :[ 'ORIGIN', 'FYSETC', 'HYPRECY', 'MKS', 'RELOADED', 'IA_CREALITY', 'E3S1PRO' ]
 */
//#define DGUS_LCD_UI ORIGIN
#if DGUS_UI_IS(MKS)
  #define USE_MKS_GREEN_UI
#elif DGUS_UI_IS(IA_CREALITY)
  //#define LCD_SCREEN_ROTATE 90          // Portrait Mode or 800x480 displays
  //#define IA_CREALITY_BOOT_DELAY 1500   // (ms)
#endif

//
// LCD for Malyan M200/M300 printers
//
//#define MALYAN_LCD

//
// Touch UI for FTDI EVE (FT800/FT810) displays
// See Configuration_adv.h for all configuration options.
//
//#define TOUCH_UI_FTDI_EVE

//
// Touch-screen LCD for Anycubic Chiron
//
//#define ANYCUBIC_LCD_CHIRON

//
// Touch-screen LCD for Anycubic i3 Mega
//
//#define ANYCUBIC_LCD_I3MEGA
#if ENABLED(ANYCUBIC_LCD_I3MEGA)
  //#define ANYCUBIC_LCD_GCODE_EXT  // Add ".gcode" to menu entries for DGUS clone compatibility
#endif

//
// Touch-screen LCD for Anycubic Vyper
//
//#define ANYCUBIC_LCD_VYPER

//
// Sovol SV-06 Resistive Touch Screen
//
//#define SOVOL_SV06_RTS

//
// 320x240 Nextion 2.8" serial TFT Resistive Touch Screen NX3224T028
//
//#define NEXTION_TFT

//
// Third-party or vendor-customized controller interfaces.
// Sources should be installed in 'src/lcd/extui'.
//
//#define EXTENSIBLE_UI

#if ENABLED(EXTENSIBLE_UI)
  //#define EXTUI_LOCAL_BEEPER // Enables use of local Beeper pin with external display
#endif

//=============================================================================
//=============================== Graphical TFTs ==============================
//=============================================================================

/**
 * Specific TFT Model Presets. Enable one of the following options
 * or enable TFT_GENERIC and set sub-options.
 */

//
// 480x320, 3.5", SPI Display with Rotary Encoder from MKS
// Usually paired with MKS Robin Nano V2 & V3
// https://github.com/makerbase-mks/MKS-TFT-Hardware/tree/master/MKS%20TS35
//
//#define MKS_TS35_V2_0

//
// 320x240, 2.4", FSMC Display From MKS
// Usually paired with MKS Robin Nano V1.2
//
//#define MKS_ROBIN_TFT24

//
// 320x240, 2.8", FSMC Display From MKS
// Usually paired with MKS Robin Nano V1.2
//
//#define MKS_ROBIN_TFT28

//
// 320x240, 3.2", FSMC Display From MKS
// Usually paired with MKS Robin Nano V1.2
//
//#define MKS_ROBIN_TFT32

//
// 480x320, 3.5", FSMC Display From MKS
// Usually paired with MKS Robin Nano V1.2
//
//#define MKS_ROBIN_TFT35

//
// 480x272, 4.3", FSMC Display From MKS
//
//#define MKS_ROBIN_TFT43

//
// 320x240, 3.2", FSMC Display From MKS
// Usually paired with MKS Robin
//
//#define MKS_ROBIN_TFT_V1_1R

//
// 480x320, 3.5", FSMC Stock Display from Tronxy
//
//#define TFT_TRONXY_X5SA

//
// 480x320, 3.5", FSMC Stock Display from AnyCubic
//
//#define ANYCUBIC_TFT35

//
// 320x240, 2.8", FSMC Stock Display from Longer/Alfawise
//
//#define LONGER_LK_TFT28

//
// 320x240, 2.8", FSMC Stock Display from ET4
//
//#define ANET_ET4_TFT28

//
// 480x320, 3.5", FSMC Stock Display from ET5
//
//#define ANET_ET5_TFT35

//
// 1024x600, 7", RGB Stock Display with Rotary Encoder from BIQU BX
// https://github.com/bigtreetech/BIQU-BX/tree/master/Hardware
//
//#define BIQU_BX_TFT70

//
// 480x320, 3.5", SPI Stock Display with Rotary Encoder from BIQU B1 SE Series
// https://github.com/bigtreetech/TFT35-SPI/tree/master/v1
//
//#define BTT_TFT35_SPI_V1_0

//
// Generic TFT with detailed options
//
//#define TFT_GENERIC
#if ENABLED(TFT_GENERIC)
  // :[ 'AUTO', 'ST7735', 'ST7789', 'ST7796', 'R61505', 'ILI9328', 'ILI9341', 'ILI9488' ]
  #define TFT_DRIVER AUTO

  // Interface. Enable one of the following options:
  //#define TFT_INTERFACE_FSMC
  //#define TFT_INTERFACE_SPI

  // TFT Resolution. Enable one of the following options:
  //#define TFT_RES_320x240
  //#define TFT_RES_480x272
  //#define TFT_RES_480x320
  //#define TFT_RES_1024x600
#endif

/**
 * TFT UI - User Interface Selection. Enable one of the following options:
 *
 *   TFT_CLASSIC_UI - Emulated DOGM - 128x64 Upscaled
 *   TFT_COLOR_UI   - Marlin Default Menus, Touch Friendly, using full TFT capabilities
 *   TFT_LVGL_UI    - A Modern UI using LVGL
 *
 *   For LVGL_UI also copy the 'assets' folder from the build directory to the
 *   root of your SD card, together with the compiled firmware.
 */
//#define TFT_CLASSIC_UI
//#define TFT_COLOR_UI
//#define TFT_LVGL_UI

#if ENABLED(TFT_COLOR_UI)
  /**
   * TFT Font for Color UI. Choose one of the following:
   *
   * NOTOSANS  - Default font with anti-aliasing. Supports Latin Extended and non-Latin characters.
   * UNIFONT   - Lightweight font, no anti-aliasing. Supports Latin Extended and non-Latin characters.
   * HELVETICA - Lightweight font, no anti-aliasing. Supports Basic Latin (0x0020-0x007F) and Latin-1 Supplement (0x0080-0x00FF) characters only.
   */
  #define TFT_FONT  NOTOSANS

  /**
   * TFT Theme for Color UI. Choose one of the following or add a new one to 'Marlin/src/lcd/tft/themes' directory
   *
   * BLUE_MARLIN  - Default theme with 'midnight blue' background
   * BLACK_MARLIN - Theme with 'black' background
   * ANET_BLACK   - Theme used for Anet ET4/5
   */
  #define TFT_THEME BLACK_MARLIN

  //#define TFT_SHARED_IO   // I/O is shared between TFT display and other devices. Disable async data transfer.

  #define COMPACT_MARLIN_BOOT_LOGO  // Use compressed data to save Flash space
#endif

#if ENABLED(TFT_LVGL_UI)
  //#define MKS_WIFI_MODULE // MKS WiFi module
#endif

/**
 * TFT Rotation. Set to one of the following values:
 *
 *   TFT_ROTATE_90,  TFT_ROTATE_90_MIRROR_X,  TFT_ROTATE_90_MIRROR_Y,
 *   TFT_ROTATE_180, TFT_ROTATE_180_MIRROR_X, TFT_ROTATE_180_MIRROR_Y,
 *   TFT_ROTATE_270, TFT_ROTATE_270_MIRROR_X, TFT_ROTATE_270_MIRROR_Y,
 *   TFT_MIRROR_X, TFT_MIRROR_Y, TFT_NO_ROTATION
 *
 * :{ 'TFT_NO_ROTATION':'None', 'TFT_ROTATE_90':'90°', 'TFT_ROTATE_90_MIRROR_X':'90° (Mirror X)', 'TFT_ROTATE_90_MIRROR_Y':'90° (Mirror Y)', 'TFT_ROTATE_180':'180°', 'TFT_ROTATE_180_MIRROR_X':'180° (Mirror X)', 'TFT_ROTATE_180_MIRROR_Y':'180° (Mirror Y)', 'TFT_ROTATE_270':'270°', 'TFT_ROTATE_270_MIRROR_X':'270° (Mirror X)', 'TFT_ROTATE_270_MIRROR_Y':'270° (Mirror Y)', 'TFT_MIRROR_X':'Mirror X', 'TFT_MIRROR_Y':'Mirror Y' }
 */
//#define TFT_ROTATION TFT_NO_ROTATION

//=============================================================================
//============================  Other Controllers  ============================
//=============================================================================

//
// Ender-3 v2 OEM display. A DWIN display with Rotary Encoder.
//
//#define DWIN_CREALITY_LCD           // Creality UI
//#define DWIN_LCD_PROUI              // Pro UI by MRiscoC
//#define DWIN_CREALITY_LCD_JYERSUI   // Jyers UI by Jacob Myers
//#define DWIN_MARLINUI_PORTRAIT      // MarlinUI (portrait orientation)
//#define DWIN_MARLINUI_LANDSCAPE     // MarlinUI (landscape orientation)

//
// Touch Screen Settings
//
//#define TOUCH_SCREEN
#if ENABLED(TOUCH_SCREEN)
  #define BUTTON_DELAY_EDIT      50 // (ms) Button repeat delay for edit screens
  #define BUTTON_DELAY_MENU     250 // (ms) Button repeat delay for menus

  #if ANY(TFT_CLASSIC_UI, TFT_COLOR_UI)
    //#define NO_BACK_MENU_ITEM     // Don't display a top menu item to go back to the parent menu
  #endif

  #define TOUCH_SCREEN_CALIBRATION

  //#define TOUCH_CALIBRATION_X 12316
  //#define TOUCH_CALIBRATION_Y -8981
  //#define TOUCH_OFFSET_X        -43
  //#define TOUCH_OFFSET_Y        257
  //#define TOUCH_ORIENTATION TOUCH_LANDSCAPE

  #if ALL(TOUCH_SCREEN_CALIBRATION, EEPROM_SETTINGS)
    #define TOUCH_CALIBRATION_AUTO_SAVE // Auto save successful calibration values to EEPROM
  #endif

  #if ENABLED(TFT_COLOR_UI)
    //#define SINGLE_TOUCH_NAVIGATION
  #endif
#endif

//
// RepRapWorld REPRAPWORLD_KEYPAD v1.1
// https://reprapworld.com/products/electronics/ramps/keypad_v1_0_fully_assembled/
//
//#define REPRAPWORLD_KEYPAD
#if ENABLED(REPRAPWORLD_KEYPAD)
  //#define REPRAPWORLD_KEYPAD_MOVE_STEP 10.0 // (mm) Distance to move per key-press
#endif

//
// EasyThreeD ET-4000+ with button input and status LED
//
//#define EASYTHREED_UI

//=============================================================================
//=============================== Extra Features ==============================
//=============================================================================

// @section fans

// Set number of user-controlled fans. Disable to use all board-defined fans.
// :[1,2,3,4,5,6,7,8]
//#define NUM_M106_FANS 1

/**
 * Use software PWM to drive the fan, as for the heaters. This uses a very low frequency
 * which is not as annoying as with the hardware PWM. On the other hand, if this frequency
 * is too low, you should also increment SOFT_PWM_SCALE.
 */
//#define FAN_SOFT_PWM

/**
 * Incrementing this by 1 will double the software PWM frequency, affecting heaters, and
 * the fan if FAN_SOFT_PWM is enabled. However, control resolution will be halved for each
 * increment; at zero value, there are 128 effective control positions.
 * :[0,1,2,3,4,5,6,7]
 */
#define SOFT_PWM_SCALE 0

/**
 * If SOFT_PWM_SCALE is set to a value higher than 0, dithering can be used to mitigate the
 * associated resolution loss. If enabled, some of the PWM cycles are stretched so on average
 * the desired duty cycle is attained.
 */
//#define SOFT_PWM_DITHER

// @section extras

// Support for the BariCUDA Paste Extruder
//#define BARICUDA

// @section lights

/**
 * Temperature status LEDs that display the hotend and bed temperature.
 * If all hotends, bed temperature, and target temperature are under 54C
 * the BLUE led is on. Otherwise the RED led is on. (1C hysteresis)
 */
//#define TEMP_STAT_LEDS

// Support for BlinkM/CyzRgb
//#define BLINKM

// Support for PCA9632 PWM LED driver
//#define PCA9632

// Support for PCA9533 PWM LED driver
//#define PCA9533

/**
 * RGB LED / LED Strip Control
 *
 * Enable support for an RGB LED connected to 5V digital pins, or
 * an RGB Strip connected to MOSFETs controlled by digital pins.
 *
 * Adds the M150 command to set the LED (or LED strip) color.
 * If pins are PWM capable (e.g., 4, 5, 6, 11) then a range of
 * luminance values can be set from 0 to 255.
 * For NeoPixel LED an overall brightness parameter is also available.
 *
 *  === CAUTION ===
 *  LED Strips require a MOSFET Chip between PWM lines and LEDs,
 *  as the Arduino cannot handle the current the LEDs will require.
 *  Failure to follow this precaution can destroy your Arduino!
 *
 *  NOTE: A separate 5V power supply is required! The NeoPixel LED needs
 *  more current than the Arduino 5V linear regulator can produce.
 *
 *  Requires PWM frequency between 50 <> 100Hz (Check HAL or variant)
 *  Use FAST_PWM_FAN, if possible, to reduce fan noise.
 */

// LED Type. Enable only one of the following two options:
//#define RGB_LED
//#define RGBW_LED

#if ANY(RGB_LED, RGBW_LED)
  //#define RGB_LED_R_PIN 34
  //#define RGB_LED_G_PIN 43
  //#define RGB_LED_B_PIN 35
  //#define RGB_LED_W_PIN -1
#endif

#if ANY(RGB_LED, RGBW_LED, PCA9632)
  //#define RGB_STARTUP_TEST              // For PWM pins, fade between all colors
  #if ENABLED(RGB_STARTUP_TEST)
    #define RGB_STARTUP_TEST_INNER_MS 10  // (ms) Reduce or increase fading speed
  #endif
#endif

// Support for Adafruit NeoPixel LED driver
//#define NEOPIXEL_LED
#if ENABLED(NEOPIXEL_LED)
  #define NEOPIXEL_TYPE          NEO_GRBW // NEO_GRBW, NEO_RGBW, NEO_GRB, NEO_RBG, etc.
                                          // See https://github.com/adafruit/Adafruit_NeoPixel/blob/master/Adafruit_NeoPixel.h
  //#define NEOPIXEL_PIN                4 // LED driving pin
  //#define NEOPIXEL2_TYPE  NEOPIXEL_TYPE
  //#define NEOPIXEL2_PIN               5
  #define NEOPIXEL_PIXELS              30 // Number of LEDs in the strip. (Longest strip when NEOPIXEL2_SEPARATE is disabled.)
  #define NEOPIXEL_IS_SEQUENTIAL          // Sequential display for temperature change - LED by LED. Disable to change all LEDs at once.
  #define NEOPIXEL_BRIGHTNESS         127 // Initial brightness (0-255)
  //#define NEOPIXEL_STARTUP_TEST         // Cycle through colors at startup

  // Support for second Adafruit NeoPixel LED driver controlled with M150 S1 ...
  //#define NEOPIXEL2_SEPARATE
  #if ENABLED(NEOPIXEL2_SEPARATE)
    #define NEOPIXEL2_PIXELS           15 // Number of LEDs in the second strip
    #define NEOPIXEL2_BRIGHTNESS      127 // Initial brightness (0-255)
    #define NEOPIXEL2_STARTUP_TEST        // Cycle through colors at startup
    #define NEOPIXEL_M150_DEFAULT      -1 // Default strip for M150 without 'S'. Use -1 to set all by default.
  #else
    //#define NEOPIXEL2_INSERIES          // Default behavior is NeoPixel 2 in parallel
  #endif

  // Use some of the NeoPixel LEDs for static (background) lighting
  //#define NEOPIXEL_BKGD_INDEX_FIRST   0 // Index of the first background LED
  //#define NEOPIXEL_BKGD_INDEX_LAST    5 // Index of the last background LED
  //#define NEOPIXEL_BKGD_COLOR         { 255, 255, 255, 0 }  // R, G, B, W
  //#define NEOPIXEL_BKGD_TIMEOUT_COLOR {  25,  25,  25, 0 }  // R, G, B, W
  //#define NEOPIXEL_BKGD_ALWAYS_ON       // Keep the backlight on when other NeoPixels are off
#endif

/**
 * Printer Event LEDs
 *
 * During printing, the LEDs will reflect the printer status:
 *
 *  - Gradually change from blue to violet as the heated bed gets to target temp
 *  - Gradually change from violet to red as the hotend gets to temperature
 *  - Change to white to illuminate work surface
 *  - Change to green once print has finished
 *  - Turn off after the print has finished and the user has pushed a button
 */
#if ANY(BLINKM, RGB_LED, RGBW_LED, PCA9632, PCA9533, NEOPIXEL_LED)
  #define PRINTER_EVENT_LEDS
#endif

// @section servos

/**
 * Number of servos
 *
 * For some servo-related options NUM_SERVOS will be set automatically.
 * Set this manually if there are extra servos needing manual control.
 * Set to 0 to turn off servo support.
 */
//#define NUM_SERVOS 3 // Note: Servo index starts with 0 for M280-M282 commands

// (ms) Delay before the next move will start, to give the servo time to reach its target angle.
// 300ms is a good value but you can try less delay.
// If the servo can't reach the requested position, increase it.
#define SERVO_DELAY { 300 }

// Only power servos during movement, otherwise leave off to prevent jitter
//#define DEACTIVATE_SERVOS_AFTER_MOVE

// Edit servo angles with M281 and save to EEPROM with M500
//#define EDITABLE_SERVO_ANGLES

// Disable servo with M282 to reduce power consumption, noise, and heat when not in use
//#define SERVO_DETACH_GCODE
