#include "state.h" //hjelp er dette lov?
#include "time.h"

int timer_open_door_ms = 30000; //ms
int door_is_open=0;
clock_t start_time

int has_time_passed(double delay, clock_t start_time){
	clock_t clock_ticks_taken = clock() - start_time;
	double time_in_seconds = clock_ticks_taken/(double) CLOCKS_PER_SEC;
	if(time_in_seconds>delay){
		return 1;
	}
	else{
		return 0;
	}
}

void open_door(){
  if(elev_get_floor_sensor_signal(){
    elev_set_door_open_lamp(1);
    if(has_time_passed()){
    elev_set_door_open_lamp(0);
  }
  }
}

void stop_button_while_in_floor(){
  stop_button=elev_get_stop_signal();
  if(stop_button){
    elev_set_door_open_lamp(1);
  }
  else open_door();
}
int stop_button = -1;
