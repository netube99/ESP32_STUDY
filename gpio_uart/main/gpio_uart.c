#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "driver/gpio.h"
#include "driver/uart.h"

#define LED_RED_PIN             GPIO_NUM_32
#define LED_GREEN_PIN           GPIO_NUM_15
#define LED_GREEN_PIN_SEL       GPIO_SEL_15
#define LED_BLUE_PIN            GPIO_NUM_16
#define LED_BLUE_PIN_SEL        GPIO_SEL_16

#define UART_TEST               UART_NUM_1

//GPIO 初始化方式1
void GPIO_Init_1(void)
{
    gpio_reset_pin(LED_RED_PIN);                            //复位为普通管脚
    gpio_set_level(LED_RED_PIN, 1);                         //预设为高电平
    gpio_set_direction(LED_RED_PIN,GPIO_MODE_OUTPUT_OD);    //设置管脚模式为开漏输出
}

//GPIO 初始化方式2
void GPIO_Init_2()
{
    gpio_set_level(LED_GREEN_PIN, 1);
    gpio_set_level(LED_BLUE_PIN, 1);

    gpio_config_t gpio_cfgt ;
    gpio_cfgt.intr_type = GPIO_INTR_DISABLE ;
    gpio_cfgt.mode = GPIO_MODE_OUTPUT_OD ;
    gpio_cfgt.pull_down_en = GPIO_PULLDOWN_DISABLE ;
    gpio_cfgt.pull_up_en = GPIO_PULLUP_ENABLE ;
    gpio_cfgt.pin_bit_mask = LED_GREEN_PIN_SEL ;
    gpio_config(&gpio_cfgt);

    gpio_cfgt.pin_bit_mask = LED_BLUE_PIN_SEL ;
    gpio_config(&gpio_cfgt);
}

void UART_Init(void)
{
    uart_config_t uart_cfgt ;
    uart_cfgt.baud_rate = 9600 ;                            //波特率
    uart_cfgt.data_bits = UART_DATA_8_BITS ;                //数据长度
    uart_cfgt.flow_ctrl = UART_HW_FLOWCTRL_DISABLE ;        //关闭硬件流控制
    uart_cfgt.parity = UART_PARITY_DISABLE ;                //奇偶校验关闭
    // uart_cfgt.rx_flow_ctrl_thresh = 122 ;                   //这到底是啥？
    uart_cfgt.source_clk = UART_SCLK_APB ;                  //从APB获取串口外设的时钟
    uart_cfgt.stop_bits = UART_STOP_BITS_1 ;                //设置停止位
    // uart_cfgt.use_ref_tick =                                //这又是个啥
    uart_param_config(UART_TEST, &uart_cfgt);              //根据参数配置串口外设
}

void app_main(void)
{
    GPIO_Init_1();
    GPIO_Init_2();
    UART_Init();
    while(1)
    {
        //测试红灯
        printf("LOGHT ON !\r\n");
        gpio_set_level(LED_RED_PIN, 0);
        vTaskDelay(500/portTICK_PERIOD_MS);
        printf("LOGHT OFF !\r\n");
        gpio_set_level(LED_RED_PIN, 1);
        vTaskDelay(500/portTICK_PERIOD_MS);

        //测试绿灯
        printf("LOGHT ON !\r\n");
        gpio_set_level(LED_GREEN_PIN, 0);
        vTaskDelay(500/portTICK_PERIOD_MS);
        printf("LOGHT OFF !\r\n");
        gpio_set_level(LED_GREEN_PIN, 1);
        vTaskDelay(500/portTICK_PERIOD_MS);

        //测试蓝灯
        printf("LOGHT ON !\r\n");
        gpio_set_level(LED_BLUE_PIN, 0);
        vTaskDelay(500/portTICK_PERIOD_MS);
        printf("LOGHT OFF !\r\n");
        gpio_set_level(LED_BLUE_PIN, 1);
        vTaskDelay(500/portTICK_PERIOD_MS);
    }
}
