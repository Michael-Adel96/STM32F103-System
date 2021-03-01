/********************************************/
/* Author	: Michael Adel					*/
/* Version	: V01							*/
/* Date		: 06 Jan. 2021					*/
/********************************************/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

/****************************************************************/
/******************* PUBLIC DEFINITIONS *************************/
/****************************************************************/

/* Periphrals postion number */
#define NVIC_u8WWDG						0			//Window Watchdog Interrupt
#define NVIC_u8PVD						1			//PVD Through EXTI Line Detection Interrupt
#define NVIC_u8TAMPER					2			//Tamper Interrupt
#define NVIC_u8RTC						3			//RTC
#define NVIC_u8FLASH					4			//Flash
#define NVIC_u8RCC						5			//RCC
#define NVIC_u8EXTI0					6			//EXTI0
#define NVIC_u8EXTI1					7			//EXTI1
#define NVIC_u8EXTI2					8			//EXTI2
#define NVIC_u8EXTI3					9			//EXTI3
#define NVIC_u8EXTI4					10			//EXTI4
#define NVIC_u8DMA1_CHANNEL1			11			//DMA Channel1
#define NVIC_u8DMA1_CHANNEL2			12			//DMA Channel2
#define NVIC_u8DMA1_CHANNEL3			13			//DMA Channel3
#define NVIC_u8DMA1_CHANNEL4			14			//DMA Channel4
#define NVIC_u8DMA1_CHANNEL5			15			//DMA Channel5
#define NVIC_u8DMA1_CHANNEL6			16			//DMA Channel6
#define NVIC_u8DMA1_CHANNEL7			17			//DMA Channel7
#define NVIC_u8ADC1_2					18			//ADC1 and ADC2
#define NVIC_u8USB_HP_CAN_TX			19			//USB High Priority or CAN TX interrupt
#define NVIC_u8USB_LP_CAN_RX0			20			//USB Low Priority or CAN RX0 interrupt
#define NVIC_u8CAN_RX1					21			//CAN RX1
#define NVIC_u8CAN_SCE					22			//CAN SCE
#define NVIC_u8EXTI9_5					23			//EXTI5 to EXTI9
#define NVIC_u8TIM1_BRK					24			//Timer1 Break Interrupt
#define NVIC_u8TIM1_UP					25			//Timer1 Update Interrupt
#define NVIC_u8TIM1_TRG_COM				26			//Timer1 Trigger and Communication Interrupts
#define NVIC_u8TIM1_CC					27			//Timer1 Capture Compare Interrupt
#define NVIC_u8TIM2						28			//Timer2
#define NVIC_u8TIM3						29			//Timer3
#define NVIC_u8TIM4						30			//Timer4
#define NVIC_u8I2C1_EV					31			//I2C1 Event Interrupt
#define NVIC_u8I2C1_ER					32			//I2C1 Error Interrupt
#define NVIC_u8I2C2_EV					33			//I2C2 Event Interrupt
#define NVIC_u8I2C2_ER					34			//I2C2 Error Interrupt
#define NVIC_u8SPI1						35			//SPI1
#define NVIC_u8SPI2						36			//SPI2
#define NVIC_u8USART1					37			//USART1
#define NVIC_u8USART2					38			//USART2
#define NVIC_u8USART3					39			//USART3
#define NVIC_u8EXTI15_10				40			//EXTI15 to EXTI10
#define NVIC_u8RTCALARM					41			//RTC Alarm through EXTI line interrupt
#define NVIC_u8USBWAKEUP				42			//USB wakeup from suspend through EXTI line interrupt
#define NVIC_u8TIM8_BRK					43			//Timer8 Break interrupt
#define NVIC_u8TIM8_UP					44			//Timer8 Update interrupt
#define NVIC_u8TIM8_TRG_COM				45			//Timer8 Trigger and Communication Interrupts
#define NVIC_u8TIM8_CC					46			//Timer8 Capture Compare Interrupt
#define NVIC_u8ADC3						47			//ADC3
#define NVIC_u8FSMC						48			//FSMC
#define NVIC_u8SDIO						49			//SDIO
#define NVIC_u8TIM5						50			//Timer5
#define NVIC_u8SPI3						51			//SPI3
#define NVIC_u8UART4					52			//UART4
#define NVIC_u8UART5					53			//UART5
#define NVIC_u8TIM6						54			//Timer6
#define NVIC_u8TIM7						55			//Timer7
#define NVIC_u8DMA2_CHANNEL1			56			//DMA2 Channel1
#define NVIC_u8DMA2_CHANNEL2			57			//DMA2 Channel2
#define NVIC_u8DMA2_CHANNEL3			58			//DMA2 Channel3
#define NVIC_u8DMA2_CHANNEL4_5			59			//DMA2 Channel4 and Channel5


