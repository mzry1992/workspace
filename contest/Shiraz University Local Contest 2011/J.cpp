#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

struct Point
{
    double x,y;
    Point() {}
    Point(double _x,double _y)
    {
        x = _x;
        y = _y;
    }
    Point operator -(const Point &b)const
    {
        return Point(x-b.x,y-b.y);
    }
    double operator *(const Point &b)const
    {
        return x*b.y-y*b.x;
    }
    double operator &(const Point &b)const
    {
        return x*b.x+y*b.y;
    }
};

bool is_inter(Point a1,Point a2,Point b1,Point b2)
{
    return ((max(a1.x,a2.x) >= min(b1.x,b2.x)) &&
            (max(b1.x,b2.x) >= min(a1.x,a2.x)) &&
            (max(a1.y,a2.y) >= min(b1.y,b2.y)) &&
            (max(b1.y,b2.y) >= min(a1.y,a2.y)) &&
            (((b1-a1)*(a2-a1))*((b2-a1)*(a2-a1)) <= 0) &&
            (((a1-b1)*(b2-b1))*((a2-b1)*(b2-b1)) <= 0));
}

bool is_simple(Point p[],int n)
{
    for (int i = 0; i < n; i++)
        //p[i] -> p[(i+1)%n]
        for (int j = 0; j < n; j++)
            if (j != i && (j+1)%n != i && j != (i+1)%n)
                if (is_inter(p[i],p[(i+1)%n],p[j],p[(j+1)%n]))
                    return false;
    return true;
}

double calc_dist(Point a,Point b)
{
    return sqrt((a-b)&(a-b));
}

double calc_area(Point p[],int n)
{
    double res = 0;
    for (int i = 0; i < n; i++)
        res += (p[i]*p[(i+1)%n])/2;
    return fabs(res);
}

double calc_perimeter(Point p[],int n)
{
    double res = 0;
    for (int i = 0; i < n; i++)
        res += calc_dist(p[i],p[(i+1)%n]);
    return res;
}

Point p[10],tp[10];
int n,a[10];

int main()
{
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1; cas <= totcas; cas++)
    {
        scanf("%d",&n);
        for (int i = 0; i < n; i++)
        {
            scanf("%lf%lf",&tp[i].x,&tp[i].y);
            a[i] = i;
        }

        double minperimeter = 1e100;
        double minarea = 1e100,minperimeter2 = 1e100;

        do
        {
            for (int i = 0; i < n; i++)
                p[i] = tp[a[i]];
            if (is_simple(p,n))
            {
                double area = calc_area(p,n);
                double perimeter = calc_perimeter(p,n);

                minperimeter = min(minperimeter,perimeter);
                if (area < minarea || (area == minarea && perimeter < minperimeter2))
                {
                    minperimeter2 = perimeter;
                    minarea=area;
                }

                //printf("%.4f %.4f\n",area,perimeter);
            }
        }
        while (next_permutation(a+1,a+n));

        printf("%.4f\n",fabs(minperimeter2-minperimeter));
    }
    return 0;
}

