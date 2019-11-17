#include "Mod_Time.h"
#include "Initialization.h"

void blink() {
    switch(state) {
        case 1:
            LCDCursorControl(0, 0);
            LCDPutStr("  ");
            break;
        case 2:
            LCDCursorControl(0, 3);
            LCDPutStr("  ");
            break;
        case 3:
            LCDCursorControl(0, 6);
            LCDPutStr("  ");
            break;
        default:
            return;
    }
}

void modSecond() {
    normalClock();
    if (blinkFlag == 1 && checkRB0 == 1) {
        blinkFlag = 0;
        blink();
    }
    if (reappearFlag == 1) {
        reappearFlag = 0;
        LCDCursorControl(0, 6);
        LCDPutChar(second/10+'0');
        LCDPutChar(second%10+'0');
    }
}

void modMinute() {
    normalClock();
    if (blinkFlag == 1 && checkRB0 == 1) {
        blinkFlag = 0;
        blink();
    }
    if (reappearFlag == 1) {
        reappearFlag = 0;
        LCDCursorControl(0, 3);
        LCDPutChar(minute/10+'0');
        LCDPutChar(minute%10+'0');
    }
}

void modHour() {
    normalClock();
    if (blinkFlag == 1 && checkRB0 == 1) {
        blinkFlag = 0;
        blink();
    }
    if (reappearFlag == 1) {
        reappearFlag = 0;
        LCDCursorControl(0, 0);
        LCDPutChar(hour/10+'0');
        LCDPutChar(hour%10+'0');
    }
}
