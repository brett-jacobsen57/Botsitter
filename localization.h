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

    float distanceFromRSSI(int RSSI, int n, int A);
    void findCoordinates(float *x, float *y, int x1, int y1, int x2, int y2, float d1, float d2);
    double findDistance(int x1, int y1, int x2, int y2);
    double findAngle(int y2, int y1, double distance);
    double findTargetDirection(int x1, int x2, int y1, int y2, double angle);
    double findCurrentDirection();
    void displayCoordinates(float x, float y);

#ifdef	__cplusplus
}
#endif

#endif	/* LOCALIZATION_H */
