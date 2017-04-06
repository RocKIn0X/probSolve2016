#include <map>
#include <cstdio>

using namespace std;

int main() {
  int n, statusNo, mostLikeStatus, maxLike;
  map<int, int> mapStatus;

  maxLike = 0;

  scanf("%d", &n);

  for (int  i = 0; i < n; i++) {
    scanf("%d", &statusNo);

    mapStatus[statusNo] += 1;

    if (mapStatus[statusNo] >= maxLike) {
      mostLikeStatus = statusNo;
      maxLike = mapStatus[statusNo];
    }

    printf("%d\n", mostLikeStatus);
  }
}
