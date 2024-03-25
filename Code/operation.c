#include "stm32f10x.h"
#include "operation.h"
#include "LCD.h"

//----------------------------------------Welcome Message----------------------------------------
void welcomeMessage()
{
	LCD_sendString("Feras");
	LCD_sendCommand(LCD_Line2);
	LCD_sendString("Welcome");
	LCD_sendCommand(LCD_Line1_13);
	LCD_sendString(";)");
	delay_ms(3000);
	LCD_sendCommand(LCD_Clear);
}
//----------------------------------------Display the number of spots----------------------------------------
void displaySpots(int spots, int carsCount)
{
	clearLCD();
	LCD_sendString("Available spots:");
	LCD_sendCommand(LCD_Line2);
	int count = spots - carsCount;
	LCD_sendInteger(count);
}
//----------------------------------------Fire Alarm Function----------------------------------------
void fireAlarm(int readGas)
{
	uint32_t clearbitB8 = 0xFFFFFEFF;
	clearLCD();
	while(readGas >= 0xBFF)
	{
		GPIOB->ODR |= (1 << 8);
		LCD_sendCommand(LCD_Line1_3);
		LCD_sendString("Fire Alarm");
		delay_ms(300);
		GPIOB->ODR &= clearbitB8;
		delay_ms(300);
		readGas = gasADC_acquire();
		clearLCD();
	}
}
//----------------------------------------Enterance Door Function----------------------------------------
int enteranceDoor(int spots, int carsCount)
{
	int readPressure = 0;
	int i = 0;
	clearLCD();
	LCD_sendString("...");
	delay_ms(1800);
	// Taking the average of 20 readings
	while(i < 20)
	{
		readPressure += pressureADC_acquire();
		i++;
	}
	readPressure = readPressure / 20;
	clearLCD();
	// Check if there is a spot
	if(spots == carsCount)
	{
		LCD_sendString("Sorry...");
		LCD_sendCommand(LCD_Line2);
		LCD_sendString("There's no spots");
		delay_ms(3000);
		clearLCD();
		return carsCount;
	}else
	{
		// Check if it is heavy vehicle
		if(readPressure >= 0xC12)
		{
			LCD_sendString("Heavy Vehicle");
			LCD_sendCommand(LCD_Line2);
			LCD_sendString("$3 per hour");
			delay_ms(3000);
			clearLCD();
			LCD_sendString("Go...");
			updateServoAngle(0, 1);
			delay_ms(4000);
			clearLCD();
			updateServoAngle(90, 1);
			carsCount++;
		}
		// Else if it is light vehicle
		else if (readPressure >= 0x888)
		{
			LCD_sendString("Light Vehicle");
			LCD_sendCommand(LCD_Line2);
			LCD_sendString("$2 per hour");
			delay_ms(3000);
			clearLCD();
			LCD_sendString("Go...");
			updateServoAngle(0, 1);
			delay_ms(3000);
			clearLCD();
			updateServoAngle(90, 1);
			carsCount++;
		}	
		return carsCount;
	}
}
//----------------------------------------Exit Door Function----------------------------------------
int exitDoor(int carsCount)
{
	delay_ms(1000);
	updateServoAngle(90, 2);
	// While the car is present
	while((GPIOB->IDR & (1 << 9)) == 0){}
	delay_ms(2000);
	updateServoAngle(21, 2);
	carsCount--;
	return carsCount;
}