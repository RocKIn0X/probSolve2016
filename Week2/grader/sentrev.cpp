#include <iostream>

using namespace std;

void printWord(char* ptr) {
  while (*ptr != '\0' and *ptr != '_') {
    cout << *ptr;
    ptr++;
  }
}

void reverse(char str[], char* ptr) {
  while (ptr != str - 1) {

    if (*ptr == '_') {
      printWord(ptr + 1);
      cout << '_';
    }

    if (ptr == str) {
      printWord(ptr);
    }

    ptr--;
  }

  cout << endl;
}

int main () {
  int i = 0;
  char str[1010];
  char* ptr = '\0';

  cin.getline(str, 1010);

  while (str[i] != '\0') {
    i++;
  }

  i--;
  ptr = &str[i];
  reverse(str, ptr);

  return 0;
}
