#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const double eps = 1e-8;
struct Point
{
    double x,y;
    int id;
    Point(){}
    Point(double _x,double _y)
        {
            x = _x;
            y = _y;
        }
    void transXY(double B)
        {
            double tx = x,ty = y;
            x = tx*cos(B) - ty*sin(B);
            y = tx*sin(B) + ty*cos(B);
        }
};

int cmp(double a,double b)
{
    if (fabs(a-b) < eps)    return 0;
    if (a < b)  return -1;
    return 1;
}

bool Pointcmp(const Point& a,const Point& b)
{
    if (cmp(a.x,b.x) == 0)
        return cmp(a.y,b.y) < 0;
    return cmp(a.x,b.x) < 0;
}

int n;
Point p[100000],v;
double B,res;
int resa,resb,l,r,minid,minpos,minid2;

void Gao(double B)
{
    for (int i = 0;i < n;i++)
        p[i].transXY(B);
    sort(p,p+n,Pointcmp);
    for (int i = 0;i < n;i++)
        if (i == 0 || cmp(p[i].x,p[i-1].x) != 0)
        {
            l = r = i;
            while (r < n && cmp(p[r].x,p[l].x) == 0)    r++;
            r--;
            minid = n;
            for (int j = l;j <= r;j++)
                if (p[j].id < minid)
                {
                    minid = p[j].id;
                    minpos = j;
                }
            minid2 = n;
            for (int j = l;j <= r;j++)
                if (j != minpos)
                    if (cmp(p[j].y,p[minpos].y) > 0)
                        if (p[j].id < minid2)
                            minid2 = p[j].id;
            if (minid2 == n)
            {
                minid2 = n;
                for (int j = l;j <= r;j++)
                    if (j != minpos)
                        if (p[j].id < minid2)
                            minid2 = p[j].id;
                swap(minid,minid2);
            }
            if (minid < resa || (minid == resa && minid2 < resb))
            {
                resa = minid;
                resb = minid2;
            }
        }
    for (int i = 0;i < n;i++)
        p[i].transXY(-B);
}

int wg;
char ch;
bool ng;

inline int readint()
{
    ch = getchar();
    while (ch != '-' && (ch < '0' || ch > '9'))    ch = getchar();
    if (ch == '-')
    {
        ng = true;
        ch = getchar();
    }
    else ng = false;
    wg = ch-'0';
    ch = getchar();
    while (ch >= '0' && ch <= '9')
    {
        wg = wg*10+ch-'0';
        ch = getchar();
    }
    if (ng == true) wg = -wg;
    return wg;
}

int main()
{
    while (scanf("%d%lf%lf",&n,&v.x,&v.y) != EOF)
    {
        B = atan2(v.x,v.y);
        for (int i = 0;i < n;i++)
        {
            p[i].x = (double)readint();
            p[i].y = (double)readint();
            p[i].transXY(B);
            p[i].id = i;
        }
        sort(p,p+n,Pointcmp);
        res = 0.0;
        for (int i = 1;i < n;i++)
            res = max(res,atan2(fabs(p[i].y-p[i-1].y),fabs(p[i].x-p[i-1].x)));
        resa = resb = n;
        Gao(acos(-1.0)/2.0-res);
        Gao(res-acos(-1.0)/2.0);
        printf("%d %d\n",resa+1,resb+1);
    }
    return 0;
}
