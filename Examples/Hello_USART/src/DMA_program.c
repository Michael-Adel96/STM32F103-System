/********************************************/
/* Title    : DMA_1 Driver                  */
/* Author   : Michael Adel                  */
/* Version  : V01                           */
/* Date     : 29 Mar. 2021                  */
/********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DMA_interface.h"
#include "DMA_private.h"
#include "DMA_config.h"

/***************************************************************************************************/
/* Description: NOP function loaded to all pointers to functions to avoid going to hard fault      */
/*              when there's something incorrect in user's intializations.                         */
/* Input      : Void                                                                               */
/* Output     : Void                                                                               */
/* Scope      : Private                                                                            */
/***************************************************************************************************/
static void stub(void)
{
    asm("NOP");
}

void (*CallBack_Handler_TransferComplete[7])(void) = {
    stub,
    stub,
    stub,
    stub,
    stub,
    stub,
    stub};
void (*CallBack_Handler_HalfTransferComplete[7])(void) = {
    stub,
    stub,
    stub,
    stub,
    stub,
    stub,
    stub};

void (*CallBack_Handler_TransferError[7])(void) = {
    stub,
    stub,
    stub,
    stub,
    stub,
    stub,
    stub};


/***************************************************************************************************/
/* Description: Used to configure a specific DMA channel.                                          */
/*              It is mandatory to configure each channel before start transfer operation.         */
/* Input      : DMA_Config_t Channelx_Config => Struct contain all DMA configerations.             */
/*                                           => Struct definition exists in DMA_interface.h file.  */
/* Output     : Void                                                                               */
/* Scope      : Public                                                                             */
/***************************************************************************************************/
void DMA_voidConfigureChannel(DMA_Config_t Channelx_Config)
{
    u8 u8Channel;
    u8Channel = Channelx_Config.Channel_Id;
    if (u8Channel >= Channel_1 && u8Channel <= Channel_7)
    {
        DMA->Channel[u8Channel].CCR = (Channelx_Config.MEM2MEM << 14) |
                                      (Channelx_Config.Channel_priority << 12) |
                                      (Channelx_Config.MEM_Size << 10) |
                                      (Channelx_Config.Periphral_Size << 8) |
                                      (Channelx_Config.MINC << 7) |
                                      (Channelx_Config.PINC << 6) |
                                      (Channelx_Config.CIRC << 5) |
                                      (Channelx_Config.DIR << 4) |
                                      (Channelx_Config.TEIE << 3) |
                                      (Channelx_Config.HTIE << 2) |
                                      (Channelx_Config.TCIE << 1) |
                                      (0 << 0);
    }
    else
    {
        // Return Error message: Wrong Input Range
    }
}

/********************************************************************************************************/
/* Description: 1. Set Source, destinations addresses and Size of data to be transferred.               */
/*              2. Start the Transfer operation.                                                        */
/* Input      : DMA_CHANNEL ChannelId => Select Channel number.                                         */
/*                                    => DMA_CHANNEL Enum definition exists in DMA_interface.h file.    */
/*                                    => Range: Channel_x, x: 1 to 7                                    */
/*              volatile u32 *PER_Address => pointer to perihral address.                               */
/*                                        => Range: Not specified.                                      */
/*              volatile u32 *MEM_Address => pointer to memory address.                                 */
/*                                        => Range: Not specified.                                      */
/*              u16 CopyDataSize => Number of data blocks to be transferred. (number of transactions)   */
/*                               => Each data block size is defined DMA_Config_t. (8, 16 or 32 Bits)    */
/*                               => Range: 0 to 65535                                                   */
/* Output     : Void                                                                                    */
/* Scope      : Public                                                                                  */
/********************************************************************************************************/
void DMA_voidTransfer(DMA_CHANNEL ChannelId, volatile u32 *PER_Address, volatile u32 *MEM_Address, u16 CopyDataSize)
{
    if (ChannelId >= Channel_1 && ChannelId <= Channel_7)
    {
        /* Disable the selected channel*/
        CLR_BIT(DMA->Channel[ChannelId].CCR, 0);

        /* Set Data Size to be transfered */
        DMA->Channel[ChannelId].CNDTR = CopyDataSize;

        /* Set Periphral Address */
        DMA->Channel[ChannelId].CPAR = PER_Address;

        /* Set Memory Address */
        DMA->Channel[ChannelId].CMAR = MEM_Address;

        /* Enable DMA channel to start its operation */
        SET_BIT(DMA->Channel[ChannelId].CCR, 0);
    }
    else
    {
        // Return Error message: Wrong Input Range
    }
}

