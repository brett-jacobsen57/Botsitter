/* 
 * File:   lcd.h
 * Author: bj57
 *
 * Implementation file for LCD functions, for testing purposes
 */

#include "mcc_generated_files/system.h"
#include "lcd.h"
#include "delay.h"

void InitPMP(void)
{
    PMCON = 0x8303;
    PMMODE = 0x03FF;
    PMAEN = 0x0001;
}

void InitLCD(void)
{
    PMADDR = 0;
    PMDIN1 = 0b00111000;
    ms_delay(1);
    
    PMDIN1 = 0b00001100;
    ms_delay(1);
    
    PMDIN1 = 0b00000001;
    ms_delay(2);
    
    PMDIN1 = 0b00000110; 
    ms_delay(2);
} // InitLCD

char ReadLCD(int addr)
{
    int dummy;
    while (PMMODEbits.BUSY); 
    PMADDR = addr; 
    dummy = PMDIN1; 
    while (PMMODEbits.BUSY); 
    return (PMDIN1);
} // ReadLCD

#define BusyLCD() ReadLCD(0) & 0x80
#define AddrLCD() ReadLCD(0) & 0x7F
#define getLCD() ReadLCD(1)

void WriteLCD(int addr, char c)
{
    while (BusyLCD());
    while (PMMODEbits.BUSY);
    PMADDR = addr;
    PMDIN1 = c;
}

#define putLCD(d) WriteLCD(1, (d))
#define CmdLCD(c) WriteLCD(0, (c))
#define HomeLCD() WriteLCD(0, 2)
#define ClrLCD() WriteLCD(0, 1)

void putsLCD(char *s)
{
    while (*s) putLCD(*s++);
} //putsLCD

void SetCursorAtLine(int i)
{
    int k;
    
    if (i == 1)
    {
        HomeLCD();
    }
    else if (i == 2)
    {
        CmdLCD(192);
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
