#include <cstdio>

using namespace std;

bool check[3655];

void init () {
    for (int i = 0; i < 3655; i++) {
        check[i] = false;
    }
}

int main () {
    int n, days, party, hartal, count;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &days);
        scanf("%d", &party);

        count = 0;
        init();

        for (int j = 0; j < party; j++) {
            int tmp = 0;
            scanf("%d", &hartal);

            tmp = hartal;
            while (tmp <= days) {
                if (tmp % 7 != 0 && tmp % 7 != 6) {
                    if (check[tmp] == false) {
                        count++;
                        check[tmp] = true;
                    }
                }

                tmp += hartal;
            }
        }

        printf("%d\n", count);
    }


    return 0;
}