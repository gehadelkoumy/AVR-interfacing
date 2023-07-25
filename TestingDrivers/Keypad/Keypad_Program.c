#include "STD_TYPES.h"
#include "BitMath.h"
#include "DIO_Config.h"
#include "DIO_Interface.h"
#include "Keypad_Config.h"
#include "Keypad_Interface.h"
#include "avr/delay.h"

void KEYPAD_voidInit(void)
{
	DIO_voidSetPortDirection(KYP_port,0x0f);
	DIO_voidSetPortValue(KYP_port,0xff);
}

u8 KEYPAD_voidGetPressedKey(void)
{
	u8 Local_u8SwValue[4][4] = {{1,2,3,4},
		                        {5,6,7,8},
								{9,10,11,12},
	                            {13,14,15,16}};
	u8 Local_u8KeyState = 0xff;
	u8 Local_u8CheckPressed = 1;
	//DIO_voidSetPortDirection(KYP_port,0x0f);
	//DIO_voidSetPortValue(KYP_port,0xff);
	
	u8 Copy_u8Col , Copy_u8Row;
	for(Copy_u8Col = Col_Start ; Copy_u8Col <= Col_End ; Copy_u8Col++)
	{
		DIO_voidSetPinValue(KYP_port , Copy_u8Col , pin_low);     //activate
		for(Copy_u8Row = Row_Start ; Copy_u8Row <= Row_End ; Copy_u8Row++)
		{
			Local_u8CheckPressed = DIO_u8GetPinValue(KYP_port , Copy_u8Row);
			if(Local_u8CheckPressed == 0)
			{
				Local_u8KeyState = Local_u8SwValue[Copy_u8Row-Row_Start][Copy_u8Col];
				while(Local_u8CheckPressed == 0)
				{
					Local_u8CheckPressed = DIO_u8GetPinValue(KYP_port , Copy_u8Row);
				}
				_delay_ms(50);
				return Local_u8KeyState;
			}
		}
		DIO_voidSetPinValue(KYP_port , Copy_u8Col , pin_high);    //deactivate
	}
	return Local_u8KeyState;
}
