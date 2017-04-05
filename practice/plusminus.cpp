#include <iostream>

using namespace std;

int cal() {
  char c;
  int x;

  cin >> c >> x;

  if (c == '+') {
    return x;
  } else if (c == '-') {
    return -x;
  } else {
    return 0;
  }
}

int main () {
  int n, sum;

  sum = 0;
  cin >> n >> sum;

  for (int i = 0; i < n - 1; i++) {
    sum += cal();
  }

  cout << sum << endl;

  return 0;
}
