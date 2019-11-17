/*
 * File:   m.c
 * Author: lnakhuong
 *
 * Created on September 24, 2019, 8:47 PM
 */

#include <xc.h>
#include "Initialization.h"

void main(void) {
    system_init();
    //dispClock();
    while (1) {
        if (buttonFlag == 1) {
            button();
            buttonFlag = 0;
        }
        handleTime();
        switch (state) {
            case 0: normalClock();
            break;
            case 1: modHour();
            break;
            case 2: modMinute();
            break;
            case 3: modSecond();
            break;
            case 4: stopWatch();
            break;
        }
    }
    return;
}
