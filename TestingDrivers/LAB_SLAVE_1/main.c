/*
 * main.c
 *
 *  Created on: Aug 28, 2022
 *      Author: HP
 */

#include "STD_TYPES.h"
#include "BitMath.h"
#include "SPI_Private.h"
#include "DIO_Config.h"
#include "DIO_Interface.h"
#include "SPI_Config.h"
#include "SPI_Interface.h"
#include "TMR0_Config.h"
#include "TMR0_Interface.h"
#include "GIE_Interface.h"

void Timer()
{
	static u16 count = 0;
	if (count == 3907)
	{
		DIO_voidTogglePinValue(portA ,pin0);
		count = 0;
	}
	else
	{
		count ++;
	}
}

int main()
{
	u8 data;
	SPI_voidInitailSlave();

	TMR0_voidInit();
	EXT_voidGIE_Enable();

	DIO_voidSetPinDirection(portA ,pin0 , pin_output);
	data = SPI_u8Transceiver('a');

	if (data == 'a')
	{
		TMR0_SetCallBack(Timer);
	}

	while(1);
	return 0;
}
