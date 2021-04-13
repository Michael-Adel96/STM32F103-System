/********************************************/
/* Title    : USART Driver                  */
/* Author   : Michael Adel                  */
/* Version  : V01                           */
/* Date     : 04 April 2021                 */
/********************************************/

/********************************************************************************/
/* USART1 Operation sequence                                                    */
/* =========================                                                    */
/* => User must include RCC and DMA drivers.                                    */
/* 1. Enable USART1 and set USART1 configurations in USART_config.h file.       */
/*    => Ensure that USART1_TRANSMITTER_ENABLE is Enabled in USART_config.h.    */
/*    => Ensure that USART1_RECEIVER_ENABLE is Enabled in USART_config.h.       */
/*    => Set USART1_RECEIVER_ENABLE in USART_config.h                           */
/*    => Assign F_PCLK1_MHZ and F_PCLK2_MHZ in USART_config.h                   */
/* 2. Enable system RCC.                                                        */
/* 3. Enable RCC_GPIOA_CLK.                                                     */
/* 4. Enable RCC_USART1_CLK.                                                    */
/* 5. Intialize NVIC. (If Interrupt is needed)                                  */
/* 6. Enable USART Interrupt (NVIC_u8USART1).                                   */
/* 7. Set GPIOA->Pin9 as Alternate output function push pull 50 MHZ (Tx).       */
/* 8. Set GPIOA->Pin10 as Input floating (Rx).                                  */
/* 9. Intialize USART to Load all Configurations from USART_config.h file.      */
/*    USART_voidInit()                                                          */
/* 10. User Can transmit single character or transmit string.                   */
/* 11. User Can receive data with 3 different methods:                          */
/*          A) Polling Method:                                                  */
/*             => Call USART_u16SynchronousReceiveCharacter(xx)                 */
/*             => This function will wait(stuck) until a character is received. */
/*          B) Interrupt Method:                                                */
/*             => Ensure that USART Int. is Enabled by NVIC.                    */
/*             => Ensure that USART1_READ_DATA_REGISTER_NOT_EMPTY_INT is        */
/*                Enbaled in USART_config.h file.                               */
/*             => Call USART_voidSetCallBack(x, y)                              */
/*             => the excuted function when the Int. is fired must receive the  */
/*                 received character.                                          */
/*         C) DMA Method:                                                       */
/*             => Ensure that USART1_ENABLE_DMA_RECEIVER is Enabled in          */
/*                USART_config.h file.                                          */
/*             => Call USART_u16AsynchronousDMAReceive(x,y,z)                   */
/*             => DMA is responsible to transfer data based in your             */
/*                configerations without stucking the whole systems, it seems   */
/*                as DMA is tansfering data parallel to the processor main      */
/*                functionality.                                                */
/*             => Do not send data over same USART channel while DMA is         */
/*                transferring data, it may cause corruption in the received    */
/*                data.                                                         */
/********************************************************************************/

#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

/***************************************************************************************************/
/********************************* PUBLIC DEFINITIONS **********************************************/
/***************************************************************************************************/


typedef enum {
    USART_Channel_1,
    USART_Channel_2,
    USART_Channel_3,
    USART_Channel_4,
    USART_Channel_5,
} USART_Channel;




/***************************************************************************************************/
/********************************* PUBLIC FUNCTIONS ************************************************/
/***************************************************************************************************/

/****************************************************************************************************/
/* Description: Intialize all USART Enabled channels with the pre-defined configurations            */
/*              in USART_config.h                                                                   */
/* Input      : Void                                                                                */
/* Output     : Void                                                                                */
/* Scope      : Puplic                                                                              */
/****************************************************************************************************/
void USART_voidInit(void);


/****************************************************************************************************/
/* Description: Send a character of 8 bits or 9 bits over the selected USART channel.               */
/*              User can configure the word size in USART_config.h file.                            */
/* Input      : USART_Channel Channel_No => Selected channel number.                                */
/*                                       => Range: USART_Channel_x, where x: 1 to 5                 */
/*              const u16 Copy_u16CharTx => character to be sent to other USART node.               */
/*                                       => 8 or 9 bit size depends on the pre-defined              */
/*                                          configurations.                                         */
/* Output     : Void                                                                                */
/* Scope      : Puplic                                                                              */
/****************************************************************************************************/
void USART_voidSendCharacter(USART_Channel Channel_No, const u16 Copy_u16CharTx);


