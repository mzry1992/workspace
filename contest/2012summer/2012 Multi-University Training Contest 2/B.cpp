#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

struct Point
{
    int x,y,idy,id;
};

bool cmp(Point a,Point b)
{
    if (a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}

bool cmp2(Point a,Point b)
{
    if (a.x == b.x)
        return a.y > b.y;
    return a.x > b.x;
}

long long treen[100001],treex[100001],treey[100001];
long long lu[100001],ld[100001],ru[100001],rd[100001];
Point p[100000];
int n,sy[100000],m;

void updaten(int x,int v)
{
    for (;x <= m;x+=x&-x)
        treen[x] += v;
}

void updatex(int x,int v)
{
    for (;x <= m;x+=x&-x)
        treex[x] += v;
}

void updatey(int x,int v)
{
    for (;x <= m;x+=x&-x)
        treey[x] += v;
}

long long readn(int x)
{
    long long res = 0;
    for (;x > 0;x^=x&-x)
        res += treen[x];
    return res;
}

long long readn(int x,int y)
{
    if (x > y)  return 0;
    return readn(y)-readn(x-1);
}

long long readx(int x)
{
    long long res = 0;
    for (;x > 0;x^=x&-x)
        res += treex[x];
    return res;
}

long long readx(int x,int y)
{
    if (x > y)  return 0;
    return readx(y)-readx(x-1);
}

long long ready(int x)
{
    long long res = 0;
    for (;x > 0;x^=x&-x)
        res += treey[x];
    return res;
}

long long ready(int x,int y)
{
    if (x > y)  return 0;
    return ready(y)-ready(x-1);
}

int main()
{
    int totcas;
    scanf("%d",&totcas);
    while (totcas--)
    {
        scanf("%d",&n);
        for (int i = 0;i < n;i++)
        {
            scanf("%d%d",&p[i].x,&p[i].y);
            sy[i] = p[i].y;
            p[i].id = i;
        }
        sort(sy,sy+n);
        m = unique(sy,sy+n)-sy;
        for (int i = 0;i < n;i++)
            p[i].idy = lower_bound(sy,sy+m,p[i].y)-sy+1;

        sort(p,p+n,cmp);
        memset(treen,0,sizeof(treen));
        memset(treex,0,sizeof(treex));
        memset(treey,0,sizeof(treey));
        for (int i=0;i<n;i++)
        {
            lu[p[i].id]=(p[i].x+p[i].y)*readn(1,p[i].idy)-readx(1,p[i].idy)-ready(1,p[i].idy);
            ld[p[i].id]=(p[i].x-p[i].y)*readn(p[i].idy+1,m)-readx(p[i].idy+1,m)+ready(p[i].idy+1,m);
            //cout << lu[p[i].id] << ' ' << ld[p[i].id] << ' ' << p[i].id << endl;
            updaten(p[i].idy,1);
            updatex(p[i].idy,p[i].x);
            updatey(p[i].idy,p[i].y);
        }
        sort(p,p+n,cmp2);
        memset(treen,0,sizeof(treen));
        memset(treex,0,sizeof(treex));
        memset(treey,0,sizeof(treey));
        for (int i=0;i<n;i++)
        {
            ru[p[i].id]=(-p[i].x+p[i].y)*readn(1,p[i].idy)+readx(1,p[i].idy)-ready(1,p[i].idy);
            rd[p[i].id]=(-p[i].x-p[i].y)*readn(p[i].idy+1,m)+readx(p[i].idy+1,m)+ready(p[i].idy+1,m);
            updaten(p[i].idy,1);
            updatex(p[i].idy,p[i].x);
            updatey(p[i].idy,p[i].y);
        }
        long long res = 0x7fffffffffffffffLL;
        for (int i = 0;i < n;i++)
            res = min(res,lu[i]+ld[i]+ru[i]+rd[i]);
        printf("%I64d\n",res);
    }
	return 0;
}
