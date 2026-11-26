#include "user_HardwareInitTask.h"

#include "cmsis_os.h"
#include "delay.h"
#include "lcd.h"
#include "lcd_init.h"
#include "CST816.h"

#include <stdio.h>

static uint16_t dma_test_buf[32 * 32];

void HardwareInitTask(void *argument)
{
    (void)argument;
    delay_init();

    printf("Hardware init start\r\n");

    LCD_Init();
    printf("LCD init done\r\n");

    CST816_GPIO_Init();
    CST816_RESET();
    CST816_Config_AutoSleepTime(5);

    printf("CST816 init done\r\n");
    printf("CST816 chip reg = 0x%02X\r\n", CST816_Get_ChipID());

    vTaskDelete(NULL);
}