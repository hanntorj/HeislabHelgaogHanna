/**
* @file
* @brief A control system for elevator orders.
*/

#ifndef CONTROL_H
#define CONTROL_H

#include "elev.h"
/**
* @brief Takes new orders and adds them to the queue.
*/
void new_order();

/**
* @brief Delete orders at a floor.
* @param floor Floor number (0-3) to delete all orders from.
*/
void delete_orders_at_floor(int floor);

/**
* @brief Delete all orders in queue.
*/
void delete_all_orders();

/**
* @brief Checks for orders in queue.
* @return 1 if orders in queue, 0 if not.
*/
int has_orders();

/**
* @brief Checks for orders above current floor.
* @param current_floor The floor the elevator is located at.
* @return the next floor (0-3) the elevator should go to, must be above current floor.
*/
int has_orders_above(int current_floor);

/**
* @brief Checks for orders below current floor.
* @param current_floor The floor the elevator is located at.
* @return the next floor (0-3) the elevator should go to, must be below current floor.
*/
int has_orders_below(int current_floor);

/**
* @brief Tells the elevator which floor to go to next.
* @param current_floor The floor the elevator is located at.
* @param direction The direction the elevator has (up/down).
* @return 0-3, the next floor the elevator is going to.
*/
int get_next_floor(int current_floor, elev_motor_direction_t direction);

/**
* @brief Tells the elevator which direction to go next.
* @param current_floor The floor the elevator is located at.
* @param target_floor The next floor the elevator is going to.
* @return next direction for the elevator (up/down).
*/
elev_motor_direction_t get_next_direction(double current_floor, int target_floor);

/**
* @brief Checks if the elevator should stop at the floor it is passing.
* @param current_floor The floor the elevator is located at.
* @param direction The direction the elevator has (up/down).
* return 1 if it should stop at that floor, 0 if not.
*/
int should_I_stop(int current_floor, elev_motor_direction_t direction);

#endif
