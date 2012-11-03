#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define cost(X) (((X)>0)?(X):(0))
using namespace std;

int n,cur;
long long a[100001],dp[100001];
bool visit[100001];
queue<int> Q;

int main()
{
    scanf("%d",&n);
    for (int i = 0;i <= n;i++)
    {
        scanf("%lld",&a[i]);
        dp[i] = 100000LL*1000000000LL;
    }
    dp[0] = 0;
    memset(visit,false,sizeof(visit));
    while (!Q.empty())  Q.pop();
    Q.push(0);
    visit[0] = true;
    while (!Q.empty())
    {
        cur = Q.front();
        Q.pop();
        visit[cur] = false;
        for (int i = cur+1;i <= cur+a[cur] && i <= n;i++)
            if (a[i] <= a[cur])
            {
                if (dp[i] > dp[cur])
                {
                    dp[i] = dp[cur];
                    if (visit[i] == false)
                    {
                        Q.push(i);
                        visit[i] = true;
                    }
                }
            }
            else
            {
                if (dp[i] > dp[cur]+cost(a[i]-a[cur]))
                {
                    dp[i] = dp[cur]+cost(a[i]-a[cur]);
                    if (visit[i] == false)
                    {
                        Q.push(i);
                        visit[i] = true;
                    }
                }
                break;
            }
    }
    printf("%lld\n",dp[n]);
}
