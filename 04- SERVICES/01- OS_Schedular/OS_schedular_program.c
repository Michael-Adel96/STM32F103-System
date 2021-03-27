/********************************************/
/* Title    : OS_schedular                  */
/* Author   : Michael Adel                  */
/* Version  : V01                           */
/* Date     : 20 Mar. 2021                  */
/********************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"

#include "OS_schedular_interface.h"
#include "OS_schedular_private.h"
#include "OS_schedular_config.h"


/* Array of Tasks */
static Task OS_Tasks[NUMBER_OF_TASKS] = {NULL};

/***************************************************************************************************/
/* Description: Core algorithm of OS which decides which task to run at every OS tick.             */
/* Input      : Void                                                                               */
/* Output     : Void                                                                               */
/* Scope      : Private                                                                            */
/***************************************************************************************************/
static void OS_voidSchedular(void)
{
    u8 countTask;

    for(countTask = 0; countTask < NUMBER_OF_TASKS; countTask++)
    {
        if ((OS_Tasks[countTask].TaskHandler != NULL) && (OS_Tasks[countTask].state == TASK_READY))
        {
            if(OS_Tasks[countTask].firstDelay == 0)
            {
                OS_Tasks[countTask].TaskHandler();
                OS_Tasks[countTask].firstDelay = OS_Tasks[countTask].periodicity - 1;
            }
            else
            {
                OS_Tasks[countTask].firstDelay--;
            }
        }
        else
        {
            // Return Error message
        }
        
    }
}

/***************************************************************************************************/
/* Description: Used to create tasks.                                                              */
/* Input      : u8 Copy_u8TaskId => Each task must have a unique ID                                */
/*                               => Range: 0 -> NUMBER_OF_TASKS - 1 	                           */
/*                               => NUMBER_OF_TASKS exists in OS_schedular_config.h file           */
/*              u16 Copy_u16Periodicity => Task Periodic time.                                     */
/*                                      => Periodicity is in terms of OS_Tick_number               */
/*                                      => Range: Not specified                                    */
/*                                      => Actual periodicity = PERIODICITY x OS_TICK_ACTUAL_DELAY */
/*              void (*ptr) (void) => pointer to function which will be excuted when the task      */
/*                                    is running.                                                  */
/*                                    => Range: Not specified                                      */
/*              u16 Copy_u16FirstDelay => Specifiy when the task starts to be scheduled.           */
/*                                     => First Delay ticks number is the number of OS ticks to    */
/*                                        start running the task.                                  */
/*                                     => Range: Not specified                                     */
/*                              => Actual First delay = FIRST_DELAY_TICKS x OS_TICK_ACTUAL_DELAY   */
/* Output     : Void                                                                               */
/* Scope      : Public                                                                             */
/***************************************************************************************************/
void OS_voidCreateTask(u8 Copy_u8TaskId, u16 Copy_u16Periodicity, void (*ptr) (void), u16 Copy_u16FirstDelay)
{
    OS_Tasks[Copy_u8TaskId].periodicity = Copy_u16Periodicity;
    OS_Tasks[Copy_u8TaskId].firstDelay = Copy_u16FirstDelay;
    OS_Tasks[Copy_u8TaskId].TaskHandler = ptr;
    OS_Tasks[Copy_u8TaskId].state = TASK_READY;
}

/***************************************************************************************************/
/* Description: Used to start the OS by intializing and configure Systick Timer,                   */
/*              Setting OS Tick Time is the main task of this functions.                           */
/* Input      : Void                                                                               */
/* Output     : Void                                                                               */
/* Scope      : Public                                                                             */
/***************************************************************************************************/
void OS_voidStartOS(void)
{
    /* Intialization */
    STK_voidInit();
    STK_voidSetIntervalPeriodic(OS_TICK_TIME, OS_voidSchedular);
}

/***************************************************************************************************/
/* Description: Used to suspend specific task from running.                                        */
/* Input      : u8 Copy_u8TaskId => Id of the task to be suspended.                                */
/*                               => Range: 0 -> NUMBER_OF_TASKS - 1 	                           */
/*                               => NUMBER_OF_TASKS exists in OS_schedular_config.h file           */
/* Output     : Void                                                                               */
/* Scope      : Public                                                                             */
/***************************************************************************************************/
void OS_voidSuspendTask(u8 Copy_u8TaskId)
{
    OS_Tasks[Copy_u8TaskId].state = TASK_SUSPENDED;   
}

/***************************************************************************************************/
/* Description: Used to resume specific task from suspending state.                                */
/* Input      : u8 Copy_u8TaskId => Id of the task to be resumed.                                  */
/*                               => Range: 0 -> NUMBER_OF_TASKS - 1 	                           */
/*                               => NUMBER_OF_TASKS exists in OS_schedular_config.h file           */
/* Output     : Void                                                                               */
/* Scope      : Public                                                                             */
/***************************************************************************************************/
void OS_voidResumeTask(u8 Copy_u8TaskId)
{
    OS_Tasks[Copy_u8TaskId].state = TASK_READY;   
}

/***************************************************************************************************/
/* Description: Used to delete specific.                                                           */
/* Input      : u8 Copy_u8TaskId => Id of the task to be deleted.                                  */
/*                               => Range: 0 -> NUMBER_OF_TASKS - 1 	                           */
/*                               => NUMBER_OF_TASKS exists in OS_schedular_config.h file           */
/* Output     : Void                                                                               */
/* Scope      : Public                                                                             */
/***************************************************************************************************/
void OS_voidDeleteTask(u8 Copy_u8TaskId)
{
    OS_Tasks[Copy_u8TaskId].TaskHandler = NULL;
}