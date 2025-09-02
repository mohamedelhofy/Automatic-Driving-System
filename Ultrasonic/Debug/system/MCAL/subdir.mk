################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../system/MCAL/ADC_Program.c \
../system/MCAL/DIO_Program.c \
../system/MCAL/EXT_IN_Program.c \
../system/MCAL/GIE_Program.c 

OBJS += \
./system/MCAL/ADC_Program.o \
./system/MCAL/DIO_Program.o \
./system/MCAL/EXT_IN_Program.o \
./system/MCAL/GIE_Program.o 

C_DEPS += \
./system/MCAL/ADC_Program.d \
./system/MCAL/DIO_Program.d \
./system/MCAL/EXT_IN_Program.d \
./system/MCAL/GIE_Program.d 


# Each subdirectory must supply rules for building sources it contributes
system/MCAL/%.o: ../system/MCAL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


