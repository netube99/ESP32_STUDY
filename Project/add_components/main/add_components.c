#include <stdio.h>
#include "bsp.h"

void app_main(void)
{
    while(1)
    {
        BSP_Test();
        vTaskDelay(1000/portTICK_RATE_MS);
    }
}