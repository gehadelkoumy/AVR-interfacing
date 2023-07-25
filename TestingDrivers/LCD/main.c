#include "STD_TYPES.h"
#include "BitMath.h"
#include "DIO_Config.h"
#include "DIO_Interface.h"
#include "LCD_Config.h"
#include "LCD_Interface.h"
#include "util/delay.h"

int main()
{
	u8 p_1[] = {0B00000,0B00111,0B01001,0B11111,0B00000,0B00010,0B00000,0B00000};
	u8 p_2[] = {0B00000,0B00111,0B01101,0B01111,0B00000,0B00000,0B00000,0B00000};
	LCD_voidInitialize();
	//LCD_voidGoToXY(5,1);
	//LCD_voidNumbers(1354);
	LCD_voidWriteSpecialCharacter(p_1,0,5,1);
	LCD_voidWriteSpecialCharacter(p_2,1,4,1);
	return 0;
}

