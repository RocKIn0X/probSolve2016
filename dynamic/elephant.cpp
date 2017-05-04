#include <cstdio>
#define MAX 100005

using namespace std;

int max(int x, int y) {
  if (x > y) {
    return x;
  } else {
    return y;
  }
}

int main() {
  int data[MAX];
  int arr[MAX];
  int n;

  data[0] = 0;
  arr[0] = 0;
  scanf("%d", &n);

  for (int i = 1; i <= n; i++) {
    scanf("%d", &data[i]);
  }

  for (int i = 1; i <= n; i++) {
    if (i == 1 or i == 2) {
      arr[i] = 0;
    } else {
      arr[i] = max(data[i] + arr[i-3], arr[i-1]);
    }
  }

  printf("%d\n", arr[n]);

  return 0;
}
