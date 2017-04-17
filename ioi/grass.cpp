#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  char map[105][105];
  char command;
  int n, m, pos;

  scanf("%d %d", &n, &m);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> map[i][j];
    }
  }

  for (int i = 0; i < m; i++) {
    cin >> command >> pos;
    pos--;

    if (command == 'L') {
      for (int j = 0; j < n; j++) {
        if (map[pos][j] == 'x') {
          map[pos][j] = '.';
        } else if (map[pos][j] == '.' or map[pos][j] == '#') {
          break;
        }
      }
    } else if (command == 'R') {
      for (int j = n - 1; j >= 0; j--) {
        if (map[pos][j] == 'x') {
          map[pos][j] = '.';
        } else if (map[pos][j] == '.' or map[pos][j] == '#') {
          break;
        }
      }
    } else if (command == 'U') {
      for (int j = 0; j < n; j++) {
        if (map[j][pos] == 'x') {
          map[j][pos] = '.';
        } else if (map[j][pos] == '.' or map[j][pos] == '#') {
          break;
        }
      }
    } else if (command == 'D') {
      for (int j = n - 1; j >= 0; j--) {
        if (map[j][pos] == 'x') {
          map[j][pos] = '.';
        } else if (map[j][pos] == '.' or map[j][pos] == '#') {
          break;
        }
      }
    } else if (command == 'A') {
      for (int j = 0; j < n; j++) {
        if (map[pos][j] == '.') {
          map[pos][j] = 'x';
        } else if (map[pos][j] == '#') {
          continue;
        }
      }
    } else if (command == 'B') {
      for (int j = 0; j < n; j++) {
        if (map[j][pos] == '.') {
          map[j][pos] = 'x';
        } else if (map[j][pos] == '#') {
          continue;
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%c", map[i][j]);
    }
    printf("\n");
  }
}
