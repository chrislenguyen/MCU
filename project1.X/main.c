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
            case SET_TEMP: Set_Temp();
            break;
            case SET_HUMID: Set_Humid();
            break;
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
