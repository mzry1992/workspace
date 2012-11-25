#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int n,f,c[100],ti[100];
double dp[10002];

int main()
{
	while (scanf("%d%d",&n,&f) != EOF)
	{
	    for (int i = 0;i < n;i++)
	    {
            scanf("%d",&c[i]);
            ti[i] = floor((1.0+sqrt(5.0))/2.0*c[i]*c[i]);
	    }
        for (int i = 10001;i >= f;i--)
        {
            dp[i]=0;
            for (int j = 0;j < n;j++)
                if (c[j] >= i)
                    dp[i] += (1+dp[min(10001,i+c[j])])/n;
                else
                    dp[i] += (double)ti[j]/n;
        }
        printf("%.3f\n",dp[f]);
	}
	return 0;
}
