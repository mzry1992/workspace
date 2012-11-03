#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const double pi = acos(-1.0);
const double eps = 1e-10;

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
    double len2()
    {
        return x*x+y*y;
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

bool gcmp(const Point& a,const Point& b)
{
    if (cmp(a.x,b.x) == 0)  return cmp(a.y,b.y) < 0;
    return cmp(a.x,b.x) < 0;
}

void gscan(Point p[],int n,Point res[],int& resn)
{
    resn = 0;
    int top = 0;
    sort(p,p+n,gcmp);
    for (int i = 0; i < n;)
        if (resn < 2 ||
                cmp(xmult(Point(res[resn-2],res[resn-1]),Point(res[resn-1],p[i])),0) > 0)
            res[resn++] = p[i++];
        else
            --resn;
    top = resn-1;
    for (int i = n-2; i >= 0;)
        if (resn < top+2 ||
                cmp(xmult(Point(res[resn-2],res[resn-1]),Point(res[resn-1],p[i])),0) > 0)
            res[resn++] = p[i--];
        else
            --resn;
    resn--;
    if (resn < 3)
        resn = 0;
}

double CalcTheta(Point a)
{
    return atan2(a.y,a.x);
}

double CalcDis(Point a)
{
    return sqrt(a.x*a.x+a.y*a.y);
}

Point p[300],s,cp[300],tp[300],tcp[300];
int n,cn,tn,tcn,cur;
double len[300],theta[300],pretheta,nowtheta,xtheta,res,nowrot,totlen;

void cross(Point o,double r,Point a,Point b,double &ra,double &rb)
{
    double r2 = r*r;
    Point d = Point(a,b),ao = Point(o,a);
    double A2 = 2.0*d.len2();
    double B = 2.0*pmult(ao,d);
    double C = ao.len2()-r2;
    double tk = B*B-2*A2*C;
    double k1 = 1e100,k2 = 1e100;
    bool fa = cmp(Point(o,a).len2(),r2) < 0;
    bool fb = cmp(Point(o,b).len2(),r2) < 0;
    ra = rb = 1e100;
    if (fa)
    {
        if (fb) return ;
        k1 = (sqrt(tk)-B) / A2;
    }
    else if (fb)
    {
        k1 = (-sqrt(tk)-B) / A2;
    }
    else
    {
        if (cmp(tk,0) >= 0)
        {
            k1 = (sqrt(tk)-B) / A2;
            k2 = (-sqrt(tk)-B) / A2;
        }
    }
    if (k1 < 1e100 / 2 && cmp(k1,0) >= 0 && cmp(k1,1.0) <= 0)
    {
        Point c = Point(a.x+d.x*k1,a.y+d.y*k1);
        ra = CalcTheta(Point(o,c));
    }
    if (k2 < 1e100 / 2 && cmp(k2,0) >= 0 && cmp(k2,1.0) <= 0)
    {
        Point c = Point(a.x+d.x*k2,a.y+d.y*k2);
        rb = CalcTheta(Point(o,c));
    }
}

double check(Point c,double mint,double maxt,double r)
{
    double res = 1e100,t[2];
    if (cmp(maxt,mint) < 0)
        maxt += 2*pi;
    for (int i = 0; i < n; i++)
    {
        cross(c,r,p[i],p[(i+1)%n],t[0],t[1]);
        for (int j = 0; j < 2; j++)
            if (cmp(t[j],1e50) < 0)
            {
                if (cmp(t[j],mint) < 0)
                    t[j] += 2*pi;
                if (cmp(t[j],maxt) <= 0)
                    res = min(res,t[j]-mint);
            }
    }
    return res;
}

double CalcTheta(double l,double r)
{
    if (cmp(r,l) < 0)
        r += 2*pi;
    return r-l;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out1.txt","w",stdout);
    int ft = 1;
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 0; i < n; i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        scanf("%lf%lf",&s.x,&s.y);
        tn = n;
        for (int i = 0; i < n; i++)
            tp[i] = p[i];
        gscan(tp,tn,tcp,tcn);
        for (int i = 0; i < tcn; i++)
            if (cmp(tcp[i].y,0) == 0)
            {
                cn = tcn;
                for (int j = 0; j < tcn; j++)
                    cp[j] = tcp[(i+j)%tcn];
                break;
            }
        totlen = 0;
        for (int i = 0; i < cn; i++)
        {
            len[i] = CalcDis(Point(cp[i],cp[(i+1)%cn]));
            theta[i] = CalcTheta(Point(cp[i],cp[(i+1)%cn]));
            totlen += len[i];
        }
        pretheta = 0;
        s.x = s.x-cp[0].x;
        cur = 0;
        res = 1e100;
        bool hasres = false;
        nowrot = 0;
        while (cmp(s.x+totlen,0) >= 0)
        {
            xtheta = CalcTheta(s);
            nowtheta = theta[cur];
            res = check(cp[cur],pretheta+xtheta,nowtheta+xtheta,CalcDis(s));
            if (cmp(res,1e50) < 0)
            {
                res += nowrot;
                hasres = true;
                break;
            }
            s.x -= len[cur];
            nowrot += CalcTheta(pretheta,nowtheta);
            pretheta = nowtheta;
            cur = (cur+1)%cn;
        }
        printf("Case %d: ",ft++);
        if (hasres == true)
            printf("%.2f\n",res*180.0/pi);
        else
            printf("Impossible\n");
    }
    return 0;
}
