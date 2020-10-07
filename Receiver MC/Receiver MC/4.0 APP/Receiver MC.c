/*
 * Receiver_MC.c
 *
 * Created: 9/8/2020 7:50:09 PM
 *  Author: mahmoud
 */ 


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "LCD.h"

#include "Motor.h"


 uint8_t duty;
 uint8_t buffer[20];
 
int main()
{	
	LCD_init();
    LCD_sendCommand(0x01);
   Motor  MotorObject;
    
 Str_TimerConfiguration_t timer={0,8,FastPWM,POLLING};
	  MotorObject.timer=timer;


    Motor_Intial(&MotorObject);

   duty=(TIMER0_OCR0*100/255)+1;

   itoa(duty,buffer,10);
 
	LCD_displayString (buffer);
	





while(1)
	{ 
		 
			duty=Motor_Operate();
		
			LCD_sendCommand(0x01);
			
			itoa(duty,buffer,10);

			LCD_displayString (buffer);	
	 }
		    
return 0;



}