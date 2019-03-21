#include "elev.h"

int floor;
int motor_speed;
bool stop_button= elev_get_stop_signal;

elev_motor_direction_t get_direction();
void set_motor_speed();
