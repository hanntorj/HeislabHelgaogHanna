/**
* @brief Switches between the different states of the elevator.
*/
#ifndef TIMER_H
#define TIMER_H

#include "elev.h"
#include "control.h"
#include "utilities.h"
#include <stdio.h>
#include "timer.h"
#include <time.h>

/**
* @brief Enum class representing the states the elevator can acquire.
*/

typedef enum tag_elev_state{
  INIT, /** Case when initializing the elevator.*/
  NO_ORDERS, /** Case when the elevator is on a floor, with no orders waiting.*/
  RUNNING, /** Case when the elevator is operating between floors.*/
  OPEN_DOOR, /** Case when the elevator stops at a floor and opens the door.*/
  STOP_BUTTON_PRESSED /** Case when the stop button is continuously pressed*/
} elev_state_t;


/*elev_motor_direction_t get_direction();
void set_direction(elev_motor_direction_t direction_rhs);*/

/*int get_current_floor();*/
/**
* @brief Updates the local variable that represents the last floor(0-3)
  the elevator stopped at or passed.
*/
void update_current_floor();

elev_state_t state_init();

elev_state_t state_no_orders();

int go_to_target_floor();
elev_state_t state_open_door();
elev_state_t state_stop_button_pressed();
void FSM();

#endif
