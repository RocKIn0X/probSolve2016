#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>

using namespace std;

map<char, int> price;
char text[150005][10005];
int line;

void paid_char (int n) {
    char c;
    int value;

    for (int i = 0; i < n; i++) {
        scanf(" %c %d", &c, &value);

        price[c] = value;
    }
}

void read_text (int line) {
    for (int i = 0; i < line; i++) {
        fgets(text[i], sizeof text[i], stdin);
    }
}

void print_value () {
    double sumValue = 0;

    for (int i = 0; i < line; i++) {
        for (int j = 0; j < strlen(text[i]); j++) {
            if (price[text[i][j]] > 0) {
                sumValue += price[text[i][j]];
            }
        }
    }

    sumValue /= 100;

    printf("%.2f$\n", sumValue);
}

int main () {
    int test, num;

    scanf(" %d", &test);

    for (int i = 0; i < test; i++) {
        price.clear();
        scanf(" %d", &num);
        
        paid_char(num);

        scanf(" %d ", &line);
        read_text(line);
        
        print_value();
    }
}