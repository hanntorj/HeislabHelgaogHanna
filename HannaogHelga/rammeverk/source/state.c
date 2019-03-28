#include "state.h"

elev_motor_direction_t direction;
int current_floor;

void state_init(){
  current_floor = elev_get_floor_sensor_signal();
  if(current_floor==-1){
    elev_set_motor_direction(DIRN_DOWN);
  }
  while(current_floor == -1){
    elev_set_motor_direction(DIRN_DOWN);
    current_floor = elev_get_floor_sensor_signal();
  }
  elev_set_motor_direction(DIRN_STOP);
}

elev_motor_direction_t get_direction(){
    return direction;
}

int get_current_floor() {
  return current_floor;
}
void set_direction(elev_motor_direction_t direction_rhs){
  direction= direction_rhs;
}

void set_current_floor(){
  current_floor = elev_get_floor_sensor_signal();
  elev_set_floor_indicator(current_floor);
}

int run(){
  int target_floor = get_next_floor(current_floor, direction);
  direction = get_next_direction(current_floor, target_floor);
  elev_set_motor_direction(direction);
  if (target_floor == current_floor){
    elev_set_motor_direction(DIRN_STOP);
    return 1;
  }
  return 0;
}

/*kjør(){
    les hvilken etg vi skal til og sett retning med funksjonen instuksjon...
    setter elev_set_motor_direction til direction
    stoppe i floor
    hopper til case åpen dør
}*/


/*case åpen dør()
stopp når vi når etg floor
åpne dør/lukke dør
slett alle bestillinger i floor
gå til ny case
*/

elev_state_t FSM(elev_state_t state){
  set_current_floor();
  new_order();
  switch(state){
    case INIT:
      state_init();
      state = NO_ORDERS;
    case NO_ORDERS:
      if (has_orders()){
      state = RUNNING;}
      break;
    case RUNNING:
    //gå til case  stop
      if (run()){
      state=OPEN_DOOR;
      }
      break;
    case OPEN_DOOR:
      open_door();
      delete_order(current_floor);
      //...hvilken caase den skal til
      break;
    case STOP_BUTTON_PRESSED:
    
      break;


}
return state;
}
