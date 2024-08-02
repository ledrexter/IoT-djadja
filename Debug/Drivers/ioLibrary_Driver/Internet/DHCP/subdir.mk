################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/ioLibrary_Driver/Internet/DHCP/dhcp.c 

OBJS += \
./Drivers/ioLibrary_Driver/Internet/DHCP/dhcp.o 

C_DEPS += \
./Drivers/ioLibrary_Driver/Internet/DHCP/dhcp.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/ioLibrary_Driver/Internet/DHCP/%.o Drivers/ioLibrary_Driver/Internet/DHCP/%.su: ../Drivers/ioLibrary_Driver/Internet/DHCP/%.c Drivers/ioLibrary_Driver/Internet/DHCP/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I"/home/radoslav/STM32CubeIDE/workspace_1.10.1/IoT-djadja/Drivers/ioLibrary_Driver/Ethernet" -I"/home/radoslav/STM32CubeIDE/workspace_1.10.1/IoT-djadja/Drivers/ioLibrary_Driver/Internet" -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-ioLibrary_Driver-2f-Internet-2f-DHCP

clean-Drivers-2f-ioLibrary_Driver-2f-Internet-2f-DHCP:
	-$(RM) ./Drivers/ioLibrary_Driver/Internet/DHCP/dhcp.d ./Drivers/ioLibrary_Driver/Internet/DHCP/dhcp.o ./Drivers/ioLibrary_Driver/Internet/DHCP/dhcp.su

.PHONY: clean-Drivers-2f-ioLibrary_Driver-2f-Internet-2f-DHCP

