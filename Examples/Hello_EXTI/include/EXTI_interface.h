/********************************************/
/* Author   : Michael Adel                  */
/* Version  : V01                           */
/* Date     : 07 Jan. 2021                  */
/********************************************/

/************************************************************************/
/* EXTI Functionality                                                   */
/* ==================                                                   */
/* 1. Intialize RCC_SYS_CLK                                             */
/* 2. Enable EXTI port clock RCC_CLK_PORTx                              */
/* 3. Enable AFIO clock RCC_CLK_AFIO                                    */
/* 4. Intialize NVIC NVIC_Init                                          */
/* 5. Enable the used EXTI line from NVIC (NVIC_Enable_Int(EXTI_x))     */
/* 6. Set EXTI pin mode from GPIO (input pull up/down)                  */
/* 7. Configure AFIO for the selected EXTI Line from GPIO API           */
/* 8. Set Call back functions for each EXTI Line                        */
/* 9. Intialize EXTI (EXTI_Init())                                      */
/* 10. Set Signal sense mode for each EXTI Line (Option A)              */
/* 11. Enable EXTI Int. (Option A)                                      */
/* NOTE => user have to options to Enable/Disable EXTI Int and          */
/*         Selecting Signal sense mode which are:                       */
/*          A. Runtime method: Using normal API provided finctions in   */
/*             EXTI_interface.h file.                                   */
/*          B. Compilation time method: using configeration parameters  */
/*             in EXTI_config.h file which is loaded when calling       */
/*             EXTI_Init() function.                                    */
/************************************************************************/


#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

/*******************************************************/
/************** PUBLIC DEFINITIONS *********************/
/*******************************************************/




/* EXTI lines numbers */
#define     EXTI_LINE_0         0
#define     EXTI_LINE_1         1
#define     EXTI_LINE_2         2
#define     EXTI_LINE_3         3
#define     EXTI_LINE_4         4
#define     EXTI_LINE_5         5
#define     EXTI_LINE_6         6
#define     EXTI_LINE_7         7
#define     EXTI_LINE_8         8
#define     EXTI_LINE_9         9
#define     EXTI_LINE_10        10
#define     EXTI_LINE_11        11
#define     EXTI_LINE_12        12
#define     EXTI_LINE_13        13
#define     EXTI_LINE_14        14
#define     EXTI_LINE_15        15
#define     EXTI_LINE_16        16
#define     EXTI_LINE_17        17
#define     EXTI_LINE_18        18
#define     EXTI_LINE_19        19

/* Trigger sense modes */
#define     EXTI_RISING_EDGE_TRIGGER        0
#define     EXTI_FALLING_EDGE_TRIGGER       1
#define     EXTI_BOTH_EDGES_TRIGGER         2

/*******************************************************/
/************** PUBLIC FUNCTIONS ***********************/
/*******************************************************/

/***************************************************************************************************/
/* Description: Load Masking and trigger sense mode pre-configered data from config.h file.        */
/* Input      : Void                                                                               */
/* Output     : Void                                                                               */
/* Scope      : Public                                                                             */
/***************************************************************************************************/
void EXTI_voidInit(void);

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
void EXTI_voidSetSignalLatch(u8 copy_u8EXTILine, u8 copy_u8EXTISenseMode);

/***************************************************************************************************/
/* Description: Enable EXTI Interrupt line during runtime. (unmasking)                             */
/* Input      : u8 copy_u8EXTILine => choose EXTI line number                                      */
/*                                 => Range: EXTI_LINE_x, x: 0 to 19                               */
/* Output     : Void                                                                               */
/* Scope      : Public                                                                             */
/***************************************************************************************************/
void EXTI_voidEnableEXTIInt(u8 copy_u8EXTILine);

/***************************************************************************************************/
/* Description: Disable EXTI Interrupt line during runtime. (masking)                              */
/* Input      : u8 copy_u8EXTILine => choose EXTI line number                                      */
/*                                 => Range: EXTI_LINE_x, x: 0 to 19                               */
/* Output     : Void                                                                               */
/* Scope      : Public                                                                             */
/***************************************************************************************************/
void EXTI_voidDisableEXTIInt(u8 copy_u8EXTILine);

/***************************************************************************************************/
/* Description: Enable EXTI Event line during runtime. (unmasking)                                 */
/* Input      : u8 copy_u8EXTILine => choose EXTI line number                                      */
/*                                 => Range: EXTI_LINE_x, x: 0 to 19                               */
/* Output     : Void                                                                               */
/* Scope      : Public                                                                             */
/***************************************************************************************************/
void EXTI_voidEnableEXTIEvent(u8 copy_u8EXTILine);

/***************************************************************************************************/
/* Description: Disable EXTI Event line during runtime. (masking)                                  */
/* Input      : u8 copy_u8EXTILine => choose EXTI line number                                      */
/*                                 => Range: EXTI_LINE_x, x: 0 to 19                               */
/* Output     : Void                                                                               */
/* Scope      : Public                                                                             */
/***************************************************************************************************/
void EXTI_voidDisableEXTIEvent(u8 copy_u8EXTILine);

/***************************************************************************************************/
/* Description: Fire Software interrupt event on a certain EXTI line                               */
/* Input      : u8 copy_u8EXTILine => choose EXTI line number                                      */
/*                                 => Range: EXTI_LINE_x, x: 0 to 19                               */
/* Output     : Void                                                                               */
/* Scope      : Public                                                                             */
/***************************************************************************************************/
void EXTI_voidSoftwareTriggerInt(u8 copy_u8EXTILine);

/***************************************************************************************************/
/* Description: Set callback function for a certain EXTI line ISR                                  */
/* Input      : u8 copy_u8EXTILine => choose EXTI line number                                      */
/*                                 => Range: EXTI_LINE_x, x: 0 to 19                               */
/*              void (*ptr) (void) => pointer to function to be excuted when                       */
/*                                    a certain EXTI is fired.                                     */
/* Output     : Void                                                                               */
/* Scope      : Public                                                                             */
/***************************************************************************************************/
void EXTI_voidSetCallBack(u8 copy_u8EXTILine, void (*ptr) (void));



#endif