/********************************************/
/* Author	: Michael Adel					*/
/* Version	: V01							*/
/* Date		: 06 Jan. 2021					*/
/********************************************/
#ifndef NVIC_CONFIG_H
#define NVIC_CONFIG_H

/*
*	Options:
*           GROUP_BITS_4_SUB_GROUP_BITS_0
*           GROUP_BITS_3_SUB_GROUP_BITS_1
*           GROUP_BITS_2_SUB_GROUP_BITS_2
*           GROUP_BITS_1_SUB_GROUP_BITS_3
*           GROUP_BITS_0_SUB_GROUP_BITS_4
*/
#define PRIORITY_GROUPING_CONTROL GROUP_BITS_2_SUB_GROUP_BITS_2

#endif