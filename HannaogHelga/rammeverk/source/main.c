#include "elev.h"
#include "state.h"
/*! \mainpage About
 *
 * A program coded in c language that controls an elevator with 4 floors.
 *
 * For the course "Tilpassede Datasystemer" (TTK4235) at NTNU spring 2019.
 *
 * -Helga and Hanna
 */
#include <stdio.h>

int main() {
  if(!elev_init()) {
    printf("Unable to initialize elevator hardware!\n");
    return 1;
  }
  while(1){
    FSM();
  }
  return 0;
}
