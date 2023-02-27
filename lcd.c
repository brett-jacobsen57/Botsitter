/* 
 * File:   lcd.h
 * Author: bj57
 *
 * Implementation file for LCD functions, for testing purposes
 */

#include "mcc_generated_files/system.h"

void initLCD(void)
{
    T1CON = 0x8030;
    TMR1 = 0; while(TMR1<2000);
    
    //Initialize the PMP
    PMCON = 0x8303;
    PMMODE = 0x03FF;
    PMAEN = 0x0001;
    
    PMADDR = 0;
    PMDIN1 = 0b00111000;
    TMR1 = 0;while(TMR1<3);
    
    PMDIN1 = 0b00001100;
    TMR1 = 0;while(TMR1<3);
    
    PMDIN1 = 0b00000001;
    TMR1 = 0; while(TMR1<110);
    
    PMDIN1 = 0b00000110;
    TMR1 = 0; while(TMR1<110);
}

char readLCD(int addr)
{
    int dummy;
    while(PMMODEbits.BUSY);
    PMADDR = addr;
    dummy = PMDIN1;
    while(PMMODEbits.BUSY);
    return(PMDIN1);
}

#define BusyLCD() readLCD(0) & 0x80
void writeLCD(int addr, char c)
{
    while(BusyLCD());
    while(PMMODEbits.BUSY);
    PMADDR = addr;
    PMDIN1 = c;
}

#define putLCD(d) writeLCD(1,(d))
#define cmdLCD(c) writeLCD(0,(c))
#define homeLCD() writeLCD(0,2)
#define clrLCD() writeLCD(0,1)

void setCursorAtLine(int i)
{
    int k;
    
    if (i == 1)
    {
        homeLCD();
    }
    else if (i == 2)
    {
        cmdLCD(192);
    }
    else
    {
        TRISA = 0x00;
        for (k = 1; k < 20; k++)
        {
            PORTA = 0xff;
            ms_delay(100);
            PORTA = 0x00;
            ms_delay(100);
        }
    }
}