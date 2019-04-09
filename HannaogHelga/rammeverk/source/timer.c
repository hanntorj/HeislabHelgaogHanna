#include "timer.h"

clock_t begin, end;
double time_spent;

void timer_start(){
  begin = clock();
}

int timer_end(){
  int sec = 3;
  end = clock();
  time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  if(time_spent >= sec){
    return 0;
  }
  else{
    return 1;
  }
}
