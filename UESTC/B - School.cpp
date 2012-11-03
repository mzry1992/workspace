#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m,g[100001],v[100001],b[100001],a,res;
bool visit[100001];

int main()
{
    scanf("%d%d",&n,&m);
    for (int i = 1;i <= n;i++)  scanf("%d",&g[i]);
    for (int i = 1;i <= m;i++)  scanf("%d",&v[i]);
    for (int i = 1;i <= m;i++)  scanf("%d",&b[i]);
    for (int j = 1;j <= n;j++)  visit[j] = false;
    res = 0;
    for (int i = 1;i <= m;i++)
    {
        a = (v[i]+res-1)%n+1;
        res = 0;
        while (true)
        {
            a = g[a];
            b[i]--;
            if (visit[a] == false)  res++;
            visit[a] = true;
            if (b[i] == 0)  break;
        }
        printf("%d\n",res);
    }
}
