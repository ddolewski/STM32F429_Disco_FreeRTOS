/*
 * uart.c
 *
 *  Created on: Dec 28, 2016
 *      Author: Damian Dolewski
 */
#include "uart.h"

QueueHandle_t xRxedChars = NULL;
QueueHandle_t xCharsForTx = NULL;

void vhUartInit(void)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	GPIO_PinAFConfig(TERMINAL_GPIO, GPIO_PinSource9, GPIO_AF_USART1);  //Tx
	GPIO_PinAFConfig(TERMINAL_GPIO, GPIO_PinSource10, GPIO_AF_USART1); //Rx

	GPIO_InitTypeDef gpioUsart;
	gpioUsart.GPIO_Mode = GPIO_Mode_AF;
	gpioUsart.GPIO_OType = GPIO_OType_PP;
	gpioUsart.GPIO_Pin = TERMINAL_TX | TERMINAL_RX;
	gpioUsart.GPIO_Speed = GPIO_Speed_50MHz;
	gpioUsart.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(TERMINAL_GPIO, &gpioUsart);

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);

	USART_InitTypeDef USART_InitStructure;
	USART_InitStructure.USART_BaudRate = 115200;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No ;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	//Write USART1 parameters
	USART_Init(USART1, &USART_InitStructure);
	//Enable USART1
	USART_Cmd(USART1, ENABLE);

	NVIC_PriorityGroupConfig( NVIC_PriorityGroup_4 );

	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = configLIBRARY_LOWEST_INTERRUPT_PRIORITY;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	USART_ITConfig(USART1, USART_IT_TXE, DISABLE);
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);

	xRxedChars = xQueueCreate( 64, ( unsigned portBASE_TYPE ) sizeof( signed char ) );
	xCharsForTx = xQueueCreate( 64 + 1, ( unsigned portBASE_TYPE ) sizeof( signed char ) );
}

signed portBASE_TYPE xSerialGetChar(signed char *pcRxedChar)
{
	if( xQueueReceive( xRxedChars, pcRxedChar, (TickType_t)0 ) )
	{
		return pdTRUE;
	}
	else
	{
		return pdFALSE;
	}
}

void vSerialPutString(char * xString)
{
	signed char *pxNext;

	/* Send each character in the string, one at a time. */
	pxNext = ( signed char * ) xString;
	while ( *pxNext )
	{
		xSerialPutChar( *pxNext );
		pxNext++;
	}
}

signed portBASE_TYPE xSerialPutChar(signed char cOutChar)
{
	signed portBASE_TYPE xReturn;

	if ( xQueueSend( xCharsForTx, &cOutChar, ( TickType_t ) 0 ) == pdPASS )
	{
		xReturn = pdPASS;
		USART_ITConfig( USART1, USART_IT_TXE, ENABLE );
	}
	else
	{
		xReturn = pdFAIL;
	}

	return xReturn;
}

void USART1_IRQHandler(void)
{
	portBASE_TYPE xHigherPriorityTaskWoken = pdFALSE;
	char cChar;

	if( USART_GetITStatus( USART1, USART_IT_TXE ) == SET )
	{
		if( xQueueReceiveFromISR( xCharsForTx, &cChar, &xHigherPriorityTaskWoken ) == pdTRUE )
		{
			USART_SendData( USART1, cChar );
		}
		else
		{
			USART_ITConfig( USART1, USART_IT_TXE, DISABLE );
		}

		USART_ClearITPendingBit(USART1, USART_IT_TXE);
	}

	if( USART_GetITStatus( USART1, USART_IT_RXNE ) == SET )
	{
		cChar = USART_ReceiveData( USART1 );
		xQueueSendFromISR( xRxedChars, &cChar, &xHigherPriorityTaskWoken );

		USART_ClearITPendingBit(USART1, USART_IT_RXNE);
	}

	portEND_SWITCHING_ISR( xHigherPriorityTaskWoken );
}
