#include "STD_TYPES.h"
#include "BitMath.h"
#include "TMR1_Private.h"
#include "DIO_Config.h"
#include "DIO_Interface.h"
#include "TMR1_Interface.h"

void TMR1_voidInit(void)
{
	ClrBit(TCCR1A , 4);
	SetBit(TCCR1A , 5);
	ClrBit(TCCR1A , 6);
	SetBit(TCCR1A , 7);

	/*prescaler*/
	ClrBit(TCCR1B , 0);
	SetBit(TCCR1B , 1);
	ClrBit(TCCR1B , 2);

	/*fast PWM*/
	ClrBit(TCCR1A , 0);
	SetBit(TCCR1A , 1);

	SetBit(TCCR1B , 3);
	SetBit(TCCR1B , 4);

	ICR1 = 20000;    //for servo motor
}


void TMR1_voidOCR1A(u16 Copy_u16OCR1AValue)
{
	OCR1A = Copy_u16OCR1AValue;
}
