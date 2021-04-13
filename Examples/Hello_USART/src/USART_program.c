/********************************************/
/* Title    : USART Driver                  */
/* Author   : Michael Adel                  */
/* Version  : V01                           */
/* Date     : 04 April 2021                 */
/********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"

#include "DMA_interface.h"
#include "RCC_interface.h"

/* pointers to callback functions of USART */
void (*USART_CallBack_Func[5])(u16) = {
    stub,
    stub,
    stub,
    stub,
    stub};

/****************************************************************************************************/
/* Description: Intialize all USART Enabled channels with the pre-defined configurations            */
/*              in USART_config.h                                                                   */
/* Input      : Void                                                                                */
/* Output     : Void                                                                                */
/* Scope      : Puplic                                                                              */
/****************************************************************************************************/
void USART_voidInit(void)
{
    /* Set Baud Rate                        */
    /* Configure Each enabled USART channel */
    /* Enable USART channel                 */
#if USART1_STATUS == ENABLED
    USART1->BRR = get_Mantissa_fraction(USART_Channel_1);
    USART1->CR1 = (1 << 13) |
                  (USART1_WORD_LENGTH << 12) |
                  (USART1_WAKEUP_METHOD << 11) |
                  (USART1_PARITY_CONTROL_ENABLE << 10) |
                  (USART1_PARITY_SELECTION << 9) |
                  (USART1_PARITY_ERROR_INT << 8) |
                  (USART1_TRANSMIT_DATA_REG_EMPTY_INT << 7) |
                  (USART1_TRANSMISSION_COMPLETE_INT_ENABLE << 6) |
                  (USART1_READ_DATA_REGISTER_NOT_EMPTY_INT << 5) |
                  (USART1_IDLE_DETECTED_INT_ENABLE << 4) |
                  (USART1_TRANSMITTER_ENABLE << 3) |
                  (USART1_RECEIVER_ENABLE << 2) |
                  (USART1_RECEIVER_WAKEUP << 1) |
                  (USART1_SEND_BREAK << 0);

    USART1->CR2 = 0x0;
    USART1->CR2 |= (USART1_STOP_BITS << 12);

    USART1->CR3 = 0x0;
    USART1->CR3 |= ((USART1_ENABLE_DMA_TRANSMITTER << 7) | (USART1_ENABLE_DMA_RECEIVER << 6));

#endif

#if USART2_STATUS == ENABLED
    USART2->BRR = get_Mantissa_fraction(USART_Channel_2);
    USART2->CR1 = (1 << 13) |
                  (USART2_WORD_LENGTH << 12) |
                  (USART2_WAKEUP_METHOD << 11) |
                  (USART2_PARITY_CONTROL_ENABLE << 10) |
                  (USART2_PARITY_SELECTION << 9) |
                  (USART2_PARITY_ERROR_INT << 8) |
                  (USART2_TRANSMIT_DATA_REG_EMPTY_INT << 7) |
                  (USART2_TRANSMISSION_COMPLETE_INT_ENABLE << 6) |
                  (USART2_READ_DATA_REGISTER_NOT_EMPTY_INT << 5) |
                  (USART2_IDLE_DETECTED_INT_ENABLE << 4) |
                  (USART2_TRANSMITTER_ENABLE << 3) |
                  (USART2_RECEIVER_ENABLE << 2) |
                  (USART2_RECEIVER_WAKEUP << 1) |
                  (USART2_SEND_BREAK << 0);

    USART2->CR2 = 0x0;
    USART2->CR2 |= (USART2_STOP_BITS << 12);

    USART2->CR3 = 0x0;
    USART2->CR3 |= ((USART2_ENABLE_DMA_TRANSMITTER << 7) | (USART2_ENABLE_DMA_RECEIVER << 6));
#endif

#if USART3_STATUS == ENABLED
    USART3->BRR = get_Mantissa_fraction(USART_Channel_3);
    USART3->CR1 = (1 << 13) |
                  (USART3_WORD_LENGTH << 12) |
                  (USART3_WAKEUP_METHOD << 11) |
                  (USART3_PARITY_CONTROL_ENABLE << 10) |
                  (USART3_PARITY_SELECTION << 9) |
                  (USART3_PARITY_ERROR_INT << 8) |
                  (USART3_TRANSMIT_DATA_REG_EMPTY_INT << 7) |
                  (USART3_TRANSMISSION_COMPLETE_INT_ENABLE << 6) |
                  (USART3_READ_DATA_REGISTER_NOT_EMPTY_INT << 5) |
                  (USART3_IDLE_DETECTED_INT_ENABLE << 4) |
                  (USART3_TRANSMITTER_ENABLE << 3) |
                  (USART3_RECEIVER_ENABLE << 2) |
                  (USART3_RECEIVER_WAKEUP << 1) |
                  (USART3_SEND_BREAK << 0);

    USART3->CR2 = 0x0;
    USART3->CR2 |= (USART3_STOP_BITS << 12);

    USART3->CR3 = 0x0;
    USART3->CR3 |= ((USART3_ENABLE_DMA_TRANSMITTER << 7) | (USART3_ENABLE_DMA_RECEIVER << 6));
#endif

#if USART4_STATUS == ENABLED
    USART4->BRR = get_Mantissa_fraction(USART_Channel_4);
    USART4->CR1 = (1 << 13) |
                  (USART4_WORD_LENGTH << 12) |
                  (USART4_WAKEUP_METHOD << 11) |
                  (USART4_PARITY_CONTROL_ENABLE << 10) |
                  (USART4_PARITY_SELECTION << 9) |
                  (USART4_PARITY_ERROR_INT << 8) |
                  (USART4_TRANSMIT_DATA_REG_EMPTY_INT << 7) |
                  (USART4_TRANSMISSION_COMPLETE_INT_ENABLE << 6) |
                  (USART4_READ_DATA_REGISTER_NOT_EMPTY_INT << 5) |
                  (USART4_IDLE_DETECTED_INT_ENABLE << 4) |
                  (USART4_TRANSMITTER_ENABLE << 3) |
                  (USART4_RECEIVER_ENABLE << 2) |
                  (USART4_RECEIVER_WAKEUP << 1) |
                  (USART4_SEND_BREAK << 0);

    USART4->CR2 = 0x0;
    USART4->CR2 |= (USART4_STOP_BITS << 12);

    USART4->CR3 = 0x0;
    USART4->CR3 |= ((USART4_ENABLE_DMA_TRANSMITTER << 7) | (USART4_ENABLE_DMA_RECEIVER << 6));
#endif

#if USART5_STATUS == ENABLED
    USART5->BRR = get_Mantissa_fraction(USART_Channel_5);
    USART5->CR1 = (1 << 13) |
                  (USART5_WORD_LENGTH << 12) |
                  (USART5_WAKEUP_METHOD << 11) |
                  (USART5_PARITY_CONTROL_ENABLE << 10) |
                  (USART5_PARITY_SELECTION << 9) |
                  (USART5_PARITY_ERROR_INT << 8) |
                  (USART5_TRANSMIT_DATA_REG_EMPTY_INT << 7) |
                  (USART5_TRANSMISSION_COMPLETE_INT_ENABLE << 6) |
                  (USART5_READ_DATA_REGISTER_NOT_EMPTY_INT << 5) |
                  (USART5_IDLE_DETECTED_INT_ENABLE << 4) |
                  (USART5_TRANSMITTER_ENABLE << 3) |
                  (USART5_RECEIVER_ENABLE << 2) |
                  (USART5_RECEIVER_WAKEUP << 1) |
                  (USART5_SEND_BREAK << 0);

    USART5->CR2 = 0x0;
    USART5->CR2 |= (USART5_STOP_BITS << 12);

    USART5->CR3 = 0x0;
    USART5->CR3 |= ((USART5_ENABLE_DMA_TRANSMITTER << 7) | (USART5_ENABLE_DMA_RECEIVER << 6));
#endif
}

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
void USART_voidSendCharacter(USART_Channel Channel_No, const u16 Copy_u16CharTx)
{
    switch (Channel_No)
    {
    case USART_Channel_1:
        /* clear transmission complete bit */
        CLR_BIT(USART1->SR, 6);
        USART1->DR = Copy_u16CharTx;
        /* Wait until the transmission is completed */
        while (GET_BIT(USART1->SR, 6) == 0)
            ;
        break;
    case USART_Channel_2:
        /* clear transmission complete bit */
        CLR_BIT(USART2->SR, 6);
        USART2->DR = Copy_u16CharTx;
        /* Wait until the transmission is completed */
        while (GET_BIT(USART2->SR, 6) == 0)
            ;
        break;
    case USART_Channel_3:
        /* clear transmission complete bit */
        CLR_BIT(USART3->SR, 6);
        USART3->DR = Copy_u16CharTx;
        /* Wait until the transmission is completed */
        while (GET_BIT(USART3->SR, 6) == 0)
            ;

        break;
    case USART_Channel_4:
        /* clear transmission complete bit */
        CLR_BIT(USART4->SR, 6);
        USART4->DR = Copy_u16CharTx;
        /* Wait until the transmission is completed */
        while (GET_BIT(USART4->SR, 6) == 0)
            ;
        break;
    case USART_Channel_5:
        /* clear transmission complete bit */
        CLR_BIT(USART5->SR, 6);
        USART5->DR = Copy_u16CharTx;
        /* Wait until the transmission is completed */
        while (GET_BIT(USART5->SR, 6) == 0)
            ;
        break;
    default:
        // return Error message: input is out of range
        break;
    }
}


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
u16 USART_u16SynchronousReceiveCharacter(USART_Channel Channel_No)
{
    u32 Local_ReceivedChar;
    switch (Channel_No)
    {
    case USART_Channel_1:
        /* Wait until the data is received */
        while (GET_BIT(USART1->SR, 5) == 0)
            ;
        Local_ReceivedChar = USART1->DR;
        break;
    case USART_Channel_2:
        /* Wait until the data is received */
        while (GET_BIT(USART2->SR, 5) == 0)
            ;
        Local_ReceivedChar = USART2->DR;
        break;
    case USART_Channel_3:
        /* Wait until the data is received */
        while (GET_BIT(USART3->SR, 5) == 0)
            ;
        Local_ReceivedChar = USART3->DR;
        break;
    case USART_Channel_4:
        /* Wait until the data is received */
        while (GET_BIT(USART4->SR, 5) == 0)
            ;
        Local_ReceivedChar = USART4->DR;
        break;
    case USART_Channel_5:
        /* Wait until the data is received */
        while (GET_BIT(USART5->SR, 5) == 0)
            ;
        Local_ReceivedChar = USART5->DR;
        break;
    default:
        // return Error message: input is out of range
        break;
    }
    return Local_ReceivedChar;
}

