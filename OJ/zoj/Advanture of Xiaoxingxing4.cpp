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
    double theta()
    {
        return atan2(y,x);
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

int n,tn,cur;
Point p[100],e,tp[100],yp[100];
double res,nowx,len[100],theta[100],totlen;
bool hasres;

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
        printf("Case %d: ",ft++);

        hasres = false;
        res = 0;
        for (cur = 0;cmp(tp[cur].y,0) != 0;cur++);
        nowx = tp[cur].x;
        for (int i = 0;i < tn;i++)
        {
            len[i] = Point(tp[i],tp[(i+1)%tn]).Length();
            theta[i] = Point(tp[i],tp[(i+1)%tn]).theta();
            totlen += len[i];
        }

        while (true)
        {

        }

        if (hasres == false)
            printf("Impossible\n");
        else
            printf("%.2f\n",180*res/pi);
    }
    return 0;
}

