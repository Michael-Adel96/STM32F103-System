/*
 * main.c
 *
 *  Created on: Jan 11, 2021
 *      Author: Michael Adel
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"

u8 x =0;

void hello(void);

/* Example for testing all STK driver API */
void main(void)
{
	u32 y, z;
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2, RCC_GPIOA_CLK);
	/* Note: STK is a core periphral so, NVIC doesn't need
	 * RCC enable Clock instruction as it connected with the core clock directly */

	GPIO_voidSetPinMode(GPIOA, PIN0, OUTPUT_PUSH_PULL_SPEED_2MHZ);

// Uncomment the below block to test "SetBusyWait" function
/* ====================================================== */
//	STK_voidInit();
//	asm("NOP");
//	STK_voidSetBusyWait(10000000);
//	asm("NOP");
//	STK_voidSetBusyWait(5000000);
//	asm("NOP");
/* ====================================================== */
	STK_voidSetIntervalPeriodic(10000000, hello);


/* used to clarify the operation of GetElapsedTicks and GetRemainingTicks */
/* Important Note: y, z variables must be volatile to not be optimized by compiler */
/* ====================================================== */
	while(1)
	{
		y = STK_u32GetElapsedTicks();
		z = STK_u32GetRemainingTicks();
		if(y >= 5000000 && y <= 5000555)
		{
			asm("NOP");
		}

	}


// this process used to clarify the concept of Asynchronous Delay
/* ====================================================== */
//	while(1)
//	{
//		// this process used to clarify the concept of Asynchronous Delay
//
//		GPIO_voidSetPinValue(GPIOA, PIN0, GPIO_HIGH);
//		for(u16 i = 0; i<50000; i++)
//		{
//			for(u16 j = 0; i<500; i++)
//			{
//				asm("NOP ");
//			}
//		}
//		GPIO_voidSetPinValue(GPIOA, PIN0, GPIO_LOW);
//		for(u16 i = 0; i<50000; i++)
//		{
//			for(u16 j = 0; i<500; i++)
//			{
//				asm("NOP ");
//			}
//		}
//	}
}

void hello(void)
{
	x++;
	if(x == 3)
	{
		STK_voidStopTimer();
		STK_voidSetIntervalSingle(5000000, hello);
	}
	asm("NOP");
}
