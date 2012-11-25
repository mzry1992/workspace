#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int n,m,a[2000],cost[2000][2000];
int dp[2000][26];

int main()
{
	//while (true)
	{
	    n = 2000;
	    m = 25;
	    //scanf("%d%d",&n,&m);
        //if (n == 0 && m == 0)   break;
        for (int i = 0;i < n;i++)
        {
            //scanf("%d",&a[i]);
            a[i] = rand();
        }
        for (int i = 0;i < n;i++)
        {
            priority_queue<int,vector<int>,greater<int> > Qa;//小根堆，装大数
            priority_queue<int,vector<int>,less<int> > Qb;//大根堆
            int suma,sumb;
            suma = sumb = 0;
            if (a[i] < a[i+1])
            {
                Qa.push(a[i+1]);
                Qb.push(a[i]);
                suma = a[i+1];
                sumb = a[i];
            }
            else
            {
                Qb.push(a[i+1]);
                Qa.push(a[i]);
                sumb = a[i+1];
                suma = a[i];
            }
            cost[i][i] = 0;
            cost[i][i+1] = abs(a[i]-a[i+1]);
            for (int j = i+2;j < n;j++)
            {
                if (Qa.size() <= Qb.size())
                {
                    Qa.push(a[j]);
                    suma += a[j];
                }
                else
                {
                    Qb.push(a[j]);
                    sumb += a[j];
                }
                if (Qa.top() < Qb.top())
                {
                    int ta = Qa.top();Qa.pop();
                    suma -= ta;
                    Qb.push(ta);
                    sumb += ta;
                    int tb = Qb.top();Qb.pop();
                    sumb -= tb;
                    Qa.push(tb);
                    suma += tb;
                }
                int mid;
                if (Qa.size() >= Qb.size())
                    mid = Qa.top();
                else
                    mid = Qb.top();
                cost[i][j] = (suma-mid*Qa.size())+(mid*Qb.size()-sumb);
                //printf("%d %d %d\n",i,j,cost[i][j]);
            }
        }
        memset(dp,63,sizeof(dp));
        for (int i = 0;i < n;i++)
            dp[i][1] = cost[0][i];
        for (int i = 2;i <= m;i++)
            for (int j = i-1;j < n;j++)
                for (int k = i-2;k < j;k++)
                    dp[j][i] = min(dp[j][i],dp[k][i-1]+cost[k+1][j]);
        printf("%d\n",dp[n-1][m]);
	}
	return 0;
}
