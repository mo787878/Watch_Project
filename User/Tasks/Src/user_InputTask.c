#include "user_InputTask.h"

#include "cmsis_os.h"
#include "key.h"

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

        osDelay(10);
    }
}