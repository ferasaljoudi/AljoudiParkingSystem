#include "stm32f10x.h"
#include "timer.h"

//----------------------------------------Time initialization----------------------------------------
void time_init(void)
{
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	TIM2->CR1 = 0;
	TIM2->PSC = 72 -1;
	TIM2->ARR	= 0xffff - 1;
	TIM2->CR1 |= TIM_CR1_CEN;
	// Wait for the counter to generate its first update event
	while(!(TIM2->SR & TIM_SR_UIF));
}
//----------------------------------------Function for delay_us----------------------------------------
void delay_us(uint16_t delay_time_us)
{
	TIM2->CNT = 0;
	while (TIM2->CNT <= delay_time_us)
	{}
}
//----------------------------------------Function for delay_ms----------------------------------------
void delay_ms(uint16_t delay_time_ms)
{
	for (uint16_t i=0; i<delay_time_ms; i++)
	{
		delay_us (1000);
	}
}
