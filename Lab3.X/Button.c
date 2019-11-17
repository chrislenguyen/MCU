#include "Button.h"
#include "Initialization.h"

void button() {
   checkRA5 = readButtonRA5();
    checkRB0 = readButtonRB0();
    if (checkRA5 == 1) {
        countRA5 = 0;
    }
    if (checkRB0 == 1) {
        countRB0 = 0;
    }
    if (checkRA5 == 2) {
        if (countRA5 == 0) {
            state = (state + 1) % 5;
            dispClock();
        }
        countRA5++;
        if (countRA5 > TIME_PRESSED_1S) {
            state = (state + 1) % 5;
            if (state == 4) {
                dispSw();
            }
            else {
                dispClock();
            }
            countRA5 = 1;
        }
    }
    if (checkRB0 == 2) {
        if (countRB0 == 0) {
            if (state == 1) {
                hour++;
                handleTime();
                LCDCursorControl(0, 0);
                LCDPutChar(hour/10+'0');
                LCDPutChar(hour%10+'0');
            }
            if (state == 2) {
                minute++;
                handleTime();
                LCDCursorControl(0, 3);
                LCDPutChar(minute/10+'0');
                LCDPutChar(minute%10+'0');
            }
            if (state == 3) {
                second++;
                handleTime();
                LCDCursorControl(0, 6);
                LCDPutChar(second/10+'0');
                LCDPutChar(second%10+'0');
            }
            if (state == 4) {
                isPressedRB0 = 1;
            }
        }
        countRB0++;
        if (countRB0 > TIME_PRESSED_1S) {
            if (state == 1) {
                hour++;
                handleTime();
                LCDCursorControl(0, 0);
                LCDPutChar(hour/10+'0');
                LCDPutChar(hour%10+'0');
            }
            if (state == 2) {
                minute++;
                handleTime();
                LCDCursorControl(0, 3);
                LCDPutChar(minute/10+'0');
                LCDPutChar(minute%10+'0');
            }
            if (state == 3) {
                second++;
                handleTime();
                LCDCursorControl(0, 6);
                LCDPutChar(second/10+'0');
                LCDPutChar(second%10+'0');
            }
            countRB0 = countRB0 - TIME_AUTO_CHANGE;
        }
    }  
}
