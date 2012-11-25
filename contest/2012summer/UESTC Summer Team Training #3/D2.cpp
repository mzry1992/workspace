#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
#include<vector>
#include<map>
#include<ctime>
#include<set>
using namespace std;
#define ll long long

int f[333][333][9][9];
ll sud[333][333];
int su[333][333];
int n,m;
void RMQ_init()
{
    int i,j,x,y;
    //puts("a");
    for(i=0; (1<<i)<=n; i++)
    {
        for(j=0; (1<<j)<=m; j++)
        {
            if(i==0&&j==0)
                continue;
            for(x=1; x+(1<<i)-1<=n; x++)
            {
                for(y=1; y+(1<<j)-1<=m; y++)
                {
                    int tmp=f[x][y][0][0];
                    if(i)
                        tmp=max(tmp,max(f[x][y][i-1][j],f[x+(1<<(i-1))][y][i-1][j]));
                    if(j)
                        tmp=max(tmp,max(f[x][y][i][j-1],f[x][y+(1<<(j-1))][i][j-1]));
                    //cout<<x<<" "<<y<<" "<<i<<" "<<j<<" "<<tmp<<endl;
                    f[x][y][i][j]=tmp;
                    //printf("%d\n",tmp);
                }
            }
        }
    }
}
int query(int x1,int y1,int x2,int y2)
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
    int cas=1,i,j,x;
    while(~scanf("%d %d",&n,&m))
    {
        printf("Case %d:\n",cas++);
        for(i=1; i<=n; i++)
            for(j=1; j<=m; j++)
            {
                scanf("%d",&x);
                sud[i][j]=sud[i-1][j]+sud[i][j-1]+x*x-sud[i-1][j-1];
                su[i][j]=su[i-1][j]+su[i][j-1]+x-su[i-1][j-1];
                f[i][j][0][0]=x;
            }
        int t;
        RMQ_init();
        scanf("%d",&t);
        while(t--)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            double ans=1e20;
            int ansx,ansy;
            for(int i=1; i<=n-x+1; i++)
                for(int j=1; j<=m-y+1; j++)
                {
                    int ma=query(i,j,i+x-1,j+y-1);
                    //printf("%d\n",ma);
                    double tp=(su[i+x-1][j+y-1]-su[i+x-1][j-1]-su[i-1][j+y-1]+su[i-1][j-1]-ma)*1.0/(x*y-1);
                    double tmp=(sud[i+x-1][j+y-1]-sud[i+x-1][j-1]-sud[i-1][j+y-1]+sud[i-1][j-1]-ma*ma)*1.0/(x*y-1)-tp*tp;
                    if(tmp<ans)
                    {
                        ans=tmp;
                        ansx=i;
                        ansy=j;
                    }
                }
            printf("(%d, %d), %.2f\n",ansx,ansy,ans);
        }

    }

}
