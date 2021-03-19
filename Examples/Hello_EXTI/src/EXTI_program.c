/********************************************/
/* Author   : Michael Adel                  */
/* Version  : V01                           */
/* Date     : 07 Jan. 2021                  */
/********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

/* Array of pointers to ISR callback functions */
static void (*EXTI_CallBack[19])(void);

/***************************************************************************************************/
/* Description: NOP function loaded to all pointers to functions to avoid going to hard fault      */
/*              when there's something incorrect in user's intializations.                         */
/* Input      : Void                                                                               */
/* Output     : Void                                                                               */
/* Scope      : Private                                                                            */
/***************************************************************************************************/
static void stub (void)
{
    asm("NOP");
}

/***************************************************************************************************/
/* Description: Load Masking and trigger sense mode pre-configered data from config.h file.        */
/* Input      : Void                                                                               */
/* Output     : Void                                                                               */
/* Scope      : Public                                                                             */
/***************************************************************************************************/
void EXTI_voidInit(void)
{
    u8 count;
    /* Intialize Interrupt mask register with startup configerations */
    EXTI->IMR = EXTI_IMR_LOAD_DATA;
    /* Intialize Event mask register with startup configerations */
    EXTI->EMR = EXTI_EMR_LOAD_DATA;
    /* Intialize Sense trigger mode with startup configerations */
    EXTI->RTSR = EXTI_RTSR_LOAD_DATA;
    EXTI->FTSR = EXTI_FTSR_LOAD_DATA;

    /* Intialize all pointers to functions to point to NOP function */
    for(count = 0; count<19; count++)
    {
        EXTI_CallBack[count] = stub;
    }
}

/***************************************************************************************************/
/* Description: Select trigger sense mode during runtime.                                          */
/* Input      : u8 copy_u8EXTILine => choose EXTI line number                                      */
/*                                 => Range: EXTI_LINE_x, x: 0 to 19                               */
/*              u8 copy_u8EXTISenseMode => Choose triggering mode                                  */
/*                                      => Range: EXTI_RISING_EDGE_TRIGGER,                        */
/*                                                EXTI_FALLING_EDGE_TRIGGER,                       */
/*                                                EXTI_BOTH_EDGES_TRIGGER                          */
/* Output     : Void                                                                               */
/* Scope      : Public                                                                             */
/***************************************************************************************************/
void EXTI_voidSetSignalLatch(u8 copy_u8EXTILine, u8 copy_u8EXTISenseMode)
{
    switch (copy_u8EXTISenseMode)
    {
    case EXTI_RISING_EDGE_TRIGGER:
        SET_BIT(EXTI->RTSR, copy_u8EXTILine);
        CLR_BIT(EXTI->FTSR, copy_u8EXTILine);
        break;
    case EXTI_FALLING_EDGE_TRIGGER:
        CLR_BIT(EXTI->RTSR, copy_u8EXTILine);
        SET_BIT(EXTI->FTSR, copy_u8EXTILine);
        break;
    case EXTI_BOTH_EDGES_TRIGGER:
        SET_BIT(EXTI->RTSR, copy_u8EXTILine);
        SET_BIT(EXTI->FTSR, copy_u8EXTILine);
        break;
    }
}

/***************************************************************************************************/
/* Description: Enable EXTI Interrupt line during runtime. (unmasking)                             */
/* Input      : u8 copy_u8EXTILine => choose EXTI line number                                      */
/*                                 => Range: EXTI_LINE_x, x: 0 to 19                               */
/* Output     : Void                                                                               */
/* Scope      : Public                                                                             */
/***************************************************************************************************/
void EXTI_voidEnableEXTIInt(u8 copy_u8EXTILine)
{
    SET_BIT(EXTI->IMR, copy_u8EXTILine);
}
/***************************************************************************************************/
/* Description: Disable EXTI Interrupt line during runtime. (masking)                              */
/* Input      : u8 copy_u8EXTILine => choose EXTI line number                                      */
/*                                 => Range: EXTI_LINE_x, x: 0 to 19                               */
/* Output     : Void                                                                               */
/* Scope      : Public                                                                             */
/***************************************************************************************************/
void EXTI_voidDisableEXTIInt(u8 copy_u8EXTILine)
{
    CLR_BIT(EXTI->IMR, copy_u8EXTILine);
}

