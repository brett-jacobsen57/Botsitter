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

void findCoordinates(double *x, double *y, int x1, int y1, int x2, int y2, double d1, double d2)
{
    double u;
    double v;
    double w;
    
    double a;
    double b;
    double c;
        
    u = pow(x2, 2) - pow(x1, 2) + pow(d1, 2) + pow(y2, 2) - pow(y1, 2) - pow(d2, 2);
    v = 2 * (x2 - x1);
    w = y2 - y1;
    
    a = 1 + ((4*pow(w, 2))/(2*pow(v, 2)));
    b = ((4*w*(x1-u))/v) - 2*y1;
    c = (pow(u, 2)/pow(v, 2)) - ((2*x1*u)/v) + y1 - pow(d1, 2);
    
    *y = (-b + sqrt(pow(b, 2) - 4*a*c))/2*a;
    if (*y < 0)
    {
        *y = abs(*y);
    }
    *x = sqrt(pow(d1, 2) - pow(*y, 2));
}

double findDistance(int x1, int y1, int x2, int y2)
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