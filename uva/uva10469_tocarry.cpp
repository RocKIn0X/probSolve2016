#include <iostream>

using namespace std;

int binA[32];
int binB[32];
int sum[32];

void init() {
    for (int i = 0; i < 32; i++) {
        binA[i] = 0;
        binB[i] = 0;
        sum[i] = 0;
    }
}

void toBinary (int x, char c) {
    int index = 31;

    while (x != 0) {
        int tmp = x % 2;
        x /= 2;

        if (c == 'a') {
            binA[index] = tmp;
        } else if (c == 'b') {
            binB[index] = tmp;
        }

        index--;
    }
}

void sumBinary() {
    for (int i = 0; i < 32; i++) {
        if ((binA[i] == 0 && binB[i] == 1) || (binA[i] == 1 && binB[i] == 0)) {
            sum[i] = 1;
        }
    }
}

void print_ans() {
    int ans = 0;

    for (int i = 0; i < 32; i++) {
        ans = (ans << 1) + sum[i];
    }

    printf("%d\n", ans);
}

int main () {
    while (true) {
        int a, b;

        cin >> a >> b;

        if(cin.eof()) {
            break;
        }
        
        init();
        
        toBinary(a, 'a');
        toBinary(b, 'b');

        sumBinary();
        print_ans();
    }

    return 0;
}