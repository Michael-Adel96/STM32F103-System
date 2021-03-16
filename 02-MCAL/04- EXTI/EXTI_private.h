/********************************************/
/* Author   : Michael Adel                  */
/* Version  : V01                           */
/* Date     : 07 Jan. 2021                  */
/********************************************/
#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

/* Register definition */
typedef struct
{
    volatile u32 IMR;
    volatile u32 EMR;
    volatile u32 RTSR;
    volatile u32 FTSR;
    volatile u32 SWIER;
    volatile u32 PR;
 
} EXTI_Type;

#define     EXTI     ((volatile EXTI_Type * )0x40010400)


#define     DISABLED    0
#define     ENABLED     1

#define     EXTI_IMR_LOAD_DATA      0b000000000000##EXTI_19_Int##EXTI_18_Int##EXTI_17_Int##EXTI_16_Int##EXTI_15_Int##EXTI_14_Int##EXTI_13##EXTI_12_Int##EXTI_11_Int##EXTI_10_Int##EXTI_9##EXTI_8_Int##EXTI_7_Int##EXTI_6_Int##EXTI_5_Int##EXTI_4_Int##EXTI_3_Int##EXTI_2_Int##EXTI_1_Int##EXTI_0_Int
#define     EXTI_EMR_LOAD_DATA      0b000000000000##EXTI_19_Event##EXTI_18_Event##EXTI_17_Event##EXTI_16_Event##EXTI_15_Event##EXTI_14_Event##EXTI_13##EXTI_12_Event##EXTI_11_Event##EXTI_10_Event##EXTI_9##EXTI_8_Event##EXTI_7_Event##EXTI_6_Event##EXTI_5_Event##EXTI_4_Event##EXTI_3_Event##EXTI_2_Event##EXTI_1_Event##EXTI_0_Event
#define     EXTI_RTSR_LOAD_DATA     0b000000000000##EXTI_19_RISING_EDGE_TRIGGER##EXTI_18_RISING_EDGE_TRIGGER##EXTI_17_RISING_EDGE_TRIGGER##EXTI_16_RISING_EDGE_TRIGGER##EXTI_15_RISING_EDGE_TRIGGER##EXTI_14_RISING_EDGE_TRIGGER##EXTI_13##EXTI_12_RISING_EDGE_TRIGGER##EXTI_11_RISING_EDGE_TRIGGER##EXTI_10_RISING_EDGE_TRIGGER##EXTI_9##EXTI_8_RISING_EDGE_TRIGGER##EXTI_7_RISING_EDGE_TRIGGER##EXTI_6_RISING_EDGE_TRIGGER##EXTI_5_RISING_EDGE_TRIGGER##EXTI_4_RISING_EDGE_TRIGGER##EXTI_3_RISING_EDGE_TRIGGER##EXTI_2_RISING_EDGE_TRIGGER##EXTI_1_RISING_EDGE_TRIGGER##EXTI_0_RISING_EDGE_TRIGGER
#define     EXTI_FTSR_LOAD_DATA     0b000000000000##EXTI_19_FALLING_EDGE_TRIGGER##EXTI_18_FALLING_EDGE_TRIGGER##FALLING_EDGE_TRIGGER##EXTI_16_FALLING_EDGE_TRIGGER##EXTI_15_FALLING_EDGE_TRIGGER##EXTI_14_FALLING_EDGE_TRIGGER##EXTI_13##EXTI_12_FALLING_EDGE_TRIGGER##EXTI_11_FALLING_EDGE_TRIGGER##EXTI_10_FALLING_EDGE_TRIGGER##EXTI_9##EXTI_8_FALLING_EDGE_TRIGGER##EXTI_7_FALLING_EDGE_TRIGGER##EXTI_6_FALLING_EDGE_TRIGGER##EXTI_5_FALLING_EDGE_TRIGGER##EXTI_4_FALLING_EDGE_TRIGGER##EXTI_3_FALLING_EDGE_TRIGGER##EXTI_2_FALLING_EDGE_TRIGGER##EXTI_1_FALLING_EDGE_TRIGGER##EXTI_0_FALLING_EDGE_TRIGGER




#endif