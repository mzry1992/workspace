//poj 2485
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int t;
int n;
struct graph
{
       int x,y,cost;
}b[360000];
int m,f[600];

bool cmp(graph a,graph b)
{
     return a.cost < b.cost;
}

int findf(int x)//并查集 
{
    if (f[x] != x) f[x] = findf(f[x]);
    return f[x];
}

int kurskal()
{
    int i,now,tot,fa,fb;
    for (i = 1;i <= n;i++)
    f[i] = i;
    tot = 0;
    now = 1;
    while (true)
    {
          fa = findf(b[now].x);       fb = findf(b[now].y);
          if (fa != fb)
          {
             tot++;
             f[fa] = fb;
             if (tot == n-1)//第N-1个边就是答案 
                return b[now].cost;
          }
          now++;
    }
}

int main()
{
    int i,j,tt;
    scanf("%d",&t);
    for (t;t > 0;t--)
    {
        scanf("%d",&n);
        m = 0;
        for (i = 1;i <= n;i++)
        for (j = 1;j <= n;j++)
        {
            scanf("%d",&tt);
            if (i < j)
            {
                  m++;
                  b[m].x = i; b[m].y = j;   b[m].cost = tt;
            }
        }
        sort(b+1,b+m+1,cmp);
        printf("%d\n",kurskal());
    }    
}
