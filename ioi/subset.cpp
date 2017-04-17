#include <cstdio>
#include <math.h>

using namespace std;

int main() {
  char c;
  int count = 0;

  scanf("%c", &c);
  scanf("%c", &c);

  if (c != '}') {
    count = 1;
    while (c != '}') {
      scanf("%c", &c);

      if (c == ',') {
        count++;
      }
    }
  }

  printf("%d\n", (int)pow(2, count));

  return 0;
}
