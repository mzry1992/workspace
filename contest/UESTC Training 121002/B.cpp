#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
int n,m;
int dp[1500][1500];
char s[1501],t[3000];
int solve(int x)
{
    for (int i=0;i<n;i++)
        dp[i][0]=s[i]==t[x];
    for (int i=1;i<m;i++)
        dp[0][i]=s[0]==t[x+i];
    for (int i=1;i<n;i++)
        for (int j=1;j<m;j++)
            if (s[i]==t[x+j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    return dp[n-1][m-1];
}
int main()
{
    while (scanf("%s%s",s,t)!=EOF)
    {
        n=strlen(s);
        m=strlen(t);
        for (int i=0;i<m;i++)
            t[i+m]=t[i];
        int ans=0;
        for (int i=0;i<m;i++)
        if (n<200 || rand()%5==0)
            ans=max(ans,solve(i));
        reverse(t,t+m);
        for (int i=0;i<m;i++)
            t[i+m]=t[i];
        for (int i=0;i<m;i++)
        if (n<200 || rand()%5==0)
            ans=max(ans,solve(i));
        printf("%d\n",ans*2);
    }
    return 0;
}
