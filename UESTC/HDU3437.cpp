#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const double eps = 1e-7;
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
};

int cmp(double a,double b)
{
    if (fabs(a-b) < eps)    return 0;
    if (a < b)  return -1;
    return 1;
}

Point cur;
int n,ni[10];
double h;
Point p[10][10];

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        printf("Case %d: ",ft);
        scanf("%lf%lf%lf",&cur.x,&cur.y,&cur.z);
        scanf("%d",&n);
        for (int i = 0;i < n;i++)
        {

        }
        if (cmp(z,0.0) == 0)
            printf("0.00\n");
        else if (cmp(z,0.0) < 0)
            printf("Forever!\n");
        else
        {

        }
    }
    return 0;
}
