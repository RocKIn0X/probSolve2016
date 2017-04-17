#include <vector>
#include <cstdio>
#define MAX_N 3

using namespace std;

vector<int> type[MAX_N];
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

  for (int i = 0; i < n-1; i++) {
    scanf("%d %d %d", &a, &b, &c);

    type[i].push_back(a);
    type[i].push_back(b);
    type[i].push_back(c);
  }

  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", &a, &b, &c);

    if (type[lv-1][0] <= a) {
      pass[0] = true;
    }

    if (type[lv-1][1] <= b) {
      pass[1] = true;
    }

    if (type[lv-1][2] <= c) {
      pass[2] = true;
    }

    if (allTypePass()) {
      if (lv != MAX_N) {
        lv++;
        reset();
      }
    }
  }

  printf("%d\n", lv);

  return 0;
}
