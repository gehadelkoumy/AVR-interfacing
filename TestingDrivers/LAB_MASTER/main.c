/*
 * main.c
 *
 *  Created on: Aug 28, 2022
 *      Author: HP
 */
#include "STD_TYPES.h"
#include "BitMath.h"
#include "SPI_Private.h"
#include "DIO_Config.h"
#include "DIO_Interface.h"
#include "SPI_Config.h"
#include "SPI_Interface.h"
#include "EXT_Config.h"
#include "EXT_Interface.h"
#include "GIE_Interface.h"

void Slave_1(void)
{      //ISR
	u8 data_1;

	DIO_voidSetPinValue(portB ,pin0 ,pin_low);   //select slave_1
	DIO_voidSetPinValue(portB ,pin1 ,pin_high);

	data_1 = SPI_u8Transceiver('a');
}

void Slave_2(void)
{      //ISR
	u8 data_2;

	DIO_voidSetPinValue(portB ,pin0 ,pin_high);   //select slave_2
	DIO_voidSetPinValue(portB ,pin1 ,pin_low);

	data_2 = SPI_u8Transceiver('b');

}

int main()
{
	SPI_voidInitailMaster();

	EXT_voidGIE_Enable();
	EXT_voidInitialize(EXT0 , FallingEdge);
	EXT_voidInitialize(EXT1 , FallingEdge);

	/*for slave select*/
	DIO_voidSetPinDirection(portB ,pin0 ,pin_output);
	DIO_voidSetPinDirection(portB ,pin1 ,pin_output);
	DIO_voidSetPinValue(portB ,pin0 ,pin_high);
	DIO_voidSetPinValue(portB ,pin1 ,pin_high);

	/*calling interrupt*/
	EXT0_SetCallBack(Slave_1);
	EXT1_SetCallBack(Slave_2);

	while(1);

	return 0;
}

