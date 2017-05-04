#include <cstdio>
#define MAX 1005

using namespace std;

bool incMax(int x, int y, int* check) {
  if (x > y) {
    *check = 1;

    return true;
  } else {
    return false;
  }
}

int main() {
  int data[MAX];
  int arr[MAX];
  int n;
  int count = 0;
  int check = 0;

  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%d", &data[i]);
  }

  for (int i = 0; i < n; i++) {
    if (i == 0) {
      arr[i] = data[i];
      count++;
    } else {
      if (count == 1) {
        if (data[i] <= data[i-1]) {
          arr[count-1] = data[i];
        } else {
          arr[count] = data[i];
          count++;
        }
      } else {
        if (data[i] > arr[count-1]) {
          arr[count] = data[i];
          count++;
        }
      }
    }
  }

  printf("%d\n", count);

  for (int i = 0; i < count; i++) {
    if (i == 0) {
      printf("%d", arr[i]);
    } else {
      printf(" %d", arr[i]);
    }
  }

  printf("\n");

  return 0;
}
