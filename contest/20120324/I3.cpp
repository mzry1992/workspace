#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const double pi = acos(-1.0);
const double eps = 1e-6;

int cmp(double a,double b)
{
    if (fabs(a-b) < eps)    return 0;
    if (a < b)  return -1;
    return 1;
}

struct point
{
    double x,y;
    point() {}
    point(double _x,double _y)
    {
        x = _x;
        y = _y;
    }
    double operator *(const point& b)
    {
        return x*b.y-y*b.x;
    }
    double operator &(const point& b)
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
    void transXY(double B)
    {
        double tx = x,ty = y;
        x = tx*cos(B) - ty*sin(B);
        y = tx*sin(B) + ty*cos(B);
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
    bool operator == (const line& b)const
    {
        return s == b.s && e == b.e;
    }
};

int dx,dy,px,py;
char com;
line a[1100],b[1100];
int tota,totb;
bool del[1100];

bool check(point mid,point s,point e)
{
    double miny = min(s.y,e.y);
    double maxy = max(s.y,e.y);
    return (cmp(s.x,mid.x) <= 0 && cmp(mid.x,e.x) <= 0 && cmp(miny,mid.y) <= 0 && cmp(mid.y,maxy) <= 0);
}

void output(line a)
{
    printf("[(%.3f,%.3f) -> (%.3f,%.3f)] ",a.s.x,a.s.y,a.e.x,a.e.y);
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
        {
            a[tot++] = line(point(px,py),point(px+dx,py+dy));
            if (a[tot-1].e < a[tot-1].s)
                swap(a[tot-1].e,a[tot-1].s);
        }
        px += dx;
        py += dy;
    }
    memset(del,false,sizeof(del));
    for (int i = 0;i < tot;i++)
        if (del[i] == false)
            for (int j = 0;j < tot;j++)
                if (i != j && del[j] == false)
                {
                    if (cmp((a[i].s-a[j].s)*(a[i].s-a[j].e),0) != 0)    continue;
                    if (cmp((a[i].e-a[j].s)*(a[i].e-a[j].e),0) != 0)    continue;
                    if (check(a[i].s,a[j].s,a[j].e) == false && check(a[i].e,a[j].s,a[j].e) == false)   continue;
                    a[i].s = min(a[i].s,a[j].s);
                    a[i].e = max(a[i].e,a[j].e);
                    del[j] = true;
                }
    int tmp = tot;
    tot = 0;
    for (int i = 0; i < tmp; i++)
        if (del[i] == false)
            a[tot++] = a[i];
    /*for (int i = 0;i < tot;i++)
        output(a[i]);
    printf("\n");*/
    return true;
}

line ta[1100],tb[1100];

bool ac(line la,line lb)
{
    point pa = la.e-la.s;
    point pb = lb.e-lb.s;

    double thetapa = atan2(pa.y,pa.x);
    double thetapb = atan2(pb.y,pb.x);
    double theta = (thetapa-thetapb);
    if (cmp(theta,0) < 0)   theta += 2*pi;
    double fai = sqrt((pb&pb)/(pa&pa));

    for (int i = 0; i < tota; i++)
    {
        ta[i] = line(a[i].s-la.s,a[i].e-la.s);
        ta[i].s.transXY(-theta);
        ta[i].s = point(ta[i].s.x*fai,ta[i].s.y*fai);
        ta[i].e.transXY(-theta);
        ta[i].e = point(ta[i].e.x*fai,ta[i].e.y*fai);
        if (ta[i].e < ta[i].s)
            swap(ta[i].s,ta[i].e);
        tb[i] = line(b[i].s-lb.s,b[i].e-lb.s);
        if (tb[i].e < tb[i].s)
            swap(tb[i].s,tb[i].e);
    }

    sort(ta,ta+tota);
    sort(tb,tb+totb);

    for (int i = 0; i < tota; i++)
        if (!(ta[i] == tb[i]))
            return false;
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
                if (ac(a[0],b[i]) == true)
                {
                    hasres = true;
                    break;
                }
            if (hasres == false)
                puts("NO");
            else
                puts("YES");
        }
    }
    return 0;
}
