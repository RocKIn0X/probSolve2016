#include <iostream>
using namespace std;

void copy_string(char* src, char* dest) {
  int i = 0;

  while (i < 1000) {
    if (*src == '\0') {
      *dest = 0;
      break;
    }

    *dest = *src;
    dest += 1;
    src += 1;
  }
}

main()
{
  char st1[1000];
  char st2[1000];

  cin.getline(st1,1000);
  copy_string(st1,st2);

  cout << st2 << endl;
}
