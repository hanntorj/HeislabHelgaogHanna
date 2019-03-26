#include "state.h"
#include "elev.h"
#include "control.h"

elev_motor_direction_t direction;

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

/*stille(){
hvis floor er -1 gå til case stå stille
hvis floor !=-1 gå til case RUNNING
}
*/
elev_state_t state_no_orders(int current_floor, elev_motor_direction_t direction, elev_state_t state){

    int floor = get_next_instructions(current_floor, get_direction());
    if (floor!=-1){
        state=RUNNING;
        printf("Floor is %d\n", floor);
    }
    else{
        state=NO_ORDERS;
    }
    return state;
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
  switch(state){
    case INIT:
      state_init();
      state = NO_ORDERS;
    case NO_ORDERS:
        state = state_no_orders(current_floor, direction, state);//klarer ikke å komme over til RUNNING. Når vi printer state er den 2 aka RUNNING så skjønner ikke. det må være noe feil med køen vår
        break;
    case RUNNING:
      break;
    case OPEN_DOOR:
      break;
    case STOP_BUTTON_PRESSED:
      break;
  }
  return state;
}
