#include <cstdio>
#include <stack>
#define MAX 1005

using namespace std;

int data[MAX];
int arr[MAX];
int n, count, maxInc, checkPoint;
stack<int> incStack;


void inc() {
  maxInc = 1;

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (data[i] > data[j] && arr[j] + 1 > arr[i]) {
        arr[i] = arr[j] + 1;

        if (arr[i] > maxInc) {
          maxInc = arr[i];
          checkPoint = i;
        }
      }
    }
  }
}

void inStack() {
  int check;

  incStack.push(data[checkPoint]);
  check = checkPoint;
  checkPoint--;
  maxInc--;

  while(maxInc != 0) {
    if (arr[checkPoint] + 1 == arr[check]) {
      incStack.push(data[checkPoint]);
      check = checkPoint;
      maxInc--;
      checkPoint--;
    } else {
      checkPoint--;
    }
  }

}

void printInc() {
  inStack();

  while(!incStack.empty()) {
    printf("%d ", incStack.top());
    incStack.pop();
  }
  printf("\n");
}

int main() {
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%d", &data[i]);
    arr[i] = 1;
  }

  inc();

  printf("%d\n", maxInc);
  printInc();

  return 0;
}
