/********************************************/
/* Title    : OS_schedular                  */
/* Author   : Michael Adel                  */
/* Version  : V01                           */
/* Date     : 20 Mar. 2021                  */
/********************************************/
 
#ifndef OS_SCHEDULAR_PRIVATE_H
#define OS_SCHEDULAR_PRIVATE_H

typedef struct
{
    u16 periodicity;
    u16 firstDelay;
    u8 state;
    void (*TaskHandler) (void);
}Task;

#define     TASK_READY      1
#define     TASK_SUSPENDED  2

#define     NULL    (void *)0


#endif