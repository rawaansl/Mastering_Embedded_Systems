//this is a custom header file including the platform types for STM microcontrollers 
//without using stdint header file

#ifndef _PLATFORM_TYPES_H             //header protection
#define _PLATFORM_TYPES_H
#include <stdbool.h>

typedef unsigned long boolean;

typedef signed char sint8;
typedef unsigned char uint8;

typedef signed short sint16;
typedef unsigned short uint16;

typedef signed long sint32;
typedef unsigned long uint32;

typedef volatile signed char vsint8;
typedef volatile unsigned char vuint8;

typedef volatile signed short vsint16;
typedef volatile unsigned short vuint16;

typedef volatile signed long vsint32;
typedef volatile unsigned long vuint32;


#endif