#include <iostream>
#include <set>
#include <map>

using namespace std;

set<int> iset;
map<int, int> imap;

int main () {
    int n, course, count;

    while (true) {
        cin >> n;
        count = 0;

        if (n == 0) {
            break;
        }

        for (int i = 0; i < n*5; i++) {
            cin >> course;

            imap[course]++;
            iset.insert (course);
        }

        for (set<int>::iterator it = iset.begin(); it != iset.end(); ++it) {
            if (imap[*it] == n) {
                count++;
            }
        }

        printf ("%d\n", count);
        imap.clear();
        iset.clear();
    }

    return 0;
}