#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int map[200][200],f[200];
struct graph
{
       int a,b,dist;
}g[20000];
int totg;
int ans;

bool cmp(graph a,graph b)
{
     return a.dist < b.dist;
}

int findf(int x)
{
    if (f[x] != x)       f[x] = findf(f[x]);
    return f[x];
}

bool check()
{
     int i;
     for (i = 2;i <= n;i++)
     if (findf(i) != findf(1))
        return false;
     return true;
}

int main()
{
    int i,j,k,q,f1,f2;
    scanf("%d",&n);
    for (i = 1;i <= n;i++)
        f[i] = i;
    for (i = 1;i <= n;i++)
    for (j = 1;j <= n;j++)
        scanf("%d",&map[i][j]);
    scanf("%d",&m);
    for (j = 1;j <= m;j++)
    {
        scanf("%d%d",&k,&q);
        f1 = findf(k);      f2 = findf(q);
        f[f2] = f1;
        map[k][q] = map[q][k] = 0;//去掉边 
    }
    totg = 0;
    for (i = 1;i < n;i++)
    for (j = i+1;j <= n;j++)
    if (map[i][j] != 0)
    {
                  totg++;
                  g[totg].a = i;  g[totg].b = j;    g[totg].dist = map[i][j];
    }
    sort(g+1,g+totg+1,cmp);
    int ta,tb,td;
    i = 1;
    ans = 0;
    while (true)
    {
          ta = g[i].a;     tb = g[i].b;     td = g[i].dist;
          f1 = findf(ta);  f2 = findf(tb);
          if (f1 != f2)
          {
                 f[f2] = f1;
                 ans += td;
          }
          i++;
          if (check() == true)  break;//如果所有的边都联通那么就退出 
    }
    printf("%d\n",ans);
    system("pause");
    return 0;
}
