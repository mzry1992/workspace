#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const double eps = 1e-8;
struct Point
{
    double x,y;
    Point() {};
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
    void transXY(double cosB)
    {
        double tx = x,ty = y,sinB = sqrt(1-cosB*cosB);
        x = tx*cosB - ty*sinB;
        y = tx*sinB + ty*cosB;
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

int cmp(double a,double b)
{
    if (fabs(a-b) < eps)    return 0;
    if (a < b)  return -1;
    return 1;
}

bool EQ(Point a,Point b)
{
    return cmp(a.x,b.x) == 0 && cmp(a.y,b.y) == 0;
}

double xmult(Point a,Point b)
{
    return a.x*b.y-a.y*b.x;
}

double pmult(Point a,Point b)
{
    return a.x*b.x+a.y*b.y;
}

bool conPoint(Point p[],int n)
{
    for (int i = 1; i < n; i++)
        if (EQ(p[i],p[0]) == false) return false;
    return true;
}

bool conLine(Point p[],int n)
{
    for (int i = 2; i < n; i++)
        if (xmult(Point(p[0],p[1]),Point(p[0],p[i])) != 0)  return false;
    return true;
}

bool grahamScanCmp(Point a,Point b)
{
    if (a.x == b.x) return a.y > b.y;
    return a.x < b.x;
}

void grahamScan(Point p[],int n,Point res[],int& resn)
{
    resn = 0;
    if (n < 3 || conPoint(p,n) == true || conLine(p,n) == true) return;
    int top = 0;
    sort(p,p+n,grahamScanCmp);
    for (int i = 0; i < n;)
        if (resn < 2 || cmp(xmult(Point(res[resn-2],res[resn-1]),Point(res[resn-1],p[i])),0.0) > 0)
            res[resn++] = p[i++];
        else
            --resn;
    top = resn-1;
    for (int i = n-2; i >= 0;)
        if (resn < top+2 || cmp(xmult(Point(res[resn-2],res[resn-1]),Point(res[resn-1],p[i])),0.0) > 0)
            res[resn++] = p[i--];
        else
            --resn;
    resn--;
    if (resn < 3)   resn = 0;
}

double CalcArea(Point a,Point b,Point c)
{
    return xmult(Point(a,b),Point(a,c))/2.0;
}

double CalcArea(Point l[],int n)
{
    if (n < 3) return 0.0;
    double res = 0.0;
    for (int i = 2; i < n; i++)
        res += CalcArea(l[0],l[i-1],l[i]);
    return res;
}

Point LineToLine(Line a,Line b)
{
    Point res = a.s;
    double t = ((a.s.x-b.s.x)*(b.s.y-b.e.y)-(a.s.y-b.s.y)*(b.s.x-b.e.x))/((a.s.x-a.e.x)*(b.s.y-b.e.y)-(a.s.y-a.e.y)*(b.s.x-b.e.x));
    res.x += (a.e.x-a.s.x)*t;
    res.y += (a.e.y-a.s.y)*t;
    return res;
}

double BoundingRectangle(Point c[],int id[],Point v[])
{
    Point p[4];
    for (int i = 0; i < 4; i++)
        p[i] = LineToLine(Line(c[id[i]],Point(c[id[i]].x+v[i].x,c[id[i]].y+v[i].y)),
                          Line(c[id[(i+1)%4]],Point(c[id[(i+1)%4]].x+v[(i+1)%4].x,c[id[(i+1)%4]].y+v[(i+1)%4].y)));

    cout << "BoundingRectangle" << endl;
    cout << "Id : ";
    for (int i = 0;i < 4;i++)
        cout << id[i] << ' ';
    cout << endl;
    for (int i = 0;i < 4;i++)
        cout << p[i].x << ' ' << p[i].y << endl;
    return CalcArea(p,4);
}

double SmallestBoundingRectangle(Point p[],int n)
{
    if (n < 3)  return 0.0;
    Point v[4];
    int id[4];
    v[0] = Point(1,0);
    v[1] = Point(0,1);
    v[2] = Point(-1,0);
    v[3] = Point(0,-1);
    id[0] = id[1] = id[2] = id[3] = 0;
    for (int i = 0; i < n; i++)
    {
        if (cmp(p[i].y,p[id[0]].y) < 0) id[0] = i;
        if (cmp(p[i].x,p[id[1]].x) > 0) id[1] = i;
        if (cmp(p[i].y,p[id[2]].y) > 0) id[2] = i;
        if (cmp(p[i].x,p[id[3]].x) < 0) id[3] = i;
    }
    double theta[4],maxtheta;
    double res = BoundingRectangle(p,id,v);
    for (int i = 0; i < n; i++)
    {
        //cos()
        for (int j = 0; j < 4; j++)
            theta[j] = pmult(Point(p[id[j]],p[(id[j]+1)%n]),v[j])/Point(p[id[j]],p[(id[j]+1)%n]).Length();
        maxtheta = theta[0];
        for (int j = 1; j < 4; j++)
            maxtheta = max(maxtheta,theta[0]);
        for (int j = 0; j < 4; j++)
            v[j].transXY(maxtheta);
        for (int j = 0; j < 4; j++)
            if (cmp(maxtheta,theta[j]) == 0)
            {
                cout << "Maxtheta = " << maxtheta << endl;
                id[j] = (id[j]+1)%n;
                break;
            }
        res = min(res,BoundingRectangle(p,id,v));
    }
    return res;
}

int n,newn,tpn;
Point p[1001],tp[1001];

int main()
{
    while (true)
    {
        scanf("%d",&tpn);
        if (tpn == 0)   break;
        for (int i = 0; i < tpn; i++)   scanf("%lf%lf",&tp[i].x,&tp[i].y);
        grahamScan(tp,tpn,p,n);
        printf("%.4f\n",SmallestBoundingRectangle(p,n));
    }
    return 0;
}
