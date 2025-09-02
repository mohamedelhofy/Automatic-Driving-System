################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../system/HAL/Keypad_Program.c \
../system/HAL/LCD_Program.c \
../system/HAL/SWCH_Program.c \
../system/HAL/Stepper_program.c 

OBJS += \
./system/HAL/Keypad_Program.o \
./system/HAL/LCD_Program.o \
./system/HAL/SWCH_Program.o \
./system/HAL/Stepper_program.o 

C_DEPS += \
./system/HAL/Keypad_Program.d \
./system/HAL/LCD_Program.d \
./system/HAL/SWCH_Program.d \
./system/HAL/Stepper_program.d 


# Each subdirectory must supply rules for building sources it contributes
system/HAL/%.o: ../system/HAL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


