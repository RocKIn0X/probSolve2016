#include <iostream>

using namespace std;

void rev(char* ptr) {
  while (*ptr != '_' and *ptr != '\0') {
    cout << *ptr;
    ptr--;
  }
}

main () {
  char str[1005];
  char* ptr = '\0';

  cin >> str;

  ptr = str;

  while (*ptr != '\0') {
    if (*ptr == '_') {
      rev(ptr - 1);
      cout << '_';
    } else if (*(ptr + 1) == '\0') {
      rev(ptr);
    }

    ptr++;
  }

  cout << endl;
}
