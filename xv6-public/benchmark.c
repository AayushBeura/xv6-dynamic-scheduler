// benchmark.c
#include "types.h"
#include "user.h"

int main() {
  int start = uptime();
  
  // Do some fixed amount of work
  long sum = 0;
  for(long i = 0; i < 1000000000; i++) {
    sum += i;
  }
  
  int end = uptime();
  printf(1, "Completed in %d ticks\n", end-start);
  exit();
}
