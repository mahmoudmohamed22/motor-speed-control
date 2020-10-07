/*
 * Transmitter_Mc.c
 *
 * Created: 9/8/2020 7:07:26 PM
 *  Author: mahmoud
 */ 


#include "PushButton.h"
#include "External_Interrupt.h"

#define MaxNumSpeed 10
#define MinNumSpeed  0

static  uint8_t	  Speed_arr[11]={0,25,51,76,102,127,153,178,204,229,255};
static int8_t index=5;

pushButtonProject button1={PIND,PIN2,HIGH,INT0,FALLING_EDGE };
pushButtonProject button2={PIND,PIN3,HIGH,INT1,FALLING_EDGE };

void Speed_up();
void Slow_down();

int main(void)
{
	USART_voidInit();

	
	
	Button_intial_ExtInterrupt(&button1);
	Button_intial_ExtInterrupt(&button2);
	
	
	SetCallBackFunction(INT0 ,Speed_up);
	SetCallBackFunction(INT1 ,Slow_down);
	
	while(1)
	{

	}
	
}
void Speed_up(){
	
	if(GetValue_ExtPushButton(&button1)==LOW)
	{
		index++;

		if(index >MaxNumSpeed)		index=MaxNumSpeed;		
		USART_voidTransmit(Speed_arr[index]);
		
	}

}

void Slow_down(){
	
	if(GetValue_ExtPushButton(&button2)==LOW)
	{
		index--;
		if(index<MinNumSpeed)		index=MinNumSpeed;
		USART_voidTransmit(Speed_arr[index]);
		
	}

}