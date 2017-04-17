#include <list>
#include <iostream>
#include <string>

using namespace std;

int main() {
  int n;
  int order[4];
  char op;
  string str;

  list<string> lst;
  list<string>::iterator itr = lst.begin();

  cin >> n;;

  for (int i = 0; i < n; i++) {
    cin >> op;

    if (op == 'i') {
      cin >> str;

      lst.insert(itr, str);
    } else if (op == 'l') {
      if (itr != lst.begin()) {
        itr--;
      }
    } else if (op == 'r') {
      if (itr != lst.end()) {
        itr++;
      }
    } else if (op == 'b') {
      if (itr != lst.begin()) {
        itr--;
        itr = lst.erase(itr);
      }
    } else if (op == 'd') {
      if (itr != lst.end()) {
        itr = lst.erase(itr);
      }
    }
  }

  for (list<string>::iterator i = lst.begin(); i != lst.end(); i++) {
      cout << *i << " ";
  }

  cout << endl;

  return 0;
}
