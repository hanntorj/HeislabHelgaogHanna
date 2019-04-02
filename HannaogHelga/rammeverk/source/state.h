/**
* @brief Switches between the different states of the elevator.
*/
#ifndef STATE_H
#define STATE_H

#include "elev.h"
#include "control.h"
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

/**
* @brief Transports the elevator to the prioritized floor in queue.
* @return 1 if the elevator has arrived at the floor, 0 if not.
*/
int go_to_target_floor();

/**
* @brief Tells the elevator what to do when initializing.
* @return THe elevator's next state.
*/
elev_state_t state_init();

/**
* @brief Tells the elevator what to do when it has no orders in queue.
* @return The elevator's next state.
*/
elev_state_t state_no_orders();

elev_state_t state_running();

/**
* @brief Opens the elevator door.
* @return The elevator's next state.
*/
elev_state_t state_open_door();

/**
* @brief Handles the elevator when stop button is pressed.
* @return The elevator's next state.
*/
elev_state_t state_stop_button_pressed();

/**
* @brief Contains a switch between the sates the elevator acquires.
*/
void FSM();

#endif
