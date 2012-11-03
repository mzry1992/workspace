#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const double eps = 1e-12;
const double pi = acos(-1.0);

int cmp(double a,double b)
{
    if (fabs(a-b) < eps)    return 0;
    if (a < b)  return -1;
    return 1;
}

struct Point
{
    double x,y,z;
    Point() {}
    Point(double _x,double _y,double _z)
    {
        x = _x;
        y = _y;
        z = _z;
    }
    Point(Point _s,Point _e)
    {
        x = _e.x-_s.x;
        y = _e.y-_s.y;
        z = _e.z-_s.z;
    }
    void transXY(double B)
    {
        double tx = x,ty = y;
        x = tx*cos(B) - ty*sin(B);
        y = tx*sin(B) + ty*cos(B);
    }
    void transYZ(double B)
    {
        double ty = y,tz = z;
        y = ty*cos(B) - tz*sin(B);
        z = ty*sin(B) + tz*cos(B);
    }
};

double xmult(Point a,Point b)
{
    return a.x*b.y-a.y*b.x;
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

double a,b,c,d;
Point p[100],light,tp[100];
int n;

int main()
{
    while (true)
    {
        scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
        if (cmp(a,0) == 0 && cmp(b,0) == 0 && cmp(c,0) == 0 && cmp(d,0) == 0)   break;
        scanf("%d",&n);
        for (int i = 0; i < n; i++)
            scanf("%lf%lf%lf",&p[i].x,&p[i].y,&p[i].z);
        scanf("%lf%lf%lf",&light.x,&light.y,&light.z);

        if (cmp(a,0) != 0)
        {
            for (int i = 0; i < n; i++)
                p[i].x -= d/a;
            light.x -= d/a;
        }
        else if (cmp(b,0) != 0)
        {
            for (int i = 0; i < n; i++)
                p[i].y -= d/b;
            light.y -= d/b;
        }
        else if (cmp(c,0) != 0)
        {
            for (int i = 0; i < n; i++)
                p[i].z -= d/c;
            light.z -= d/c;
        }

        if (cmp(a,0) != 0 || cmp(b,0) != 0)
        {
            Point v = Point(a,b,c);
            double theta = pi/2-atan2(v.y,v.x);
            for (int i = 0; i < n; i++)
                p[i].transXY(theta);
            light.transXY(theta);
            v.transXY(theta);
            //cout << "V0 = " << v.x << ' ' << v.y << ' ' << v.z << endl;
            theta = pi/2-atan2(v.z,v.y);
            for (int i = 0; i < n; i++)
                p[i].transYZ(theta);
            light.transYZ(theta);
            v.transYZ(theta);
            //cout << "V1 = " << v.x << ' ' << v.y << ' ' << v.z << endl;
        }
        if (cmp(light.z,0) < 0)
        {
            for (int i = 0; i < n; i++)
                p[i].z = -p[i].z;
            light.z = -light.z;
        }
        int f=0;
        for (int i = 0; i < n; i++)
            if (cmp(p[i].z,light.z) >= 0)    f++;
        if (f == n)
        {
            puts("0.00");
            continue;
        }
        if(f > 0)
        {
            puts("Infi");
            continue;
        }
        Point vl;
        for (int i = 0; i < n; i++)
        {
            vl = Point(light,p[i]);
            double k = -p[i].z/vl.z;
            tp[i] = Point(p[i].x+k*vl.x,p[i].y+k*vl.y,0);
        }
        int tn;
        grahamScan(tp,n,p,tn);
        printf("%.2f\n",CalcArea(p,tn));
    }
    return 0;
}
