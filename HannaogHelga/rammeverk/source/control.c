#include "control.h"

void new_order(elev_button_type_t button,int floor_requested){
  if (button=BUTTON_CALL_UP){
  queue[floor_requested][0]=1;
  }
  else if (button=BUTTON_CALL_DOWN){
  queue[floor_requested][1]=1;
  }
  else if (button=BUTTON_COMMAND){
  queue[floor_requested][2]=1;
  }
}

void delete_order(int floor){
  for (int i=0; i<3; i++) {
    queue[floor][i]=0;
  }
}

int give_instructions(int floor, elev_motor_direction_t direction){
  if (direction=DIRN_UP){
    for (int i=floor; i<3; i++){
        if(queue[i][0]=1 || queue[i][2]){
          return i;
        }
    }
  }
  else if (direction=DIRN_DOWN){
    for (int i=floor; i>0; i--){
        if(queue[i][1]=1 || queue[i][2]){
          return i;
        }
    }
  }
  else if (direction=DIRN_STOP){
    //skriv ferdig

  }
}
