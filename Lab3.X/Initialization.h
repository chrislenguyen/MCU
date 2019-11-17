/* 
 * File:   Initialization.h
 * Author: lnakhuong
 *
 * Created on September 24, 2019, 8:35 PM
 */

#ifndef INITIALIZATION_H
#define	INITIALIZATION_H

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include "LCD.h"
#include "Read_Button.h"
#include "Interrupt_Tmr.h"
#include "Button.h"
#include "Mod_Time.h"
#include "Normal_Clock.h"
#include "Stop_Watch.h"

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

#define _XTAL_FREQ  8000000
#define INTERRUPT_TIME 10
#define TIME_AUTO_CHANGE 100 / INTERRUPT_TIME
#define TIME_PRESSED_1S 1000 / INTERRUPT_TIME
#define BLINK_TIME 700 / INTERRUPT_TIME

//---------STATE---------------
int state = 0;

//---------TIMER---------------
int timerCounter = 0;

//---------BUTTON--------------
char firstReadRA5 = 1;
char secondReadRA5 = 1;
char firstReadRB0 = 1;
char secondReadRB0 = 1;
char stateRA5 = 0;
char stateRB0 = 0;
char isPressedRB0 = 0;
int countRA5 = 0;
int countRB0 = 0;
int checkRA5 = 0;
int checkRB0 = 0;
unsigned char RA5flag = 0;
unsigned char RB0flag = 0;
unsigned char buttonFlag = 0;

//---------------CLOCK-------------
unsigned int hour = 0, minute = 0, second = 0, mSecond = 0;
unsigned int swMiliSec = 0, swSec = 0, swMin = 0;
unsigned char blinkFlag = 0;
unsigned char stopWatchState = 0;
unsigned char stopFlag = 1;
unsigned char secondFlag = 0;
unsigned char minuteFlag = 0;
unsigned char hourFlag = 0;
unsigned char reappearFlag = 0;


void system_init(void);

#endif	/* INITIALIZATION_H */

