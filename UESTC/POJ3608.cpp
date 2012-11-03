#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const double eps = 1e-6;
struct Point
{
    double x,y;
    Point(){}
    Point(double _x ,double _y)
        {
            x = _x;
            y = _y;
        }
    Point(Point a,Point b)
        {
            x = b.x-a.x;
            y = b.y-a.y;
        }
};
struct Line
{
    Point s,e;
    Line(){}
    Line(const Point & a ,const Point &b)
        {
            s = a;
            e = b;
        }
};

int n0,n1;
Point pa[1001],pb[1001];
double res;

inline double Xmult(Point a,Point b)
{
    return a.x*b.y-a.y*b.x;
}

inline double Xmult(Point a,Point b,Point c)
{
    return Xmult(Point(b.x-a.x,b.y-a.y),Point(c.x-a.x,c.y-a.y));
}

inline double Distance(Point a,Point b)
{
    return (sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y)));
}

inline double Distance(Point a,Line b) //点到线段
{
    Point t = a;
    t.x += b.s.y-b.e.y;
    t.y += b.e.x-b.s.x;
    if (Xmult(b.s,t,a)*Xmult(b.e,t,a) > eps)
        return min(Distance(a,b.s),Distance(a,b.e));
    return fabs(Xmult(a,b.e,b.s))/Distance(b.s,b.e);
}

inline double Distance(Line a,Line b) //平行线段
{
    return min(min(Distance(a.s,b),Distance(a.e,b)),min(Distance(b.s,a),Distance(b.e,a)));
}

void AntiPodal(Point a,Point b)
{
    if (res > Distance(a,b))    res = Distance(a,b);
}

void AntiPodal(Point a,Line b)
{
    if (res > Distance(a,b))    res = Distance(a,b);
}

void AntiPodal(Line a,Line b)
{
    if (res > Distance(a,b))    res = Distance(a,b);
}

void RotatingCalipers(Point pa[],Point pb[],int n0,int n1)
{
    int p0,p1,q0,q1,tp0,tp1;
    double xmult;
    Point v0,v1,now;
    p0 = p1 = 1;
    for (int i = 0;i < n0;i++)
        if ((pa[p0].y > pa[i].y) || ((pa[p0].y == pa[i].y) && (pa[p0].x > pa[i].x)))  p0 = i;
    for (int i = 0;i < n1;i++)
        if ((pb[p1].y < pb[i].y) || ((pb[p1].y == pb[i].y) && (pb[p1].x < pb[i].x)))  p1 = i;
    AntiPodal(pa[p0],pb[p1]);
    tp0 = p0;
    tp1 = p1;
    while (true)
    {
        q0 = (p0+1)%n0;
        q1 = (p1+1)%n1;
        v0 = Point(pa[q0].x-pa[p0].x,pa[q0].y-pa[p0].y);
        v1 = Point(pb[q1].x-pb[p1].x,pb[q1].y-pb[p1].y);
        xmult = Xmult(v0,v1);
        if (xmult < -eps)
        {
            //cout << "A" << endl;
            AntiPodal(pa[q0],pb[p1]);
            AntiPodal(pb[p1],Line(pa[p0],pa[q0]));
            p0 = q0;
        }
        else if (xmult > eps)
        {
            //cout << "B" << endl;
            AntiPodal(pa[p0],pb[q1]);
            AntiPodal(pa[p0],Line(pb[p1],pb[q1]));
            p1 = q1;
        }
        else
        {
            //cout << "C" << endl;
            AntiPodal(pa[p0],pb[q1]);
            AntiPodal(pa[q0],pb[p1]);
            AntiPodal(pa[q0],pb[q1]);
            AntiPodal(Line(pa[p0],pa[q0]),Line(pb[p1],pb[q1]));
            p0 = q0;
            p1 = q1;
        }
        if (p0 != tp0)  continue;
        if (p1 != tp1)  continue;
        break;
    }
}

bool GrahamScanCmp(Point p1,Point p2)
{
    if (p1.x == p2.x)   return p1.y > p2.y;
    else return p1.x > p2.x;
}

