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
#include "TMR0_Config.h"
#include "TMR0_Interface.h"

void ISR_TOGGLE(void)
{           //ISR
	DIO_voidTogglePinValue(portA ,pin0);
}

int main()
{
	DIO_voidSetPinDirection(portB , pin3 , pin_output);
	EXT_voidGIE_Enable();
	TMR0_voidInit();
	TMR0_voidOCR0(127);
	//TMR0_SetCallBack(ISR_TOGGLE);
	//TMR0_voidPreload(192);
	while(1);
	return 0;
}

