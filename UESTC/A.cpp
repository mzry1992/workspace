#include <iostream>
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
    Point(Point _s,Point _e)
    {
        x = _e.x-_s.x;
        y = _e.y-_s.y;
    }
    double Length()
    {
        return x*x+y*y;
        //return sqrt(x*x+y*y);
    }
};
struct Line
{
    Point s,e;
    Line() {}
    Line(Point _s,Point _e)
    {
        s = _s;
        e = _e;
    }
};

Point r1[3],r2[3],v1,v2,xp,v;
Line l1,l2;

double xmult(Point a,Point b)
{
    return a.x*b.y-a.y*b.x;
}

double xmult(Line a,Line b)
{
    return xmult(Point(a.s,a.e),Point(b.s,b.e));
}

int cmp(double a,double b)
{
    if (fabs(a-b) < eps)    return 0;
    if (a < b)  return -1;
    return 1;
}

Point LineToLine(Line a,Line b)
{
    Point res = a.s;
    double t = ((a.s.x-b.s.x)*(b.s.y-b.e.y)-(a.s.y-b.s.y)*(b.s.x-b.e.x))/((a.s.x-a.e.x)*(b.s.y-b.e.y)-(a.s.y-a.e.y)*(b.s.x-b.e.x));
    res.x += (a.e.x-a.s.x)*t;
    res.y += (a.e.y-a.s.y)*t;
    return res;
}

bool OnSeg(Point a,Line b)
{
    if (cmp(xmult(Point(a,b.s),Point(a,b.e)),0.0) != 0)  return false;
    return (cmp(a.x,min(b.s.x,b.e.x)) >= 0 && cmp(max(b.s.x,b.e.x),a.x) >= 0 &&
            cmp(a.y,min(b.s.y,b.e.y)) >= 0 && cmp(max(b.s.y,b.e.y),a.y) >= 0);
}

void Gao(Point r1[3],Point r2[3],Point v1,Point v2,bool &flag,double &res)
{
    v.x = v1.x-v2.x;
    v.y = v1.y-v2.y;
    res = 1e100;
    flag = false;
    double speed = v.Length();
    if (cmp(speed,0.0) > 0)
    {
        for (int i = 0; i < 3; i++)
        {
            l1 = Line(r1[i],Point(r1[i].x+v.x,r1[i].y+v.y));
            double curmin = 1e100;
            bool tflag = false;
            for (int j = 0; j < 3; j++)
            {
                l2 = Line(r2[j],r2[(j+1)%3]);
                if (cmp(xmult(l1,l2),0.0) == 0) continue;
                xp = LineToLine(l1,l2);
                if (OnSeg(xp,l2) == false)  continue;
                //if (cmp(v.x,0.0) != 0)
                    if (cmp(Point(r1[i],xp).x*v.x,0.0) < 0)    continue;
                //if (cmp(v.y,0.0) != 0)
                    if (cmp(Point(r1[i],xp).y*v.y,0.0) < 0)    continue;
                curmin = min(curmin,Point(r1[i],xp).Length());
                tflag = true;
            }
            if (tflag == true)
            {
                res = min(res,curmin);
                flag = true;
            }
        }
        /*int aa[10],taa = 0;
        for (int i = 0;i < 3;i++)
        {
            l1 = Line(r1[i],Point(r1[i].x+v.x,r1[i].y+v.y));
            for (int j = 0;j < 3;j++)
                aa[taa++] = cmp(xmult(Point(r1[i],r2[j]),Point(l1.s,l1.e)),0.0);
        }
        bool flag1,flag2;
        flag1 = flag2 = false;
        for (int i = 0;i < taa;i++)
            if (aa[i] > 0)  flag1 = true;
            else if (aa[i] < 0) flag2 = true;
        if (flag1 == false || flag2 == false)   flag = false;*/
    }
    if (flag == true)
        res = sqrt(res/speed);
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1; ft <= t; ft++)
    {
        for (int i = 0; i < 3; i++)
            scanf("%lf%lf",&r1[i].x,&r1[i].y);
        scanf("%lf%lf",&v1.x,&v1.y);
        for (int i = 0; i < 3; i++)
            scanf("%lf%lf",&r2[i].x,&r2[i].y);
        scanf("%lf%lf",&v2.x,&v2.y);
        bool flag,flag1,flag2;
        double res,res1,res2;
        Gao(r1,r2,v1,v2,flag1,res1);
        Gao(r2,r1,v2,v1,flag2,res2);
        flag = flag1|flag2;
        res = min(res1,res2);
        if (flag == false)
            puts("NO COLLISION");
        else
            printf("%.9f\n",res);
    }
    return 0;
}
