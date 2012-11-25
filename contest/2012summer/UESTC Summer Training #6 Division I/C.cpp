#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const double eps = 1e-12;
struct Point
{
    double x,y;
    Point() {}
    Point(double _x,double _y)
    {
        x = _x;
        y = _y;
    }
    Point operator - (const Point& b)const
    {
        return Point(x-b.x,y-b.y);
    }
    double operator * (const Point& b)const
    {
        return x*b.y-y*b.x;
    }
};
struct Line
{
    Point s,e;
    double k;
    Line() {}
    Line(Point _s,Point _e,double _k)
    {
        s = _s;
        e = _e;
        k = _k;
    }
    Point operator & (const Line& b)
    {
        Point res = s;
        double t = ((s-b.s)*(b.s-b.e))/((s-e)*(b.s-b.e));
        res.x += (e.x-s.x)*t;
        res.y += (e.y-s.y)*t;
        return res;
    }
    double operator * (const Line& b)
    {
        return (e-s)*(b.e-b.s);
    }
};

Line getLine(double a,double c)
{
    return Line(Point(-1000,a*-1000+c),Point(1000,a*1000+c));
}

bool HPIcmp(Line a,Line b)
{
    if (fabs(a.k-b.k) > eps)    return a.k < b.k;
    return (a.s-b.s)*(b.e-b.s) < 0.0;
}

int HPI(Line line[],int n)
{
    Line Q[5100];
    int tot = n;
    sort(line,line+n,HPIcmp);
    tot = 1;
    for (int i = 1; i < n; i++)
        if (fabs(line[i].k-line[i-1].k) > eps)
            line[tot++] = line[i];
    if (tot < 3)  return tot;
    int tail;
    tail = 1;
    Q[0] = line[0];
    Q[1] = line[1];
    for (int i = 2; i < tot; i++)
    {
        while (tail > 0 &&
                ((Q[tail]&Q[tail-1])-line[i].s)*(line[i].e-line[i].s) > -eps)
            tail--;
        tail++;
        Q[tail] = line[i];
    }
    return tail+1;
}

int n;
Line line[5100];

int main()
{
    int totcas;
    scanf("%d",&totcas);
    while (totcas--)
    {
        scanf("%d",&n);
        for (int i = 0; i < n; i++)
        {
            double a,b;
            scanf("%lf%lf",&a,&b);
            line[i] = getLine(a,b);
            //printf("(%.2f %.2f)->(%.2f %.2f)\n",line[i].s.x,line[i].s.y,line[i].e.x,line[i].e.y);
        }
        //n = 0;
        //line[n++] = Line(Point(-1e10,-1e10),Point(1e10,-1e10));
        //line[n++] = Line(Point(1e10,-1e10),Point(1e10,1e10));
        //line[n++] = Line(Point(1e10,1e10),Point(-1e10,1e10));
        //line[n++] = Line(Point(-1e10,1e10),Point(-1e10,-1e10));
        printf("%d\n",HPI(line,n));
    }
    return 0;
}
