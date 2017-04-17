#include <cstdio>
#include <map>
#include <iostream>
#include <string.h>
#define MAX_TEAM 4

using namespace std;

map<int,string> scoreMap;

void swap (int*& a, int*& b) {
  int* temp = a;
  a = b;
  b = temp;
}

void swap (string*& a, string*& b) {
  string* temp = a;
  a = b;
  b = temp;
}

int main() {
  int scoreTbl[MAX_TEAM][MAX_TEAM];
  int score[MAX_TEAM];
  int goal[MAX_TEAM];
  int maxGoal[MAX_TEAM];
  string national[MAX_TEAM];

  for (int i = 0; i < MAX_TEAM; i++) {
    cin >> national[i];
  }

  for (int i = 0; i < MAX_TEAM; i++) {
    for (int j = 0; j < MAX_TEAM; j++) {
      cin >> scoreTbl[i][j];
    }
  }

  for (int i = 0; i < MAX_TEAM; i++) {
    score[i] = 0;
    goal[i] = 0;
    maxGoal[i] = 0;
    for (int j = 0; j < MAX_TEAM; j++) {
      maxGoal[i] += scoreTbl[i][j];
      if (i != j) {
        if (scoreTbl[i][j] > scoreTbl[j][i]) {
          score[i] += 3;
          goal[i] += scoreTbl[i][j] - scoreTbl[j][i];
        } else if (scoreTbl[i][j] == scoreTbl[j][i]) {
          score[i] += 1;
        } else {
          goal[i] += scoreTbl[i][j] - scoreTbl[j][i];
        }
      }
    }
  }

  for (int i = 0; i < MAX_TEAM; i++) {
    for (int j = 1; j < MAX_TEAM; j++) {
      if (score[j - 1] < score[j]) {
        swap(score[j-1], score[j]);
        swap(goal[j-1], goal[j]);
        swap(national[j-1], national[j]);
        swap(maxGoal[j-1], maxGoal[j]);
      } else if (score[j - 1] == score[j]) {
        if (goal[j - 1] < goal[j]) {
          swap(score[j-1], score[j]);
          swap(goal[j-1], goal[j]);
          swap(national[j-1], national[j]);
          swap(maxGoal[j-1], maxGoal[j]);
        } else if (goal[j - 1] == goal[j]) {
          if (maxGoal[j-1] < maxGoal[j]) {
            swap(score[j-1], score[j]);
            swap(goal[j-1], goal[j]);
            swap(national[j-1], national[j]);
            swap(maxGoal[j-1], maxGoal[j]);
          }
        }
      }
    }
  }

  for (int i = 0; i < MAX_TEAM; i++) {
    cout << national[i] << " " << score[i] << endl;
  }

  return 0;
}