/****************************************************************************************************/
/* Description: Receive data of multiple characters each character is 8 bits over USART             */
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
void USART_u16AsynchronousDMAReceive(USART_Channel Channel_No, volatile u8 *buffer, u16 dataBlocksNum)
{
    /*Enable clock on DMA Peripheral*/
    RCC_voidEnableClock(RCC_AHB, RCC_DMA1_CLK);

    switch (Channel_No)
    {
    case USART_Channel_1:; // to avoid (error: a label can only be part of a statement and a declaration is not a statement)

        DMA_Config_t DMA_St1 = {
            Channel_5,     // Channel_Id: Channel_x, x: 1->7
            Disable,       // MEM2MEM: Enable, Disable
            Very_high,     // Channel_priority: Low, Medium, High, Very_high
            MEM_BITS_8,   // MEM_Size: BITS_8, BITS_16, BITS_32
            PER_BITS_8,   // Periphral_Size: BITS_8, BITS_16, BITS_32
            Enable,        // Memory increment mode, MINC: Enable, Disable
            Disable,       // Peripheral increment mode, PINC: Enable, Disable
            Disable,       // Circular mode, CIRC: Enable, Disable
            Read_From_PER, // Data transfer direction, DIR: Read_From_PER, Read_From_MEM
            Disable,       // Transfer error interrupt enable, TEIE: Enable, Disable
            Disable,       // Half transfer interrupt enable, HTIE: Enable, Disable
            Disable        // Transfer complete interrupt enable, TCIE: Enable, Disable
        };

        DMA_voidConfigureChannel(DMA_St1);
        DMA_voidTransfer(Channel_5, &(USART1->DR), buffer, dataBlocksNum);
        break;
    case USART_Channel_2:; // to avoid (error: a label can only be part of a statement and a declaration is not a statement)

        DMA_Config_t DMA_St2 = {
            Channel_6,     // Channel_Id: Channel_x, x: 1->7
            Disable,       // MEM2MEM: Enable, Disable
            Very_high,     // Channel_priority: Low, Medium, High, Very_high
            MEM_BITS_8,   // MEM_Size: BITS_8, BITS_16, BITS_32
            PER_BITS_8,   // Periphral_Size: BITS_8, BITS_16, BITS_32
            Enable,        // Memory increment mode, MINC: Enable, Disable
            Disable,       // Peripheral increment mode, PINC: Enable, Disable
            Disable,       // Circular mode, CIRC: Enable, Disable
            Read_From_PER, // Data transfer direction, DIR: Read_From_PER, Read_From_MEM
            Disable,       // Transfer error interrupt enable, TEIE: Enable, Disable
            Disable,       // Half transfer interrupt enable, HTIE: Enable, Disable
            Disable        // Transfer complete interrupt enable, TCIE: Enable, Disable
        };

        DMA_voidConfigureChannel(DMA_St2);
        DMA_voidTransfer(Channel_5, &(USART2->DR), buffer, dataBlocksNum);
        break;
    case USART_Channel_3:; // to avoid (error: a label can only be part of a statement and a declaration is not a statement)

        DMA_Config_t DMA_St3 = {
            Channel_3,     // Channel_Id: Channel_x, x: 1->7
            Disable,       // MEM2MEM: Enable, Disable
            Very_high,     // Channel_priority: Low, Medium, High, Very_high
            MEM_BITS_8,   // MEM_Size: BITS_8, BITS_16, BITS_32
            PER_BITS_8,   // Periphral_Size: BITS_8, BITS_16, BITS_32
            Enable,        // Memory increment mode, MINC: Enable, Disable
            Disable,       // Peripheral increment mode, PINC: Enable, Disable
            Disable,       // Circular mode, CIRC: Enable, Disable
            Read_From_PER, // Data transfer direction, DIR: Read_From_PER, Read_From_MEM
            Disable,       // Transfer error interrupt enable, TEIE: Enable, Disable
            Disable,       // Half transfer interrupt enable, HTIE: Enable, Disable
            Disable        // Transfer complete interrupt enable, TCIE: Enable, Disable
        };

        DMA_voidConfigureChannel(DMA_St3);
        DMA_voidTransfer(Channel_5, &(USART3->DR), buffer, dataBlocksNum);
        break;
    default:
        // return Error message: input is out of range
        break;
    }
}


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
void USART_voidSendString(USART_Channel Channel_No, u8 * StrPtr)
{
    u16 i = 0;
    while (StrPtr[i] != '\0')
    {
        USART_voidSendCharacter(Channel_No, StrPtr[i]);
        i++;
    }
}


