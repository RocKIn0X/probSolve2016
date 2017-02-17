#include <iostream>

using namespace std;

class Dog
{
private:
  string name;
  int age;
  float speed;

public:
  Dog(string n, int a, float s)
  {
    name = n;
    age = a;
    speed = s;
  }

  float get_speed()
  {
    return speed;
  }

  void set_speed(float s)
  {
    speed = s;
  }

  void say_hi()
  {
    cout << "Hello. My name is " << name << endl;
  }

  float get_run_duration(float distance)
  {
    return distance / speed;
  }
};

main()
{
  Dog d("Dang", 5, 5);

  cout << d.get_speed() << endl;
  cout << d.get_run_duration(14) << endl;
  d.set_speed(12);
  cout << d.get_run_duration(30) << endl;
}
