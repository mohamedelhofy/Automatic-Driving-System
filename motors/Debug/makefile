################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/subdir.mk
-include HAL/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
motors.lss \

FLASH_IMAGE += \
motors.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: motors.elf secondary-outputs

# Tool invocations
motors.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,motors.map -mmcu=atmega32 -o "motors.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

motors.lss: motors.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S motors.elf  >"motors.lss"
	@echo 'Finished building: $@'
	@echo ' '

motors.hex: motors.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex motors.elf  "motors.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: motors.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 motors.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: motors.elf
	@echo 'Invoking: AVRDude'
	D:\ITI_ARM\02-ARM Tools\03- IMT SDK\IMT_SDK_Win_64\WinAVR\bin\avrdude -pm32 -cusbasp -Uflash:w:motors.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) motors.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
