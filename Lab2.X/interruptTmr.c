#include "interruptTmr.h"
#include "calculateTmr.h"

void __interrupt() ITR(void) {
    if (INTCONbits.TMR0IF) {
        INTCONbits.TMR0IF = 0;
        TMR0 = timerCounter;
        button();
    }
}

