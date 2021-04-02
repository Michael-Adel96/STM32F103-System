/********************************************/
/* Title    : DMA_1 Driver                  */
/* Author   : Michael Adel                  */
/* Version  : V01                           */
/* Date     : 29 Mar. 2021                  */
/********************************************/

#ifndef DMA_PRIVATE_H
#define DMA_PRIVATE_H

typedef struct
{
    volatile u32 CCR;
    volatile u32 CNDTR;
    volatile u32 CPAR;
    volatile u32 CMAR;
    volatile u32 reserved;
} DMA_channel;



typedef struct
{
    volatile u32 ISR;
    volatile u32 IFCR;
    DMA_channel Channel[7];
} DMA_t;

#define     DMA     ((volatile DMA_t *) 0x40020000)
#endif