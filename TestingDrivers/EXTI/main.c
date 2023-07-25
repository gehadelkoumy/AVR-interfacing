/*
 * main.c
 *
 *  Created on: Aug 21, 2022
 *      Author: HP
 */
#include "STD_TYPES.h"
#include "BitMath.h"
#include "DIO_Config.h"
#include "DIO_Interface.h"
#include "GIE_Interface.h"
#include "EXT_Config.h"
#include "EXT_Interface.h"

void ISR0(void)
{      //ISR
	DIO_voidSetPinDirection(portA , pin0 , pin_output);
	DIO_voidTogglePinValue(portA ,pin0);
}

void ISR1(void)
{      //ISR
	DIO_voidSetPinDirection(portA , pin1 , pin_output);
	DIO_voidTogglePinValue(portA ,pin1);
}

void ISR2(void)
{      //ISR
	DIO_voidSetPinDirection(portA , pin2 , pin_output);
	DIO_voidTogglePinValue(portA ,pin2);
}

int main()
{
	EXT_voidGIE_Enable();
	EXT_voidInitialize(EXT0 , FallingEdge);
	EXT0_SetCallBack(ISR0);
	EXT_voidInitialize(EXT1 , LowLevel);
	EXT1_SetCallBack(ISR1);
	EXT_voidInitialize(EXT2 , FallingEdge);
	EXT2_SetCallBack(ISR2);
	while(1);
	return 0;
}

