/********************************************/
/* Author   : Michael Adel                  */
/* Version  : V01                           */
/* Date     : 02 March. 2021                */
/********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"

/* pointer to function */
static void (*STK_callBackFunc)(void);

/* Interval mode either Periodic or Single */
static u8 STK_intervalMode;

/***************************************************************************************************/
/* Description: => Apply Clock choice from STK_config.h file                                       */
/*              => Disable systick interrupt                                                       */
/*              => Disable systick                                                                 */
/* Input      : Void                                                                               */
/* Output     : Void                                                                               */
/* Scope      : Public                                                                             */
/***************************************************************************************************/
void STK_voidInit(void)
{
#if STK_CLK_SRC == AHB_DIV_8
    STK_CTRL = 0x00000000;
#elif STK_CLK_SRC == AHB
    STK_CTRL = 0x00000004;
#endif
}

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
void STK_voidSetBusyWait(u32 Copy_u32Ticks)
{
    /* Check the input range */
    if (Copy_u32Ticks >= 0x00000001 && Copy_u32Ticks <= 0x00FFFFFF)
    {
    	/* Clear the timer current value register and COUNTFLAG bit in the STK_CTRL */
   	 	 STK_VAL = 0;

        /* Load the ticks value */
        STK_LOAD = Copy_u32Ticks;

        /* Start SysTick */
        SET_BIT(STK_CTRL, 0);

        /* wait the Timer to finish counting */
        while (GET_BIT(STK_CTRL, 16) == 0)
        {
        }

        /* Stop and clear Systick */
        CLR_BIT(STK_CTRL, 0);
        STK_LOAD = 0;
        STK_VAL = 0;
    }
    else
    {
        // Return Error msg: Wrong input Range
    }
}

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
void STK_voidSetIntervalSingle(u32 Copy_u32Ticks, void (*Copy_ptr)(void))
{
    /* Check the input range */
    if (Copy_u32Ticks >= 0x00000001 && Copy_u32Ticks <= 0x00FFFFFF)
    {
    	/* Clear the timer current value register and COUNTFLAG bit in the STK_CTRL */
   	 	STK_VAL = 0;

        /* Assign the passed function to ISR */
        STK_callBackFunc = Copy_ptr;

        /* Load the ticks value */
        STK_LOAD = Copy_u32Ticks;

        /* Select the interval mode */
        STK_intervalMode = STK_SINGLE_INTERVAL;

        /* Enable STK Interupt */
        SET_BIT(STK_CTRL, 1);

        /* Start SysTick */
        SET_BIT(STK_CTRL, 0);
    }
    else
    {
        // Return Error msg: Wrong input Range
    }
}

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
void STK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void (*Copy_ptr)(void))
{
    /* Check the input range */
    if (Copy_u32Ticks >= 0x00000001 && Copy_u32Ticks <= 0x00FFFFFF)
    {
    	/* Clear the timer current value register and COUNTFLAG bit in the STK_CTRL */
   	 	STK_VAL = 0;

        /* Assign the passed function to ISR */
        STK_callBackFunc = Copy_ptr;

        /* Load the ticks value */
        STK_LOAD = Copy_u32Ticks;

        /* Enable STK Interupt */
        SET_BIT(STK_CTRL, 1);

        /* Select the interval mode */
        STK_intervalMode = STK_PERIODIC_INTERVAL;

        /* Start SysTick */
        SET_BIT(STK_CTRL, 0);
    }
    else
    {
        // Return Error msg: Wrong input Range
    }
}

/***************************************************************************************************/
/* Description: Stop timer and clear Load & Val Registers                                          */
/* Input      : Void                                                                               */
/* Output     : Void                                                                               */
/* Scope      : Public                                                                             */
/***************************************************************************************************/
void STK_voidStopTimer(void)
{
    /* Disable STK interrupt */
    CLR_BIT(STK_CTRL, 1);

    /* Stop and clear Systick */
    CLR_BIT(STK_CTRL, 0);
    STK_LOAD = 0;
    STK_VAL = 0;
}

/***************************************************************************************************/
/* Description: Get the elapesed ticks number                                                      */
/* Input      : Void                                                                               */
/* Output     : u32 => Elapsed Ticks number                                                        */
/* Scope      : Public                                                                             */
/***************************************************************************************************/
u32 STK_u32GetElapsedTicks(void)
{
    u32 u32ElapsedTicks;
    u32ElapsedTicks = STK_LOAD - STK_VAL;
    return u32ElapsedTicks;
}

/***************************************************************************************************/
/* Description: Get the remaining ticks number                                                     */
/* Input      : Void                                                                               */
/* Output     : u32 => Remaining Ticks number                                                      */
/* Scope      : Public                                                                             */
/***************************************************************************************************/
u32 STK_u32GetRemainingTicks(void)
{
    u32 u32RemainingTicks;
    u32RemainingTicks = STK_VAL;
    return u32RemainingTicks;
}


/* STK Exception Handler*/
void SysTick_Handler(void)
{
    u8 Local_u8Temporary;
    if (STK_intervalMode == STK_SINGLE_INTERVAL)
    {
        /* Disable Systick interrupt */
        CLR_BIT(STK_CTRL, 1);

        /* Stop and clear Systick */
        CLR_BIT(STK_CTRL, 0);
        STK_LOAD = 0;
        STK_VAL = 0;
    }
    Local_u8Temporary = GET_BIT(STK_CTRL, 16);
    STK_callBackFunc();
}