/***************************************************************************************************/
/* Description: Enable EXTI Event line during runtime. (unmasking)                                 */
/* Input      : u8 copy_u8EXTILine => choose EXTI line number                                      */
/*                                 => Range: EXTI_LINE_x, x: 0 to 19                               */
/* Output     : Void                                                                               */
/* Scope      : Public                                                                             */
/***************************************************************************************************/
void EXTI_voidEnableEXTIEvent(u8 copy_u8EXTILine)
{
    SET_BIT(EXTI->EMR, copy_u8EXTILine);
}
/***************************************************************************************************/
/* Description: Disable EXTI Event line during runtime. (masking)                                  */
/* Input      : u8 copy_u8EXTILine => choose EXTI line number                                      */
/*                                 => Range: EXTI_LINE_x, x: 0 to 19                               */
/* Output     : Void                                                                               */
/* Scope      : Public                                                                             */
/***************************************************************************************************/
void EXTI_voidDisableEXTIEvent(u8 copy_u8EXTILine)
{
    CLR_BIT(EXTI->EMR, copy_u8EXTILine);
}

/***************************************************************************************************/
/* Description: Fire Software interrupt event on a certain EXTI line                               */
/* Input      : u8 copy_u8EXTILine => choose EXTI line number                                      */
/*                                 => Range: EXTI_LINE_x, x: 0 to 19                               */
/* Output     : Void                                                                               */
/* Scope      : Public                                                                             */
/***************************************************************************************************/
void EXTI_voidSoftwareTriggerInt(u8 copy_u8EXTILine)
{
    SET_BIT(EXTI->PR, copy_u8EXTILine);
    SET_BIT(EXTI->SWIER, copy_u8EXTILine);
}

/***************************************************************************************************/
/* Description: Set callback function for a certain EXTI line ISR                                  */
/* Input      : u8 copy_u8EXTILine => choose EXTI line number                                      */
/*                                 => Range: EXTI_LINE_x, x: 0 to 19                               */
/*              void (*ptr) (void) => pointer to function to be excuted when                       */
/*                                    a certain EXTI is fired.                                     */
/* Output     : Void                                                                               */
/* Scope      : Public                                                                             */
/***************************************************************************************************/
void EXTI_voidSetCallBack(u8 copy_u8EXTILine, void (*ptr)(void))
{
    EXTI_CallBack[copy_u8EXTILine] = ptr;
}


/***************************************************************************************************/
/* Description: EXTI0 Interrupt service routine Handler.                                           */
/* Note_1     : ISR assigned by the user Indirectly through EXTI_voidSetCallBack() function.       */
/* Note_2     : if the ISR running twice times for one Int. fire, add some "NOP" Instructions      */
/*              after clearing pending flag to give it suitable time to clear pending flag.        */
/* Scope      : Private                                                                            */
/***************************************************************************************************/
void EXTI0_IRQHandler(void)
{
    EXTI_CallBack[EXTI_LINE_0]();
    /* Clear Pending bit */
    SET_BIT(EXTI->PR, EXTI_LINE_0);
}
/***************************************************************************************************/
/* Description: EXTI1 Interrupt service routine Handler.                                           */
/* Note_1     : ISR assigned by the user Indirectly through EXTI_voidSetCallBack() function.       */
/* Note_2     : if the ISR running twice times for one Int. fire, add some "NOP" Instructions      */
/*              after clearing pending flag to give it suitable time to clear pending flag.        */
/* Scope      : Private                                                                            */
/***************************************************************************************************/
void EXTI1_IRQHandler(void)
{
    EXTI_CallBack[EXTI_LINE_1]();
    /* Clear Pending bit */
    SET_BIT(EXTI->PR, EXTI_LINE_1);
}
/***************************************************************************************************/
/* Description: EXTI2 Interrupt service routine Handler.                                           */
/* Note_1     : ISR assigned by the user Indirectly through EXTI_voidSetCallBack() function.       */
/* Note_2     : if the ISR running twice times for one Int. fire, add some "NOP" Instructions      */
/*              after clearing pending flag to give it suitable time to clear pending flag.        */
/* Scope      : Private                                                                            */
/***************************************************************************************************/
void EXTI2_IRQHandler(void)
{
    EXTI_CallBack[EXTI_LINE_2]();
    /* Clear Pending bit */
    SET_BIT(EXTI->PR, EXTI_LINE_2);
}

/***************************************************************************************************/
/* Description: EXTI3 Interrupt service routine Handler.                                           */
/* Note_1     : ISR assigned by the user Indirectly through EXTI_voidSetCallBack() function.       */
/* Note_2     : if the ISR running twice times for one Int. fire, add some "NOP" Instructions      */
/*              after clearing pending flag to give it suitable time to clear pending flag.        */
/* Scope      : Private                                                                            */
/***************************************************************************************************/
void EXTI3_IRQHandler(void)
{
    EXTI_CallBack[EXTI_LINE_3]();
    /* Clear Pending bit */
    SET_BIT(EXTI->PR, EXTI_LINE_3);
}

