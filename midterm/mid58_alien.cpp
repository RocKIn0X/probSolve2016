#include <cstdio>

using namespace std;

int main () {
  int n, a, b, r, x, y, people;

  scanf("%d %d %d %d", &n, &a, &b, &r);

  r = r * r;
  people = 0;

  for (int i = 0; i < n; i++) {
    scanf("%d %d", &x, &y);

    if ( ((x-a)*(x-a)) + ((y-b)*(y-b)) <= r ) {
      people++;
    }
  }

  printf("%d\n", people);
}
