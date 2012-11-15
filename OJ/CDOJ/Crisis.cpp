#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const double eps = 1e-8;
const double pi = acos(-1.0);

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
    void transXY(double B)
    {
        double tx = x,ty = y;
        x = tx*cos(B) - ty*sin(B);
        y = tx*sin(B) + ty*cos(B);
    }
    double Length()
    {
        return sqrt(eps+x*x+y*y);
    }
};

int cmp(double a,double b)
{
    if (fabs(a-b) < eps)    return 0;
    if (a < b)  return -1;
    return 1;
}

Point CenterOfPolygon(Point poly[],int n)
{
    Point p, p0, p1, p2, p3;
    double m, m0;

    p1 = poly[0];
    p2 = poly[1];
    p.x = p.y = m = 0;
    for (int i = 2; i < n; i++)
    {
        p3 = poly[i];
        p0.x = (p1.x + p2.x + p3.x) / 3.0;
        p0.y = (p1.y + p2.y + p3.y) / 3.0;
        m0 = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y - p1.y * p2.x - p2.y * p3.x - p3.y * p1.x;
        if (cmp(m + m0,0.0) == 0)
            m0 += eps;
        p.x = (m * p.x + m0 * p0.x) / (m + m0);
        p.y = (m * p.y + m0 * p0.y) / (m + m0);
        m = m + m0;
        p2 = p3;
    }
    return p;
}

bool EQ(Point a,Point b)
{
    return cmp(a.x,b.x) == 0 && cmp(a.y,b.y) == 0;
}

double xmult(Point a,Point b)
{
    return a.x*b.y-a.y*b.x;
}

bool conPoint(Point p[],int n)
{
    for (int i = 1; i < n; i++)
        if (EQ(p[i],p[0]) == false) return false;
    return true;
}

bool conLine(Point p[],int n)
{
    for (int i = 2; i < n; i++)
        if (cmp(xmult(Point(p[0],p[1]),Point(p[0],p[i])),0.0) != 0)  return false;
    return true;
}

bool GrahamScanCmp(Point a,Point b)
{
    if (cmp(a.x,b.x) == 0)  return cmp(a.y,b.y) > 0;
    return cmp(a.x,b.x) < 0;
}

void GrahamScan(Point p[],int n,Point res[],int& resn)
{
    resn = 0;
    if (n < 3 || conPoint(p,n) == true || conLine(p,n) == true) return;
    int top = 0;
    sort(p,p+n,GrahamScanCmp);
    for (int i = 0; i < n;)
        if (resn < 2 || cmp(xmult(Point(res[resn-2],res[resn-1]),Point(res[resn-1],p[i])),0.0) > 0)
            res[resn++] = p[i++];
        else
            --resn;
    top = resn-1;
    for (int i = n-2; i >= 0;)
        if (resn < top+2 || cmp(xmult(Point(res[resn-2],res[resn-1]),Point(res[resn-1],p[i])),0.0) > 0)
            res[resn++] = p[i--];
        else
            --resn;
    resn--;
    if (resn < 3)   resn = 0;
}

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

double xmult(Line a,Line b)
{
    return xmult(Point(a.s,a.e),Point(b.s,b.e));
}

bool HalfPlaneIntersectionCmp(Line a,Line b)
{
    if (fabs(a.k-b.k) > eps)    return a.k < b.k;
    return xmult(Point(b.s,a.s),Point(b.s,b.e)) < 0.0;
}

Point LineToLine(Line a,Line b)
{
    Point res = a.s;
    double t = ((a.s.x-b.s.x)*(b.s.y-b.e.y)-(a.s.y-b.s.y)*(b.s.x-b.e.x))/((a.s.x-a.e.x)*(b.s.y-b.e.y)-(a.s.y-a.e.y)*(b.s.x-b.e.x));
    res.x += (a.e.x-a.s.x)*t;
    res.y += (a.e.y-a.s.y)*t;
    return res;
}

