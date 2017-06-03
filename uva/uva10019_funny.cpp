#include <cstdio>

using namespace std;

int x1[32];
char hex_x2[32];

void init() {
    for (int i = 0; i < 32; i++) {
        x1[i] = 0;
    }
}

void toBinary (int x) {
  int index = 31;
  int count = 0;

  while (x != 0) {
    int tmp = x % 2;
    x /= 2;

    x1[index] = tmp;

    index--;
  }

  for (int i = 0; i < 32; i++) {
    if (x1[i] == 1) {
      count++;
    }
  }

  printf("%d ", count);
}

void toHex (int x) {
  int count = 0;

  while (x != 0) {
    int tmp = x % 10;
    char hex;
    if (tmp > 9) {
      hex = (char) tmp - 10 + 'A';
    } else {
      hex = (char) tmp + 48;
    }
    x /= 10;

    if (hex == '1' || hex == '2' || hex == '4' || hex == '8') {
      count += 1;
    } else if (hex == '3' || hex == '5' || hex == '6' || hex == '9' || hex == 'A' || hex == 'C') {
      count += 2;
    } else if (hex == '7' || hex == 'B' || hex == 'D' || hex == 'E') {
      count += 3;
    } else if (hex == 'F') {
      count += 4;
    }
  }

  printf("%d\n", count);
}

int main () {
  int n;

  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    init();

    int x, a, b;
    scanf("%d", &x);

    toBinary(x);
    toHex(x);
  }

  return 0;
}
