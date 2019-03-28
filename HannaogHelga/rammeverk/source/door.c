#include "state.h" //hjelp er dette lov?
#include "time.h"


int timer_open_door_ms = 30000; //ms
int door_is_open=0;
int stop_button = -1;
clock_t start_timer



/*void timer(){
  int msec=0;
  clock_t before = clock();
  do{
    clock_t difference = clock()- before;
    msec = difference*1000 / CLOCKS_PER_SEC;
  }while (msec < timer_open_door_ms);
}
*/

void open_door(){
  if(elev_get_floor_sensor_signal() && DIRN_STOP){
    elev_set_door_open_lamp(1);
    timer();
    elev_set_door_open_lamp(0);
  }
}

void stop_button_while_in_floor(){
  stop_button=elev_get_stop_signal();
  if(stop_button){
    open_door();
  }
}
