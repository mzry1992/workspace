#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m,res,a[101][101];
int mintree[101][101][101];
int maxtree[101][101][101];

void updatamin(int x,int y,int z,int val)
{
    int tmp = y,tmp1 = z;
    while (x <= n)
    {
        y = tmp;
        while (y <= m)
        {
            z = tmp1;
            while (z > 0)
            {
                mintree[x][y][z] = min(mintree[x][y][z],val);
                z -= z&(-z);
            }
            y += y&(-y);
        }
        x += x&(-x);
    }
}

int readmin(int x,int y,int z)
{
    int tmp = y,tmp1 = z;
    int res = 19921005;
    while (x > 0)
    {
        y = tmp;
        while (y > 0)
        {
            z = tmp1;
            while (z <= 100)
            {
                res = min(res,mintree[x][y][z]);
                z += z&(-z);
            }
            y -= y&(-y);
        }
        x -= x&(-x);
    }
    return res;
}

void updatamax(int x,int y,int z,int val)
{
    int tmp = y,tmp1 = z;
    while (x <= n)
    {
        y = tmp;
        while (y <= m)
        {
            z = tmp1;
            while (z > 0)
            {
                maxtree[x][y][z] = max(maxtree[x][y][z],val);
                z -= z&(-z);
            }
            y += y&(-y);
        }
        x += x&(-x);
    }
}

int readmax(int x,int y,int z)
{
    int tmp = y,tmp1 = z;
    int res = -19921005;
    while (x > 0)
    {
        y = tmp;
        while (y > 0)
        {
            z = tmp1;
            while (z <= 100)
            {
                res = max(res,maxtree[x][y][z]);
                z += z&(-z);
            }
            y -= y&(-y);
        }
        x -= x&(-x);
    }
    return res;
}

int dp[101][101][2];

int ABS(int x)
{
    if (x < 0)  return -x;
    return x;
}

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= m;j++)
                scanf("%d",&a[i][j]);
        res = a[1][1];
        memset(mintree,127,sizeof(mintree));
        memset(maxtree,128,sizeof(maxtree));
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= m;j++)
            {
                if (ABS(a[i][j]) == 100)
                {
                    dp[i][j][0] = a[i][j];
                    dp[i][j][1] = -a[i][j];
                }
                else
                {
                    if (readmin(i,j,ABS(a[i][j])+1) >= 19921005)
                        dp[i][j][0] = a[i][j];
                    else
                        dp[i][j][0] = readmin(i,j,ABS(a[i][j])+1)+a[i][j];
                    if (readmax(i,j,ABS(a[i][j])+1) <= -19921005)
                        dp[i][j][1] = -a[i][j];
                    else
                        dp[i][j][1] = readmax(i,j,ABS(a[i][j])+1)-a[i][j];
                }
                updatamax(i,j,ABS(a[i][j]),dp[i][j][0]);
                updatamin(i,j,ABS(a[i][j]),dp[i][j][1]);
                res = max(res,dp[i][j][0]);
            }
        printf("%d\n",res);
    }
}
