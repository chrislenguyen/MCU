/* 
 * File:   mcc.h
 * Author: lnakhuong
 *
 * Created on October 10, 2019, 12:51 PM
 */

#ifndef MCC_H
#define	MCC_H    
    
#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include "Driver.h"
#include "Interrupt.h"
#include "Linked_List.h"
#include "Task.h"


    // PRAGMA
#ifdef _18F8722
#pragma config  OSC = INTIO7
#pragma config 	FCMEN = OFF
#pragma config 	IESO = OFF
#pragma config 	PWRT = OFF
#pragma config 	BOREN = OFF
#pragma config 	WDT = OFF
#pragma config 	MCLRE = ON
#pragma config 	LVP = OFF
#pragma config 	XINST = OFF
#endif


#define INTERRUPT_TIME_0 1                     //MILISECOND
#define INTERRUPT_TIME_1 1
#define LED0 LATD0
#define LED1 LATD1
#define LED2 LATD2
#define LED3 LATD3
#define LED4 LATD4
#define LED5 LATD5
#define LED6 LATD6
#define LED7 LATD7 
#define _XTAL_FREQ 8000000

    typedef unsigned long int uint32_t;
    typedef unsigned long long int uint64_t;
   
    int test = 0;
    int list_head = 0;
    int size = 0;
    uint32_t timer0Counter = 0;
    int timer1Counter = 0; 
    
    typedef void (*timer_callback_t)();

    typedef struct{
        uint64_t period;
        uint64_t delay;
        int run_flag;
        void (*pTask)();
        int next;
        void* data;
    } Node;
    Node tempNode;
    Node arr_task[MAX_TASK];
    
    void System_init();
    
#endif	/* MCC_H */

