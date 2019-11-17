#include "readButton.h"

//-----------------READ RB0 BUTTON---------------------
char readButtonD() {
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

//------------------READ RA5 BUTTON----------------------
char readButtonI() {
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

