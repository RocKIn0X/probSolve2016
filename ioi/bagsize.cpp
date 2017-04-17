#include <iostream>

using namespace std;

int main() {
  int prodNum, minSize, maxSize, maxWeight;
  int weight[1005];

  cin >> prodNum >> minSize >> maxSize;
  maxWeight = 0;

  for (int i = 0; i < prodNum; i++) {
    cin >> weight[i];
    if (weight[i] > maxWeight) {
      maxWeight = weight[i];
    }
  }

  if (maxWeight < minSize) {
    maxWeight = minSize;
  }

  //cout << "max: " << maxWeight << endl;

  int junkWeight = 0;
  int chooseWeight;

  for (int i = maxWeight; i <= maxSize; i++) {
    int sum = 0;
    int junk = i;
    for (int j = 0; j < prodNum; j++) {
      if (junk - weight[j] >= 0) {
        junk -= weight[j];
      } else {
        //cout << "junk" << i << ": " << junk << endl;
        sum += junk;
        junk = i - weight[j];
      }
    }

    sum += junk;

    if (i == maxWeight) {
      junkWeight = sum;
      chooseWeight = i;
    }

    if (junkWeight > sum) {
      junkWeight = sum;
      chooseWeight = i;
    }
  }

  cout << chooseWeight << endl;

  return 0;
}
