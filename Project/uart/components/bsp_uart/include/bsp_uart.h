#ifndef _BSP_UART_H_
#define _BSP_UART_H_

#include "esp_system.h"
#include "sdkconfig.h"

#define TEST_UART_PORT          (CONFIG_TEST_UART_PORT)
#define TEST_UART_TXD           (CONFIG_TEST_UART_TXD)
#define TEST_UART_RXD           (CONFIG_TEST_UART_TXD)
#define TEST_UART_BAUD          (CONFIG_TEST_UART_BAUD)
#define TEST_UART_BUFFER_SIZE   (CONFIG_TEST_UART_BUFFER_SIZE)

//uart事件队列句柄
extern QueueHandle_t test_uart_queue ;

void Test_Uart_Init(void);

#endif