#include "stm32f10x.h"
#include "pressureSensor.h"

//----------------------------------------Pressure Sensor initialisation----------------------------------------
void pressureADC_init (void)
{
	// Enable the clocks for ADC, Port A, AFIO
	RCC->APB2ENR |= (RCC_APB2ENR_ADC1EN | RCC_APB2ENR_IOPAEN | RCC_APB2ENR_AFIOEN);
	// Configure PAO as an analog input; 0000 for Conf and mode
	GPIOA->CRL &= ~GPIO_CRL_MODE0;
	GPIOA->CRL &= ~GPIO_CRL_CNF0;
	// Turn on ADC1
	ADC1->CR2 = 0x00000001;
}
//----------------------------------------Function to return ADC value----------------------------------------
int pressureADC_acquire(void)
{
	ADC1->SQR3 = (0);
	// Start Conversion
	ADC1->CR2 = 0x00000001;
	// Wait for BOC flag to set
	while(!(ADC1->SR & ADC_SR_EOC)) {};
	
	return ((ADC1->DR & ADC_DR_DATA));
}