################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
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
ICU_Software.lss \

FLASH_IMAGE += \
ICU_Software.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: ICU_Software.elf secondary-outputs

# Tool invocations
ICU_Software.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,ICU_Software.map -mmcu=atmega32 -o "ICU_Software.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ICU_Software.lss: ICU_Software.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S ICU_Software.elf  >"ICU_Software.lss"
	@echo 'Finished building: $@'
	@echo ' '

ICU_Software.hex: ICU_Software.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex ICU_Software.elf  "ICU_Software.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: ICU_Software.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 ICU_Software.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) ICU_Software.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
