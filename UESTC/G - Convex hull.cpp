#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

struct Point
{
    int x,y;
    Point(){}
    Point(int _x,int _y)
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
            return sqrt((double)(x*x+y*y));
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

double xmult(Point a,Point b)
{
    return (double)(a.x*b.y-b.x*a.y);
}

double Distance(Point p,Line l)
{
    return fabs(xmult(Point(l.s,p),Point(l.s,l.e)))/Point(l.s,l.e).Length();
}

int n,maxx,minx,maxy,miny;
Point p[100000],near[4],v[4],c[4],res[8];
double dist[4];

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        minx = miny = 1000;
        maxx = maxy = 0;
        for (int i = 0;i < n;i++)
        {
            scanf("%d%d",&p[i].x,&p[i].y);
            minx = min(minx,p[i].x);
            maxx = max(maxx,p[i].x);
            miny = min(miny,p[i].y);
            maxy = max(maxy,p[i].y);
        }
        for (int i = 0;i < 4;i++)
            dist[i] = 1e20;
        c[0] = Point(minx,miny);
        c[1] = Point(maxx,miny);
        c[2] = Point(maxx,maxy);
        c[3] = Point(minx,maxy);
        v[0] = v[2] = Point(1,-1);
        v[1] = v[3] = Point(1,1);
        for (int i = 0;i < n;i++)
            for (int j = 0;j < 4;j++)
                if (dist[j] > Distance(c[j],Line(p[i],Point(p[i].x+v[j].x,p[i].y+v[j].y))))
                {
                    dist[j] = Distance(c[j],Line(p[i],Point(p[i].x+v[j].x,p[i].y+v[j].y)));
                    near[j] = p[i];
                }
        res[0] = Point(c[0].x,near[0].y+near[0].x-c[0].x);
        res[1] = Point(near[0].x+near[0].y-c[0].y,c[0].y);
        res[2] = Point(near[1].x-(near[1].y-c[1].y),c[1].y);
        res[3] = Point(c[1].x,near[1].y+c[1].x-near[1].x);
        res[4] = Point(c[2].x,near[2].y-(c[2].x-near[2].x));
        res[5] = Point(near[2].x-(c[2].y-near[2].y),c[2].y);
        res[6] = Point(near[3].x+c[3].y-near[3].y,c[3].y);
        res[7] = Point(c[3].x,near[3].y-(near[3].x-c[3].x));
        n = 0;
        for (int i = 0;i < 8;i++)
            if ((res[i].x != res[(i+1)%8].x) || (res[i].y != res[(i+1)%8].y))
                res[n++] = res[i];
        if (n == 0) n++;
        for (int i = 0;i < n;i++)
            printf("%d %d\n",res[i].x,res[i].y);
    }
}
