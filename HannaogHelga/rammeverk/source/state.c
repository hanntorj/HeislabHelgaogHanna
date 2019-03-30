#include "state.h"

elev_motor_direction_t direction;
int current_floor;
elev_state_t state = INIT;


int get_current_floor() {
  return current_floor;
}

void update_current_floor(){
    current_floor = elev_get_floor_sensor_signal();
    if(current_floor!=-1){
      elev_set_floor_indicator(current_floor);
    }
}

elev_motor_direction_t get_direction(){
    return direction;
}

void set_direction(elev_motor_direction_t direction_rhs){
  direction= direction_rhs;
}

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
  if(elev_get_stop_signal()){
    return STOP_BUTTON_PRESSED;
  }
    int arrived = go_to_target_floor();
    if(arrived){
      return OPEN_DOOR;
    }
  return RUNNING;
}

elev_state_t state_open_door(){
//  open_door();
  	printf("open door");

 //antar at dette skjer først, dvs døren lukkes før den går videre. Test dette!
  delete_orders_at_floor(current_floor);
  if(elev_get_stop_signal()){
    return  STOP_BUTTON_PRESSED;
  }
  else if(has_orders()){
    return  RUNNING;
    }
  else if(!has_orders()){
    return  NO_ORDERS;
  }
  return OPEN_DOOR;
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

void FSM(){
  update_current_floor();
  new_order();
//  printf("\n %d \n",state);
  switch(state){

    case INIT:
    //må lage noe som ignorerer nye forsøk på bestillinger
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
    printf("%d \n", state);
      state = state_open_door();
      break;
    case STOP_BUTTON_PRESSED:
    printf("stop button pressed");
  /*  elev_set_motor_direction(DIRN_STOP);
      while(elev_get_stop_signal){
        delete_all_orders();//køen slettes
        if(get_current_floor!=-1){//sjekk om i etg, isåfall åpen dør konstant
          stop_button_while_in_floor();
      }
      //gå til neste state
      if(new_order()){
        state=RUNNING;
      }*/
      break;
}
}
