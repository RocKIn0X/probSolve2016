#include <cstdio>

main()
{
  int x,y;
  do {
    int r = scanf("%d %d",&x,&y);
    if(r!=2) {
      break;
    }
    printf("%d\n",x+y);
  } while(true);
}
