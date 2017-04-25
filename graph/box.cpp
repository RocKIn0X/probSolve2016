#include <cstdio>
#include <string.h>
#include <iostream>
#include <vector>
#include <queue>
#define MAX_N 35
#define MAX_M 35

using namespace std;

char map[MAX_N][MAX_M];
bool visited[MAX_N][MAX_M];
int n, m;

void init() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      visited[i][j] = false;
    }
  }
}

void walk(int row, int col, char* check) {
  if (map[row][col] != '.' or map[row][col+1] != '.' or map[row+1][col] != '.' or map[row+1][col+1] != '.') {
    return;
  }

  if (*check == 't') {
    return;
  }

  visited[row][col] = true;

  if (row == n-2) {
    *check = 't';
    return;
  }

  if (visited[row+1][col] != true) walk(row+1, col, check);
  if (visited[row][col+1] != true) walk(row, col+1, check);
  if (visited[row-1][col] != true) walk(row-1, col, check);
  if (visited[row][col-1] != true) walk(row, col-1, check);
}

int main () {
  char check = 'f';
  scanf("%d %d", &n, &m);
  init();

  for (int i = 0; i < n; i++) {
    scanf("%s", map[i]);
  }

  for (int i = 0; i < m-1; i++) {
    if (map[0][i] == '.' and map[0][i+1] == '.') {
      walk(0, i, &check);
    }
  }

  if (check == 't') {
    printf("yes\n");
  } else if (check == 'f') {
    printf("no\n");
  }

  return 0;
}
