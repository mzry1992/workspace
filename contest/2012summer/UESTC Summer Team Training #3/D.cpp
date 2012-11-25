#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int n,m,h[310][310],a,b;
long long x[310][310],x2[310][310];
int f[310][310][9][9];

void init()
{
    for (int x = 1; x <= n; x++)
        for (int y = 1; y <= m; y++)
            f[x][y][0][0] = h[x][y];
    for (int i=0; (1<<i)<=n; i++)
        for (int j=0; (1<<j)<=m; j++)
            if (i != 0 || j != 0)
                for(int x=1; x+(1<<i)-1<=n; x++)
                    for(int y=1; y+(1<<j)-1<=m; y++)
                    {
                        int tmp=f[x][y][0][0];
                        if(i)
                            tmp=max(tmp,max(f[x][y][i-1][j],f[x+(1<<(i-1))][y][i-1][j]));
                        if(j)
                            tmp=max(tmp,max(f[x][y][i][j-1],f[x][y+(1<<(j-1))][i][j-1]));
                        f[x][y][i][j]=tmp;
                    }
}

int find(int x1,int y1,int x2,int y2)
{
    int ans;
    int t1=floor(log((x2-x1+1)*1.0)/log(2.0));
    int t2=floor(log((y2-y1+1)*1.0)/log(2.0));
    ans=f[x1][y1][0][0];
    if(t1)
        ans=max(ans,max(f[x1][y1][t1][t2],f[x2-(1<<t1)+1][y1][t1][t2]));
    if(t2)
        ans=max(ans,max(f[x1][y1][t1][t2],f[x1][y2-(1<<t2)+1][t1][t2]));
    if(t1&&t2)
        ans=max(ans,f[x2-(1<<t1)+1][y2-(1<<t2)+1][t1][t2]);
    return ans;
}

int main()
{
    int cas = 0;
    while (scanf("%d%d",&n,&m) != EOF)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                scanf("%d",&h[i][j]);
                x[i][j] = x[i-1][j]+x[i][j-1]-x[i-1][j-1]+h[i][j];
                x2[i][j] = x2[i-1][j]+x2[i][j-1]-x2[i-1][j-1]+h[i][j]*h[i][j];
            }
        init();
        printf("Case %d:\n",++cas);
        int Q;
        scanf("%d",&Q);
        for (int fQ = 0; fQ < Q; fQ++)
        {
            scanf("%d%d",&a,&b);
            double ans = 1e100;
            int rx,ry;
            for (int i = a; i <= n; i++)
                for (int j = b; j <= m; j++)
                {
                    int maxx = find(i-a+1,j-b+1,i,j);
                    double tx = (x[i][j]-x[i-a][j]-x[i][j-b]+x[i-a][j-b]-maxx)*1.0/(a*b-1);
                    double tx2 = (x2[i][j]-x2[i-a][j]-x2[i][j-b]+x2[i-a][j-b]-maxx*maxx)*1.0/(a*b-1)-tx*tx;
                    if (tx2 < ans)
                    {
                        rx = i-a+1;
                        ry = j-b+1;
                        ans = tx2;
                    }
                }
            printf("(%d, %d), %.2f\n",rx,ry,ans);
        }
    }
    return 0;
}
