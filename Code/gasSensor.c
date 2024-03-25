#include "stm32f10x.h"
#include "gasSensor.h"

//----------------------------------------Gas Sensor initialisation----------------------------------------
void gasADC_init (void)
{
	// Enable the clocks for ADC, Port A, AFIO
	RCC->APB2ENR |= (RCC_APB2ENR_ADC2EN | RCC_APB2ENR_IOPAEN | RCC_APB2ENR_AFIOEN);
	// Configure PA1 as an analog input; 0000 for Conf and mode
	GPIOA->CRL &= ~GPIO_CRL_MODE1;
	GPIOA->CRL &= ~GPIO_CRL_CNF1;
	// Congiguring PB8 for the Buzzer
	GPIOB->CRH &= ~GPIO_CRH_CNF8 & ~GPIO_CRH_MODE8;
	GPIOB->CRH |= GPIO_CRH_MODE8;
	// Turn on ADC2
	ADC2->CR2 = 0x00000001;
}
//----------------------------------------Function to return ADC value----------------------------------------
int gasADC_acquire(void)
{
	ADC2->SQR3 = (1);
	// Start Conversion
	ADC2->CR2 = 0x00000001;
	// Wait for BOC flag to set
	while(!(ADC2->SR & ADC_SR_EOC)) {};
	
	return ((ADC2->DR & ADC_DR_DATA));
}