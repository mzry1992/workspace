#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const double eps = 1e-8;

int cmp(double a,double b)
{
    if (fabs(a-b) < eps)    return 0;
    if (a < b)  return -1;
    return 1;
}

struct Point
{
    double x,y;
    Point() {}
    Point(double _x,double _y)
    {
        x = _x;
        y = _y;
    }
    Point(Point _s,Point _e)
    {
        x = _e.x-_s.x;
        y = _e.y-_s.y;
    }
};
struct Line
{
    Point s,e;
    double k;
    Line(){}
    Line(Point _s,Point _e)
    {
        s = _s;
        e = _e;
        k = atan2(e.y-s.y,e.x-s.x);
    }
};

double xmult(Point a,Point b)
{
    return a.x*b.y-a.y*b.x;
}

double xmult(Line a,Line b)
{
    return xmult(Point(a.s,a.e),Point(b.s,b.e));
}

bool hpicmp(const Line& a,const Line& b)
{
    if (cmp(a.k,b.k) != 0)  return cmp(a.k,b.k) < 0;
    return cmp(xmult(Point(b.s,a.s),Point(b.s,b.e)),0) < 0;
}

Point LineToLine(Line a,Line b)
{
    Point res = a.s;
    double t = xmult(Point(b.s,a.s),Point(b.e,b.s))/xmult(Point(a.e,a.s),Point(b.e,b.s));
    res.x += (a.e.x-a.s.x)*t;
    res.y += (a.e.y-a.s.y)*t;
    return res;
}

Line l[50000],Q[50000];

void hpi(Line line[],int n,Point res[],int& resn)
{
    /*sort(line,line+n,hpicmp);
    int tot = 1;
    for (int i = 1;i < n;i++)
        if (cmp(line[i].k,line[i-1].k) > 0)
            line[tot++] = line[i];*/
    int tot = n;
    int head,tail;
    head = 0;
    tail = 1;
    Q[0] = line[0];
    Q[1] = line[1];
    resn = 0;
    for (int i = 2;i < tot;i++)
    {
        if(cmp(xmult(Q[tail],Q[tail-1]),0) == 0 || cmp(xmult(Q[head],Q[head+1]),0) == 0)    return;
        while (head < tail && cmp(xmult(Point(line[i].s,LineToLine(Q[tail],Q[tail-1])),Point(line[i].s,line[i].e)),0) > 0)
            tail--;
        while (head < tail && cmp(xmult(Point(line[i].s,LineToLine(Q[head],Q[head+1])),Point(line[i].s,line[i].e)),0) > 0)
            head++;
        tail++;
        Q[tail] = line[i];
    }
    while (head < tail && cmp(xmult(Point(Q[head].s,LineToLine(Q[tail],Q[tail-1])),Point(Q[head].s,Q[head].e)),0) > 0)
        tail--;
    while (head < tail && cmp(xmult(Point(Q[tail].s,LineToLine(Q[head],Q[head+1])),Point(Q[tail].s,Q[tail].e)),0) > 0)
        head++;
    if (tail <= head+1) return;
    for (int i = head;i < tail;i++)
        res[resn++] = LineToLine(Q[i],Q[i+1]);
    if (head < tail+1)
        res[resn++] = LineToLine(Q[head],Q[tail]);
}

double CalcArea(Point a,Point b,Point c)
{
    return xmult(Point(a,b),Point(a,c))/2.0;
}

double CalcArea(Point p[],int n)
{
    if (n < 3)  return 0;
    double res = 0;
    for (int i = 2;i < n;i++)
        res += CalcArea(p[0],p[i-1],p[i]);
    return res;
}

int n,resn;
Point p[50000],res[50000];

bool check(int del)
{
    int totline = 0;
    for (int i = 0;i < n;i++)
        l[totline++] = Line(p[i],p[(i+del+1)%n]);
    hpi(l,totline,res,resn);
    return cmp(CalcArea(res,resn),0) > 0;
}

int wg;
char ch;
bool ng;

inline int readint() //整数,包括负数
{
    ch = getchar();
    while (ch != '-' && (ch < '0' || ch > '9')) ch=getchar();
    if (ch == '-')
    {
        ng = true;
        ch = getchar();
    }
    else ng = false;
    wg = ch-'0';
    ch = getchar();
    while (ch >= '0' && ch <= '9')
    {
        wg = wg*10+ch-'0';
        ch = getchar();
    }
    if (ng == true) wg = -wg;
    return wg;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1; ft <= t; ft++)
    {
        scanf("%d",&n);
        for (int i = 0; i < n; i++)
        {
            p[n-1-i].x = readint();
            p[n-1-i].y = readint();
        }
        int l=0,r=n;
        while (l<r)
        {
            int mid=l+r+1>>1;
            if (check(mid))
                l=mid;
            else
                r=mid-1;
        }
        printf("%d\n",l+1);
    }
    return 0;
}
