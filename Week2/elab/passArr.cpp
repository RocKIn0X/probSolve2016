#include <iostream>
using namespace std;

void find_max_min(int b[], int n, int* max, int* min) {
  int c = 0;

  *max = 0;
  *min = 999999;

  while (c < n) {
    if (b[c] > *max) {
      *max = b[c];
    }

    if (b[c] < *min) {
      *min = b[c];
    }
    c++;
  }
}

main() {
  int a[1000];
  int n;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int mx, mn;
  find_max_min(a, n, &mx, &mn);

  cout << "max = " << mx << endl;
  cout << "min = " << mn << endl;
}
