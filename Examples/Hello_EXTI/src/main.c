/*
 * main.c
 *
 *  Created on: Mar 18, 2021
 *      Author: DELL
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"

#include "GPIO_private.h"

void hello(void)
{
	GPIO_voidSetPinValue(GPIOA, PIN1, GPIO_HIGH);
}

void main(void)
{
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2, RCC_GPIOA_CLK);
	RCC_voidEnableClock(RCC_APB2, RCC_AFIO_CLK);

	NVIC_voidInit();
	NVIC_voidEnableInterrupt(NVIC_u8EXTI0);
	/* Note: NVIC is a core periphral so, NVIC doesn't need
	 * RCC enable Clock instruction as it connected with the core clock directly */

	GPIO_voidSetPinMode(GPIOA, PIN0,INPUT_PULL_DOWN);

	GPIO_voidSetPinMode(GPIOA, PIN1,OUTPUT_PUSH_PULL_SPEED_2MHZ);
	GPIO_voidSetPinValue(GPIOA, PIN1, GPIO_LOW);

	AFIO_voidEXTILineConfig(EXTI_LINE_0 , EXTI_PORTA_PIN);



	EXTI_voidInit();
	EXTI_voidSetCallBack(EXTI_LINE_0, hello);

	EXTI_voidSetSignalLatch(EXTI_LINE_0, EXTI_RISING_EDGE_TRIGGER);

	EXTI_voidEnableEXTIInt(EXTI_LINE_0);


	while(1)
	{
		asm("NOP");
	}
}