/********************************************************************************************************/
/* Description: Disable DMA channel.                                                                    */
/*              After Every DMA transaction, you should disable channel.                                */
/* Input      : DMA_CHANNEL ChannelId => Select Channel number.                                         */
/*                                    => DMA_CHANNEL Enum definition exists in DMA_interface.h file.    */
/*                                    => Range: Channel_x, x: 1 to 7                                    */
/* Output     : Void                                                                                    */
/* Scope      : Public                                                                                  */
/********************************************************************************************************/
void DMA_voidDisableChannel(DMA_CHANNEL ChannelId)
{
    if (ChannelId >= Channel_1 && ChannelId <= Channel_7)
    {
        /* Disable the selected channel*/
        CLR_BIT(DMA->Channel[ChannelId].CCR, 0);
    }
    else
    {
        // Return Error message: Wrong Input Range
    }
}


/************************************************************************************************************/
/* Description: Set call back function for each channel and for 3 interrupt type .                          */
/*              If you don't set call back functions, by default it call NOP function(Stub)                 */
/* Input      : DMA_CHANNEL ChannelId => Select Channel number.                                             */
/*                                    => DMA_CHANNEL Enum definition exists in DMA_interface.h file.        */
/*                                    => Range: Channel_x, x: 1 to 7                                        */
/*              void (*Func_Ptr)(void) => pointer to function to be excuted when a certain channel fire a   */
/*                                        certain interrupt type.                                           */
/*              DMA_Interrupt_Type InterruptFlagType => Select the interrupt type is Transfer complete,     */
/*                                                      Half Transfer complete or Tansfer error.            */
/* Output     : Void                                                                                        */
/* Scope      : Public                                                                                      */
/************************************************************************************************************/
void DMA_voidSetCallBack(DMA_CHANNEL ChannelId, void (*Func_Ptr)(void), DMA_Interrupt_Type InterruptFlagType)
{
    if (ChannelId >= Channel_1 && ChannelId <= Channel_7)
    {
        if (InterruptFlagType == TCIF)
        {
            CallBack_Handler_TransferComplete[ChannelId] = Func_Ptr;
        }
        if (InterruptFlagType == HTIF)
        {
            CallBack_Handler_HalfTransferComplete[ChannelId] = Func_Ptr;
        }
        if (InterruptFlagType == TEIF)
        {
            CallBack_Handler_TransferError[ChannelId] = Func_Ptr;
        }
    }
    else
    {
        // Return Error message: Wrong Input Range
    }
}

/****************************************************************************************************/
/* Description: DMA_1 Channel_1 ISR                                                                 */
/* Input      : Void                                                                                */
/* Output     : Void                                                                                */
/* Scope      : Private                                                                             */
/****************************************************************************************************/
void DMA1_Channel1_IRQHandler(void)
{
    if (GET_BIT(DMA->ISR, 1) == 1)
    {
        CallBack_Handler_TransferComplete[Channel_1]();
    }
    if (GET_BIT(DMA->ISR, 2) == 1)
    {
        CallBack_Handler_HalfTransferComplete[Channel_1]();
        ;
    }
    if (GET_BIT(DMA->ISR, 3) == 1)
    {
        CallBack_Handler_TransferError[Channel_1]();
    }

    DMA->IFCR = (1 << (Channel_1 * 4));
}

/****************************************************************************************************/
/* Description: DMA_1 Channel_2 ISR                                                                 */
/* Input      : Void                                                                                */
/* Output     : Void                                                                                */
/* Scope      : Private                                                                             */
/****************************************************************************************************/
void DMA1_Channel2_IRQHandler(void)
{
    if (GET_BIT(DMA->ISR, 5) == 1)
    {
        CallBack_Handler_TransferComplete[Channel_2]();
    }
    if (GET_BIT(DMA->ISR, 6) == 1)
    {
        CallBack_Handler_HalfTransferComplete[Channel_2]();
        ;
    }
    if (GET_BIT(DMA->ISR, 7) == 1)
    {
        CallBack_Handler_TransferError[Channel_2]();
    }

    DMA->IFCR = (1 << (Channel_2 * 4));
}