inline int is_left(Point a,Point b,Point c)
{
    Point p1,p2;
    p1 = Point(b.x-a.x,b.y-a.y);
    p2 = Point(c.x-b.x,c.y-b.y);
    return Xmult(p1,p2);
}

Point tp[1001];
int h[1001];

int GrahamScan(Point p[],int n)
{
    int top,sp = 0;
    for (int i = 0;i < n;i++)   tp[i] = p[i];
    sort(tp,tp+n,GrahamScanCmp);
    for (int i = 0;i < n;)
        if (sp < 2 || is_left(tp[h[sp-2]],tp[h[sp-1]],tp[i]) >= 0) h[sp++] = i++;
        else --sp;
    top = sp-1;
    for (int i = n-2;i >= 0;)
        if (sp < top+2 || is_left(tp[h[sp-2]],tp[h[sp-1]],tp[i]) >= 0)  h[sp++] = i--;
        else --sp;
    for (int i = 0;i < sp;i++)
        p[i] = tp[h[i]];
    return sp-1;
}

int main()
{
    while (scanf("%d%d",&n0,&n1) != EOF)
    {
        for (int i = 0;i < n0;i++)
            scanf("%lf%lf",&pa[i].x,&pa[i].y);
        for (int i = 0;i < n1;i++)
            scanf("%lf%lf",&pb[i].x,&pb[i].y);
        n0 = GrahamScan(pa,n0);
        n1 = GrahamScan(pb,n1);
        res = 1e15;
        if (n0 >= 3 && n1 >= 3)
        {
            RotatingCalipers(pa,pb,n0,n1);
            RotatingCalipers(pb,pa,n1,n0);
            printf("%.4f\n",res);
        }
        else
        {
            if (n0 == 1)
            {
                for (int i = 0;i < n1;i++)
                    if (res > Distance(pa[0],pb[i]))
                        res = Distance(pa[0],pb[i]);
                for (int i = 0;i < n1;i++)
                    if (res > Distance(pa[0],Line(pb[i],pb[(i+1)%n1])))
                        res = Distance(pa[0],Line(pb[i],pb[(i+1)%n1]));
            }
            else if (n0 == 2)
            {
                for (int i = 0;i < n0;i++)
                    for (int j = 0;j < n1;j++)
                        if (res > Distance(pa[i],pb[j]))
                            res = Distance(pa[i],pb[j]);
                for (int i = 0;i < n1;i++)
                    if (res > Distance(pb[i],Line(pa[0],pa[1])))
                        res = Distance(pb[i],Line(pa[0],pa[1]));
                for (int i = 0;i < n1;i++)
                    if (res > Distance(Line(pa[0],pa[1]),Line(pb[i],pb[(i+1)%n1])))
                        res = Distance(Line(pa[0],pa[1]),Line(pb[i],pb[(i+1)%n1]));
            }
            else if (n1 == 1)
            {
                for (int i = 0;i < n0;i++)
                    if (res > Distance(pb[0],pa[i]))
                        res = Distance(pb[0],pa[i]);
                for (int i = 0;i < n0;i++)
                    if (res > Distance(pb[0],Line(pa[i],pa[(i+1)%n0])))
                        res = Distance(pb[0],Line(pa[i],pa[(i+1)%n0]));
            }
            else if (n1 == 2)
            {
                for (int i = 0;i < n1;i++)
                    for (int j = 0;j < n0;j++)
                        if (res > Distance(pb[i],pa[j]))
                            res = Distance(pb[i],pa[j]);
                for (int i = 0;i < n0;i++)
                    if (res > Distance(pa[i],Line(pb[0],pb[1])))
                        res = Distance(pa[i],Line(pb[0],pb[1]));
                for (int i = 0;i < n0;i++)
                    if (res > Distance(Line(pb[0],pb[1]),Line(pa[i],pa[(i+1)%n0])))
                        res = Distance(Line(pb[0],pb[1]),Line(pa[i],pa[(i+1)%n0]));
            }
            printf("%.4f\n",res);
        }
    }
}
