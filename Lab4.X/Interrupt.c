#include "Interrupt.h"
#include "Linked_List.h"
#include "mcc.h"
int count = 0;
void __interrupt() ISR(void) {
    if (INTCONbits.TMR0IE && INTCONbits.TMR0IF) {
        timer_ISR();
        INTCONbits.TMR0IF = 0;
        TMR0 = timer0Counter;
//        test++;
//        if (test == 250) {
//            if (arr_task[0].next == -1) toggle_LED_7();
//            test = 0;
//        }
    }    
    
    if (PIE1bits.TMR1IE && PIR1bits.TMR1IF) {
        PIR1bits.TMR1IF = 0;
        TMR1 = timer1Counter;
        current_time++;
    }
}
