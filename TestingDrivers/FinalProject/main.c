/*
 * main.c
 *
 *  Created on: Sep 8, 2022
 *      Author: HP
 */

#include "D:\Z\ITI_Embedded training\Drivers\COTS\LIB\STD_TYPES.h"
#include "D:\Z\ITI_Embedded training\Drivers\COTS\LIB\BitMath.h"
#include "D:\Z\ITI_Embedded training\Drivers\COTS\MCAL\DIO\DIO_Config.h"
#include "D:\Z\ITI_Embedded training\Drivers\COTS\MCAL\DIO\DIO_Interface.h"
#include "D:\Z\ITI_Embedded training\Drivers\COTS\HAL\LCD\LCD_Config.h"
#include "D:\Z\ITI_Embedded training\Drivers\COTS\HAL\LCD\LCD_Interface.h"
#include "D:\Z\ITI_Embedded training\Drivers\COTS\MCAL\GIE\GIE_Interface.h"
#include "D:\Z\ITI_Embedded training\Drivers\COTS\MCAL\ADC\ADC_Config.h"
#include "D:\Z\ITI_Embedded training\Drivers\COTS\MCAL\ADC\ADC_Interface.h"
#include "D:\Z\ITI_Embedded training\Drivers\COTS\MCAL\TMR0\TMR0_Config.h"
#include "D:\Z\ITI_Embedded training\Drivers\COTS\MCAL\TMR0\TMR0_Interface.h"
#include "D:\Z\ITI_Embedded training\Drivers\COTS\MCAL\TMR1\TMR1_Config.h"
#include "D:\Z\ITI_Embedded training\Drivers\COTS\MCAL\TMR1\TMR1_Interface.h"
#include "D:\Z\ITI_Embedded training\Drivers\COTS\MCAL\TMR2\TMR2_Config.h"
#include "D:\Z\ITI_Embedded training\Drivers\COTS\MCAL\TMR2\TMR2_Interface.h"

#include "avr/delay.h"

int main()
{
	u16 temp , LDR_OUT , LDR_IN;
	u16 factor , curtain , Room_light;


	ADC_voidInit();
	LCD_voidInitialize();

	EXT_voidGIE_Enable();

	DIO_voidSetPinDirection(portB , pin3 ,pin_output);
	TMR0_voidInit();

	DIO_voidSetPinDirection(portD , pin5 ,pin_output);
	TMR1_voidInit();

	DIO_voidSetPinDirection(portD , pin7 , pin_output);
	TMR2_voidInit();

	_delay_ms(500);

		while(1){
			temp = ADC_voidStartConversion(ADC0 , factor64);
			temp = ( ((u32)temp*5000)/(u16)1023 ) / 10;         //degree

			LCD_voidClear();
			LCD_voidString("Temp = ");
			LCD_voidNumbers(temp);
			LCD_voidString(" C");

			if ((temp >= 20) && (temp <= 25))
			{
				TMR0_voidOCR0(127);
				LCD_voidGoToXY(0,2);
				LCD_voidString("Fan : half speed");
			}

			else if ((temp > 25) && (temp <= 30))
			{
				TMR0_voidOCR0(191);
				LCD_voidGoToXY(0,2);
				LCD_voidString("Fan : 75% speed");
			}

			else if ((temp > 30) && (temp <= 45))   //high temperature
			{
				TMR0_voidOCR0(255);
				LCD_voidGoToXY(0,2);
				LCD_voidString("Fan : full speed");
			}

			else
			{
				TMR0_voidOCR0(0);
				LCD_voidGoToXY(0,2);
				LCD_voidString("Fan OFF");
			}

			_delay_ms(500);

			//----------------------------------------------------------------
			LDR_OUT = ADC_voidStartConversion(ADC1 , factor64);
			factor = ( (2300-800) / (1023-0) );
			curtain = (LDR_OUT*factor) + 800;
			TMR1_voidOCR1A(curtain);
			_delay_ms(200);
			//------------------------------------------------------------------
			/*LDR_IN = ADC_voidStartConversion(ADC2 , factor64);
			factor = ( (255) / (1023) );
			Room_light = (LDR_IN*factor) ;*/

			for (Room_light =0 ; Room_light <= 255 ; Room_light++)
			{
				TMR2_voidOCR2(Room_light);
				_delay_ms(3200);
			}


		}


	return 0;
}






