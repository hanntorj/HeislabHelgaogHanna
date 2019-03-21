#include "door.h"
#include "state.h"
#include <ctime>
#include <iostream>
using namespace std;

void wait(int seconds){
  clock_t end_wait;
  end_wait=clock()+ seconds * CLK_TCK();
  while (clock() < end_wait) {};
}

void open_door(){
  if(elev_get_floor_sensor_signal && motor_speed==0){
    elev_set_door_open_lamp(1); // hvordan setter vi denne i kun 3 sekunder?
    wait(timer_open_door);
    elev_set_door_open_lamp(0);
  }


void stop_button_while_in_floor(){
  if(stop_button){
    open_door();
  }
}
