#include <iostream>
#include <queue>
#include <functional>

using namespace std;

priority_queue<int,vector<int>, greater<int>> myqueue;

int main () {
    int x, y;
    char c = 'C';

    cin >> x;

    while (true) {
        cin >> y;

        if (y == 0) {
            break;
        }

        myqueue.push(y);
    }

    for (int i = 2559; i < x; i++) {
        if (!myqueue.empty() && myqueue.top() == i) {
            myqueue.pop();
            continue;
        }

        if (c == 'C') {
            c = 'K';
        } else if (c == 'K') {
            c = 'C';
        }
    }

    printf ("%c\n", c);

    return 0;
}