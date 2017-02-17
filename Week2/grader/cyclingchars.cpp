#include <iostream>

using namespace std;

void cycling(char ch) {
  char newChar;

  if (ch >= 'a') {
    newChar = (char) (ch + 4);
    if (newChar > 'z') {
      newChar = (char) (newChar - 'z' + 'a' - 1);
    }
  }
  cout << newChar;
}

void newStr(char str[]) {
  int i = 0;
  char ch;

  while (str[i] != '\0') {
    cycling(str[i]);
    i++;
  }

  cout << endl;
}

main () {
  char str[100];

  cin >> str;

  newStr(str);
}
