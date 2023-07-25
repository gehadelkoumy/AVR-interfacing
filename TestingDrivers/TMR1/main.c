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
#include "TMR1_Interface.h"

void ISR_TOGGLE(void)
{           //ISR
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

	DIO_voidSetPinDirection(portD , pin5 ,pin_output);
	TMR1_voidInit();
	//TMR1_voidPreload(192);
	//TMR1_SetCallBack(ISR_TOGGLE);
	TMR1_voidOCR1A(2000);
	while(1);
	return 0;
}
