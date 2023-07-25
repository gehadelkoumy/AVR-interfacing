#include "STD_TYPES.h"
#include "BitMath.h"
#include "SPI_Private.h"
#include "DIO_Config.h"
#include "DIO_Interface.h"
#include "SPI_Config.h"
#include "SPI_Interface.h"

void SPI_voidInitailMaster(void)
{
	DIO_voidSetPinDirection(portB , pin4 ,pin_input);
	DIO_voidSetPinDirection(portB , pin5 ,pin_output);
	DIO_voidSetPinDirection(portB , pin6 ,pin_input);
	DIO_voidSetPinDirection(portB , pin7 ,pin_output);

	ClrBit(SPCR ,pin7);
	SetBit(SPCR ,pin6);
	ClrBit(SPCR ,pin5);

	SetBit(SPCR ,pin4);

	ClrBit(SPCR ,pin3);
	ClrBit(SPCR ,pin2);

	ClrBit(SPCR ,pin1);
	SetBit(SPCR ,pin0);

	SetBit(SPSR ,pin0);

}

void SPI_voidInitailSlave(void)
{
	DIO_voidSetPinDirection(portB , pin4 ,pin_input);
	DIO_voidSetPinDirection(portB , pin5 ,pin_input);
	DIO_voidSetPinDirection(portB , pin6 ,pin_output);
	DIO_voidSetPinDirection(portB , pin7 ,pin_input);

	ClrBit(SPCR ,pin7);
	SetBit(SPCR ,pin6);
	ClrBit(SPCR ,pin5);

	ClrBit(SPCR ,pin4);

	ClrBit(SPCR ,pin3);
	ClrBit(SPCR ,pin2);

	ClrBit(SPCR ,pin1);
	SetBit(SPCR ,pin0);

	SetBit(SPSR ,pin0);
}


u8 SPI_u8Transceiver(u8 Copy_u8Data)
{
	SPDR = Copy_u8Data;
	while(GetBit(SPSR , SPIF) == 0);
	return SPDR;
}

