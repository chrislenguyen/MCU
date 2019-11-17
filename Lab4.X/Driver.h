/* 
 * File:   Driver.h
 * Author: lnakhuong
 *
 * Created on October 20, 2019, 10:11 AM
 */

#ifndef DRIVER_H
#define	DRIVER_H

typedef unsigned int timestamp_t;
timestamp_t current_time = 0;  

void start_timer(unsigned int timer_opt);
timestamp_t get_time(void);
int stop_timer(void);
void timer_ISR(void);
   
#endif	/* DRIVER_H */

