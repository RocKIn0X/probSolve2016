#include <cstdio>
#include <iostream>
#define MAX_R 10
#define MAX_C 10

using namespace std;

int r, c, b, t;
int hungry[MAX_R];

int main() {
  int sum = 0;
  int ratio;

  scanf(" %d %d %d %d", &r, &c, &b, &t);

  ratio = b/t;

  for (int i = 0; i < r; i++) {
    hungry[i] = 0;
    for (int j = 0; j < c; j++) {
      int num;
      cin >> num;
      hungry[i] += num;
    }
  }

  for (int i = 0; i < r; i++) {
    sum += hungry[i]/ratio;

    if (hungry[i] % ratio != 0) {
      sum += 1;
    }
  }

  printf("%d\n", sum);

  return 0;
}
