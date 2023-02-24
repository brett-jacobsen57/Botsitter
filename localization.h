/* 
 * File:   localization.h
 * Author: bj57
 *
 * Created on February 9, 2023, 4:50 PM
 * Include file for localization functions
 */

#ifndef LOCALIZATION_H
#define	LOCALIZATION_H

#ifdef	__cplusplus
extern "C" {
#endif

double distanceFromRSSI(int RSSI, int n, int A);
void findCoordinates(double *x, double *y, int x1, int y1, int x2, int y2, double d1, double d2);
double findDistance(int x1, int y1, int x2, int y2);
double findAngle(int y2, int y1, double distance);
double findTargetDirection(int x1, int x2, int y1, int y2, double angle);
double findCurrentDirection();

#ifdef	__cplusplus
}
#endif

#endif	/* LOCALIZATION_H */
