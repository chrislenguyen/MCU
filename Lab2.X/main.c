/*
 * File:   main.c
 * Author: lnakhuong
 *
 * Created on September 21, 2019, 1:44 PM
 */


#include "config.h"
#include "initialization.h"
#include "calculateTmr.h"
#include "readButton.h"
#include "buttonProcess.h"
#include "interruptTmr.h"
#include "LEDControl.h"

//---------------------------MAIN-----------------------
void main(void) {
    initTmr();
    initLED();
    initButton();
    initOsc();
    calculateTmr();
    while (1) {
        switch(state) {
            case INIT: init();
                break;
            case NORMAL_INCREASE: normalIncrease();
                break;
            case SLOW_INCREASE: slowIncrease();
                break;
            case FAST_INCREASE: fastIncrease();
                break;
            case NORMAL_DECREASE: normalDecrease();
                break;
            case SLOW_DECREASE: slowDecrease();
                break;
            case FAST_DECREASE: fastDecrease();
                break;
        }
    }
}
