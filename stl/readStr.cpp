#include <list>
#include <cstdio>
#include <cstring>

using namespace std;

main()
{
  char buffer[1000];
  int n;
  list<char*> slist;

  scanf("%d",&n);
  for(int i=0; i<n; i++) {
    scanf("%s",buffer);
    char* w = strdup(buffer);
    slist.push_back(w);
  }

  for(list<char*>::iterator i = slist.begin();
      i != slist.end(); i++) {
    printf("%s\n", *i);
  }
}
