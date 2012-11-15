#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
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
    double Length()
        {
            return sqrt((e.x-s.x)*(e.x-s.x)+(e.y-s.y)*(e.y-s.y));
        }
};

struct door
{
    double x;
    double y[4];
};

double xmult(Point a,Point b)
{
    return a.x*b.y-a.y*b.x;
}

bool EQ(double a,double b)
{
    return fabs(a-b) < eps;
}

bool BT(double a,double b)
{
    return a-b > eps;
}

bool EBT(double a,double b)
{
    return EQ(a,b) || BT(a,b);
}

bool OnSeg(Point a,Line b)
{
    if (EQ(xmult(Point(a,b.s),Point(a,b.e)),0.0) == false)  return false;
    return (EBT(a.x,min(b.s.x,b.e.x)) && EBT(max(b.s.x,b.e.x),a.x) &&
            EBT(a.y,min(b.s.y,b.e.y)) && EBT(max(b.s.y,b.e.y),a.y));
}

bool Cross(Line a,Line b)
{
    if (OnSeg(a.s,b) || OnSeg(a.e,b) || OnSeg(b.s,a) || OnSeg(b.e,a))   return true;
    if (EQ(xmult(Point(a.s,a.e),Point(b.s,b.e)),0.0) == true)   return false;
    if (BT(min(b.s.x,b.e.x),max(a.s.x,a.e.x)) || BT(min(a.s.x,a.e.x),max(b.s.x,b.e.x))) return false;
    if (BT(min(b.s.y,b.e.y),max(a.s.y,a.e.y)) || BT(min(a.s.y,a.e.y),max(b.s.y,b.e.y))) return false;
    if (BT(xmult(Point(a.s,a.e),Point(a.s,b.e))*xmult(Point(a.s,a.e),Point(a.s,b.s)),0.0)||
        BT(xmult(Point(b.s,b.e),Point(b.s,a.e))*xmult(Point(b.s,b.e),Point(b.s,a.s)),0.0)) return false;
    return true;
}

int n;
door d[20];
double dis[20][4][20][4],dp[20][4];
Line seg;
bool flag;

int main()
{
    while (true)
    {
        scanf("%d",&n);
        if (n == -1)    break;
        d[0].x = 0.0;
        d[n+1].x = 10.0;
        for (int i = 0;i < 4;i++)
            d[0].y[i] = d[n+1].y[i] = 5.0;
        for (int i = 1;i <= n;i++)
            scanf("%lf%lf%lf%lf%lf",&d[i].x,&d[i].y[0],&d[i].y[1],&d[i].y[2],&d[i].y[3]);
        n += 2;
        for (int i = 0;i < n;i++)
            for (int j = 0;j < 4;j++)
                for (int k = i+1;k < n;k++)
                    for (int q = 0;q < 4;q++)
                    {
                        seg = Line(Point(d[i].x,d[i].y[j]),Point(d[k].x,d[k].y[q]));
                        flag = true;
                        for (int w = i+1;w < k;w++)
                            if (Cross(seg,Line(Point(d[w].x,0.0),Point(d[w].x,d[w].y[0]))) ||
                                Cross(seg,Line(Point(d[w].x,d[w].y[1]),Point(d[w].x,d[w].y[2]))) ||
                                Cross(seg,Line(Point(d[w].x,d[w].y[3]),Point(d[w].x,10.0))))
                                flag = false;
                        if (flag == true)
                            dis[i][j][k][q] = seg.Length();
                        else
                            dis[i][j][k][q] = 1e100;
                    }
        for (int i = 0;i < n;i++)
            for (int j = 0;j < 4;j++)
                dp[i][j] = 1e100;
        for (int i = 0;i < 4;i++)
            dp[0][i] = 0;
        for (int i = 0;i < n;i++)
            for (int j = 0;j < 4;j++)
                for (int k = 0;k < i;k++)
                    for (int q = 0;q < 4;q++)
                        if (dp[i][j] > dp[k][q]+dis[k][q][i][j])
                            dp[i][j] = dp[k][q]+dis[k][q][i][j];
        printf("%.2f\n",dp[n-1][0]);
    }
    return 0;
}
