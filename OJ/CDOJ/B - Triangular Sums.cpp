#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
long long sum[500];
long long res;

int main()
{
    int t;
    scanf("%d",&t);
    sum[0] = 0;
    for (int i = 1;i <= 301;i++)
        sum[i] = sum[i-1]+i;
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        res = 0;
        for (int i = 1;i <= n;i++)
            res = res+i*sum[i+1];
        printf("%d %d %I64d\n",ft,n,res);
    }
}
