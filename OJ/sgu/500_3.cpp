#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const double pi = acos(-1.0);
const int MaxN = 50000;
struct Point
{
    long long x,y;
    Point() {}
    Point(long long _x,long long _y)
    {
        x = _x,y = _y;
    }
    Point operator -(const Point& b)const
    {
        return Point(x-b.x,y-b.y);
    }
    long long operator *(const Point& b)const
    {
        return x*b.y-y*b.x;
    }
    long long operator &(const Point& b)const
    {
        return x*b.x+y*b.y;
    }
};

struct Line
{
    Point s,e;
    Line() {}
    Line(Point _s,Point _e)
    {
        s = _s,e = _e;
    }
};

bool GScmp(Point a,Point b)
{
	if (a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}

bool conLine(Point p[],int n)
{
    for (int i = 2; i < n; i++)
        if ((p[1]-p[0])*(p[i]-p[0]) != 0)
            return false;
    return true;
}

void GS(Point p[],int n,Point res[],int &resn)
{
    resn = 0;
    int top = 0;
    sort(p,p+n,GScmp);

    if (n < 2)
    {
        res[resn++] = p[0];
        return;
    }

    if (conLine(p,n))
    {
        res[resn++] = p[0];
        res[resn++] = p[n-1];
        return;
    }

    for (int i = 0; i < n;)
        if (resn < 2 || (res[resn-1]-res[resn-2])*(p[i]-res[resn-1]) > 0)
            res[resn++] = p[i++];
        else
            --resn;
    top = resn-1;
    for (int i = n-2; i >= 0;)
        if (resn < top+2 || (res[resn-1]-res[resn-2])*(p[i]-res[resn-1]) > 0)
            res[resn++] = p[i--];
        else
            --resn;
    resn--;
}

double Norm(Point p)
{
    return sqrt(1.0*(p&p));
}
double NPT(Point P,Line L)
{
	return fabs(1.0*((P-L.s)*(L.e-L.s)))/Norm(L.s-L.e);
}

long long r;

double cut(Point a,Point b)
{
	if (a.x == b.x && a.y == b.y)
		return -1;

	double dis = NPT(Point(0,0),Line(a,b));
    double theta = acos(dis/r);
    double res;

    if ((b-a)*(Point(0,0)-a) <= 0)
        res = theta*r*r-dis*sqrt(r*r-dis*dis);
    else
        res = (pi-theta)*r*r+dis*sqrt(r*r-dis*dis);

    printf("a = (%lld, %lld), b = (%lld, %lld), res = %.8f\n",a.x,a.y,b.x,b.y,res);
    return res;
}

const double eps = 1e-8;
double theta[MaxN];
void Gettheta(Point p[],int n)
{
    for (int i = 0; i < n; i++)
    {

        Point v = p[(i+1)%n]-p[i];
        theta[i] = atan2(v.y,v.x);
    }
    for (int i = 1; i < n; i++)
        if (theta[i-1] > theta[i]+eps)
            theta[i] += 2*pi;
}

int Calc(Point s,Point p[],int n,int& pl,int& pr)
{
    Line l = Line(s,p[0]);
    double tnow;
    Point v = l.e-l.s;
    tnow = atan2(v.y,v.x);
    if (tnow < theta[0]-eps)	tnow += 2*pi;
    int tpl = lower_bound(theta,theta+n,tnow)-theta;
    tnow = atan2(-v.y,-v.x);
    if (tnow < theta[0]-eps)	tnow += 2*pi;
    int tpr = lower_bound(theta,theta+n,tnow)-theta;

    pl = tpl = tpl%n;
    pr = tpr = tpr%n;

    {
        while ((p[(pl+1)%n]-s)*(p[pl]-s) < 0)	pl = (pl+1)%n;
        while ((p[(pr-1+n)%n]-s)*(p[pr]-s) > 0)	pr = (pr-1+n)%n;
    }
}

double solve(Point pa[],int n,Point pb[],int m)
{
    Gettheta(pb,m);

    printf("==================\n");
    double res = 0;
    for (int i = 0; i < n; i++)
    {
        int pl,pr;
        Calc(pa[i],pb,m,pl,pr);

        //pa[i]->pb[pr]; pa[i+1]->pa[i]

        //pa[i]->pb[pl]; pa[i-1]->pa[i]
        printf("-------------------\n");
        printf("pa[i] = (%lld %lld)\n",pa[i].x,pa[i].y);
        printf("pl = (%lld %lld), pr = (%lld %lld)\n",pb[pl].x,pb[pl].y,pb[pr].x,pb[pr].y);

        if ((pb[pl]-pa[i])*(pa[(i+1)%n]-pa[i]) >= 0 &&
                (pb[pl]-pa[i])*(pa[(i+n-1)%n]-pa[i]) >= 0)
        {
            puts("pb[pl], pa[i]");
            res = max(res,cut(pb[pl],pa[i]));
        }

        if ((pb[pr]-pa[i])*(pa[(i+1)%n]-pa[i]) <= 0 &&
                (pb[pr]-pa[i])*(pa[(i+n-1)%n]-pa[i]) <= 0)
        {
            puts("pa[i], pb[pr]");
            res = max(res,cut(pa[i],pb[pr]));
        }

        if ((pa[(i+1)%n]-pa[i])*(pb[pl]-pa[i]) <= 0 &&
                (pa[(i+1)%n]-pa[i])*(pb[pr]-pa[i]) <= 0)
        {
            puts("pa[(i+1)%n], pa[i]");
            res = max(res,cut(pa[(i+1)%n],pa[i]));
        }

        if ((pa[(i-1+n)%n]-pa[i])*(pb[pl]-pa[i]) >= 0 &&
                (pa[(i-1+n)%n]-pa[i])*(pb[pr]-pa[i]) >= 0)
        {
            puts("pa[i], pa[(i-1+n)%n]");
            res = max(res,cut(pa[i],pa[(i-1+n)%n]));
        }

        Point pp = Point(pa[i].x-pa[i].y,pa[i].y+pa[i].x);
        if ((pp-pa[i])*(pa[(i+1)%n]-pa[i]) <= 0 &&
                (pp-pa[i])*(pa[(i+n-1)%n]-pa[i]) <= 0 &&
                (pp-pa[i])*(pb[pr]-pa[i]) >= 0 &&
                (pp-pa[i])*(pb[pl]-pa[i]) >= 0)
        {
            puts("pa[i], pp");
            res = max(res,cut(pa[i],pp));
        }
    }
    return res;
}

int n,m,tn;
Point pa[MaxN],pb[MaxN],tp[MaxN];

int main()
{
	//freopen("input","r",stdin);
    scanf("%lld",&r);

    scanf("%d",&tn);
    for (int i = 0; i < tn; i++)
        scanf("%lld%lld",&tp[i].x,&tp[i].y);
    GS(tp,tn,pa,n);

    scanf("%d",&tn);
    for (int i = 0; i < tn; i++)
        scanf("%lld%lld",&tp[i].x,&tp[i].y);
    GS(tp,tn,pb,m);

    /*scanf("%I64d",&r);

    scanf("%d",&tn);
    for (int i = 0; i < tn; i++)
        scanf("%I64d%I64d",&tp[i].x,&tp[i].y);
    GS(tp,tn,pa,n);

    scanf("%d",&tn);
    for (int i = 0; i < tn; i++)
        scanf("%I64d%I64d",&tp[i].x,&tp[i].y);
    GS(tp,tn,pb,m);*/

    //for (int i = 0;i < n;i++)
    //	printf("(%lld, %lld) ",pa[i].x,pa[i].y);
    //printf("\n");
    //for (int i = 0;i < m;i++)
    //	printf("(%lld, %lld) ",pb[i].x,pb[i].y);
    //printf("\n");

    double ans1 = solve(pa,n,pb,m);
    double ans2 = solve(pb,m,pa,n);

    //printf("%.10f %.10f\n",ans1,ans2);

    printf("%.10f %.10f\n",pi*r*r-ans1,ans2);

    return 0;
}
