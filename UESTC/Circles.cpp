#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

const double pi = acos(-1.0);
const double eps = 1e-8;

struct Point
{
    double x,y,r;
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
    double Length()
    {
        return sqrt(x*x+y*y);
    }
};

Point c[1000];
int m,com,totc,pos;
vector<int> undel;
vector<int>::iterator it;

void Gao(Point a,Point b,Point& q1,Point& q2)
{
    Point vab = Point(a,b);
    double tab = atan2(vab.y,vab.x);
    double dis = sqrt(vab.x*vab.x+vab.y*vab.y);
    double tt;
    if (b.r > a.r)
        tt = asin((b.r-a.r)/dis);
    else
        tt = -asin((a.r-b.r)/dis);
    double theta = tab+pi/2+tt;
    q1 = Point(a.x+a.r*cos(theta),a.y+a.r*sin(theta));
    q2 = Point(b.x+b.r*cos(theta),b.y+b.r*sin(theta));
}

double xmult(Point a,Point b)
{
    return a.x*b.y-a.y*b.x;
}

double CalcDis(Point a,Point b)
{
    return Point(a,b).Length();
}

double CalcDis(Point a,Point s,Point e)
{
    return fabs(xmult(Point(a,s),Point(a,e)))/CalcDis(s,e);
}

int cmp(double a,double b)
{
    if (fabs(a-b) < eps)    return 0;
    if (a < b)  return -1;
    return 1;
}

bool check(Point s,Point e,Point c)
{
    return cmp(CalcDis(c,s,e),c.r) <= 0;
}

int solve()
{
    int res,tres;
    int n = undel.size();
    Point pa[2],pb[2];
    if (n < 3)  return n;
    res = 0;
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
        {
            Gao(c[undel[i]],c[undel[j]],pa[0],pb[0]);
            Gao(c[undel[j]],c[undel[i]],pa[1],pb[1]);
            for (int ppa = 0; ppa < 2; ppa++)
                for (int ppb = 0; ppb < 2; ppb++)
                {
                    tres = 0;
                    for (int k = 0;k < n;k++)
                        if (check(pa[ppa],pb[ppb],c[undel[k]]) == true)
                            tres++;
                    res = max(res,tres);
                }
        }
    return res;
}

int main()
{
    while (scanf("%d",&m) != EOF)
    {
        undel.clear();
        totc = 0;
        for (int i = 0; i < m; i++)
        {
            scanf("%d",&com);
            if (com == 1)
            {
                scanf("%lf%lf%lf",&c[totc].x,&c[totc].y,&c[totc].r);
                undel.push_back(totc++);
            }
            else if (com == 2)
            {
                scanf("%d",&pos);
                for (it = undel.begin(); it != undel.end(); it++)
                    if (*it == pos-1)
                        break;
                if (it != undel.end())
                    undel.erase(it);
            }
            else if (com == 3)
                printf("%d\n",solve());
        }
    }
    return 0;
}
