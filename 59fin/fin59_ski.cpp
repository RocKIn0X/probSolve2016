#include <cstdio>

using namespace std;

struct Block {
  int hi;
  int si;

  Block(int hi, int si)
    : hi(hi), si(si) {}
};

int N, K;
int score[1005];
Block* block[1005];

int main() {
  scanf("%d %d", &N, &K);

  for (int i = 0; i < N; i++) {
    int hi, si;
    scanf("%d %d", &hi, &si);

    block[i] = new Block(hi, si);
    score[i] = si;
  }

  for (int i = 1; i < N; i++) {
    int temp = block[i]->hi;
    for (int j = i-1; j >= 0; j--) {
      if (temp+4 >= block[j]->hi && temp <= block[j]->hi) {
        //printf("%d -> %d\n", temp, block[j]->hi);
        temp = block[j]->hi;
        score[i] += block[j]->si;
      }
    }
  }

  int max = 0;

  for (int i = 0; i < N; i++) {
    if (score[i] > max) {
      max = score[i];
    }
  }

  printf("%d\n", max);

  return 0;
}
