#include "STD_TYPES.h"
#include "BitMath.h"
#include "DIO_Config.h"
#include "DIO_Interface.h"
#include "GIE_Interface.h"
#include "EXT_Private.h"
#include "EXT_Config.h"
#include "EXT_Interface.h"


void EXT_voidInitialize(u8 Copy_u8EXT_ID , u8 Copy_u8SenseMode)
{
	EXT_voidGIE_Enable();       //Enable Global Interrupt
           /*EXT0*/
	if(Copy_u8EXT_ID == EXT0)
	{
		DIO_voidSetPinDirection(portD , pin2 , pin_input);
		DIO_voidSetPinValue(portD , pin2 , pin_high);

        /*PIF sense control*/
		switch(Copy_u8SenseMode)
		{
		case LowLevel :
			ClrBit(MCUCR , pin0);
			ClrBit(MCUCR , pin1);
			break;

		case RisingEdge :
			SetBit(MCUCR , pin0);
			SetBit(MCUCR , pin1);
			break;

		case FallingEdge :
			ClrBit(MCUCR , pin0);
			SetBit(MCUCR , pin1);
			break;

		case AnyLogicalChange :
			SetBit(MCUCR , pin0);
			ClrBit(MCUCR , pin1);
			break;
		}

		SetBit(GICR , pin6);   //General Interrupt control Register
	}

          /*EXT1*/
	else if(Copy_u8EXT_ID == EXT1)
	{
		DIO_voidSetPinDirection(portD , pin3 , pin_input);
		DIO_voidSetPinValue(portD , pin3 , pin_high);

		/*PIF sense control*/
		switch(Copy_u8SenseMode)
		{
		case LowLevel :
			ClrBit(MCUCR , pin2);
			ClrBit(MCUCR , pin3);
			break;

		case RisingEdge :
			SetBit(MCUCR , pin2);
			SetBit(MCUCR , pin3);
			break;

		case FallingEdge :
			ClrBit(MCUCR , pin2);
			SetBit(MCUCR , pin3);
			break;

		case AnyLogicalChange :
			SetBit(MCUCR , pin2);
			ClrBit(MCUCR , pin3);
			break;
		}

		SetBit(GICR , pin7);    //General Interrupt control Register
	}

	         /*EXT2*/
	else if(Copy_u8EXT_ID == EXT2)
	{
		DIO_voidSetPinDirection(portB , pin2 , pin_input);
		DIO_voidSetPinValue(portB , pin2 , pin_high);

		/*PIF sense control*/
		switch(Copy_u8SenseMode)
		{
		case RisingEdge :
			SetBit(MCUCR , pin6);
			break;

		case FallingEdge :
			ClrBit(MCUCR , pin6);
			break;
		}

		SetBit(GICR , pin5);     //General Interrupt control Register
	}

}

void __vector_1()__attribute__((signal));
void __vector_1()
{
	DIO_voidTogglePinValue(portA ,pin0);
}

void __vector_2()__attribute__((signal));
void __vector_2()
{
	//DIO_voidSetPinValue(portA ,pin1 ,pin_high);
	DIO_voidTogglePinValue(portA ,pin1);
}

void __vector_3()__attribute__((signal));
void __vector_3()
{
	//DIO_voidSetPinValue(portA ,pin2 ,pin_high);
	DIO_voidTogglePinValue(portA ,pin2);
}
