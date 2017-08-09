#include <cstdio>
#include <map>

using namespace std;

map<int, int> numCD;
int n, m;

int main () {
    int jack, jill;
    int count;

    while (true) {
        count = 0;

        scanf("%d %d", &n, &m);

        if (n == 0 && m == 0) {
            break;
        }

        for (int i = 0; i < n; i++) {
            scanf("%d", &jack);

            numCD[jack]++;
        }

        for (int i = 0; i < m; i++) {
            scanf("%d", &jill);

            if (numCD[jill] != 0) {
                count++;
            }
        }

        printf("%d\n", count);
        numCD.clear();
    }

    return 0;
}