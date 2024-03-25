#include "stm32f10x.h"

//----------------------------------------LCD Declaration----------------------------------------
#define LCD_Data 0x38 // 8-bit, 2 lines, 5x7 dots
#define LCD_DisON_CurOFF 0x0C // Display on, cursor off
#define LCD_ShiftCursorR 0x06 // Increment cursor (shift cursor to right)
#define LCD_Line1_3 0X83 // Force cursor to the beginning of 3rd position on line 1
#define LCD_Line1_13 0X8C // Force cursor to the beginning of 13th position on line 1
#define LCD_Line2 0XC0 // Force cursor to the beginning (2nd line)
#define LCD_Clear 0X01 // Clear display screen
#define resetRS_setE 0X00010002 // Reset RS and set E
#define reset_RS_E 0x00030000 // Reset RS and E
#define set_RS_E 0x00000003 // Set RS and E
#define setRS_resetE 0x00020001 // Set RS and reset E

void LCD_init(void);
void LCD_sendCommand(uint8_t);
void LCD_sendData(uint8_t);
void LCD_sendString(char *);
void LCD_sendInteger(int);
void clearLCD(void);
