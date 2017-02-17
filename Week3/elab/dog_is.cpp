#include <iostream>

using namespace std;

class Dog
{
private:
  string name;
  int age;
  float speed;

public:
  /* member functions from the last task are hidden */

    bool is_faster(Dog d);
    bool is_younger(Dog d);

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

  bool Dog::is_faster(Dog d)
  {
    if (speed >= d.speed) {
      return true;
    } else {
      return false;
    }
  }

  bool Dog::is_younger(Dog d)
  {
    if (age <= d.age) {
      return true;
    } else {
      return false;
    }
  }

main()
{
  Dog d1("Dang", 5, 5);

  int d2_age;
  float d2_speed;

  cin >> d2_age >> d2_speed;

  Dog d2("Dum", d2_age, d2_speed);

  if (d1.is_faster(d2)) {
    cout << "d1 is faster" << endl;
  } else {
    cout << "d2 is faster" << endl;
  }
  if (d1.is_younger(d2)) {
    cout << "d1 is younger" << endl;
  } else {
    cout << "d2 is younger" << endl;
  }
}
