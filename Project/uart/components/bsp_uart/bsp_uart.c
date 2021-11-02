#include "bsp_uart.h"
#include "driver/uart.h"
#include "driver/gpio.h"

void Uart1_Init()
{
    uart_config_t uart_cfg ;
    uart_cfg.baud_rate = 9600 ;
    uart_cfg.data_bits = UART_DATA_8_BITS ;
    uart_cfg.flow_ctrl = UART_HW_FLOWCTRL_DISABLE ;
    uart_cfg.parity = UART_PARITY_DISABLE ;
    uart_cfg.stop_bits = UART_STOP_BITS_1 ;
    uart_cfg.source_clk = UART_SCLK_APB ;
    uart_param_config(UART_NUM_1, &uart_cfg);

    uart_set_pin(UART_NUM_1, GPIO_NUM_10, GPIO_NUM_9, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
}