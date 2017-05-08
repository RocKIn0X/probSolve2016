#include <set>
#include <cstdio>

using namespace std;

typedef pair<int,int> int_pair;
typedef pair<int,int_pair> node_pair;
set<node_pair> s;

main()
{
  int_pair p = make_pair(0,1);
  s.insert(make_pair(0,p));

  //pair<set<int_pair>::iterator,bool> res = s.insert(int_pair(10,0));
  p = make_pair(0,0);
  s.insert(make_pair(0,p));
  s.insert(node_pair(0,int_pair(1,2)));

  //s.erase(res.first);

  for(set<node_pair>::iterator i = s.begin();
      i != s.end(); i++) {
    printf("%d, %d\n", i->first, i->second);
  }
}
