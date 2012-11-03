#include <stdio.h>

int n,m,i,j,f[51000],root[51000],result,tot,a,b,fa,fb;

int findf(int x)
{
    if (f[x] != x) f[x] = findf(f[x]);
    return f[x];
}

int main()
{
    scanf("%d %d",&n,&m);
    tot = 1;
    while (!((n == 0) && (m == 0)))
    {
          for (i = 1;i <= n;i++)
          {
              f[i] = i;
              root[i] = 0;
          }
          for (i = 1;i <= m;i++)
          {
              scanf("%d %d",&a,&b);
              fa = findf(a);
              fb = findf(b);
              f[fa] = fb;
          }
          result = 0;
          for (i = 1;i <= n;i++)
          {
              fa = findf(i);
              if (root[fa] == 0)
              {
                          result++;
                          root[fa] = 1;
              }
          }
          printf("Case %d: %d\n",tot,result);
          scanf("%d %d",&n,&m);
          tot++;
    }
    return 0;
}
