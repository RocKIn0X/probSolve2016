#include <iostream>

using namespace std;

int main () {
  int mission, vdo, no, vdoTime, sumTime;
  int minTime[102];

  sumTime = 0;
  cin >> mission >> vdo;

  for (int i = 0; i < vdo; i++) {
    minTime[i] = 0;
  }

  for (int i = 0; i < vdo; i++) {
    cin >> no >> vdoTime;
    no--;

    if (minTime[no] == 0) {
      minTime[no] = vdoTime;
      sumTime += vdoTime;
    } else {
      if (vdoTime < minTime[no]) {
        sumTime -= minTime[no];
        sumTime += vdoTime;
        minTime[no] = vdoTime;
      }
    }
  }

  cout << sumTime << endl;

  for (int i = 0; i < mission; i++) {
    cout << i + 1 << " " << minTime[i] << endl;
  }

  return 0;
}
