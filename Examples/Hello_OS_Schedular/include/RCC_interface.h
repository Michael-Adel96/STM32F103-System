/********************************************/
/* Author	: Michael Adel					*/
/* Version	: V01							*/
/* Date		: 13 Nov. 2020					*/
/********************************************/
#ifndef _RCC_INTERFACE_H
#define _RCC_INTERFACE_H

/**********************************************************/
/***************** PUBLIC DEFINITIONS *********************/
/**********************************************************/

/* Bus ID */
#define RCC_AHB			0
#define RCC_APB1		1	
#define RCC_APB2		2

/* Periphrals ID */
/* AHB bus Periphrals */
#define RCC_DMA1_CLK		 0
#define RCC_DMA2_CLK		 1
#define RCC_SRAM_CLK		 2
#define RCC_FLITF_CLK		 4
#define RCC_CRC_CLK			 6
#define RCC_FSMC_CLK		 8
#define RCC_SDIO_CLK		 10

/* APB1 bus Periphrals */
#define	RCC_TIM2_CLK		 0
#define	RCC_TIM3_CLK		 1
#define	RCC_TIM4_CLK		 2
#define	RCC_TIM5_CLK		 3
#define	RCC_TIM6_CLK		 4
#define	RCC_TIM7_CLK		 5
#define	RCC_TIM12_CLK		 6
#define	RCC_TIM13_CLK		 7
#define	RCC_TIM14_CLK		 8
#define	RCC_WWDG_CLK		 11
#define	RCC_SPI2_CLK		 14
#define	RCC_SPI3_CLK		 15
#define	RCC_USART2_CLK		 17
#define	RCC_USART3_CLK		 18
#define	RCC_USART4_CLK		 19
#define	RCC_USART5_CLK		 20
#define RCC_I2C1_CLK		 21
#define RCC_I2C2_CLK		 22
#define RCC_USB_CLK		 	 23
#define RCC_CAN_CLK		 	 25
#define RCC_BKP_CLK		 	 27
#define RCC_PWR_CLK		 	 28
#define RCC_DAC_CLK		 	 29


/* APB2 bus Periphrals */
#define	RCC_AFIO_CLK		 0
#define	RCC_GPIOA_CLK		 2
#define	RCC_GPIOB_CLK		 3
#define	RCC_GPIOC_CLK		 4
#define	RCC_GPIOD_CLK		 5
#define	RCC_ADC1_CLK		 9
#define	RCC_ADC2_CLK		 10
#define	RCC_TIM1_CLK		 11
#define	RCC_SPI1_CLK		 12
#define	RCC_TIM8_CLK		 13
#define	RCC_USART1_CLK		 14
#define	RCC_ADC3_CLK		 15
#define	RCC_TIM9_CLK		 19
#define	RCC_TIM10_CLK		 20
#define	RCC_TIM11_CLK		 21


/**********************************************************/
/***************** PUBLIC FUNCTIONS ***********************/
/**********************************************************/

/* Brief: used to intialize system clock with the 		  */
/*		  pre-configured options in RCC_config.h file     */
/* Input: void											  */
/* Return: void											  */
void RCC_voidInitSysClock(void);

/* Brief: used to Enable each periphral clock except      */
/*		  Core periphrals as it doesn't need to intialize */
/*		  its clock, default core periphrals clock is     */
/*		  same as system clock 							  */
/* Input_1:(u8 copy_u8BusId) Periphral's Bus ID		      */
/* Input_1 Range: RCC_AHB, RCC_APB1, RCC_APB2  			  */
/* Input_2:(u8 copy_u8PerId)  Periphral ID in its Bus	  */
/* Input_2 Range: 0 -> 31 choose from Public definitions  */
/*				  in RCC_interface.h file 				  */
/* Return: void											  */
void RCC_voidEnableClock(u8 copy_u8BusId, u8 copy_u8PerId);

/* Brief: used to Disable each periphral clock except     */
/*		  Core periphrals as it doesn't need to intialize */
/*		  its clock, default core periphrals clock is     */
/*		  same as system clock 							  */
/* Input_1:(u8 copy_u8BusId) Periphral's Bus ID		      */
/* Input_1 Range: RCC_AHB, RCC_APB1, RCC_APB2  			  */
/* Input_2:(u8 copy_u8PerId)  Periphral ID in its Bus	  */
/* Input_2 Range: 0 -> 31,choose from Public definitions  */
/*				  in RCC_interface.h file 				  */
/* Return: void											  */
void RCC_voidDisableClock(u8 copy_u8BusId, u8 copy_u8PerId);

#endif