#include "global.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stm32f429i_discovery.h"
#include "uart.h"

#define TERMINAL_USART						USART1
#define TERMINAL_TX 						GPIO_Pin_9
#define TERMINAL_RX 						GPIO_Pin_10
#define TERMINAL_GPIO						GPIOA

#define mainLED_TASK_PRIORITY				( tskIDLE_PRIORITY )

static void vhToggleLED(uint16_t xLedType);
static void vhLed_Init(void);
static void vTaskLED_Green(void * pvParameters);
static void vhButton_Init(void);
static void vHardwareSetup (void);

typedef enum
{
	FRAME_BASIC_MEAS,
	FRAME_PH_WATER,
	FRAME_PH_SOIL
}frame_type_t;

int main (void)
{
	vHardwareSetup();
	vTaskStartScheduler();

	return 0;
}

static void vHardwareSetup (void)
{
	SystemInit();
	SystemCoreClockUpdate();

	vhLed_Init();
	vhButton_Init();
	vhUartInit();
}

void HardFault_Handler (void)
{
	while (TRUE)
	{
//		USART_SendData(TERMINAL_USART, 'H');
//		puts("HARD FAULT...\n\r");
	}
}

static void vhButton_Init(void)
{
	RCC_AHB1PeriphClockCmd(USER_BUTTON_GPIO_CLK, ENABLE);
	GPIO_InitTypeDef GPIO_InitDef;

	GPIO_InitDef.GPIO_Pin = USER_BUTTON_PIN;
	GPIO_InitDef.GPIO_OType = GPIO_OType_PP;
	GPIO_InitDef.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitDef.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitDef.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_Init(USER_BUTTON_GPIO_PORT, &GPIO_InitDef);

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource0);

	EXTI_InitTypeDef EXTI_InitDef;
	EXTI_InitDef.EXTI_Line = EXTI_Line0;
	EXTI_InitDef.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitDef.EXTI_Trigger = EXTI_Trigger_Rising;
	EXTI_InitDef.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitDef);

	NVIC_PriorityGroupConfig( NVIC_PriorityGroup_4 );
	NVIC_InitTypeDef NVIC_EXTI_InitDef;
	NVIC_EXTI_InitDef.NVIC_IRQChannel = EXTI0_IRQn;
	NVIC_EXTI_InitDef.NVIC_IRQChannelPreemptionPriority = configLIBRARY_LOWEST_INTERRUPT_PRIORITY;
	NVIC_EXTI_InitDef.NVIC_IRQChannelSubPriority = 0;
	NVIC_EXTI_InitDef.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_EXTI_InitDef);
}

static void vhLed_Init (void)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG, ENABLE);
	GPIO_InitTypeDef GPIO_InitDef;

	GPIO_InitDef.GPIO_Pin = LED3_PIN | LED4_PIN;
	GPIO_InitDef.GPIO_OType = GPIO_OType_PP;
	GPIO_InitDef.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitDef.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitDef.GPIO_Speed = GPIO_Speed_100MHz;
	//Initialize pins
	GPIO_Init(GPIOG, &GPIO_InitDef);

	xTaskCreate(vTaskLED_Green, (portCHAR *) "LED_GREEN", configMINIMAL_STACK_SIZE, NULL, mainLED_TASK_PRIORITY, NULL );

}

void EXTI0_IRQHandler(void){
	long xHigherPriorityTaskWoken = pdFALSE;

	if(EXTI_GetITStatus(EXTI_Line0) != RESET){
		vhToggleLED(LED3_PIN);
		EXTI_ClearITPendingBit(EXTI_Line0);
	}

	portEND_SWITCHING_ISR( xHigherPriorityTaskWoken );
}

static void vTaskLED_Green (void * pvParameters)
{
	portTickType xLastFlashTime;

	xLastFlashTime = xTaskGetTickCount();
	frame_type_t frameFlag = FRAME_BASIC_MEAS;

	while (TRUE)
	{
		vTaskDelayUntil(&xLastFlashTime, 500/portTICK_RATE_MS);
		vhToggleLED(LED4_PIN);

		switch (frameFlag)
		{
		case FRAME_BASIC_MEAS:
			//STA PRIMARYMEAS hum lux temp1 temp2 temp3 soil END
			vSerialPutString((char*)"STA PRIMARYMEAS 47 15426 24.3 25.1 24.6 0 END");
			frameFlag = FRAME_PH_SOIL;
			break;

		case FRAME_PH_WATER:
			//STA PHW waterPh END
			vSerialPutString((char*)"STA PHW 6.78 END");
			frameFlag = FRAME_PH_WATER;
			break;

		case FRAME_PH_SOIL:
			//STA PHS soilPh END
			vSerialPutString((char*)"STA PHS 4.89 END");
			frameFlag = FRAME_BASIC_MEAS;
			break;

		default:
			vSerialPutString((char*)"NONE FRAME!\r\n");
			break;
		}
	}
}

static void vhToggleLED (uint16_t xLedType)
{
	GPIO_ToggleBits(GPIOG, xLedType);
}


void vApplicationMallocFailedHook( void )
{
	/* vApplicationMallocFailedHook() will only be called if
	configUSE_MALLOC_FAILED_HOOK is set to 1 in FreeRTOSConfig.h.  It is a hook
	function that will get called if a call to pvPortMalloc() fails.
	pvPortMalloc() is called internally by the kernel whenever a task, queue,
	timer or semaphore is created.  It is also called by various parts of the
	demo application.  If heap_1.c or heap_2.c are used, then the size of the
	heap available to pvPortMalloc() is defined by configTOTAL_HEAP_SIZE in
	FreeRTOSConfig.h, and the xPortGetFreeHeapSize() API function can be used
	to query the size of free heap space that remains (although it does not
	provide information on how the remaining heap might be fragmented). */
	taskDISABLE_INTERRUPTS();
	for( ;; );
}
/*-----------------------------------------------------------*/

void vApplicationIdleHook( void )
{
	/* vApplicationIdleHook() will only be called if configUSE_IDLE_HOOK is set
	to 1 in FreeRTOSConfig.h.  It will be called on each iteration of the idle
	task.  It is essential that code added to this hook function never attempts
	to block in any way (for example, call xQueueReceive() with a block time
	specified, or call vTaskDelay()).  If the application makes use of the
	vTaskDelete() API function (as this demo application does) then it is also
	important that vApplicationIdleHook() is permitted to return to its calling
	function, because it is the responsibility of the idle task to clean up
	memory allocated by the kernel to any task that has since been deleted. */
}
/*-----------------------------------------------------------*/

void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName )
{
	( void ) pcTaskName;
	( void ) pxTask;

	/* Run time stack overflow checking is performed if
	configCHECK_FOR_STACK_OVERFLOW is defined to 1 or 2.  This hook
	function is called if a stack overflow is detected. */
	taskDISABLE_INTERRUPTS();
	for( ;; );
}
