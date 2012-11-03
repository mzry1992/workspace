#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int sum[2100];

int main()
{
    sum[0] = 0;
    for (int i = 1;i <= 2009;i++)
    {
        sum[i] = sum[i-1];
        for (int j = 1;j <= 12;j++)
        {
            if (j*j == i%100 || j*j == i%1000)
                sum[i]++;
        }
    }
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",sum[y]-sum[x-1]);
    }
}
