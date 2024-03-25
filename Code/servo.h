#include "stm32f10x.h"

void servo_init(void);
void pwm_init(void);
float convertAngle(uint16_t);
void updateServoAngle(int, uint8_t);