################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/fonts.c \
../src/main.c \
../src/syscalls.c \
../src/system_stm32f4xx.c \
../src/tm_stm32f4_disco.c \
../src/tm_stm32f4_gpio.c 

OBJS += \
./src/fonts.o \
./src/main.o \
./src/syscalls.o \
./src/system_stm32f4xx.o \
./src/tm_stm32f4_disco.o \
./src/tm_stm32f4_gpio.o 

C_DEPS += \
./src/fonts.d \
./src/main.d \
./src/syscalls.d \
./src/system_stm32f4xx.d \
./src/tm_stm32f4_disco.d \
./src/tm_stm32f4_gpio.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-none-eabi-gcc -DDEBUG -DSTM32F4 -DSTM32 -DSTM32F429_439xx -DSTM32F429I_DISC1 -DSTM32F429ZITx -DUSE_STDPERIPH_DRIVER -I"C:\Git_Workspace\Eclipse_Workspace\STM32F4_projekt_FreeRTOS\STM32F429_FreeRTOS\CMSIS\core" -I"C:\Git_Workspace\Eclipse_Workspace\STM32F4_projekt_FreeRTOS\STM32F429_FreeRTOS\CMSIS\device" -I"C:\Git_Workspace\Eclipse_Workspace\STM32F4_projekt_FreeRTOS\STM32F429_FreeRTOS\FreeRTOS" -I"C:\Git_Workspace\Eclipse_Workspace\STM32F4_projekt_FreeRTOS\STM32F429_FreeRTOS\FreeRTOS\include" -I"C:\Git_Workspace\Eclipse_Workspace\STM32F4_projekt_FreeRTOS\STM32F429_FreeRTOS\FreeRTOS\portable\GCC\ARM_CM4F" -I"C:\Git_Workspace\Eclipse_Workspace\STM32F4_projekt_FreeRTOS\STM32F429_FreeRTOS\FreeRTOS\portable\MemMang" -I"C:\Git_Workspace\Eclipse_Workspace\STM32F4_projekt_FreeRTOS\STM32F429_FreeRTOS\inc" -I"C:\Git_Workspace\Eclipse_Workspace\STM32F4_projekt_FreeRTOS\STM32F429_FreeRTOS\startup" -I"C:\Git_Workspace\Eclipse_Workspace\STM32F4_projekt_FreeRTOS\STM32F429_FreeRTOS\StdPeriph_Driver\inc" -I"C:\Git_Workspace\Eclipse_Workspace\STM32F4_projekt_FreeRTOS\STM32F429_FreeRTOS\STM32F429I-Discovery" -O0 -g -Wall -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -c -fmessage-length=0 -Wall -ffunction-sections -fdata-sections -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


