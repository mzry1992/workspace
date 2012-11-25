#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

struct rect
{
    int xa,ya,xb,yb;
};

rect a[500];
int n;

bool cmpa(const rect& a,const rect& b)
{
    if (a.ya == b.ya)
        return a.xa < b.xa;
    return a.ya < b.ya;
}

bool cmpb(const rect& a,const rect& b)
{
    if (a.xa == b.xa)
        return a.ya < b.ya;
    return a.xa < b.xa;
}

int main()
{
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1;cas <= totcas;cas++)
    {
        scanf("%d",&n);
        for (int i = 0;i < n;i++)
            scanf("%d%d%d%d",&a[i].xa,&a[i].ya,&a[i].xb,&a[i].yb);
        for (int tim = 0;tim < n;tim++)
        {
            sort(a,a+n,cmpa);
            for (int i = 0;i < n;i++)
            {
                int toy = 0;
                for (int j = 0;j < i;j++)
                    if (a[j].xa < a[i].xb && a[j].xb > a[i].xa)
                        toy = max(toy,a[j].yb);
                int dy = a[i].ya-toy;
                a[i].ya -= dy;
                a[i].yb -= dy;
            }
            sort(a,a+n,cmpb);
            for (int i = 0;i < n;i++)
            {
                int tox = 0;
                for (int j = 0;j < i;j++)
                    if (a[j].ya < a[i].yb && a[j].yb > a[i].ya)
                        tox = max(tox,a[j].xb);
                int dx = a[i].xa-tox;
                a[i].xa -= dx;
                a[i].xb -= dx;
            }
        }
        int mx,my;
        mx = my = 0;
        for (int i = 0;i < n;i++)
        {
            mx = max(mx,a[i].xb);
            my = max(my,a[i].yb);
        }
        printf("%d %d\n",mx,my);
    }
	return 0;
}
