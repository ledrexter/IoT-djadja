################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/ioLibrary_Driver/Internet/DNS/dns.c 

OBJS += \
./Drivers/ioLibrary_Driver/Internet/DNS/dns.o 

C_DEPS += \
./Drivers/ioLibrary_Driver/Internet/DNS/dns.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/ioLibrary_Driver/Internet/DNS/%.o Drivers/ioLibrary_Driver/Internet/DNS/%.su: ../Drivers/ioLibrary_Driver/Internet/DNS/%.c Drivers/ioLibrary_Driver/Internet/DNS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I"/home/radoslav/STM32CubeIDE/workspace_1.10.1/IoT-djadja/Drivers/ioLibrary_Driver/Ethernet" -I"/home/radoslav/STM32CubeIDE/workspace_1.10.1/IoT-djadja/Drivers/ioLibrary_Driver/Internet" -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-ioLibrary_Driver-2f-Internet-2f-DNS

clean-Drivers-2f-ioLibrary_Driver-2f-Internet-2f-DNS:
	-$(RM) ./Drivers/ioLibrary_Driver/Internet/DNS/dns.d ./Drivers/ioLibrary_Driver/Internet/DNS/dns.o ./Drivers/ioLibrary_Driver/Internet/DNS/dns.su

.PHONY: clean-Drivers-2f-ioLibrary_Driver-2f-Internet-2f-DNS

