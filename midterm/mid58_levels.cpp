#include <map>
#include <cstdio>
#define MAX_N 3

using namespace std;

typedef pair<int,int> type;
map<type, int> mission;
bool pass[MAX_N];

void reset() {
  for (int i = 0; i < MAX_N; i++) {
    pass[i] = false;
  }
}

bool allTypePass() {
  for (int i = 0; i < MAX_N; i++) {
    if (pass[i] != true) {
      return false;
    }
  }

  return true;
}

int main () {
  int n, m, a, b, c, lv;

  lv = 1;
  scanf("%d %d", &n, &m);

  for (int i = 1; i <= n-1; i++) {
    scanf("%d %d %d", &a, &b, &c);

    type m1 = type(i, 1);
    type m2 = type(i, 2);
    type m3 = type(i, 3);

    mission[m1] = a;
    mission[m2] = b;
    mission[m3] = c;
  }

  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", &a, &b, &c);

    type m1 = type(lv, 1);
    type m2 = type(lv, 2);
    type m3 = type(lv, 3);

    if (mission[m1] <= a) {
      pass[0] = true;
    }

    if (mission[m2] <= b) {
      pass[1] = true;
    }

    if (mission[m3] <= c) {
      pass[2] = true;
    }

    if (allTypePass()) {
      if (lv < MAX_N) {
        lv++;
        reset();
      }
    }
  }

  printf("%d\n", lv);

  return 0;
}
