#include "Initialization.h"
void osc_init() {
    OSCCON = 0x70;
}

void pin_init() {
    TRISD = 0x00;
    LATD = 0x00;
   
    LATA = 0x00;
    TRISA = 0xF3;

    LATB = 0x00;
    TRISB = 0xFF;
    
    LATC = 0x00;
    TRISC = 0xD7;
    ADCON1 = 0b00001111;
}

void interrupt_init() {
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
}

void tmr0_init() {
    INTCONbits.TMR0IE = 1;
    INTCONbits.TMR0IF = 0;
    T0CON = 0b10001000;
}

void calculate_init_tmr() {
     timerCounter = pow(2, 16) - (int)((INTERRUPT_TIME) * (2 * pow(10, 3)));
}

void system_init() {
    osc_init();
    pin_init();
    interrupt_init();
    tmr0_init();
    calculate_init_tmr();
    mOPEN_LCD;
    dispClock();
}