/****************************************************************************************************/
/* Description: DMA_1 Channel_3 ISR                                                                 */
/* Input      : Void                                                                                */
/* Output     : Void                                                                                */
/* Scope      : Private                                                                             */
/****************************************************************************************************/
void DMA1_Channel3_IRQHandler(void)
{
    if (GET_BIT(DMA->ISR, 9) == 1)
    {
        CallBack_Handler_TransferComplete[Channel_3]();
    }
    if (GET_BIT(DMA->ISR, 10) == 1)
    {
        CallBack_Handler_HalfTransferComplete[Channel_3]();
        ;
    }
    if (GET_BIT(DMA->ISR, 11) == 1)
    {
        CallBack_Handler_TransferError[Channel_3]();
    }

    DMA->IFCR = (1 << (Channel_3 * 4));
}

/****************************************************************************************************/
/* Description: DMA_1 Channel_4 ISR                                                                 */
/* Input      : Void                                                                                */
/* Output     : Void                                                                                */
/* Scope      : Private                                                                             */
/****************************************************************************************************/
void DMA1_Channel4_IRQHandler(void)
{
    if (GET_BIT(DMA->ISR, 13) == 1)
    {
        CallBack_Handler_TransferComplete[Channel_4]();
    }
    if (GET_BIT(DMA->ISR, 14) == 1)
    {
        CallBack_Handler_HalfTransferComplete[Channel_4]();
        ;
    }
    if (GET_BIT(DMA->ISR, 15) == 1)
    {
        CallBack_Handler_TransferError[Channel_4]();
    }

    DMA->IFCR = (1 << (Channel_4 * 4));
}

/****************************************************************************************************/
/* Description: DMA_1 Channel_5 ISR                                                                 */
/* Input      : Void                                                                                */
/* Output     : Void                                                                                */
/* Scope      : Private                                                                             */
/****************************************************************************************************/
void DMA1_Channel5_IRQHandler(void)
{
    if (GET_BIT(DMA->ISR, 17) == 1)
    {
        CallBack_Handler_TransferComplete[Channel_5]();
    }
    if (GET_BIT(DMA->ISR, 18) == 1)
    {
        CallBack_Handler_HalfTransferComplete[Channel_5]();
        ;
    }
    if (GET_BIT(DMA->ISR, 19) == 1)
    {
        CallBack_Handler_TransferError[Channel_5]();
    }

    DMA->IFCR = (1 << (Channel_5 * 4));
}

/****************************************************************************************************/
/* Description: DMA_1 Channel_6 ISR                                                                 */
/* Input      : Void                                                                                */
/* Output     : Void                                                                                */
/* Scope      : Private                                                                             */
/****************************************************************************************************/
void DMA1_Channel6_IRQHandler(void)
{
    if (GET_BIT(DMA->ISR, 21) == 1)
    {
        CallBack_Handler_TransferComplete[Channel_6]();
    }
    if (GET_BIT(DMA->ISR, 22) == 1)
    {
        CallBack_Handler_HalfTransferComplete[Channel_6]();
        ;
    }
    if (GET_BIT(DMA->ISR, 23) == 1)
    {
        CallBack_Handler_TransferError[Channel_6]();
    }

    DMA->IFCR = (1 << (Channel_6 * 4));
}

/****************************************************************************************************/
/* Description: DMA_1 Channel_7 ISR                                                                 */
/* Input      : Void                                                                                */
/* Output     : Void                                                                                */
/* Scope      : Private                                                                             */
/****************************************************************************************************/
void DMA1_Channel7_IRQHandler(void)
{
    if (GET_BIT(DMA->ISR, 25) == 1)
    {
        CallBack_Handler_TransferComplete[Channel_7]();
    }
    if (GET_BIT(DMA->ISR, 26) == 1)
    {
        CallBack_Handler_HalfTransferComplete[Channel_7]();
        ;
    }
    if (GET_BIT(DMA->ISR, 27) == 1)
    {
        CallBack_Handler_TransferError[Channel_7]();
    }

    DMA->IFCR = (1 << (Channel_7 * 4));
}
