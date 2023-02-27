/* 
 * File:   lcd.h
 * Author: bj57
 *
 * Created on February 9, 2023, 4:31 PM
 * Include file for LCD functions
 */

#ifndef LCD_H
#define	LCD_H

#ifdef	__cplusplus
extern "C" {
#endif

void initLCD(void);
char readLCD(int addr);
void writeLCD(int addr, char c);
void setCursorAtLine(int i);

#ifdef	__cplusplus
}
#endif

#endif	/* LCD_H */
