/*
 * PushButton.h
 *
 * Created: 9/6/2020 7:33:09 PM
 *  Author: mahmoud
 */ 


#ifndef PUSHBUTTON_H_
#define PUSHBUTTON_H_
#include "GPIO.h"
#include "External_Interrupt.h"
#include <util/delay.h>
#include "UART_Init.h"



#define BUTTON_BOUNCE_PERIOD_mS	(60)



typedef enum{
	NOT_PRESS,
	HIGH_PRESSED,
	LOW_PRESSED,
	}Button_State;

typedef struct {
	pinNumber pinButton ;
	digitalState Prev_StateButton;
	DIO_Configure * Button_DIO;
	Mode  ButtonMode;
	External_interrupt buttonInterrupt;
	Modes_Ext_INTERRUPT   buttonInterruptModes;
	}PushButton;
	
typedef struct {
	DIO_Configure * Button_DIO;
		pinNumber pinButton ;
		digitalState Prev_StateButton;
		External_interrupt buttonInterrupt;
		Modes_Ext_INTERRUPT   buttonInterruptModes;
	}pushButtonProject;	

	
void Button_intial(PushButton *button); // why pointer because change value pin button
Button_State ReadButton(PushButton *button);
void Button_intial_ExtInterrupt(pushButtonProject *button);// button on external
digitalState GetValue_ExtPushButton(pushButtonProject *button); 
void ButtonCallBackFun(pushButtonProject *button,void (*volatile pf_INT) (void ));
void error_button(void);
	



#endif /* PUSHBUTTON_H_ */