# Klipper 固件与配置

本目录为 0xC0FFEE_ZY 3D 打印机主板的 Klipper 预编译固件、配套配置文件，以及编译时的菜单配置截图。

## 文件说明

| 文件 | 用途 |
|---|---|
| `klipper.bin` | 预编译的 Klipper MCU 固件。基于 `make_menuconfig.png` 中选项编译生成。 |
| `printer.cfg` | Klipper 主配置文件，定义 MCU 连接、运动学、步进电机、挤出机、热床等核心硬件参数。 |
| `make_menuconfig.png` | 编译 `klipper.bin` 时使用的配置菜单截图。用于确认 MCU 架构、处理器型号、Bootloader 偏移量、通信接口等关键选项。 |

## 使用前提

- 上位机（树莓派等）已安装 Klipper 服务，并能通过 SSH 或网页界面访问。
- `klipper.bin` 仅适用于与截图配置**完全匹配**的 MCU。配置不匹配时会导致无法正常通信。

## 编译配置参考（make_menuconfig.png）

`klipper.bin` 是基于以下类别的选项编译生成的。make_menuconfig.png 图中展示的每一项都直接决定了固件能否在目标主板上运行：

```text
=====================================================================
 下位机固件编译 (make menuconfig) 注意
=====================================================================

 选项具体内容可参考开源仓库 Klipper 文件夹内的 make_menuconfig.png 图片。
 
  在树莓派等上位机上编译（cd ~/klipper && make menuconfig）

  1. 勾选「Enable extra low-level configuration options」
  2. Micro-controller Architecture ：STMicroelectronics STM32
  3. Processor model               ：STM32F407
  4. Bootloader offset             ：No bootloader（ST-Link 直接烧到 0x08000000）
  5. Clock Reference               ：8 MHz crystal   硬件电路中晶振为 8MHz
  6. Communication interface       ：Serial (on USART3 PD9/PD8)   ← PD8=TX、PD9=RX
  7. Baud rate                     ：250000（与 [mcu] 默认波特率一致）

  说明：
  · 编译产物 ~/klipper/out/klipper.bin，用 ST-Link 烧到 0x08000000。
```

如果你要**重新编译**，在 `~/klipper` 目录下执行：

```bash
make clean
make menuconfig
# 根据 make_menuconfig.png 逐项核对并选择
make
```

<div align="right">
Author：0xC0FFEE_ZY<br>
Date：2026-10-31
</div>