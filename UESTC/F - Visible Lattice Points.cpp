#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
int res[1100];
bool map[1100][1100];

int gcd(int a,int b)
{
    if (a == 0 && b == 0)   return 0;
    if (b == 0) return a;
    return gcd(b,a%b);
}

int main()
{
    memset(map,false,sizeof(map));
    for (int i = 1;i <= 1001;i++)
    for (int j = 1;j <= 1001;j++)
    if (gcd(i-1,j-1) == 1)
        map[i][j] = true;
    res[0] = 1;
    for (int i = 1;i <= 1001;i++)
    {
        res[i] = res[i-1];
        for (int j = 1;j < i;j++)
            res[i] += map[i][j]+map[j][i];
    }
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        printf("%d %d %d\n",ft,n,res[n+1]);
    }
}
