#include "utilities.h"

clock_t start_time;

void start_timer(time_t* current_time){
	time(current_time);
}

int timer_3_sec(time_t door_timer_start){
	time_t current_time;
	time(&current_time);
	return(labs(current_time-door_timer_start)>=3);
}

/*
void open_door(){
	printf("open door");
	elev_set_door_open_lamp(1);
  if (timer_3_sec(start_time)){
    elev_set_door_open_lamp(0);
  }
}
*/
void stop_button_while_in_floor(){
  stop_button=elev_get_stop_signal();
  if(stop_button){
    elev_set_door_open_lamp(1);
  }
  else open_door();
}
int stop_button = -1;
