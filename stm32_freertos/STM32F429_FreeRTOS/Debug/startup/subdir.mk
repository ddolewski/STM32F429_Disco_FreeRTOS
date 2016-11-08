################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS += \
../startup/startup_stm32f429_439xx.S 

OBJS += \
./startup/startup_stm32f429_439xx.o 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Assembler'
	arm-none-eabi-as -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -I"C:\Git_Workspace\Eclipse_Workspace\STM32F4_projekt_FreeRTOS\STM32F429_FreeRTOS\CMSIS\core" -I"C:\Git_Workspace\Eclipse_Workspace\STM32F4_projekt_FreeRTOS\STM32F429_FreeRTOS\CMSIS\device" -I"C:\Git_Workspace\Eclipse_Workspace\STM32F4_projekt_FreeRTOS\STM32F429_FreeRTOS\FreeRTOS" -I"C:\Git_Workspace\Eclipse_Workspace\STM32F4_projekt_FreeRTOS\STM32F429_FreeRTOS\FreeRTOS\include" -I"C:\Git_Workspace\Eclipse_Workspace\STM32F4_projekt_FreeRTOS\STM32F429_FreeRTOS\FreeRTOS\portable\GCC\ARM_CM4F" -I"C:\Git_Workspace\Eclipse_Workspace\STM32F4_projekt_FreeRTOS\STM32F429_FreeRTOS\FreeRTOS\portable\MemMang" -I"C:\Git_Workspace\Eclipse_Workspace\STM32F4_projekt_FreeRTOS\STM32F429_FreeRTOS\inc" -I"C:\Git_Workspace\Eclipse_Workspace\STM32F4_projekt_FreeRTOS\STM32F429_FreeRTOS\startup" -I"C:\Git_Workspace\Eclipse_Workspace\STM32F4_projekt_FreeRTOS\STM32F429_FreeRTOS\StdPeriph_Driver\inc" -I"C:\Git_Workspace\Eclipse_Workspace\STM32F4_projekt_FreeRTOS\STM32F429_FreeRTOS\STM32F429I-Discovery" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


