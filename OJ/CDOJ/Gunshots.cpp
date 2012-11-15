#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
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
    if (a.x == b.x) return a.y > b.y;
    return a.x < b.x;
}

void grahamScan(Point p[],int n,Point res[],int& resn)
{
    int top = 0;
    sort(p,p+n,grahamScanCmp);
    resn = 0;
    if (conPoint(p,n) == true)
    {
        res[resn++] = p[0];
        return;
    }
    if (conLine(p,n) == true)
    {
        res[resn++] = p[0];
        res[resn++] = p[n-1];
        return;
    }
    for (int i = 0; i < n;)
        if (resn < 2 || cmp(xmult(Point(res[resn-2],res[resn-1]),Point(res[resn-1],p[i])),0) > 0)
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

double CalcDis(Point a,Point b)
{
    return Point(a,b).Length();
}

double CalcDis(Point a,Point s,Point e)
{
    if (pmult(Point(s,e),Point(s,a)) < 0 || pmult(Point(e,s),Point(e,a)) < 0)
        return min(CalcDis(a,s),CalcDis(a,e));
    return abs(xmult(Point(a,s),Point(a,e)))/CalcDis(s,e);
}

int n,n0,n1,q[100],m,id;
Point p[100][1000],p0[1000],p1[1000],s,v;
double theta[100][1000];

bool check()
{
    int pl,pr;
    double tnow;
    double mindis = 1e100,nowdis;
    id = -1;
    for (int i = 0; i < n; i++)
    {
        tnow = atan2(v.y,v.x);
        if (cmp(tnow,theta[i][0]) < 0) tnow += 2*pi;
        pl = lower_bound(theta[i],theta[i]+q[i],tnow)-theta[i];
        tnow = atan2(-v.y,-v.x);
        if (cmp(tnow,theta[i][0]) < 0) tnow += 2*pi;
        pr = lower_bound(theta[i],theta[i]+q[i],tnow)-theta[i];
        //交点就在pl到pr这个区间和pr到pl这个区间（如果有交点）
        //cout << pl << ' ' << pr << endl;
        if (cmp(xmult(v,Point(s,p[i][pl%q[i]])),0)*cmp(xmult(v,Point(s,p[i][pr%q[i]])),0) > 0)
            continue;
        if (cmp(pmult(v,Point(s,p[i][pl%q[i]])),0) <= 0 &&
                cmp(pmult(v,Point(s,p[i][pr%q[i]])),0) <= 0)
            continue;
        nowdis = CalcDis(s,p[i][pl%q[i]],p[i][pr%q[i]]);
        //cout << i << ' ' << nowdis << ' ' << pl << ' ' << pr << endl;
        //cout << p[i][pl].x << ' ' << p[i][pl].y << ' ' << p[i][pr].x << ' ' << p[i][pr].y << endl;
        if (cmp(nowdis,mindis) < 0)
        {
            mindis = nowdis;
            id = i;
        }
    }
    return cmp(mindis,1e100) < 0;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1; ft <= t; ft++)
    {
        scanf("%d",&n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d",&n0);
            for (int j = 0; j < n0; j++)
                scanf("%lf%lf",&p0[j].x,&p0[j].y);
            grahamScan(p0,n0,p1,n1);
            for (int j = 0; j < n1; j++)
                p[i][j] = p1[j];
            q[i] = n1;
            for (int j = 0; j < q[i]; j++)
            {
                v = Point(p[i][j],p[i][(j+1)%q[i]]);
                theta[i][j] = atan2(v.y,v.x);
            }
            for (int j = 1; j < q[i]; j++)
                if (cmp(theta[i][j-1],theta[i][j]) > 0)
                    theta[i][j] += 2*pi;
            /*printf("ID = %d q[i] = %d\n",i,q[i]);
            for (int j = 0;j < q[i];j++)
                printf("%f %f theta = %f\n",p[i][j].x,p[i][j].y,theta[i][j]);*/
        }
        scanf("%d",&m);
        for (int i = 0; i < m; i++)
        {
            scanf("%lf%lf%lf%lf",&s.x,&s.y,&v.x,&v.y);
            if (check() == true)
                printf("HIT %d\n",id);
            else
                printf("MISS\n");
        }
        printf("*****\n");
    }
    return 0;
}
