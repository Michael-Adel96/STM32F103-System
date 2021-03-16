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

static void (* EXTI_CallBack[19]) (void);

/***************************************************************************************************/
/* Description: Load Masking and trigger sense mode pre-configered data from config.h file.        */
/* Input      : Void                                                                               */
/* Output     : Void                                                                               */
/* Scope      : Public                                                                             */
/***************************************************************************************************/
void EXTI_voidInit(void)
{
    /* Intialize Interrupt mask register with startup configerations */
    EXTI->IMR = EXTI_IMR_LOAD_DATA;
    /* Intialize Event mask register with startup configerations */
    EXTI->EMR = EXTI_EMR_LOAD_DATA ;
    /* Intialize Sense trigger mode with startup configerations */
    EXTI->RTSR = EXTI_RTSR_LOAD_DATA;
    EXTI->FTSR = EXTI_FTSR_LOAD_DATA;
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
    switch(copy_u8EXTISenseMode)
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
void EXTI_voidSetCallBack(u8 copy_u8EXTILine, void (*ptr) (void))
{
    EXTI_CallBack[copy_u8EXTILine] = ptr;
}



void EXTI0_IRQHandler(void)
{
    EXTI_CallBack[EXTI_LINE_0]();
    /* Clear Pending bit */
    SET_BIT(EXTI->PR, EXTI_LINE_0);
}

void EXTI1_IRQHandler(void)
{
    EXTI_CallBack[EXTI_LINE_1]();
    /* Clear Pending bit */
    SET_BIT(EXTI->PR, EXTI_LINE_1);
}

void EXTI2_IRQHandler(void)
{
    EXTI_CallBack[EXTI_LINE_2]();
    /* Clear Pending bit */
    SET_BIT(EXTI->PR, EXTI_LINE_2);
}
void EXTI3_IRQHandler(void)
{
    EXTI_CallBack[EXTI_LINE_3]();
    /* Clear Pending bit */
    SET_BIT(EXTI->PR, EXTI_LINE_3);
}
void EXTI4_IRQHandler(void)
{
    EXTI_CallBack[EXTI_LINE_4]();
    /* Clear Pending bit */
    SET_BIT(EXTI->PR, EXTI_LINE_4);
}

void EXTI9_5_IRQHandler(void)
{

}

void EXTI15_10_IRQHandler(void)
{

}

