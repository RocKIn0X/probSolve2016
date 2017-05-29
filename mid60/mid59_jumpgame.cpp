#include <cstdio>
#include <iostream>
#define MAX_N 21

using namespace std;

int n, power;
int tbl[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

void init() {
  for (int i = 0; i < n+2; i++) {
    for (int j = 0; j < n+2; j++) {
      visited[i][j] = false;
    }
  }
}

void read_input() {
  for (int i = 0; i < n+2; i++) {
    for (int j = 0; j < n+2; j++) {
      if (i == 0 || i == n+1 || j == 0 || j == n+1) {
        tbl[i][j] = -1;
      } else {
        cin >> tbl[i][j];
      }
    }
  }
}

void canJump(int row, int col, char* check) {
  if (tbl[row][col] == -1 || visited[row][col] == true || *check == 't') {
    return;
  }

  visited[row][col] = true;

  if (row == n && col == n) {
    *check = 't';
    return;
  }

  if (tbl[row+1][col] - tbl[row][col] <= power) canJump(row+1, col, check);
  if (tbl[row][col+1] - tbl[row][col] <= power) canJump(row, col+1, check);
  if (tbl[row-1][col] - tbl[row][col] <= power) canJump(row-1, col, check);
  if (tbl[row][col-1] - tbl[row][col] <= power) canJump(row, col-1, check);
}

int main() {
  char check = 'f';

  scanf("%d %d", &n, &power);

  init();
  read_input();
  canJump(1,1,&check);

  if (check == 't') {
    printf("yes\n");
  } else {
    printf("no\n");
  }

  return 0;
}
