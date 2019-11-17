/* 
 * File:   config.h
 * Author: lnakhuong
 *
 * Created on September 21, 2019, 1:45 PM
 */

#ifndef CONFIG_H
#define	CONFIG_H

#include <stdio.h>
#include <math.h>
#include <xc.h>

//-----------------HARDWARE--------------------
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

//-----------------DEFINITION------------------

#define INTERRUPT_TIME 20  //  in milisecond
#define TIME_PRESSED_1S 1000/INTERRUPT_TIME
#define TIME_PRESSED_3S 3000/INTERRUPT_TIME
#define SLOW_COUNTER_LIMIT 500/INTERRUPT_TIME
#define FAST_COUNTER_LIMIT 100/INTERRUPT_TIME
#define LED LATD
enum State{INIT, NORMAL_INCREASE, SLOW_INCREASE, FAST_INCREASE, 
        NORMAL_DECREASE, SLOW_DECREASE, FAST_DECREASE};
enum State state;

//----------------VARIABLE DECLARATAION-------------
char firstReadRA5 = 1;
char secondReadRA5 = 1;
char firstReadRB0 = 1;
char secondReadRB0 = 1;
int countI = 0;
int countD = 0;
int slowCount = 0;
int fastCount = 0;
int timerCounter = 0;


#endif	/* CONFIG_H */

