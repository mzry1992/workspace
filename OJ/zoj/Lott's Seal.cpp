#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const double eps = 1e-10;

int cmp(double a,double b)
{
    if (fabs(a-b) < eps)    return 0;
    if (a < b)  return -1;
    return 1;
}

struct point
{
    double x,y;
    point(){}
    point(double _x,double _y)
    {
        x = (double)_x;
        y = (double)_y;
    }
    friend double operator &(const point& a,const point& b)
    {
        return a.x*b.y-a.y*b.x;
    }
    friend double operator *(const point& a,const point& b)
    {
        return a.x*b.x+a.y*b.y;
    }
    friend point operator -(const point& a,const point& b)
    {
        return point(a.x-b.x,a.y-b.y);
    }
};

point lott;
point img[100000],_img[100000];
int n,_n;
double r,s;

bool conpoint(point p[],int n)
{
    for (int i = 1;i < n;i++)
        if (cmp(p[i].x,p[0].x) != 0 ||
            cmp(p[i].y,p[0].y) != 0)
                return false;
    return true;
}

bool conline(point p[],int n)
{
}

int main()
{
    while (scanf("%lf%lf",&lott.x,&lott.y) != EOF)
    {
        scanf("%d",&_n);
        for (int i = 0;i < _n;i++)
            scanf("%lf%lf",&_img[i].x,&_img[i].y);

    }
	return 0;
}
