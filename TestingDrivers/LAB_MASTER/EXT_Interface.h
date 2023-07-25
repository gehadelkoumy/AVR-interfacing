#ifndef _EXT_INTERFACE_H
#define _EXT_INTERFACE_H

void EXT_voidInitialize(u8 Copy_u8EXT_ID , u8 Copy_u8SenseMode);
void EXT0_SetCallBack(void (*ptr)(void));
void EXT1_SetCallBack(void (*ptr)(void));
void EXT2_SetCallBack(void (*ptr)(void));

#endif
