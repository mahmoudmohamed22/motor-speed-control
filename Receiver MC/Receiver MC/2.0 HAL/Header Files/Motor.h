/*
 * Motor.h
 *
 * Created: 9/6/2020 7:34:49 PM
 *  Author: mahmoud
 */ 


#ifndef MOTOR_H_
#define MOTOR_H_


#include "GPIO.h"
#include "Timers.h"
#include "UART_Init.h"


uint8_t x;
typedef struct {

Str_TimerConfiguration_t timer;

}Motor;

void Motor_Intial(Motor *Motor);
uint8_t Motor_Operate(void);

void error_Motor(void);




#endif /* MOTOR_H_ */