#include "Linked_List.h"
#include "mcc.h"
#include "Task.h"

void init_arr_task(void) {
    int index = 0;
    while (index < MAX_TASK) {
        arr_task[index].delay = 0;
        arr_task[index].period = 0;
        arr_task[index].next = -1;
        arr_task[index].run_flag = -1;
        arr_task[index].pTask = NULL;
        arr_task[index].data = NULL;
        index++;
    }
}

uint64_t add_task(uint64_t delay, uint64_t period, void(*callback)(), void *data) {  
    int index = 0;
    
    if (size == MAX_TASK) {
        return -1;
    }
    
    if (size == 0) {
        list_head = 0;
        arr_task[list_head].delay = delay;
        arr_task[list_head].period = period;
        arr_task[list_head].run_flag = 0;
        arr_task[list_head].pTask = callback;
        arr_task[list_head].next = -1;
        arr_task[list_head].data = data;
        size++;
        return 0;
    }
    
    else {
        int cur, pre;
//        LATD = arr_task[index].period;
//        __delay_ms(100);
        while (arr_task[index].pTask != NULL && index < MAX_TASK) {
            index++;
//            LATD = 0x55;
//            __delay_ms(100);
        }
        
        cur = list_head;
        pre = -1;
        
        if (delay < arr_task[cur].delay) {
            arr_task[index].next = list_head;
            list_head = index;
            int temp = arr_task[index].next;
            arr_task[temp].delay -= delay;
        }
        
        else {
            pre = cur;
            cur = arr_task[cur].next;
            delay -= arr_task[pre].delay;
            
//            LATD = cur;
//                __delay_ms(100);
            while (delay >= arr_task[cur].delay && cur != -1) {
                delay -= arr_task[cur].delay;
                pre = cur; 
                cur = arr_task[cur].next;          
            }

//                LATD = cur;
//                __delay_ms(100);
//                LATD = pre;
//                __delay_ms(100);
            arr_task[pre].next = index;
            arr_task[index].next = cur;
            if (arr_task[index].next != -1) {
                int temp = arr_task[index].next;
                arr_task[temp].delay -= delay;
            }
        }
        
        arr_task[index].delay = delay;
        arr_task[index].period = period;
        arr_task[index].run_flag = 0;
        arr_task[index].data = data; 
        arr_task[index].pTask = callback; 
        
        size++;
    }
    return index;
}

void Sched_Update(void) {
    if (size == 0) {
        return;
    }
    
    int temp = list_head;
    while (arr_task[temp].delay <= 0) {
        arr_task[temp].run_flag = 1;
        temp = arr_task[temp].next; 
    }
    
    arr_task[list_head].delay--;
}

void remove_task(uint32_t id) {
    int cur = list_head;
    int pre = -1; 
    while (cur != id) {
        pre = cur;
        cur = arr_task[cur].next;
    }
    
    if (size > 1) {
        if (id == list_head) {
            list_head = arr_task[list_head].next;
        }   
        else {
            arr_task[pre].next = arr_task[cur].next;
            int pos = arr_task[id].next;
            int delay = arr_task[id].delay;
            while (pos != - 1) {
                arr_task[pos].delay -= delay;
                pos = arr_task[id].next;
            }
        }   
    }
    
    arr_task[id].delay = 0;
    arr_task[id].period = 0;
    arr_task[id].next = -1;
    arr_task[id].run_flag = -1;
    arr_task[id].pTask = NULL;
    arr_task[id].data = NULL;
    size--;
}

void dispatch_task(void) {
    if (arr_task[list_head].run_flag > 0) {
        (*arr_task[list_head].pTask)();
        tempNode = arr_task[list_head];    
        remove_task(list_head);
        if (tempNode.period != 0) { 
           add_task(tempNode.period, tempNode.period, tempNode.pTask, tempNode.data);
        }
    }
}
