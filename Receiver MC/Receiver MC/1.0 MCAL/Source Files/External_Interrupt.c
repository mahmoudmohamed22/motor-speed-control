/*
 * External_Interrupt.c
 *
 * Created: 6/17/2020 6:45:23 PM
 *  Author: mahmoud
 */ 
#include "External_Interrupt.h"
#define SREG *((volatile uint8_t*)0x5F)

/*  ------call back function --------------*/
/* used to send function to  ISR Interrupt  to Is implemented */
/* pointer to funtions pointer to null then to function interrupt or users ,and call in layers users */
/* poiner to function to assigned ISR */
void __vector_1(void) __attribute__((signal));
void __vector_2(void) __attribute__((signal));
void __vector_3(void) __attribute__((signal));
void(*gptr[3])(void)={NULL,NULL,NULL};

static void(* volatile  pfunction_INT0)(void)= NULL;
static void(*volatile   pfunction_INT1)(void)= NULL;
static void(*volatile   pfunction_INT2)(void)= NULL;


void External_interrupt_Configure(External_interrupt EXt_interrupt ,Modes_Ext_INTERRUPT modes_interrupt )  /*function used seting or comfigure external interrupt */
{
	switch(EXt_interrupt){
		case INT0:
		switch(modes_interrupt){
			case ANY_LOGICAL_Change: 
			
			SeTBit(MCUCR->Fullbits,ISC00);
			ClearBit(MCUCR->Fullbits,ISC01);
			break;
			case FALLING_EDGE:
				ClearBit(MCUCR->Fullbits,ISC00);
			SeTBit(MCUCR->Fullbits,ISC01);
			break;
			case RISING_EDGE:
			SeTBit(MCUCR->Fullbits,ISC00);
			SeTBit(MCUCR->Fullbits,ISC01);
			break;
			case LOW_LEVEL:
				ClearBit(MCUCR->Fullbits,ISC00);
				ClearBit(MCUCR->Fullbits,ISC01);
			break;
			default:
			break;
		}
		
		break;
		
		case INT1:
			switch(modes_interrupt){
				case ANY_LOGICAL_Change:
				SeTBit(MCUCR->Fullbits,ISC10);
					ClearBit(MCUCR->Fullbits,ISC11);
				break;
				case FALLING_EDGE:
					ClearBit(MCUCR->Fullbits,ISC10);
				SeTBit(MCUCR->Fullbits,ISC11);
				break;
				case RISING_EDGE:
				SeTBit(MCUCR->Fullbits,ISC10);
				SeTBit(MCUCR->Fullbits,ISC11);
				break;
				case LOW_LEVEL:
			ClearBit(MCUCR->Fullbits,ISC10);
					ClearBit(MCUCR->Fullbits,ISC11);
				break;
				default:
				break;
			}
		
		break;
		
		case INT2:
		switch(modes_interrupt){
		
			case FALLING_EDGE:
			ClearBit(MCUCSR->Fullbits,ISC2);
			break;
			case RISING_EDGE:
			SeTBit(MCUCSR->Fullbits,ISC2);
			break;
			default:
			break;
		}
		
		break;
	}
}
	
void Enable_External_interrupt(External_interrupt interrupt){ /*function enable interrupt*/
	
	switch(interrupt){
		case INT0:
			DIO_Init_PIN(PIND,2 ,InputPullup);
			DIO_SetPinValue(PIND ,2,HIGH );
		SeTBit(GICR->Fullbits,INT0_GICR);
		break;
		case INT1:
			DIO_Init_PIN(PIND,3 ,InputPullup);
			DIO_SetPinValue(PIND ,3,HIGH );

		SeTBit(GICR->Fullbits,INT1_GICR);
		break;
		case INT2:
			DIO_Init_PIN(PIND,2 ,InputPullup);
			DIO_SetPinValue(PIND ,2,HIGH );

		SeTBit(GICR->Fullbits,INT2_GICR);
		break;
		default:
		/*function error external interrupt */
		break;
		
	}
	
}
void Disable_External_interrupt(External_interrupt interrupt){ /*function disable  interrupt*/
	switch(interrupt){
		case INT0:
	ClearBit(GICR->Fullbits,INT0_GICR);
		break;
		case INT1:
	ClearBit(GICR->Fullbits,INT1_GICR);
		break;
		case INT2:
	ClearBit(GICR->Fullbits,INT2_GICR);
		break;
		default:
		/*function error external interrupt */
		break;
		
	}
	
}
/*----------------------------------------------ISR MICRO---------------------------*/
/* ISR talk complier for attribute interrupt to push register in stack because variable main don't effect */
/*ISR(INT0_vect){
		if( pfunction_INT0 !=NULL)
	 pfunction_INT0();
}
ISR(INT1_vect){
	if( pfunction_INT1 !=NULL)
	 pfunction_INT1();
}

ISR(INT2_vect){
	if( pfunction_INT2 !=NULL)
	 pfunction_INT2();
}*/

/*--------------------SET CALL BACK function -------*/
void SetCallBackFunction(External_interrupt ext_interrupt ,void (*volatile pf_INT) (void )){
	if(pf_INT!=NULL)
	{
		switch(ext_interrupt){
			case INT0:
				gptr[0]=pf_INT;

			break;
			case INT1:
				gptr[1]=pf_INT;
			break;
			case INT2:
				gptr[2]=pf_INT;
			break;
		}

	}
}

void MCU_voidEnableGlobalInt(void)
{
	SeTBit(SREG,7);
}

void __vector_1 (void)
{
	if(gptr[0]!=NULL)
		(*gptr[0])();
	MCU_voidEnableGlobalInt();
}

void __vector_2 (void)
{
	if(gptr[1]!=NULL)
		(*gptr[1])();
	MCU_voidEnableGlobalInt();
}

void __vector_3 (void)
{
	if(gptr[2]!=NULL)
		(*gptr[2])();
	MCU_voidEnableGlobalInt();
}

