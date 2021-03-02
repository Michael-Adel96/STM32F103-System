/********************************************/
/* Author   : Michael Adel                  */
/* Version  : V01                           */
/* Date     : 02 March. 2021                */
/********************************************/
#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H

/****************************************************************/
/******************* PUBLIC DEFINITIONS *************************/
/****************************************************************/


/****************************************************************/
/******************* PUBLIC FUNCTIONS ***************************/
/****************************************************************/

/***************************************************************************************************/
/* Description: => Apply Clock choice from STK_config.h file                                       */
/*              => Disable systick interrupt                                                       */
/*              => Disable systick                                                                 */
/* Input      : Void                                                                               */
/* Output     : Void                                                                               */
/* Scope      : Public                                                                             */
/***************************************************************************************************/
void STK_voidInit(void);

/***************************************************************************************************/
/* Description: Synchronous Delay function based on Polling design method,                         */
/*              The processor is stuck until the delay is finished                                 */
/* Input      : u32 Copy_u32Ticks => Number of Delay Ticks needed                                  */
/*                                => Range:0x00000001-0x00FFFFFF                                   */
/* Note       : => Delay Time = Num. of Ticks x (1/Fsystick)                                       */
/*              => Fsystick = FAHB or (FAHB/8) based in your selection in config file              */
/*              => IF System clk selected in RCC config is HSI so, FAHB = 8 MHZ                    */
/* Output     : Void                                                                               */
/* Scope      : Public                                                                             */
/***************************************************************************************************/
void STK_voidSetBusyWait(u32 Copy_u32Ticks);

/***************************************************************************************************/
/* Description: Asynchronous single Delay function based on Interrupt design method,               */
/*              The processor can run normally until the delay is completed then                   */
/*              an Interrupt is fired to notify the precessor and run user pre passed function.    */
/* Input      : u32 Copy_u32Ticks => Number of Delay Ticks needed                                  */
/*                                => Range:0x00000001-0x00FFFFFF                                   */
/*              void (*Copy_ptr) (void) => pointer to function to be excuted after                 */
/*                                         the delay is finished.                                  */
/* Note       : => Delay Time = Num. of Ticks x (1/Fsystick)                                       */
/*              => Fsystick = FAHB or (FAHB/8) based in your selection in config file              */
/*              => IF System clk selected in RCC config is HSI so, FAHB = 8 MHZ                    */
/* Output     : Void                                                                               */
/* Scope      : Public                                                                             */
/***************************************************************************************************/
void STK_voidSetIntervalSingle(u32 Copy_u32Ticks, void (*Copy_ptr) (void));

/***************************************************************************************************/
/* Description: Asynchronous periodic Delay function based on Interrupt design method,             */
/*              The processor can run normally until the delay is completed then                   */
/*              an Interrupt is fired to notify the precessor and run user pre passed function.    */
/* Input      : u32 Copy_u32Ticks => Number of Delay Ticks needed                                  */
/*                                => Range:0x00000001-0x00FFFFFF                                   */
/*              void (*Copy_ptr) (void) => pointer to function to be excuted after                 */
/*                                         the delay is finished.                                  */
/* Note       : => Delay Time = Num. of Ticks x (1/Fsystick)                                       */
/*              => Fsystick = FAHB or (FAHB/8) based in your selection in config file              */
/*              => IF System clk selected in RCC config is HSI so, FAHB = 8 MHZ                    */
/* Output     : Void                                                                               */
/* Scope      : Public                                                                             */
/***************************************************************************************************/
void STK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void (*Copy_ptr) (void));

/***************************************************************************************************/
/* Description: Stop timer and clear Load & Val Registers                                          */
/* Input      : Void                                                                               */
/* Output     : Void                                                                               */
/* Scope      : Public                                                                             */
/***************************************************************************************************/
void STK_voidStopTimer(void);

/***************************************************************************************************/
/* Description: Get the elapesed ticks number                                                      */
/* Input      : Void                                                                               */
/* Output     : u32 => Elapsed Ticks number                                                        */
/* Scope      : Public                                                                             */
/***************************************************************************************************/
u32  STK_u32GetElapsedTicks(void);

/***************************************************************************************************/
/* Description: Get the remaining ticks number                                                     */
/* Input      : Void                                                                               */
/* Output     : u32 => Remaining Ticks number                                                        */
/* Scope      : Public                                                                             */
/***************************************************************************************************/
u32  STK_u32GetRemainingTicks(void);


#endif