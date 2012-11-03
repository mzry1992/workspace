#include<stdio.h>
#include<string.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;
double dp[32][33000];
int main()
{
    int n,m,l,i,j,k;
    double ans;
    while (scanf("%d%d%d",&n,&m,&l)!=EOF ,n||m||l)
    {
        memset(dp,0,sizeof(dp));
        for (i=1;i<=m;i++)
            dp[1][i]=1;
        for (i=1;i<n;i++)
            for (j=i;j<=i*m;j++)
                for (k=1;k<=m;k++)
                {
                    dp[i+1][j+k]+=dp[i][j];
                    //cout<<dp[i][j]<<endl;
                }
        ans=0;
        for (int i=n;i<=n*m;i++)
        {
            if (i-l<=1) ans+=dp[n][i];
            else ans+=dp[n][i]*(i-l);
        }
        printf("%.8lf\n",ans/pow((double)m,n));
    }
}
