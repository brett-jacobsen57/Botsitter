/* 
 * File:   localization.c
 * Author: bj57
 *
 * Created on February 9, 2023, 4:50 PM
 * Implementation file for localization functions
 */

#include "mcc_generated_files/system.h"
#include "localization.h"
#include "stdlib.h"
#include "math.h"
#include "i2c.h"
#include "lcd.h"

#define BusyLCD() readLCD(0) & 0x80
#define putLCD(d) writeLCD(1,(d))
#define cmdLCD(c) writeLCD(0,(c))
#define homeLCD() writeLCD(0,2)
#define clrLCD() writeLCD(0,1)

const double PI = 3.1415926535;

float distanceFromRSSI(int RSSI, int n, int A)
{
    float u = -A - RSSI;
    float v = 10 * n;
    float w = u/v;
    float d = pow(10, w);
    
    float distance = d * 100;
    return distance;
}

void findCoordinates(float *x, float *y, int x1, int y1, int x2, int y2, float d1, float d2)
{
    float u;
    float v;
    float w;
    
    float a;
    float b;
    float c;
        
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

void displayCoordinates(float x, float y)
{
    cmdLCD(0x80); //clears LCD
    int xDisp = (int)x;
    int yDisp = (int)y;
    
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;
    int x3 = 0;
    int y3 = 0;
    setCursorAtLine(1);
    putLCD('x');
    putLCD(':');
    putLCD(' ');
    x3 = xDisp%10; //isolate digit 3
    xDisp = xDisp/10; //divide by 10 for next digit
    x2 = xDisp%10; //isolate digit 2
    xDisp = xDisp/10; //divide by 10 for next digit 
    x1 = xDisp;
    putLCD(x1 + 0x30); //print digits and convert to hex so LCD happy
    putLCD(x2 + 0x30);
    putLCD(x3 + 0x30);
    setCursorAtLine(2);
    putLCD('y');
    putLCD(':');
    putLCD(' ');
    y3 = yDisp%10; //isolate digit 3
    yDisp = yDisp/10; //divide by 10 for next digit
    y2 = yDisp%10; //isolate digit 2
    yDisp = yDisp/10; //divide by 10 for next digit 
    y1 = yDisp;
    putLCD(y1 + 0x30); //print digits and convert to hex so LCD happy
    putLCD(y2 + 0x30);
    putLCD(y3 + 0x30);
}