
#include<string.h>
#include"UART_Init.h"

void(*Global_uint8_tPtr[3])(void)={NULL,NULL,NULL};

void __vector_13(void) __attribute__((signal));
void __vector_14(void) __attribute__((signal));
void __vector_15(void) __attribute__((signal));

void USART_voidInit(void)
{
	UBRRH=(uint8_t)(MYUBRR>>8);		    //MYUBBR is the value of UBRR.
	UBRRL=(uint8_t)(MYUBRR);
	UCSRB = (1<<RXEN)|(1<<TXEN);   // Enabling the Transmitter and the Receiver.
	UCSRC = (1<<7)|(1<<2)|(1<<1);  // Configure character size of 8 bits, Asynchronous mode and 1 stop bit.
}

void USART_voidTransmit(uint8_t Copy_uint8_tData)
{
	while(!(UCSRA & (1<<5) )); //Polling on UDRE bit to check if the UDR is empty
	UDR=Copy_uint8_tData;
}

uint8_t USART_uint8_tReceive(void)
{
	while(!(UCSRA & (1<<7) ));  //Polling on RXC bit to check if the reception complete
	return UDR;

}

void USART_voidTransStirng(uint8_t* Copy_uint8_tPString)
{
	uint8_t i=0;
	while((Copy_uint8_tPString[i])!='\0') // Sending a string char by char until find the '\0'.
	{
		USART_voidTransmit((Copy_uint8_tPString[i]));
		i++;
	}
}

uint8_t USART_uint8_tUDRRead(void)
{
	return UDR;
}


/*
void MCU_voidEnableGlobalInt(void) //Enabling the global interrupt
{
	SeTBit(SREG,7);
}*/

void USART_voidIntEnDisable(uint8_t Copy_uint8_tINT,uint8_t Copy_uint8_tStutus) //USAR interrupt Enable or Disable
{
	switch(Copy_uint8_tINT)
	{
	case RXCIE :
		if(Copy_uint8_tStutus)
		{
			UCSRB |= (1<<RXCIE);
		}
		else
		{
			UCSRB &=~(1<<RXCIE);
		}
		break;
	case UDRIE :
		if(Copy_uint8_tStutus)
		{
			UCSRB |= (1<<UDRIE);
		}
		else
		{
			UCSRB &=~(1<<UDRIE);
		}
		break;
	case TXCIE :
		if(Copy_uint8_tStutus)
		{
			UCSRB |= (1<<TXCIE);
		}
		else
		{
			UCSRB &=~(1<<TXCIE);
		}
		break;
	}

}

void USART_voidRXC_INT(void(*Copy_uint8_tPtr)(void)) //This function takes an address of a function and assign it
{											    //to the global pointer which executed inside the interrupt service
	if(Copy_uint8_tPtr!=NULL)
	{
		Global_uint8_tPtr[0]=Copy_uint8_tPtr;
	}
}
void USART_voidUDRE_INT(void(*Copy_uint8_tPtr)(void)) //This function takes an address of a function and assign it
{											    //to the global pointer which executed inside the interrupt service
	if(Copy_uint8_tPtr!=NULL)
	{
		Global_uint8_tPtr[1]=Copy_uint8_tPtr;
	}
}
void USART_voidTXC_INT(void(*Copy_uint8_tPtr)(void)) //This function takes an address of a function and assign it
{											    //to the global pointer which executed inside the interrupt service
	if(Copy_uint8_tPtr!=NULL)
	{
		Global_uint8_tPtr[2]=Copy_uint8_tPtr;
	}
}
void __vector_13(void)
{
	if(Global_uint8_tPtr[0]!=NULL)
		(*Global_uint8_tPtr[0])();  // Executing the function whose address is carried by this pointer
}



void __vector_14(void)
{
	if(Global_uint8_tPtr[1]!=NULL)
		(*Global_uint8_tPtr[1])();  // Executing the function whose address is carried by this pointer
}

void __vector_15(void)
{
	if(Global_uint8_tPtr[2]!=NULL)
		(*Global_uint8_tPtr[2])();  // Executing the function whose address is carried by this pointer
}
