#ifndef _I2C_keypad_H_
#define _I2C_keypad_H_

#include "stm32f4xx_i2c.h"

#define keypad_ADDR	0x43 //0100xxx1(mode lecture)

extern void delay(uint32_t t);

#define PCF_P0	0
#define PCF_P1	1
#define PCF_P2	2
#define PCF_P3	3
#define PCF_P4	4
#define PCF_P5	5
#define PCF_P6	6
#define PCF_P7	7


#define rw1	    PCF_P4//+Vcc
#define rw2		PCF_P5//+Vcc
#define rw3		PCF_P6//+Vcc
#define rw4		PCF_P7//+Vcc
#define li1		PCF_P0
#define li2		PCF_P1
#define li3		PCF_P2
#define li4		PCF_P3



#endif
