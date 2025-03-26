#include "xparameters.h"  // 系統參數（GPIO ID）
#include "xgpio.h"        // GPIO 函式庫
#include <stdio.h>
#include <stdlib.h>

// 簡單延遲函式
void simple_delay(int simple_delay) {
    volatile int i = 0;
    for (i = 0; i < simple_delay; i++);
}

int main(int argc, char *argv[]) {
    XGpio led_gpio;  // 宣告 GPIO 實體

    // 初始化 GPIO
    XGpio_Initialize(&led_gpio, XPAR_AXI_GPIO_0_DEVICE_ID);

    // 設定通道 1 為輸出
    XGpio_SetDataDirection(&led_gpio, 1, 0x0);

    printf("Start to blink LED via AXI GPIO!\n\r");

    int led_value = 0xC3;  // 初始 LED 狀態

    while (1) {
        printf("LED GPIO value set to 0x%X\n\r", led_value);

        // 寫入 LED 值
        XGpio_DiscreteWrite(&led_gpio, 1, led_value);

        // 延遲
        simple_delay(100000000);

        // 翻轉 LED 狀態
        led_value = ~led_value;
    }

    return 0;
}
