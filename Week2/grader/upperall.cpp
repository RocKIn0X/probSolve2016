#include <iostream>

using namespace std;

void upper (char c) {
  int diff = 'a' - 'A';
  char upperChar;

  if (c >= 'a' && c <= 'z') {
    upperChar = (char) (c - diff);
    cout << upperChar;
  } else {
    cout << c;
  }


}

main() {
  char str[100];
  int i = 0;

  cin >> str;

  while (str[i] != '\0') {
    upper(str[i]);
    i++;
  }

  cout << endl;
}
