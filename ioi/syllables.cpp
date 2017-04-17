#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  int n, state, count;
  char* ptr;

  cin >> n;
  state = 1; //state 1 not found aeiou, state 2 found
  count = 0;

  for (int i = 0; i < n; i++) {
    char str[35];
    ptr = str;

    cin >> str;

    while (*ptr != '\0') {
      if (state == 1) {
        if (*ptr == 'a' or *ptr == 'e' or *ptr == 'i' or *ptr == 'o' or *ptr == 'u') {
            state = 2;
            count++;
        }
      } else if (state == 2) {
        if (*ptr == 'a' or *ptr == 'e' or *ptr == 'i' or *ptr == 'o' or *ptr == 'u') {
            state = 2;
        } else {
          state = 1;
        }
      }
      ptr++;
    }

    cout << count << endl;
    count = 0;
  }

  return 0;
}
