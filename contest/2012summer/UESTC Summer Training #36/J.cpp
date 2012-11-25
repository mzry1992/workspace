#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

//const double eps = 1e-12;
const double pi = acos(-1.0);

int cmp(double a,double b)
{
    if (a == b) return 0;
    if (a < b)  return -1;
    return 1;
//    if (fabs(a-b) < eps)    return 0;
//    if (a < b)  return -1;
//    return 1;
}

struct Point
{
    double x,y;
    Point(){}
    Point(double _x,double _y)
    {
        x = _x;
        y = _y;
    }
    Point operator -(const Point &b)const
    {
        return Point(x-b.x,y-b.y);
    }
    double operator *(const Point &b)const
    {
        return x*b.y-y*b.x;
    }
    double operator &(const Point &b)const
    {
        return x*b.x+y*b.y;
    }
};

struct Line
{
    Point s,e;
    Line(){}
    Line(Point _s,Point _e)
    {
        s = _s;
        e = _e;
    }
    Point operator &(const Line &b)const
    {
        Point res = s;
        double t = ((s-b.s)*(b.s-b.e))/((s-e)*(b.s-b.e));
        res.x += (e.x-s.x)*t;
        res.y += (e.y-s.y)*t;
        return res;
    }
};

struct Event
{
    double tim;
    int typ,id;
    Event(){}
    Event(double _tim,int _typ,int _id)
    {
        tim = _tim;
        typ = _typ;
        id = _id;
    }
    bool operator < (const Event& b)const
    {
        if (cmp(tim,b.tim) == 0)
        {
            if (id == b.id)
                return typ < b.typ;
            return id < b.id;
        }
        return tim < b.tim;
    }
};

Event e[1000000];
int tote;
Point p[100000];
int n,m;

double Theta(Point p)
{
    return atan2(p.y,p.x);
}

void addEvent(double l,double r,int typ)
{
    if (cmp(l,r) > 0)
        swap(l,r);
    if (cmp(r-l,pi) > 0)
        swap(l,r);
    e[tote++] = Event(l,typ,1);
    e[tote++] = Event(r,typ,-1);
    if (cmp(l,r) > 0)
    {
        e[tote++] = Event(-pi,typ,1);
        e[tote++] = Event(pi,typ,-1);
    }
}

double res;

void addRes(int id,double l,double r)
{
    Point pa = Line(p[id],p[(id+1)%n])&Line(Point(0,0),Point(cos(l),sin(l)));
    Point pb = Line(p[id],p[(id+1)%n])&Line(Point(0,0),Point(cos(r),sin(r)));
    res += sqrt((pa-pb)&(pa-pb));
}

int main()
{
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; i++)
        scanf("%lf%lf",&p[i].x,&p[i].y);

    tote = 0;
    for (int i = 0; i < n; i++)
        addEvent(Theta(p[i]),Theta(p[(i+1)%n]),i);
    for (int i = 0; i < m; i++)
    {
        Point pa,pb;
        scanf("%lf%lf%lf%lf",&pa.x,&pa.y,&pb.x,&pb.y);
        addEvent(Theta(pa),Theta(pb),-1);
    }
    sort(e,e+tote);

//    for (int i = 0;i < tote;i++)
//        printf("%.2f %d %d\n",e[i].tim,e[i].typ,e[i].id);

    res = 0;
    double prel,pretheta;
    int cover = 0,nowid = -1;
    for (int i = 0;i < tote;i++)
    {
        if (e[i].typ == -1)
        {
            cover += e[i].id;
            if (cover == 1 && e[i].id == 1)
                prel = e[i].tim;
            if (cover == 0 && e[i].id == -1)
            {
                //printf("[%.2f %.2f]\n",prel,e[i].tim);
                if (nowid != -1)
                    addRes(nowid,max(prel,pretheta),e[i].tim);
            }
        }
        else
        {
            if (e[i].id == 1)
            {
                nowid = e[i].typ;
                pretheta = e[i].tim;
            }
            else
            {
                if (cover > 0)
                    addRes(nowid,max(prel,pretheta),e[i].tim);
                nowid = -1;
            }
        }
    }
    printf("%.10f\n",res);
    return 0;
}
