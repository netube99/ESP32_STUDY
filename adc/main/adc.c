#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "driver/adc.h"

//设置光敏电阻ADC输入通道
#define LIGHT_RES_PIN   ADC1_CHANNEL_6

void ADC_Init(void)
{
    //设置数据位数和通道输入衰减
    adc1_config_width(ADC_WIDTH_BIT_12);
    adc1_config_channel_atten(LIGHT_RES_PIN, ADC_ATTEN_DB_2_5);
}

void app_main(void)
{
    ADC_Init(); //初始化ADC
    while (1)
    {
        uint16_t raw = adc1_get_raw(LIGHT_RES_PIN) ;    //获得ADC转换原数据
        float mv = raw * 1100 / 4096.0 ;                //根据衰减倍数与数据位数换算成电压
        printf("voltage = %.3f mv\r\n", mv);            //打印电压数据观察变化
        vTaskDelay(100/portTICK_RATE_MS);               //延时一段时间准备下次测量
    }
}
