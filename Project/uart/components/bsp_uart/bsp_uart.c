#include "bsp_uart.h"
#include "driver/uart.h"
#include "driver/gpio.h"

//uart事件队列句柄
QueueHandle_t test_uart_queue ;

void Test_Uart_Init(void)
{
    //注册串口的驱动程序
    //未能理解 intr_alloc_flags 这个参数的意义
    uart_driver_install(TEST_UART_PORT, TEST_UART_BUFFER_SIZE, \
                        TEST_UART_BUFFER_SIZE, 10, &test_uart_queue, 0);
    
    //修改串口参数
    uart_config_t uart_cfg ;
    uart_cfg.baud_rate = 9600 ;
    uart_cfg.data_bits = UART_DATA_8_BITS ;
    uart_cfg.flow_ctrl = UART_HW_FLOWCTRL_DISABLE ;
    uart_cfg.parity = UART_PARITY_DISABLE ;
    uart_cfg.stop_bits = UART_STOP_BITS_1 ;
    uart_cfg.source_clk = UART_SCLK_APB ;
    uart_param_config(UART_NUM_1, &uart_cfg);

    //设置gpio复用为串口专用引脚
    uart_set_pin(UART_NUM_1, GPIO_NUM_10, GPIO_NUM_9, \
                UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
}