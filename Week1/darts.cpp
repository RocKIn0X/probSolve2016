#include <iostream>
#include <math.h>

using namespace std;

float getScore(float r) {
   if (r <= 2) {
     return 5;
   } else if (r <= 4) {
     return 4;
   } else if (r <= 6) {
     return 3;
   } else if (r <= 8) {
     return 2;
   } else if (r <= 10) {
     return 1;
   }

   return 0;
}

int main() {
  int n, x, y, score;
  float r;
  score = 0;

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    r = (float) sqrt((x * x) + (y * y));
    score += getScore(r);
  }

  cout << score << endl;

  return 0;
}
