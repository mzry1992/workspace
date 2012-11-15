#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const double eps = 1e-8;
const double pi = acos(-1.0);

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
    void transXY(double B)
    {
        double tx = x,ty = y;
        x = tx*cos(B) - ty*sin(B);
        y = tx*sin(B) + ty*cos(B);
    }
    double Length()
    {
        return sqrt(x*x+y*y);
    }
    double Length2()
    {
        return (x*x+y*y);
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

double CalcDis(Point a,Point b)
{
    return Point(a,b).Length();
}

double CalcDis2(Point a,Point b)
{
    return Point(a,b).Length2();
}

double CalcDis2(Point a,Point s,Point e)
{
    return xmult(Point(a,s),Point(a,e))*xmult(Point(a,s),Point(a,e))/CalcDis2(s,e);
}

bool conPoint(Point p[],int n)
{
    for (int i = 1; i < n; i++)
        if (cmp(p[i].x,p[0].x) != 0 ||
                cmp(p[i].y,p[0].y) != 0) return false;
    return true;
}

bool conLine(Point p[],int n)
{
    for (int i = 2; i < n; i++)
        if (cmp(xmult(Point(p[0],p[1]),Point(p[0],p[i])),0) != 0)  return false;
    return true;
}

bool grahamScanCmp(Point a,Point b)
{
    if (cmp(a.x,b.x) == 0)  return cmp(a.y,b.y) < 0;
    return cmp(a.x,b.x) < 0;
}

void grahamScan(Point p[],int n,Point res[],int& resn)
{
    resn = 0;
    if (n < 3 || conPoint(p,n) == true || conLine(p,n) == true) return;
    int top = 0;
    sort(p,p+n,grahamScanCmp);
    for (int i = 0; i < n;)
        if (resn < 2 || cmp(xmult(Point(res[resn-2],res[resn-1]),Point(res[resn-1],p[i])),0) > 0) //将等号去掉就是求不保留凸包边上的点
            res[resn++] = p[i++];
        else
            --resn;
    top = resn-1;
    for (int i = n-2; i >= 0;)
        if (resn < top+2 || cmp(xmult(Point(res[resn-2],res[resn-1]),Point(res[resn-1],p[i])),0) > 0)
            res[resn++] = p[i--];
        else
            --resn;
    resn--;
    if (resn < 3)   resn = 0;
}

int n,tn;
Point p[100],e,tp[100],yp[100];

Point NPT(Point P, Point s,Point e)
{
    Point result;
    double a, b, t;
    a = e.x - s.x;
    b = e.y - s.y;
    t = ( (P.x - s.x) * a + (P.y - s.y) * b ) / (a * a + b * b);
    result.x = s.x + a * t;
    result.y = s.y + b * t;
    return result;
}

bool OnSeg(Point s,Point e,Point b)
{
    return (cmp(xmult(Point(b,s),Point(b,e)),0) == 0 &&
            cmp((b.x-s.x)*(b.x-e.x),0) <= 0 &&
            cmp((b.y-s.y)*(b.y-e.y),0) <= 0);
}

bool Between(Point s,Point e,Point b)
{
    return cmp(xmult(b,s),0)*cmp(xmult(b,e),0) <= 0;
}

void findPoint(Point c,double r2,Point s,Point e,Point& xp1,Point& xp2)
{
    Point np = NPT(c,s,e),v = Point(s,e);
    double A2 = Point(c,np).Length2();
    double C2 = r2;
    double B2 = C2-A2;
    double D2 = v.Length2();
    xp1 = Point(np.x+v.x*sqrt(B2/D2),np.y+v.y*sqrt(B2/D2));
    xp2 = Point(np.x-v.x*sqrt(B2/D2),np.y-v.y*sqrt(B2/D2));
}

int main()
{
    int ft = 1;
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%lf%lf",&p[i].x,&p[i].y);
            yp[i] = p[i];
        }
        scanf("%lf%lf",&e.x,&e.y);
        grahamScan(yp,n,tp,tn);
        Point gr = Point(1,0),ngr,ves,vet,xp1,xp2;
        double t0,t1,tes,tmin,r2,nowx;
        int cur = 0;
        for (; cur < tn; cur++)
            if (cmp(tp[cur].y,0) == 0)  break;
        double res = 0;
        bool hasres = false;
        int tr;
        nowx = tp[cur].x;
        double totlen = 0;
        for (int i = 0;i < tn;i++)
            totlen += Point(tp[i],tp[(i+1)%tn]).Length();
        while (cmp(nowx-totlen-e.x,0) < 0)
        {
            ngr = Point(tp[cur],tp[(cur+1)%tn]);
            t0 = atan2(gr.y,gr.x);
            t1 = atan2(ngr.y,ngr.x);
            if (cmp(t1,t0) < 0) t1 += 2*pi;
            t0 = t1-t0;

            vet = ves = Point(e.x-nowx,e.y);
            vet.transXY(t0);

            tmin = 1e100;
            tes = atan2(ves.y,ves.x);

            r2 = ves.Length2();

            for (int i = 0; i < n; i++)
                if (cmp(CalcDis2(tp[cur],p[i],p[(i+1)%n]),r2) <= 0)
                {
                    findPoint(tp[cur],r2,p[i],p[(i+1)%n],xp1,xp2);
                    if (OnSeg(p[i],p[(i+1)%n],xp1) == true && Between(ves,vet,Point(tp[cur],xp1)) == true)
                    {
                        t1 = atan2(Point(tp[cur],xp1).y,Point(tp[cur],xp1).x);
                        if (cmp(t1,tes) < 0)    t1 += 2*pi;
                        tmin = min(tmin,t1-tes);
                    }
                    if (OnSeg(p[i],p[(i+1)%n],xp2) == true && Between(ves,vet,Point(tp[cur],xp2)) == true)
                    {
                        t1 = atan2(Point(tp[cur],xp2).y,Point(tp[cur],xp2).x);
                        if (cmp(t1,tes) < 0)    t1 += 2*pi;
                        tmin = min(tmin,t1-tes);
                    }
                }
            if (cmp(tmin,1e100) < 0)
            {
                res += tmin;
                hasres = true;
                break;
            }

            res += t0;
            nowx += Point(tp[cur],tp[(cur+1)%tn]).Length();
            cur = (cur+1)%tn;
            gr = ngr;

        }
        printf("Case %d: ",ft++);
        if (hasres == false)
            printf("Impossible\n");
        else
            printf("%.2f\n",180*res/pi);
    }
    return 0;
}
