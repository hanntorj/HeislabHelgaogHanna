/**
* @file
* @brief Dette er køkontrolløren vår.
*/
#include "elev.h"

int queue[N_FLOORS][3];
elev_button_type_t button;
int floor_requested;

void new_order(elev_button_type_t button,int floor_requested);
void delete_order(int floor);
void delete_all_orders();
int has_orders(void);
int has_orders_above(int current_floor);
int has_orders_below(int current_floor);
int get_next_floor(int current_floor, elev_motor_direction_t direction);
int get_next_instructions(int current_floor, elev_motor_direction_t direction);
