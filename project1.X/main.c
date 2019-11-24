/*
 * File:   main.c
 * Author: lnakhuong
 *
 * Created on November 23, 2019, 12:57 PM
 */


#include "mcc.h"

void main(void) {
    system_init();
    while (1) {
        switch (state) {
            case IDLE: Idle();
                break;
            case HEATER: Heater();
                break;
            case HEAT_PUMP: Heat_Pump();
                break;
        }
    }
    return;
}
