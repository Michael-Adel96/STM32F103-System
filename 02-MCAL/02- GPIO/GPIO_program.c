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
	switch(u8CopyPortId)
	{
		case GPIOA: 
			asm("NOP");
			if(u8CopyPinId >= PIN0 && u8CopyPinId <= PIN7)
			{
				GPIOA_CRL &= ~ ((0b1111) << (u8CopyPinId * 4));
				GPIOA_CRL |= ((u8CopyPinMode) << (u8CopyPinId * 4));
			}
			else if(u8CopyPinId >= PIN8 && u8CopyPinId <= PIN15)
			{
				u8CopyPinId = u8CopyPinId - 8;
				GPIOA_CRH &= ~ ((0b1111) << (u8CopyPinId * 4));
				GPIOA_CRH |= ((u8CopyPinMode) << (u8CopyPinId * 4));
			}
			else
			{
				// Return error mesage: Wrong input value range
			}
			break;
		
		case GPIOB:
			if(u8CopyPinId >= PIN0 && u8CopyPinId <= PIN7)
			{
				GPIOB_CRL &= ~ ((0b1111) << (u8CopyPinId * 4));
				GPIOB_CRL |= ((u8CopyPinMode) << (u8CopyPinId * 4));
			}
			else if(u8CopyPinId >= PIN8 && u8CopyPinId <= PIN15)
			{
				u8CopyPinId = u8CopyPinId - 8;
				GPIOB_CRH &= ~ ((0b1111) << (u8CopyPinId * 4));
				GPIOB_CRH |= ((u8CopyPinMode) << (u8CopyPinId * 4));
			}
			else
			{
				// Return error mesage: Wrong input value range
			}
			break;
			break;
		
		case GPIOC:
			if(u8CopyPinId >= PIN0 && u8CopyPinId <= PIN7)
			{
				GPIOC_CRL &= ~ ((0b1111) << (u8CopyPinId * 4));
				GPIOC_CRL |= ((u8CopyPinMode) << (u8CopyPinId * 4));
			}
			else if(u8CopyPinId >= PIN8 && u8CopyPinId <= PIN15)
			{
				u8CopyPinId = u8CopyPinId - 8;
				GPIOC_CRH &= ~ ((0b1111) << (u8CopyPinId * 4));
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
	switch(u8CopyPortId)
	{
		case GPIOA:
			if(u8CopyPinValue == GPIO_LOW)
			{
				CLR_BIT(GPIOA_ODR, u8CopyPinId);
			}
			else if(u8CopyPinValue == GPIO_HIGH)
			{
				SET_BIT(GPIOA_ODR, u8CopyPinId);
			}
			else
			{
				// Return Error message: Wrong input value
			}
			break;
		case GPIOB:
			if(u8CopyPinValue == GPIO_LOW)
			{
				CLR_BIT(GPIOB_ODR, u8CopyPinId);
			}
			else if(u8CopyPinValue == GPIO_HIGH)
			{
				SET_BIT(GPIOB_ODR, u8CopyPinId);
			}
			else
			{
				// Return Error message: Wrong input value
			}
			break;
		case GPIOC:
			if(u8CopyPinValue == GPIO_LOW)
			{
				CLR_BIT(GPIOC_ODR, u8CopyPinId);
			}
			else if(u8CopyPinValue == GPIO_HIGH)
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

u8	 GPIO_u8GetPinValue(u8 u8CopyPortId, u8 u8CopyPinId)
{
	u8 u8PinStatus;
	switch(u8CopyPortId)
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
