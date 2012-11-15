#include<cstdio>
#include<cstring>
#include<algorithm>
#include<deque>
using namespace std;
int sum[50001],dp[50001],a[50001];
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        int A,B;
        scanf("%d%d",&A,&B);
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            sum[i]=sum[i-1]+a[i];
        }
        deque<pair<int,int> > dq;
        dp[0]=0;
        dq.push_back(make_pair(0,0));//id cost
        int L=0x3fffffff;
        for (int i=1;i<=n;i++)
        {
            while (!dq.empty() && sum[i]-sum[dq.front().first]>=m)
            {
                int tmp=dq.front().first;
                if (L>dp[tmp]-sum[tmp]*A)
                    L=dp[tmp]-sum[tmp]*A;
                dq.pop_front();
            }
            dp[i]=min(sum[i]*B+dq.front().second,sum[i]*A+L);
            int tmp=dp[i]-sum[i]*B;
            while (!dq.empty() && dq.back().second>tmp)
                dq.pop_back();
            dq.push_back(make_pair(i,tmp));
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}
