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

double CalcDis(Point a,Point s,Point e)
{
    return fabs(xmult(Point(a,s),Point(a,e)))/CalcDis(s,e);
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

double findtheta(Point c,double r,Point s,Point e)
{
    Point mid;
    if (cmp(CalcDis(c,s),CalcDis(c,e)) > 0)
        swap(s,e);
    for (int i = 0;i < 500;i++)
    {
        mid = Point((s.x+e.x)/2,(s.y+e.y)/2);
        if (cmp(CalcDis(c,mid),r) < 0)
            s = mid;
        else
            e = mid;
    }
    return atan2(Point(c,s).y,Point(c,s).x);
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
        Point gr = Point(1,0),ngr,ves,vet;
        double t0,t1,tes,tet,tmin,r;
        int cur = 0;
        for (; cur < tn; cur++)
            if (cmp(xmult(gr,Point(tp[cur],tp[(cur+1)%tn])),0) > 0)
                break;
        double res = 0;
        bool hasres = false;
        int tr;
        while (true)
        {
            ngr = Point(tp[cur],tp[(cur+1)%tn]);
            vet = ves = Point(tp[cur],e);
            t0 = atan2(gr.y,gr.x);
            t1 = atan2(ngr.y,ngr.x);
            if (cmp(t1,t0) < 0) t1 += 2*pi;
            t0 = t1-t0;
            vet.transXY(t0);
            //判断碰到了
            //以tp[cur]为圆心，ves的模长为半径做圆，判断ves到vet这一段圆弧与多边形是否有交点，如果有那么答案就是最早的那个交点>_<
            tmin = 1e100;
            tes = atan2(ves.y,ves.x);
            tet = atan2(vet.y,vet.x);
            if (cmp(tet,tes) < 0)   tet += 2*pi;
            r = ves.Length();
            for (int i = 0; i < n; i++)
                if (cmp(CalcDis(tp[cur],p[i]),r)*cmp(CalcDis(tp[cur],p[(i+1)%n]),r) <= 0)
                {
                    t1 = findtheta(tp[cur],r,p[i],p[(i+1)%n]);
                    if (cmp(t1,tes) < 0)    t1 += 2*pi;
                    if (cmp(t1,tet) > 0)    continue;
                    //cout << tp[cur].x << ' ' << tp[cur].y << ' ' << r << ' ' << i << endl;
                    //cout << p[i].x << ' ' << p[i].y << ' ' << p[(i+1)%n].x << ' ' << p[(i+1)%n].y << endl;
                    //cout << t1 << ' ' << tes << ' ' << tet << endl;
                    tmin = min(tmin,t1-tes);
                }
            if (cmp(tmin,1e100) < 0)
            {
                //碰到了
                //cout << res/pi*180 << ' ' << tmin/pi*180 << endl;
                res += tmin;
                hasres = true;
                break;
            }
            //判断已经滚过头了
            tr = 0;
            for (int i = 0; i < tn; i++)
                if (cmp(pmult(gr,Point(e,tp[i])),0) > 0)
                    tr++;
            if (tr == tn)
            {
                hasres = false;
                break;
            }
            //没有交点而且还没滚过头那么继续滚
            res += t0;
            e = Point(tp[cur].x+vet.x,tp[cur].y+vet.y);
            cur = (cur+1)%tn;
            gr = ngr;
        }
        printf("Case %d: ",ft++);
        if (hasres == false)
            printf("Impossible\n");
        else
            printf("%.2f\n",res/pi*180);
    }
    return 0;
}
