#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

stack<string> strStack;

int main () {
    char text[100005];
    char tmp_c[100005];
    string tmp;
    int index = 0;

    cin >> text;

    for (int i = 0; i < strlen(text); i++) {
        if (text[i] != '_') {
            tmp_c[index] = text[i];
            index++;
        } else {
            tmp(tmp_c);
            strStack.push(tmp);
        }
    }

    while (!strStack.empty()) {
        string temp = strStack.top();
        strStacl.pop();

        printf("%s\n", temp);
    }

    return 0;
}