/*
 * main.c
 *
 *  Created on: Aug 25, 2022
 *      Author: HP
 */

#include "STD_TYPES.h"
#include "BitMath.h"
#include "SPI_Private.h"
#include "DIO_Config.h"
#include "DIO_Interface.h"
#include "SPI_Config.h"
#include "SPI_Interface.h"
#include "LCD_Config.h"
#include "LCD_Interface.h"

int main()
{
	u8 data;
	LCD_voidInitialize();
	SPI_voidInitailMaster();
	//data = SPI_u8Tranceiver()

	return 0;
}
