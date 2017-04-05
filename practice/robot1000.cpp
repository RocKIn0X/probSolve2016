#include <iostream>
#include <string.h>

using namespace std;

int main () {
  char dir[100];
  int x, y;

  x = 0;
  y = 0;

  cin >> dir;

  for (int i = 0; i < strlen(dir); i++) {
    switch (dir[i]) {
      case 'N':
        y += 1;
        break;
      case 'S':
        y -= 1;
        break;
      case 'E':
        x += 1;
        break;
      case 'W':
        x -= 1;
        break;
      case 'Z':
        x = 0;
        y = 0;
        break;
    }
  }

  cout << x << ' ' << y << endl;

  return 0;
}
