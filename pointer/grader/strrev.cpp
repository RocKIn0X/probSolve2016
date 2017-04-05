#include <iostream>

using namespace std;

void reverse(int i, char* ptr) {
  while (i >= 0) {
    cout << *(ptr--);
    i--;
  }

  cout << endl;
}

int main () {
  char str[1005];
  char* ptr;
  int i = 0;

  cin.getline(str, 1005);

  while (str[i] != '\0') {
    i++;
  }

  i--;
  ptr = &str[i];
  reverse(i, ptr);

  return 0;
}
