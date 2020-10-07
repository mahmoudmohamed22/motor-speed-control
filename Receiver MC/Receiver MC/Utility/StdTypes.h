/*
 * StdTypes.h
 *
 * Created: 8/31/2020 1:04:35 PM
 *  Author: mahmo
 */ 


#ifndef STDTYPES_H_
#define STDTYPES_H_

#define NULL (void*)(0)

typedef unsigned char		uint8_t;
typedef signed char			sint8_t;
//typedef unsigned short	 	uint16_t;
typedef signed short		sint16_t;
typedef unsigned long		uint32_t;
typedef signed long			sint32_t;
typedef unsigned long long	uint64_t;
typedef signed long long	sint64_t;
typedef float				float32;
typedef double				float64;

typedef volatile uint8_t  vuint8_t;
typedef volatile sint8_t  vsint8_t;
//typedef volatile uint16_t  vuint16_t;
typedef volatile sint16_t  vsint16_t;
typedef volatile uint32_t  vuint32_t;
typedef volatile sint32_t  vsint32_t;
typedef volatile uint64_t  vuint64_t;
typedef volatile sint64_t  vsint64_t;






#endif /* STDTYPES_H_ */
