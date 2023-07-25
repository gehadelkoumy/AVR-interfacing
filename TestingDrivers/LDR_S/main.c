/*
 * main.c
 *
 *  Created on: Aug 19, 2022
 *      Author: HP
 */
#include "STD_TYPES.h"
#include "BitMath.h"
#include "DIO_Config.h"
#include "DIO_Interface.h"
#include "ADC_Config.h"
#include "ADC_Interface.h"
#include "LCD_Interface.h"
#include "util/delay.h"

int main(){
	u16 LDR;
	ADC_voidInit();
	LCD_voidInitialize();

	while(1){
		LCD_voidClear();
		LDR = ADC_voidStartConversion(ADC1 , factor64);
		LDR = ((u32)LDR*5000)/(u16)1023;
		LCD_voidString("Volt = ");
		LCD_voidNumbers(LDR);
		LCD_voidString(" mV");
		_delay_ms(600);
	}

	return 0;
}


