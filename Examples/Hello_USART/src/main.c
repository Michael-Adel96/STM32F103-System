

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "NVIC_interface.h"
#include "USART_interface.h"
#include "USART_private.h"
#include "GPIO_interface.h"

volatile u16 recievedChar;

/* Used in testing interrupt method of receiving a character */
void readCharRecieved(u16 x)
{
	recievedChar = x;
	if(recievedChar == '5')
	{
		asm("NOP");
	}

}

volatile u8 buffer[30];
void main(void)
{

	 RCC_voidInitSysClock();
	 RCC_voidEnableClock(RCC_APB2, RCC_GPIOA_CLK);
	 RCC_voidEnableClock(RCC_APB2, RCC_USART1_CLK);

	 NVIC_voidInit();
	 NVIC_voidEnableInterrupt(NVIC_u8USART1);
	 GPIO_voidSetPinMode(GPIOA, PIN9, AF_OUTPUT_PUSH_PULL_SPEED_50MHZ);
	 GPIO_voidSetPinMode(GPIOA, PIN10, INPUT_FLOATING);


	 USART_voidInit();
	 USART_voidSetCallBack(USART_Channel_1, readCharRecieved);
	 USART_u16AsynchronousDMAReceive(USART_Channel_1, buffer, 30);
	 u8 x = 0;

//	 USART_voidSendString(USART_Channel_1, "123456");

	while(1)
	{
//		USART_voidSendCharacter(USART_Channel_1,'B');
//		x = USART_u16ReceiveCharacter(USART_Channel_1);
//		if(x == '5')
//		{
//			asm("NOP");
//		}
//		if(x == 'r')
//		{
//			asm("NOP");
//
//		}
		if (buffer[29] == '5')
		{
			asm("NOP");
		}

		asm("NOP");
	}

}


