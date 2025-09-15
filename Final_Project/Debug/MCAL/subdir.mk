################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/ADC_Program.c \
../MCAL/DIO_Program.c \
../MCAL/EXT_IN_Program.c \
../MCAL/GIE_Program.c \
../MCAL/Timer0_Program.c \
../MCAL/Timer1_Program.c 

OBJS += \
./MCAL/ADC_Program.o \
./MCAL/DIO_Program.o \
./MCAL/EXT_IN_Program.o \
./MCAL/GIE_Program.o \
./MCAL/Timer0_Program.o \
./MCAL/Timer1_Program.o 

C_DEPS += \
./MCAL/ADC_Program.d \
./MCAL/DIO_Program.d \
./MCAL/EXT_IN_Program.d \
./MCAL/GIE_Program.d \
./MCAL/Timer0_Program.d \
./MCAL/Timer1_Program.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/%.o: ../MCAL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O2 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


