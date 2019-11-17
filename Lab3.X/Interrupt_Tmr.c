#include "Interrupt_Tmr.h"
#include "Initialization.h"


void __interrupt() ITR(void) {
    if (INTCONbits.TMR0IE && INTCONbits.TMR0IF) {
        INTCONbits.TMR0IF = 0;
        TMR0 = timerCounter;
        buttonFlag = 1;
        mSecond++;
        if (mSecond > 99) {
            mSecond = 0;
            second++;
            secondFlag = 1;
            reappearFlag = 1;
        }
        if (mSecond > BLINK_TIME) {
            blinkFlag = 1;
        } 
        handleTime();
        if (state == 4 && stopFlag == 0) {
            swMiliSec++;
        }
    }    
}
