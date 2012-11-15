#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const double eps = 1e-12;
const double pi = acos(-1.0);

struct Point
{
    double x,y;
    Point(){}
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

bool HalfPlaneIntersectionCmp(Line a,Line b)
{
    if (fabs(a.k-b.k) > eps)    return a.k < b.k;
    return xmult(Point(b.s,a.s),Point(b.s,b.e)) < 0.0;
}

Point LineToLine(Line a,Line b)
{
    Point res = a.s;
    double t = ((a.s.x-b.s.x)*(b.s.y-b.e.y)-(a.s.y-b.s.y)*(b.s.x-b.e.x))/((a.s.x-a.e.x)*(b.s.y-b.e.y)-(a.s.y-a.e.y)*(b.s.x-b.e.x));
    res.x += (a.e.x-a.s.x)*t;
    res.y += (a.e.y-a.s.y)*t;
    return res;
}

void HalfPlaneIntersection(Line line[],int n,Point res[],int& resn)
{
    Line Q[100];
    int tot = n;
    sort(line,line+n,HalfPlaneIntersectionCmp);
    tot = 1;
    for (int i = 1;i < n;i++)
        if (fabs(line[i].k-line[i-1].k) > eps)
            line[tot++] = line[i];
    int head,tail;
    head = 0;
    tail = 1;
    Q[0] = line[0];
    Q[1] = line[1];
    resn = 0;
    for (int i = 2;i < tot;i++)
    {
        if ((fabs(xmult(Q[tail],Q[tail-1])) < eps) || (fabs(xmult(Q[head],Q[head+1])) < eps))   return;
        while (head < tail && xmult(Point(line[i].s,LineToLine(Q[tail],Q[tail-1])),Point(line[i].s,line[i].e)) > eps)
            tail--;
        while (head < tail && xmult(Point(line[i].s,LineToLine(Q[head],Q[head+1])),Point(line[i].s,line[i].e)) > eps)
            head++;
        tail++;
        Q[tail] = line[i];
    }
    while (head < tail && xmult(Point(Q[head].s,LineToLine(Q[tail],Q[tail-1])),Point(Q[head].s,Q[head].e)) > eps)
        tail--;
    while (head < tail && xmult(Point(Q[tail].s,LineToLine(Q[head],Q[head+1])),Point(Q[tail].s,Q[tail].e)) > eps)
        head++;
    if (tail <= head+1) return;
    for (int i = head;i < tail;i++)
        res[resn++] = LineToLine(Q[i],Q[i+1]);
    if (head < tail+1)
        res[resn++] = LineToLine(Q[head],Q[tail]);
}

Line GetLine(double a,double b,double c,int& sta) //ax+by+c > 0
{
    if (fabs(a) < eps && fabs(b) < eps)
    {
        if (c > eps)    sta = 1;
        else sta = 2;
        return Line();
    }
    if (fabs(a) < eps)
    {
        double tmp = -c/b;
        if (b > eps)    //5y+3 > 0 -> y > -3/5
            return Line(Point(0,tmp),Point(1,tmp));
        else    //-5y+3 > 0 -> 5y < 3 -> y < 3/5
            return Line(Point(1,tmp),Point(0,tmp));
    }
    if (fabs(b) < eps)
    {
        double tmp = -c/a;
        if (a > eps)    //5x+3 > 0 -> x > -3/5
            return Line(Point(tmp,1),Point(tmp,0));
        else    //-5x+3 > 0 -> 5x < 3 -> x < 3/5
            return Line(Point(tmp,0),Point(tmp,1));
    }
    //ax+by+c > 0 -> by > -ax-c
    double tmp1 = -a/b;
    double tmp2 = -c/b;
    if (b > eps)    // y > -a/b * x-c/b
        return Line(Point(0,tmp2),Point(1,tmp1+tmp2));
    else    // -by < ax+c -> -a/b * x-c/b
        return Line(Point(1,tmp1+tmp2),Point(0,tmp2));
}

double CalcArea(Point a,Point b,Point c)    {   return xmult(Point(a,b),Point(a,c))/2.0;}

double CalcArea(Point l[],int n)
{
    if (n < 3) return 0.0;
    double res = 0.0;
    for (int i = 2;i < n;i++)
        res += CalcArea(l[0],l[i-1],l[i]);
    return res;
}

int n,linen,resn;
double u[100],v[100],w[100],a,b,c;
Point res[100];
Line line[100];

bool InsertLine(double a,double b,double c)
{
    int sta;
    Line tmp = GetLine(a,b,c,sta);
    if (sta == 2)   return false;
    if (sta == 1)   return true;
    line[linen++] = tmp;
    int j = linen-1;
    return true;
}

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 0;i < n;i++)
            scanf("%lf%lf%lf",&u[i],&v[i],&w[i]);
        for (int i = 0;i < n;i++)
        {
            linen = 0;
            InsertLine(1,0,0);
            InsertLine(0,1,0);
            InsertLine(-1,-1,1);
            for (int j = 0;j < n;j++)
                if (i != j)
                {
                    c = 1/w[j]-1/w[i];
                    a = 1/v[j]-1/v[i]-c;
                    b = 1/u[j]-1/u[i]-c;
                    bool flag = InsertLine(a,b,c);
                    if (flag == false)
                    {
                        linen = 0;
                        break;
                    }
                }
            HalfPlaneIntersection(line,linen,res,resn);
            if (CalcArea(res,resn) >= 1e-16)   printf("Yes\n");
            else printf("No\n");
        }
    }
}
