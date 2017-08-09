#include <cstdio>
#include <iostream>
#define MAX 100005

using namespace std;

int n, maxVal;
int data[MAX];
int cond[MAX];
int arr[MAX];

int find_max (int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int main () {
    arr[0] = 0;
    data[0] = 0;
    cond[0] = 0;
    maxVal = 0;

    scanf ("%d", &n);

    for (int i = 1; i <= n; i++) {
        cin >> data[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> cond[i];
    }

    for (int i = 1; i <= n; i++) {
        if (i < 4) {
            arr[i] = find_max (arr[i-1], arr[i-1] + data[i]);
        } else {
            for (int j)
        }
    }

    return 0;
}