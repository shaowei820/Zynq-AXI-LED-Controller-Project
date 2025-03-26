# Zynq-AXI-GPIO-LED-Blinking

## 專案簡介

本專案展示如何使用 Xilinx Zynq SoC 上的 **AXI GPIO** 介面，透過 **Processing System (PS)** 控制 **PL (Programmable Logic)** 端的 8 顆 LED 燈，達成簡單的閃爍效果。

本專案以 C 語言撰寫，控制 AXI GPIO IP 將資料寫入 LED，藉此達成 LED 閃爍。

## 系統架構

![image](https://github.com/user-attachments/assets/763644ae-072d-450c-85e9-9badafe18237)

## 需求分析
#### 硬體需求

| 項目             | 說明 |
|------------------|------|
| **開發板**       | EGO-XZ7 Board (Zynq-7000 SoC，型號：XC7Z020CLG484-1) |
| **處理器**       | 雙核心 ARM Cortex-A9，最高時脈約 866 MHz |
| **可程式邏輯 (PL)** | 用來整合 AXI GPIO IP，控制外部 8 顆 LED |
| **LED 燈**       | 8 顆（與 AXI GPIO 輸出腳位相連） |


#### 軟體需求

| 軟體工具      | 說明 |
|---------------|------|
| **Xilinx Vivado** | 建立硬體架構（Block Design）、產生 bitstream 與 XSA 檔案 |


## 主要元件：

- `processing_system7_0`：Zynq PS，包含 ARM CPU。
- `axi_gpio_0`：AXI GPIO IP，用來控制 LED。
- `ps7_0_axi_periph`：AXI Interconnect，連接 PS 和 GPIO。
- `rst_ps7_0_50M`：Reset 模組。
- `leds_8bits`：輸出腳位，連接到實體 LED。

## DEMO
https://github.com/user-attachments/assets/774fa24d-8e63-490a-a5d0-78742201dd34
