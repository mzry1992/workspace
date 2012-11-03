#include <stdio.h>
#include <math.h>

int n,m,t,i,j,k,q,a[30][2100],sum[2100][30],tsum;
int f[2100][30][30],near,tcase;

int main()
{
    tcase = 0;
    while (scanf("%d %d %d",&n,&m,&t) == 3)
    {
          tcase++;
          near = 19921005;
          for (i = 1;i <= n;i++)
          for (j = 1;j <= m;j++)
          {
              scanf("%d",&a[i][j]);
              if (fabs(a[i][j]-t) < fabs(near-t))
                 near = a[i][j];
              else
              if (fabs(a[i][j]-t) == fabs(near-t))
                 if (a[i][j] < near)
                    near = a[i][j];
          }
          for (i = 1;i <= m;i++)
          {
              sum[i][0] = 0;
              for (j = 1;j <= n;j++)
                  sum[i][j] = sum[i][j-1]+a[j][i];
          }
          for (j = 1;j <= n;j++)
          for (k = 1;k <= n;k++)
              f[0][j][k] = 0;
          for (i = 1;i <= m;i++)
          for (j = 1;j <= n;j++)
          for (k = j;k <= n;k++)
          {
              f[i][j][k] = sum[i][k]-sum[i][j-1];
              if (fabs(f[i][j][k]-t) < fabs(near-t))
                 near = f[i][j][k];
              if (fabs(f[i][j][k]-t) == fabs(near-t))
              if (f[i][j][k] < near)
                 near = f[i][j][k];
              tsum = f[i][j][k]+f[i-1][j][k];
              if (tsum >= t)
              {
                       if (fabs(tsum-t) < fabs(near-t))
                          near = tsum;
                       if (fabs(tsum-t) == fabs(near-t))
                          if (tsum < near)
                             near = tsum;
              }
              else
              {
                       f[i][j][k] = tsum;
                       if (fabs(tsum-t) < fabs(near-t))
                          near = tsum;
                       if (fabs(tsum-t) == fabs(near-t))
                          if (tsum < near)
                             near = tsum;
              }    
          }   
          printf("Case %d:\n",tcase); 
          printf("%d\n",near);
    }
    return 0;
}
