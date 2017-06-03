#include <iostream>
#include <string.h>

using namespace std;

int main () {
    char letter[30];

    while (true) {        
        cin >> letter;

        if (cin.eof()) {
            break;
        }

        for (int i = 0; i < strlen(letter); i++) {
            if (letter[i] == '-' || letter[i] == '0' || letter[i] == '1') {
                cout << letter[i];
                continue;
            } 
            
            if ('A' <= letter[i] && letter[i] <= 'C') {
                cout << 2;
            } else if ('D' <= letter[i] && letter[i] <= 'F') {
                cout << 3;
            } else if ('G' <= letter[i] && letter[i] <= 'I') {
                cout << 4;
            } else if ('J' <= letter[i] && letter[i] <= 'L') {
                cout << 5;
            } else if ('M' <= letter[i] && letter[i] <= 'O') {
                cout << 6;
            } else if ('P' <= letter[i] && letter[i] <= 'S') {
                cout << 7;
            } else if ('T' <= letter[i] && letter[i] <= 'V') {
                cout << 8;
            } else if ('W' <= letter[i] && letter[i] <= 'Z') {
                cout << 9;
            }
        }

        cout << endl;
    }
    return 0;
}