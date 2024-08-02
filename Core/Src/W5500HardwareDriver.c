/*Include: STM Library*/
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_rcc.h"
#include "stm32f1xx_hal_gpio.h"
#include "stm32f1xx_hal_spi.h"
#include "stm32f1xx_hal_exti.h"

/*Include: Header file*/
#include "W5500HardwareDriver.h"

/*Include: W5500 Library*/
#include "wizchip_conf.h"

/*include: Standard IO library*/


//extern led_ctrl led1,led2;
extern wiz_NetInfo gWIZNETINFO;

SPI_HandleTypeDef hspi1;

void W5500HardwareInitilize(void) {

	GPIO_InitTypeDef GPIO_InitStruct = { 0 };

	/* GPIO Ports Clock Enable */
	W5500_GPIO_CLOCK_EN();

	/*Configure GPIO pin : PA3 */
	GPIO_InitStruct.Pin = W5500_INT_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(W5500_INT_PORT, &GPIO_InitStruct);

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET);

	/*Configure GPIO pin : PA2 */
	GPIO_InitStruct.Pin = W5500_RESET_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(W5500_RESET_PORT, &GPIO_InitStruct);

	hspi1.Instance = W5500_SPI;
	hspi1.Init.Mode = SPI_MODE_MASTER;
	hspi1.Init.Direction = SPI_DIRECTION_2LINES;
	hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
	hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
	hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
	hspi1.Init.NSS = SPI_NSS_SOFT;
	hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
	hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
	hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
	hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
	hspi1.Init.CRCPolynomial = 10;
	if (HAL_SPI_Init(&hspi1) != HAL_OK) {
		asm("bkpt 255");
	}

	W5500HardwareReset();
}

void W5500Initialze(void) {
	unsigned char temp;
	unsigned char W5500FifoSize[2][8] = { { 2, 2, 2, 2, 2, 2, 2, 2, }, { 2, 2,
			2, 2, 2, 2, 2, 2 } };

	W5500DeSelect();

	/* spi function register */
	reg_wizchip_spi_cbfunc(W5500ReadByte, W5500WriteByte);

	/* CS function register */
	reg_wizchip_cs_cbfunc(W5500Select, W5500DeSelect);

	if (ctlwizchip(CW_INIT_WIZCHIP, (void*) W5500FifoSize) == -1) {
		asm("bkpt 255");
//		printf("W5500 initialized fail.\r\n");
	}

	do { //check phy status.
		if (ctlwizchip(CW_GET_PHYLINK, (void*) &temp) == -1) {
			asm("bkpt 255");
//			printf("Unknown PHY link status.\r\n");
		}
	} while (temp == PHY_LINK_OFF);

}

void W5500HardwareReset(void) {
	int i, j, k;
	k = 0;
	HAL_GPIO_WritePin(W5500_RESET_PORT, W5500_RESET_PIN, GPIO_PIN_RESET);
	for (i = 0; i < 100; i++) {
		for (j = 0; j < 100; j++) {
			k++;
		}
	}
	HAL_GPIO_WritePin(W5500_RESET_PORT, W5500_RESET_PIN, GPIO_PIN_SET);
}

void W5500WriteByte(unsigned char byte) {

	HAL_SPI_Transmit(&hspi1, (uint8_t*) &byte, 1, 100);
	HAL_SPI_Receive(&hspi1, (uint8_t*) &byte, 1, 100);
}

unsigned char W5500ReadByte(void) {

	unsigned char byte = 0xff;

	HAL_SPI_Transmit(&hspi1, (uint8_t*) &byte, 1, 100);
	HAL_SPI_Receive(&hspi1, (uint8_t*) &byte, 1, 100);

	return byte;
}

void W5500Select(void) {
	HAL_GPIO_WritePin(W5500_CS_PORT, W5500_CS_PIN, GPIO_PIN_RESET);
}

void W5500DeSelect(void) {
	HAL_GPIO_WritePin(W5500_CS_PORT, W5500_CS_PIN, GPIO_PIN_SET);
}

