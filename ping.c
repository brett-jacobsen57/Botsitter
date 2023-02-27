#include "mcc_generated_files/system.h"
#include "ping.h"
#include "lcd.h"

#define BusyLCD() readLCD(0) & 0x80
#define putLCD(d) writeLCD(1,(d))
#define cmdLCD(c) writeLCD(0,(c))
#define homeLCD() writeLCD(0,2)
#define clrLCD() writeLCD(0,1)

void init_ping()
{
    TRISB = 0x01;
    TRISA = 0x00;
    AD1PCFG = 0x03;
    T2CON = 0x8000;
}

int pingDistance(long duration)
{
    int distance = 0;
    duration = 0;
    PORTBbits.RB1 = 0;
    int i = 0;
    for (i=0; i<1040; i++)
    {
        PORTBbits.RB1 = 1;      
    }
    TMR2 = 0; while (_RB0 == 0);
    TMR2 = 0; while (_RB0 == 1);
    duration = TMR2;
    distance = ((474)*(long)duration)/5000; 
    distance = distance/100;
    
    return distance;
}

void displayPingDistance(int distance)
{
    int d1 = 0;
    int d2 = 0;
    int d3 = 0;
    
    d3 = distance%10; //isolate digit 3
    distance = distance/10; //divide by 10 for next digit
    d2 = distance%10; //isolate digit 2
    distance = distance/10; //divide by 10 for next digit 
    d1 = distance;
    putLCD(d1+0x30); //print digits and convert to hex so LCD happy
    putLCD(d2+0x30);
    putLCD(d3+0x30);
    putLCD(' ');
    putLCD('c');
    putLCD('m');
    cmdLCD(0x80); //clears LCD
}
