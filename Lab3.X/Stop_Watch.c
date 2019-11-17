#include "Stop_Watch.h"
#include "Initialization.h"

void dispSw() {
    stopFlag = 1;
    swMiliSec = 0;
    swSec = 0;
    swMin = 0;
    mCURSOR_LINE1;
    LCDPutChar(swMin/10+'0');
    LCDPutChar(swMin%10+'0');
    LCDPutChar(':');
    LCDPutChar(swSec/10+'0');
    LCDPutChar(swSec%10+'0');
    LCDPutChar(':');
    LCDPutChar(swMiliSec/10+'0');
    LCDPutChar(swMiliSec%10+'0');
    LCDPutStr("       ");
}

void handleTimeSw() {
    LCDCursorControl(0, 6);
    LCDPutChar(swMiliSec/10+'0');
    LCDPutChar(swMiliSec%10+'0');
    if (swMiliSec > 99) {
        swMiliSec = 0;
        swSec++;
        LCDCursorControl(0, 4);
        LCDPutChar(swSec % 10 + '0');
        if (swSec > 59) {
            LCDCursorControl(0, 3);
            LCDPutChar('0');
        }
        if (swSec > 9 && swSec < 60) {   
            LCDCursorControl(0, 3);
            LCDPutChar(swSec / 10 + '0');
        }
    }
    if (swSec > 59) {
        swSec = 0;
        swMin++;
        LCDCursorControl(0, 1);
        LCDPutChar(swMin % 10 + '0');
        if (swMin > 59) {
            LCDCursorControl(0, 0);
            LCDPutChar('0');
        }
        if (swMin > 9 && swMin < 60) {   
            LCDCursorControl(0, 0);
            LCDPutChar(swMin / 10 + '0');
        }
    }
}

void stopWatch() {
    switch (stopWatchState) {
        case 0:
            if (isPressedRB0 == 1) {
                stopFlag = 0;
                isPressedRB0 = 0;
                stopWatchState = 1;
            }
            break;  
        case 1:
            if (isPressedRB0 == 1) {
                stopFlag = 1;
                isPressedRB0 = 0;
                stopWatchState = 0;
            }
            handleTimeSw();
    }
}
