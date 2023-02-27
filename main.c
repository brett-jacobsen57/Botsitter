/**
  Generated main.c file from MPLAB Code Configurator

  @Company
    Microchip Technology Inc.

  @File Name
    main.c

  @Summary
    This is the generated main.c using PIC24 / dsPIC33 / PIC32MM MCUs.

  @Description
    This source file provides main entry point for system initialization and application code development.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.171.1
        Device            :  PIC24FJ128GA010
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.70
        MPLAB 	          :  MPLAB X v5.50
*/

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/**
  Section: Included Files
*/
#include "mcc_generated_files/system.h"
#include "i2c.h"
#include "delay.h"
#include "bluetooth.h"
#include "localization.h"
#include "motor_control.h"
#include "ping.h"
#include "lcd.h" // For testing purposes

#define BusyLCD() readLCD(0) & 0x80
#define putLCD(d) writeLCD(1,(d))
#define cmdLCD(c) writeLCD(0,(c))
#define homeLCD() writeLCD(0,2)
#define clrLCD() writeLCD(0,1)

const int A = 70;
const int n = 2;

long duration = 0; 
long durationms = 0;
int distance = 0;
float x = 0;
float y = 0;

int main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    init_ping();
    initLCD();
    init_motors();
    
    int x1 = 0;
    int y1 = 0;
    int x2 = 300;
    int y2 = 0;
    
    int RSSI1;
    int RSSI2;
    
    while (1)
    {
        RSSI1 = -69;
        RSSI2 = -77;
        
        float d1 = distanceFromRSSI(RSSI1, n, A);
        float d2 = distanceFromRSSI(RSSI2, n, A);
        findCoordinates(&x, &y, x1, y1, x2, y2, d1, d2);
        displayCoordinates(x, y);
        
        distance = pingDistance(duration);
        
        if (PORTDbits.RD6 == 0)
            forward();
        else if (PORTDbits.RD7 == 0)
            backward();
        else if (PORTDbits.RD13 == 0)
            stop();
        
        if (distance > 25 && distance < 50)
        {
            PORTAbits.RA1 = 1;
        }
        for (int i=0; i<6000; i++);
        PORTAbits.RA1 = 0;
        
        //displayPingDistance(distance);
        
        for (int i=0; i<3000; i++); //delay roughly 4 milliseconds */
    }
    
    return 1;
}
/**
 End of File
*/
