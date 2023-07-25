#include "STD_TYPES.h"
#include "Private.h"
#include "Config.h"
#include "Interface.h"

//_____________________________________________Port direction__________________________________
void voidSetPortDirection(u8 Copy_u8PortID , u8 Copy_u8PortDirection)
{
	      /*Output Mode*/
	switch(Copy_u8PortID)
	{
		case portA :
		DDRA_REG = Copy_u8PortDirection;
		break;
		
		case portB :
		DDRB_REG = Copy_u8PortDirection;
		break;
		
		case portC :
		DDRC_REG = Copy_u8PortDirection;
		break;
		
		case portD :
		DDRD_REG = Copy_u8PortDirection;
		break;
	}
}

//_______________________________________________Port Value_________________________________________
void voidSevenSegmentDisplay(u8 Copy_u8PortID , u8 Copy_u8PortNumber)
{
	u8 arr[] = {0x3F , 0x06 , 0x5B , 0x4F , 0x66 , 0x6D , 0x7D , 0x07 , 0x7F , 0x6F};
	      /*Output port high or low*/
	switch(Copy_u8PortID)
	{
		case portA :
		PORTA_REG = arr[Copy_u8PortNumber];
		break;
		
		case portB :
		PORTB_REG = arr[Copy_u8PortNumber];
		break;
		
		case portC :
		PORTC_REG = arr[Copy_u8PortNumber];
		break;
		
		case portD :
		PORTD_REG = arr[Copy_u8PortNumber];
		break;
	}
}
