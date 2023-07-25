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
#include "TMR0_Config.h"
#include "TMR0_Interface.h"
#include "TMR1_Config.h"
#include "TMR1_Interface.h"
#include "LCD_Config.h"
#include "LCD_Interface.h"
#include "avr/delay.h"

u16 snap1 , snap2 , snap3 , flag = 0 ;

void TMR1_ISR(void)
{      //ISR
	if (flag == 0)
	{
		snap1 = TMR1_u16ICR1();
        TMR1_voidICU_EdgeSelect(FallingEdge);
		flag = 1;
	}
	else if(flag == 1)
	{
		snap2 = TMR1_u16ICR1();
		TMR1_voidICU_EdgeSelect(RisingEdge);
		flag = 2;
	}
	else if(flag == 2)
	{
		snap3 = TMR1_u16ICR1();
        flag = 3;
        //EXT_voidGIE_Disable();
	}
}

int main()
{
	LCD_voidInitialize();

	//OC0 PWM timer0
	DIO_voidSetPinDirection(portB ,pin3 ,pin_output);
	TMR0_voidInit();
	TMR0_voidOCR0(150);

	EXT_voidGIE_Enable();

	//sense edge timer1
	DIO_voidSetPinDirection(portD ,pin6 ,pin_input);
	TMR1_voidInit();
	TMR1_voidICU_EdgeSelect(RisingEdge);
	TMR1_SetCallBack(TMR1_ISR);

	u32 Ton , Ttot , Toff;

	while(1)
	{
		if(flag == 3)
		{
			Ton = snap2 - snap1;
			Ttot = snap3 - snap1;
			Toff = Ttot - Ton;

			//LCD_voidClear();
			LCD_voidGoToXY(0,1);
			LCD_voidNumbers(Ton);
			LCD_voidGoToXY(0,2);
			LCD_voidNumbers(Toff);
			_delay_ms(500);

			flag = 0;
		}
	}
	return 0 ;
}
