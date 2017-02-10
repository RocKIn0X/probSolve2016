#include <iostream>
using namespace std;

int count_char(char* st, char c) {
  int count = 0;
  int i = 0;

  while (i < 1000) {
    if (*st == '\0') {
      return count;
    }

    if (*st == c) {
      count++;
    }
    st += 1;
    i++;
  }

  return count;
}

main()
{
  char st[1000];

  cin.getline(st,1000);

  cout << "space: " << count_char(st,' ') << endl;
  cout << "dot: " << count_char(st,'.') << endl;
  cout << "semi: " << count_char(st,';') << endl;
}
