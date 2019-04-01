/**
* @file
* @brief A timer.
*/
#ifndef TIMER_H
#define TIMER_H

#include <time.h>

/**
* @brief Saves the time when the funcition is called in a local variable @param begin.
*/
void  timer_start();

/**
* @brief Sets a timer, program is still running while timer is running.
* @return 1 if selected seconds has passed, return 0 if not.
*/
int timer_end();

#endif
