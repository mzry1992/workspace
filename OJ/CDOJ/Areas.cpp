#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
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
struct Line
{
    Point s,e;
    double k;
    Line() {}
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

bool HPICmp(Line a,Line b)
{
    if (cmp(a.k,b.k) == 0)
        return cmp(xmult(Point(b.s,a.s),Point(b.s,b.e)),0) < 0;
    return cmp(a.k,b.k) < 0;
}

Point LineToLine(Line a,Line b)
{
    Point res = a.s;
    double t =
        ((a.s.x-b.s.x)*(b.s.y-b.e.y)-(a.s.y-b.s.y)*(b.s.x-b.e.x))/
        ((a.s.x-a.e.x)*(b.s.y-b.e.y)-(a.s.y-a.e.y)*(b.s.x-b.e.x));
    res.x += (a.e.x-a.s.x)*t;
    res.y += (a.e.y-a.s.y)*t;
    return res;
}

void HPI(Line line[],int n,Point res[],int& resn)
{
    Line Q[100];
    int tot = n;
    sort(line,line+n,HPICmp);
    tot = 1;
    for (int i = 1; i < n; i++)
        if (cmp(line[i].k,line[i-1].k) != 0)
            line[tot++] = line[i];
    int head,tail;
    head = 0;
    tail = 1;
    Q[0] = line[0];
    Q[1] = line[1];
    resn = 0;
    for (int i = 2; i < tot; i++)
    {
        if (cmp(xmult(Q[tail],Q[tail-1]),0) == 0 ||
                cmp(xmult(Q[head],Q[head+1]),0) == 0)   return;
        while (head < tail &&
                cmp(xmult(Point(line[i].s,LineToLine(Q[tail],Q[tail-1])),Point(line[i].s,line[i].e)),0) > 0)
            tail--;
        while (head < tail &&
                cmp(xmult(Point(line[i].s,LineToLine(Q[head],Q[head+1])),Point(line[i].s,line[i].e)),0) > 0)
            head++;
        tail++;
        Q[tail] = line[i];
    }
    while (head < tail &&
            cmp(xmult(Point(Q[head].s,LineToLine(Q[tail],Q[tail-1])),Point(Q[head].s,Q[head].e)),0) > 0)
        tail--;
    while (head < tail &&
            cmp(xmult(Point(Q[tail].s,LineToLine(Q[head],Q[head+1])),Point(Q[tail].s,Q[tail].e)),0) > 0)
        head++;
    if (tail <= head+1) return;
    for (int i = head; i < tail; i++)
        res[resn++] = LineToLine(Q[i],Q[i+1]);
    if (head < tail+1)
        res[resn++] = LineToLine(Q[head],Q[tail]);
    tot = resn;
    resn = 1;
    for (int i = 1;i < tot;i++)
        if (cmp(res[i].x,res[resn-1].x) != 0 || cmp(res[i].y,res[resn-1].y) != 0)
            res[resn++] = res[i];
    while (resn > 0 && cmp(res[0].x,res[resn-1].x) == 0 && cmp(res[0].y,res[resn-1].y) == 0)
        resn--;
}

int n,m;
double L,W;
Line cutl[100];
vector<Point> tmp,poly[7000];
int totpol;

void Gao(vector<Point> p,int cid)
{
    /*cout << "Gao : " << p.size() << " " << cid << endl;
    for (int i = 0;i < p.size();i++)
        cout << p[i].x << ", " << p[i].y << " | ";
    cout << endl;*/
    int pn = p.size();
    if (cid > n)
    {
        poly[totpol].resize(pn);
        for (int i = 0; i < pn; i++)
            poly[totpol][i] = p[i];
        totpol++;
        return;
    }
    int ma,mb,tmp;
    ma = mb = 0;
    for (int i = 0; i < pn; i++)
    {
        tmp = cmp(xmult(Point(cutl[cid].s,p[i]),Point(cutl[cid].s,cutl[cid].e)),0);
        if (tmp > 0)
            ma++;
        else if (tmp < 0)
            mb++;
    }
    if (ma == 0 || mb == 0)
        Gao(p,cid+1);
    else
    {
        Point p1[100];
        vector<Point> p3;

        Line l[100];
        int totl,tp1;

        totl = 0;
        for (int i = 0; i < pn; i++)
            l[totl++] = Line(p[i],p[(i+1)%pn]);
        l[totl++] = Line(cutl[cid].s,cutl[cid].e);
        HPI(l,totl,p1,tp1);
        p3.resize(tp1);
        for (int i = 0; i < tp1; i++)
            p3[i] = p1[i];
        Gao(p3,cid+1);
        totl = 0;
        for (int i = 0; i < pn; i++)
            l[totl++] = Line(p[i],p[(i+1)%pn]);
        l[totl++] = Line(cutl[cid].e,cutl[cid].s);
        HPI(l,totl,p1,tp1);
        p3.resize(tp1);
        for (int i = 0; i < tp1; i++)
            p3[i] = p1[i];
        Gao(p3,cid+1);
    }
}
Point c;
double r,area[7000];
double res[7000];
int totres;

double CalcArea(Point a,Point b,Point c)
{
    return xmult(Point(a,b),Point(a,c))/2.0;
}

double CalcArea(vector<Point> l)
{
    int n = l.size();
    if (n < 3) return 0.0;
    double res = 0.0;
    for (int i = 2; i < n; i++)
        res += CalcArea(l[0],l[i-1],l[i]);
    return res;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        for (int i = 0; i < n; i++)
            scanf("%lf%lf%lf%lf",&cutl[i].s.x,&cutl[i].s.y,&cutl[i].e.x,&cutl[i].e.y);
        tmp.resize(4);
        tmp[0] = Point(-1e5,-1e5);
        tmp[1] = Point(1e5,-1e5);
        tmp[2] = Point(1e5,1e5);
        tmp[3] = Point(-1e5,1e5);
        totpol = 0;
        Gao(tmp,0);
        for (int i = 0; i < totpol; i++)
            area[i] = CalcArea(poly[i]);
    }
    return 0;
}