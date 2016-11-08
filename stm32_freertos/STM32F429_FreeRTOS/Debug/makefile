################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include startup/subdir.mk
-include src/subdir.mk
-include StdPeriph_Driver/src/subdir.mk
-include STM32F429I-Discovery/subdir.mk
-include FreeRTOS/portable/MemMang/subdir.mk
-include FreeRTOS/portable/GCC/ARM_CM4F/subdir.mk
-include FreeRTOS/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: STM32F429_FreeRTOS.elf

# Tool invocations
STM32F429_FreeRTOS.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross GCC Linker'
	arm-none-eabi-gcc -T"C:\Git_Workspace\Eclipse_Workspace\STM32F4_projekt_FreeRTOS\STM32F429_FreeRTOS\stm32f429zi_flash.ld" -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Wl,-Map=output.map -Wl,--gc-sections -lm -o "STM32F429_FreeRTOS.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) STM32F429_FreeRTOS.elf
	-@echo ' '

post-build:
	-@echo 'Generating binary and Printing size information:'
	-arm-none-eabi-objcopy -O binary "STM32F429_FreeRTOS.elf" "STM32F429_FreeRTOS.bin"&arm-none-eabi-objcopy -O ihex "STM32F429_FreeRTOS.elf" "STM32F429_FreeRTOS.hex"&arm-none-eabi-size STM32F429_FreeRTOS.elf
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
