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
#include "Keypad_Config.h"
#include "Keypad_Interface.h"
#include "util/delay.h"

int main()
{
	u8 keypadpressed=0;
	LCD_voidInitialize();
	KEYPAD_voidInit();
	while(1)
	{
		keypadpressed = KEYPAD_voidGetPressedKey();
		if(keypadpressed != 0xff)
		{
			LCD_voidNumbers(keypadpressed);
		}
	}
	return 0;
}
