#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const double eps = 1e-8;

int cmp(double a,double b)
{
    if (fabs(a-b) < eps)    return 0;
    if (a < b)  return -1;
    return 1;
}

struct Point
{
    double x,y,z;
    Point(){}
    Point(double _x,double _y,double _z)
    {
        x = _x;
        y = _y;
        z = _z;
    }
    Point(Point _s,Point _e)
    {
        x = _e.x-_s.x;
        y = _e.y-_s.y;
        z = _e.z-_s.z;
    }
    double Length2()
    {
        return x*x+y*y+z*z;
    }
};

struct Face
{
    Point p[3];
};

Point xmult(Point a,Point b)
{
    return Point(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x);
}

double pmult(Point a,Point b)
{
    return a.x*b.x+a.y*b.y+a.z*b.z;
}

double xpmult(Point a,Point b,Point c,Point d)
{
    return pmult(Point(a,d),xmult(Point(a,b),Point(a,c)))/6;
}

bool ConPoint(Point a,Point b)
{
    return cmp(a.x,b.x) == 0 && cmp(a.y,b.y) == 0 && cmp(a.z,b.z) == 0;
}

bool ConLine(Point a,Point b,Point c)
{
    return cmp(xmult(Point(a,b),Point(a,c)).Length2(),0) == 0;
}

bool ConFace(Point a,Point b,Point c,Point d)
{
    return cmp(xpmult(a,b,c,d),0) == 0;
}

void ConvexHull(Point p[],int n,Face res[],int resn)
{
    resn = 0;
    if (n < 4)  return;

    //找两个不共点的
    bool flag = false;
    for (int i = 1;i < n;i++)
        if (ConPoint(p[0],p[i]) == false)
        {
            swap(p[1],p[i]);
            flag = true;
            break;
        }
    if (flag == false)  return;
    //找三个不共线的
    flag = false;
    for (int i = 2;i < n;i++)
        if (ConLine(p[0],p[1],p[i]) == false)
        {
            swap(p[2],p[i]);
            flag = true;
            break;
        }
    if (flag == false)  return;
    //找四个不共面的
    flag = false;
    for (int i = 3;i < n;i++)
        if (ConFace(p[0],p[1],p[2],p[i]) == false)
        {
            swap(p[3],p[i]);
            flag = true;
            break;
        }
    if (flag == false)  return;

    //先把最初的四面体搞出来
    for (int i = 0;i < 4;i++)
    {
        Face tmp;
        for (int j = 0;j < 3;j++)
            tmp.p[j] = p[(i+j)%4];
        Point pp = p[(i+3)%4];
        res[resn++] = tmp;
    }
}

int CalcFace(Face f[],int n) //计算凸包有多少个面
{
    int res = 0;
    return res;
}

int n,resn;
Point p[300];
Face res[300];

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 0;i < n;i++)
            scanf("%lf%lf%lf",&p[i].x,&p[i].y,&p[i].z);
        ConvexHull(p,n,res,resn);
        printf("%d\n",CalcFace(res,resn));
    }
    return 0;
}
