/* 
 * File:   ping.h
 * Author: bj57
 *
 * Created on February 26, 2023, 6:33 PM
 */

#ifndef PING_H
#define	PING_H

#ifdef	__cplusplus
extern "C" {
#endif

    void init_ping();
    int pingDistance(long duration);
    void displayPingDistance(int distance);

#ifdef	__cplusplus
}
#endif

#endif	/* PING_H */

