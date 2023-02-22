/* 
 * File:   motor_control.h
 * Author: bj57
 *
 * Created on February 9, 2023, 4:52 PM
 * Include file for motor control
 */

#ifndef MOTOR_CONTROL_H
#define	MOTOR_CONTROL_H

#ifdef	__cplusplus
extern "C" {
#endif

    void init_motors();
    void forward();
    void backward();
    void left();
    void right();
    void stop();

#ifdef	__cplusplus
}
#endif

#endif	/* MOTOR_CONTROL_H */
