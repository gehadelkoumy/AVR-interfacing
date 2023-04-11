#include "STD_TYPES.h"
#include "BitMath.h"
#include "TMR2_Private.h"
#include "DIO_Config.h"
#include "DIO_Interface.h"
#include "TMR2_Config.h"
#include "TMR2_Interface.h"

void (*TMR2_GlobalPtr)(void) = '\0';

void TMR2_SetCallBack(void (*Ptr)(void))
{
	TMR2_GlobalPtr = Ptr;
}

void TMR2_voidInit(void)
{
	/**********************************TMR2 Prescaler******************************/
#if TMR2_Prescaler == TMR2_NO_Prescaler
	SetBit(TCCR2 , CS20);
	ClrBit(TCCR2 , CS21);
	ClrBit(TCCR2 , CS22);
#elif TMR2_Prescaler == TMR2_Prescaler_8
	ClrBit(TCCR2 , CS20);
	SetBit(TCCR2 , CS21);
	ClrBit(TCCR2 , CS22);
#elif TMR2_Prescaler == TMR2_Prescaler_32
	SetBit(TCCR2 , CS20);
	SetBit(TCCR2 , CS21);
	ClrBit(TCCR2 , CS22);
#elif TMR2_Prescaler == TMR2_Prescaler_64
	ClrBit(TCCR2 , CS20);
	ClrBit(TCCR2 , CS21);
	SetBit(TCCR2 , CS22);
#elif TMR2_Prescaler == TMR2_Prescaler_256
	ClrBit(TCCR2 , CS20);
	SetBit(TCCR2 , CS21);
	SetBit(TCCR2 , CS22);
#elif TMR2_Prescaler == TMR2_Prescaler_1024
	SetBit(TCCR2 , CS20);
	SetBit(TCCR2 , CS21);
	SetBit(TCCR2 , CS22);
#endif

/******************************************TMR2 Modes*********************************/
#if TMR2_Mode == Normal
	ClrBit(TCCR2 , WGM21);
	ClrBit(TCCR2 , WGM20);
	/*overflow interrupt enable*/
	SetBit(TIMSK , TOIE2);
#elif TMR2_Mode == PhaseCorrectPWM
	ClrBit(TCCR2 , WGM21);
	SetBit(TCCR2 , WGM20);
	/*************OC0 Compare match*********/
	ClrBit(TCCR2 , COM20);
	SetBit(TCCR2 , COM21);
#elif TMR2_Mode == CTC
	SetBit(TCCR2 , WGM21);
	ClrBit(TCCR2 , WGM20);
	/*************OC0 Compare match*********/
	SetBit(TCCR2 , COM20);
	ClrBit(TCCR2 , COM21);
	/*Output Compare Match Interrupt Enable*/
	SetBit(TIMSK , OCIE2);
#elif TMR2_Mode == FastPWM
	SetBit(TCCR2 , WGM21);
	SetBit(TCCR2 , WGM20);
	/*************OC0 Compare match*********/
	ClrBit(TCCR2 , COM20);
	SetBit(TCCR2 , COM21);
#endif

}

void TMR2_voidOCR2(u16 Copy_u16OCR0Value)
{
	OCR2 = Copy_u16OCR0Value;
}

void TMR2_voidPreload(u16 Copy_u16Value)
{
	TCNT2 = Copy_u16Value;
}


void __vector_5()__attribute__((signal));
void __vector_5()
{
	static u16 count = 0;
	if (count == 3907)
	{
		if(TMR2_GlobalPtr != '\0')
	    {
			TMR2_GlobalPtr();
	        count = 0;
	    }
	}
	else
	{
		count ++;
	}
}

void __vector_4()__attribute__((signal));
void __vector_4()
{
	static u16 count = 0;
	if (count == 4000)
	{
		if(TMR2_GlobalPtr != '\0')
		{
			TMR2_GlobalPtr();
		    count = 0;
		}
	}
	else
	{
		count ++;
	}
}

