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

void OS_voidCreateTask(u8 Copy_u8TaskId, u16 Copy_u16Periodicity, void (*ptr) (void), u16 Copy_u16FirstDelay)
{
    OS_Tasks[Copy_u8TaskId].periodicity = Copy_u16Periodicity;
    OS_Tasks[Copy_u8TaskId].firstDelay = Copy_u16FirstDelay;
    OS_Tasks[Copy_u8TaskId].TaskHandler = ptr;
    OS_Tasks[Copy_u8TaskId].state = TASK_READY;
}


void OS_voidStartOS(void)
{
    /* Intialization */
    STK_voidInit();
    STK_voidSetIntervalPeriodic(1000, OS_voidSchedular);
}

