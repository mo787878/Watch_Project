#include "key.h"

uint8_t KeyScan(uint8_t mode)
{
    static uint8_t key_up = 1;
    uint8_t key_value = 0;

    if(mode)
    {
        key_up = 1;
    }

    if (key_up &&
        HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin) == GPIO_PIN_RESET)
    {
        HAL_Delay(3);

        if (HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin) == GPIO_PIN_RESET)
        {
            key_value = 1;
            key_up = 0;
        }
    }
    else
    {
        HAL_Delay(3);

        if (HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin) == GPIO_PIN_SET)
        {
            key_up = 1;
        }
    }

    return key_value;
}