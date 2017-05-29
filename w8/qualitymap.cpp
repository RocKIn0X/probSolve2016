#include <cstdio>
#include <string.h>
#define MAX 30

using namespace std;

int row, col, level, goodLv, normalLv;
char map[MAX][MAX];
bool visited[MAX][MAX];

void reVisited() {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      visited[i][j] = false;
    }
  }
}

void walk(int r, int c, int* n, int* level) {
  if (r < 0 || c < 0 || r > row-1 || c > col-1 || visited[r][c] == true) {
    return;
  }

  if (map[r][c] == '#') {
    visited[r][c] = true;
    return;
  }

  if (map[r][c] == '*' || map[r][c] == '$') {
    *level += 1;
  }

  *n += 1;
  visited[r][c] = true;

  if (visited[r+1][c] != true) walk(r+1, c, n, level);
  if (visited[r-1][c] != true) walk(r-1, c, n, level);
  if (visited[r][c+1] != true) walk(r, c+1, n, level);
  if (visited[r][c-1] != true) walk(r, c-1, n, level);
}

int main() {
  level = 0;
  goodLv = 0;
  normalLv = 0;

  scanf("%d %d", &row, &col);

  for (int i = 0; i < row; i++) {
    scanf("%s", map[i]);
  }

  reVisited();

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (map[i][j] == '*' || map[i][j] == '$') {
        int n = 0;
        level = 0;

        walk(i, j, &n, &level);

        if (level >= 2) {
          goodLv += n;
        } else if (level == 1) {
          normalLv += n;
        }
      }
    }
  }

  printf("%d %d\n", goodLv, normalLv);

  return 0;
}
