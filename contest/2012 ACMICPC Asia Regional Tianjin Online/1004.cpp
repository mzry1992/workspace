#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
struct Point
{
    int x,y;
    Point(){}
    Point(int _x,int _y)
    {
        x=_x;
        y=_y;
    }
    int disto(const Point &a)
    {
        double dis2=((double)x-a.x)*((double)x-a.x)+((double)y-a.y)*((double)y-a.y);
        return ceil(sqrt(dis2));
    }
}point[15];
int c[15];
int dp[1<<15][15];
int f[1<<15],d[1<<15],e[1<<15];
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        n--;
        int x,y;
        scanf("%d%d",&x,&y);
        Point st=Point(x,y);
        for (int i=0;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            point[i]=Point(x,y);
        }
        scanf("%*d");
        for (int i=0;i<n;i++)
            scanf("%d",&c[i]);
        memset(dp,63,sizeof(dp));
        int full=(1<<n)-1;
        for (int i=0;i<n;i++)
            dp[1<<i][i]=point[i].disto(st);
        for (int i=0;i<full;i++)
            for (int j=0;j<n;j++)
                if ((i>>j)&1)
                    for (int k=0;k<n;k++)
                        if (!((i>>k)&1))
                            dp[i|(1<<k)][k]=min(dp[i|(1<<k)][k],dp[i][j]+point[j].disto(point[k]));
        for (int i=0;i<=full;i++)
        {
            d[i]=dp[i][0]+point[0].disto(st);
            for (int j=1;j<n;j++)
                d[i]=min(d[i],dp[i][j]+point[j].disto(st));
            e[i]=0;
            for (int j=0;j<n;j++)
                if (i>>j&1)
                    e[i]+=c[j];
        }
        f[0]=0;
        for (int i=1;i<=full;i++)
        {
            f[i]=0x3f3f3f3f;
            for (int j=i;j;j=i&(j-1))
                if (e[j]<=m)
                    f[i]=min(f[i],f[i^j]+1);
        }
        if (f[full]==0x3f3f3f3f)
        {
            puts("-1 -1");
            continue;
        }
        printf("%d ",f[full]);
        f[0]=0;
        for (int i=1;i<=full;i++)
        {
            f[i]=0x3f3f3f3f;
            for (int j=i;j;j=i&(j-1))
                if (e[j]<=m)
                    f[i]=min(f[i],f[i^j]+d[j]);
        }
        printf("%d\n",f[full]);
    }
    return 0;
}
