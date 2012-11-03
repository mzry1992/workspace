#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int n,dp[1234];
struct rectangle
{
       int x1,y1,x2,y2;
}a[1234];
int ans;

bool cmp(rectangle a,rectangle b)
{
     if (a.x2 < b.x1)
     if (a.y2 < b.y1)
        return true;
     return false;
}

bool cmpxy(rectangle a,rectangle b)
{
     if (a.x1 == b.x1)
        return a.y1 < a.y2;
     return a.x1 < b.x1;
}

int main()
{
    int i,j;
    while (true)
    {
          scanf("%d",&n);
          if (n == 0)    break;
          for (i = 1;i <= n;i++)
              scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
          sort(a+1,a+n+1,cmpxy);
          memset(dp,0,sizeof(dp));
          ans = 1;
          for (i = 1;i <= n;i++)
          {
              dp[i] = 1;
              for (j = 1;j <= i-1;j++)
              if (cmp(a[j],a[i]) == true)
              if (dp[i] < dp[j]+1)
              {
                 dp[i] = dp[j]+1;
                 if (dp[i] > ans)
                    ans = dp[i];
              }
          }
          printf("%d\n",ans);
    }   
    return 0;
}
