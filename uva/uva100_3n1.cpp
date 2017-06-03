#include <cstdio>

using namespace std;

void numCycle (int a, int* b) {
  if (a == 1) return;

  *b += 1;

  if (a % 2 != 0) return numCycle(3*a+1, b);
  else return numCycle(a/2, b);
}

int main () {
  int a, b;

  while (true) {
    int cycleMax = 0;
    int min, max;

    int r = scanf("%d %d", &a, &b);
    if(r != 2) {
      break;
    }

    if (a > b) {
      max = a;
      min = b;
    } else {
      max = b;
      min = a;
    }

    for (int i = min; i <= max; i++) {
      int cycle = 1;
      numCycle(i, &cycle);

      if (cycle > cycleMax) {
        cycleMax = cycle;
      }
    }

    printf("%d %d %d\n", a, b, cycleMax);
  }

  return 0;
}
