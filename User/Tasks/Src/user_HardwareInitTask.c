#include "user_HardwareInitTask.h"

#include "cmsis_os.h"
#include "delay.h"
#include "lcd.h"
#include "lcd_init.h"

#include <stdio.h>

void HardwareInitTask(void *argument)
{
    (void)argument;
    delay_init();

    printf("Hardware init start\r\n");

    LCD_Init();
    printf("LCD init done\r\n");

    for (;;)
    {
        LCD_Fill(0, 0, LCD_W, LCD_H, RED);
        printf("LCD RED\r\n");
        osDelay(1000);

        LCD_Fill(0, 0, LCD_W, LCD_H, GREEN);
        printf("LCD GREEN\r\n");
        osDelay(1000);

        LCD_Fill(0, 0, LCD_W, LCD_H, BLUE);
        printf("LCD BLUE\r\n");
        osDelay(1000);
    }
}