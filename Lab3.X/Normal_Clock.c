#include "Normal_Clock.h"
#include "Initialization.h"

void handleTime() {
    if (second > 59) {
        second = 0;
        minute++;
        minuteFlag = 1;
    }
    if (minute > 59) {
        minute = 0;
        hour++;
        hourFlag = 1;
    }
    if (hour > 23 ) {
        hour = 0;
    }
}

void dispClock() {
    mCURSOR_LINE1;
    LCDPutChar(hour/10+'0');
    LCDPutChar(hour%10+'0');
    LCDPutChar(':');
    LCDPutChar(minute/10+'0');
    LCDPutChar(minute%10+'0');
    LCDPutChar(':');
    LCDPutChar(second/10+'0');
    LCDPutChar(second%10+'0');
    LCDPutStr("       ");
    if (state == 0) {
        LCDCursorControl(1,0);
        LCDPutStr("NORMAL CLOCK");
    } 
    if (state == 1) {
        LCDCursorControl(1,0);
        LCDPutStr("MOD HOUR    ");
    }
    if (state == 2) {
        LCDCursorControl(1,0);
        LCDPutStr("MOD MINUTE  ");
    }
    if (state == 3) {
        LCDCursorControl(1,0);
        LCDPutStr("MOD SECOND  ");
    }
    if (state == 4) {
        dispSw();
        LCDCursorControl(1,0);
        LCDPutStr("STOP WATCH  ");
    }
}

void normalClock() {
    if(secondFlag) {
        secondFlag = 0;
        LCDCursorControl(0, 6);
        LCDPutChar(second/10+'0');
        LCDPutChar(second%10+'0');
    }
    if(minuteFlag) {
        minuteFlag = 0;
        LCDCursorControl(0, 3);
        LCDPutChar(minute/10+'0');
        LCDPutChar(minute%10+'0');
    }
    if(hourFlag) {
        hourFlag = 0;
        LCDCursorControl(0, 0);
        LCDPutChar(hour/10+'0');
        LCDPutChar(hour%10+'0');
    }
}

