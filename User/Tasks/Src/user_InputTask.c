#include "user_InputTask.h"

#include "cmsis_os.h"
#include "key.h"
#include "CST816.h"

#include <stdio.h>

void InputTask(void *argument)
{
    (void)argument;

    printf("InputTask start\r\n");

    for (;;)
    {
        if (KeyScan(0) == 1)
        {
            printf("KEY pressed\r\n");
        }

        uint8_t finger_num = CST816_Get_FingerNum();

        if (finger_num != 0x00 && finger_num != 0xFF)
        {
            CST816_Get_XY_AXIS();

            printf(
                "TOUCH x=%u y=%u finger=%u\r\n",
                (unsigned int)CST816_Instance.X_Pos,
                (unsigned int)CST816_Instance.Y_Pos,
                (unsigned int)finger_num);
        }
        
        osDelay(20);
    }
}