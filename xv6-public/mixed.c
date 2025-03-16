// mixed.c
#include "types.h"
#include "user.h"

int main() {
  printf(1, "Mixed workload process %d starting\n", getpid());
  for(int i = 0; i < 10; i++) {
    int x = 0;
    // Compute for a while
    for(int j = 0; j < 100000000; j++) {
      x += j;
    }
    sleep(1);
  }
  exit();
}
