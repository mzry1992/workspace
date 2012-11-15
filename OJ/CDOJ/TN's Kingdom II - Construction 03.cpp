#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int MaxN = 100010;
const int MaxM = 800100;
const double eps = 1e-8;
const double inf = 1e100;

int cmp(double a,double b)
{
    if (fabs(a-b) < eps)  return 0;
    if (a < b)  return -1;
    return 1;
}

struct Point
{
    double x,y;
    int id;
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
    friend bool operator < (const Point& a,const Point& b)
    {
        if (cmp(a.x,b.x) == 0)  return cmp(a.y,b.y) < 0;
        return cmp(a.x,b.x) < 0;
    }
    friend double xmult(Point a,Point b)
    {
        return a.x*b.y-a.y*b.x;
    }
    double Length()
    {
        return sqrt(x*x+y*y);
    }
};

struct Line
{
    Point s,e;
    Line() {}
    Line(Point _s,Point _e)
    {
        s = _s;
        e = _e;
    }
};

struct Edge
{
    int to,next,pre,rid;
    //rid :反向边id
};

Edge edge[MaxM];
int mem[MaxM],top;
Point p[MaxN];
int n;

Point LineToLine(Line a,Line b)
{
    Point res = a.s;
    double t = ((a.s.x-b.s.x)*(b.s.y-b.e.y)-(a.s.y-b.s.y)*(b.s.x-b.e.x))/((a.s.x-a.e.x)*(b.s.y-b.e.y)-(a.s.y-a.e.y)*(b.s.x-b.e.x));
    res.x += (a.e.x-a.s.x)*t;
    res.y += (a.e.y-a.s.y)*t;
    return res;
}

void addedge(int u,int v)
{
    int L = mem[--top],id0,id1;

    edge[L].to = v;

    edge[L].pre = u;
    edge[L].next = edge[u].next;

    id0 = edge[u].next = L;
    if (edge[L].next != -1)
        edge[edge[L].next].pre = L;

    L = mem[--top];

    edge[L].to = u;

    edge[L].pre = v;
    edge[L].next = edge[v].next;

    id1 = edge[v].next = L;
    if (edge[L].next != -1)
        edge[edge[L].next].pre = L;

    edge[id0].rid = id1;
    edge[id1].rid = id0;
}

void deledge(int id)
{
    int pre,next;
    pre = edge[id].pre;
    next = edge[id].next;
    edge[pre].next = next;
    if (next != -1)
        edge[next].pre = pre;
    mem[top++] = id;

    id = edge[id].rid;

    pre = edge[id].pre;
    next = edge[id].next;
    edge[pre].next = next;
    if (next != -1)
        edge[next].pre = pre;
    mem[top++] = id;
}

bool conLine(Point p0,Point p1,Point p2)
{
    return xmult(Point(p0,p1),Point(p0,p2)) == 0;
}

inline int getnext(int now,int l,int r)
{
    if (now+1 > r)  return l;
    return now+1;
}

inline int getpre(int now,int l,int r)
{
    if (now-1 < l)  return r;
    return now-1;
}

double get_sit(Point p1,Point p2,Point p3)
{
    return xmult(Point(p1,p2),Point(p1,p3));
}

Line getmidline(Point s,Point e)
{
    Point _s,_e;
    _s = Point((s.x+e.x)/2,(s.y+e.y)/2);
    _e = Point(_s.x+(s.y-e.y),_s.y-(s.x-e.x));
    return Line(_s,_e);
}

int a[MaxN],used[MaxN];
bool check[MaxN];

bool SegCross(Line a,Line b)
{
    return cmp(get_sit(a.s,a.e,b.s),0)*cmp(get_sit(a.s,a.e,b.e),0) < 0 &&
           cmp(get_sit(b.s,b.e,a.s),0)*cmp(get_sit(b.s,b.e,a.e),0) < 0;
}

