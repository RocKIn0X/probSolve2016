#include <iostream>
using namespace std;
class IntegerMap
{
private:
  static const int max_size = 100;
  int keys[max_size];
  int values[max_size];
  int num_elements;
public:
  IntegerMap() : num_elements(0) {}

  void set_value(int k, int v);
  int get_value(int k);
  bool contains_key(int k);
private:
  int get_key_index(int k);
};

int IntegerMap::get_value(int k)
{
  int i = get_key_index(k);
  if (i == -1) {
    throw "key not found.";
  } else {
    return values[i];
  }
}

bool IntegerMap::contains_key(int k)
{
  return get_key_index(k) != -1;
}

int IntegerMap::get_key_index(int k)
{
  for (int i = 0; i < num_elements; i++) {
    if (keys[i] == k) {
      return i;
    }
  }

  return -1;
}

void IntegerMap::set_value(int k, int v)
{
  int i = get_key_index(k);
  if (i != -1) {
    values[i] = v;
  } else {
    keys[num_elements] = k;
    values[num_elements] = v;

    num_elements++;
  }
}

main()
{
  IntegerMap m;

  cout << m.contains_key(10) << endl;
  m.set_value(1,100);
  cout << m.get_value(1) << endl;
  m.set_value(1,1000);
  cout << m.get_value(1) << endl;
  m.set_value(10,20);
  cout << m.get_value(10) << endl;
  m.set_value(100000000,-1);
  cout << m.get_value(100000000) << endl;
  cout << m.contains_key(100000000) << endl;
  cout << m.contains_key(1000) << endl;
}
