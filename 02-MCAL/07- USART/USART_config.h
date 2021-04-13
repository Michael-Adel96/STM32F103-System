/********************************************/
/* Title    : USART Driver                  */
/* Author   : Michael Adel                  */
/* Version  : V01                           */
/* Date     : 04 April 2021                 */
/********************************************/

#ifndef USART_CONFIG_H
#define USART_CONFIG_H

/*****************************************************************************************************/
/*********************************   USART CHANNELS CONTROL  *****************************************/
/*****************************************************************************************************/

/* Options: ENABLED, DISABLED */ 
#define     USART1_STATUS      	ENABLED
#define     USART2_STATUS       DISABLED
#define     USART3_STATUS       DISABLED
#define     USART4_STATUS      	DISABLED
#define     USART5_STATUS       DISABLED

/* ======================================================================================== */
/* Assign the Input clock for USART2,3,4,5 (MAX = 36 Mhz)                                   */
/* you have to conclude this info from RCC settings based upon APB1 clock and system clock  */
/* Note: The entered value will not force USART system to work with this value,             */
/*       its only concluded value from RCC clock system settings,                           */
/*       conslusion is based on the user, and wrong concluded values will cause failure     */
/*       in USART BAUD RATE calculations.                                                   */
/* Example: If HSI (8 MHz) or HSE (8 MHz) is used without any prescalers and                */
/*          APB1 has no prescalers so, F_PCLK1_MHZ = 8                                      */
/* UNIT is MHz                                                                              */
/* ======================================================================================== */
#define     F_PCLK1_MHZ     8
/* ======================================================================================== */
/* Assign the Input clock for USART1 (MAX = 72 Mhz)                                         */
/* you have to conclude this info from RCC settings based upon APB2 clock and system clock  */
/* Note: The entered value will not force USART system to work with this value,             */
/*       its only concluded value from RCC clock system settings,                           */
/*       conslusion is based on the user, and wrong concluded values will cause failure     */
/*       in USART BAUD RATE calculations.                                                   */
/* Example: If HSI (8 MHz) or HSE (8 MHz) is used without any prescalers and                */
/*          APB2 has no prescalers so, F_PCLK1_MHZ = 8                                      */
/* UNIT is MHz                                                                              */
/* ======================================================================================== */
#define     F_PCLK2_MHZ     8


/*****************************************************************************************************/
/*********************************   USART 1 CONFIGURATIONS  *****************************************/
/*****************************************************************************************************/

/* Options: 9600, 115200 */
#define     USART1_BAUD_RATE                           9600

/* Options: BIT_8, BIT_9 */ 
#define     USART1_WORD_LENGTH                         BIT_8

/* Options: IDLE_LINE, ADDRESS_MARK */
#define     USART1_WAKEUP_METHOD                       IDLE_LINE

/* Options: ENABLED, DISABLED */    
#define     USART1_PARITY_CONTROL_ENABLE               DISABLED

/* Considered only when USART1_PARITY_CONTROL_ENABLE is ENABLED */
/* Options: EVEN_PARITY, ODD_PARITY */
#define     USART1_PARITY_SELECTION                    EVEN_PARITY

/* Options: ENABLED, DISABLED */    
#define     USART1_PARITY_ERROR_INT                    DISABLED

/* Options: ENABLED, DISABLED */    
#define     USART1_TRANSMIT_DATA_REG_EMPTY_INT         DISABLED

/* Options: ENABLED, DISABLED */
#define     USART1_TRANSMISSION_COMPLETE_INT_ENABLE    DISABLED

/* Options: ENABLED, DISABLED */
#define     USART1_READ_DATA_REGISTER_NOT_EMPTY_INT    ENABLED

/* Options: ENABLED, DISABLED */
#define     USART1_IDLE_DETECTED_INT_ENABLE            DISABLED

/* Options: ENABLED, DISABLED */
#define     USART1_TRANSMITTER_ENABLE                  ENABLED

/* Options: ENABLED, DISABLED */
#define     USART1_RECEIVER_ENABLE                     ENABLED

/* Options: ACTIVE_MODE, MUTE_MODE*/
#define     USART1_RECEIVER_WAKEUP                     ACTIVE_MODE

/* Options: NO_BREAK_CHARACTER_TRANSMITTED, BREAK_CHARACTER_TRANSMITTED	*/
#define     USART1_SEND_BREAK                          NO_BREAK_CHARACTER_TRANSMITTED

/* Options: ENABLED, DISABLED */
#define     USART1_ENABLE_DMA_TRANSMITTER             DISABLED

/* Options: ENABLED, DISABLED */
#define     USART1_ENABLE_DMA_RECEIVER                DISABLED 

/* Options: STOP_BIT_1, STOP_BIT_0_5 ,STOP_BIT_2, STOP_BIT_1_5 */
#define     USART1_STOP_BITS                          STOP_BIT_1
/*****************************************************************************************************/


