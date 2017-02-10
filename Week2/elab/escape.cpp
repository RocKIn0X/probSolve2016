#include <iostream>
using namespace std;

char* write_chars(char* dest, const char* st) {
  int i = 0;

  while (i < 1000) {
    if (*st == '\0') {
      break;
    }

    *dest = *st;
    dest += 1;
    st += 1;
  }


  return dest;
}

void escape(char* src, char *dest) {
  int i = 0;

  while (i < 1000) {
    if (*src == '\0') {
      *dest = 0;
      break;
    }

    if (*src == '<') {
      dest = write_chars(dest, "&lt;");
      src += 1;
    } else if (*src == '>') {
      dest = write_chars(dest, "&gt;");
      src += 1;
    } else if (*src == '\"') {
      dest = write_chars(dest, "&quot;");
      src += 1;
    } else {
      *dest = *src;
      dest += 1;
      src += 1;
    }
  }
}

main() {
  char st[1000];
  char out[1000];
  int l;

  cin.getline(st,1000);
  escape(st,out);

  cout << out << endl;
}
