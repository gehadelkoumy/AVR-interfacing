/*
 * main.c
 *
 *  Created on: Aug 17, 2022
 *      Author: HP
 */
#include "STD_TYPES.h"
#include "BitMath.h"
#include "DIO_Config.h"
#include "DIO_Interface.h"
#include"avr/delay.h"

int main(){
	/*DIO_voidSetPinDirection(portB , pin0 , pin_output);
	DIO_voidSetPinDirection(portB , pin1 , pin_output);
	DIO_voidSetPinDirection(portB , pin2 , pin_output);
	DIO_voidSetPinDirection(portB , pin3 , pin_output);*/
	DIO_voidSetPortDirection(portB , 0x0F);

	while(1)
	{
		/*DIO_voidSetPinValue(portB , pin0 , pin_high);
		_delay_ms(10);
		DIO_voidSetPinValue(portB , pin1 , pin_low);
		_delay_ms(10);
		DIO_voidSetPinValue(portB , pin2 , pin_low);
		_delay_ms(10);
		DIO_voidSetPinValue(portB , pin3 , pin_low);
		_delay_ms(1000);

		DIO_voidSetPinValue(portB , pin0 , pin_low);
		_delay_ms(10);
		DIO_voidSetPinValue(portB , pin1 , pin_high);
		_delay_ms(10);
		DIO_voidSetPinValue(portB , pin2 , pin_low);
		_delay_ms(10);
		DIO_voidSetPinValue(portB , pin3 , pin_low);
		_delay_ms(1000);

		DIO_voidSetPinValue(portB , pin0 , pin_low);
		_delay_ms(10);
		DIO_voidSetPinValue(portB , pin1 , pin_low);
		_delay_ms(10);
		DIO_voidSetPinValue(portB , pin2 , pin_high);
		_delay_ms(10);
		DIO_voidSetPinValue(portB , pin3 , pin_low);
		_delay_ms(1000);

		DIO_voidSetPinValue(portB , pin0 , pin_low);
		_delay_ms(10);
		DIO_voidSetPinValue(portB , pin1 , pin_low);
		_delay_ms(10);
		DIO_voidSetPinValue(portB , pin2 , pin_low);
		_delay_ms(10);
		DIO_voidSetPinValue(portB , pin3 , pin_high);
		_delay_ms(1000);*/

		DIO_voidSetPortValue(portB , 0b00000000);
		_delay_ms(500);
		DIO_voidSetPortValue(portB , 0b00000001);
		_delay_ms(500);
		DIO_voidSetPortValue(portB , 0b00000010);
		_delay_ms(500);
		DIO_voidSetPortValue(portB , 0b00000100);
		_delay_ms(500);
		DIO_voidSetPortValue(portB , 0b00001000);
		_delay_ms(500);



	}

	return 0;
}

