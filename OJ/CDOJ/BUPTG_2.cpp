#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

int f1[100200],f2[100200],p[100],m[100],c[100][20],v[100][200];
int n,maxv;

int main()
{
    int i,j,k;
    while (scanf("%d%d",&n,&maxv) != EOF)
    {
          for (i = 1;i <= n;i++)
          {
              scanf("%d%d",&p[i],&m[i]);
              for (j = 1;j <= m[i];j++)
                  scanf("%d%d",&c[i][j],&v[i][j]);
          }
          memset(f1,0,sizeof(f1));
          for (i = 1;i <= n;i++)
          {
              for (j = 0;j <= maxv;j++)
                  f2[j] = f1[j];
              for (j = 1;j <= m[i];j++)
              for (k = maxv;k >= c[i][j];k--)
              if (f2[k] < f2[k-c[i][j]]+v[i][j])
                 f2[k] = f2[k-c[i][j]]+v[i][j];
              for (k = maxv;k >= p[i];k--)
              if (f1[k] < f2[k-p[i]])
                 f1[k] = f2[k-p[i]];
          }
          printf("%d\n",f1[maxv]);
    }
    return 0;
}