/****************************************************************************************************/
/* Description: Receive a character of 8 bits or 9 bits through the selected USART channel.         */
/*              It waits until it receives any character (Polling method).                          */
/* Input      : USART_Channel Channel_No => Selected channel number.                                */
/*                                       => Range: USART_Channel_x, where x: 1 to 5                 */
/* Output     : u16 => the received character.                                                      */
/* Scope      : Puplic                                                                              */
/* ===================                                                                              */
/* Future improvement:                                                                              */
/* ===================                                                                              */
/*     1. add time out for receiving a character to avoid stucking while waiting                    */
/*        a character to be received.                                                               */
/****************************************************************************************************/
u16 USART_u16SynchronousReceiveCharacter(USART_Channel Channel_No);

/****************************************************************************************************/
/* Description: Receive data of multiple characters each character is 8 or 9 bits over USART        */
/*              through DMA, so it seems to be parallel to normal excution of processor functions.  */
/*              It doesn't wait(stuck) to receive character as DMA is responsible to handle the     */
/*              transaction not the main core processor.                                            */
/* Input      : USART_Channel Channel_No => Selected channel number.                                */
/*                                       => Range: USART_Channel_x, where x: 1 to 3                 */
/*              volatile u16 *buffer => pointer to buffer at which the received data will be copied.*/
/*              u16 dataBlocksNum => number of data blocks needed to be transfered through DMA.     */
/*                                => Range: 0 to 65535                                              */
/* Note_1     : This functionality does not apply on USART 4 and USART 5                            */
/* Note_2     : Don't transmit data while DMA transfer data from DR Reg to a certain buffer         */
/*              location that will lead to unexpected behavior in the received data.                */
/* Output     : void                                                                                */
/* Scope      : Puplic                                                                              */
/****************************************************************************************************/
void USART_u16AsynchronousDMAReceive(USART_Channel Channel_No, volatile u8 *buffer, u16 dataBlocksNum);

/****************************************************************************************************/
/* Description: Send a string through a specific USART channel.                                     */
/* Input      : USART_Channel Channel_No => Selected channel number.                                */
/*                                       => Range: USART_Channel_x, where x: 1 to 5                 */
/*              u8 * StrPtr => pointer to a string to be sent through USART.                        */
/* Caution    : The passed string must be ended with '\0' Null character, if not overflow error     */
/*              will occur.                                                                         */
/* Output     : void.                                                                               */
/* Scope      : Puplic                                                                              */
/* ===================                                                                              */
/* Future improvement:                                                                              */
/* ===================                                                                              */
/*   1. Check if the string is ended with Null character or not and if not through error status     */
/*      and avoid overflow problem.                                                                 */
/****************************************************************************************************/
void USART_voidSendString(USART_Channel Channel_No, u8 * StrPtr);


/****************************************************************************************************/
/* Description: Set call back function to be excuted when USART revceive character and              */
/*              fire the crossponding interrupt.                                                    */
/* Input      : USART_Channel Channel_No => Selected channel number.                                */
/*                                       => Range: USART_Channel_x, where x: 1 to 3                 */
/*              void (*Func_ptr)(u16) => pointer to function to be excuted when the interrupt       */
/*                                       is fired.                                                  */
/*                                    => The passed function must has 1 u16 input patameter and     */
/*                                       return void.                                               */
/*                                    => when the interrupt is fired the passed function is called  */
/*                                       and the received character is passed to it as u16 input    */
/*                                       argument.                                                  */
/* Output     : void                                                                                */
/* Scope      : Puplic                                                                              */
/****************************************************************************************************/
void USART_voidSetCallBack(USART_Channel USARTChannelNum, void (*Func_ptr)(u16));



#endif