#include "Interrupt.h"
#include "mcc.h"

void __interrupt() ISR(void) {
    if (INTCONbits.TMR0IE && INTCONbits.TMR0IF) {
        INTCONbits.TMR0IF = 0;
        test++;
        routine_time++;
        
        if (routine_time == ROUTINE_TIME) {
            heater_flag = 1;
            routine_time = 0;
        }
        if (state_flag == 1) {  
            time_out_counter++;
        }
        if (time_out_counter == TIMEOUT) {
            timeout_flag = 1;
        }
        if (test == 50) {
            readTempAndHumid();
            mCURSOR_LINE1;
            LCDPutChar('T');
            LCDPutChar(':');
            LCDPutChar(temp/10 +'0');
            LCDPutChar(temp%10 +'0');
            mCURSOR_LINE2;
            LCDPutChar('H');
            LCDPutChar(':');
            LCDPutChar(humid/10 +'0');
            LCDPutChar(humid%10 +'0');
            test = 0;
        }
        TMR0 = timerCounter;
    }
} 
