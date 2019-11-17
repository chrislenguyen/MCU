/* 
 * File:   initialization.h
 * Author: lnakhuong
 *
 * Created on September 21, 2019, 1:47 PM
 */

#ifndef INITIALIZATION_H
#define	INITIALIZATION_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "config.h"
#include "calculateTmr.h"

//--------------INITIALIZATION------------------
    
    void initTmr();
    void initLED();
    void initButton();
    void initOsc();

#ifdef	__cplusplus
}
#endif

#endif	/* INITIALIZATION_H */

