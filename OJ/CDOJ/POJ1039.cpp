#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int n;
struct point
{
    double x,y;
}p[50];
const double EPS = 1e-10;

double cross(point a,point b,point c)
{
    return ((b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y));
}

int dblcmp(double d)
{
    if (fabs(d) < EPS)
        return 0;
    return (d>0)?1:-1;
}

int segcross(point a,point b,point c,point d,point &p)
{
    double s1,s2,s3,s4;
    int d1,d2,d3,d4;
    s1 = cross(a,b,c);
    s2 = cross(a,b,d);
    s3 = cross(c,d,a);
    s4 = cross(c,d,b);
    d1 = dblcmp(s1);
    d2 = dblcmp(s2);
    d3 = dblcmp(s3);
    d4 = dblcmp(s4);
    if ((d1*d2 < 0) && (d3*d4) < 0)
    {
        p.x = (c.x*s2-d.x*s1)/(s2-s1);
        p.y = (c.y*s2-d.y*s1)/(s2-s1);
        return 1;
    }
    return 0;
}

double solve(point a,point b,int f)
{
    double res = p[1].x-1.0;
    double y0 = (b.y-a.y)*(p[1].x-a.x)/(b.x-a.x)+a.y;
    point tl,tr,tp;
    tl.x = p[1].x; tl.y = y0;
    double y1 = (b.y-a.y)*(p[n].x-a.x)/(b.x-a.x)+a.y;
    tr.x = p[n].x; tr.y = y1;
    for (int i = 1;i < f;i++)
    {
        double ty0 = (b.y-a.y)*(p[i].x-a.x)/(b.x-a.x)+a.y;
        double ty1 = (b.y-a.y)*(p[i+1].x-a.x)/(b.x-a.x)+a.y;
        if (ty0-EPS > p[i].y)   return res;
        if (ty0+EPS < p[n+i].y) return res;
        if (ty1-EPS > p[i+1].y)   return res;
        if (ty1+EPS < p[n+i+1].y) return res;
    }
    cout << "X" << endl;
    cout << tl.x << ' ' << tl.y << " and " << tr.x << ' ' << tr.y << endl;
    for (int i = f;i < n;i++)
    {
        double ty0 = (b.y-a.y)*(p[i].x-a.x)/(b.x-a.x)+a.y;
        double ty1 = (b.y-a.y)*(p[i+1].x-a.x)/(b.x-a.x)+a.y;
        if ((ty0-EPS > p[i].y) || (ty0+EPS < p[n+i].y))
            return res;
        if ((ty0-EPS > p[i+1].y) || (ty0+EPS < p[n+i+1].y))
        {
            point tp1,tp2;
            int res1 = segcross(tl,tr,p[i],p[i+1],tp1);
            int res2 = segcross(tl,tr,p[n+i],p[n+i+1],tp2);
            cout << p[i].x << ' ' << p[i].y << " and " << p[i+1].x << ' ' << p[i+1].y << ' ' << res1 << endl;
            cout << p[n+i].x << ' ' << p[n+i].y << " and " << p[n+i+1].x << ' ' << p[n+i+1].y << ' ' << res2 << endl;
            if (res2 == 1)
                return tp2.x;
            else if (res1 == 1)
                return tp1.x;
        }
    }
    cout << "XX" << endl;
    return p[n].x+1.0;
}

int main()
{
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        for (int i = 1;i <= n;i++)
        {
            scanf("%lf%lf",&p[i].x,&p[i].y);
            p[n+i].x = p[i].x;
            p[n+i].y = p[i].y-1.0;
        }
        double ans = p[1].x;
        for (int i = 1;i < n;i++)
            for (int j = i+1;j <= n;j++)
            {
                double res = solve(p[i],p[n+j],i);
                if (ans < res) ans = res;
                res = solve(p[n+i],p[j],i);
                if (ans < res) ans = res;
            }
        if (ans < p[n].x)
            printf("%.2lf\n",ans);
        else
            printf("Through all the pipe.\n");
    }
    return 0;
}
