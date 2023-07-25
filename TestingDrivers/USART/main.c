/*
 * main.c
 *
 *  Created on: Aug 24, 2022
 *      Author: HP
 */

#include "STD_TYPES.h"
#include "BitMath.h"
#include "USART_Private.h"
#include "DIO_Config.h"
#include "DIO_Interface.h"
#include "USART_Config.h"
#include "USART_Interface.h"
#include "LCD_Config.h"
#include "LCD_Interface.h"
#include "Keypad_Config.h"
#include "Keypad_Interface.h"


int main()
{
	//u16 Data;
	//u16 keypadpressed=0;

    USART_voidInitial();

    USART_voidSendNumbers(125);
    //LCD_voidInitialize();
    //KEYPAD_voidInit();

    USART_voidSendString("ali");
    //USART_voidRecieveString("");
    while(1)
    {
    	//LCD_voidClear();
    	//Data = USART_u16RecieveData();
        //LCD_voidWriteData(Data);


    	/*keypadpressed = KEYPAD_voidGetPressedKey();
    	if(keypadpressed != 0xff)
    	{
    		USART_voidSendData(keypadpressed);
    	}*/

    }
	return 0;
}