void Delaunay(int l,int r)
{
    if (l == r) return;
    if (l == r-1)
        addedge(l,r);
    else if (l == r-2)
    {
        addedge(l,l+1);
        addedge(l+1,l+2);
        if (conLine(p[l],p[l+1],p[l+2]) == false)
            addedge(l,l+2);
    }
    else
    {

        int mid = (l+r)>>1;
        Delaunay(l,mid);
        Delaunay(mid+1,r);

        //找最下面和最上面的切线
        int tot = 2;
        memset(a,0,sizeof(a));
        memset(check,false,sizeof(check));
        a[0] = l;
        a[1] = l+1;
        int i = l+2,j;
        check[l] = check[l+1] = true;
        for (; i <= r; i++)
            if (check[i] == false)
            {
                while ((tot > 1) && cmp(get_sit(p[a[tot-2]],p[a[tot-1]],p[i]),0) < 0)
                    check[a[--tot]] = false;
                check[i] = true;
                a[tot++] = i;
            }
        for (i = 0; i < tot; i++)
            if (a[i] > mid) break;
        int p1 = a[i-1];
        int p2 = a[i];
        //下切线 p1 --> p2
        //合并
        Line l1,l2;
        Point xp;
        //l1是当前下切线的中垂线，l2是与当前下切线关联的某条边的中垂线，xp是这两条线的交点
        double miny,predis,nowdis;
        int nextid,nexttyp;
        int tl,tr;
        //nextid是下一个点，nexttyp表示下一个点属于左边还是右边

        while (true)
        {
            addedge(p1,p2);

            l1 = getmidline(p[p1],p[p2]);
            miny = inf;
            nexttyp = -1;
            for (i = edge[p1].next; i != -1; i = edge[i].next)
            {
                if (edge[i].to < l || edge[i].to > mid) continue;
                if (cmp(get_sit(p[p1],p[p2],p[edge[i].to]),0) <= 0) continue;
                l2 = getmidline(p[p1],p[edge[i].to]);
                xp = LineToLine(l1,l2);
                nowdis = Point(xp,l1.s).Length();
                if (cmp(miny,xp.y) > 0
                        || (cmp(miny,xp.y) == 0 && cmp(nowdis,predis) < 0))
                    {
                        miny = xp.y;
                        nextid = edge[i].to;
                        nexttyp = 0;
                        predis = nowdis;
                    }
            }
            for (i = edge[p2].next; i != -1; i = edge[i].next)
            {
                if (edge[i].to < mid+1 || edge[i].to > r) continue;
                if (cmp(get_sit(p[p1],p[p2],p[edge[i].to]),0) <= 0) continue;
                l2 = getmidline(p[p2],p[edge[i].to]);
                xp = LineToLine(l1,l2);
                nowdis = Point(xp,l1.s).Length();
                if (cmp(miny,xp.y) > 0
                        || (cmp(miny,xp.y) == 0 && cmp(nowdis,predis) < 0))
                    {
                        miny = xp.y;
                        nextid = edge[i].to;
                        nexttyp = 1;
                        predis = nowdis;
                    }
            }
            if (nexttyp == -1)  break;
            if (nexttyp == 0)
            {
                tl = tr = p1;
                p1 = nextid;
            }
            else
            {
                tl = tr = p2;
                p2 = nextid;
            }

            //删除
            l1 = Line(p[p1],p[p2]); //当前的切线
            for (i = tl; i <= tr; i++)
                for (j = edge[i].next; j != -1; j = edge[j].next)
                    if (SegCross(Line(p[i],p[edge[j].to]),l1) == true) //如果相交
                    {
                        deledge(j);
                    }
        }
    }
}

struct MSTEdge
{
    int u,v;
    double dis;
    friend bool operator < (const MSTEdge& a,const MSTEdge& b)
    {
        return cmp(a.dis,b.dis) < 0;
    }
};

MSTEdge g[MaxM];
int tote,f[MaxN];

int findf(int x)
{
    if (f[x] != x)  f[x] = findf(f[x]);
    return f[x];
}

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%lf%lf",&p[i].x,&p[i].y);
            p[i].id = i;
            edge[i].next = -1;
        }

        top = 0;
        for (int i = n+1; i < MaxM; i++)
            mem[top++] = i;
        sort(p,p+n);

        int tn = n;
        n = 1;
        for (int i = 1; i < tn; i++)
            if (cmp(p[i].x,p[n-1].x) != 0 ||
                    cmp(p[i].y,p[n-1].y) != 0)
                p[n++] = p[i];


        Delaunay(0,n-1);

        tote = 0;
        for (int i = 0; i < n; i++)
            for (int j = edge[i].next; j != -1; j = edge[j].next)
                if (i < edge[j].to)
                {
                    g[tote].u = i;
                    g[tote].v = edge[j].to;
                    g[tote++].dis = Point(p[i],p[edge[j].to]).Length();
                }
        sort(g,g+tote);
        for (int i = 0; i < n; i++)
            f[i] = i;
        int fa,fb,totn = 0;
        double res = 0.0;
        for (int i = 0; i < tote; i++)
        {
            fa = findf(g[i].u);
            fb = findf(g[i].v);
            if (fa != fb)
            {
                totn++;
                f[fa] = fb;
                res += g[i].dis;
            }
            if (totn == n)  break;
        }
        printf("%.4f\n",res);
    }
    return 0;
}
