#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"

#include "bsp_uart.h"

void app_main(void)
{
    Test_Uart_Init();
    while(1)
    {
        
    }
}
