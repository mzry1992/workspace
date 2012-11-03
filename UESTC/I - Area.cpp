#include <iostream>
#include <cstring>
#include <cstdio>
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
};

int xmult(Point a,Point b)
{
    return a.x*b.y-a.y*b.x;
}

int gcd(int a,int b)
{
    if (b == 0) return a;
    return gcd(b,a%b);
}

int Abs(int a)
{
    if (a < 0)  return -a;
    return a;
}

int getonline(Point a,Point b)
{
    if (a.x == b.x) return Abs(a.y-b.y)+1;
    if (a.y == b.y) return Abs(a.x-b.x)+1;
    return gcd(Abs(a.x-b.x),Abs(a.y-b.y))+1;
}

int n;
Point p[101],pre,cur;
int I,E,A,tI,tE,tA;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        p[0] = Point(0,0);
        for (int i = 0;i < n;i++)
        {
            scanf("%d%d",&p[i+1].x,&p[i+1].y);
            p[i+1].x += p[i].x;
            p[i+1].y += p[i].y;
        }
        I = E = A = 0;
        for (int i = 0;i < n;i++)
            E += getonline(p[i],p[(i+1)%n]);
        E -= n;
        for (int i = 1;i < n-1;i++)
            A += xmult(p[i],p[i+1]);
        I = (A-E)/2+1;
        printf("Scenario #%d:\n",ft);
        printf("%d %d %d.%c\n\n",I,E,A/2,(A%2 == 0)?'0':'5');
    }
}
