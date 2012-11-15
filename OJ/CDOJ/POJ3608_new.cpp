#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
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
    Point(Point _a,Point _b)
    {
        x = _b.x-_a.x;
        y = _b.y-_a.y;
    }
    double Length()
    {
        return sqrt(x*x+y*y);
    }
};

double xmult(Point a,Point b)
{
    return a.x*b.y-a.y*b.x;
}

double pmult(Point a,Point b)
{
    return a.x*b.x+a.y*b.y;
}

double CalcDis(Point a,Point b) //两点距离
{
    return Point(a,b).Length();
}

double CalcDis(Point a,Point s,Point e) //点到线段距离
{
    if (cmp(pmult(Point(s,e),Point(s,a)),0)< 0 || cmp(pmult(Point(e,s),Point(e,a)),0) < 0)
        return min(CalcDis(a,s),CalcDis(a,e));
    return abs(xmult(Point(a,s),Point(a,e)))/CalcDis(s,e);
}

double CalcDis(Point s0,Point e0,Point s1,Point e1) //平行线段距离
{
    return min(min(CalcDis(s0,s1,e1),CalcDis(e0,s1,e1)),
               min(CalcDis(s1,s0,e0),CalcDis(e1,s0,e0)));
}

double solve(Point p0[],int n,Point p1[],int m)
{
    double res,tres;
    Point v;
    res = 1e100;
    int cur = 0;
    for (int i = 0;i < n;i++)
    {
        v = Point(p0[(i+1)%n],p0[i]);
        while (cmp(xmult(v,Point(p1[cur],p1[(cur+1)%m])),0) < 0)
            cur = (cur+1)%m;
        //p[cur] 和 p[i] 、 p[cur] 和 p[i+1] 是对踵点
        res = min(res,CalcDis(p0[i],p1[cur]));
        res = min(res,CalcDis(p0[(i+1)%n],p1[cur]));
        //p[cur] 和 p[i]->p[i+1] 是点边对踵
        res = min(res,CalcDis(p1[cur],p0[i],p0[(i+1)%n]));
        //如果p[cur]->p[cur+1] 和 p[i]->p[i+1] 平行那么就是边边对踵了。
        if (cmp(xmult(v,Point(p1[cur],p1[(cur+1)%m])),0) == 0)
            res = min(res,CalcDis(p1[cur],p1[(cur+1)%m],p0[i],p0[(i+1)%n]));
    }
    return res;
}

Point p0[10000],p1[10000];
int n,m;

int main()
{
    while (true)
    {
        scanf("%d%d",&n,&m);
        if (n == 0 && m == 0) break;
        for (int i = 0; i < n; i++)
            scanf("%lf%lf",&p0[i].x,&p0[i].y);
        for (int i = 0; i < m; i++)
            scanf("%lf%lf",&p1[i].x,&p1[i].y);
        printf("%.6f\n",min(solve(p0,n,p1,m),solve(p1,m,p0,n)));
    }
    return 0;
}
