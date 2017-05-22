/*
 * uart.h
 *
 *  Created on: Dec 28, 2016
 *      Author: Damian Dolewski
 */

#ifndef INC_UART_H_
#define INC_UART_H_

#include "stdint.h"
#include "stddef.h"
#include "FreeRTOS.h"
#include "queue.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_usart.h"

#define TERMINAL_USART						USART1
#define TERMINAL_TX 						GPIO_Pin_9
#define TERMINAL_RX 						GPIO_Pin_10
#define TERMINAL_GPIO						GPIOA

void vhUartInit(void);
signed portBASE_TYPE xSerialPutChar(signed char cOutChar);
signed portBASE_TYPE xSerialGetChar(signed char *pcRxedChar);
void vSerialPutString(char * xString);

extern QueueHandle_t xRxedChars;
extern QueueHandle_t xCharsForTx;

#endif /* INC_UART_H_ */
