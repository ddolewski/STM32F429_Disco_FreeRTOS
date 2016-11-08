################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRTOS/croutine.c \
../FreeRTOS/event_groups.c \
../FreeRTOS/list.c \
../FreeRTOS/queue.c \
../FreeRTOS/tasks.c \
../FreeRTOS/timers.c 

OBJS += \
./FreeRTOS/croutine.o \
./FreeRTOS/event_groups.o \
./FreeRTOS/list.o \
./FreeRTOS/queue.o \
./FreeRTOS/tasks.o \
./FreeRTOS/timers.o 

C_DEPS += \
./FreeRTOS/croutine.d \
./FreeRTOS/event_groups.d \
./FreeRTOS/list.d \
./FreeRTOS/queue.d \
./FreeRTOS/tasks.d \
./FreeRTOS/timers.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS/%.o: ../FreeRTOS/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-none-eabi-gcc -DDEBUG -DSTM32F4 -DSTM32 -DSTM32F429_439xx -DSTM32F429I_DISC1 -DSTM32F429ZITx -DUSE_STDPERIPH_DRIVER -I"C:\Git_Workspace\Eclipse_Workspace\STM32F4_projekt_FreeRTOS\STM32F429_FreeRTOS\CMSIS\core" -I"C:\Git_Workspace\Eclipse_Workspace\STM32F4_projekt_FreeRTOS\STM32F429_FreeRTOS\CMSIS\device" -I"C:\Git_Workspace\Eclipse_Workspace\STM32F4_projekt_FreeRTOS\STM32F429_FreeRTOS\FreeRTOS" -I"C:\Git_Workspace\Eclipse_Workspace\STM32F4_projekt_FreeRTOS\STM32F429_FreeRTOS\FreeRTOS\include" -I"C:\Git_Workspace\Eclipse_Workspace\STM32F4_projekt_FreeRTOS\STM32F429_FreeRTOS\FreeRTOS\portable\GCC\ARM_CM4F" -I"C:\Git_Workspace\Eclipse_Workspace\STM32F4_projekt_FreeRTOS\STM32F429_FreeRTOS\FreeRTOS\portable\MemMang" -I"C:\Git_Workspace\Eclipse_Workspace\STM32F4_projekt_FreeRTOS\STM32F429_FreeRTOS\inc" -I"C:\Git_Workspace\Eclipse_Workspace\STM32F4_projekt_FreeRTOS\STM32F429_FreeRTOS\startup" -I"C:\Git_Workspace\Eclipse_Workspace\STM32F4_projekt_FreeRTOS\STM32F429_FreeRTOS\StdPeriph_Driver\inc" -I"C:\Git_Workspace\Eclipse_Workspace\STM32F4_projekt_FreeRTOS\STM32F429_FreeRTOS\STM32F429I-Discovery" -O0 -g -Wall -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -c -fmessage-length=0 -Wall -ffunction-sections -fdata-sections -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


