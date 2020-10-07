
#ifndef UART_INIT_H_
#define UART_INIT_H_

#include"UART_Config.h"
#include "MicroConfiguration.h"
#include "Macros.h"
#include "StdTypes.h"
#include "util/delay.h"
#include "AVR_USART_REG.h"


#define MYUBRR (Fosc/16/Baud-1)  // Calculating UBRR value

#define RXCIE 7  // RX Complete interrupt enable bit
#define UDRIE 5  // UDR Empty interrupt enable bit
#define TXCIE 6  // TX Complete interrupt enable bit

#define RXEN 4 //RX Enable bit
#define TXEN 3 //TX Enable bit

#define USART_Enable 1
#define USART_Disable 0

void USART_voidInit(void);
void USART_voidTransmit(uint8_t Copy_uint8_tData);
uint8_t USART_uint8_tReceive(void);

void USART_voidTransStirng(uint8_t* Copy_uint8_tPString);
void MCU_voidEnableGlobalInt(void);
void USART_voidIntEnDisable(uint8_t Copy_uint8_tINT,uint8_t Copy_uint8_tStutus);
void USART_voidRXC_INT(void(*Copy_uint8_tPtr)(void));
void USART_voidUDRE_INT(void(*Copy_uint8_tPtr)(void));
void USART_voidTXC_INT(void(*Copy_uint8_tPtr)(void));

uint8_t USART_uint8_tUDRRead(void);
#endif /* UART_INIT_H_ */
