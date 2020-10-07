/*
 * Macros.h
 *
 * Created: 8/31/2020 1:05:06 PM
 *  Author: mahmo
 */ 


#ifndef MACROS_H_
#define MACROS_H_


#define SeTBit(PORTX,Bit)    PORTX |=(1<<(Bit))
#define  ClearBit(PORTX,Bit)   PORTX &=~(1<<(Bit))
#define ToggleBit(PORTX,Bit)    PORTX ^=(1<<(Bit))
#define  ReadBit(PORTX,Bit)    ((PORTX & (1<<(Bit)))>>(Bit))


#endif /* MACROS_H_ */