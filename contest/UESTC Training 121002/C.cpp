#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const double eps = 1e-12;
struct Point
{
    double x,y;
    Point(){}
    Point(double _x,double _y)
    {
        x = _x,y = _y;
    }
    Point operator -(const Point &b)const
    {
        return Point(x-b.x,y-b.y);
    }
    double operator *(const Point &b)const
    {
        return x*b.y-y*b.x;
    }
    double operator &(const Point &b)const
    {
        return x*b.x+y*b.y;
    }
};

struct Line
{
    Point s,e;
    double k;
    Line(){}
    Line(Point _s,Point _e)
    {
        s = _s,e = _e;
    }
    Point operator &(const Line &b)const
    {
        Point res = s;
        double t = ((s-b.s)*(b.s-b.e))/((s-e)*(b.s-b.e));
        res.x += (e.x-s.x)*t;
        res.y += (e.y-s.y)*t;
        return res;
    }
};

bool GScmp(Point a,Point b)
{
    if (fabs(a.x-b.x) < eps)
        return a.y < b.y-eps;
    return a.x < b.x-eps;
}

void GS(Point p[],int n,Point res[],int &resn)
{
    resn = 0;
    int top = 0;
    sort(p,p+n,GScmp);
    for (int i = 0;i < n;)
        if (resn < 2 || (res[resn-1]-res[resn-2])*(p[i]-res[resn-1]) > eps)
            res[resn++] = p[i++];
        else
            --resn;
    top = resn-1;
    for (int i = n-2;i >= 0;)
        if (resn < top+2 || (res[resn-1]-res[resn-2])*(p[i]-res[resn-1]) > eps)
            res[resn++] = p[i--];
        else
            --resn;
    resn--;
    if (resn < 3)   resn = 0;
}

void solve(Point p[],int n,int res[])
{
    Point v;
    int cur = 1;
    for (int i = 0;i < n;i++)
    {
        v = p[i]-p[(i+1)%n];
        while (v*(p[(cur+1)%n]-p[cur]) < 0)
            cur = (cur+1)%n;
        //p[cur] -> p[i]
        //p[cur] -> p[i+1]

        //p[cur] -> (p[i],p[i+1])
        res[i] = cur;
    }
}

double CalcArea(Point p[],int n)
{
    double res = 0;
    for (int i = 0;i < n;i++)
        res += (p[i]*p[(i+1)%n])/2;
    return res;
}

Point p[1000],tp[1000],np[1000];
Line tl[4];
int anti[1000];
int n,tn;

int main()
{
	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
        scanf("%d",&tn);
        for (int i = 0;i < tn;i++)
            scanf("%lf%lf",&tp[i].x,&tp[i].y);
        GS(tp,tn,p,n);
        solve(p,n,anti);
        double res = 1e100;
        for (int i = 0;i < n;i++)
            for (int j = 0;j < n;j++)
            {
                Point va = p[(i+1)%n]-p[i];
                Point vb = p[(j+1)%n]-p[j];
                if (fabs(va*vb) < eps)  continue;

                tl[0] = Line(p[i],Point(p[i].x+va.x,p[i].y+va.y));
                tl[1] = Line(p[anti[i]],Point(p[anti[i]].x+va.x,p[anti[i]].y+va.y));
                tl[2] = Line(p[j],Point(p[j].x+vb.x,p[j].y+vb.y));
                tl[3] = Line(p[anti[j]],Point(p[anti[j]].x+vb.x,p[anti[j]].y+vb.y));

                tp[0] = tl[0]&tl[2];
                tp[1] = tl[0]&tl[3];
                tp[2] = tl[1]&tl[2];
                tp[3] = tl[1]&tl[3];

                GS(tp,4,np,tn);
                res = min(res,CalcArea(np,tn));
            }
        printf("Swarm %d Parallelogram Area: %.4f\n",cas,res);
	}
    return 0;
}

