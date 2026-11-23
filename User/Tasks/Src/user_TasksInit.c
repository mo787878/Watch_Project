#include "user_TasksInit.h"
#include "user_HardwareInitTask.h"

#include <stdio.h>

static osThreadId_t hardwareInitHandle;

static const osThreadAttr_t hardwareInitAttr = {
    .name = "HardwareInit",
    .stack_size = 2048,
    .priority = (osPriority_t)osPriorityHigh,
};

void User_Tasks_Init(void)
{
    hardwareInitHandle = osThreadNew(
        HardwareInitTask,
        NULL,
        &hardwareInitAttr);

        if(hardwareInitHandle == NULL)
        {
            printf("Create HardwareInitTask failed\r\n");
        }
}