#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

map<int,double> ma;
int n,m,k;
int a[1000];
double p[1000];
double dp[1000][51];
double pre[1000][1000];

int main()
{
    while (true)
    {
        scanf("%d%d",&k,&m);
        if (k == 0 && m == 0)   break;
        ma.clear();
        for (int i = 0;i < k;i++)
        {
            int cnt;
            scanf("%d",&cnt);
            for (int j = 0;j < cnt;j++)
            {
                int x;
                double tp;
                scanf("%d%lf",&x,&tp);
                ma[x] += tp;
            }
        }
        n = 0;
        for (map<int,double>::iterator it = ma.begin();it != ma.end();it++)
        {
            a[n] = it->first;
            p[n++] = it->second;
        }
//        for (int i = 0;i < n;i++)
//            printf("%d %.2f\n",a[i],p[i]);

        for (int i = 0;i < n;i++)
        {
            int pnow = i;
            double sum = 0,sp1 = p[i],sp2 = 0;
            pre[i][i] = sum;
            for (int j = i+1;j < n;j++)
            {
                sp2 += p[j];
                sum += p[j]*(a[j]-a[pnow]);

                while (pnow < j && sp1 <= sp2)
                {
                    sum += (sp1-sp2)*(a[pnow+1]-a[pnow]);
                    pnow++;
                    sp1 += p[pnow];
                    sp2 -= p[pnow];
                }

                pre[i][j] = sum;
            }
        }

//        for (int i = 0;i < n;i++)
//        {
//            for (int j = i;j < n;j++)
//                printf("%2d %2d : %.4f\n",i,j,pre[i][j]);
//        }

        for (int i = 0;i < n;i++)
        {
            dp[i][1] = pre[0][i];
            for (int j = 2;j <= m;j++)
            {
                dp[i][j] = 1e100;
                for (int k = 0;k < i;k++)
                    dp[i][j] = min(dp[i][j],dp[k][j-1]+pre[k+1][i]);
            }
        }
        printf("%.2f\n",dp[n-1][m]);
    }
	return 0;
}
