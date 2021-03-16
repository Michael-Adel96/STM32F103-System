/********************************************/
/* Author	: Michael Adel					*/
/* Version	: V01							*/
/* Date		: 25 Nov. 2020					*/
/********************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

void GPIO_voidSetPinMode(u8 u8CopyPortId, u8 u8CopyPinId, u8 u8CopyPinMode)
{
	switch (u8CopyPortId)
	{
	case GPIOA:
		asm("NOP");
		if (u8CopyPinId >= PIN0 && u8CopyPinId <= PIN7)
		{
			GPIOA_CRL &= ~((0b1111) << (u8CopyPinId * 4));
			GPIOA_CRL |= ((u8CopyPinMode) << (u8CopyPinId * 4));
		}
		else if (u8CopyPinId >= PIN8 && u8CopyPinId <= PIN15)
		{
			u8CopyPinId = u8CopyPinId - 8;
			GPIOA_CRH &= ~((0b1111) << (u8CopyPinId * 4));
			GPIOA_CRH |= ((u8CopyPinMode) << (u8CopyPinId * 4));
		}
		else
		{
			// Return error mesage: Wrong input value range
		}
		break;

	case GPIOB:
		if (u8CopyPinId >= PIN0 && u8CopyPinId <= PIN7)
		{
			GPIOB_CRL &= ~((0b1111) << (u8CopyPinId * 4));
			GPIOB_CRL |= ((u8CopyPinMode) << (u8CopyPinId * 4));
		}
		else if (u8CopyPinId >= PIN8 && u8CopyPinId <= PIN15)
		{
			u8CopyPinId = u8CopyPinId - 8;
			GPIOB_CRH &= ~((0b1111) << (u8CopyPinId * 4));
			GPIOB_CRH |= ((u8CopyPinMode) << (u8CopyPinId * 4));
		}
		else
		{
			// Return error mesage: Wrong input value range
		}
		break;
		break;

	case GPIOC:
		if (u8CopyPinId >= PIN0 && u8CopyPinId <= PIN7)
		{
			GPIOC_CRL &= ~((0b1111) << (u8CopyPinId * 4));
			GPIOC_CRL |= ((u8CopyPinMode) << (u8CopyPinId * 4));
		}
		else if (u8CopyPinId >= PIN8 && u8CopyPinId <= PIN15)
		{
			u8CopyPinId = u8CopyPinId - 8;
			GPIOC_CRH &= ~((0b1111) << (u8CopyPinId * 4));
			GPIOC_CRH |= ((u8CopyPinMode) << (u8CopyPinId * 4));
		}
		else
		{
			// Return error mesage: Wrong input value range
		}
		break;
		break;

	default:
		// Return error mesage: Wrong input value range
		break;
	}
}

void GPIO_voidSetPinValue(u8 u8CopyPortId, u8 u8CopyPinId, u8 u8CopyPinValue)
{
	switch (u8CopyPortId)
	{
	case GPIOA:
		if (u8CopyPinValue == GPIO_LOW)
		{
			CLR_BIT(GPIOA_ODR, u8CopyPinId);
		}
		else if (u8CopyPinValue == GPIO_HIGH)
		{
			SET_BIT(GPIOA_ODR, u8CopyPinId);
		}
		else
		{
			// Return Error message: Wrong input value
		}
		break;
	case GPIOB:
		if (u8CopyPinValue == GPIO_LOW)
		{
			CLR_BIT(GPIOB_ODR, u8CopyPinId);
		}
		else if (u8CopyPinValue == GPIO_HIGH)
		{
			SET_BIT(GPIOB_ODR, u8CopyPinId);
		}
		else
		{
			// Return Error message: Wrong input value
		}
		break;
	case GPIOC:
		if (u8CopyPinValue == GPIO_LOW)
		{
			CLR_BIT(GPIOC_ODR, u8CopyPinId);
		}
		else if (u8CopyPinValue == GPIO_HIGH)
		{
			SET_BIT(GPIOC_ODR, u8CopyPinId);
		}
		else
		{
			// Return Error message: Wrong input value
		}
		break;
	default:
		// Return Error message: Wrong input value
		break;
	}
}

u8 GPIO_u8GetPinValue(u8 u8CopyPortId, u8 u8CopyPinId)
{
	u8 u8PinStatus;
	switch (u8CopyPortId)
	{
	case GPIOA:
		u8PinStatus = GET_BIT(GPIOA_IDR, u8CopyPinId);
		break;
	case GPIOB:
		u8PinStatus = GET_BIT(GPIOB_IDR, u8CopyPinId);
		break;
	case GPIOC:
		u8PinStatus = GET_BIT(GPIOC_IDR, u8CopyPinId);
		break;
	default:
		// Return Error message: Wrong input value
		break;
	}
	return u8PinStatus;
}

/****************************************************************************************************/
/* Description: Configure a certain EXTI Line with the selected port line.						   	*/
/* Input      : u8 u8CopyEXTILine => choose EXTI line number                                     	*/
/*                                => Range: EXTI_LINE_x, x: 0 to 15                               	*/
/*              u8 u8CopyEXTIPort => choose which port pin to be mapped for a certain EXTI line.	*/
/*                                      => Range: EXTI_PORTA_PIN,		                        	*/
/*                                                EXTI_PORTB_PIN,                       			*/
/*                                                EXTI_PORTC_PIN                          			*/
/* Note 	  : RCC_AFIO_CLK must be Enabled before calling this function.				 			*/
/* Output     : Void                                                                               	*/
/* Scope      : Public                                                                             	*/
/****************************************************************************************************/
void AFIO_voidEXTILineConfig(u8 u8CopyEXTILine, u8 u8CopyEXTIPort)
{
	u8 u8Local_temp;
	if (u8CopyEXTILine <= EXTI_LINE_3)
	{
		u8Local_temp = u8CopyEXTILine;
		AFIO_EXTICR1 = (AFIO_EXTICR1 & ~(0b1111 << (u8Local_temp * 4))) | (u8CopyEXTIPort << (u8Local_temp * 4));
	}
	else if (u8CopyEXTILine <= EXTI_LINE_7)
	{
		u8Local_temp = u8CopyEXTILine - 4;
		AFIO_EXTICR2 = (AFIO_EXTICR2 & ~(0b1111 << (u8Local_temp * 4))) | (u8CopyEXTIPort << (u8Local_temp * 4));
	}
	else if (u8CopyEXTILine <= EXTI_LINE_11)
	{
		u8Local_temp = u8CopyEXTILine - 8;
		AFIO_EXTICR3 = (AFIO_EXTICR3 & ~(0b1111 << (u8Local_temp * 4))) | (u8CopyEXTIPort << (u8Local_temp * 4));
	}
	else if (u8CopyEXTILine <= EXTI_LINE_15)
	{
		u8Local_temp = u8CopyEXTILine - 12;
		AFIO_EXTICR4 = (AFIO_EXTICR4 & ~(0b1111 << (u8Local_temp * 4))) | (u8CopyEXTIPort << (u8Local_temp * 4));
	}
	else
	{
		// Return Error message: Wrong input value
	}
}