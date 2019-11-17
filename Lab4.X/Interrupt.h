/* 
 * File:   Interrupt.h
 * Author: lnakhuong
 *
 * Created on October 20, 2019, 1:22 PM
 */

#ifndef INTERRUPT_H
#define	INTERRUPT_H

#ifdef	__cplusplus
extern "C" {
#endif

    void __interrupt() ISR(void);

#ifdef	__cplusplus
}
#endif

#endif	/* INTERRUPT_H */

