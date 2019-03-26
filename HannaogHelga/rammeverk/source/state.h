#include "elev.h"
#include <stdio.h>


typedef enum tag_elev_state{
  INIT,
  STOP_ON_FLOOR,
  MOVING,
  OPEN_DOOR,
  STOP_BUTTON_PRESSED
} elev_state_t;

int current_floor;
elev_motor_direction_t direction;

static elev_state_t state;
//int stop_button= elev_get_stop_signal();

void stateinit();


void FSM();
