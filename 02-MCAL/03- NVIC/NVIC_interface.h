/********************************************/
/* Author	: Michael Adel					*/
/* Version	: V01							*/
/* Date		: 06 Jan. 2021					*/
/********************************************/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H



#define GROUP_BITS_4_SUB_GROUP_BITS_0	0x05FA0300
#define GROUP_BITS_3_SUB_GROUP_BITS_1   0x05FA0400
#define GROUP_BITS_2_SUB_GROUP_BITS_2   0x05FA0500
#define GROUP_BITS_1_SUB_GROUP_BITS_3   0x05FA0600
#define GROUP_BITS_0_SUB_GROUP_BITS_4   0x05FA0700

void NVIC_voidInit(void);
void NVIC_voidEnableInterrupt(u8 copy_u8IntNum);
void NVIC_voidDisableInterrupt(u8 copy_u8IntNum);
void NVIC_voidSetPendingFlag(u8 copy_u8IntNum);
void NVIC_voidClearPendingFlag(u8 copy_u8IntNum);
u8 NVIC_u8GetActiveFlag(u8 copy_u8IntNum);
void NVIC_voidSetInterruptPriority(u8 copy_u8IntNum, u8 copy_u8GroupPriority, u8 copy_u8SubPriority);

#endif