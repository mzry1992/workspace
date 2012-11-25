#include<cstdio>
#include<queue>
using namespace std;
long long dp[50000];
int c[50000],d[50000];
class cmp
{
public:
    bool operator()(const int &a,const int &b)
    {
        return dp[a]>dp[b];
    }
};
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=0;i<n;i++)
            scanf("%d",&c[i]);
        for (int i=0;i<n;i++)
            scanf("%d",&d[i]);
        dp[0]=c[0];
        long long ans=0x7fffffffffffffffLL;
        priority_queue<int,vector<int>,cmp> que;
        que.push(0);
        for (int i=1;i<n;i++)
        {
            while (!que.empty() && que.top()+d[que.top()]<i)
                que.pop();
            dp[i]=dp[que.top()]+c[i];
            if (i+d[i]>=n)
                ans=min(ans,dp[i]);
            que.push(i);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
