#include "Read_Button.h"
#include "mcc.h"

char readButtonRA5() {
    firstReadRA5 = secondReadRA5;
    secondReadRA5 = PORTAbits.RA5;
    if(secondReadRA5 == firstReadRA5) {
        if (secondReadRA5 == 0) 
            return 2;
        else 
            return 1;   
    }
    return 0;
}

char readButtonRB0() {
    firstReadRB0 = secondReadRB0;
    secondReadRB0 = PORTBbits.RB0;
    if(secondReadRB0 == firstReadRB0) {
        if (secondReadRB0 == 0) 
            return 2;
        else 
            return 1;
    }
    return 0;
}

void button() {
    char set_button = readButtonRA5();
    char state_button = readButtonRB0();
    if (set_button == 2) {
        if (count_RA5 == 0) {
            RA5_flag = 1;
            count_RA5++;
        }
    }
    
    if (state_button == 2) {
        if (count_RB0 == 0) {
            RB0_flag = 1;
            if (state < 2) {
                state++;
            }
            count_RB0++;
        }
    }
    
    if (set_button == 1) {
        count_RA5 = 0;
    }
    if (state_button == 1) {
        count_RB0 = 0;
    }
}