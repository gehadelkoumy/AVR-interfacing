/*
 * main.c
 *
 *  Created on: Aug 22, 2022
 *      Author: HP
 */
#include "STD_TYPES.h"
#include "BitMath.h"
#include "DIO_Config.h"
#include "DIO_Interface.h"
#include "GIE_Interface.h"
#include "TMR2_Config.h"
#include "TMR2_Interface.h"

void ISR_TOGGLE(void)
{           //ISR
	DIO_voidTogglePinValue(portA ,pin0);
}

int main()
{
	DIO_voidSetPinDirection(portD , pin7 , pin_output);
	EXT_voidGIE_Enable();
	TMR2_voidInit();
	TMR2_voidOCR2(127);
	//TMR2_SetCallBack(ISR_TOGGLE);
	//TMR2_voidPreload(192);
	while(1);
	return 0;
}