/****************************************************************************************************/
/* Description: Calculate Mantissa and Fraction based on the user baud rate configerations          */
/*              and APB1, APB2 clock speeds in USART_config.h file.                                 */
/* Input      : USART_Channel USARTChannelNum => Selected channel number.                           */
/*                                            => Range: USART_Channel_x, where x: 1 to 5            */
/* Output     : u16 => BRR register value.                                                          */
/* Scope      : Private                                                                             */
/****************************************************************************************************/
static u16 get_Mantissa_fraction(USART_Channel USARTChannelNum)
{

    float temp1, temp2;
    u16 mantissa;
    u8 fraction;
    u32 fclk, Baud_Rate;
    switch (USARTChannelNum)
    {
    case USART_Channel_1:
        fclk = F_PCLK2_MHZ * 1000000;
        Baud_Rate = USART1_BAUD_RATE;
        break;
    case USART_Channel_2:
        fclk = F_PCLK1_MHZ * 1000000;
        Baud_Rate = USART2_BAUD_RATE;
        break;
    case USART_Channel_3:
        Baud_Rate = USART3_BAUD_RATE;
        fclk = F_PCLK1_MHZ * 1000000;
        break;
    case USART_Channel_4:
        Baud_Rate = USART4_BAUD_RATE;
        fclk = F_PCLK1_MHZ * 1000000;
        break;
    case USART_Channel_5:
        Baud_Rate = USART5_BAUD_RATE;
        fclk = F_PCLK1_MHZ * 1000000;
        break;
    }
    mantissa = fclk / (16 * Baud_Rate);
    temp2 = (((float)fclk / (16 * Baud_Rate)) - (mantissa)) * (16);
    temp1 = temp2 - (float)(u8)temp2;
    if (temp1 >= 0.5)
    {
        temp2++;
    }
    fraction = (u8)temp2;

    return (mantissa << 4) + (fraction);
}


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
void USART_voidSetCallBack(USART_Channel USARTChannelNum, void (*Func_ptr)(u16))
{
    if (USARTChannelNum >= USART_Channel_1 && USARTChannelNum <= USART_Channel_5)
    {
        USART_CallBack_Func[USARTChannelNum] = Func_ptr;
    }
    else
    {
        // Return Error message: Out of range index
    }
}



