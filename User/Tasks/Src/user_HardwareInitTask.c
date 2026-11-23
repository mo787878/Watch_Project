#include "user_HardwareInitTask.h"

#include "cmsis_os.h"
#include "delay.h"
#include "lcd.h"
#include "lcd_init.h"

#include <stdio.h>

static uint16_t dma_test_buf[32 * 32];

void HardwareInitTask(void *argument)
{
    (void)argument;
    delay_init();

    printf("Hardware init start\r\n");

    LCD_Init();
    printf("LCD init done\r\n");

    vTaskDelete(NULL);
}