/* 
 * File:   mcc.h
 * Author: lnakhuong
 *
 * Created on November 23, 2019, 11:00 AM
 */

#ifndef MCC_H
#define	MCC_H

#include <xc.h>
#include <stdint.h>
#include <math.h>
#include "LCD.h"
#include "LTD.h"
#include "Interrupt.h"
#include "dht11.h"
#include "Read_Button.h"

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

#define INTERRUPT_TIME 10
#define ROUTINE_TIME 3000/INTERRUPT_TIME
#define TIMEOUT 10000/INTERRUPT_TIME
#define MIN_HUMID 100 - max_humid
#define SET_TEMP 0
#define SET_HUMID 1
#define IDLE 2
#define HEATER 3
#define HEAT_PUMP 4
#define RESET_TIMEOUT time_out_counter = 0
#define HEATER_ON LATD7 = 1
#define HEATER_OFF LATD7 = 0
#define HEAT_PUMP_ON LATD5 = 1
#define HEAT_PUMP_OFF LATD5 = 0
#define FAN_1_ON LATD1 = 1
#define FAN_2_ON LATD2 = 1
#define FAN_3_ON LATD3 = 1
#define FAN_1_OFF LATD1 = 0
#define FAN_2_OFF LATD2 = 0
#define FAN_3_OFF LATD3 = 0

typedef long long int int64;

char state = 0;
char firstReadRA5 = 1;
char secondReadRA5 = 1;
char firstReadRB0 = 1;
char secondReadRB0 = 1;
int max_temp = 0;
int max_humid = 0;
int state_flag = 0;
int heater_flag = 0;
int timeout_flag = 0;
int LCD_flag = 0;
int temp = 0;
int humid = 0;
int count_LCD = 0;
int count_RB0 = 0;
int RB0_flag = 0;
int count_RA5 = 0;
int RA5_flag = 0;

int64 timerCounter = 0;
int64 routine_counter = 0;
int64 time_out_counter = 0;

void system_init();


#endif	/* MCC_H */

