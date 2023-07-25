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
#include "USART_Config.h"
#include "USART_Interface.h"

int main()
{
	u8 data;
	SPI_voidInitailSlave();

	USART_voidInitial();
	data = SPI_u8Transceiver('b');
	if (data == 'b')
	{
		USART_voidSendString("welcome");
	}
	while(1);
	return 0;
}
