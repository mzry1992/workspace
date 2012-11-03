#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;

struct Point
{
    long long x,y;
};

Point tv[100],tp[100];
Point p[100],v[100];
int n;

void Get(long long a,long long b,long long c,long long d,long long &a0,long long &a1,long long &a2)
{
    a0 = a*c;
    a1 = a*d+b*c;
    a2 = b*d;
}

bool conLine(Point a,Point b)
{
    return (a.x*b.y-a.y*b.x) == 0;
}

map<long long,int> tim;
map<long long,int>::iterator it;

int Gao(int a0,int a1)
{
    for (int i = 0;i < n;i++)
    {
        tv[i].x = (v[i].x-v[a0].x);
        tv[i].y = (v[i].y-v[a0].y);
        tp[i].x = (p[i].x-p[a0].x);
        tp[i].y = (p[i].y-p[a0].y);
    }
    tim.clear();
    long long A,B,C,ta,tb,tc,tt,ttt;
    int always = 2;
    for (int i = 0;i < n;i++)
        if (i != a0 && i != a1)
        {
            Get(tp[a1].x,tv[a1].x,tp[i].y,tv[i].y,C,B,A);
            Get(tp[i].x,tv[i].x,tp[a1].y,tv[a1].y,tc,tb,ta);
            C -= tc;
            B -= tb;
            A -= ta;
            if (A == 0)
            {
                if (B == 0)
                {
                    if (C == 0) always++;
                }
                else
                {
                    if (C%B == 0)
                    {
                        if (-C/B >= 0)
                            tim[-C/B]++;
                    }
                }
            }
            else
            {
                tt = B*B-4*A*C;
                if (tt == 0)
                {
                    ta = -B;
                    tb = 2*A;
                    if (ta%tb == 0)
                    {
                        if (ta/tb >= 0)
                            tim[ta/tb]++;
                    }
                }
                else
                {
                    ttt = (long long)sqrt(1.0*tt);
                    if (ttt*ttt == tt)
                    {
                        ta = -B+ttt;
                        tb = 2*A;
                        if (ta%tb == 0)
                        {
                            if (ta/tb >= 0)
                                tim[ta/tb]++;
                        }
                        ta = -B-ttt;
                        tb = 2*A;
                        if (ta%tb == 0)
                        {
                            if (ta/tb >= 0)
                                tim[ta/tb]++;
                        }
                    }
                }
            }
        }
    int res = 0;
    for (it = tim.begin();it != tim.end();it++)
    {
        ta = tp[a1].x+tv[a1].x*it->first;
        tb = tp[a1].y+tv[a1].y*it->first;
        if (ta == 0 && tb == 0)
        {
            int tres = 0;
            for (int i = 0;i < n;i++)
                if (i != a0 && i != a1)
                {
                    ta = tp[i].x+tv[i].x*it->first;
                    tb = tp[i].y+tv[i].y*it->first;
                    if (ta == 0 && tb == 0) tres++;
                }
            res = max(res,tres);
        }
        else
            res = max(res,it->second);
    }
    return res+always;
}

int main()
{
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        for (int i = 0;i < n;i++)
            scanf("%I64d%I64d%I64d%I64d",&p[i].x,&p[i].y,&v[i].x,&v[i].y);
        bool conPoint = true;
        for (int i = 0;i < n;i++)
            if (p[i].x != p[0].x || p[i].y != p[0].y)
            {
                conPoint = false;
                break;
            }
        int res = 0;
        if (conPoint == true)
            res = n;
        else
        {
            for (int i = 0;i < n;i++)
                for (int j = 0;j < n;j++)
                    if (i != j && (p[i].x != p[j].x || p[i].y != p[j].y))
                        res = max(res,Gao(i,j));
        }
        printf("%d\n",res);
    }
    return 0;
}
