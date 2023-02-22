/* 
 * File:   delay.h
 * Author: bj57
 *
 * Created on February 9, 2023, 4:38 PM
 * Include file for delay functions
 */

#ifndef DELAY_H
#define	DELAY_H

#ifdef	__cplusplus
extern "C" {
#endif

void us_delay(int n);
void ms_delay(int n);

#ifdef	__cplusplus
}
#endif

#endif	/* DELAY_H */

