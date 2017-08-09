#include <iostream>
#include <map>
#include <queue>

using namespace std;

map<int, int> num;
queue<int> order;

int main () {
    int n;

    while (true) {
        cin >> n;

        if (cin.eof()) {
            break;
        }

        if (num[n] == 0) {
            order.push(n);
        }

        num[n]++;
    }

    while (!order.empty()) {
        int tmp = order.front();
        order.pop();
        printf("%d %d\n", tmp, num[tmp]);
    }

    return 0;
}