#ifndef _TMR2_CONFIG_H
#define _TMR2_CONFIG_H



/************************prescaler**********************/
#define TMR2_NO_Prescaler        1
#define TMR2_Prescaler_8         8
#define TMR2_Prescaler_32        32
#define TMR2_Prescaler_64        64
#define TMR2_Prescaler_256       256
#define TMR2_Prescaler_1024      1024

#define CS20     0
#define CS21     1
#define CS22     2

#define TMR2_Prescaler   TMR2_Prescaler_8

/****************************Modes*****************************/
#define Normal               0
#define PhaseCorrectPWM      1
#define CTC                  2
#define FastPWM              3

#define COM20    4
#define COM21    5

#define WGM21     3
#define WGM20     6

#define TOIE2     6
#define OCIE2     7


#define TMR2_Mode   FastPWM

#endif