/****************************************************************************************************/
/* Description: USART1 ISR handler.                                                                 */
/*              Multiple events could fire this interrupt (check Register discription page: 816).   */
/*              Receiving a character is the only handled event in this routine.                    */
/* Input      : void.                                                                               */
/* Output     : void.                                                                               */
/* Scope      : Private                                                                             */
/* ===================                                                                              */
/* Future improvement:                                                                              */
/* ===================                                                                              */
/*   1. Handle all the events interrupts not only receiving a character event.                      */
/****************************************************************************************************/
void USART1_IRQHandler(void)
{
    /* check if the interrupt is fired, because of receiving a character */
    if (GET_BIT(USART1->SR, 5) == 1)
    {
        /* Call the call back function and pass the received character to it */
        USART_CallBack_Func[USART_Channel_1](USART1->DR);
    }
}
/****************************************************************************************************/
/* Description: USART2 ISR handler.                                                                 */
/*              Multiple events could fire this interrupt (check Register discription page: 816).   */
/*              Receiving a character is the only handled event in this routine.                    */
/* Input      : void.                                                                               */
/* Output     : void.                                                                               */
/* Scope      : Private                                                                             */
/* ===================                                                                              */
/* Future improvement:                                                                              */
/* ===================                                                                              */
/*   1. Handle all the events interrupts not only receiving a character event.                      */
/****************************************************************************************************/
void USART2_IRQHandler(void)
{
    /* check if the interrupt is fired, because of receiving a character */
    if (GET_BIT(USART2->SR, 5) == 1)
    {
        /* Call the call back function and pass the received character to it */
        USART_CallBack_Func[USART_Channel_2](USART2->DR);
    }
}

