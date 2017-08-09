#include <cstdio>
#define MAX 505

using namespace std;

int main () {
    int width, height, n, lx, ly, rx, ry, minx, miny, maxx, maxy, count;
    int field[MAX][MAX];

    while (true) {
        count = 0;

        scanf(" %d %d %d", &width, &height, &n);

        if (width == 0 && height == 0 && n == 0) {
            break;
        }

        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                field[i][j] = 0;
            }
        }

        for (int i = 0; i < n; i++) {
            scanf(" %d %d %d %d", &lx, &ly, &rx, &ry); lx--; ly--; rx--; ry--;

            if (lx > rx) {
                minx = rx;
                maxx = lx;
            } else {
                minx = lx;
                maxx = rx;
            }

            if (ly > ry) {
                miny = ry;
                maxy = ly;
            } else {
                miny = ly;
                maxy = ry;
            }

            for (int i = minx; i <= maxx; i++) {
                for (int j = miny; j <= maxy; j++) {
                    field[i][j]++;
                }
            }
        }

        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                if (field[i][j] == 0) {
                    count++;
                }
            }
        }

        if (count == 0) {
            printf("There is no empty spots.\n");
        } else if (count == 1) {
            printf("There is one empty spot.\n");
        } else {
            printf("There are %d empty spots.\n", count);
        }

    }

    return 0;
}