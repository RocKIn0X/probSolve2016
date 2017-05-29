#include <cstdio>
#include <map>
#include <climits>
#include <cmath>
#define MAX 100005

using namespace std;

struct Info {
  int price;
  int bread;

  Info(int price, int bread)
    : price(price), bread(bread) {}
};

int n, q;
map<int,Info*> m;
map<int,Info*>::iterator iter;

void update(int adrSellerMin) {
  m[adrSellerMin]->bread -= 1;
}

void calMinPrice(int adrBuyer) {
  iter = m.upper_bound(adrBuyer);

  while (true) {
    if (abs(iter->first - adrBuyer) > 5) {
      break;
    } else {
      iter++;
    }
  }
}

int main() {
  scanf("%d %d", &n, &q);

  m[0] = new Info(100, 100);

  for (int i = 0; i < n; i++) {
    int adr, c, l;
    scanf(" %d %d %d", &adr, &c, &l);

    m[adr] = new Info(c, l);

    if (i == n-1) {
      m[adr+100] = new Info(100, 100);
    }
  }

  for (int i = 0; i < q; i++) {
    int adrBuyer;

    scanf("%d\n", &adrBuyer);

    calMinPrice(adrBuyer);
  }

  return 0;
}
