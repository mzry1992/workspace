#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,a[1000],b[1000],ta,tb,la,lb,lc;
struct Girl
{
    int a,b,c,s;
};
Girl g[1000];
struct Girl2
{
    int c,s;
};
Girl2 g2[1000];
int tg,l,sum;

bool cmp(const Girl2& a,const Girl2& b)
{
    return a.c < b.c;
}

bool cmp2(const Girl& a,const Girl& b)
{
    return a.c < b.c;
}

int main()
{
    int tn;
    while (scanf("%d",&tn) != EOF)
    {
        n = 0;
        for (int i = 0; i < tn; i++)
        {
            scanf("%d%d%d%d",&g[n].a,&g[n].b,&g[n].c,&g[n].s);
            if (g[n].s >= 0)    continue;
            a[n] = g[n].a;
            b[n] = g[n].b;
            n++;
        }
        sort(g,g+n,cmp2);
        scanf("%d%d%d",&la,&lb,&lc);
        sort(a,a+n);
        sort(b,b+n);
        ta = unique(a,a+n)-a;
        tb = unique(b,b+n)-b;
        int res = 0;
        for (int fa = 0; fa < ta; fa++)
            for (int fb = 0; fb < tb; fb++)
            {
                tg = 0;
                for (int i = 0; i < n; i++)
                    if (a[fa] <= g[i].a && g[i].a <= a[fa]+la)
                        if (b[fb] <= g[i].b && g[i].b <= b[fb]+lb)
                        {
                            g2[tg].c = g[i].c;
                            g2[tg].s = g[i].s;
                            tg++;
                        }
                if (tg == 0)    continue;
                l = 0;
                sum = 0;
                for (int i = 0; i < tg; i++)
                {
                    sum += g2[i].s;
                    while (l < i && g2[l].c+lc < g2[i].c)
                    {
                        sum -= g2[l].s;
                        l++;
                    }
                    res = min(res,sum);
                }
            }
        if (res == 0)
            puts("Error 404, mahou shoujo not found!");
        else
            printf("%d\n",res);
    }
    return 0;
}
