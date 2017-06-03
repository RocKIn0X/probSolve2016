#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;

void print_hex (int x) {
    if (x == 0) return;

    int temp = x % 16;
    x /= 16;
    print_hex(x);

    if (temp > 9) {
        printf("%c", temp - 10 + 'A');
    } else {
        printf("%d", temp);
    }
}

void print_dec (char num[]) {
    int dec = 0;
    int length = strlen(num) - 3;
    int index = 2;

    while (length >= 0) {
        if (num[index] == 'A') {
            dec += 10 * pow (16, length);
        } else if (num[index] == 'B') {
            dec += 11 * pow (16, length);
        } else if (num[index] == 'C') {
            dec += 12 * pow (16, length);
        } else if (num[index] == 'D') {
            dec += 13 * pow (16, length);
        } else if (num[index] == 'E') {
            dec += 14 * pow (16, length);
        } else if (num[index] == 'F') {
            dec += 15 * pow (16, length);
        } else {
            dec += (int(num[index]) - 48) * pow (16, length);
        }
        index++;
        length--;
    }

    printf("%d\n", dec);
}

int main(int argc, char * argv[]) {
    while (true) {
        char num[32];
        cin >> num;
        
        if(cin.eof()) {
            break;
        }

        if (num[0] != '0' && num[1] != 'x') {
            int x;
            sscanf(num, "%d", &x);
            if (num[0] != '-') {
                printf("0x");
                print_hex(x);
                printf("\n");
            }
        } else {
            print_dec(num);
        }
    }


    return 0;
}