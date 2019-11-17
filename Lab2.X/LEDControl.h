/* 
 * File:   LEDControl.h
 * Author: lnakhuong
 *
 * Created on September 23, 2019, 9:06 AM
 */

#ifndef LEDCONTROL_H
#define	LEDCONTROL_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "initialization.h"
    void init();
    void normalIncrease();
    void slowIncrease();
    void fastIncrease();
    void normalDecrease();
    void slowDecrease();
    void fastDecrease();
#ifdef	__cplusplus
}
#endif

#endif	/* LEDCONTROL_H */

