#include "STD_TYPES.h"
#include "BitMath.h"
#include "DIO_Config.h"
#include "DIO_Interface.h"

int main()
{
	//DIO_voidSetPinDirection(portA , pin0 ,1);
	//DIO_voidSetPinValue(portA , pin0 , 1);
	DIO_voidSetPortDirection(portA , 0xff);
	DIO_voidSetPortValue(portA , 0xff);
	return 0;
}
