#include "control.h"

void new_order(elev_button_type_t button,int floor_requested){
  if (button==BUTTON_CALL_UP){
  queue[floor_requested][0]=1;
  }
  else if (button==BUTTON_CALL_DOWN){
  queue[floor_requested][1]=1;
  }
  else if (button==BUTTON_COMMAND){
  queue[floor_requested][2]=1;
  }
}

void delete_order(int floor){
  for (int i=0; i<3; i++) {
    queue[floor][i]=0;
  }
}

void delete_all_orders(){
  for(int i=0; i<N_FLOORS; i++){
    delete_order(i);
  }
}

int has_orders(void){
  for(int i=0; i<N_FLOORS; i++){
    for (int j=0; j<3; j++){
      if (queue[i][j]==1){
        return 1;
      }
    }
  }
  return 0;
}

// has CheckOrdersAbove
// etg curr-N med bestilliung
// -1 om ingen bestilling
int has_orders_above(int current_floor){
    for (int i=current_floor; i<N_FLOORS; i++){
        if(queue[i][0] || queue[i][2]){
          return i;
        }
    }
    for (int i=current_floor; i<N_FLOORS; i++){
        if(queue[i][1]){
          return i;
        }
    }
    return -1;
}

// has orders below
int has_orders_below(int current_floor){
    for (int i=current_floor; i>=0; i--){
        if(queue[i][1] || queue[i][2]){
          return i;
        }
    }
    for (int i=current_floor; i>=0; i--){
        if(queue[i][0]){
          return i;
        }
    }
    return -1;
}

// get nextFloor
int get_next_floor(int current_floor, elev_motor_direction_t direction){
    int floor=-1;
    while (has_orders()){
        if (direction==DIRN_UP){
            floor=has_orders_above(current_floor);
            if (floor==-1){
                floor=has_orders_below(current_floor);
            }
        }
        else if (direction==DIRN_DOWN){
            floor=has_orders_below(current_floor);
            if (floor==-1){
                floor=has_orders_above(current_floor);
            }
        }
    }
    return floor;
    // if dir = opp
        // sjekke om bestilling over meg // først opp/cab deretter evt. ned
        // sjekke om bestilling under meg // først ned/cab derretter evt. opp

    // if dir = ned
        // sjekke om bestilling under meg // først ned/cab derretter evt. opp
        // sjekke om bestilling over meg // først opp/cab deretter evt. ned
    //
}

int get_next_instructions(int current_floor, elev_motor_direction_t direction){
    int floor = get_next_floor(current_floor, direction);
    if(floor<current_floor){
        direction=DIRN_DOWN;
    }
    else{
        direction=DIRN_UP;
    }
    return floor;
}
