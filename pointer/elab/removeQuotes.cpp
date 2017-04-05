#include <iostream>
using namespace std;

void remove_quotes(char* src, char *dest) {
  int i = 0;

  while (i < 1000) {
    if (*src == '\0') {
      *dest = 0;
      break;
    }

    if (*src != '\'' and *src != '\"') {
      *dest = *src;
      dest += 1;
      src += 1;
    } else {
      src += 1;
    }
  }
}

main()
{
  char st[1000];
  char out[1000];
  int l;

  cin.getline(st,1000);
  remove_quotes(st,out);

  cout << out << endl;
}
