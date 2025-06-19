# ZYNQ AXI GPIO LED Blinker

這是一個簡單的範例程式，展示如何在 ZYNQ SoC 上透過 AXI GPIO 控制 LED 閃爍。該程式使用 Xilinx 提供的 `XGpio` 函式庫來初始化與控制 GPIO 硬體。

## 硬體需求

- ZedBoard 或其他具備 AXI GPIO 的 ZYNQ FPGA 開發板
- 至少一組連接至 `AXI GPIO` 的 LED
- 已使用 Vivado 建立 Block Design 並連接：
  - `AXI GPIO` (1 channel, output)
  - 並已產生 Bitstream、Export Hardware、Launch Vitis

## 軟體環境

- Xilinx Vitis
- 包含以下檔案：
  - `main.c`：主程式（如上）
  - `xparameters.h`：自動由 Vitis 產生，包含 AXI GPIO ID 定義
  - `xgpio.h`：Xilinx GPIO 函式庫標頭

## 程式說明

### 初始化與設置

```c
XGpio_Initialize(&led_gpio, XPAR_AXI_GPIO_0_DEVICE_ID);
XGpio_SetDataDirection(&led_gpio, 1, 0x0);  // 通道 1 設定為輸出
