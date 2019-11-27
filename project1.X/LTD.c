#include "LTD.h"
#include "mcc.h"

void Set_Temp() {
    mCURSOR_LINE1;
    LCDPutStr("MAX_TEMP");
    mCURSOR_LINE2;
    LCDPutChar(max_temp / 10 + '0');
    LCDPutChar(max_temp % 10 + '0');
    if (RA5_flag == 1) {
        max_temp += 5;
        mCURSOR_LINE2;
        LCDPutChar(max_temp / 10 + '0');
        LCDPutChar(max_temp % 10 + '0');
        RA5_flag = 0;
    }
}

void Set_Humid() {
    mCURSOR_LINE1;
    LCDPutStr("MAX_HUMID");
    mCURSOR_LINE2;
    LCDPutChar(max_humid / 10 + '0');
    LCDPutChar(max_humid % 10 + '0');
    if (RA5_flag == 1) {
        max_humid += 5;
        RA5_flag = 0;
        mCURSOR_LINE2;
        LCDPutChar(max_humid / 10 + '0');
        LCDPutChar(max_humid % 10 + '0');
    }
}

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
    
    else if (temp > max_temp || humid > max_humid) {
        RESET_TIMEOUT;
        heater_flag = 0;
        state = HEAT_PUMP;
        return;
    }
    
    HEATER_ON;
    FAN_2_ON;
    FAN_3_OFF;
    HEAT_PUMP_OFF;
}

void Heat_Pump() {
    if (timeout_flag == 1) {
        timeout_flag = 0;
        state_flag = 0;
        state = IDLE;
        return;
    }
    
    HEAT_PUMP_ON;
    FAN_1_ON;
    FAN_3_ON;
    FAN_2_OFF;
    HEATER_OFF; 
    
    if (humid < MIN_HUMID) {
        FAN_3_OFF;
        if (temp < max_temp) {
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