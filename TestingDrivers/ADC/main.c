/*
 * main.c
 *
 *  Created on: Aug 18, 2022
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
	u16 Result , Temp , LDR;
	ADC_voidInit();
	LCD_voidInitialize();

	while(1){
		LCD_voidClear();
		/*Result = ADC_voidStartConversion(ADC0 , factor64);
		Temp = ((u32)Result*5000)/(u16)1023;      //m-volt
		Temp /= 10;
		LCD_voidGoToXY(0,1);
		LCD_voidString("Temp = ");
		LCD_voidNumbers(Temp);
		LCD_voidString(" C");*/

		LDR = ADC_voidStartConversion(ADC1 , factor64);
		//LDR = ((u32)LDR*5000)/(u16)1023;
		//LCD_voidGoToXY(0,2);
		LCD_voidString("Volt = ");
		LCD_voidNumbers(LDR);
		//LCD_voidString(" mV");
		_delay_ms(500);
	}
	return 0;
}
