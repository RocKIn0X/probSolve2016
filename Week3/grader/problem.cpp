#include <iostream>

using namespace std;

main () {
  int i, j, n, sum;

  n = 1;

  while (true) {
    cin >> i >> j;

    sum = i;

    while (n < j) {
      if (sum % 2 != 0) {
        sum = 3 * sum + 1;
      } else {
        sum = sum / 2;
      }
      n++;
    }

    n = 1;
    cout << i << ' ' << j << ' ' << sum << endl;
  }
}
