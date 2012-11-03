#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

int cmp(long long a,long long b)
{
    if (a == b)    return 0;
    if (a < b)  return -1;
    return 1;
}

struct point
{
    long long x,y;
    point() {}
    point(long long _x,long long _y)
    {
        x = _x;
        y = _y;
    }
    long long operator *(const point& b)
    {
        return x*b.y-y*b.x;
    }
    long long operator &(const point& b)
    {
        return x*b.x+y*b.y;
    }
    point operator -(const point& b)
    {
        return point(x-b.x,y-b.y);
    }
    point operator +(const point& b)
    {
        return point(x+b.x,y+b.y);
    }
    bool operator < (const point& b)const
    {
        if (cmp(x,b.x) == 0)   return  cmp(y,b.y) < 0;
        return cmp(x,b.x) < 0;
    }
    bool operator == (const point& b)const
    {
        return cmp(x,b.x) == 0 && cmp(y,b.y) == 0;
    }

};

struct line
{
    point s,e;
    line() {}
    line(point _s,point _e)
    {
        s = _s;
        e = _e;
    }
    bool operator < (const line& b)const
    {
        if (s == b.s)   return e < b.e;
        return s < b.s;
    }
};

long long xxx(line a,line b)
{
    return (a.e-a.s)*(b.e-b.s);
}

int dx,dy,px,py;
char com;
line a[1100],b[1100];
int tota,totb;
bool del[1100];

bool check(point mid,point s,point e)
{
    long long minx = min(s.x,e.x);
    long long maxx = max(s.x,e.x);
    long long miny = min(s.y,e.y);
    long long maxy = max(s.y,e.y);
    return (cmp(minx,mid.x) <= 0 && cmp(mid.x,maxx) <= 0 && cmp(miny,mid.y) <= 0 && cmp(mid.y,maxy) <= 0);
}

void output(line a)
{
    printf("[(%lld,%lld) -> (%lld,%lld)] ",a.s.x,a.s.y,a.e.x,a.e.y);
}

bool Gao(line a[],int& tot)
{
    px = py = tot = 0;
    while (true)
    {
        scanf(" %c",&com);
        if (com == 'Q') return false;
        if (com == 'E') break;
        scanf("%d%d",&dx,&dy);
        if (com == 'L')
            a[tot++] = line(point(px,py),point(px+dx,py+dy));
        px += dx;
        py += dy;
    }
    memset(del,false,sizeof(del));
    for (int i = 0; i < tot; i++)
        if (del[i] == false)
            for (int j = i+1; j < tot; j++)
                if (del[j] == false)
                    if (xxx(a[i],a[j]) == 0 && (a[i].s-a[j].s)*(a[i].s-a[j].e) == 0 && (check(a[i].s,a[j].s,a[j].e) || check(a[i].e,a[j].s,a[j].e)))
                    {
                        int typ = 0;
                        if (cmp(min(a[i].s.x,a[i].e.x),a[i].s.x) == 0 && cmp(max(a[i].s.y,a[i].e.y),a[i].s.y) == 0)   typ = 1;
                        if (cmp(min(a[i].s.x,a[i].e.x),a[i].e.x) == 0 && cmp(max(a[i].s.y,a[i].e.y),a[i].e.y) == 0)   typ = 1;

                        long long minx = min(min(a[i].s.x,a[i].e.x),min(a[j].s.x,a[j].e.x));
                        long long maxx = max(max(a[i].s.x,a[i].e.x),max(a[j].s.x,a[j].e.x));
                        long long miny = min(min(a[i].s.y,a[i].e.y),min(a[j].s.x,a[j].e.x));
                        long long maxy = max(max(a[i].s.y,a[i].e.y),max(a[j].s.y,a[j].e.y));
                        del[j] = true;

                        if (typ == 0)
                            a[i] = line(point(minx,miny),point(maxx,maxy));
                        else
                            a[i] = line(point(minx,maxy),point(maxx,miny));
                    }
    int tmp = tot;
    tot = 0;
    for (int i = 0; i < tmp; i++)
        if (del[i] == false)
            a[tot++] = a[i];
    for (int i = 0;i < tot;i++)
        output(a[i]);
    printf("\n");
    return true;
}

bool tle(long long x,long long tx,long long y,long long ty)
{
    if (tx == 0)    return (ty == 0 || x == 0);
    if (ty == 0)    return (y == 0 || tx == 0);

    long long dx = x/tx,mx = x%tx;
    long long dy = y/ty,my = y%ty;
    return (dx == dy && mx == my);
}

bool ac(long long x,long long y,long long z,point a,point b,long long xm)
{
    point pa = a;
    point pb = b;
    //if (cmp(xm,0) == 0 && cmp(pa*pb,0) != 0)    return false;
    //if (cmp(pa*pb,0) != 0 && cmp(pa*pb,0) != cmp(xm,0))  return false;

    point mv = pb-pa;

    long long tx,ty,tz;

    tx = pa&pa;
    ty = pb&pb;
    tz = mv&mv;

    if (tle(x,tx,y,ty) == false || tle(x,tx,z,tz) == false)   return false;

    return true;
}

bool wa(line la,line lb)
{
    point pa = la.e-la.s;
    point pb = lb.e-lb.s;
    point mv = pb-pa;

    long long xm = pa*pb;

    long long x,y,z;
    x = pa&pa;
    y = pb&pb;
    z = mv&mv;

    for (int i = 0;i < tota;i++)
    {
        bool flag = false;
        for (int j = 0;j < totb;j++)
        {
            if ((ac(x,y,z,a[i].s-la.s,b[j].s-lb.s,xm) && ac(x,y,z,a[i].e-la.s,b[j].e-lb.s,xm)) ||
                (ac(x,y,z,a[i].s-la.s,b[j].e-lb.s,xm) && ac(x,y,z,a[i].e-la.s,b[j].s-lb.s,xm)))
            {
                flag = true;
                break;
            }
        }
        if (flag == false)  return false;
    }

    return true;
}

int main()
{
    while (true)
    {
        if (Gao(a,tota) == false)   break;
        Gao(b,totb);

        if (tota != totb)
            puts("NO");
        else
        {
            bool hasres = false;
            for (int i = 0; i < totb; i++)
            {
                if (wa(a[0],line(b[i].s,b[i].e)) ||
                        wa(a[0],line(b[i].e,b[i].s)))
                {
                    hasres = true;
                    break;
                }
            }
            if (hasres == true)
                puts("YES");
            else
                puts("NO");
        }
    }
    return 0;
}
