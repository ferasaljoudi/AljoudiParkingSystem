#include "stm32f10x.h"
#include "servo.h"

//----------------------------------------Servo initialisation----------------------------------------
void servo_init(void){           
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_AFIOEN;
	
	// Configure PA6 and PA7 as AFIO; 1011 for conf and mode
	GPIOA->CRL |= GPIO_CRL_CNF6_1 | GPIO_CRL_MODE6_1 | GPIO_CRL_MODE6_0;
	GPIOA->CRL &= ~GPIO_CRL_CNF6_0;
  
	GPIOA->CRL |= GPIO_CRL_CNF7_1 | GPIO_CRL_MODE7_1 | GPIO_CRL_MODE7_0;
	GPIOA->CRL &= ~GPIO_CRL_CNF7_0;
}
//----------------------------------------PWM initialisation----------------------------------------
void pwm_init(void)
{
	// Turn on Timer 3
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	TIM3->CR1 = 0;
	TIM3->CR1 |= TIM_CR1_ARPE;

	// PWM mode 1, preload enable and fast enable for CH1
	TIM3->CCMR1 |= TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1;
	TIM3->CCMR1 |= TIM_CCMR1_OC1PE | TIM_CCMR1_OC1FE;
	// PWM mode 1, preload enable and fast enable for CH2
	TIM3->CCMR1 |= TIM_CCMR1_OC2M_2 | TIM_CCMR1_OC2M_1;
	TIM3->CCMR1 |= TIM_CCMR1_OC2PE | TIM_CCMR1_OC2FE;
	
	// Enable CH1 and CH2
	TIM3->CCER |= TIM_CCER_CC1E;
	TIM3->CCER |= TIM_CCER_CC2E;
	
	TIM3->PSC = 720 - 1;
	// Set # of counts, period is 20mS
	TIM3->ARR = 2000;
	// Set # of counts/pulse width for CH1 and CH2, duty cycle is 7.5%
	TIM3->CCR1 = 150;
	TIM3->CCR2 = 150;
	
	TIM3->EGR |= TIM_EGR_UG;
	TIM3->CR1 |= TIM_CR1_CEN;
}
//----------------------------------------Function to convert the angle----------------------------------------
float convertAngle(uint16_t angle)
{
	float converted;
	converted = (angle * 1.11111111111) + 50;
		
	return converted;
}
//----------------------------------------Function to update the angle----------------------------------------
void updateServoAngle(int angle, uint8_t channel)
{
	if (channel == 1)
	{
		TIM3->CCR1 = convertAngle(angle);
  }else if (channel == 2)
	{
		TIM3->CCR2 = convertAngle(angle);
  }
	TIM3->EGR |= TIM_EGR_UG;
	delay_ms(500);
}