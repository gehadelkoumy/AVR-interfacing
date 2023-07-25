/*
 * main.c
 *
 *  Created on: Aug 29, 2022
 *      Author: HP
 */

#include "STD_TYPES.h"
#include "BitMath.h"
#include "DIO_Config.h"
#include "DIO_Interface.h"
#include "USART_Config.h"
#include "USART_Interface.h"
#include "ADC_Config.h"
#include "ADC_Interface.h"
#include "avr/delay.h"

int main()
{
	u8 temp , pre_temp = 0;
	u16 Result;

	ADC_voidInit();
	USART_voidInitial();

	_delay_ms(500);
		while(1){
			Result = ADC_voidStartConversion(ADC0 , factor64);
			Result = ((u32)Result*5000)/(u16)1023;         //m-volt
			temp = Result / 10;

			if (temp != pre_temp)
			{
				USART_voidSendNumbers(temp);
				USART_voidSendString("C  ");
			}
			pre_temp = temp;
		}

	return 0;
}
