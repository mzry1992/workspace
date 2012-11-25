#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

long long f[1001][1001];

bool check(int n)
{
    if (n==1)
        return 0;
    for (int i = 2;i*i <= n;i++)
        if (n%i == 0)
            return false;
    return true;
}
long long sum[1001];
int main()
{
    f[0][0]=1;
    for (int i=1;i<=1000;i++)
        if (check(i))
        {
            for (int j=0;j<=1000;j++)
            {
                f[j][i]+=f[j][i-1];
                for (int k=i;j+k<=1000;k*=i)
                    f[j+k][i]+=f[j][i-1];
            }
        }
        else
            for (int j=0;j<=1000;j++)
                f[j][i]=f[j][i-1];
    sum[0]=1;
    for (int i=1;i<=1000;i++)
        sum[i]=sum[i-1]+f[i][i];

    int n;
    while (scanf("%d",&n) != EOF)
        printf("%I64d\n",sum[n]);
	return 0;
}
