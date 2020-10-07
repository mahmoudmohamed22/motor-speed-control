/*
 * Motor.c
 *
 * Created: 9/6/2020 7:35:04 PM
 *  Author: mahmo
 */ 
#include "Motor.h"


void Motor_Intial(Motor *Motor)
{
	USART_voidInit();
	Timer_Init(&Motor->timer);
	Timer_Start( 0,5);
	TIMER0_void_COMM();
	TIMER0_void_OCR0(127);
}

uint8_t  Motor_Operate(void)
{
	TIMER0_OCR0=USART_uint8_tReceive();
	
	x=(TIMER0_OCR0*100/255);
	if(x%2!=0)
	{
		x+=1;
	}
	return x;
}
void error_Motor(void)
{
	
}
