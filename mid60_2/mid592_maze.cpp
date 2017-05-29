#include <cstdio>
#include <string.h>
#include <iostream>
#include <vector>
#include <queue>
#define MAX_N 25

using namespace std;

char map[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int n, m;

void init() {
  for (int i = 0; i < n+2; i++) {
    for (int j = 0; j < n+2; j++) {
      visited[i][j] = false;
    }
  }
}

void walk(int row, int col, int a, int b, int key, char* check) {
  if (row < 0 || col < 0 || row >= n || col >= n || *check == 't' || (map[row][col] == 'O' && key == 0)) {
    return;
  }

  if (map[row][col] == '#') {
    visited[row][col] = true;
    return;
  }

  if (map[row][col] == 'O') {
    key -= 1;
  }

  visited[row][col] = true;

  if (row == a && col == b) {
    *check = 't';
    return;
  }

  if (visited[row+1][col] != true)
    walk(row+1, col, a, b, key, check);
  if (visited[row][col+1] != true)
    walk(row, col+1, a, b, key, check);
  if (visited[row-1][col] != true)
    walk(row-1, col, a, b, key, check);
  if (visited[row][col-1] != true)
    walk(row, col-1, a, b, key, check);
}

int main () {
  char check = 'f';
  scanf("%d %d", &n, &m);
  init();

  for (int i = 0; i < n; i++) {
    scanf("%s", map[i]);
  }

  for (int i = 0; i < m; i++) {
    int r, c, a, b;
    int key = 1;
    check = 'f';

    scanf(" %d %d %d %d", &r, &c, &a, &b);

    init();

    walk(r-1, c-1, a-1, b-1, key, &check);

    if (check == 't') {
      printf("yes\n");
    } else if (check == 'f') {
      printf("no\n");
    }
  }


  return 0;
}
