#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = 1<<30;
int n,m;
char s[3];
int prim[20005],pnum;
bool pr[20005];
int dp[20005][3][3];
int ans[3];
void dfs(int sum,int pos)
{
    int i;
    if(dp[sum][pos][pos]!=-1)
        return;
    for(i=0; i<3; i++)
        dp[sum][pos][i]=inf;
    if(!pr[sum])
    {
        dfs(sum+1,(pos+1)%3);
        for(i=0; i<3; i++)
            dp[sum][pos][i]=dp[sum+1][(pos+1)%3][i];
        dp[sum][pos][pos]=min(dp[sum][pos][pos],sum+1);
        for(i=0; i<pnum&&prim[i]<sum; i++)
            if(sum%prim[i]==0)
            {
                dfs(sum/prim[i],(pos+1)%3);
                int tmp=min(dp[sum/prim[i]][(pos+1)%3][pos],sum/prim[i]);
                if(tmp<=dp[sum][pos][pos])
                {
                    int j;
                    for(j=0; j<3; j++)
                        dp[sum][pos][j]=dp[sum/prim[i]][(pos+1)%3][j];
                    dp[sum][pos][pos]=tmp;
                }
            }
    }
    else
    {
        for(i=0; i<3; i++)
            if(i==pos)
                dp[sum][pos][i]=1;
            else
                dp[sum][pos][i]=inf;
    }
}
int main()
{
    memset(pr,false,sizeof(pr));
    pnum=0;
    int i,j;
    for(i=2; i<=20001; i++)
    {
        bool flag=true;
        for(j=2; flag&&j*j<=i; j++)
            if(i%j==0)
                flag=false;
        if(flag)
        {
            prim[pnum++]=i;
            pr[i]=true;
        }
    }
    while(scanf("%d",&n)==1)
    {
        memset(ans,0,sizeof(ans));
        memset(dp,-1,sizeof(dp));
        for(i=0; i<n; i++)
        {
            scanf("%s",s);
            scanf("%d",&m);
            if(m<=1)
            {
                ans[0]++,ans[1]++,ans[2]++;
                continue;
            }
            int st;
            if(s[0]=='O')
                st=0;
            else if(s[0]=='E')
                st=1;
            else if(s[0]=='I')
                st=2;
            dfs(m,st);
            int j;
            for(j=0; j<3; j++)
            {
                if(dp[m][st][j]==inf)
                    ans[j]+=m;
                else
                    ans[j]+=dp[m][st][j];
            }
        }
        printf("%d %d %d\n",ans[0],ans[1],ans[2]);
    }
    return 0;
}
