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
    Point(){};
    Point(double _x,double _y)
    {
        x = _x;
        y = _y;
    }
    friend Point operator - (Point s,Point e)
    {
        return Point(s.x-e.x,s.y-e.y);
    }
    friend double operator * (Point a,Point b)
    {
        return a.x*b.y-a.y*b.x;
    }
    double length2()
    {
        return fabs(x*x+y*y);
    }
};

Point LineToLine(Point as,Point ae,Point bs,Point be,int& sta)
{
    Point res = as;
    if (cmp((as-ae)*(bs-be),0) == 0)
        sta = 0;
    else
        sta = 1;
    double t = ((as-bs)*(bs-be))/((as-ae)*(bs-be));
    res.x += (ae.x-as.x)*t;
    res.y += (ae.y-as.y)*t;
    return res;
}

int n,totl;
double res,lx,ly,len,wid,la,lb;
Point a[4],b[4],xp,l[10],tl[2];

bool lcmp(Point a,Point b)
{
    return cmp((a-l[0]).length2(),(b-l[0]).length2()) < 0;
}

bool OnSeg(Point as,Point ae,Point b)
{
    return (cmp((as-b)*(ae-b),0) == 0 &&
            cmp((b.x-as.x)*(b.x-ae.x),0) <= 0 &&
            cmp((b.y-as.y)*(b.y-ae.y),0) <= 0);
}

double calc(Point p[],Point s,Point e,int typ)
{
    Point mid = Point((s.x+e.x)/2,(s.y+e.y)/2);
    int c = 2;
    for (int i = 0; i < 4; i++)
        c = min(c,cmp((p[i]-mid)*(p[(i+1)%4]-mid),0));
    if (c >= 1-typ) return sqrt((s-e).length2());
    return 0;
}

double Gao(Point p[],int typ)
{
    l[0] = tl[0];
    l[1] = tl[1];
    int sta;
    totl = 2;
    for (int j = 0; j < 4; j++)
    {
        xp = LineToLine(l[0],l[1],p[j],p[(j+1)%4],sta);
        if (sta == 0)   continue;
        if (OnSeg(l[0],l[1],xp) == true && OnSeg(p[j],p[(j+1)%4],xp) == true)
            l[totl++] = xp;
    }
    sort(l+1,l+totl,lcmp);
    double res = 0;
    /*for (int i = 0;i < totl;i++)
        printf("(%.2f ,%.2f) ",l[i].x,l[i].y);
    printf("\n");*/
    for (int j = 1; j < totl; j++)
        res += calc(p,l[j-1],l[j],typ);
    return res;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1; ft <= t; ft++)
    {
        scanf("%lf%lf%lf%lf",&lx,&ly,&len,&wid);
        a[3] = Point(lx,ly);
        a[2] = Point(lx,ly+wid);
        a[1] = Point(lx+len,ly+wid);
        a[0] = Point(lx+len,ly);
        scanf("%lf%lf%lf%lf",&lx,&ly,&len,&wid);
        b[3] = Point(lx,ly);
        b[2] = Point(lx,ly+wid);
        b[1] = Point(lx+len,ly+wid);
        b[0] = Point(lx+len,ly);
        scanf("%d",&n);
        res = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%lf%lf%lf%lf",&tl[0].x,&tl[0].y,&tl[1].x,&tl[1].y);
            la = Gao(a,0);
            lb = Gao(b,1);
            //cout << la << ' ' << lb << endl;
            res += max(la,lb)-min(la,lb);
        }
        printf("Case #%d: %.2f\n",ft,res);
    }
    return 0;
}
