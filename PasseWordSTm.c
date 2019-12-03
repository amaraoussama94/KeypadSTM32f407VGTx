
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stm32_ub_lcd_2x16.h"

char PASSWORD;
char key;
int ncount=0;
int a;
int FLAG;
int i=0;
int k;
unsigned long j;
char text[5];
char text1[5];
char text2[5];

char psw[5]="ABCDD";

void configuration()
{
	RCC->AHB1ENR=0x00000008;
	GPIOD->MODER=0x55555500; //PD7 ->PD4 OUTPUT PD3->PD0 INPUT
	GPIOD->PUPDR=0x55555555;
}

void MESSAGE_WELCOM()
{
	UB_LCD_2x16_String(0,0,"LCD 2x16 STM32F4");
    UB_LCD_2x16_String(1,1,"HELLO KHALIL");
    P_LCD_2x16_Delay(20000000);
    UB_LCD_2x16_Clear();
}



char GETKEY()
{
	GPIOD->ODR=0x0070;
	if((GPIOD->IDR&0x0008)==0)
	{
		ncount++;
		return '1';
	}
	if((GPIOD->IDR&0x0004)==0)
	{
		ncount++;
		return '2';
	}
	if((GPIOD->IDR&0x0002)==0)
	{
		ncount++;
		return '3';
	}
	if((GPIOD->IDR&0x0001)==0)
	{
		ncount++;
		FLAG=1;
		return 'A';
	}

	GPIOD->ODR=0x00B0;
	if((GPIOD->IDR&0x0008)==0)
	{
		ncount++;
		return '4';
	}
	if((GPIOD->IDR&0x0004)==0)
	{
		ncount++;
		return '5';
	}
	if((GPIOD->IDR&0x0002)==0)
	{
		ncount++;
		return '6';
	}
	if((GPIOD->IDR&0x0001)==0)
	{
		ncount++;
		return 'B';
	}

	GPIOD->ODR=0x00D0;

	if((GPIOD->IDR&0x0008)==0)
	{
		ncount++;
		return '7';
	}
	if((GPIOD->IDR&0x0004)==0)
	{
		ncount++;
		return '8';
	}
	if((GPIOD->IDR&0x0002)==0)
	{
		ncount++;
		return '9';
	}
	if((GPIOD->IDR&0x0001)==0)
	{
		ncount++;
		return 'C';
	}

	GPIOD->ODR=0x00E0;


	if((GPIOD->IDR&0x0008)==0)
	{
		ncount++;
		return '*';
	}
	if((GPIOD->IDR&0x0004)==0)
	{
		ncount++;
		return '0';
	}
	if((GPIOD->IDR&0x0002)==0)
	{
		ncount++;
		return '#';
	}
	if((GPIOD->IDR&0x0001)==0)
	{
		ncount++;
		return 'D';
	}

   return key;

}


void validation_password()
{
	if(PASSWORD!=0)
	    {
		  sprintf (text,"%c",PASSWORD);
		  UB_LCD_2x16_String(ncount-1,1,text);
		  text1[ncount-1]=PASSWORD;
		 P_LCD_2x16_Delay(2000000);
	    }
	    if(ncount==5)
	    {
		       sprintf (text2,"%s",text1);
	           UB_LCD_2x16_String(5,0,text2);
		       P_LCD_2x16_Delay(20000000);

		       a=strcmp(text2,psw);

		       if(a==0)
		       {
		             GPIOD->ODR=0x8000;
		             P_LCD_2x16_Delay(10000000);
		             GPIOD->ODR=0x0000;
		             UB_LCD_2x16_Clear();
		             UB_LCD_2x16_String(5,0,"CODE OK ");
		             UB_LCD_2x16_String(3,1,"WELCOM KHALIL ");
		             P_LCD_2x16_Delay(20000000);
		       }
		       else
		       {
			         GPIOD->ODR=0x0000;
			         UB_LCD_2x16_String(5,0,"CODE NOT OK ");
			         UB_LCD_2x16_String(0,1,"INPUT TRUE KEY ");
			         P_LCD_2x16_Delay(20000000);
		       }

		       UB_LCD_2x16_Clear();
		       ncount=0;
	     }
}

int main(void)
{


  SystemInit();
  configuration();
  UB_LCD_2x16_Init();
  MESSAGE_WELCOM();



  while(1)
  {
	UB_LCD_2x16_String(0,0,"KEY:");

    PASSWORD=GETKEY();

    validation_password();

  }

}



