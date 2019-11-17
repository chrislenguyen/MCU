#include "buttonProcess.h"

void button() {
    char checkI = readButtonI();
    char checkD = readButtonD();
    if (checkI == 2) {
        countD = 0;
        countI++;
        if (countI > TIME_PRESSED_1S)
            slowCount++;
        if (countI > TIME_PRESSED_3S)
            fastCount++;
    }
    else if (checkD == 2) {
        countI = 0;
        countD++;
        if (countD > TIME_PRESSED_1S)
            slowCount++;
        if (countD > TIME_PRESSED_3S)
            fastCount++;
    }
    else if (checkI == 1 || checkD == 1) {
        countI = 0;
        countD = 0;
        slowCount = 0;
        fastCount = 0;
    }
}
