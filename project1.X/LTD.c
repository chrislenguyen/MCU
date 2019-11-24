#include "LTD.h"
#include "mcc.h"

void Idle() {
    if (heater_flag == 1) {
        state_flag = 1;
        state = HEATER;
    }
    
    RESET_TIMEOUT;
    HEATER_OFF;
    HEAT_PUMP_OFF;
    FAN_1_OFF;
    FAN_2_OFF;
    FAN_3_OFF;
}

void Heater() {
    if (timeout_flag == 1) {
        timeout_flag = 0;
        state_flag = 0;
        heater_flag = 0;
        state = IDLE;
        return;
    }
    
    else if (temp > MAX_TEMP || humid > MAX_HUMID) {
        RESET_TIMEOUT;
        heater_flag = 0;
        state = HEAT_PUMP;
        return;
    }
    
    HEAT_PUMP_OFF;
    HEATER_ON;
    FAN_2_ON;
    FAN_3_OFF;
}

void Heat_Pump() {
    if (timeout_flag == 1) {
        timeout_flag = 0;
        state_flag = 0;
        state = IDLE;
        return;
    }
    
    FAN_2_OFF;
    FAN_1_ON;
    FAN_3_ON;
    HEATER_OFF;
    HEAT_PUMP_ON;
    
    if (humid < MIN_HUMID) {
        FAN_3_OFF;
        if (temp < MAX_TEMP) {
            RESET_TIMEOUT;
            state = HEATER;
        }
        else {
            timeout_flag = 0;
            state_flag = 0;
            state = IDLE;
        }
        return;
    }
    
    
}