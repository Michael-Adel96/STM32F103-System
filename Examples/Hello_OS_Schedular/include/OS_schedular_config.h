/********************************************/
/* Title    : OS_schedular                  */
/* Author   : Michael Adel                  */
/* Version  : V01                           */
/* Date     : 20 Mar. 2021                  */
/********************************************/

#ifndef OS_SCHEDULAR_CONFIG_H
#define OS_SCHEDULAR_CONFIG_H

/****************************************************************************/
/* Choose the total number of tasks that is expected to be handled by OS.   */
/* Choosing very large number of tasks may cause stack overflow problem.    */
/****************************************************************************/
#define     NUMBER_OF_TASKS     3

/****************************************************************************/
/* Choose OS periodic time to call schedular to decide which task will run  */
/* Actual OS Tick time = OS_TICK_TIME x systick one Tick actual delay       */
/* Example: STK Tick time = 1 uSec                                          */
/*          OS_TICK_TIME = 1000                                             */
/*          Actual OS Tick Time = 1000 x 1 uSec                             */
/*          Schedular function will be called every 1 mSec                  */
/****************************************************************************/
#define     OS_TICK_TIME    1000

#endif