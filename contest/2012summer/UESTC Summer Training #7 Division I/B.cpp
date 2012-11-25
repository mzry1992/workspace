#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
int dp[1<<21],sum[1<<21];
int a[21],b[21];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for (int i=0;i<n;i++)
        scanf("%d",&b[i]);
    vector<int> g;
    for (int i=0;i<n;i++)
        if (a[i]!=b[i])
            g.push_back(b[i]-a[i]);
    n=g.size();
    int full=(1<<n)-1;
    for (int i=0;i<=full;i++)
    {
        sum[i]=0;
        for (int j=0;j<n;j++)
            if (i&(1<<j))
                sum[i]+=g[j];
    }
    memset(dp,0,sizeof(dp));
    for (int i=1;i<=full;i++)
        for (int j=0;j<n;j++)
        {
            if (i&(1<<j))
                dp[i]=max(dp[i^(1<<j)]+(sum[i]==0),dp[i]);
        }
    printf("%d\n",n-dp[full]);
    return 0;
}
