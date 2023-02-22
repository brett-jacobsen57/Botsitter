/* 
 * File:   delay.c
 * Author: bj57
 *
 * Created on February 9, 2023, 4:38 PM
 * Implementation file for delay functions
 */

#include "mcc_generated_files/system.h"
#include "delay.h"

void us_delay(int n) 
{
    T1CON = 0x8010;         // Timer 1 on, Prescale 8:1
    TMR1 = 0;
    while (TMR1 < n * 2);   // (1/(16MHz/8))*2 = 1us, i is multiplier for ius.
}

void ms_delay(int n) 
{
    T1CON = 0x8030;             // Timer 1 on, Prescale 256:1
    TMR1 = 0;
    while (TMR1 < n * 62.5);    // (1/(16MHz/8))*2 = 1us, i is multiplier for ius.
}

