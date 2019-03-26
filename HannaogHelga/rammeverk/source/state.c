#include "state.h"

void stateinit(){

  printf("hei\n");
  current_floor = elev_get_floor_sensor_signal();
  if(current_floor==-1){
    elev_set_motor_direction(DIRN_DOWN);
  }
  while(current_floor == -1){
    printf("TESTING\n");
    current_floor = elev_get_floor_sensor_signal();
  }
  elev_set_motor_direction(DIRN_STOP);

}


void FSM(){
  state=INIT;
  switch(state){
    case INIT:
      stateinit();
      state=STOP_ON_FLOOR;
    case STOP_ON_FLOOR:
      printf("Yo\n");
    case MOVING:
      break;

    case OPEN_DOOR:
      break;
    case STOP_BUTTON_PRESSED:
      break;
  }

}
