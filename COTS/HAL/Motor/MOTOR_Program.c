#include "STD_TYPES.h"
#include "BitMath.h"
#include "DIO_Config.h"
#include "DIO_Interface.h"
#include "MOTOR_Config.h"
#include "MOTOR_Interface.h"
#include "avr/delay.h"


void MOTOR_voidInitialze(void)
{
	DIO_voidSetPinDirection(MOTOR_port , MOTOR_pin1 ,pin_high);
	DIO_voidSetPinDirection(MOTOR_port , MOTOR_pin2 ,pin_high);
}

void MOTOR_voidRotation(u8 Copy_u8Direction)
{
	DIO_voidSetPortValue(MOTOR_port , Copy_u8Direction);
}