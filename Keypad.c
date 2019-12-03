#include "i2c_keypad.h"

void keypad_Send(uint8_t data)
{
	while(I2C_GetFlagStatus(I2C1, I2C_FLAG_BUSY));
	I2C_GenerateSTART(I2C1, ENABLE);

	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT));
	I2C_Send7bitAddress(I2C1, keypad_ADDR, I2C_Direction_Receiver );
	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED));
	I2C_ReceiveData(I2C1);
	//I2C_SendData(I2C1, data);
	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_RECEIVED  ));
	 I2C_NACKPositionConfig( I2C1, I2C_NACKPosition_Current); //I2C_NACKPosition_Next

	 I2C_GenerateSTOP(I2C1, ENABLE);

}
void gen_fun( )
{
	x=1 ;
	delay(100);
	x=10 ;
	delay(100);
	x=100 ;
	delay(100);
}

char GETKEY()
{
	if(gen=1)
	{if((I2C1->DR&0x0001)==0) //P7P6P5 P3P2P1P0
	{
		ncount++;
		return '1';
	}
	if((I2C1->DR&0x0002)==0)
	{
		ncount++;
		return '2';
	}
	if((I2C1->DR&0x0004)==0)
	{
		ncount++;
		return '3';
	}
	if((I2C1->DR&0x0001)==0)
	{
		ncount++;
		FLAG=1;
		return 'A';
	}
	}
	if(gen=10)
	{	{if((I2C1->DR&0x0001)==0) //P7P6P5P4 P3P2P1P0
		ncount++;
		return '4';
	}
	if((I2C1->DR&0x0004)==0)
	{
		ncount++;
		return '5';
	}
	if((I2C1->DR&0x0002)==0)
	{
		ncount++;
		return '6';
	}
	if((I2C1->DR&0x0001)==0)
	{
		ncount++;
		return 'B';
	}
	}
	if(gen=100)
	{
	if((I2C1->DR&0x0008)==0)
	{
		ncount++;
		return '7';
	}
	if((I2C1->DR&0x0004)==0)
	{
		ncount++;
		return '8';
	}
	if((I2C1->DR&0x0002)==0)
	{
		ncount++;
		return '9';
	}
	if((I2C1->DR&0x0001)==0)
	{
		ncount++;
		return 'C';
	}
	}
	if(gen=1000)

	{
	if((I2C1->DR&0x0008)==0)
	{
		ncount++;
		return '*';
	}
	if((I2C1->DR&0x0004)==0)
	{
		ncount++;
		return '0';
	}
	if((I2C1->DR&0x0002)==0)
	{
		ncount++;
		return '#';
	}
	if((I2C1->DR&0x0001)==0)
	{
		ncount++;
		return 'D';
	}
	}
   return key;

}
