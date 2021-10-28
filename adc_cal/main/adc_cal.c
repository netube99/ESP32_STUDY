#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_adc_cal.h"

esp_adc_cal_characteristics_t adc1_cal_t ;      //校准值保存结构体
uint32_t voltage_mv ;                           //转换得到的的电压值
bool efuse_flag ;                               //内部校准值有效标志位

void ADC_Init(void)
{
    //查询是否有校准值
    if(esp_adc_cal_check_efuse(ESP_ADC_CAL_VAL_EFUSE_VREF) != ESP_OK)
    {
        efuse_flag = false ;
        printf("efuse value error !\r\n");
    }
    else
    {
        efuse_flag = true ;
        printf("efuse value ready !\r\n");
    }
    //设置数据宽度，设置通道的衰减值
    adc1_config_width(ADC_WIDTH_12Bit);
    adc1_config_channel_atten(ADC_CHANNEL_6, ADC_ATTEN_11db);
    //保存efuse的校准值到结构体，作为后续的电压转换做参考
    esp_adc_cal_characterize(ADC_UNIT_1, ADC_ATTEN_11db, ADC_WIDTH_12Bit, 1100, &adc1_cal_t);
}

void app_main(void)
{
    ADC_Init();
    while(1)
    {
        //转换电压，电压值保存到 voltage_mv
        esp_adc_cal_get_voltage(ADC_CHANNEL_6, &adc1_cal_t, &voltage_mv);
        if(efuse_flag)
            printf("the voltage conversion by efuse vref : %d mV\r\n", voltage_mv);
        else
            printf("the voltage conversion by default vref : %d mV\r\n", voltage_mv);
        //延时一秒
        vTaskDelay(1000/portTICK_RATE_MS);
    }
}
