#include "Read_Button.h"
#include "Initialization.h"

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

