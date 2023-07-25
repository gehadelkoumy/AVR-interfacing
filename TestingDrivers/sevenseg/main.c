#include "STD_TYPES.h"
#include "Config.h"
#include "Interface.h"
#include "util/delay.h"

int main()
{
	u8 i;
	voidSetPortDirection(portA , 0xff);
	while(1)
	{
		//portA
		for(i = 0 ; i<10 ; i++)
		{
			voidSevenSegmentDisplay(portA , i);
			_delay_ms(500);
		}

	}
		return 0;
}









/*voidSetPortDirection(portA , 0x00);
        //portB
		voidSetPortDirection(portB , 0xff);
	    for(i = 0 ; i<10 ; i++)
		{
			voidSevenSegmentDisplay(portB , i);
			_delay_ms(500);
		}
	    voidSetPortDirection(portB , 0x00);
        //portC
	    voidSetPortDirection(portC , 0xff);
	    for(i = 0 ; i<10 ; i++)
	    {
	    	voidSevenSegmentDisplay(portC , i);
	    	_delay_ms(500);
	    }
	    voidSetPortDirection(portC , 0x00);
        //portD
	    voidSetPortDirection(portD , 0xff);
	    for(i = 0 ; i<10 ; i++)
	    {
	    	voidSevenSegmentDisplay(portD , i);
	    	_delay_ms(500);
	    }
	    voidSetPortDirection(portD , 0x00);
	}*/



