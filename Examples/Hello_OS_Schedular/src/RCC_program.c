/********************************************/
/* Author	: Michael Adel					*/
/* Version	: V01							*/
/* Date		: 13 Nov. 2020					*/
/********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_voidInitSysClock(void)
{
	#if RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
		/* Enable HSE clock with no bypass */
		RCC_CR   = 0x00010000;
		RCC_CFGR = 0x00000001;
	#elif RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
		/* Enable HSE clock with bypass */
		RCC_CR   = 0x00050000;
		RCC_CFGR = 0x00000001;
	#elif RCC_CLOCK_TYPE == RCC_HSI
		/* Enable HSI clock withot trimming */
		RCC_CR   = 0x00000081;
		RCC_CFGR = 0x00000000;
	#elif RCC_CLOCK_TYPE == RCC_PLL
		/* Development section */
		#if RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2	
		
		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2	
		
		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE	
		/* Development section end*/
		#endif
	#else
		#error("You chosed Wrong Clock Type");
	#endif
}


void RCC_voidEnableClock(u8 copy_u8BusId, u8 copy_u8PerId)
{
	
	if (copy_u8PerId <= 31)
	{
		switch (copy_u8BusId)
		{
			case RCC_AHB : SET_BIT(RCC_AHBENR, copy_u8PerId);  break;
			case RCC_APB1: SET_BIT(RCC_APB1ENR, copy_u8PerId); break;
			case RCC_APB2: SET_BIT(RCC_APB2ENR, copy_u8PerId); break;
		  //default		 : /* return error*/	 			   break;
		}
	}
	else
	{
		/* Return Error*/
	}
	
}

void RCC_voidDisableClock(u8 copy_u8BusId, u8 copy_u8PerId)
{
	
	if (copy_u8PerId <= 31)
	{
		switch (copy_u8BusId)
		{
			case RCC_AHB : CLR_BIT(RCC_AHBENR, copy_u8PerId);  break;
			case RCC_APB1: CLR_BIT(RCC_APB1ENR, copy_u8PerId); break;
			case RCC_APB2: CLR_BIT(RCC_APB2ENR, copy_u8PerId); break;
		  //default		 : /* return error*/	 			   break;
		}
	}
	else
	{
		/* Return Error*/
	}
	
}
