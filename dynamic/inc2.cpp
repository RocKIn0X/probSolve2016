#include <cstdio>
#include <stack>
#define MAX 100005

using namespace std;

int data[MAX];
int arr[MAX];
int n, count, len;
stack<int> incList;


void inc() {
  len = 0;
  arr[len] = 0;

  for (int i = 1; i < n; i++) {
    if (data[arr[len]] < data[i]) {
      len++;
      arr[len] = i;
    } else {
      for (int j = 0; j <= len; j++) {
        if (data[arr[j]] > data[i]) {
          arr[j] = i;
          break;
        }
      }
    }
  }
}

int main() {
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%d", &data[i]);
  }

  inc();

  printf("%d\n", len+1);

  return 0;
}
