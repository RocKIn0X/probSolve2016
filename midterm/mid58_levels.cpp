#include <vector>
#include <cstdio>
#define MAX_N 3

using namespace std;

void reset(bool pass[]) {
  for (int i = 0; i < MAX_N; i++) {
    pass[i] = false;
  }
}

bool check(bool pass[]) {
  if (pass[0] == true and pass[1] == true and pass[2] == true) {
    return true;
  }

  return false;
}

int main () {
  int n, m, a, b, c, lv;
  vector<int> type[MAX_N];
  bool pass[MAX_N];

  lv = 1;
  scanf("%d %d", &n, &m);

  for (int i = 1; i < n; i++) {
    scanf("%d %d %d", &a, &b, &c);

    type[i].push_back(a);
    type[i].push_back(b);
    type[i].push_back(c);
  }

  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", &a, &b, &c);

    if (type[lv][0] <= a) {
      pass[0] = true;
    }

    if (type[lv][1] <= b) {
      pass[1] = true;
    }

    if (type[lv][2] <= c) {
      pass[2] = true;
    }

    if (check(pass)) {
      if (lv != n - 1) {
        lv++;
      }
    }

    printf("%d\n", lv);
  }

  return 0;
}
