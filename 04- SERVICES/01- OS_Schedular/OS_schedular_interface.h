/********************************************/
/* Title    : OS_schedular                  */
/* Author   : Michael Adel                  */
/* Version  : V01                           */
/* Date     : 20 Mar. 2021                  */
/********************************************/

#ifndef OS_SCHEDULAR_INTERFACE_H
#define OS_SCHEDULAR_INTERFACE_H


void OS_voidCreateTask(u8 Copy_u8TaskId, u16 Copy_u16Periodicity, void (*ptr) (void), u16 Copy_u16FirstDelay);
void OS_voidStartOS(void);

void OS_voidSuspendTask(u8 Copy_u8TaskId);
void OS_voidResumeTask(u8 Copy_u8TaskId);
void OS_voidDeleteTask(u8 Copy_u8TaskId);


#endif