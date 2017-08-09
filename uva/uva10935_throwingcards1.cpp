#include <cstdio>
#include <list>

using namespace std;

list<int> deck;

int main () {
    int n;

    while (true) {
        scanf("%d", &n);

        if (n == 0) {
            break;
        }

        for (int i = 1; i <= n; i++) {
            deck.push_back(i);
        }

        printf("Discarded cards:");

        for (int i = 1; i < n; i++) {
            if (i == 1) {
                printf(" %d", deck.front());
            } else {
                printf(", %d", deck.front());
            }
            deck.pop_front(); // Discard top card

            int nextCard = deck.front();
            deck.pop_front();
            deck.push_back(nextCard); // Next card go to buttom deck
        }

        printf("\nRemaining card: %d\n", deck.front());
        deck.pop_front();
    }

    return 0;
}