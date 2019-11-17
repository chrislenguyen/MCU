/*
 * File:   main.c
 * Author: lnakhuong
 *
 * Created on November 2, 2019, 11:40 AM
 */


#include <xc.h>
#include "mcc.h"


void main(void) {
    System_init();
    while (1) {
        
        dispatch_task();
        
    }
    return;
}
