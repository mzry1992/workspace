#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int cash,n;
int w[200];
int tot;
bool dp[101000];

int main()
{
    while (scanf("%d%d",&cash,&n) != EOF)
    {
        tot = 0;
        for (int i = 1;i <= n;i++)
        {
            int num,val,base,ttot;
            scanf("%d%d",&num,&val);
            if (num == 0)   continue;
            tot++;
            w[tot] = val;
            base = 1;
            ttot = 1;
            for (int j = 1;;j++)
            {
                base *= 2;
                ttot += base;
                if (ttot <= num)
                {
                    tot++;
                    w[tot] = val*base;
                }
                else
                {
                    tot++;
                    w[tot] = val*(num-(ttot-base));
                    break;
                }

            }
        }
        memset(dp,false,sizeof(dp));
        dp[0] = true;
        for (int i = 1;i <= tot;i++)
        for (int j = cash;j >= w[i];j--)
        if (dp[j-w[i]] == true)
            dp[j] = true;
        for (int i = cash;i >= 0;i--)
        if (dp[i] == true)
        {
            printf("%d\n",i);
            break;
        }
    }
}
