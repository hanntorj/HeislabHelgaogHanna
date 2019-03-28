/**
* @file
* @brief Dette er køkontrolløren vår.
*/
#include "elev.h"
#include "stdio.h"



void new_order();
void delete_order(int floor);
void delete_all_orders();
int has_orders(void);
int has_orders_above(int current_floor);
int has_orders_below(int current_floor);
int get_next_floor(int current_floor, elev_motor_direction_t direction);
elev_motor_direction_t get_next_direction(int current_floor, int target_floor);
