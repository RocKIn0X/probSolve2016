#include <iostream>

using namespace std;

class IntegerSet
{
private:
  static const int max_size = 100;
  int elements[max_size];
  int num_elements;

public:
  IntegerSet();

  void add(int x);
  bool contains(int x);
  void remove(int x);
};

IntegerSet::IntegerSet()
{
  num_elements = 0;
}

bool IntegerSet::contains(int x)
{
  for (int i = 0; i < num_elements; i++) {
    if (elements[i] == x) {
      return true;
    }
  }
  return false;
}

void IntegerSet::add(int x)
{
  if (!contains(x)) {
    if (num_elements == max_size) {
      throw "Array overflow";
    }
    elements[num_elements] = x;
    num_elements++;
  }
}

void IntegerSet::remove(int x)
{
  if (contains(x)) {
    for (int i = 0; i < num_elements; i++) {
      if (elements[i] == x) {
        elements[i] = '\0';
      }
    }
  }
}

main()
{
  IntegerSet s;

  s.add(1);
  s.add(10);
  s.add(50);
  cout << s.contains(1) << endl;
  cout << s.contains(10) << endl;
  cout << s.contains(50) << endl;

  s.remove(10);
  cout << s.contains(5) << endl;
  cout << s.contains(10) << endl;
  cout << s.contains(50) << endl;

  s.remove(5);
  cout << s.contains(5) << endl;
  cout << s.contains(10) << endl;
  cout << s.contains(50) << endl;

  s.add(10);
  s.add(100);
  s.remove(50);
  cout << s.contains(10) << endl;
  cout << s.contains(50) << endl;
  cout << s.contains(100) << endl;
}
