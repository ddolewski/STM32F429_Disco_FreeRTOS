#ifndef GLOBAL_H_
#define GLOBAL_H_



//-----------------------STANDARD C LIBS--------------------------//
#include "stdint.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
//-----------------------KERNEL FreeRTOS--------------------------//
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "croutine.h"
//-----------------------STM32F4xx LIBS--------------------------//
#include "system_stm32f4xx.h"
#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_usart.h"
#include "tm_stm32f4_disco.h"

#define DEBUG_MODE

#ifdef DEBUG_MODE
// wlasne definy
#else
//	#define GLOBAL_FLASH_PROTECT
//	#define WATCHDOG_ON
#endif

//#define NULL 			0
#define ALWAYS 			1

#define True			1
#define False			0
#define Other			2

typedef enum {FALSE, TRUE, OTHER} bool_t;
typedef void (*fun_ptr_t)(void);
#define ASSERT(ARG)

#define ARRAY_LEN(X) (sizeof(X) / sizeof(X[0])) //liczba elementow tabeli

#define SETIO(PORT, PIN)	 	GPIOx_SetPin(PORT, PIN)
#define CLRIO(PORT, PIN)	 	GPIOx_ResetPin(PORT, PIN)

//Timer systemowy
#define SYSTIMER 				SysTick
#define SYSTIME_HANDLER			SysTick_Handler

#define UC						(uint8_t *)

#define PACK_STRUCT_BEGIN
#define PACK_STRUCT_STRUCT 		__attribute__ ((__packed__))
#define PACK_STRUCT_END
#define PACK_STRUCT_FIELD(x) 	x
#define SIZEOF_TAB(x) 			(sizeof(x)/sizeof(x[0]))

#define ASM_REV32				__REV
#define ASM_REV16				__REV16

#define MAX(X,Y) 				((X)>(Y)?(X):(Y))
#define MIN(X,Y) 				((X)<(Y)?(X):(Y))
#define ABS_DIF(X,Y)			(MAX(X,Y) - MIN(X,Y))
#define ABS(X)           		(((X) < 0) ? -(X) : (X))

#endif
