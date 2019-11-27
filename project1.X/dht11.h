/* 
 * File:   dht11.h
 * Author: Tuan
 *
 * Created on November 18, 2019, 10:25 AM
 */

#ifndef DHT11_H
#define	DHT11_H

#include "mcc.h"

#define TIME_OUT 80
    
#define DHT_DIRECTION TRISAbits.TRISA0
#define DHT_IN PORTAbits.RA0
#define DHT_OUT LATAbits.LATA0
#define ERROR -10    
    
int realTemp;
int realHumid;
char dhtData[5];
int error = 0;

void printData();
char getByteData(void);
int readDHT (void);
void readTempAndHumid(void);
#endif	/* DHT11_H */

