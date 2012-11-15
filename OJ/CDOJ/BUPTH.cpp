#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int n,d,a,dp[120000];
int ans;
int 
int main()
{
    int i;
    while (scanf("%d%d",&n,&d) == 2)
    {
          for (i = 1;i <= n;i++)
              scanf("%d",&a);
          sort(a+1,a+n+1);
          
          ans = 0;
          for (i = 1;i <= n;i++)
              ans += dp[i];
          printf("%d\n",ans);
    }
    return 0;
}
