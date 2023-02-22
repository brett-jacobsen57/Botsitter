/* 
 * File:   localization.c
 * Author: bj57
 *
 * Created on February 9, 2023, 4:50 PM
 * Implementation file for localization functions
 */

#include "localization.h"
#include "stdlib.h"
#include "math.h"
#include "i2c.h"

const double PI = 3.1415926535;

double distanceFromRSSI(int RSSI, int n, int A)
{
    return pow(10, (-A-RSSI)/(10*n)) * 100;
}

void findCoordinates(int x1, int y1, int x2, int y2, double d1, double d2)
{
    return;
}

double distance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2));
}

double findAngle(int y2, int y1, double distance)
{
    return asin((y2 - y1)/distance);
}

double findTargetDirection(int x1, int x2, int y1, int y2, double angle)
{
    if (x2 > x1 && y2 > y1)
        return PI - angle;
    else if (x2 < x1 && y2 > y1)
        return angle;
    else if (x2 < x1 && y2 < y1)
        return -angle;
    else
        return PI + angle;
}

double findCurrentDirection()
{
    return 0;
}