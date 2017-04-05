#include <iostream>
#include <string.h>

using namespace std;

void turn(int curr, int prev) {
  int r = curr - prev;

  if (r < 0) {
    r += 4;
  }

  for (int i = 0; i < r; i++) {
    cout << 'R';
  }
}

int main () {
  enum State {N, E, S, W, Z};
  char dir[100];

  State currentDir = N;
  State previousDir = currentDir;

  cin >> dir;

  for (int i = 0; i < strlen(dir); i++) {
    switch (dir[i]) {
      case 'N':
        currentDir = N;
        break;
      case 'E':
        currentDir = E;
        break;
      case 'S':
        currentDir = S;
        break;
      case 'W':
        currentDir = W;
        break;
      case 'Z':
        currentDir = Z;
        break;
    }

    if (currentDir != Z) {
      turn(currentDir, previousDir);
      cout << 'F';
      previousDir = currentDir;
    } else {
      cout << 'Z';
      currentDir = N;
      previousDir = currentDir;
    }

  }

  cout << endl;

  return 0;
}
