#include "mcc.h"
#include "Linked_List.h"
#include "Driver.h"
#include "Task.h"
#include "Interrupt.h"

void osc_init() {
    OSCCON = 0x70;
}

void init_LED() {
    TRISD = 0x00;
    LATD = 0x00;
}

void interrupt_init() {
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
}

void init_task() {
    //add_task(0, 700, toggle_LED_2, 0);
    add_task(0, 500, toggle_LED_0, 0);
    //add_task(1000, 0, toggle_LED_0, 0);
    add_task(110, 700, toggle_LED_2, 0);
    add_task(250, 600, toggle_LED_4, 0);
}

void calculate_init_tmr0() {
    timer0Counter = pow(2, 16) - (uint32_t)((INTERRUPT_TIME_0) * (2 * pow(10, 3))) - 1;
//    TMR0H = (timer1Counter >> 8);
//    TMR0L = (int) timer0Counter;
}

void calculate_init_tmr1() {
    timer1Counter = pow(2, 16) - (int)((INTERRUPT_TIME_1) * (2 * pow(10, 3)));
    TMR1H = (timer1Counter >> 8);
    TMR1L = (int) timer1Counter;
}

void System_init() {
    init_LED();
//    LATD = 0x55;
//    __delay_ms(100);
    osc_init();
    interrupt_init();
    calculate_init_tmr0();
    calculate_init_tmr1();
    init_arr_task();
    init_task();
    start_timer(0);
    start_timer(1);   
}
