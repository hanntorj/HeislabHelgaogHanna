#include "elev.h"
#include "control.h"
#include "door.h"
#include <stdio.h>


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
void set_current_floor();

//int stop_button= elev_get_stop_signal();

void state_init();

int go_to_target_floor();

elev_state_t FSM(elev_state_t state);
