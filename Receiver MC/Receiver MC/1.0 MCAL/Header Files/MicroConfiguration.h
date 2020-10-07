/*
 * MicroConfiguration.h
 *
 * Created: 8/31/2020 2:03:20 PM
 *  Author: mahmo
 */ 


#ifndef MICROCONFIGURATION_H_
#define MICROCONFIGURATION_H_
#include "Macros.h"
#include "StdTypes.h"

/******************************* CPU Related Defines *******************************************************/
#define F_CPU		(16000000U)
/******************************* CPU Internal Registers <SFRs & GPRs> **************************************/
#define IO_OFFSET  (0x20)
#define NULL	((void *) 0x0FFF) /* ask */
#define NULLPTR   ((void*)0)

/*****************************/
typedef union {
	vuint8_t Fullbits;
	struct {
			vuint8_t b0:1;
			vuint8_t b1:1;
			vuint8_t b2:1;
			vuint8_t b3:1;
			vuint8_t b4:1;
			vuint8_t b5:1;
			vuint8_t b6:1;
			vuint8_t b7:1;
		}Bits;
	
	
	}reg;
	
	
	typedef struct {
	
		reg PIN;
		reg DDR;
		reg port;
		}DIO_Configure;


typedef enum {
	FALSE,
	TRUE,
}Bool;

typedef enum {
	LOW=0,
	HIGH=1,
}digitalState;

typedef enum {
	PIN0=0,PIN1=1,PIN2=2,PIN3=3,PIN4=4,PIN5=5,PIN6=6,PIN7=7,
}pinNumber;


/*---------------------------*/
/*-------------------INTERRUPT section map --------------------------------*/
/*-------------------------------CPU Internal Registers or register enable external interrupt  ------------------------*/

#define GICR  ((reg*)(IO_OFFSET+0x3B)) /* bit 5 and bit 7 and bit 8 controls enable external interrupt */
#define GIFR  ((reg*)(IO_OFFSET+0x3A)) /* when interrupt happens , register writes one  */
#define SREG ((reg*)(IO_OFFSET+0x3F)) /* there is i-bit control global interrupt */
#define MCUCR  ((reg*)(IO_OFFSET+0x35)) /* 4 bits controls modes external interrupt */
#define MCUCSR  ((reg*)(IO_OFFSET+0x34))  /* controls modes external interrupt two */
#define ISC00  0
#define ISC01   1
#define ISC10   2
#define ISC11   3
#define ISC2 6
#define  INT0_GICR 6
#define  INT1_GICR 7
#define  INT2_GICR 5
#define  Interrupt_global_SREG 7
/*---------------------mircos function ISR or external interrupt ------------------------*/
#define  ISR(vector,...) \
void vector (void) __attribute__ ((signal)) __VA_ARGS__;\
void vector (void)

#define ISR_NAKED      	__attribute__((naked))
/******************************************* Global Interrupt Related Macros **************************************/
#define GLOBAL_INTERRUPT_ENABLE()	{ SeTBit(SREG->Fullbits,Interrupt_global_SREG);  }
#define GLOBAL_INTERRUPT_DISABLE()	{ClearBit(SREG->Fullbits,Interrupt_global_SREG);}
	
/********************************************************************************************************/




/*------------------------------- vectors tables interrupt ------------------------*/
/* External Interrupt Request 0 */
#define INT0_vect	__vector_1
/* External Interrupt Request 1 */
#define INT1_vect			__vector_2
/* External Interrupt Request 2 */
#define INT2_vect			__vector_3
/* Timer/Counter2 Compare Match */
#define TIMER2_COMP_vect		__vector_4
/* Timer/Counter2 Overflow */
#define TIMER2_OVF_vect			__vector_5
/* Timer/Counter1 Capture Event */
#define TIMER1_CAPT_vect		__vector_6
/* Timer/Counter1 Compare Match A */
#define TIMER1_COMPA_vect		__vector_7
/* Timer/Counter1 Compare Match B */
#define TIMER1_COMPB_vect		__vector_8
/* Timer/Counter1 Overflow */
#define TIMER1_OVF_vect			__vector_9
/* Timer/Counter0 Compare Match */
#define TIMER0_COMP_vect		__vector_10
/* Timer/Counter0 Overflow */
#define TIMER0_OVF_vect			__vector_11
/* Serial Transfer Complete */
#define SPI_STC_vect			__vector_12
/* USART, Rx Complete */
#define USART_RXC_vect			__vector_13
/* USART Data Register Empty */
#define USART_UDRE_vect			__vector_14
/* USART, Tx Complete */
#define USART_TXC_vect			__vector_15
/* ADC Conversion Complete */
#define ADC_vect			   __vector_16
/* EEPROM Ready */
#define EE_RDY_vect			   __vector_17
/* Analog Comparator */
#define ANA_COMP_vect			__vector_18
/* 2-wire Serial Interface */
#define TWI_vect			    __vector_19
/* Store Program Memory Ready */
#define SPM_RDY_vect			__vector_20
/******************************************************************/
/*-----------------------Timer section ------------------------------*/




#define PORTA *((volatile uint8_t*) 0x3B)
#define PORTB *((volatile uint8_t*) 0x38)
#define PORTC *((volatile uint8_t*) 0x35)
#define PORTD *((volatile uint8_t*) 0x32)

#define PINA *((volatile uint8_t*) 0x39)
#define PINB *((volatile uint8_t*) 0x36)
#define PINC *((volatile uint8_t*) 0x33)
#define PIND *((volatile uint8_t*) 0x30)

#define DDRA *((volatile uint8_t*) 0x3A)
#define DDRB *((volatile uint8_t*) 0x37)
#define DDRC *((volatile uint8_t*) 0x34)
#define DDRD *((volatile uint8_t*) 0x31)

#define DDRA (*(volatile unsigned char*)0x3A)
#define DDRB (*(volatile unsigned char*)0x37)
#define DDRC (*(volatile unsigned char*)0x34)
#define DDRD (*(volatile unsigned char*)0x31)

#define PINA (*(volatile unsigned char*)0x39)
#define PINB (*(volatile unsigned char*)0x36)
#define PINC (*(volatile unsigned char*)0x33)
#define PIND (*(volatile unsigned char*)0x30)

#define PORTA (*(volatile unsigned char*)0x3B)
#define PORTB (*(volatile unsigned char*)0x38)
#define PORTC (*(volatile unsigned char*)0x35)
#define PORTD (*(volatile unsigned char*)0x32)
/********************************************************************************************************/



#endif /* MICROCONFIGURATION_H_ */