void HalfPlaneIntersection(Line line[],int n,Point res[],int& resn)
{
    Line Q[150];
    int tot = n;
    sort(line,line+n,HalfPlaneIntersectionCmp);
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
        if ((fabs(xmult(Q[tail],Q[tail-1])) < eps) || (fabs(xmult(Q[head],Q[head+1])) < eps))   return;
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

Point LineToCircle(Line l,Point c,double r)
{
    Point tv = Point(l.s,l.e);
    Line tmp = Line(c,Point(c.x+tv.y,c.y-tv.x));
    Point near = LineToLine(l,tmp);
    //保证有交点了
    double A,B,C;
    A = Point(c,near).Length();
    C = r;
    B = sqrt(eps+C*C-A*A);
    tv = Point(l.s,near);
    double tvl = tv.Length();
    double nvl = tvl-B;
    return Point(l.s.x+nvl/tvl*tv.x,l.s.y+nvl/tvl*tv.y);
}

double re,thetar,thetas;
Point ps,pe,cent,tv,centnew,v1,v2,el,er;
int tn,n,timr,tims,tim,resn;
Point tp[100],p[100],resp[150];
Line l[150];
int linen;

int main()
{
    while (scanf("%lf%lf%lf%lf%lf",&ps.x,&ps.y,&pe.x,&pe.y,&re) != EOF)
    {
        scanf("%d%d%d%d",&tn,&timr,&tims,&tim);// 点数 公转 自转 爆发时间
        thetar = 2*pi*(double)(tim%timr)/(double)timr;
        thetas = 2*pi*(double)(tim%tims)/(double)tims;
        for (int i = 0; i < tn; i++)
            scanf("%lf%lf",&tp[i].x,&tp[i].y);
        cent = CenterOfPolygon(tp,tn);
        GrahamScan(tp,tn,p,n);
        tv = Point(pe,cent);
        tv.transXY(thetar);
        //cout << "Cent : " << cent.x << ' ' << cent.y << endl;
        centnew = Point(pe.x+tv.x,pe.y+tv.y); //公转
        //cout << "Cent after trans : " << centnew.x << ' ' << centnew.y << endl;
        for (int i = 0;i < n;i++) //自转
        {
            tv = Point(cent,p[i]);
            tv.transXY(thetas);
            p[i] = Point(centnew.x+tv.x,centnew.y+tv.y);
        }
        //cout << "After trans ; tot points = " << n << endl;
        //for (int i = 0;i < n;i++)
        //    cout << p[i].x << ' ' << p[i].y << endl;
        v1 = v2 = tv = Point(ps,pe);
        double A,B,C,theta;
        C = tv.Length();
        B = re;
        A = sqrt(eps+C*C-B*B);
        theta = atan2(B,A);
        v1.transXY(-theta);
        v2.transXY(theta);
        er = Point(ps.x+v1.x*A/C,ps.y+v1.y*A/C);
        el = Point(ps.x+v2.x*A/C,ps.y+v2.y*A/C);
        linen = 0;
        l[linen++] = Line(ps,er);
        l[linen++] = Line(er,el);
        l[linen++] = Line(el,ps);
        //cout << "border" << endl;
        //cout << el.x << ' ' << el.y << endl;
        //cout << er.x << ' ' << er.y << endl;
        for (int i = 0;i < n;i++)
            l[linen++] = Line(p[i],p[(i+1)%n]);
        HalfPlaneIntersection(l,linen,resp,resn);
        //cout << "Final poly --- points = " << resn << endl;
        //for (int i = 0;i < resn;i++)
        //    cout << resp[i].x << ' ' << resp[i].y << endl;
        theta = pi-2*theta;
        double res = re*theta;
        if (resn > 0)
        {
            Line bl,br,tmp;
            bl = br = Line(ps,resp[0]);
            for (int i = 0;i < resn;i++)
            {
                tmp = Line(ps,resp[i]);
                if (cmp(xmult(tmp,bl),0.0) > 0)
                    bl = tmp;
                if (cmp(xmult(tmp,br),0.0) < 0)
                    br = tmp;
            }
            //bl是被挡住的下边界 br是上边界，相对于逆时针
            Point xp1,xp2;
            xp1 = LineToCircle(bl,pe,re);
            xp2 = LineToCircle(br,pe,re);
            //cout << "border point : " << endl;
            //cout << xp1.x << ' ' << xp1.y << endl;
            //cout << xp2.x << ' ' << xp2.y << endl;
            A = atan2(Point(pe,xp1).y,Point(pe,xp1).x);
            B = atan2(Point(pe,xp2).y,Point(pe,xp2).x);
            if (cmp(A,0.0) < 0) A += 2*pi;
            if (cmp(B,0.0) < 0) B += 2*pi;
            if (cmp(A,2*pi) > 0) A -= 2*pi;
            if (cmp(B,2*pi) > 0) B -= 2*pi;
            theta = A-B;
            //cout << theta << endl;
            res -= re*theta;
        }
        printf("%.2f\n",res);
    }
    return 0;
}
