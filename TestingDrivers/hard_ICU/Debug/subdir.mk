################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_Program.c \
../GIE_Program.c \
../LCD_Program.c \
../TMR0_Program.c \
../TMR1_Program.c \
../main.c 

OBJS += \
./DIO_Program.o \
./GIE_Program.o \
./LCD_Program.o \
./TMR0_Program.o \
./TMR1_Program.o \
./main.o 

C_DEPS += \
./DIO_Program.d \
./GIE_Program.d \
./LCD_Program.d \
./TMR0_Program.d \
./TMR1_Program.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


