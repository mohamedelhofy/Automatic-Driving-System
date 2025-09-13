################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Keypad_Program.c \
../HAL/L298_Prog.c \
../HAL/LCD_Program.c \
../HAL/SERVO_Prog.c \
../HAL/SWCH_Program.c \
../HAL/Stepper_program.c \
../HAL/Ultrasonic_Program.c 

OBJS += \
./HAL/Keypad_Program.o \
./HAL/L298_Prog.o \
./HAL/LCD_Program.o \
./HAL/SERVO_Prog.o \
./HAL/SWCH_Program.o \
./HAL/Stepper_program.o \
./HAL/Ultrasonic_Program.o 

C_DEPS += \
./HAL/Keypad_Program.d \
./HAL/L298_Prog.d \
./HAL/LCD_Program.d \
./HAL/SERVO_Prog.d \
./HAL/SWCH_Program.d \
./HAL/Stepper_program.d \
./HAL/Ultrasonic_Program.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/%.o: ../HAL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O2 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


