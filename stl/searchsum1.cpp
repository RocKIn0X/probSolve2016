#include <map>
#include <iostream>
#include <cstdio>

using namespace std;

int main() {
  int n, k, cost, money;
  map<int, int> m;
  map<int, int>::iterator iter = m.begin();

  scanf("%d %d", &n, &k);;

  for (int i = 0; i < n; i++) {
    scanf("%d", &cost);
    m[i] = cost;
  }

  for (int i = 0; i < k; i++) {
    int count = 0;
    iter = m.begin();

    scanf("%d", &money);

    while (iter != m.end()) {
      money -= iter->second;

      if (money < 0) {
        break;
      }

      count++;
      iter++;
    }

    printf("%d\n", count);
  }

  return 0;
}
