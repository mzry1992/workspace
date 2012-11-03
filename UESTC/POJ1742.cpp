#include <iostream>
using namespace std;

bool f[100100];
int u[100100];
int n,m,i,j,k,ans,a[200],c[200];

int main()
{
    while (true)
    {
          scanf("%d%d",&n,&m);
          if ((n == 0) && (m == 0)) break;
          for (i = 1;i <= n;i++)
              scanf("%d",&a[i]);
          for (i = 1;i <= n;i++)
              scanf("%d",&c[i]);
          for (i = 1;i <= m;i++)
              f[i] = false;
          f[0] = true;
          for (i = 1;i <= n;i++)
          {
              for (j = 0;j <= m;j++)
                  u[j] = 0;
              for (j = a[i];j <= m;j++)
              if (f[j] == false)
              {
                  if (f[j-a[i]] == true)
                  if (u[j-a[i]] < c[i])
                  {
                                  u[j] = u[j-a[i]]+1;
                                  f[j] = true;
                  }
              }
          }
          ans = 0;
          for (i = 1;i <= m;i++)
          if (f[i] == true)
             ans++;
          printf("%d\n",ans);
    }
    return 0;
}
