#include <iostream>
#include <string.h>

using namespace std;

void calTotalOpposite (int vertical[], int horizontal[], int *totalDist, int *oppositeDist) {
  if (vertical[0] > vertical[1]) {
    totalDist += vertical[0];
    oppositeDist += vertical[1];
  } else {
    totalDist += vertical[1];
    oppositeDist += vertical[0];
  }

  if (horizontal[0] > horizontal[1]) {
    totalDist += horizontal[0];
    oppositeDist += horizontal[1];
  } else {
    totalDist += horizontal[1];
    oppositeDist += horizontal[0];
  }
}

int main () {
  char dir[100];
  int vertical[2], horizontal[2]; //vertical[] is amount of [0] - N and [1] - S, horizontal[] is amount of [0] - E and [1] - W.
  int miss, *oppositeDist, *totalDist, maxDist, minEnergy;

  vertical[0] = vertical[1] = horizontal[0] = horizontal[1] = 0;
  miss = *totalDist = *oppositeDist = maxDist = minEnergy = 0;

  cin >> dir >> miss;

  if (strlen(dir) == miss) {
    cout << 0 << endl;
    return 0;
  }

  for (int i = 0; i < strlen(dir); i++) {
    switch (dir[i]) {
      case 'N':
        vertical[0]++;
        break;
      case 'S':
        vertical[1]++;
        break;
      case 'E':
        horizontal[0]++;
        break;
      case 'W':
        horizontal[1]++;
        break;
      default:
        break;
    }
  }

  calTotalOpposite(vertical, horizontal, totalDist, oppositeDist);

  maxDist = totalDist - (oppositeDist - miss);
  minEnergy = maxDist * 2;

  cout << minEnergy << endl;

  return 0;
}
