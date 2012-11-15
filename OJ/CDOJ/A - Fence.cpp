#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct Point
{
    double x,y;
};

Point p[100];
double k,h;
int n;

int main()
{
    while (scanf("%lf%lf%d",&k,&h,&n) != EOF)
    {
        for (int i = 0;i < n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
    }
}
