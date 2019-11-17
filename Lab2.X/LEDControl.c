#include "LEDControl.h"
#include "initialization.h"
#include "buttonProcess.h"

void init() {
    countI = 0;
    countD = 0;
    slowCount = 0;
    fastCount = 0;
    if (countI > 0) {
        LED++;
        state = NORMAL_INCREASE;
    }
    else if (countD > 0 && countI == 0) {
        LED--;
        state = NORMAL_DECREASE;
    }
}

void normalIncrease() {
    if (countI == 0) {
        state = INIT;
    }
    if (countI > TIME_PRESSED_1S) {
        state = SLOW_INCREASE;
    }
}

void slowIncrease() {
    if (countI == 0) {
        state = INIT;
    }
    if (countI > TIME_PRESSED_3S) {
        state = FAST_INCREASE;
    }
    if (slowCount > SLOW_COUNTER_LIMIT) {
        LED++;
        slowCount = 0;
    }
}

void fastIncrease() {
    if (countI == 0) {
        state = INIT;
    }
    if (fastCount > FAST_COUNTER_LIMIT) {
        LED++;
        fastCount = 0;
    }
}

void normalDecrease() {
    if (countD == 0 || countI > 0) {  
        state = INIT;
    }
    if (countD > TIME_PRESSED_1S && countI == 0) { 
        state = SLOW_DECREASE;
    }
}

void slowDecrease() {
    if (countD == 0 || countI > 0) {
        state = INIT;
    }
    if (countD > TIME_PRESSED_3S && countI == 0) {
        state = FAST_DECREASE;
    }
    if (slowCount > SLOW_COUNTER_LIMIT && countI == 0) {
        LED--;
        slowCount = 0;
    }
}

void fastDecrease() {
    if (countD == 0 || countI > 0) 
        state = INIT;
    if (fastCount > FAST_COUNTER_LIMIT && countI == 0) {
        LED--;
        fastCount = 0;
    }
}

    

