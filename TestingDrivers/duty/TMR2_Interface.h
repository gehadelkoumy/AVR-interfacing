#ifndef _TMR2_INTERFACE_H
#define _TMR2_INTERFACE_H

void TMR2_voidInit(void);
void TMR2_voidPreload(u16 Copy_u16Value);
void TMR2_SetCallBack(void (*Ptr)(void));
void TMR2_voidOCR2(u16 Copy_u16OCR0Value);

#endif
