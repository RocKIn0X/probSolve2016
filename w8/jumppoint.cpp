#include <cstdio>
#include <list>
#include <queue>
#define MAX 1005

using namespace std;

struct Point {
  int x;
  int y;
  int count;
  Point(int x, int y, int count=0)
    : x(x), y(y), count(count) {}
};

int n, power, minDist;
list<Point*> lp;
queue<Point*> qp;
bool foundDest = false;

int getLength(int x, int y, int nextX, int nextY) {
  int diffX = x - nextX;
  int diffY = y - nextY;

  return (diffX * diffX) + (diffY * diffY);
}

void jump() {
  while (!qp.empty() && !foundDest) {
    Point* point = qp.front();
    qp.pop();

    list<Point*>::iterator i = lp.begin();
    while(i != lp.end()) {
      Point* nextPoint = *i;

      int x = point->x;
      int y = point->y;
      int nextX = nextPoint->x;
      int nextY = nextPoint->y;

      if (getLength(x, y, nextX, nextY) <= power * power) {
        nextPoint->count = point->count + 1;

        if (nextX == 100 & nextY == 100) {
          foundDest = true;
          minDist = nextPoint->count;
          break;
        }
        qp.push(nextPoint);
        lp.erase(i++);
      } else {
        i++;
      }
    }
  }
}

int main() {
  scanf("%d %d", &n, &power);

  qp.push(new Point(0,0));
  minDist = -1;

  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);

    lp.push_back(new Point(x, y));
  }

  lp.push_back(new Point(100, 100));
  jump();

  printf("%d\n", minDist);

  return 0;
}
