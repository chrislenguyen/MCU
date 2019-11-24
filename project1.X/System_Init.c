#include "mcc.h"
#include "LCD.h"

void init_osc() {
    OSCCON = 0x70;
}

void init_LED() {
    TRISD = 0x00;
    LATD = 0x00;  
}

void init_input (void) {
    TRISA = 0x00;
    ADCON1 = 0b00001111;
}

void init_tmr0() {
    INTCONbits.TMR0IE = 1;
    INTCONbits.TMR0IF = 0;
    T0CON = 0b10001000;
}


void init_interrupt() {
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
}

void calculate_init_tmr() {
    timerCounter = pow(2, 16) - (int64)((INTERRUPT_TIME) * (2 * pow(10, 3))) - 1;
}

void system_init() {
    init_osc();
    init_tmr0();
    init_interrupt();
    calculate_init_tmr();
    LCDInit();
    init_LED();
    init_input();  
}
