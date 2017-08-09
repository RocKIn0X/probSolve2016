#include <cstdio>
#include <iostream>

using namespace std;

int ladder[1005];
int n, d, dice, pos;

int main () {
    scanf ("%d %d", &n, &d);
    ladder[0] = 0;
    pos = 0;

    for (int i = 1; i <= n; i++) {
        cin >> ladder[i];
    }

    for (int i = 0; i < d; i++) {
        int temp;

        cin >> dice;

        if (pos + dice > n) {
            pos = n;
            continue;
        }

        temp = pos + dice + ladder[pos+dice];

        if (pos + temp < 0) {
            pos = 0;
        } else {
            pos = temp;
        }
    }

    printf ("%d\n", pos);

    return 0;
}