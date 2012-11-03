#include <iostream>
#include <cstdio>
#include <cstring>
#include <deque>
using namespace std;

int n,k,a,s[1000],dp[1000][1001],val,pos;
deque<pair<int,int> > Q;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d%d",&n,&k,&a);
        for (int i = 0;i < n;i++)   scanf("%d",&s[i]);
        memset(dp,63,sizeof(dp));
        for (int i = 0;i < 1001;i++)    dp[0][i] = (i-s[0])*(i-s[0]);
        for (int i = 1;i < n;i++)
        {
            Q.clear();
            for (int j = 0;j < 1001;j++)
            {
                val = dp[i-1][j]-a*j;
                pos = j;
                while (true)
                {
                    if (Q.empty())  break;
                    if (Q.front().first >= val)   Q.pop_front();
                    else    break;
                }
                Q.push_front(make_pair(val,pos));
                while (true)
                {
                    if (Q.back().second+k < pos)    Q.pop_back();
                    else    break;
                }
                dp[i][j] = min(dp[i][j],Q.back().first+a*j+(j-s[i])*(j-s[i]));
            }
            Q.clear();
            for (int j = 1000;j >= 0;j--)
            {
                val = dp[i-1][j]+a*j;
                pos = j;
                while (true)
                {
                    if (Q.empty())  break;
                    if (Q.front().first >= val)   Q.pop_front();
                    else    break;
                }
                Q.push_front(make_pair(val,pos));
                while (true)
                {
                    if (pos+k < Q.back().second)    Q.pop_back();
                    else    break;
                }
                dp[i][j] = min(dp[i][j],Q.back().first-a*j+(j-s[i])*(j-s[i]));
            }
        }
        int ans = dp[n-1][0];
        for (int i = 0;i < 1001;i++)
            ans = min(dp[n-1][i],ans);
        printf("%d\n",ans);
    }
    return 0;
}
