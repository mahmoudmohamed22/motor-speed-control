/*
 * AVR_USART_REG.h
 *
 *  Created on: Aug 7, 2020
 *      Author: Hazem Shalaby
 */

#ifndef AVR_USART_REG_H_
#define AVR_USART_REG_H_

#define UBRRH    *((volatile uint8_t*)0x40)
#define UBRRL    *((volatile uint8_t*)0x29)
#define UCSRA    *((volatile uint8_t*)0x2B)
#define UCSRB    *((volatile uint8_t*)0x2A)
#define UCSRC    *((volatile uint8_t*)0x40)
#define UDR      *((volatile uint8_t*)0x2C)




#endif /* AVR_USART_REG_H_ */
