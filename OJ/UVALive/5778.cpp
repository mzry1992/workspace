#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const double pi = acos(-1.0);
struct Point
{
    double x,y;
};

int n;
int c,d[15],s[15];
Point p[15];
double dp[1<<15][15];

double calc(int id,Point now)
{

}

int main()
{
    while (true)
    {
        scanf("%d%lf",&n,&c);
        if (n == 0)	break;
        for (int i = 0; i < (1<<n); i++)
            for (int j = 0; j < n; j++)
                dp[i][j] = -1;
        for (int i = 0; i < n; i++)
        {
            scanf("%lf%lf%lf%lf",&p[i].x,&p[i].y,&d[i],&s[i]);
            d[i] = d[i]/180*pi;

        }
    }
    return 0;
}
