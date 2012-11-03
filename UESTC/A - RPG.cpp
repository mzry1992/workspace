#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MIN(X,Y) (((X)>(Y))?(Y):(X))
using namespace std;

int n,e;
struct equipment
{
    int a,b,c;
}a[20];

int main()
{
    int T;
    scanf("%d",&T);
    for (int ft = 1;ft <= T;ft++)
    {
        scanf("%d",&n);
        int ta,tb,tc;
        ta = tb = tc = 0;
        for (int i = 1;i <= n;i++)
        {
            scanf("%d",&e);
            for (int j = 1;j <= e;j++)
                scanf("%d%d%d",&a[j].a,&a[j].b,&a[j].c);
        }
    }
}
