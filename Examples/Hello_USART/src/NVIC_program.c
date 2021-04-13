/********************************************/
/* Author	: Michael Adel					*/
/* Version	: V01							*/
/* Date		: 06 Jan. 2021					*/
/********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"



/***************************************************************************************************/
/* Description: Load from the config file the number of Group and sub priority bits 			   */
/*               and Configure it in SCB                                                           */
/* Input      : Void                                                                               */
/* Output     : Void                                                                  		 	   */
/* Scope      : Public                                                                 			   */
/***************************************************************************************************/
void NVIC_voidInit(void)
{
	#define SCB_AIRCR *((u32 *)0xE000ED0C)
	SCB_AIRCR = PRIORITY_GROUPING_CONTROL;
}

/***************************************************************************************************/
/* Description: Enable Interrupt for a certain periphral        								   */
/* Input      : u8 copy_u8IntNum => Periphral postion number to Enable its interrupt               */
/*                               => Range: 0 -> 59  	                                           */
/*                               => Check PUBLIC DEFINITIONS section for all periphrals definition */
/* Output     : Void                                                                  		 	   */
/* Scope      : Public                                                                 			   */
/***************************************************************************************************/
void NVIC_voidEnableInterrupt(u8 copy_u8IntNum)
{
	if (copy_u8IntNum <= 31)
	{
		NVIC_ISER0 = (1 << copy_u8IntNum);
	}
	else if (copy_u8IntNum <= 59)
	{
		copy_u8IntNum -= 32;
		NVIC_ISER1 = (1 << copy_u8IntNum);
	}
	else
	{
		/* Return Error msg: Wrong Input range */
	}
}

/***************************************************************************************************/
/* Description: Disable Interrupt for a certain periphral        								   */
/* Input      : u8 copy_u8IntNum => Periphral postion number to Disable its interrupt              */
/*                               => Range: 0 -> 59  	                                           */
/*                               => Check PUBLIC DEFINITIONS section for all periphrals definition */
/* Output     : Void                                                                  		 	   */
/* Scope      : Public                                                                 			   */
/***************************************************************************************************/
void NVIC_voidDisableInterrupt(u8 copy_u8IntNum)
{
	if (copy_u8IntNum <= 31)
	{
		NVIC_ICER0 = (1 << copy_u8IntNum);
	}
	else if (copy_u8IntNum <= 59)
	{
		copy_u8IntNum -= 32;
		NVIC_ICER1 = (1 << copy_u8IntNum);
	}
	else
	{
		/* Return Error msg: Wrong Input range */
	}
}

/***************************************************************************************************/
/* Description: Set Interrupt pending flag for a certain periphral        						   */
/* Input      : u8 copy_u8IntNum => Periphral postion number to Set its pending flag               */
/*                               => Range: 0 -> 59  	                                           */
/*                               => Check PUBLIC DEFINITIONS section for all periphrals definition */
/* Output     : Void                                                                  		 	   */
/* Scope      : Public                                                                 			   */
/***************************************************************************************************/
void NVIC_voidSetPendingFlag(u8 copy_u8IntNum)
{
	if (copy_u8IntNum <= 31)
	{
		NVIC_ISPR0 = (1 << copy_u8IntNum);
	}
	else if (copy_u8IntNum <= 59)
	{
		copy_u8IntNum -= 32;
		NVIC_ISPR1 = (1 << copy_u8IntNum);
	}
	else
	{
		/* Return Error msg: Wrong Input range */
	}
}


/***************************************************************************************************/
/* Description: Clear Interrupt pending flag for a certain periphral        					   */
/* Input      : u8 copy_u8IntNum => Periphral postion number to clear its pending flag             */
/*                               => Range: 0 -> 59  	                                           */
/*                               => Check PUBLIC DEFINITIONS section for all periphrals definition */
/* Output     : Void                                                                  		 	   */
/* Scope      : Public                                                                 			   */
/***************************************************************************************************/
void NVIC_voidClearPendingFlag(u8 copy_u8IntNum)
{
	if (copy_u8IntNum <= 31)
	{
		NVIC_ICPR0 = (1 << copy_u8IntNum);
	}
	else if (copy_u8IntNum <= 59)
	{
		copy_u8IntNum -= 32;
		NVIC_ICPR1 = (1 << copy_u8IntNum);
	}
	else
	{
		/* Return Error msg: Wrong Input range */
	}
}

