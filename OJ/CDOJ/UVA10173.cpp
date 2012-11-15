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

bool grahamScanCmp(Point a,Point b)
{
    if (cmp(a.x,b.x) == 0)  return cmp(a.y,b.y) < 0;
    return cmp(a.x,b.x) < 0;
}

void grahamScan(Point p[],int n,Point res[],int& resn)
{
    resn = 0;
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
}

double solve(Point p[],int n)
{
    double res,dis1,dis2;
    Point v0,v1,v2;
    res = 1e100;
    int cur1,cur2,cur3;
    cur1 = cur2 = cur3 = 1;
    for (int i = 0;i < n;i++)
    {
        //基准向量
        v0 = Point(p[(i+1)%n],p[i]);
        v1 = Point(-v0.y,v0.x);
        v2 = Point(-v1.x,-v1.y);
        //确定剩下三个向量
        //与v1平行的对边
        while (cmp(xmult(v1,Point(p[cur1],p[(cur1+1)%n])),0) < 0)
            cur1 = (cur1+1)%n;
        //与v0平行的对边
        cur2 = max(cur2,cur1);
        while (cmp(xmult(v0,Point(p[cur2],p[(cur2+1)%n])),0) < 0)
            cur2 = (cur2+1)%n;
        //与v2平行的对边
        cur3 = max(cur3,cur2);
        while (cmp(xmult(v2,Point(p[cur3],p[(cur3+1)%n])),0) < 0)
            cur3 = (cur3+1)%n;

        dis1 = fabs(xmult(Point(p[i],p[cur1]),v1)/v1.Length());
        dis2 = fabs(xmult(Point(p[i],p[cur1]),v0)/v0.Length());
        res = min(res,dis1*dis2);

        cout << "-----------------" << endl;

        cout << "Find " << endl;
        cout << p[i].x << ' ' << p[i].y << ' ' << p[cur1].x << ' ' << p[cur1].y << endl;
        cout << p[cur2].x << ' ' << p[cur2].y << ' ' << p[cur3].x << ' ' << p[cur3].y << endl;
        cout << dis1 << ' ' << dis2 << endl;

        cout << "V = " << endl;
        cout << v0.x << ' ' << v0.y << ' ' << v1.x << ' ' << v1.y << endl;
        cout << v2.x << ' ' << v2.y << endl;
    }
    return res;
}

Point p[1001],tp[1001];
int n,tn;

int main()
{
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        for (int i = 0; i < n; i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        grahamScan(p,n,tp,tn);
        double ans;
        ans = solve(tp,tn);
        printf("%.4f\n",ans);
    }
    return 0;
}