/*****************************************************************************************************/
/*********************************   USART 2 CONFIGURATIONS  *****************************************/
/*****************************************************************************************************/

/* Options: 9600, 115200 */
#define     USART2_BAUD_RATE                           9600

/* Options: BIT_8, BIT_9 */ 
#define     USART2_WORD_LENGTH                         BIT_8

/* Options: IDLE_LINE, ADDRESS_MARK */
#define     USART2_WAKEUP_METHOD                       IDLE_LINE

/* Options: ENABLED, DISABLED */    
#define     USART2_PARITY_CONTROL_ENABLE               DISABLED

/* Considered only when USART2_PARITY_CONTROL_ENABLE is ENABLED */
/* Options: EVEN_PARITY, ODD_PARITY */
#define     USART2_PARITY_SELECTION                    EVEN_PARITY

/* Options: ENABLED, DISABLED */    
#define     USART2_PARITY_ERROR_INT                    DISABLED

/* Options: ENABLED, DISABLED */    
#define     USART2_TRANSMIT_DATA_REG_EMPTY_INT         DISABLED

/* Options: ENABLED, DISABLED */
#define     USART2_TRANSMISSION_COMPLETE_INT_ENABLE    DISABLED

/* Options: ENABLED, DISABLED */
#define     USART2_READ_DATA_REGISTER_NOT_EMPTY_INT    DISABLED

/* Options: ENABLED, DISABLED */
#define     USART2_IDLE_DETECTED_INT_ENABLE            DISABLED

/* Options: ENABLED, DISABLED */
#define     USART2_TRANSMITTER_ENABLE                  ENABLED

/* Options: ENABLED, DISABLED */
#define     USART2_RECEIVER_ENABLE                     ENABLED

/* Options: ACTIVE_MODE, MUTE_MODE*/
#define     USART2_RECEIVER_WAKEUP                     ACTIVE_MODE

/* Options: NO_BREAK_CHARACTER_TRANSMITTED, BREAK_CHARACTER_TRANSMITTED	*/
#define     USART2_SEND_BREAK                          NO_BREAK_CHARACTER_TRANSMITTED

/* Options: ENABLED, DISABLED */
#define     USART2_ENABLE_DMA_TRANSMITTER             DISABLED

/* Options: ENABLED, DISABLED */
#define     USART2_ENABLE_DMA_RECEIVER                DISABLED  

/* Options: STOP_BIT_1, STOP_BIT_0_5 ,STOP_BIT_2, STOP_BIT_1_5 */
#define     USART2_STOP_BITS                          STOP_BIT_1
/*****************************************************************************************************/

/*****************************************************************************************************/
/*********************************   USART 3 CONFIGURATIONS  *****************************************/
/*****************************************************************************************************/

/* Options: 9600, 115200 */
#define     USART3_BAUD_RATE                           9600

/* Options: BIT_8, BIT_9 */ 
#define     USART3_WORD_LENGTH                         BIT_8

/* Options: IDLE_LINE, ADDRESS_MARK */
#define     USART3_WAKEUP_METHOD                       IDLE_LINE

/* Options: ENABLED, DISABLED */    
#define     USART3_PARITY_CONTROL_ENABLE               DISABLED

/* Considered only when USART3_PARITY_CONTROL_ENABLE is ENABLED */
/* Options: EVEN_PARITY, ODD_PARITY */
#define     USART3_PARITY_SELECTION                    EVEN_PARITY

/* Options: ENABLED, DISABLED */    
#define     USART3_PARITY_ERROR_INT                    DISABLED

/* Options: ENABLED, DISABLED */    
#define     USART3_TRANSMIT_DATA_REG_EMPTY_INT         DISABLED

/* Options: ENABLED, DISABLED */
#define     USART3_TRANSMISSION_COMPLETE_INT_ENABLE    DISABLED

/* Options: ENABLED, DISABLED */
#define     USART3_READ_DATA_REGISTER_NOT_EMPTY_INT    DISABLED

/* Options: ENABLED, DISABLED */
#define     USART3_IDLE_DETECTED_INT_ENABLE            DISABLED

/* Options: ENABLED, DISABLED */
#define     USART3_TRANSMITTER_ENABLE                  ENABLED

/* Options: ENABLED, DISABLED */
#define     USART3_RECEIVER_ENABLE                     ENABLED

/* Options: ACTIVE_MODE, MUTE_MODE*/
#define     USART3_RECEIVER_WAKEUP                     ACTIVE_MODE

/* Options: NO_BREAK_CHARACTER_TRANSMITTED, BREAK_CHARACTER_TRANSMITTED	*/
#define     USART3_SEND_BREAK                          NO_BREAK_CHARACTER_TRANSMITTED

/* Options: ENABLED, DISABLED */
#define     USART3_ENABLE_DMA_TRANSMITTER             DISABLED

/* Options: ENABLED, DISABLED */
#define     USART3_ENABLE_DMA_RECEIVER                DISABLED  

