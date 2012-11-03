#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const double pi = acos(-1.0);

struct Point
{
    int x,y;
    Point(){}
    Point(int _x,int _y)
        {
            x = _x;
            y = _y;
        }
    Point (Point _s,Point _e)
        {
            x = _e.x-_s.x;
            y = _e.y-_s.y;
        }
    int len2()
        {
            return x*x+y*y;
        }
};

struct even
{
    int type;
    double time;
    even(){}
    even(int _type,double _time)
        {
            type = _type;
            time = _time;
        }
};

int n,r,res,tres;
Point p[2000];
even e[4000];
int toteven;

bool evencmp(even a,even b)
{
    if (a.time == b.time)   return a.type > b.type;
    return a.time < b.time;
}

int main()
{
    while (true)
    {
        scanf("%d%d",&n,&r);
        if (n == 0 && r == 0)   break;
        for (int i = 0;i < n;i++)
            scanf("%d%d",&p[i].x,&p[i].y);
        res = 1;
        for (int i = 0;i < n;i++)
        {
            toteven = 0;
            for (int j = 0;j < n;j++)
                if (i != j)
                {
                    double dis = sqrt((double)Point(p[i],p[j]).len2())/2.0;
                    if (dis > r)    continue;
                    double dis2 = sqrt((double)r*(double)r-dis*dis);
                    double basepolar = atan2(Point(p[i],p[j]).y,Point(p[i],p[j]).x);
                    double det = atan2(dis2,dis);
                    e[toteven++] = even(1,basepolar-det);
                    e[toteven++] = even(-1,basepolar+det);
                }
            sort(e,e+toteven,evencmp);
            tres = 1;
            for (int j = 0;j < toteven;j++)
            {
                tres += e[j].type;
                if (tres > res) res = tres;
            }
        }
        printf("It is possible to cover %d points.\n",res);
    }
    return 0;
}
