/********************************************/
/* Author   : Michael Adel                  */
/* Version  : V01                           */
/* Date     : 07 Jan. 2021                  */
/********************************************/
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
void EXTI_voidInit(void);
/* change the signal sense mode in runtime */
void EXTI_voidSetSignalLatch(u8 copy_u8EXTILine, u8 copy_u8EXTISenseMode);
void EXTI_voidEnableEXTIInt(u8 copy_u8EXTILine);
void EXTI_voidDisableEXTIInt(u8 copy_u8EXTILine);
void EXTI_voidEnableEXTIEvent(u8 copy_u8EXTILine);
void EXTI_voidDisableEXTIEvent(u8 copy_u8EXTILine);
void EXTI_voidSoftwareTriggerInt(u8 copy_u8EXTILine);
void EXTI_voidSetCallBack(void (*ptr) (void));



#endif