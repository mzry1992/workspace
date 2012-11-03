#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

long long dp[1<<16][16];
int a[5][5],pos[16][2],id[5][5];
int tgcd[5][5];

int gcd(int a,int b)
{
    return (b == 0)?a:gcd(b,a%b);
}

int xu,xv,yu,yv,dx,dy,nx,ny,rgcd;

bool check(int u,int v,int sta)
{
    xu = pos[u][0];
    yu = pos[u][1];
    xv = pos[v][0];
    yv = pos[v][1];
    dx = xv-xu;
    dy = yv-yu;
    rgcd = tgcd[abs(dx)][abs(dy)];
    dx /= rgcd;
    dy /= rgcd;
    nx = xu+dx;
    ny = yu+dy;
    while (true)
    {
        if (nx == xv && ny == yv)   break;
        if (a[nx][ny] == 1) return false;
        if (a[nx][ny] == 0)
            if (((sta>>(id[nx][ny]))&1) == 0)   return false;
        nx += dx;
        ny += dy;
    }
    return true;
}

int main()
{
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            tgcd[i][j] = gcd(i,j);
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        int tot=0;
        memset(dp,0,sizeof(dp));
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
            {
                scanf("%d",&a[i][j]);
                if (a[i][j] == 0)
                {
                    dp[1<<tot][tot]=1;
                    id[i][j] = tot;
                    pos[tot][0]=i;
                    pos[tot][1]=j;
                    tot++;
                }
            }
        int L=1<<tot;
        for (int i=1; i<L; i++)
            for (int j=0; j<tot; j++)
                if (((i>>j)&1) == 1)
                    for (int k=0; k<tot; k++)
                        if (((i>>k)&1) == 0 && check(j,k,i))
                            dp[i|(1<<k)][k]+=dp[i][j];
        long long ans=0;
        for (int i=0; i<tot; i++)
            ans+=dp[L-1][i];
        printf("%I64d\n",ans);
    }
    return 0;
}
