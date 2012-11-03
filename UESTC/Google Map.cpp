#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const double pi = acos(-1.0);
double x,y,lo,la;
int l;

int main()
{
    while (scanf("%lf%lf%d",&lo,&la,&l) != EOF)
    {
        x = lo*pi/180.0;
        y = log(tan(pi/4+(la*pi/180)/2));
        double l1,r1,l2,r2;
        l1 = -180.0*pi/180.0;
        r1 = log(tan(pi/4+(-85.0*pi/180)/2));
        l2 = 180.0*pi/180.0;
        r2 = log(tan(pi/4+(85.0*pi/180)/2));
        printf("t");
        for (int i = 1;i <= l;i++)
        {
            double mid1,mid2;
            mid1 = (l1+l2)/2.0;
            mid2 = (r1+r2)/2.0;
            if ((x < mid1) && (y < mid2))
            {
                printf("t");
                l2 = mid1; r2 = mid2;
                continue;
            }
            if ((x > mid1) && (y < mid2))
            {
                printf("s");
                l1 = mid1; r2 = mid2;
                continue;
            }
            if ((x < mid1) && (y > mid2))
            {
                printf("q");
                r1 = mid2; l2 = mid1;
                continue;
            }
            if ((x > mid1) && (y > mid2))
            {
                printf("r");
                r1 = mid2; l1 = mid1;
                continue;
            }
        }
        printf("\n");
    }
}
