/*
 * main.c
 *
 *  Created on: Aug 23, 2022
 *      Author: HP
 */
#include "STD_TYPES.h"
#include "BitMath.h"
#include "DIO_Config.h"
#include "DIO_Interface.h"
#include "GIE_Interface.h"
#include "EXT_Config.h"
#include "EXT_Interface.h"
#include "TMR0_Config.h"
#include "TMR0_Interface.h"
#include "TMR2_Config.h"
#include "TMR2_Interface.h"
#include "LCD_Config.h"
#include "LCD_Interface.h"
#include "avr/delay.h"

u8  Ton , Toff , flag = 0 , overflow = 0;

void ovf(void)
{
	overflow++;
}

void ISR0(void)
{      //ISR
	if (flag == 0)
	{
		TMR0_voidPreload(0);
		EXT_voidInitialize(EXT0 , FallingEdge);
		flag = 1;
	}
	else if(flag == 1)
	{
		Ton = TMR0_count() + overflow*256;
		overflow = 0;
		TMR0_voidPreload(0);
		EXT_voidInitialize(EXT0 , RisingEdge);
		flag = 2;
	}
	else if(flag == 2)
	{
		Toff = TMR0_count() + overflow*256;
		overflow = 0;
		TMR0_voidPreload(0);
		flag = 3;
	}
}

int main()
{
	LCD_voidInitialize();

	//OC2 PWM Pulse
	DIO_voidSetPinDirection(portD , pin7 ,pin_output);
	TMR2_voidInit();
	TMR2_voidOCR2(127);

	//count Ton & Toff
	TMR0_voidInit();
	TMR0_SetCallBack(ovf);

	EXT_voidGIE_Enable();

	//Add PWM to external interrupt
	EXT_voidInitialize(EXT0 , RisingEdge);
	EXT0_SetCallBack(ISR0);

	u16 dutyCycle , freq , Ttotal;
	while(1){
		if (flag == 3)
		{
            Ttotal = (Ton + Toff);
			dutyCycle = Ton / Ttotal;
			freq = 1 / Ttotal;

			//LCD_voidClear();
			LCD_voidGoToXY(0,1);
			LCD_voidNumbers(Ton);
			LCD_voidGoToXY(0,2);
			LCD_voidNumbers(Toff);
			_delay_ms(500);

			flag = 0;
		}
	}

	return 0;
}

