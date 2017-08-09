#include <cstdio>
#include <cmath>

using namespace std;

bool isPrime (int n) {
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

void goldbach (int n) {
    int count = 0;

    for (int i = 2; i <= n/2; i++) {
        if (isPrime (i) && isPrime (n-i)) {
            count++;
        }
    }

    printf("%d\n", count);
}

int main () {
    int n;

    while (true) {
        scanf ("%d", &n);

        if (n == 0) break;

        goldbach (n);
    }

    return 0;
}