#include "STD_TYPES.h"
#include "BitMath.h"
#include "WDT_Private.h"
#include "DIO_Config.h"
#include "DIO_Interface.h"
#include "WDT_Config.h"
#include "WDT_Interface.h"

void WDT_voidWDT_Enable(void)
{
	SetBit(WDTCR , WDE);
}

void WDT_voidWDT_Sleep(void)
{
	/*time out 32.5 ms*/
	SetBit(WDTCR , WDP0);
	ClrBit(WDTCR , WDP1);
	ClrBit(WDTCR , WDP2);
}

void WDT_voidWDT_Disable(void)
{
	WDTCR = (1<<WDTOE) | (1<<WDE);
	WDTCR = 0x00;
}
