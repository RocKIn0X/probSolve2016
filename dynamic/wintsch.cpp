#include <cstdio>
#include <vector>
#define MAX 1005

using namespace std;

struct Work {
  int start;
  int finish;
  int value;

  Work (int start, int finish, int value)
    : start(start), finish(finish), value(value) {}
};

int n, len;
int maxVal[MAX];
Work* work[MAX];
vector<int> listWork[MAX];

bool isOverlap(int i, int j) {
  if (work[i]->start < work[j]->finish) {
    return true;
  }

  return false;
}

int main() {
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    int s, f, v;
    scanf(" %d %d %d", &s, &f, &v);

    work[i] = new Work(s, f, v);
    maxVal[i] = v;
    listWork[i].push_back(i);
  }

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (isOverlap(i, j)) {
        if (maxVal[j] > maxVal[i]) {
          maxVal[i] = maxVal[j];
          listWork[i] = listWork[j];
        }
      } else {
        if (work[i]->value + maxVal[j] > maxVal[i]) {
          maxVal[i] = work[i]->value + maxVal[j];
          listWork[i] = listWork[j];
          listWork[i].push_back(i);
        }
      }
    }
  }

  int max = 0;
  int maxIndex;

  for (int i = 0; i < n; i++) {
    if (maxVal[i] > max) {
      max = maxVal[i];
      maxIndex = i;
    }
  }

  printf("%d\n", max);
  printf("%d\n", (int)listWork[maxIndex].size());

  for (int i = 0; i < listWork[maxIndex].size(); i++) {
    printf("%d ", listWork[maxIndex][i] + 1);
  }

  printf("\n");
  return 0;
}
