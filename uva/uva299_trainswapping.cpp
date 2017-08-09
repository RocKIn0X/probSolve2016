#include <cstdio>
#include <iostream>

using namespace std;

int arr[55];
int count = 0;

void swap (int train) {
    for (int i = 0; i < train; i++) {
        for (int j = 1; j < train; j++) {
            if (arr[j] < arr[j-1]) {
                int tmp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = tmp;
                count++;
            }
        }
    }
}

int main () {
    int n, train;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        count = 0;

        scanf("%d", &train);

        for (int i = 0; i < train; i++) {
            cin >> arr[i];
        }

        swap (train);

        printf("Optimal train swapping takes %d swaps.\n", count);
    }


}