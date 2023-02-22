/* 
 * File:   i2c.h
 * Author: bj57
 *
 * Created on February 9, 2023, 4:14 PM
 * Include file for I2C interfacing
 */

#ifndef I2C_H
#define	I2C_H

#ifdef	__cplusplus
extern "C" {
#endif
    
void I2Cinit(int BRG);
void I2CStart(void);
void I2CStop(void);
void I2Csendbyte(char data);
char I2Cgetbyte(void);

#ifdef	__cplusplus
}
#endif

#endif	/* I2C_H */
