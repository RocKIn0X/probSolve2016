#include <map>
#include <cstdio>

using namespace std;

map<int,int> m;

main()
{
  m[1] = 10;
  m[100] = 20;
  m[1000000] = 30;
  m[100]++;
  m.insert(make_pair(1000,1000000));

  printf("%d\n",m.lower_bound(99)->first);
  printf("%d\n",m.lower_bound(1000)->first);
  printf("%d\n",m.upper_bound(999)->first);
  printf("%d\n",m.upper_bound(1000)->first);
}
