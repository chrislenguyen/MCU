/* 
 * File:   Linked_List.h
 * Author: lnakhuong
 *
 * Created on October 20, 2019, 11:38 AM
 */

#ifndef LINKED_LIST_H
#define	LINKED_LIST_H

#define MAX_TASK 20 
#include "mcc.h"




void init_arr_task(void);
uint64_t add_task(uint64_t delay, uint64_t period, void(*callback)(), void *data);
void dispatch_task(void);
void remove_task(uint32_t id);
void Sched_Update(void);
    
#endif	/* LINKED_LIST_H */

