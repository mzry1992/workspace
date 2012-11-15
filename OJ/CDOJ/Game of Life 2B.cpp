#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

const int step[8][4] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
const long long mod = 1000000009LL;

int totsys,totm,tott,totn;
int sys[11],g[11][21][21];
map<pair<int,int>,int> gl;
long long dp[11][21][21];

int Count(int sta)
{
    int res = 0;
    for (int i = 0;i < 16;i++)
        if (((sta>>i)&1) == 1)
            res++;
    return res;
}

bool CheckIn(int x,int y)
{
    return (x >= 0 && x < 4 && y >= 0 && y < 4);
}

int Get(int arr,int x,int y)
{
    return (arr>>(x*4+y))&1;
}

int Gao(int sta,int tim)
{
    if (gl.find(make_pair(sta,tim)) == gl.end())
    {
        int now = sta,tmp;
        for (int i = 0;i < tim;i++)
        {
            tmp = 0;
            for (int j = 0;j < 4;j++)
                for (int k = 0;k < 4;k++)
                {
                    int count = 0;
                    for (int q = 0;q < 8;q++)
                        if (CheckIn(j+step[q][0],k+step[q][1]) == true)
                            count += Get(now,j+step[q][0],k+step[q][1]);
                    tmp <<= 1;
                    if ((count == 3) || (Get(now,j,k) == 1 && count == 2))
                        tmp |= 1;
                }
            now = tmp;
        }
        gl[make_pair(sta,tim)] = Count(now);
    }
    return gl[make_pair(sta,tim)];
}

int main()
{
    freopen("Game of Life.in","r",stdin);
    freopen("Game of Life3.out","w",stdout);
    gl.clear();
    int t;
    scanf("%d",&t);
    for (int ft = 0;ft < t;ft++)
    {
        scanf("%d%d%d%d",&totsys,&totm,&tott,&totn);
        memset(g,0,sizeof(g));
        for (int i = 1;i <= totsys;i++)
        {
            sys[i] = 0;
            for (int j = 0;j < 16;j++)
            {
                int tmp;
                scanf("%d",&tmp);
                sys[i] = (sys[i]<<1)|tmp;
            }
            for (int j = 0;j < (1<<16);j++)
                if ((j|sys[i]) == j)
                    g[i][Count(j^sys[i])][Gao(j,tott)]++;
        }
        memset(dp,0,sizeof(dp));
        dp[0][0][0] = 1;
        for (int i = 1;i <= totsys;i++)
            for (int j = 0;j <= totm;j++)
                for (int k = 0;k <= totn;k++)
                    for (int q = 0;q <= j;q++)
                        for (int p = 0;p <= k;p++)
                            dp[i][j][k] = (dp[i][j][k]+dp[i-1][j-q][k-p]*g[i][q][p])%mod;
        long long res = 0;
        for (int i = 0;i <= totm;i++)
            res = (res+dp[totsys][i][totn])%mod;
        printf("Case #%d: %I64d\n",ft,res);
    }
    return 0;
}
