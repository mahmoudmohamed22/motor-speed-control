/*
 * PushButton.c
 *
 * Created: 9/6/2020 7:33:27 PM
 *  Author: mahmo
 */ 
#include "PushButton.h"

void Button_intial(PushButton *button)
{
	if (button!=NULL)
	{
		switch(button->ButtonMode)
		{
			case InputFloat:
			DIO_Init_PIN(button->Button_DIO,button->pinButton,InputFloat);
			break;
			case InputPullup:
			DIO_Init_PIN(button->Button_DIO,button->pinButton,InputPullup);
		    break;
			default:
			error_button();
			break;

		}
	    	button->Prev_StateButton=DIO_GetPinValue(button->Button_DIO,button->pinButton);
	}
	else 
	{
      error_button();
	}
}
Button_State ReadButton(PushButton *button)
{
	Button_State returnVar=NOT_PRESS;
	if (DIO_GetPinValue(button->Button_DIO,button->pinButton)!=button->Prev_StateButton)
	{
		_delay_ms(BUTTON_BOUNCE_PERIOD_mS);
		if(DIO_GetPinValue(button->Button_DIO,button->pinButton)!=button->Prev_StateButton)
		{
		    button->Prev_StateButton=DIO_GetPinValue(button->Button_DIO,button->pinButton);
			switch(button->Prev_StateButton)
			{
				case LOW:
				returnVar=LOW_PRESSED;
				break;
				case  HIGH:
				returnVar=HIGH_PRESSED;
				break;
				default:
				error_button();
				break;
				
			}
			
				
		}
		
	}
	return returnVar;
	
	
	
}
void Button_intial_ExtInterrupt(pushButtonProject *button)
{  
	 MCU_voidEnableGlobalInt();
	External_interrupt_Configure(button->buttonInterrupt,button->buttonInterruptModes);
	Enable_External_interrupt(button->buttonInterrupt);
	switch(button->buttonInterrupt){
		case INT0:
		button->Button_DIO=PIND;
		button->pinButton=PIN2;
		break;
		case INT1:
		button->Button_DIO=PIND;
		button->pinButton=PIN3;
		break;
		
		case INT2:
		button->Button_DIO=PINB;
		button->pinButton=PIN2;
		break;
	}
	
	
		button->Prev_StateButton=DIO_GetPinValue(button->Button_DIO,button->pinButton);
		
}

digitalState GetValue_ExtPushButton(pushButtonProject *button)
{				  switch(button->buttonInterrupt)
					{
					case INT0:
					button->Button_DIO=PIND;
					button->pinButton=PIN2;
					break;
					case INT1:
					button->Button_DIO=PIND;
					button->pinButton=PIN3;
					break;
	
					case INT2:
					button->Button_DIO=PINB;
					button->pinButton=PIN2;
					break;
					}

			return DIO_GetPinValue(button->Button_DIO,button->pinButton);
			
		
	
}
	
	void ButtonCallBackFun(pushButtonProject *button,void (*volatile pf_INT) (void ))
	{
SetCallBackFunction(button->buttonInterrupt,*pf_INT);
	}

void error_button(void)
{
	
}