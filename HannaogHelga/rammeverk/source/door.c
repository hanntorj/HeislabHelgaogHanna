#include "state.h" //hjelp er dette lov?



int timer_open_door = 3;
int door_is_open=0;
//int stop_button= elev_get_stop_signal(); //hjelp hvordan sette stopknapp

/*
void wait(int seconds){
  clock_t end_wait;
  end_wait=clock()+ seconds * CLK_TCK(); /
  while (clock() < end_wait) {};
}*/
/*
void open_door(){
  if(elev_get_floor_sensor_signal && elev_motor_direction_t==0){ //hjelp hvordan hente ut motor retningen når den er i ro
    elev_set_door_open_lamp(1);
  //  wait(timer_open_door);
  //  elev_set_door_open_lamp(0);
  }
}

void stop_button_while_in_floor(){
  if(stop_button){
    open_door();
  }
}
*/
