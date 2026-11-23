#include "user_TasksInit.h"
#include "user_HardwareInitTask.h"
#include "user_InputTask.h"

#include <stdio.h>

static osThreadId_t hardwareInitHandle;
static osThreadId_t inputHandle;

static const osThreadAttr_t hardwareInitAttr = {
    .name = "HardwareInit",
    .stack_size = 2048,
    .priority = (osPriority_t)osPriorityHigh,
};

static const osThreadAttr_t inputTaskAttr = {
    .name = "InputTask",
    .stack_size = 2048,
    .priority = (osPriority_t)osPriorityNormal,
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

    inputHandle = osThreadNew(
        InputTask,
        NULL,
        &inputTaskAttr);

        if(inputHandle == NULL)
        {
            printf("Create InputTask failed\r\n");
        }   
}