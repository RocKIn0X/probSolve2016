#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;
#define group 4

map<int, int> people;
vector<int> win;
map<int, int> mapWin;

int main() {
  int n, k, no, max, ability, numOfPeople;
  int first, second, winA, winB, loseA, loseB;

  scanf("%d", &n);
  k = 0;
  max = 0;
  numOfPeople = group * n;

  for (int i = 0; i < numOfPeople; i++) {
    scanf("%d", &ability);

    people[i] = ability;
  }

  for (int i = 0; i < group; i++) {
    for (int j = 0; j < n; j++) {
      if (people[k] > max) {
        max = people[k];
        no = k;
      }
      k++;
    }
    mapWin[max] = no;
    win.push_back(max);
    max = 0;
  }

  if (win[0] > win[1]) {
    winA = win[0];
    loseA = win[1];
  } else {
    winA = win[1];
    loseA = win[0];
  }

  if (win[2] > win[3]) {
    winB = win[2];
    loseB = win[3];
  } else {
    winB = win[3];
    loseB = win[2];
  }

  if (winA > winB) {
    first = winA;
    second = winB;
  } else {
    first = winB;
    second = winA;
  }

  printf("%d %d %d %d\n", mapWin[first] + 1, mapWin[second] + 1, mapWin[loseA] + 1, mapWin[loseB] + 1);
}
