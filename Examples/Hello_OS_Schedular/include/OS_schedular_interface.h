/********************************************/
/* Title    : OS_schedular                  */
/* Author   : Michael Adel                  */
/* Version  : V01                           */
/* Date     : 20 Mar. 2021                  */
/********************************************/

/***************************************************************************************************/
/* Functionality                                                                                   */
/* ==============                                                                                  */
/* 1. Set number of all system tasks in OS_schedular_config.h file.                                */
/* 2. Set OS_TICK_TIME in OS_schedular_config.h file.                                              */
/* 3. Create your system tasks from the provided API's methods.                                    */
/* 4. Start running OS schedular from the provided API's methods.                                  */
/* Example:                                                                                        */
/* STK => If RCC_HSI_8MHZ, AHB/8 are selected, so STK tick time = 1 uSec                           */
/* OS_schedular config => OS_TICK_TIME = 1000                                                      */
/* So, OS_schedular will be triggered each 1000 uSec (1 mSec)                                      */
/* If Task_1 periodicity = 1000, It means 1000 OS_Tick. So the Actual peroidicity time = 1000 mSec */
/* Task_1 firstDelay actual calculation is the same as periodicity.                                */
/***************************************************************************************************/

#ifndef OS_SCHEDULAR_INTERFACE_H
#define OS_SCHEDULAR_INTERFACE_H

/***************************************************************************************************/
/* Description: Used to create tasks.                                                              */
/* Input      : u8 Copy_u8TaskId => Each task must have a unique ID                                */
/*                               => Range: 0 -> NUMBER_OF_TASKS - 1 	                           */
/*                               => NUMBER_OF_TASKS exists in OS_schedular_config.h file           */
/*              u16 Copy_u16Periodicity => Task Periodic time.                                     */
/*                                      => Range: Not specified                                    */
/*              void (*ptr) (void) => pointer to function which will be excuted when the task      */
/*                                    is running.                                                  */
/*                                    => Range: Not specified                                      */
/*              u16 Copy_u16FirstDelay => Specifiy when the task start to be scheduled.            */
/*                                     => Range: Not specified                                     */
/* Output     : Void                                                                               */
/* Scope      : Public                                                                 			   */
/***************************************************************************************************/
void OS_voidCreateTask(u8 Copy_u8TaskId, u16 Copy_u16Periodicity, void (*ptr) (void), u16 Copy_u16FirstDelay);

/***************************************************************************************************/
/* Description: Used to start the OS by intializing and configure Systick Timer,                   */
/*              Setting OS Tick Time is the main task of this functions.                           */
/* Input      : Void                                                                               */
/* Output     : Void                                                                               */
/* Scope      : Public                                                                 			   */
/***************************************************************************************************/
void OS_voidStartOS(void);
/***************************************************************************************************/
/* Description: Used to suspend specific task from running.                                        */
/* Input      : u8 Copy_u8TaskId => Id of the task to be suspended.                                */
/*                               => Range: 0 -> NUMBER_OF_TASKS - 1 	                           */
/*                               => NUMBER_OF_TASKS exists in OS_schedular_config.h file           */
/* Output     : Void                                                                               */
/* Scope      : Public                                                                 			   */
/***************************************************************************************************/
void OS_voidSuspendTask(u8 Copy_u8TaskId);

/***************************************************************************************************/
/* Description: Used to resume specific task from suspending state.                                */
/* Input      : u8 Copy_u8TaskId => Id of the task to be resumed.                                  */
/*                               => Range: 0 -> NUMBER_OF_TASKS - 1 	                           */
/*                               => NUMBER_OF_TASKS exists in OS_schedular_config.h file           */
/* Output     : Void                                                                               */
/* Scope      : Public                                                                 			   */
/***************************************************************************************************/
void OS_voidResumeTask(u8 Copy_u8TaskId);

/***************************************************************************************************/
/* Description: Used to delete specific.                                                           */
/* Input      : u8 Copy_u8TaskId => Id of the task to be deleted.                                  */
/*                               => Range: 0 -> NUMBER_OF_TASKS - 1 	                           */
/*                               => NUMBER_OF_TASKS exists in OS_schedular_config.h file           */
/* Output     : Void                                                                               */
/* Scope      : Public                                                                 			   */
/***************************************************************************************************/
void OS_voidDeleteTask(u8 Copy_u8TaskId);


#endif