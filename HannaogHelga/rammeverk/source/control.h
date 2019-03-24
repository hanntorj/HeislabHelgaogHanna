/**
* @file
* @brief Dette er køkontrolløren vår.
*/
int queue[N_FLOORS][elev_button_type_t];
elev_button_type_t button;
int floor_requested;

void new_order(elev_button_type_t button,int floor_requested);
void delete_order(int floor);
int give_instructions(int floor, elev_motor_direction_t directtion);
