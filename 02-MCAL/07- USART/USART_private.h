/********************************************/
/* Title    : USART Driver                  */
/* Author   : Michael Adel                  */
/* Version  : V01                           */
/* Date     : 04 April 2021                 */
/********************************************/

#ifndef USART_PRIVATE_H
#define USART_PRIVATE_H


/***************************************************************************************************/
/********************************* PRIVATE DEFINITIONS *********************************************/
/***************************************************************************************************/

#define USART1_BASE_ADDRESS 0x40013800
#define USART2_BASE_ADDRESS 0x40004400
#define USART3_BASE_ADDRESS 0x40004800
#define USART4_BASE_ADDRESS 0x40004C00
#define USART5_BASE_ADDRESS 0x40005000

typedef struct
{
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 CR3;
	volatile u32 GTPR;
} USART_t;

#define USART1 ((volatile USART_t *) USART1_BASE_ADDRESS)
#define USART2 ((volatile USART_t *) USART2_BASE_ADDRESS)
#define USART3 ((volatile USART_t *) USART3_BASE_ADDRESS)
#define USART4 ((volatile USART_t *) USART4_BASE_ADDRESS)
#define USART5 ((volatile USART_t *) USART5_BASE_ADDRESS)

#define BIT_8 									0
#define BIT_9 									1

#define IDLE_LINE 								0
#define ADDRESS_MARK 							1

#define DISABLED 								0
#define ENABLED 								1

#define EVEN_PARITY 							0
#define ODD_PARITY 								1

#define ACTIVE_MODE 							0
#define MUTE_MODE 								1

#define NO_BREAK_CHARACTER_TRANSMITTED 			0
#define BREAK_CHARACTER_TRANSMITTED 			1


#define STOP_BIT_1								0b00	/* STOP BITS = 1 BITS	*/
#define STOP_BIT_0_5							0b01	/* STOP BITS = 0.5 BITS */
#define STOP_BIT_2								0b10	/* STOP BITS = 2 BITS	*/
#define STOP_BIT_1_5							0b11	/* STOP BITS = 1.5 BITS	*/


/***************************************************************************************************/
/********************************* PRIVATE FUNCTIONS ***********************************************/
/***************************************************************************************************/

/***************************************************************************************************/
/* Description: NOP function loaded to all pointers to functions to avoid going to hard fault      */
/*              when there's something incorrect in user's intializations.                         */
/* Input      : Void                                                                               */
/* Output     : Void                                                                               */
/* Scope      : Private                                                                            */
/***************************************************************************************************/
static void stub(u16);

/****************************************************************************************************/
/* Description: Calculate Mantissa and Fraction based on the user baud rate configerations          */
/*              and APB1, APB2 clock speeds in USART_config.h file.                                 */
/* Input      : USART_Channel USARTChannelNum => Selected channel number.                           */
/*                                            => Range: USART_Channel_x, where x: 1 to 5            */
/* Output     : u16 => BRR register value.                                                          */
/* Scope      : Private                                                                             */
/****************************************************************************************************/
static u16 get_Mantissa_fraction(USART_Channel USARTChannelNum);


#endif