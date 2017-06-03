#include <iostream>
#include <math.h>

using namespace std;

void niceOrNot (char lic[]) {
    int label = 0;
    int dec = 0;
    int exLbl = 2;
    int exDec = 3;

    for (int i = 0; i < 3; i++) {
        label += ((int)(lic[i] - 'A')) * pow(26, exLbl);
        exLbl--;
    }

    for (int i = 4; i < 8; i++) {
        dec += (int) ((lic[i] - 48)) * pow(10, exDec);
        exDec--;
    }

    if (abs(label - dec) <= 100) {
        printf("nice\n");
    } else {
        printf("not nice\n");
    }
}

int main () {
    int n;
    char lic[8];

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> lic;
        niceOrNot(lic);
    }
    
    return 0;
}