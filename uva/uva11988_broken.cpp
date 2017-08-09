#include <cstdio>
#include <iostream>
#include <cstring>
#include <list>
#define MAX 100005

using namespace std;

char text[MAX];
list<char> ans;
list<char>::iterator it = ans.begin();

void create_list () {
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == '[') {
            it = ans.begin();
            continue;
        } else if (text[i] == ']') {
            it = ans.end();
            continue;
        } else {
            ans.insert(it, text[i]);
        }
    }
}

void print_list () {
    for (it = ans.begin(); it != ans.end(); it++) {
        printf("%c", *it);
    }

    printf("\n");
}

int main () {
    while (scanf("%s", &text) != EOF) {
        create_list();
        print_list(); 
        ans.clear();
        it = ans.begin();
    }   

    return 0;
}