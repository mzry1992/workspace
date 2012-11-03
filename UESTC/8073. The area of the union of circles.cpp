#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
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
    double len()
        {
            return sqrt(x*x+y*y);
        }
};
struct Circle
{
    Point c;
    int r;
    Circle(){}
    Circle(Point _c,int _r)
        {
            c = _c;
            r = _r;
        }
};

int n,tn;
Circle c[1000];

int main()
{
    while (scanf("%d",&tn) != EOF)
    {
        n = 0;
        for (int i = 0;i < tn;i++)
        {
            scanf("%d%d%d",&c[n].c.x,&c[n].c.y,&c[n].r);
            if (c[n].r != 0)    n++;
        }
        for (int i = 0;i < n;i++)
            for (int j = 0;j < n;j++)
                if (i != j)
                    if (Point(c[i].c,c[j].c)+c[j].r <= c[i].r)
                    {

                    }
    }
}
