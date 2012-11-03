#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

struct Point
{
    int x,y;
    Point() {}
    Point(int _x,int _y)
    {
        x = _x,y = _y;
    }
    Point operator -(const Point& b)const
    {
        return Point(x-b.x,y-b.y);
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

bool conPoint(Point p[],int n)
{
    for (int i = 1; i < n; i++)
        if (p[i].x != p[0].x || p[i].y != p[0].y)
            return false;
    return true;
}

bool conLine(Point p[],int n)
{
    for (int i = 2; i < n; i++)
        if ((p[1]-p[0])*(p[i]-p[0]) != 0)   return false;
    return true;
}

Point base;
bool CMP(Point a,Point b)
{
    int ret = (a-base)*(b-base);
    if (ret == 0)
        return a.x < b.x;
    return ret > 0;
}

void GS(Point p[],int n,Point res[],int& resn)
{
    resn = 0;
    if (n < 3 || conPoint(p,n) == true || conLine(p,n) == true)
        return;

    for (int i = 2; i < n; i++)
        if ((p[i-1]-p[i-2])*(p[i]-p[i-1]) <= 0)
        {
            resn = 0;
            return;
        }
    resn = n;
    for (int i = 0; i < resn; i++)
        res[i] = p[i];
}

double CalcArea(Point p[],int n)
{
    double res = 0;
    for (int i = 0; i < n; i++)
        res += 0.5*(p[i]*p[(i+1)%n]);
    return res;
}

double CalcLen(Point p[],int n)
{
    double res = 0;
    for (int i = 0; i < n; i++)
        res += sqrt(1.0*((p[(i+1)%n]-p[i])&(p[(i+1)%n]-p[i])));
    return res;
}

Point p[20],tp[20],rp[20],kp[20];
int n,tn,rn,kn;

int main()
{
    //for (int tim = 0; tim < 10; tim++)
    while (scanf("%d",&rn) != EOF)
    {
//        rn = 20;
        for (int i = 0; i < rn; i++)
            scanf("%d%d",&rp[i].x,&rp[i].y);
//        {
//            rp[i].x = rand()%10000;
//            rp[i].y = rand()%10000;
//        }

        double res = 1e100;
        for (int i = 0; i < rn; i++)
        {
            kp[0] = rp[i];
            kn = 1;
            for (int j = 0; j < rn; j++)
                if (i != j)
                    if (rp[i].x < rp[j].x || (rp[i].x == rp[j].x && rp[i].y < rp[j].y))
                        kp[kn++] = rp[j];
            base = kp[0];
            sort(kp+1,kp+kn,CMP);

            for (int sta = 0; sta < (1<<(kn-1)); sta++)
            {
                tn = 0;
                tp[tn++] = kp[0];
                for (int j = 0; j < kn-1; j++)
                    if (((sta>>j)&1) == 1)
                        tp[tn++] = kp[j+1];
//                for (int j = 0;j < tn;j++)
//                    printf("(%d, %d) ",tp[j].x,tp[j].y);
//                printf("\n");
                GS(tp,tn,p,n);
                if (n == 0) continue;

                double len = CalcLen(p,n);
                double area = CalcArea(p,n);

                res = min(res,len*len/area);
            }
        }
        printf("%.4f\n",res);
    }
    return 0;
}

