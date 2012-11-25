#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const double eps = 1e-12;

struct Point
{
    double x,y;
    Point(){}
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
};

struct Line
{
    Point s,e;
    double k;
    Line(){}
    Line(Point _s,Point _e)
    {
        s = _s;
        e = _e;
        k = atan2(e.y-s.y,e.x-s.x);
    }
};

double xmult(Point a,Point b)
{
    return a.x*b.y-a.y*b.x;
}

double xmult(Line a,Line b)
{
    return xmult(Point(a.s,a.e),Point(b.s,b.e));
}

bool HPIcmp(Line a,Line b)
{
    if (fabs(a.k-b.k) > eps)    return a.k < b.k;
    return xmult(Point(b.s,a.s),Point(b.s,b.e)) < 0;
}

Point LineToLine(Line a,Line b)
{
    Point res = a.s;
    double t = ((a.s.x-b.s.x)*(b.s.y-b.e.y)-(a.s.y-b.s.y)*(b.s.x-b.e.x))/((a.s.x-a.e.x)*(b.s.y-b.e.y)-(a.s.y-a.e.y)*(b.s.x-b.e.x));
    res.x += (a.e.x-a.s.x)*t;
    res.y += (a.e.y-a.s.y)*t;
    return res;
}

void HPI(Line line[],int n,Point res[],int &resn)
{
    Line Q[100];
    int tot = n;
    sort(line,line+n,HPIcmp);
    tot = 1;
    for (int i = 1;i < n;i++)
        if (fabs(line[i].k-line[i-1].k) > eps)
            line[tot++] = line[i];
    int head,tail;
    head = 0;
    tail = 1;
    Q[0] = line[0];
    Q[1] = line[1];
    resn = 0;
    for (int i = 2;i < tot;i++)
    {
        if ((fabs(xmult(Q[tail],Q[tail-1])) < eps) ||
            (fabs(xmult(Q[head],Q[head+1])) < eps))
                return;
        while (head < tail && xmult(Point(line[i].s,LineToLine(Q[tail],Q[tail-1])),Point(line[i].s,line[i].e)) > eps)
            tail--;
        while (head < tail && xmult(Point(line[i].s,LineToLine(Q[head],Q[head+1])),Point(line[i].s,line[i].e)) > eps)
            head++;
        tail++;
        Q[tail] = line[i];
    }
    while (head < tail && xmult(Point(Q[head].s,LineToLine(Q[tail],Q[tail-1])),Point(Q[head].s,Q[head].e)) > eps)
        tail--;
    while (head < tail && xmult(Point(Q[tail].s,LineToLine(Q[head],Q[head+1])),Point(Q[tail].s,Q[tail].e)) > eps)
        head++;
    if (tail <= head+1) return;
    for (int i = head;i < tail;i++)
        res[resn++] = LineToLine(Q[i],Q[i+1]);
    if (head < tail+1)
        res[resn++] = LineToLine(Q[head],Q[tail]);
}

int cmp(double a,double b)
{
    if (fabs(a-b) < eps)    return 0;
    if (a < b)  return -1;
    return 1;
}

bool GScmp(Point a,Point b)
{
    if (cmp(a.x,b.x) == 0)
        return cmp(a.y,b.y) < 0;
    return cmp(a.x,b.x) < 0;
}

void GS(Point p[],int n,Point res[],int& resn)
{
    resn = 0;
    int top = 0;
    sort(p,p+n,GScmp);
    for (int i = 0;i < n;)
        if (resn < 2 || cmp(xmult(Point(res[resn-2],res[resn-1]),Point(res[resn-1],p[i])),0) > 0)
            res[resn++] = p[i++];
        else
            --resn;
    top = resn-1;
    for (int i = n-2;i >= 0;)
        if (resn < top+2 || cmp(xmult(Point(res[resn-2],res[resn-1]),Point(res[resn-1],p[i])),0) > 0)
            res[resn++] = p[i--];
        else
            --resn;
    resn--;
    if (resn < 3)   resn = 0;
}

double CalcArea(Point a,Point b,Point c)
{
    return xmult(Point(a,b),Point(a,c))/2;
}

double CalcArea(Point l[],int n)
{
    if (n < 3)  return 0;
    double res = 0;
    for (int i = 2;i < n;i++)
        res += CalcArea(l[0],l[i-1],l[i]);
    return res;
}

double r0,r1;
int n,pn[30];
Point p[30][30],tp[30],vp[30];

double dist(Point a,Point b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

double dist(Point p1,Point p2,Point p)
{
    Point res;
    double a,b,t;
    a = p2.x-p1.x;
    b = p2.y-p1.y;
    t = ((p.x-p1.x)*a+(p.y-p1.y)*b)/(a*a+b*b);
    if (t >= 0 && t <= 1)
    {
        res.x = p1.x+a*t;
        res.y = p1.y+b*t;
    }
    else
    {
        if (dist(p,p1) < dist(p,p2))
            res = p1;
        else
            res = p2;
    }
    return dist(p,res);
}

Line line[100];

bool check1(Point a,Point b,double r)
{
    Point v = Point(a,b);
    Point pv = Point(v.y,-v.x);
    double len = sqrt(dist(Point(0,0),pv));
    pv = Point(pv.x*r/len,pv.y*r/len);
    int tn = 0;
    tp[tn++] = Point(a.x+pv.x,a.y+pv.y);
    tp[tn++] = Point(a.x-pv.x,a.y-pv.y);
    tp[tn++] = Point(b.x+pv.x,b.y+pv.y);
    tp[tn++] = Point(b.x-pv.x,b.y-pv.y);
    int ttn = 0;
    GS(tp,tn,vp,ttn);
    for (int i = 0;i < n;i++)
    {
        int totline = 0;
        for (int j = 0;j < ttn;j++)
            line[totline++] = Line(vp[j],vp[(j+1)%ttn]);
        for (int j = 0;j < pn[i];j++)
            line[totline++] = Line(p[i][j],p[i][(j+1)%pn[i]]);
        HPI(line,totline,tp,tn);
        if (CalcArea(tp,tn) > eps)  return false;
    }
    return true;
}

bool check2(Point a,double r)
{
    for (int i = 0;i < n;i++)
        for (int j = 0;j < pn[i];j++)
            if (dist(p[i][j],p[i][(j+1)%pn[i]],a) < r*r)
                return false;
    return true;
}

int main()
{
    while (true)
    {
        scanf("%lf%lf%d",&r0,&r1,&n);
        if (n == 0)
            break;
        for (int i = 0;i <= n;i++)
        {
            scanf("%d",&pn[i]);
            for (int j = 0;j < pn[i];j++)
                scanf("%lf%lf",&tp[j].x,&tp[j].y);
            if (i < n)
            {
                int tn = pn[i];
                GS(tp,tn,p[i],pn[i]);
            }
            else
                for (int j = 0;j < pn[i];j++)
                    p[i][j] = tp[j];
        }
        for (int i = 1;i < pn[n];i++)
        {
            double l = 0,r = r1,mid;
            for (int tim = 0;tim < 100;tim++)
            {
                mid = (l+r)/2;
                if (check1(p[n][i-1],p[n][i],mid) && check2(p[n][i-1],mid) && check2(p[n][i],mid))
                    l = mid;
                else
                    r = mid;
            }
            if (l < r0) l = 0;
            if (i > 1)
                printf(" ");
            printf("%.0f",round(l));
        }
        printf("\n");
    }
	return 0;
}
