#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int a[3];

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d%d",&a[0],&a[1],&a[2]);
        sort(a,a+3);
        printf("Case %d: ",ft);
        if (a[2]*a[2] == a[1]*a[1]+a[0]*a[0])
            printf("Right triangle\n");
        else if (a[2]*a[2] > a[1]*a[1]+a[0]*a[0])
            printf("Obtuse triangle\n");
        else
            printf("Acute triangle\n");
    }
}
