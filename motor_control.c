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
    LATE = 0x01;
}

void forward()
{
    LATE = 0b11010101;
}

void backward()
{
    LATE = 0b10111001;
}

void right()
{
    LATE = 0b11011001;
}

void left()
{
    LATE = 0b10110101;
}

void stop()
{
    LATE = 0x01;
}
