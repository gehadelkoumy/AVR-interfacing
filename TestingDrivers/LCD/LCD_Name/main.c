/*
 * main.c
 *
 *  Created on: Aug 15, 2022
 *      Author: HP
 */

#include "STD_TYPES.h"
#include "BitMath.h"
#include "DIO_Config.h"
#include "DIO_Interface.h"
#include "LCD_Config.h"
#include "LCD_Interface.h"
#include "util/delay.h"

int main()
{
	LCD_voidInitialize();
	for (u8 i=0 ;i<16;i++)
	{
		LCD_voidGoToXY(i,1);
		LCD_voidString("Gehad");
		_delay_ms(20);
		LCD_voidClear();
	}

	return 0;
}
