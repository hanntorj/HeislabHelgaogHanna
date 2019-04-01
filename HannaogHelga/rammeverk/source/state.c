#include "state.h"
#include "timer.h"

elev_motor_direction_t direction;
int current_floor;
elev_state_t state = INIT;


/*int get_current_floor() {
  return current_floor;
}*/

void update_current_floor(){
    if (elev_get_floor_sensor_signal()!=-1){
        current_floor = elev_get_floor_sensor_signal();
        }
    if(current_floor!=-1){
        elev_set_floor_indicator(current_floor);
    }
}
/*
elev_motor_direction_t get_direction(){
    return direction;
}

void set_direction(elev_motor_direction_t direction_rhs){
  direction= direction_rhs;
}
*/
elev_state_t state_init(){
  current_floor = elev_get_floor_sensor_signal();
  if(current_floor==-1){
    elev_set_motor_direction(DIRN_DOWN);
  }
  while(current_floor == -1){
    elev_set_motor_direction(DIRN_DOWN);
    current_floor = elev_get_floor_sensor_signal();
  }
  direction = DIRN_DOWN;
  elev_set_motor_direction(DIRN_STOP);
  return NO_ORDERS;
}

int go_to_target_floor(){
  int target_floor = get_next_floor(current_floor, direction);
  direction = get_next_direction(current_floor, target_floor);
  elev_set_motor_direction(direction);
  if (target_floor == current_floor){
    elev_set_motor_direction(DIRN_STOP);
    return 1;
  }
  return 0;
}

elev_state_t state_no_orders(){
  if(elev_get_stop_signal()){
    return STOP_BUTTON_PRESSED;
  }
  if (has_orders()){
      return RUNNING;
  }
    return NO_ORDERS;
}

elev_state_t state_running(){
  int arrived = go_to_target_floor();
  if(arrived){
      return OPEN_DOOR;
  }
  else if(elev_get_stop_signal()){
      return STOP_BUTTON_PRESSED;
  }
  return RUNNING;
}

elev_state_t state_open_door(){
  timer_start();
  while(timer_end()==1){
    elev_set_door_open_lamp(1);
    delete_orders_at_floor(current_floor);
    new_order();
    if(elev_get_stop_signal()){
      return STOP_BUTTON_PRESSED;
    }
  }
  elev_set_door_open_lamp(0);

 if(has_orders()){
    return  RUNNING;
    }
  else if(!has_orders()){
    return  NO_ORDERS;
  }
  return OPEN_DOOR;
}

elev_state_t state_stop_button_pressed(){
  int has_stopped= 0;
  while(elev_get_stop_signal()){
    elev_set_motor_direction(DIRN_STOP);
    elev_set_stop_lamp(1);
    delete_all_orders();
    if(elev_get_floor_sensor_signal() != -1){
      elev_set_door_open_lamp(1);
    }
    has_stopped = 1;
  }
  elev_set_stop_lamp(0);

if (has_stopped ==1 && elev_get_floor_sensor_signal()!=-1){
   elev_set_door_open_lamp(1);
    timer_start();
    while(timer_end()==1){
      elev_set_door_open_lamp(1);
    }
    elev_set_door_open_lamp(0);
  }
if(has_orders()){
  return RUNNING;
  }
return STOP_BUTTON_PRESSED;
}

void FSM(){
  update_current_floor();
  new_order();
  switch(state){
    case INIT:
      state = state_init();
      break;
    case NO_ORDERS:
      state = state_no_orders();
      break;
    case RUNNING:
    //printf("%d", state);
      state = state_running();
      break;
    case OPEN_DOOR:
      printf("open door");
      state = state_open_door();
      break;
    case STOP_BUTTON_PRESSED:
      state = state_stop_button_pressed();
      break;
    }
  }
