#include <cstdio>
#include <iostream>
#include <math.h>

using namespace std;

int main () {
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);

        x = (((((x * 567) / 9 ) + 7492) * 235) / 47) - 498;
        x /= 10;
        x = x % 10;

        printf("%d\n", abs(x));
    }

    return 0;
}