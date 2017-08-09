#include <cstdio>
#include <climits>
#include <iostream>
#define MAX 20

using namespace std;

int n, m, minNum;
int arr[MAX][MAX];
float minValue = INT_MAX;

void find_min (int r, int c, int value) {
    float sum = 0;
    float count = 0;

    for (int i = 0; i < n; i++) {
        if (i == r) {
            continue;
        }

        sum += abs(value - arr[i][c]); 
        count++;
    }

    for (int i = 0; i < m; i++) {
        if (i == c) {
            continue;
        }

        sum += abs(value - arr[r][i]); 
        count++;
    }

    sum /= count;

    if (sum < minValue) {
        minValue = sum;
        minNum = arr[r][c];
    }
}

int main () {

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            find_min (i, j, arr[i][j]);       
        }
    }

    printf("%d\n", minNum);

    return 0;
}