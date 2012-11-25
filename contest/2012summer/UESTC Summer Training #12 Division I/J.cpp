#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const double eps = 1e-6;
const double pi = acos(-1.0);
int cmp(double a,double b)
{
    if (fabs(a-b) < eps)    return 0;
    if (a < b)  return -1;
    return 1;
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
    Point operator -(const Point& b)const
    {
        Point res;
        res.x = x-b.x;
        res.y = y-b.y;
        return res;
    }
    double operator *(const Point& b)const
    {
        return x*b.y-y*b.x;
    }
    double operator &(const Point& b)const
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
};

double r;
Point p[2],xp[2][8],np[4];
Line l[4];
int totxp[2];

int main()
{
    int totcas;
    scanf("%d",&totcas);
    while (totcas--)
    {
        scanf("%lf",&r);
        for (int i = 0;i < 2;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        l[0] = Line(Point(0,r),Point(r,0));
        np[0] = Point(r/2,r/2);

        l[1] = Line(Point(r,0),Point(0,-r));
        np[1] = Point(r/2,-r/2);

        l[2] = Line(Point(0,-r),Point(-r,0));
        np[2] = Point(-r/2,-r/2);

        l[3] = Line(Point(-r,0),Point(0,r));
        np[3] = Point(-r/2,r/2);

        bool ck[2];
        ck[0] = ck[1] = false;

        for (int i = 0;i < 2;i++)
        {
            if (fabs(p[i].x)+fabs(p[i].y) == r)
                ck[i] = true;

            totxp[i] = 0;
            for (int j = 0;j < 4;j++)
            {
                Point tv = l[j].s-l[j].e;
                Point near = np[j];

                if (near.x*near.x+near.y*near.y <= p[i].x*p[i].x+p[i].y*p[i].y)
                {
                    double A,B,C;
                    A = near.x*near.x+near.y*near.y;
                    C = p[i].x*p[i].x+p[i].y*p[i].y;
                    B = C-A;
                    double tvl = tv.x*tv.x+tv.y*tv.y;
                    double tmp = sqrt(B/tvl);
                    xp[i][totxp[i]++] = Point(near.x+tmp*tv.x,near.y+tmp*tv.y);
                    xp[i][totxp[i]++] = Point(near.x-tmp*tv.x,near.y-tmp*tv.y);
                }
            }
            //printf("(%.2f,%.2f) : \n",p[i].x,p[i].y);
            //for (int j = 0;j < totxp[i];j++)
            //    printf("   (%.2f,%.2f)\n",xp[i][j].x,xp[i][j].y);
        }
        bool res = false;
        if (ck[0] && ck[1]) res = true;
        for (int i = 0;i < totxp[0] && !res;i++)
            for (int j = 0;j < totxp[1] && !res;j++)
                if (cmp((p[0]*p[1]),(xp[0][i]*xp[1][j])) == 0 &&
                    cmp((p[0]&p[1]),(xp[0][i]&xp[1][j])) == 0)
                    res = true;
        if (res)
            puts("YES");
        else
            puts("NO");
    }
	return 0;
}
