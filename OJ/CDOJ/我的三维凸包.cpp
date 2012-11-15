#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const double eps = 1e-8;
struct Point3D
{
    double x,y,z;
    Point3D(){}
    Point3D(double _x,double _y,double _z)
        {
            x = _x;
            y = _y;
            z = _z;
        }
    Point3D(Point3D _s,Point3D _e)
        {
            x = _e.x-_s.x;
            y = _e.y-_s.y;
            z = _e.z-_s.z;
        }
    double Length()
        {
            return sqrt(x*x+y*y+z*z);
        }
};

Point3D xmult(Point3D a,Point3D b)
{
    return Point3D(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x);
}

double pmult(Point3D a,Point3D b)
{
    return a.x*b.x+a.y*b.y+a.z*b.z;
}

int cmp(double a,double b)
{
    if (fabs(a-b) < eps)    return 0;
    if (a < b)  return -1;
    return 1;
}

double volume(Point3D a,Point3D b,Point3D c,Point3D d)
{
    return pmult(Point3D(a,d),xmult(Point3D(a,b),Point3D(a,c)))/6.0;
}

Point3D p[300],res[300];
int n,resn;
bool flag;

void Gao()
{
    resn = 0;
    //找两个不同点
    flag = false;
    for (int i = 1;i < n;i++)
        if (cmp(Point3D(p[0],p[i]).Length(),0.0) != 0)
        {
            swap(p[1],p[i]);
            flag = true;
        }
    if (flag == false)  return;
    //找不共线三点
    flag = false;
    for (int i = 2;i < n;i++)
        if (cmp(xmult(Point3D(p[0],p[1]),Point3D(p[0],p[i])).Length(),0.0) != 0)
        {
            swap(p[2],p[i]);
            flag = true;
        }
    if (flag == false)  return;
    //找不共面四点
    flag = false;
    for (int i = 3;i < n;i++)
        if (cmp(volume(p[0],p[1],p[2],p[i]),0.0) != 0)
        {
            swap(p[3],p[i]);
            flag = true;
        }
    if (flag == false)  return;
    resn = 4;
    for (int i = 0;i < 4;i++)
        res[i] = p[i];
    for (int i = 4;i < n;i++)
    {

    }
}

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 0;i < n;i++)
            scanf("%lf%lf%lf",&p[i].x,&p[i].y,&p[i].z);
        Gao();
    }
}
