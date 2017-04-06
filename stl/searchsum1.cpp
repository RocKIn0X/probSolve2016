#include <map>
#include <iostream>
#include <cstdio>

using namespace std;

int main() {
  int n, k, cost, prevCost, maxCost, money;
  map<int, int> m;
  map<int, int>::iterator iter = m.begin();

  scanf("%d %d", &n, &k);

  for (int i = 1; i <= n; i++) {
    scanf("%d", &cost);

    if (i == 1) {
      m[cost] = i;
      m[cost-1] = 0;
    } else {
      cost += prevCost;
      m[cost] = i;
      m[cost-1] = i - 1;
    }
    prevCost = cost;
  }

  maxCost = cost;

  for (int i = 0; i < k; i++) {
    scanf("%d", &money);

    iter = m.lower_bound(money);

    if (money < maxCost) {
      printf("%d\n", iter->second);
    } else {
      printf("%d\n", n);
    }

  }

  return 0;
}
