#include "calculateTmr.h"

void calculateTmr() {
    timerCounter = pow(2, 16) - (int)((INTERRUPT_TIME ) * (2 * pow(10, 3)));
}