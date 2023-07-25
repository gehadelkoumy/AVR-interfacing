
#include"STD_TYPES.h"
#include"BitMath.h"
#include "DIO_Config.h"
#include "DIO_Interface.h"
#include "LCD_Config.h"
#include "LCD_Interface.h"
#include "MOTOR_Config.h"
#include "MOTOR_Interface.h"
#include"avr/delay.h"

int main()
{
	DIO_voidSetPinDirection(portB , pin4 ,pin_input);
	DIO_voidSetPinDirection(portB , pin5 ,pin_input);
	DIO_voidSetPinDirection(portB , pin6 ,pin_input);
	DIO_voidSetPinDirection(portB , pin7 ,pin_input);

	DIO_voidSetPinDirection(portD , pin1 ,pin_output);

	LCD_voidInitialize();
	MOTOR_voidInitialze();
	while(1)
	{
		DIO_voidSetPinValue(portB , pin4 ,pin_high);
		DIO_voidSetPinValue(portB , pin5 ,pin_high);
		DIO_voidSetPinValue(portB , pin6 ,pin_high);
		DIO_voidSetPinValue(portB , pin7 ,pin_high);


		if (DIO_u8GetPinValue(portB ,pin5) == 0)
		{
			MOTOR_voidRotation(Right);
			LCD_voidString("Right");
			_delay_ms(1000);
			LCD_voidClear();
			if(DIO_u8GetPinValue(portB ,pin5) == 1)
			{
				MOTOR_voidRotation(Stop);
			}
		}

		else if (DIO_u8GetPinValue(portB ,pin6) == 0)
		{
			MOTOR_voidRotation(Left);
			LCD_voidString("Left");
			_delay_ms(1000);
			LCD_voidClear();
			if (DIO_u8GetPinValue(portB ,pin6) == 1)
			{
				MOTOR_voidRotation(Stop);
			}
		}

		else if (DIO_u8GetPinValue(portB ,pin7) == 0)
		{
			MOTOR_voidRotation(Stop);
			LCD_voidString("Stop");
			_delay_ms(1000);
			LCD_voidClear();
			if(DIO_u8GetPinValue(portB ,pin7) == 1)
			{
				MOTOR_voidRotation(Stop);
			}
		}

		else if (DIO_u8GetPinValue(portB ,pin4) == 0)
		{
			DIO_voidSetPinValue(portD , pin1 , 1);
			LCD_voidString("LED ON");
			_delay_ms(1000);
			LCD_voidClear();
			if(DIO_u8GetPinValue(portB ,pin4) == 1)
			{
				DIO_voidSetPinValue(portD , pin1 , 0);
			}
		}
	}

return 0;
}


