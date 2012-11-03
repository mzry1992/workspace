#include <iostream>
#include <cstdio>
using namespace std;

const double pi = 3.141592653;

int main()
{
    int t,n,l;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&n,&l);
        double ans;
        ans = (double)n*(double)l+2.0*pi;
        printf("%.2lf\n",ans);
    }
}
