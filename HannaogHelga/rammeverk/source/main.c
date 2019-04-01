#include "elev.h"
#include "state.h"
#include <stdio.h>


int main() {
  if (!elev_init()) {
    printf("Unable to initialize elevator hardware!\n");
    return 1;
  }
  while(1){
    FSM();
    }
    return 0;
}
