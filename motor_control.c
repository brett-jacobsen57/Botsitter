/* 
 * File:   motor_control.c
 * Author: bj57
 *
 * Created on February 9, 2023, 4:52 PM
 * Implementation file for motor control
 */

#include "mcc_generated_files/system.h"
#include "motor_control.h"

void init_motors()
{
    TRISE = 0x00;
}

void forward()
{
    PORTE = 0b11010101;
}

void backward()
{
    PORTE = 0b10111001;
}

void right()
{
    PORTE = 0b11011001;
}

void left()
{
    PORTE = 0b10110101;
}

void stop()
{
    PORTE = 0x01;
}
