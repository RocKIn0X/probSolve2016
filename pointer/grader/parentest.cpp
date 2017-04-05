#include <iostream>

using namespace std;

bool sameType (char x, char y) {
  if (x == '(' and y == ')') {
    return true;
  }

  if (x == '{' and y == '}') {
    return true;
  }

  if(x == '[' and y == ']') {
    return true;
  }

  return false;
}

void checkPar (char* a, char* b) {
  char openPar[105];
  char* ptr;

  ptr = openPar;

  while (*a != '\0') {

    if (*a == '[' or *a == '(' or *a == '{') {
      *ptr = *a;
      ptr++;
    } else if (*a == ']' or *a == ')' or *a == '}') {
      if (sameType(*(ptr - 1), *a)) {
        ptr--;
        *ptr = '\0';
      } else {
        *b = 'N';
        return;
      }
    }
    a++;
  }

  if (*openPar == '\0') {
    *b = 'Y';
  } else {
    *b = 'N';
  }
}

int main() {
  int n, i;
  char par[105];
  char yesOrNo[105];
  char* ptr;

  i = 0;
  ptr = yesOrNo;
  cin >> n;

  while (n > 0) {
    cin >> par;
    n--;
    checkPar(par, yesOrNo + i);
    i++;
  }

  while (*ptr != '\0') {
    if (*ptr == 'Y') {
      cout << "yes" << endl;
    } else if (*ptr == 'N') {
      cout << "no" << endl;
    }
    ptr++;
  }

  return 0;
}
