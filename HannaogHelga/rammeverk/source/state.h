#include "elev.h"
#include <stdio.h>


typedef enum tag_elev_state{
  INIT,
  NO_ORDERS,
  RUNNING,
  OPEN_DOOR,
  STOP_BUTTON_PRESSED
} elev_state_t;

int current_floor;

elev_motor_direction_t get_direction();

//int stop_button= elev_get_stop_signal();

void state_init();

elev_state_t state_no_orders(int current_floor, elev_motor_direction_t direction, elev_state_t state);

elev_state_t FSM(elev_state_t state);
