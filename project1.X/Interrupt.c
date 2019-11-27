#include "Interrupt.h"
#include "mcc.h"

void __interrupt() ISR(void) {
    if (INTCONbits.TMR0IE && INTCONbits.TMR0IF) {
        INTCONbits.TMR0IF = 0;  
        routine_counter++;
        button();
        if (routine_counter == ROUTINE_TIME) {
            heater_flag = 1;
            routine_counter = 0;
        }
        if (state_flag == 1) {  
            time_out_counter++;
        }
        if (state > 1) {
            count_LCD++;
        }
        if (time_out_counter == TIMEOUT) {
            timeout_flag = 1;
        }
        if (count_LCD == 50 && state > 1) {
            readTempAndHumid();
            printData();
            count_LCD = 0;
        }
        TMR0 = timerCounter;
    }
} 
