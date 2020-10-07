/*
 * External_Interrupt.h
 *
 * Created: 6/17/2020 6:45:09 PM
 *  Author: mahmo
 */ 


#ifndef EXTERNAL_INTERRUPT_H_
#define EXTERNAL_INTERRUPT_H_
#include "GPIO.h"


#include "StdTypes.h"
#include "Macros.h"
#include "MicroConfiguration.h"


typedef enum {
	INT0,
	INT1,
	INT2
	}External_interrupt;
	
typedef enum
{   RISING_EDGE,
	FALLING_EDGE,
	LOW_LEVEL,
	ANY_LOGICAL_Change
	
	}Modes_Ext_INTERRUPT;	
	
	
	//intial
	//enable 
	//disable
	/*function driver external interrupt*/
	void External_interrupt_Configure(External_interrupt interrupt ,Modes_Ext_INTERRUPT modes ); /*function used seting or comfigure external interrupt */
	void Enable_External_interrupt(External_interrupt interrupt);/*function use enable interrupt*/
	void Disable_External_interrupt(External_interrupt interrupt);/*function use disable interrupt */
	void SetCallBackFunction(External_interrupt ext_interrupt ,void (*volatile pf_INT) (void )); /* set call function to send function interrupt to ISR for user layer */

	void MCU_voidEnableGlobalInt(void);



#endif /* EXTERNAL_INTERRUPT_H_ */