/* Options: STOP_BIT_1, STOP_BIT_0_5 ,STOP_BIT_2, STOP_BIT_1_5 */
#define     USART3_STOP_BITS                          STOP_BIT_1
/*****************************************************************************************************/

/*****************************************************************************************************/
/*********************************   USART 4 CONFIGURATIONS  *****************************************/
/*****************************************************************************************************/

/* Options: 9600, 115200 */
#define     USART4_BAUD_RATE                           9600

/* Options: BIT_8, BIT_9 */ 
#define     USART4_WORD_LENGTH                         BIT_8

/* Options: IDLE_LINE, ADDRESS_MARK */
#define     USART4_WAKEUP_METHOD                       IDLE_LINE

/* Options: ENABLED, DISABLED */    
#define     USART4_PARITY_CONTROL_ENABLE               DISABLED

/* Considered only when USART4_PARITY_CONTROL_ENABLE is ENABLED */
/* Options: EVEN_PARITY, ODD_PARITY */
#define     USART4_PARITY_SELECTION                    EVEN_PARITY

/* Options: ENABLED, DISABLED */    
#define     USART4_PARITY_ERROR_INT                    DISABLED

/* Options: ENABLED, DISABLED */    
#define     USART4_TRANSMIT_DATA_REG_EMPTY_INT         DISABLED

/* Options: ENABLED, DISABLED */
#define     USART4_TRANSMISSION_COMPLETE_INT_ENABLE    DISABLED

/* Options: ENABLED, DISABLED */
#define     USART4_READ_DATA_REGISTER_NOT_EMPTY_INT    DISABLED

/* Options: ENABLED, DISABLED */
#define     USART4_IDLE_DETECTED_INT_ENABLE            DISABLED

/* Options: ENABLED, DISABLED */
#define     USART4_TRANSMITTER_ENABLE                  ENABLED

/* Options: ENABLED, DISABLED */
#define     USART4_RECEIVER_ENABLE                     ENABLED

/* Options: ACTIVE_MODE, MUTE_MODE*/
#define     USART4_RECEIVER_WAKEUP                     ACTIVE_MODE

/* Options: NO_BREAK_CHARACTER_TRANSMITTED, BREAK_CHARACTER_TRANSMITTED	*/
#define     USART4_SEND_BREAK                          NO_BREAK_CHARACTER_TRANSMITTED

/* Options: ENABLED, DISABLED */
#define     USART4_ENABLE_DMA_TRANSMITTER             DISABLED

/* Options: ENABLED, DISABLED */
#define     USART4_ENABLE_DMA_RECEIVER                DISABLED  

/* Options: STOP_BIT_1, STOP_BIT_2 */
#define     USART4_STOP_BITS                          STOP_BIT_1
/*****************************************************************************************************/

/*****************************************************************************************************/
/*********************************   USART 5 CONFIGURATIONS  *****************************************/
/*****************************************************************************************************/

/* Options: 9600, 115200 */
#define     USART5_BAUD_RATE                           9600

/* Options: BIT_8, BIT_9 */ 
#define     USART5_WORD_LENGTH                         BIT_8

/* Options: IDLE_LINE, ADDRESS_MARK */
#define     USART5_WAKEUP_METHOD                       IDLE_LINE

/* Options: ENABLED, DISABLED */    
#define     USART5_PARITY_CONTROL_ENABLE               DISABLED

/* Considered only when USART5_PARITY_CONTROL_ENABLE is ENABLED */
/* Options: EVEN_PARITY, ODD_PARITY */
#define     USART5_PARITY_SELECTION                    EVEN_PARITY

/* Options: ENABLED, DISABLED */    
#define     USART5_PARITY_ERROR_INT                    DISABLED

/* Options: ENABLED, DISABLED */    
#define     USART5_TRANSMIT_DATA_REG_EMPTY_INT         DISABLED

/* Options: ENABLED, DISABLED */
#define     USART5_TRANSMISSION_COMPLETE_INT_ENABLE    DISABLED

/* Options: ENABLED, DISABLED */
#define     USART5_READ_DATA_REGISTER_NOT_EMPTY_INT    DISABLED

/* Options: ENABLED, DISABLED */
#define     USART5_IDLE_DETECTED_INT_ENABLE            DISABLED

/* Options: ENABLED, DISABLED */
#define     USART5_TRANSMITTER_ENABLE                  ENABLED

/* Options: ENABLED, DISABLED */
#define     USART5_RECEIVER_ENABLE                     ENABLED

/* Options: ACTIVE_MODE, MUTE_MODE*/
#define     USART5_RECEIVER_WAKEUP                     ACTIVE_MODE

/* Options: NO_BREAK_CHARACTER_TRANSMITTED, BREAK_CHARACTER_TRANSMITTED	*/
#define     USART5_SEND_BREAK                          NO_BREAK_CHARACTER_TRANSMITTED

/* Options: STOP_BIT_1, STOP_BIT_2 */
#define     USART5_STOP_BITS                          STOP_BIT_1
/*****************************************************************************************************/


#endif
