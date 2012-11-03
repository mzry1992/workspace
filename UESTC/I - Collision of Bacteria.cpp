#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int n;
struct rec
{
    double x1,x2,y1,y2;
}a[100];
double r,d;

double calcdis(int i,int j)
{
    if (a[j].x1 > a[i].x2)
    {
        if (a[j].y1 > a[i].y2)
            return sqrt((a[j].x1-a[i].x2)*(a[j].x1-a[i].x2)+(a[j].y1-a[i].y2)*(a[j].y1-a[i].y2));
        else if (a[j].y2 < a[i].y1)
            return sqrt((a[j].x1-a[i].x2)*(a[j].x1-a[i].x2)+(a[j].y2-a[i].y1)*(a[j].y2-a[i].y1));
        else return a[j].x1-a[i].x2;
    }
    else if (a[i].x1 > a[j].x2)
    {
        if (a[j].y1 > a[i].y2)
            return sqrt((a[i].x1-a[j].x2)*(a[i].x1-a[j].x2)+(a[j].y1-a[i].y2)*(a[j].y1-a[i].y2));
        else if (a[j].y2 < a[i].y1)
            return sqrt((a[i].x1-a[j].x2)*(a[i].x1-a[j].x2)+(a[j].y2-a[i].y1)*(a[j].y2-a[i].y1));
        else return a[i].x1-a[j].x2;
    }
    else if (a[j].y1 > a[i].y2)
    {
        return a[j].y1-a[i].y2;
    }
    else if (a[i].y1 > a[j].y2)
    {
        return a[i].y1-a[j].y2;
    }
    else return 0.0;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        for (int i = 1;i <= n;i++)
            scanf("%lf%lf%lf%lf",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
        scanf("%lf%lf",&r,&d);
        double tl,tr;
        tl = 0.00;
        tr = 1e8;
        while (tr-tl > 1e-5)
        {
            double mid = (tl+tr)/2.0;
            for (int i = 1;i <= n;i++)
            {
                a[i].x1 -= mid*r;
                a[i].x2 += mid*r;
                a[i].y1 -= mid*r;
                a[i].y2 += mid*r;
            }
            bool flag = false;
            for (int i = 1;i <= n;i++)
            for (int j = i+1;j <= n;j++)
            {
                if (calcdis(i,j) <= d)
                    flag = true;
            }
            for (int i = 1;i <= n;i++)
            {
                a[i].x1 += mid*r;
                a[i].x2 -= mid*r;
                a[i].y1 += mid*r;
                a[i].y2 -= mid*r;
            }
            if (flag == true)
                tr = mid;
            else
                tl = mid;
        }
        printf("Case %d: %.3f\n",ft,tr);
    }
}
