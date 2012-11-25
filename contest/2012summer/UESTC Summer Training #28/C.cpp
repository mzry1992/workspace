#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int cnt[16][16];

void DFS(int sta,int nowa,int nowb,int x,int y)
{
    if (y == 2)
    {
        y = 0;
        x++;
    }
    if (x == 2)
    {
        cnt[nowb][sta]++;
        return;
    }
    if (((nowa>>(2*x+y))&1) == 1)
        DFS(sta,nowa,nowb,x,y+1);
    else
    {
        DFS(sta,nowa|(1<<(2*x+y)),nowb|(1<<(2*x+y)),x,y+1);
        if (y+1 < 2)
        {
            if (((nowa>>(2*x+y))&1) == 0 &&
                ((nowa>>(2*x+y+1))&1) == 0)
                    DFS(sta,nowa|(1<<(2*x+y))|(1<<(2*x+y+1)),nowb,x,y+1);
        }
        if (x+1 < 2)
        {
            if (((nowa>>(2*x+y))&1) == 0 &&
                ((nowa>>(2*x+y+2))&1) == 0)
                    DFS(sta,nowa|(1<<(2*x+y))|(1<<(2*x+y+2)),nowb,x,y+1);
        }
    }
}

const int mod = 1000000007;

struct Matrix
{
    long long a[16][16];
    Matrix operator *(const Matrix& b)const
    {
        Matrix res;
        for (int i = 0;i < 16;i++)
            for (int j = 0;j < 16;j++)
            {
                res.a[i][j] = 0;
                for (int k = 0;k < 16;k++)
                    res.a[i][j] = (res.a[i][j]+a[i][k]*b.a[k][j])%mod;
            }
        return res;
    }
    Matrix operator ^(int y)const
    {
        Matrix res,x;
        for (int i = 0;i < 16;i++)
        {
            for (int j = 0;j < 16;j++)
                res.a[i][j] = 0,x.a[i][j] = a[i][j];
            res.a[i][i] = 1;
        }
        for (;y;y>>=1,x = x*x)
            if (y&1)
                res = res*x;
        return res;
    }
};

Matrix base;
long long f[1000001][16];
bool vis[1000001];

void solve(int n)
{
    if (vis[n])
        return;
    solve(n-1);
    vis[n] = true;
    for (int i = 0;i < 16;i++)
        for (int j = 0;j < 16;j++)
            f[n][i] = (f[n][i]+f[n-1][j]*cnt[i][j])%mod;
}

int main()
{
    memset(cnt,0,sizeof(cnt));
	for (int i = 0;i < 16;i++)
        DFS(i,i,0,0,0);
    int totcas;
    memset(vis,false,sizeof(vis));
    for (int n = 0;n <= 1000000;n += 5000)
    {
        for (int i = 0;i < 16;i++)
            for (int j = 0;j < 16;j++)
                base.a[i][j] = cnt[i][j];
        base = base^n;
        for (int i = 0;i < 16;i++)
            f[n][i] = base.a[i][0];
        vis[n] = true;
    }
    scanf("%d",&totcas);
    while (totcas--)
    {
        int n;
        scanf("%d",&n);
        solve(n);
        printf("%lld\n",f[n][0]);
    }
	return 0;
}
