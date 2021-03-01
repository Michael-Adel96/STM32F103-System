/********************************************/
/* Author	: Michael Adel					*/
/* Version	: V01							*/
/* Date		: 13 Nov. 2020					*/
/********************************************/
#ifndef _RCC_CONFIG_H
#define _RCC_CONFIG_H

/*
	Options:	RCC_HSE_CRYSTAL
				RCC_HSE_RC
				RCC_HSI
				RCC_PLL			
*/
#define RCC_CLOCK_TYPE	RCC_HSE_CRYSTAL

/* Discription: Choose PLL clock source input 						*/
/* Range: RCC_PLL_IN_HSI_DIV_2				  						*/
/*		  RCC_PLL_IN_HSE_DIV_2				  						*/
/*		  RCC_PLL_IN_HSE					  						*/
/* Note  : Select value only if you have PLL as input clock source  */
#if RCC_CLOCK_TYPE == RCC_PLL
	#define RCC_PLL_INPUT	RCC_PLL_IN_HSE_DIV_2
#endif

/* Discription: Choose PLL multiplication factor					*/
/* Range: From 2 to 16				  								*/
/* Note  :* Select value only if you have PLL as input clock source */
/* 		  * These bits are written by software to define the PLL 	*/
/*			multiplication factor. These bits can be written only 	*/
/*			when PLL is disabled.									*/	
/* Caution: The PLL output frequency must not exceed 72 MHz			*/
#if RCC_CLOCK_TYPE == RCC_PLL
	#define RCC_PLL_MUL_VAL		4	
#endif


#endif