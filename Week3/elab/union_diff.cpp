#include <iostream>

using namespace std;

class IntegerSet
{
private:
  static const int max_size = 100;
  int elements[max_size];
  int num_elements;

public:
  IntegerSet(): num_elements(0) {}

  void add(int x);
  bool contains(int x) const;
  void remove(int x);

  IntegerSet set_union(const IntegerSet& s);
  IntegerSet set_difference(const IntegerSet& s);
};

bool IntegerSet::contains(int x) const
{
  for (int i=0; i<num_elements; i++) {
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

IntegerSet IntegerSet::set_union(const IntegerSet& o)
{
  IntegerSet out;

  for (int i = 0; i < num_elements; i++) {
    out.add(elements[i]);
    out.num_elements++;
  }

  for (int i = 0; i < o.num_elements; i++) {
    if (!out.contains(o.elements[i])) {
      out.add(o.elements[i]);
    }
  }

  return out;
}

IntegerSet IntegerSet::set_difference(const IntegerSet& o)
{
  IntegerSet out;

  for (int i = 0; i < num_elements; i++) {
    out.add(elements[i]);
    out.num_elements++;
  }

  for (int i = 0; i < out.num_elements; i++) {
    if (o.contains(out.elements[i])) {
      out.elements[i] = '\0';
    }
  }

  return out;
}

main()
{
  IntegerSet s1,s2;
  s1.add(1);  s1.add(5);  s1.add(10);  s1.add(15);  s1.add(100);
  s2.add(2);  s2.add(5);  s2.add(15);  s2.add(50);  s2.add(90);
  IntegerSet q;
  q = s1.set_union(s2);
  cout << q.contains(1) << q.contains(2) << q.contains(5) << q.contains(15)
       << q.contains(50) << q.contains(100) << q.contains(200) << endl;
  q = s1.set_difference(s2);
  cout << q.contains(1) << q.contains(2) << q.contains(5) << q.contains(15)
       << q.contains(50) << q.contains(100) << q.contains(200) << endl;
}
