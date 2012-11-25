#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <deque>
using namespace std;

double dp[100010][2],sum[100010][2];
int n,m;
double f[100010];

int main()
{
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1; cas <= totcas; cas++)
    {
        scanf("%d%d",&n,&m);

        sum[0][1] = sum[0][0] = 0.0;

        dp[0][1] = 1.0;
        dp[0][0] = 0.0;
        for (int i = 1; i <= n; i++)
        {
            sum[i][0] = sum[i-1][0]+dp[i-1][0];
            sum[i][1] = sum[i-1][1]+dp[i-1][1];

            dp[i][0] = sum[i][1]-sum[max(0,i-m)][1];
            dp[i][1] = sum[i][0]-sum[max(0,i-m)][0];
            if (i < m)
                dp[i][1] += m-i;
            dp[i][0] /= m;
            dp[i][1] /= m;
        }
//
//
//        f[0] = 0;
//        for (int i = 1;i <= n;i++)
//        {
//            f[i] = 0;
//            double mm = 1.0;
//            for (int j = 1;j <= m;j++)
//            {
//                mm = min(mm,(i-j) >= 0 ? f[i-j] : 1.0);
//                f[i] += mm;
//            }
//            f[i] /= m;
//            f[i] = 1-f[i];
//        }
//        printf("%.5f\n",f[n]);
        f[0]=0;
        double s=0;
        deque<int> que;
        for (int i =1;i<=n;i++)
        {
            if (!que.empty())
                s-=f[que.front()];
            if (!que.empty() && i-que.front()>m)
                que.pop_front();
            int l=m-1;
            while (!que.empty() && f[i-1]<=f[que.back()])
            {
                int tmp=que.back();
                que.pop_back();
                if (que.empty())
                {
                    s-=l*f[tmp];
                    l=0;
                }
                else
                {
                    s-=(tmp-que.back())*f[tmp];
                    l-=tmp-que.back();
                }
            }
            que.push_back(i-1);
            s+=(m-l)*f[i-1];
            f[i]=1-s/m;
        }

        printf("%.4f %.4f\n",dp[n][0],f[n]);
    }
    return 0;
}

