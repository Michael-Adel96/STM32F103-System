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
#include "OS_schedular_interface.h"


void Led1(void)
{
	static u8 LedState = 0;
	TOG_BIT(LedState, 0);
	GPIO_voidSetPinValue(GPIOA, PIN0, LedState);
	static u8 count = 0;
	count++;
	if(count == 5)
	{
		OS_voidResumeTask(1);
	}

}

void Led2(void)
{
	static u8 LedState = 0;
	static u8 count = 0;
	count++;
	if(count == 2)
	{
		//OS_voidSuspendTask(1);
		OS_voidDeleteTask(1);
	}
	TOG_BIT(LedState, 0);
	GPIO_voidSetPinValue(GPIOA, PIN1, LedState);
}
void Led3(void)
{
	static u8 LedState = 0;
	TOG_BIT(LedState, 0);
	GPIO_voidSetPinValue(GPIOA, PIN2, LedState);
}
void main(void)
{
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2, RCC_GPIOA_CLK);

	STK_voidInit();
	GPIO_voidSetPinMode(GPIOA, PIN0, OUTPUT_PUSH_PULL_SPEED_50MHZ);
	GPIO_voidSetPinMode(GPIOA, PIN1, OUTPUT_PUSH_PULL_SPEED_50MHZ);
	GPIO_voidSetPinMode(GPIOA, PIN2, OUTPUT_PUSH_PULL_SPEED_50MHZ);
	GPIO_voidSetPinMode(GPIOA, PIN3, OUTPUT_PUSH_PULL_SPEED_50MHZ);

	GPIO_voidSetPinValue(GPIOA, PIN0, GPIO_LOW);
	GPIO_voidSetPinValue(GPIOA, PIN1, GPIO_LOW);
	GPIO_voidSetPinValue(GPIOA, PIN2, GPIO_LOW);

	OS_voidCreateTask(0, 4000, Led1, 0);
	OS_voidCreateTask(1, 5000, Led2, 0);
	OS_voidCreateTask(2, 10000, Led3, 0);

	OS_voidStartOS();



	while(1)
	{
		asm("NOP");
	}
}

