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
#include "ADC_Config.h"
#include "ADC_Interface.h"
#include "TMR1_Interface.h"
#include "avr/delay.h"

int main()
{
	u16 digitalValue ,Value ,factor;
	DIO_voidSetPinDirection(portD , pin5 ,pin_output);
	TMR1_voidInit();
	ADC_voidInit();
	while(1)
	{
		digitalValue = ADC_voidStartConversion(ADC0 , factor64);   //from 0 to 1023
		factor = ( (2300-800) / (1023-0) );
		Value = (digitalValue*factor) + 800;
		TMR1_voidOCR1A(Value);
		_delay_ms(200);
	}
	return 0;
}



/*equation : y = m*x + b
 * y : value of OCRA1
 * m :slop between digital value(0 to 1023) & max,min position of servo (800 to 2300)
 * b : 0 digital mapped to 800 so this value will be added */
