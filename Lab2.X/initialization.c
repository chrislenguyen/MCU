#include "initialization.h"

void initTmr() {
    calculateTmr();
    INTCONbits.TMR0IE = 1;
    INTCONbits.GIE = 1;
    T0CON = 0b10001000; // TIMER 16 BITS, NO SCALE
    TMR0 = timerCounter;
}

void initLED() {
    LATD = 0x00;
    TRISD = 0x00;
}

void initButton() {
    TRISAbits.TRISA5 = 1;
    TRISBbits.TRISB0 = 1;
    ADCON1 = 0b00001111;
}

void initOsc() {
    OSCCON = 0b01110000; // OSCILLATOR FREQ 8MHz
    //OSCTUNE = 0b00001111;
}
