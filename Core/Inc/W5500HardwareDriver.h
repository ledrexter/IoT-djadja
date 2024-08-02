#ifndef __W5500HARDWAREDRIVER_H_
#define __W5500HARDWAREDRIVER_H_

#define W5500_SPI_CLOCK_SPEED

#define W5500_SPI				SPI1
#define W5500_GPIO_CLOCK_EN()   __HAL_RCC_GPIOA_CLK_ENABLE()

#define W5500_RESET_PORT		GPIOA
#define W5500_RESET_PIN			GPIO_PIN_2

#define W5500_INT_PORT 			GPIOA
#define W5500_INT_PIN			GPIO_PIN_3

#define W5500_CS_PORT			GPIOA
#define W5500_CS_PIN			GPIO_PIN_4

#define W5500_CLK_PORT			GPIOA
#define W5500_CLK_PIN			GPIO_PIN_5

#define W5500_MISO_PORT			GPIOA
#define W5500_MISO_PIN			GPIO_PIN_6

#define W5500_MOSI_PORT			GPIOA
#define W5500_MOSI_PIN			GPIO_PIN_7

void W5500HardwareInitilize(void);
void W5500Initialze(void);
void W5500HardwareReset(void);
void W5500WriteByte(unsigned char byte);
unsigned char W5500ReadByte(void);
void W5500Select(void);
void W5500DeSelect(void);
uint8_t wizchip_read(void);
void  wizchip_write(uint8_t wb);

#endif
