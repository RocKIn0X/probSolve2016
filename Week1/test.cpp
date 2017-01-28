#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int getScore(int r) {

  switch (r) {
    case r <= 2 :
      cout << 5;
      return 5;
    default :
      cout << 0;
      return 0;
  }
}

int main () {
  int n, score;
  score = 0;
  //string scoreStr;

  cin >> n;

  for (int i = 0; i < n; i++) {
    score += getScore(i);
    cout << getScore(i) << endl;
  }
  //scoreStr = to_string(score);

  cout << score << endl;

  return 0;
}
