#include "stm32f10x.h"
#include "operation.h"
#include "timer.h"
#include "LCD.h"
#include "servo.h"
#include "gasSensor.h"
#include "pressureSensor.h"

// Setting the number of available spots to 4
#define AvailableSpots 4

//----------------------------------------Main Function----------------------------------------
int main(void)
{
	// System clock to 72 MHz
	SystemInit();
	// Timer Initializing
	time_init();
	// LCD initialization
	LCD_init();
	// Servos initialization
	servo_init();
  pwm_init();
	// Pressure Sensor initialization
	pressureADC_init();
	// Gas Sensor initialization
	gasADC_init();
	
	int readPressure = 0;
	int readGas = 0;
	int carsCount = 0;

	updateServoAngle(21, 2);
	
	welcomeMessage();
	displaySpots(AvailableSpots, carsCount);

	while(1)
	{
		readPressure = pressureADC_acquire();
		if(readPressure >= 0x888)
		{
			carsCount = enteranceDoor(AvailableSpots, carsCount);
			displaySpots(AvailableSpots, carsCount);
		}
		readGas = gasADC_acquire();
		if(readGas > 0xCFF)
		{
			fireAlarm(readGas);
			displaySpots(AvailableSpots, carsCount);
		}
		if((GPIOB->IDR & (1 << 9)) == 0)
		{
			carsCount = exitDoor(carsCount);
			displaySpots(AvailableSpots, carsCount);
		}
	}
}
