#include "elev.h"
#include "control.h"
#include "utilities.h"
#include <stdio.h>
#include "timer.h"
#include <time.h>


typedef enum tag_elev_state{
  INIT,
  NO_ORDERS,
  RUNNING,
  OPEN_DOOR,
  STOP_BUTTON_PRESSED
} elev_state_t;



elev_motor_direction_t get_direction();
void set_direction(elev_motor_direction_t direction_rhs);

int get_current_floor();
void update_current_floor();

/**
* @brief Tells the elevator what to do when initializing.
* @return The elevators next state.
*/
elev_state_t state_init();

/**
* @brief Tells the elevator what to do when it has no orders in queue.
* @return The elevators next state.
*/
elev_state_t state_no_orders();

/**
* @brief Transports the elevator to the prioritized floor in queue.
* @return 1 if the elevator has arrived at the floor, 0 if not.
*/
int go_to_target_floor();

/**
* @brief Opens the elevator door.
* @return The elevators next state.
*/
elev_state_t state_open_door();

/**
* @brief Handles the elevator when stop button is pressed.
* @return The elevators next state.
*/
elev_state_t state_stop_button_pressed();

/**
* @brief Contains a switch between the sates the elevator acquires. 
*/
void FSM();
