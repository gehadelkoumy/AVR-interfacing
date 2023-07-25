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
	u8 arr[5];
	u8 count = 0;
	u8 Result;
	LCD_voidInitialize();
	KEYPAD_voidInit();
	while(1)
	{
		keypadpressed = KEYPAD_voidGetPressedKey();

		if(keypadpressed != 0xff)
		{
			LCD_voidWriteData(keypadpressed);
			arr[count] = keypadpressed;
			count++;
			if(keypadpressed == '=')
			{
				switch (arr[1])
				{
				case '+' :  Result  = (arr[0]-48) + (arr[2]-48);  break;
				case '-' :  Result  = arr[0] - arr[2];       break;
				case '*' :  Result  = (arr[0]-48) * (arr[2]-48);  break;
				case '/' :  Result  = (arr[0]-48) / (arr[2]-48);  break;
				}
				//LCD_voidNumbers(Result);
				if(Result == 0)
				{
					LCD_voidWriteData('0');
				}
				else
				{
					LCD_voidNumbers(Result);
				}
			}
			if (keypadpressed == '\0')     //clear
			{
				LCD_voidClear();
				count = 0;
			}
		}
	}

	return 0;
}

