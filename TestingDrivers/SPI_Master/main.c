/*
 * main.c
 *
 *  Created on: Aug 25, 2022
 *      Author: HP
 */

#include "STD_TYPES.h"
#include "BitMath.h"
#include "DIO_Config.h"
#include "DIO_Interface.h"
#include "SPI_Config.h"
#include "SPI_Interface.h"

int main()
{
	u8 data;
	SPI_voidInitailMaster();

	DIO_voidSetPinDirection(portB , pin0 ,pin_output);
	DIO_voidSetPinValue(portB , pin0 , pin_low);

	data = SPI_u8Transceiver('a');

	while(1);
	return 0;
}

