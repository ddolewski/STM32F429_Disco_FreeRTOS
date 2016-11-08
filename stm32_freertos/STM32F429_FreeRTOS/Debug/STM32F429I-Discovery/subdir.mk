################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32F429I-Discovery/stm32f429i_discovery.c \
../STM32F429I-Discovery/stm32f429i_discovery_i2c_ee.c \
../STM32F429I-Discovery/stm32f429i_discovery_ioe.c \
../STM32F429I-Discovery/stm32f429i_discovery_l3gd20.c \
../STM32F429I-Discovery/stm32f429i_discovery_lcd.c \
../STM32F429I-Discovery/stm32f429i_discovery_sdram.c 

OBJS += \
./STM32F429I-Discovery/stm32f429i_discovery.o \
./STM32F429I-Discovery/stm32f429i_discovery_i2c_ee.o \
./STM32F429I-Discovery/stm32f429i_discovery_ioe.o \
./STM32F429I-Discovery/stm32f429i_discovery_l3gd20.o \
./STM32F429I-Discovery/stm32f429i_discovery_lcd.o \
./STM32F429I-Discovery/stm32f429i_discovery_sdram.o 

C_DEPS += \
./STM32F429I-Discovery/stm32f429i_discovery.d \
./STM32F429I-Discovery/stm32f429i_discovery_i2c_ee.d \
./STM32F429I-Discovery/stm32f429i_discovery_ioe.d \
./STM32F429I-Discovery/stm32f429i_discovery_l3gd20.d \
./STM32F429I-Discovery/stm32f429i_discovery_lcd.d \
./STM32F429I-Discovery/stm32f429i_discovery_sdram.d 


# Each subdirectory must supply rules for building sources it contributes
STM32F429I-Discovery/%.o: ../STM32F429I-Discovery/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-none-eabi-gcc -DDEBUG -DSTM32F4 -DSTM32 -DSTM32F429_439xx -DSTM32F429I_DISC1 -DSTM32F429ZITx -DUSE_STDPERIPH_DRIVER -I"C:\Git_Workspace\Eclipse_Workspace\STM32F4_projekt_FreeRTOS\STM32F429_FreeRTOS\CMSIS\core" -I"C:\Git_Workspace\Eclipse_Workspace\STM32F4_projekt_FreeRTOS\STM32F429_FreeRTOS\CMSIS\device" -I"C:\Git_Workspace\Eclipse_Workspace\STM32F4_projekt_FreeRTOS\STM32F429_FreeRTOS\FreeRTOS" -I"C:\Git_Workspace\Eclipse_Workspace\STM32F4_projekt_FreeRTOS\STM32F429_FreeRTOS\FreeRTOS\include" -I"C:\Git_Workspace\Eclipse_Workspace\STM32F4_projekt_FreeRTOS\STM32F429_FreeRTOS\FreeRTOS\portable\GCC\ARM_CM4F" -I"C:\Git_Workspace\Eclipse_Workspace\STM32F4_projekt_FreeRTOS\STM32F429_FreeRTOS\FreeRTOS\portable\MemMang" -I"C:\Git_Workspace\Eclipse_Workspace\STM32F4_projekt_FreeRTOS\STM32F429_FreeRTOS\inc" -I"C:\Git_Workspace\Eclipse_Workspace\STM32F4_projekt_FreeRTOS\STM32F429_FreeRTOS\startup" -I"C:\Git_Workspace\Eclipse_Workspace\STM32F4_projekt_FreeRTOS\STM32F429_FreeRTOS\StdPeriph_Driver\inc" -I"C:\Git_Workspace\Eclipse_Workspace\STM32F4_projekt_FreeRTOS\STM32F429_FreeRTOS\STM32F429I-Discovery" -O0 -g -Wall -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -c -fmessage-length=0 -Wall -ffunction-sections -fdata-sections -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


