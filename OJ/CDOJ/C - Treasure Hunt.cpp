#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

const double eps = 1e-8;

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
    Line(){}
    Line(Point _s,Point _e)
        {
            s = _s;
            e = _e;
        }
};
struct door
{
    Point pos;
    int typ;
};
struct edge
{
    int to,next;
};
struct node
{
    int pos,step;
    node(){}
    node(int _pos,int _step)
        {
            pos = _pos;
            step = _step;
        }
};

int cmp(double a,double b)
{
    if (fabs(a-b) < eps)    return 0;
    if (a < b)  return -1;
    return 1;
}

double xmult(Point a,Point b)
{
    return a.x*b.y-a.y*b.x;
}

double xmult(Line a,Line b)
{
    return xmult(Point(a.s,a.e),Point(b.s,b.e));
}

Point LineToLine(Line a,Line b)
{
    Point res = a.s;
    double t = ((a.s.x-b.s.x)*(b.s.y-b.e.y)-(a.s.y-b.s.y)*(b.s.x-b.e.x))/((a.s.x-a.e.x)*(b.s.y-b.e.y)-(a.s.y-a.e.y)*(b.s.x-b.e.x));
    res.x += (a.e.x-a.s.x)*t;
    res.y += (a.e.y-a.s.y)*t;
    return res;
}

bool PointCmp(const Point& a,const Point& b)
{
    if (cmp(a.x,b.x) == 0)
        return cmp(a.y,b.y) < 0;
    else
        return cmp(a.x,b.x) < 0;
}

int n,totl,totj,totdoor,head[1200],L;
Line l[50],tmp;
Point jp[50],s,xl;
door door[1200];
edge e[3000000];
double minx,miny,maxx,maxy;
bool flag;

void addedge(int u,int v)
{
    e[L].to = v;
    e[L].next = head[u];
    head[u] = L++;
}

queue<node> Q;
bool visit[1200];
node now;

int BFS()
{
    memset(visit,false,sizeof(visit));
    while (!Q.empty())  Q.pop();
    visit[0] = true;
    Q.push(node(0,0));
    while (!Q.empty())
    {
        now = Q.front();
        Q.pop();
        if (door[now.pos].typ == 2) return now.step;
        for (int i = head[now.pos];i != -1;i = e[i].next)
            if (visit[e[i].to] == false)
            {
                Q.push(node(e[i].to,now.step+1));
                visit[e[i].to] = true;
            }
    }
}

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 0;i < n;i++)
            scanf("%lf%lf%lf%lf",&l[i].s.x,&l[i].s.y,&l[i].e.x,&l[i].e.y);
        totl = n;
        l[totl++] = Line(Point(0,0),Point(100,0));
        l[totl++] = Line(Point(0,0),Point(0,100));
        l[totl++] = Line(Point(100,100),Point(100,0));
        l[totl++] = Line(Point(100,100),Point(0,100));
        scanf("%lf%lf",&s.x,&s.y);
        totdoor = 0;
        door[totdoor].pos = s;
        door[totdoor++].typ = 0;
        for (int i = 0;i < totl;i++)
        {
            totj = 0;
            for (int j = 0;j < totl;j++)
                if (cmp(xmult(l[i],l[j]),0.0) != 0)
                {
                    jp[totj++] = LineToLine(l[i],l[j]);
                    if (cmp(jp[totj-1].y,0) < 0 || cmp(jp[totj-1].y,100) > 0 ||
                        cmp(jp[totj-1].x,0) < 0 || cmp(jp[totj-1].x,100) > 0)
                            totj--;
                }
            sort(jp,jp+totj,PointCmp);
            for (int j = 1;j < totj;j++)
            if (!(cmp(jp[j-1].x,jp[j].x) == 0 && cmp(jp[j-1].y,jp[j].y) == 0))
            {
                if (i < n)
                    door[totdoor].typ = 1;
                else
                    door[totdoor].typ = 2;
                door[totdoor++].pos = Point((jp[j-1].x+jp[j].x)/2,(jp[j-1].y+jp[j].y)/2);
            }
        }
        L = 0;
        for (int i = 0;i < totdoor;i++)
            head[i] = -1;
        for (int i = 0;i < totdoor;i++)
            for (int j = i+1;j < totdoor;j++)
            {
                tmp = Line(door[i].pos,door[j].pos);
                minx = min(tmp.s.x,tmp.e.x);
                miny = min(tmp.s.y,tmp.e.y);
                maxx = max(tmp.s.x,tmp.e.x);
                maxy = max(tmp.s.y,tmp.e.y);
                flag = true;
                for (int k = 0;k < totl;k++)
                    if (cmp(xmult(tmp,l[k]),0.0) != 0)
                    {
                        xl = LineToLine(tmp,l[k]);
                        if ((cmp(xl.x,minx) > 0 && cmp(xl.x,maxx) < 0) ||
                            (cmp(xl.y,miny) > 0 && cmp(xl.y,maxy) < 0))
                            {
                                flag = false;
                                break;
                            }
                    }
                if (flag == true)
                {
                    addedge(i,j);
                    addedge(j,i);
                }
            }
        printf("Number of doors = %d\n",BFS());
    }
    return 0;
}
