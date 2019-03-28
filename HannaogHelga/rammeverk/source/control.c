#include "control.h"

int queue[N_FLOORS][3];
elev_button_type_t button;




void new_order(){
  for(int i=0; i<N_FLOORS; i++){
    if ((i!=N_FLOORS-1) && elev_get_button_signal(BUTTON_CALL_UP, i)){
      queue[i][0]=1;
    }
    if ((i!=0) && elev_get_button_signal(BUTTON_CALL_DOWN, i)){
      queue[i][1]=1;
    }
    if (elev_get_button_signal(BUTTON_COMMAND, i)){
      queue[i][2]=1;
    }
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

int get_next_floor(int current_floor, elev_motor_direction_t direction){
    int target_floor=-1;
    while (has_orders()){
        if (direction==DIRN_UP){
            target_floor=has_orders_above(current_floor);
            if (target_floor==-1){
                target_floor=has_orders_below(current_floor);
            }
        }
        else if (direction==DIRN_DOWN){
            target_floor=has_orders_below(current_floor);
            if (target_floor==-1){
                target_floor=has_orders_above(current_floor);
            }
        }
    }
    return target_floor;
    // if dir = opp
        // sjekke om bestilling over meg // først opp/cab deretter evt. ned
        // sjekke om bestilling under meg // først ned/cab derretter evt. opp

    // if dir = ned
        // sjekke om bestilling under meg // først ned/cab derretter evt. opp
        // sjekke om bestilling over meg // først opp/cab deretter evt. ned
    //
}

elev_motor_direction_t get_next_direction(int current_floor, int target_floor){
    if(target_floor<current_floor){
        return DIRN_DOWN;
    }
    else{
        return DIRN_UP;
    }
}
