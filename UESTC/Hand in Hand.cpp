#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,f[10010],p[10010],e[10010],u,v,fa,fb;
vector<pair<int,int> > e0,e1;

int findf(int x)
{
    if (f[x] != x)  f[x] = findf(f[x]);
    return f[x];
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&n,&m);
        for (int i = 1;i <= n;i++)
        {
            f[i] = i;
            p[i] = 1;
            e[i] = 0;
        }
        for (int i = 1;i <= m;i++)
        {
            scanf("%d%d",&u,&v);
            fa = findf(u);
            fb = findf(v);
            if (fa == fb)
                e[fa]++;
            else
            {
                e[fa] += e[fb]+1;
                p[fa] += p[fb];
                f[fb] = fa;
            }
        }
        e0.clear();
        for (int i = 1;i <= n;i++)
            if (findf(i) == i)
                e0.push_back(make_pair(e[i],p[i]));
        scanf("%d%d",&n,&m);
        for (int i = 1;i <= n;i++)
        {
            f[i] = i;
            p[i] = 1;
            e[i] = 0;
        }
        for (int i = 1;i <= m;i++)
        {
            scanf("%d%d",&u,&v);
            fa = findf(u);
            fb = findf(v);
            if (fa == fb)
                e[fa]++;
            else
            {
                e[fa] += e[fb]+1;
                p[fa] += p[fb];
                f[fb] = fa;
            }
        }
        e1.clear();
        for (int i = 1;i <= n;i++)
            if (findf(i) == i)
                e1.push_back(make_pair(e[i],p[i]));
        sort(e0.begin(),e0.end());
        sort(e1.begin(),e1.end());
        printf("Case #%d: ",ft);
        if (e0 == e1)
            puts("YES");
        else
            puts("NO");
    }
}
