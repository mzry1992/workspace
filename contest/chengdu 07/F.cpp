#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

int dp[50][10][1<<10];
int a[50][9];
int n,m;

inline int getbit(int sta,int pos)
{
    return (sta>>pos)&1;
}

inline int setbit(int sta,int pos,int val)
{
    return ((sta>>(pos+1))<<(pos+1))|(val<<pos)|(sta&((1<<pos)-1));
}

int geta(int x,int y)
{
    if (x < 0 || y < 0 || x >= n || y >= m) return 0;
    return a[x][y];
}

void update(int x,int y,int sta,int val)
{
    dp[x][y][sta] = min(dp[x][y][sta],val);
}

inline bool check(int a,int b,int c)
{
    return (a > b && b > c) || (a < b && b < c);
}

int main()
{
    int cas = 1;
    while (scanf("%d%d",&n,&m),n)
    {
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                scanf("%d",&a[i][j]);

        memset(dp,63,sizeof(dp));
        dp[0][0][0] = 0;

        int full = 1<<(m+1);
        int val,l,u,nl,nu,upd;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                for (int sta = 0; sta < full; sta++)
                {
                    val = dp[i][j][sta];
                    if (val == 0x3f3f3f3f)  continue;

                    upd = setbit(setbit(sta,j,0),j+1,0);
                    if (geta(i,j) == 0)
                        update(i,j+1,upd,val);
                    else
                    {
                        l = getbit(sta,j);
                        u = getbit(sta,j+1);

                        if (l == 1)
                        {
                            update(i,j+1,upd,val);

                            if (geta(i,j+1) != 0 && check(geta(i,j-1),geta(i,j),geta(i,j+1)))
                                update(i,j+1,setbit(upd,j+1,1),val);
                        }
                        else if (u == 1)
                        {
                            update(i,j+1,upd,val);

                            if (geta(i+1,j) != 0 && check(geta(i-1,j),geta(i,j),geta(i+1,j)))
                                update(i,j+1,setbit(upd,j,1),val);
                        }
                        else
                        {
                            update(i,j+1,upd,val+1);

                            if (geta(i,j+1) != 0 && geta(i,j) != geta(i,j+1))
                                update(i,j+1,setbit(upd,j+1,1),val+1);

                            if (geta(i+1,j) != 0 && geta(i,j) != geta(i+1,j))
                                update(i,j+1,setbit(upd,j,1),val+1);
                        }
                    }
                }

            if (i+1 == n)   break;
            for (int sta = 0; sta < full; sta++)
            {
                if (getbit(sta,m) == 1) continue;
                update(i+1,0,sta<<1,dp[i][m][sta]);
            }
        }

        printf("Case %d: %d\n",cas++,dp[n-1][m][0]);
    }
    return 0;
}
