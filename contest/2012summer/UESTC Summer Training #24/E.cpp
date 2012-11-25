#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
const int inf=0x3fffffff;
int n,m;
int num[50000];
int lead[50000][3];
bool trap[50000];
int dp[50000][3];
void dfs(int u,int fu)
{
    if (trap[u])
    {
        dp[u][0]=0;
        dp[u][1]=dp[u][2]=inf;
    }
    else if (num[u]==1)
    {
        dp[u][0]=inf;
        dp[u][1]=dp[u][2]=0;
    }
    else if (num[u]==2)
    {
        int v=lead[u][1];
        if (v==fu)
            v=lead[u][0];
        dfs(v,u);
        dp[u][0]=min(dp[v][0],dp[v][2]+1);
        dp[u][1]=dp[v][1];
        dp[u][2]=dp[v][2];
    }
    else
    {
        int l,r;
        for (int i=0;i<3;i++)
            if (lead[u][i]==fu)
            {
                l=lead[u][(i+1)%3];
                r=lead[u][(i+2)%3];
            }
        dfs(l,u);
        dfs(r,u);
        dp[u][0]=min(dp[l][0],dp[l][2]+1)+min(dp[r][0],dp[r][2]+1);
        dp[u][1]=dp[l][1]+dp[r][1];
        dp[u][2]=min(min(dp[l][2],dp[l][0])+dp[r][1],dp[l][1]+min(dp[r][0],dp[r][2]));
    }
}
int main()
{
    while(scanf("%d%d",&n,&m),n)
    {
        int tot=0;
        for(int i=0; i<n; i++)
        {
            trap[i]=false;
            scanf("%d",&num[i]);
            tot+=num[i];
            for(int j=0; j<num[i]; j++)
            {
                scanf("%d",&lead[i][j]);
                lead[i][j]--;
            }
        }
        for(int i=0; i<m; i++)
        {
            int a;
            scanf("%d",&a);
            trap[a-1]=true;
        }
        num[0]=2;
        lead[0][1]=-1;
        dfs(0,-1);
        printf("%d\n",dp[0][0]);
    }
    return 0;
}
