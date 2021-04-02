/********************************************/
/* Title    : DMA_1 Driver                  */
/* Author   : Michael Adel                  */
/* Version  : V01                           */
/* Date     : 29 Mar. 2021                  */
/********************************************/

/********************************************************************************/
/* Operation sequence                                                           */
/* ===================                                                          */
/* 1. Enable system RCC.                                                        */
/* 2. Enable DMA_1 Clock (RCC_DMA1_CLK).                                        */
/* 3. Enable DMA_1 needed channel Interrupt from NVIC (NVIC_u8DMA1_CHANNEL1).   */
/* 4. Create DMA_Config_t struct instance and intiallize it with all DMA        */
/*    channel configerations. (provided in DMA_interface.h file).               */
/* 5. Pass this configurations struct to DMA_voidConfigureChannel(..) function, */
/*    to intialize each channel with provided configerations.                   */
/* 6. Set call back functions for different interrupt situations.               */
/* 7. provide source, destination addresses and Data blocks number then start   */
/*    transfer data by calling DMA_voidTransfer(...) function.                  */
/********************************************************************************/

#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H

/********************************************************************************/
/************************** PUPLIC DEFINITIONS **********************************/
/********************************************************************************/
typedef enum {
    Channel_1,
    Channel_2,
    Channel_3,
    Channel_4,
    Channel_5,
    Channel_6,
    Channel_7
} DMA_CHANNEL;

typedef enum {
    Disable,
    Enable
} DMA_Status;

typedef enum {
    Low,
    Medium,
    High,
    Very_high
} DMA_Priority;

typedef enum {
    MEM_BITS_8,
	MEM_BITS_16,
	MEM_BITS_32
} DMA_MEM_Size;

typedef enum {
    PER_BITS_8,
	PER_BITS_16,
	PER_BITS_32
} DMA_PER_Size;

typedef enum {
    Read_From_PER,
    Read_From_MEM
} DMA_Transfer_DIR;

typedef enum {
    GIF,                    // Global interrupt flag
    TCIF,                   // Transfer complete flag
    HTIF,                   // Half transfer flag
    TEIF                    // Transfer error flag  
} DMA_Interrupt_Type;

typedef struct {
    DMA_CHANNEL      Channel_Id;         // Channel_Id: Channel_x, x: 1->7
    DMA_Status       MEM2MEM;            // MEM2MEM: Enable, Disable
    DMA_Priority     Channel_priority;   // Channel_priority: Low, Medium, High, Very_high
    DMA_MEM_Size     MEM_Size;           // MEM_Size: BITS_8, BITS_16, BITS_32
    DMA_PER_Size     Periphral_Size;     // Periphral_Size: BITS_8, BITS_16, BITS_32
    DMA_Status       MINC;               // Memory increment mode, MINC: Enable, Disable
    DMA_Status       PINC;               // Peripheral increment mode, PINC: Enable, Disable
    DMA_Status       CIRC;               // Circular mode, CIRC: Enable, Disable
    DMA_Transfer_DIR DIR;                // Data transfer direction, DIR: Read_From_PER, Read_From_MEM
    DMA_Status       TEIE;               // Transfer error interrupt enable, TEIE: Enable, Disable
    DMA_Status       HTIE;               // Half transfer interrupt enable, HTIE: Enable, Disable
    DMA_Status       TCIE;               // Transfer complete interrupt enable, TCIE: Enable, Disable
}DMA_Config_t;



/********************************************************************************/
/************************** PUPLIC FUNCTIONS ************************************/
/********************************************************************************/


/***************************************************************************************************/
/* Description: Used to configure a specific DMA channel.                                          */
/*              It is mandatory to configure each channel before start transfer operation.         */
/* Input      : DMA_Config_t Channelx_Config => Struct contain all DMA configerations.             */
/*                                           => Struct definition exists in DMA_interface.h file.  */
/* Output     : Void                                                                               */
/* Scope      : Public                                                                             */
/***************************************************************************************************/
void DMA_voidConfigureChannel(DMA_Config_t Channelx_Config);

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
void DMA_voidTransfer(DMA_CHANNEL ChannelId, volatile u32 *PER_Address, volatile u32 *MEM_Address, u16 CopyDataSize);

/********************************************************************************************************/
/* Description: Disable DMA channel.                                                                    */
/*              After Every DMA transaction, you should disable channel.                                */
/* Input      : DMA_CHANNEL ChannelId => Select Channel number.                                         */
/*                                    => DMA_CHANNEL Enum definition exists in DMA_interface.h file.    */
/*                                    => Range: Channel_x, x: 1 to 7                                    */
/* Output     : Void                                                                                    */
/* Scope      : Public                                                                                  */
/********************************************************************************************************/
void DMA_voidDisableChannel(DMA_CHANNEL ChannelId);

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
void DMA_voidSetCallBack(DMA_CHANNEL ChannelId, void (*Func_Ptr)(void), DMA_Interrupt_Type InterruptFlagType);


#endif