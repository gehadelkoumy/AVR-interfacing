/*
 * main.c
 *
 *  Created on: Aug 28, 2022
 *      Author: HP
 */

#include "STD_TYPES.h"
#include "BitMath.h"
#include "DIO_Config.h"
#include "DIO_Interface.h"
#include "SPI_Config.h"
#include "SPI_Interface.h"
#include "LCD_Config.h"
#include "LCD_Interface.h"

int main()
{
	u8 data;
	SPI_voidInitailSlave();

	LCD_voidInitialize();

	data = SPI_u8Transceiver('a');
	LCD_voidWriteData(data);

	while(1);
	return 0;
}
