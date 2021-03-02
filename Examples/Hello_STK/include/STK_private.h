/********************************************/
/* Author   : Michael Adel                  */
/* Version  : V01                           */
/* Date     : 02 March. 2021                */
/********************************************/
#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

/* Register Definition */
#define STK_CTRL        *((volatile u32 *)0xE000E010)
#define STK_LOAD        *((volatile u32 *)0xE000E014)
#define STK_VAL         *((volatile u32 *)0xE000E018)
#define STK_CALIB       *((volatile u32 *)0xE000E01C)

#define AHB             1
#define AHB_DIV_8       0

#define STK_PERIODIC_INTERVAL       0
#define STK_SINGLE_INTERVAL         1

#endif