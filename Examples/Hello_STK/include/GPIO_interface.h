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
#define 	INPUT_PULL_DOWN						0b1000
#define		INPUT_PULL_UP						0b1000

/* GPIO output state definition */
#define		GPIO_LOW								0
#define		GPIO_HIGH								1

/**********************************************************/
/***************** PUBLIC FUNCTIONS ***********************/
/**********************************************************/


void GPIO_voidSetPinMode(u8 u8CopyPortId,u8 u8CopyPinId, u8 u8CopyPinMode);
void GPIO_voidSetPinValue(u8 u8CopyPortId,u8 u8CopyPinId, u8 u8CopyPinValue);
u8	 GPIO_u8GetPinValue(u8 u8CopyPortId,u8 u8CopyPinId);

#endif                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
