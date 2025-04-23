# Zynq-AXI-GPIO-LED-Blinking

### 專案簡介

本專案展示如何使用 Xilinx Zynq SoC 上的 **AXI GPIO** 介面，透過 **Processing System (PS)** 控制 **PL (Programmable Logic)** 端的自訂模組 `soc_led_v1_0`，進一步控制 8 顆 LED 燈達成閃爍效果。

本專案以 C 語言撰寫，透過 AXI 匯流排控制 AXI GPIO IP 將資料寫入自訂 RTL 模組，藉此驅動 LED 閃爍。

---
### 架構圖
![image](https://github.com/user-attachments/assets/09a4e7c8-b59d-44e2-8e58-6ebb00e9a61c)

---


### 硬體需求

| 項目             | 說明 |
|------------------|------|
| **開發板**       | EGO-XZ7 Board (Zynq-7000 SoC，型號：XC7Z020CLG484-1) |
| **處理器**       | 雙核心 ARM Cortex-A9，最高時脈約 866 MHz |
| **可程式邏輯 (PL)** | 整合 AXI GPIO IP 與自訂模組 `soc_led_v1_0`，控制外部 8 顆 LED |
| **LED 燈**       | 8 顆（由 `soc_led_v1_0` 模組輸出控制） |

### 軟體需求

| 軟體工具          | 說明 |
|-------------------|------|
| **Xilinx Vivado** | 建立硬體架構（Block Design）、產生 bitstream 與 XSA 檔案 |
| **Vitis / SDK**   | 撰寫 C 程式控制 AXI GPIO，傳送資料給自訂模組 |

---

### 主要元件說明

- **`processing_system7_0`**：Zynq PS，包含 ARM CPU、AXI GP 埠、DDR 等。
- **`axi_gpio_0`**：AXI GPIO IP，將 PS 資料透過 AXI 匯流排送至 PL。
- **`soc_led_v1_0`**：自訂 RTL 模組，接收 GPIO 輸入並輸出控制 LED 狀態。
- **`ps7_0_axi_periph`**：AXI Interconnect，作為 PS 與 PL 間的橋接。
- **`rst_ps7_0_50M`**：Reset 模組，提供統一的 reset 給設計中的所有元件。
