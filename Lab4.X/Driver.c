#include "Driver.h"
#include "mcc.h"

void tmr0_init() {
    INTCONbits.TMR0IE = 1;
    INTCONbits.TMR0IF = 0;
    T0CON = 0b10001000;
}

void tmr1_init() {
    PIE1bits.TMR1IE = 1;
    PIR1bits.TMR1IF = 0;
    T1CON = 0b10000001;
}

void start_timer(unsigned int timer_opt) {
    if (timer_opt == 0) {
        tmr0_init();
    }
    else if (timer_opt == 1) {
        tmr1_init();
    }
}

timestamp_t get_time(void) {
    return current_time;
}

void timer_ISR(void) {
    Sched_Update();
}
