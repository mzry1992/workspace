#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n,m,g[301][301],sum[301][301];

int getsum(int x1,int y1,int x2,int y2)
{
    if (x1 <= x2 && y1 <= y2)
        return sum[x2][y2]-(sum[x1-1][y2]+sum[x2][y1-1]-sum[x1-1][y1-1]);
    else
        return 0;
}

int Abs(int x)
{
    if (x < 0)  return -x;
    return x;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&n,&m);
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= m;j++)
                scanf("%d",&g[i][j]);
        memset(sum,0,sizeof(sum));
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= m;j++)
                sum[i][j] = sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+g[i][j];
        int res = 0;
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= m;j++)
                for (int k = 2;k <= min(n-i+1,m-j+1);k++)
                    if (getsum(i,j,i,j+k-1) == k && getsum(i,j,i+k-1,j) == k
                        && getsum(i+k-1,j,i+k-1,j+k-1) == k && getsum(i,j+k-1,i+k-1,j+k-1) == k)
                            if (Abs(2*getsum(i+1,j+1,i+k-2,j+k-2)-(k-2)*(k-2)) <= 1)
                                res++;
        printf("%d\n",res);
    }
}
