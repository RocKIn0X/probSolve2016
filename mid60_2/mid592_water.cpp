#include <cstdio>
#define MAX 1005

using namespace std;

int main () {
  int n, sum;
  int water[MAX];
  water[0] = 0;
  sum = 0;

  scanf("%d", &n);

  for (int i = 1; i <= n; i++) {
    scanf("%d", &water[i]);

    int diff = water[i-1] - water[i];

    if (diff > 10) {
      if (diff * 10 > 700) {
        sum += 700;
      } else {
        sum += diff*10;
      }
    }
  }

  printf("%d\n", sum);

  return 0;
}
