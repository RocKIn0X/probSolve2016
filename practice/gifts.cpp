#include <iostream>

using namespace std;

void sumValue(int n) {
  int value, sum;
  sum = 0;

  for (int i = 0; i < n; i++) {
    cin >> value;

    if (value > 0) {
      sum += value;
    }
  }

  cout << sum << endl;
}

int main () {
    int n = 0;

    cin >> n;
    sumValue(n);

    return 0;
}
