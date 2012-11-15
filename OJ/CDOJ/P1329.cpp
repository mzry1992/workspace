#include <stdio.h>

long n,m,i,j,k,q,s,t,e,map[150][150];
long ans,tans;
long dis[150][150];

int main()
{
    scanf("%ld %ld",&n,&m);
    for (i = 0;i < n;i++)
    for (j = 0;j < n;j++)
        map[i][j] = -1;
    for (i = 1;i <= m;i++)
    {
        scanf("%ld %ld %ld",&s,&t,&e);
        map[s][t] = e;
    }
    for (j = 0;j < n;j++)
    for (k = 0;k < n;k++)
        dis[j][k] = map[j][k];
    for (k = 0;k < n;k++)
    for (j = 0;j < n;j++)
    for (q = 0;q < n;q++)
    if (dis[j][k] != -1)
    if (dis[k][q] != -1)
    {
       if (dis[j][q] == -1)
          dis[j][q] = dis[j][k]+dis[k][q];
       else
           if (dis[j][q] > dis[j][k]+dis[k][q])
           dis[j][q] = dis[j][k]+dis[k][q];
    }
    ans = -1;
    for (i = 0;i < n;i++)
    for (j = 0;j < n;j++)
    if (i != j)
    if (dis[i][j] != -1)
    if (dis[j][i] != -1)
    {
                  tans = dis[i][j]+dis[j][i];
                  if ((map[i][j] != -1) && (map[j][i] != -1))
                  if (tans == map[i][j]+map[j][i])
                     break;
                  if (ans == -1)
                     ans = tans;
                  else
                      if (ans > tans)
                         ans = tans;
    }
    printf("%ld\n",ans);
    getchar();
    getchar();
    return 0;
}
        
    
