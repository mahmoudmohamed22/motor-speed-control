/*
 * GPIO.c
 *
 * Created: 8/31/2020 12:33:36 PM
 *  Author: mahmoud 
 */ 
#include "GPIO.h"




void DIO_Init_PORT(DIO_Configure *DIO ,Mode mode ){
	vuint8_t pinCount =0;
	for(pinCount=0;pinCount<PinsMAX;pinCount++){
		switch(mode){
			case InputFloat:
			ClearBit(DIO->port.Fullbits,pinCount);
			ClearBit(DIO->DDR.Fullbits,pinCount);
			break;
			case InputPullup:
			SeTBit(DIO->port.Fullbits,pinCount);
			ClearBit(DIO->DDR.Fullbits,pinCount);
			break;
			case Output:
			SeTBit(DIO->DDR.Fullbits,pinCount);
			ClearBit(DIO->port.Fullbits,pinCount);
			break;
			default:
			/*function error*/
			break;
			}
	}
	
}

void DIO_Init_PIN(DIO_Configure *DIO,pinNumber pinNum ,Mode mode){//DIO_Init_PIN(PINB,num,mode output);
	switch(mode){
		case InputFloat:
		ClearBit(DIO->port.Fullbits,pinNum);
		ClearBit(DIO->DDR.Fullbits,pinNum);
		break;
		case InputPullup:
		SeTBit(DIO->port.Fullbits,pinNum);
		ClearBit(DIO->DDR.Fullbits,pinNum);
		break;
		case Output:
		SeTBit(DIO->DDR.Fullbits,pinNum);
		ClearBit(DIO->port.Fullbits,pinNum);
        break;
		default:
		/*function error*/
		break;
	}
	
}
	/*	void DIO_Init_PIN(pinNumber pinNum ,Mode mode){
			
			
		}*/


void	DIO_SetPortValue(DIO_Configure * DIO,vuint8_t portValue){
	
	DIO->port.Fullbits=portValue;
}
vuint8_t	DIO_GetPortValue(DIO_Configure *DIO){
	return DIO->PIN.Fullbits;
}
void DIO_SetPinValue(DIO_Configure *DIO,pinNumber PinNum,digitalState state ){
	if(PinNum >7 || PinNum<0){
		/*error function */
	}
	switch(state){
		case HIGH:
		SeTBit(DIO->port.Fullbits,PinNum);
		break;
		case LOW:
		ClearBit(DIO->port.Fullbits,PinNum);
		
		break;
		default:
		/*error function*/
		break;
	}
	
}
digitalState DIO_GetPinValue(DIO_Configure *DIO,pinNumber PinNum){
	if(PinNum >7  || PinNum <0){
		/*error function */
	}
	digitalState State=LOW ;
	switch(ReadBit(DIO->PIN.Fullbits,PinNum)){
		case 0:
		State=LOW;
		break;
		case 1:
		State=HIGH;
		break;
		default:
		/*function  error */
		break;
	}
	return State;
}

void ERROR_DIO(){
	
}