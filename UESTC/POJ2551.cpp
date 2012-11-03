#include <stdio.h>

int n,ans,y,c;

int main()
{
    while (scanf("%d",&n) == 1)
    {
          ans = 1;
          y = 1%n;
          while (y != 0)
          {
                ans++;
                c = y*10+1;
                y = c%n;
          }
          printf("%d\n",ans);
    }
    return 0;
}
