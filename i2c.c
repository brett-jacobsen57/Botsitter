/* 
 * File:   i2c.c
 * Author: bj57
 *
 * Created on February 9, 2023, 4:12 PM
 * Implementation file for I2C interfacing
 */

#include "mcc_generated_files/system.h"
#include "i2c.h"
#include "delay.h"

void I2Cinit(int BRG)
{
    I2C1BRG = BRG; //See PIC24FJ128GA010 data sheet, Table 16.1 pg. 139
    while (I2C1STATbits.P); // Check buss idle, see 5.1 of I2C document.
    // It works, not sure its needed.
    I2C1CONbits.A10M = 0; // 7-bit address mode (Added 8-14-17)
    I2C1CONbits.I2CEN = 1; // enable module
}

void I2CStart(void)
{
    us_delay(10); // delay to be safe
    I2C1CONbits.SEN = 1; // Initiate Start condition see pg. 21 of I2C man. DS70000195F
    while (I2C1CONbits.SEN); // wait for Start condition complete See sec. 5.1
    us_delay(10); // delay to be safe
}

void I2CStop(void)
{
    us_delay(10); // delay to be safe
    I2C1CONbits.PEN = 1; // see 5.5 pg. 27 of Microchip I2C manual DS70000195F
    while (I2C1CONbits.PEN); // This is at hardware level, & I suspect fast.
    us_delay(10); // delay to be safe
}

void I2Csendbyte(char data)
{
    while (I2C1STATbits.TBF) ; //wait if buffer is full
    I2C1TRN = data; // pass data to transmission register
    us_delay(10); // delay to be safe
}

char I2Cgetbyte( void)
{
    I2C1CONbits.RCEN =1; // Set RCEN, Enables I2C Receive mode
    while (!I2C1STATbits.RBF) ; //wait for byte to shift into I2C1RCV register
    I2C1CONbits.ACKEN = 1; // Master sends Acknowledge
    us_delay(10); // delay to be safe
    return(I2C1RCV);
}
