#include <iostream>
#include <stdlib.h>

using namespace std;

int main () {
  int star, rad;

  cin >> star;
  rad = 1000001;

  for (int i = 0; i < star; i++) {
    int x, y, r;

    cin >> x >> y >> r;

    y = abs(y);

    if (y - r > 0) {
      if (rad > y - r) {
        rad = y - r;
      }
    } else {
      rad = -1;
      break;
    }
  }

  cout << rad << endl;

  return 0;
}
