#include "stm32f10x.h"
#include "LCD.h"

//----------------------------------------LCD initialization----------------------------------------
void LCD_init(void)
{
	// Turn on the clocks for Port B and Port C
	RCC->APB2ENR |= (RCC_APB2ENR_IOPBEN | RCC_APB2ENR_IOPCEN);

	// Congiguring PB0
	GPIOB->CRL |= GPIO_CRL_MODE0;
	GPIOB->CRL &= ~GPIO_CRL_CNF0;
	// Congiguring PB1
	GPIOB->CRL |= GPIO_CRL_MODE1;
	GPIOB->CRL &= ~GPIO_CRL_CNF1;
	// Congiguring PC0
	GPIOC->CRL |= GPIO_CRL_MODE0;
	GPIOC->CRL &= ~GPIO_CRL_CNF0;
	// Congiguring PC1
	GPIOC->CRL |= GPIO_CRL_MODE1;
	GPIOC->CRL &= ~GPIO_CRL_CNF1;
	// Congiguring PC2
	GPIOC->CRL |= GPIO_CRL_MODE2;
	GPIOC->CRL &= ~GPIO_CRL_CNF2;
	// Congiguring PC3
	GPIOC->CRL |= GPIO_CRL_MODE3;
	GPIOC->CRL &= ~GPIO_CRL_CNF3;
	// Congiguring PC4
	GPIOC->CRL |= GPIO_CRL_MODE4;
	GPIOC->CRL &= ~GPIO_CRL_CNF4;
	// Congiguring PC5
	GPIOC->CRL |= GPIO_CRL_MODE5;
	GPIOC->CRL &= ~GPIO_CRL_CNF5;
	// Congiguring PC6
	GPIOC->CRL |= GPIO_CRL_MODE6;
	GPIOC->CRL &= ~GPIO_CRL_CNF6;
	// Congiguring PC7
	GPIOC->CRL |= GPIO_CRL_MODE7;
	GPIOC->CRL &= ~GPIO_CRL_CNF7;
	
	// LCD initialization
	LCD_sendCommand(LCD_Data);
	LCD_sendCommand(LCD_DisON_CurOFF);
	LCD_sendCommand(LCD_ShiftCursorR);
	LCD_sendCommand(LCD_Clear);
}
//----------------------------------------Sending Commands----------------------------------------
void LCD_sendCommand(uint8_t data)
{
	// Reset RS and set E
	GPIOB->BSRR = resetRS_setE;
	GPIOC->ODR &= 0xFF00;
	GPIOC->ODR |= data;
	delay_ms(20);
	// Reset RS and E
	GPIOB->BSRR = reset_RS_E;
	delay_ms(20);
}
//----------------------------------------Sending Data----------------------------------------
void LCD_sendData(uint8_t data)
{
	// Set RS and E
	GPIOB->BSRR = set_RS_E;
	GPIOC->ODR &= 0xFF00;
	GPIOC->ODR |= data;
	delay_ms(20);
	// Set RS and reset E
	GPIOB->BSRR = setRS_resetE;
	delay_ms(20);
}
//----------------------------------------Sending String----------------------------------------
void LCD_sendString(char *message)
{
	uint16_t strLen = strlen(message);
	for (int i = 0; i < strLen; ++i)
	{
		LCD_sendData(message[i]);
	}
}
//----------------------------------------Sending Integer----------------------------------------
void LCD_sendInteger(int count)
{
	char buffer[3];
	sprintf(buffer, "%d", count);
	LCD_sendString(buffer);
}
//----------------------------------------Clear LCD----------------------------------------
void clearLCD()
{
	LCD_sendCommand(LCD_Clear);
}
