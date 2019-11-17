/* 
 * File:   interruptTmr.h
 * Author: lnakhuong
 *
 * Created on September 21, 2019, 1:50 PM
 */

#ifndef INTERRUPTTMR_H
#define	INTERRUPTTMR_H

#include "initialization.h"
#include "buttonProcess.h"

#ifdef	__cplusplus
extern "C" {
#endif

    void __interrupt() ITR(void);


#ifdef	__cplusplus
}
#endif

#endif	/* INTERRUPTTMR_H */

