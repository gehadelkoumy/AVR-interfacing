/*
 * main.c
 *
 *  Created on: Aug 17, 2022
 *      Author: HP
 */
#include "STD_TYPES.h"
#include "BitMath.h"
#include "DIO_Config.h"
#include "DIO_Interface.h"
#include "GIE_Interface.h"
#include "EXT_Config.h"
#include "EXT_Interface.h"

int main()
{
	DIO_voidSetPinDirection(portA ,pin0 ,pin_output);
	DIO_voidSetPinDirection(portA ,pin1 ,pin_output);
	DIO_voidSetPinDirection(portA ,pin2 ,pin_output);

	EXT_voidInitialize(EXT0 ,RisingEdge);
	EXT_voidInitialize(EXT1 ,LowLevel);
	EXT_voidInitialize(EXT2 ,FallingEdge);

	while(1);
	return 0;
}
