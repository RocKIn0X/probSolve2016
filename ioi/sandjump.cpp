#include <iostream>

using namespace std;

int main () {
  int r, s, t, n, startDist;

  cin >> r >> s >> t;
  cin >> n;

  startDist = s + t;

  for (int i = 0; i < n; i++) {
    int dist;

    cin >> dist;

    if (dist < r) {
      cout << "no" << endl;
    } else {
      int check = (dist - r) % startDist;

      if (check <= s) {
        cout << "yes" << endl;
      } else {
        cout << "no" << endl;
      }
    }
  }

  return 0;
}
