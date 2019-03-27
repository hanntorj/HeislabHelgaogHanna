#include "state.h" //hjelp er dette lov?
#include "time.h"


int timer_open_door = 3;
int door_is_open=0;
int stop_button = -1;


void has_time_passed(int seconds, clock_t reference){
  clock_t new_time = clock();
  if(((new_time-reference)/CLOCKS_PER_SEC)>= count_s){
    return 1;
  }
  return 0;
}

void open_door(){
  if(elev_get_floor_sensor_signal() && DIRN_STOP){ 
    elev_set_door_open_lamp(1);
    if(has_time_passed(timer_open_door, )){
      elev_set_door_open_lamp(0);
    }
  }
}

void stop_button_while_in_floor(){
  stop_button=elev_get_stop_signal();
  if(stop_button){
    open_door();
  }
}
