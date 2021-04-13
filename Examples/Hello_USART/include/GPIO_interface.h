/********************************************/
/* Author	: Michael Adel					*/
/* Version	: V01							*/
/* Date		: 25 Nov. 2020					*/
/********************************************/

#ifndef _GPIO_INTERFACE_H
#define _GPIO_INTERFACE_H

/**********************************************************/
/***************** PUBLIC DEFINITIONS *********************/
/**********************************************************/
#define		GPIOA		0
#define 	GPIOB		1
#define 	GPIOC		2

#define 	PIN0		0
#define 	PIN1		1
#define 	PIN2		2
#define 	PIN3		3
#define 	PIN4		4
#define 	PIN5		5
#define 	PIN6		6
#define 	PIN7		7
#define 	PIN8		8
#define 	PIN9		9
#define 	PIN10		10
#define 	PIN11		11
#define 	PIN12		12
#define 	PIN13		13
#define 	PIN14		14
#define 	PIN15		15

/* Output Pin Configerations */
#define		OUTPUT_PUSH_PULL_SPEED_10MHZ		0b0001
#define		OUTPUT_PUSH_PULL_SPEED_2MHZ			0b0010
#define		OUTPUT_PUSH_PULL_SPEED_50MHZ		0b0011
	
#define		OUTPUT_OPEN_DRAIN_SPEED_10MHZ		0b0101
#define		OUTPUT_OPEN_DRAIN_SPEED_2MHZ		0b0110
#define		OUTPUT_OPEN_DRAIN_SPEED_50MHZ		0b0111

/* Alternative function Output Pin Configerations */
#define		AF_OUTPUT_PUSH_PULL_SPEED_10MHZ		0b1001
#define		AF_OUTPUT_PUSH_PULL_SPEED_2MHZ		0b1010
#define		AF_OUTPUT_PUSH_PULL_SPEED_50MHZ		0b1011

#define		AF_OUTPUT_OPEN_DRAIN_SPEED_10MHZ	0b1101
#define		AF_OUTPUT_OPEN_DRAIN_SPEED_2MHZ		0b1110
#define		AF_OUTPUT_OPEN_DRAIN_SPEED_50MHZ	0b1111

/* Input pin configerations */
#define		ANALOG_INPUT						0b0000
#define		INPUT_FLOATING						0b0100
#define 	INPUT_PULL_DOWN						0b10000
#define		INPUT_PULL_UP						0b10001

/* GPIO output state definition */
#define		GPIO_LOW								0
#define		GPIO_HIGH								1

/************************** AFIO SECTION ***************************/
/* EXTI lines numbers */
#define     EXTI_LINE_0         0
#define     EXTI_LINE_1         1
#define     EXTI_LINE_2         2
#define     EXTI_LINE_3         3
#define     EXTI_LINE_4         4
#define     EXTI_LINE_5         5
#define     EXTI_LINE_6         6
#define     EXTI_LINE_7         7
#define     EXTI_LINE_8         8
#define     EXTI_LINE_9         9
#define     EXTI_LINE_10        10
#define     EXTI_LINE_11        11
#define     EXTI_LINE_12        12
#define     EXTI_LINE_13        13
#define     EXTI_LINE_14        14
#define     EXTI_LINE_15        15


#define     EXTI_PORTA_PIN      0b0000   
#define     EXTI_PORTB_PIN      0b0001
#define     EXTI_PORTC_PIN      0b0010

/*******************************************************************/

/**********************************************************/
/***************** PUBLIC FUNCTIONS ***********************/
/**********************************************************/


void GPIO_voidSetPinMode(u8 u8CopyPortId,u8 u8CopyPinId, u8 u8CopyPinMode);
void GPIO_voidSetPinValue(u8 u8CopyPortId,u8 u8CopyPinId, u8 u8CopyPinValue);
u8	 GPIO_u8GetPinValue(u8 u8CopyPortId,u8 u8CopyPinId);

/****************************************************************************************************/
/* Description: Configure a certain EXTI Line with the selected port line.						   	*/
/* Input      : u8 u8CopyEXTILine => choose EXTI line number                                     	*/
/*                                => Range: EXTI_LINE_x, x: 0 to 15                               	*/
/*              u8 u8CopyEXTIPort => choose which port pin to be mapped for a certain EXTI line.	*/
/*                                      => Range: EXTI_PORTA_PIN,		                        	*/
/*                                                EXTI_PORTB_PIN,                       			*/
/*                                                EXTI_PORTC_PIN                          			*/
/* Note 	  : RCC_AFIO_CLK must be Enabled before calling this function.				 			*/
/* Output     : Void                                                                               */
/* Scope      : Public                                                                             */
/****************************************************************************************************/
void AFIO_voidEXTILineConfig(u8 u8CopyEXTILine, u8 u8CopyEXTIPort);



#endif