/****************************************************************************************************/
/* Description: USART3 ISR handler.                                                                 */
/*              Multiple events could fire this interrupt (check Register discription page: 816).   */
/*              Receiving a character is the only handled event in this routine.                    */
/* Input      : void.                                                                               */
/* Output     : void.                                                                               */
/* Scope      : Private                                                                             */
/* ===================                                                                              */
/* Future improvement:                                                                              */
/* ===================                                                                              */
/*   1. Handle all the events interrupts not only receiving a character event.                      */
/****************************************************************************************************/
void USART3_IRQHandler(void)
{
    /* check if the interrupt is fired, because of receiving a character */
    if (GET_BIT(USART3->SR, 5) == 1)
    {
        /* Call the call back function and pass the received character to it */
        USART_CallBack_Func[USART_Channel_3](USART3->DR);
    }
}

/****************************************************************************************************/
/* Description: USART4 ISR handler.                                                                 */
/*              Multiple events could fire this interrupt (check Register discription page: 816).   */
/*              Receiving a character is the only handled event in this routine.                    */
/* Input      : void.                                                                               */
/* Output     : void.                                                                               */
/* Scope      : Private                                                                             */
/* ===================                                                                              */
/* Future improvement:                                                                              */
/* ===================                                                                              */
/*   1. Handle all the events interrupts not only receiving a character event.                      */
/****************************************************************************************************/
void USART4_IRQHandler(void)
{
    /* check if the interrupt is fired, because of receiving a character */
    if (GET_BIT(USART4->SR, 5) == 1)
    {
        /* Call the call back function and pass the received character to it */
        USART_CallBack_Func[USART_Channel_4](USART4->DR);
    }
}


/****************************************************************************************************/
/* Description: USART5 ISR handler.                                                                 */
/*              Multiple events could fire this interrupt (check Register discription page: 816).   */
/*              Receiving a character is the only handled event in this routine.                    */
/* Input      : void.                                                                               */
/* Output     : void.                                                                               */
/* Scope      : Private                                                                             */
/* ===================                                                                              */
/* Future improvement:                                                                              */
/* ===================                                                                              */
/*   1. Handle all the events interrupts not only receiving a character event.                      */
/****************************************************************************************************/
void USART5_IRQHandler(void)
{
    /* check if the interrupt is fired, because of receiving a character */
    if (GET_BIT(USART5->SR, 5) == 1)
    {
        /* Call the call back function and pass the received character to it */
        USART_CallBack_Func[USART_Channel_5](USART5->DR);
    }
}

/***************************************************************************************************/
/* Description: NOP function loaded to all pointers to functions to avoid going to hard fault      */
/*              when there's something incorrect in user's intializations.                         */
/* Input      : Void                                                                               */
/* Output     : Void                                                                               */
/* Scope      : Private                                                                            */
/***************************************************************************************************/
static void stub(u16 x)
{
    asm("NOP");
}
