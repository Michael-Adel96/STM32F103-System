/********************************************/
/* Author	: Michael Adel					*/
/* Version	: V01							*/
/* Date		: 25 Nov. 2020					*/
/********************************************/

#ifndef _GPIO_PRIVATE_H
#define _GPIO_PRIVATE_H

#define GPIOA_BASE_ADDRESS	0x40010800
#define GPIOB_BASE_ADDRESS	0x40010C00
#define GPIOC_BASE_ADDRESS	0x40011000
#define AFIO_BASE_ADDRESS   0x40010000

/* GPIO A REGISTER DEFINITION */
#define GPIOA_CRL			*((volatile u32*)(GPIOA_BASE_ADDRESS + 0x00))
#define GPIOA_CRH			*((volatile u32*)(GPIOA_BASE_ADDRESS + 0x04))
#define GPIOA_IDR			*((volatile u32*)(GPIOA_BASE_ADDRESS + 0x08))
#define GPIOA_ODR			*((volatile u32*)(GPIOA_BASE_ADDRESS + 0x0C))
#define GPIOA_BSRR			*((volatile u32*)(GPIOA_BASE_ADDRESS + 0x10))
#define GPIOA_BRR			*((volatile u32*)(GPIOA_BASE_ADDRESS + 0x14))
#define GPIOA_LCKR			*((volatile u32*)(GPIOA_BASE_ADDRESS + 0x18))

/* GPIO B REGISTER DEFINITION */
#define GPIOB_CRL			*((volatile u32*)(GPIOB_BASE_ADDRESS + 0x00))
#define GPIOB_CRH			*((volatile u32*)(GPIOB_BASE_ADDRESS + 0x04))
#define GPIOB_IDR			*((volatile u32*)(GPIOB_BASE_ADDRESS + 0x08))
#define GPIOB_ODR			*((volatile u32*)(GPIOB_BASE_ADDRESS + 0x0C))
#define GPIOB_BSRR			*((volatile u32*)(GPIOB_BASE_ADDRESS + 0x10))
#define GPIOB_BRR			*((volatile u32*)(GPIOB_BASE_ADDRESS + 0x14))
#define GPIOB_LCKR			*((volatile u32*)(GPIOB_BASE_ADDRESS + 0x18))

/* GPIO C REGISTER DEFINITION */
#define GPIOC_CRL			*((volatile u32*)(GPIOC_BASE_ADDRESS + 0x00))
#define GPIOC_CRH			*((volatile u32*)(GPIOC_BASE_ADDRESS + 0x04))
#define GPIOC_IDR			*((volatile u32*)(GPIOC_BASE_ADDRESS + 0x08))
#define GPIOC_ODR			*((volatile u32*)(GPIOC_BASE_ADDRESS + 0x0C))
#define GPIOC_BSRR			*((volatile u32*)(GPIOC_BASE_ADDRESS + 0x10))
#define GPIOC_BRR			*((volatile u32*)(GPIOC_BASE_ADDRESS + 0x14))
#define GPIOC_LCKR			*((volatile u32*)(GPIOC_BASE_ADDRESS + 0x18))

/* AFIO REGISTER DIFINITION */
#define AFIO_EVCR           *((volatile u32*)(AFIO_BASE_ADDRESS + 0x00))
#define AFIO_MAPR           *((volatile u32*)(AFIO_BASE_ADDRESS + 0x04))
#define AFIO_EXTICR1        *((volatile u32*)(AFIO_BASE_ADDRESS + 0x08))
#define AFIO_EXTICR2        *((volatile u32*)(AFIO_BASE_ADDRESS + 0x0C))
#define AFIO_EXTICR3        *((volatile u32*)(AFIO_BASE_ADDRESS + 0x10))
#define AFIO_EXTICR4        *((volatile u32*)(AFIO_BASE_ADDRESS + 0x14))
#define AFIO_MAPR2          *((volatile u32*)(AFIO_BASE_ADDRESS + 0x1C))


#endif