/***************************************************************************************************/
/* Description: EXTI4 Interrupt service routine Handler.                                           */
/* Note_1     : ISR assigned by the user Indirectly through EXTI_voidSetCallBack() function.       */
/* Note_2     : if the ISR running twice times for one Int. fire, add some "NOP" Instructions      */
/*              after clearing pending flag to give it suitable time to clear pending flag.        */
/* Scope      : Private                                                                            */
/***************************************************************************************************/
void EXTI4_IRQHandler(void)
{
    EXTI_CallBack[EXTI_LINE_4]();
    /* Clear Pending bit */
    SET_BIT(EXTI->PR, EXTI_LINE_4);
}

/***************************************************************************************************/
/* Description: Interrupt service routine Handler for EXTIx (x: 5 to 9).                           */
/* Note_1     : ISR assigned by the user Indirectly through EXTI_voidSetCallBack() function.       */
/* Note_2     : if the ISR running twice times for one Int. fire, add some "NOP" Instructions      */
/*              after clearing pending flag to give it suitable time to clear pending flag.        */
/* Note_3      : You can change the priorities of Interrupts by change "If" condtion order.        */
/* Scope      : Private                                                                            */
/***************************************************************************************************/
void EXTI9_5_IRQHandler(void)
{
    if (GET_BIT(EXTI->PR, EXTI_LINE_5))
    {
        EXTI_CallBack[EXTI_LINE_5]();
        SET_BIT(EXTI->PR, EXTI_LINE_5);
    }
    if (GET_BIT(EXTI->PR, EXTI_LINE_6))
    {
        EXTI_CallBack[EXTI_LINE_6]();
        SET_BIT(EXTI->PR, EXTI_LINE_6);
    }
    if (GET_BIT(EXTI->PR, EXTI_LINE_7))
    {
        EXTI_CallBack[EXTI_LINE_7]();
        SET_BIT(EXTI->PR, EXTI_LINE_7);
    }
    if (GET_BIT(EXTI->PR, EXTI_LINE_8))
    {
        EXTI_CallBack[EXTI_LINE_8]();
        SET_BIT(EXTI->PR, EXTI_LINE_8);
    }
    if (GET_BIT(EXTI->PR, EXTI_LINE_9))
    {
        EXTI_CallBack[EXTI_LINE_9]();
        SET_BIT(EXTI->PR, EXTI_LINE_9);
    }

}
/***************************************************************************************************/
/* Description: Interrupt service routine Handler for EXTIx (x: 10 to 15).                         */
/* Note_1     : ISR assigned by the user Indirectly through EXTI_voidSetCallBack() function.       */
/* Note_2     : if the ISR running twice times for one Int. fire, add some "NOP" Instructions      */
/*              after clearing pending flag to give it suitable time to clear pending flag.        */
/* Note_3      : You can change the priorities of Interrupts by change "If" condtion order.        */
/* Scope      : Private                                                                            */
/***************************************************************************************************/
void EXTI15_10_IRQHandler(void)
{
    if (GET_BIT(EXTI->PR, EXTI_LINE_10))
    {
        EXTI_CallBack[EXTI_LINE_10]();
        SET_BIT(EXTI->PR, EXTI_LINE_10);
    }
    if (GET_BIT(EXTI->PR, EXTI_LINE_11))
    {
        EXTI_CallBack[EXTI_LINE_11]();
        SET_BIT(EXTI->PR, EXTI_LINE_11);
    }
    if (GET_BIT(EXTI->PR, EXTI_LINE_12))
    {
        EXTI_CallBack[EXTI_LINE_12]();
        SET_BIT(EXTI->PR, EXTI_LINE_12);
    }
    if (GET_BIT(EXTI->PR, EXTI_LINE_13))
    {
        EXTI_CallBack[EXTI_LINE_13]();
        SET_BIT(EXTI->PR, EXTI_LINE_13);
    }
    if (GET_BIT(EXTI->PR, EXTI_LINE_14))
    {
        EXTI_CallBack[EXTI_LINE_14]();
        SET_BIT(EXTI->PR, EXTI_LINE_14);
    }
    if (GET_BIT(EXTI->PR, EXTI_LINE_15))
    {
        EXTI_CallBack[EXTI_LINE_15]();
        SET_BIT(EXTI->PR, EXTI_LINE_15);
    }
}

