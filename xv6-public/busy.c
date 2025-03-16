// busy.c
#include "types.h"
#include "user.h"

int main() {
  printf(1, "CPU-intensive process %d starting\n", getpid());
  while(1) { /* infinite loop */ }
  exit();
}