/***************************************************************************************************/
/* Description: Read Interrupt Active flag for a certain periphral        					       */
/* Input      : u8 copy_u8IntNum => Periphral postion number to enabe its interrupt	               */
/*                               => Range: 0 -> 59  	                                           */
/*                               => Check PUBLIC DEFINITIONS section for all periphrals definition */
/* Output     : u8 => Active Flag status                                                           */
/*                 => Range: 0 -> Interrupt not active                               		 	   */
/*                           1 -> Interrupt active                                                 */
/* Scope      : Public                                                                 			   */
/***************************************************************************************************/
u8 NVIC_u8GetActiveFlag(u8 copy_u8IntNum)
{
	u8 u8LocalResult;
	if (copy_u8IntNum <= 31)
	{
		u8LocalResult = GET_BIT(NVIC_IABR0, copy_u8IntNum);
	}
	else if (copy_u8IntNum <= 59)
	{
		copy_u8IntNum -= 32;
		u8LocalResult = GET_BIT(NVIC_IABR1, copy_u8IntNum);
	}
	else
	{
		/* Return Error msg: Wrong Input range */
	}
	return u8LocalResult;
}

/***************************************************************************************************/
/* Description: Set Group and sub group priority                         					       */
/* Input      : u8 copy_u8IntNum => Periphral postion number to enabe its interrupt	               */
/*                               => Range: 0 -> 59  	                                           */
/*                               => Check PUBLIC DEFINITIONS section for all periphrals definition */
/*              u8 copy_u8GroupPriority => Group prioriy                                           */
/*                                      => Range: 0b0000 -> 0b1111                                 */
/*                                      => Check the specified bits for Group                      */
/*                                         priority at NVIC_config.h file                          */
/*              u8 copy_u8SubPriority => Sub Priority                                              */
/*                                    => Range: 0b0000 -> 0b1111                                   */
/*                                    => Check the specified bits for Sub                          */
/*                                       priority at NVIC_config.h file                            */
/* Output     : Void                                                                               */
/* Scope      : Public                                                                 			   */
/***************************************************************************************************/
void NVIC_voidSetInterruptPriority(u8 copy_u8IntNum, u8 copy_u8GroupPriority, u8 copy_u8SubPriority)
{
	u8 u8IntPriority = 0;
#if PRIORITY_GROUPING_CONTROL == GROUP_BITS_4_SUB_GROUP_BITS_0
	if (copy_u8IntNum <= 59 && copy_u8GroupPriority <= 0b1111)
	{
		NVIC_IP[copy_u8IntNum] = (copy_u8GroupPriority << 4);
	}
	else
	{
		/* Return Error Message: Wrong input Range */
	}

#elif PRIORITY_GROUPING_CONTROL == GROUP_BITS_3_SUB_GROUP_BITS_1
	if (copy_u8IntNum <= 59 && copy_u8GroupPriority <= 0b111 && copy_u8SubPriority <= 0b1)
	{
		u8IntPriority = (copy_u8GroupPriority << 1) + (copy_u8SubPriority);
		NVIC_IP[copy_u8IntNum] = (u8IntPriority << 4);
	}
	else
	{
		/* Return Error Message: Wrong input Range */
	}
#elif PRIORITY_GROUPING_CONTROL == GROUP_BITS_2_SUB_GROUP_BITS_2
	if (copy_u8IntNum <= 59 && copy_u8GroupPriority <= 0b11 && copy_u8SubPriority <= 0b11)
	{
		u8IntPriority = (copy_u8GroupPriority << 2) + (copy_u8SubPriority);
		NVIC_IP[copy_u8IntNum] = (u8IntPriority << 4);
	}
	else
	{
		/* Return Error Message: Wrong input Range */
	}
#elif PRIORITY_GROUPING_CONTROL == GROUP_BITS_1_SUB_GROUP_BITS_3
	if (copy_u8IntNum <= 59 && copy_u8GroupPriority <= 0b1 && copy_u8SubPriority <= 0b111)
	{
		u8IntPriority = (copy_u8GroupPriority << 3) + (copy_u8SubPriority);
		NVIC_IP[copy_u8IntNum] = (u8IntPriority << 4);
	}
	else
	{
		/* Return Error Message: Wrong input Range */
	}
#elif PRIORITY_GROUPING_CONTROL == GROUP_BITS_0_SUB_GROUP_BITS_4
	if (copy_u8IntNum <= 59 && copy_u8SubPriority <= 0b1111)
	{
		NVIC_IP[copy_u8IntNum] = (copy_u8SubPriority << 4);
	}
	else
	{
		/* Return Error Message: Wrong input Range */
	}
#endif
}