/* choosing Group and sub group needed bits */
#define GROUP_BITS_4_SUB_GROUP_BITS_0	0x05FA0300
#define GROUP_BITS_3_SUB_GROUP_BITS_1   0x05FA0400
#define GROUP_BITS_2_SUB_GROUP_BITS_2   0x05FA0500
#define GROUP_BITS_1_SUB_GROUP_BITS_3   0x05FA0600
#define GROUP_BITS_0_SUB_GROUP_BITS_4   0x05FA0700


/****************************************************************/
/******************* PUBLIC FUNCTIONS ***************************/
/****************************************************************/


void NVIC_voidInit(void);

/***************************************************************************************************/
/* Description: Enable Interrupt for a certain periphral        								   */
/* Input      : u8 copy_u8IntNum => Periphral postion number to Enable its interrupt               */
/*                               => Range: 0 -> 59  	                                           */
/*                               => Check PUBLIC DEFINITIONS section for all periphrals definition */
/* Output     : Void                                                                  		 	   */
/* Scope      : Public                                                                 			   */
/***************************************************************************************************/
void NVIC_voidEnableInterrupt(u8 copy_u8IntNum);

/***************************************************************************************************/
/* Description: Disable Interrupt for a certain periphral        								   */
/* Input      : u8 copy_u8IntNum => Periphral postion number to Disable its interrupt              */
/*                               => Range: 0 -> 59  	                                           */
/*                               => Check PUBLIC DEFINITIONS section for all periphrals definition */
/* Output     : Void                                                                  		 	   */
/* Scope      : Public                                                                 			   */
/***************************************************************************************************/
void NVIC_voidDisableInterrupt(u8 copy_u8IntNum);

/***************************************************************************************************/
/* Description: Set Interrupt pending flag for a certain periphral        						   */
/* Input      : u8 copy_u8IntNum => Periphral postion number to Set its pending flag               */
/*                               => Range: 0 -> 59  	                                           */
/*                               => Check PUBLIC DEFINITIONS section for all periphrals definition */
/* Output     : Void                                                                  		 	   */
/* Scope      : Public                                                                 			   */
/***************************************************************************************************/
void NVIC_voidSetPendingFlag(u8 copy_u8IntNum);

/***************************************************************************************************/
/* Description: Clear Interrupt pending flag for a certain periphral        					   */
/* Input      : u8 copy_u8IntNum => Periphral postion number to clear its pending flag             */
/*                               => Range: 0 -> 59  	                                           */
/*                               => Check PUBLIC DEFINITIONS section for all periphrals definition */
/* Output     : Void                                                                  		 	   */
/* Scope      : Public                                                                 			   */
/***************************************************************************************************/
void NVIC_voidClearPendingFlag(u8 copy_u8IntNum);

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
u8 NVIC_u8GetActiveFlag(u8 copy_u8IntNum);

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
void NVIC_voidSetInterruptPriority(u8 copy_u8IntNum, u8 copy_u8GroupPriority, u8 copy_u8SubPriority);

#endif