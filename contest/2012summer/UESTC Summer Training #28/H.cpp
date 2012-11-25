#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

char s[110];
int l,dp[110];
char buf[20];

int cntlen(int n)
{
    sprintf(buf,"%d",n);
    return strlen(buf);
}

int solve(int l,int r)
{
    int len = r-l+1;
    int res = len;
    for (int i = 1;i < len;i++)
        if (len%i == 0)
        {
            bool flag = true;
            for (int j = 0;j < len && flag;j++)
                if (s[l+j] != s[l+j%i])
                    flag = false;
            if (flag)
                res = min(res,i+2+cntlen(len/i));
        }
    return res;
}

int main()
{
	int totcas;
	scanf("%d",&totcas);
	while (totcas--)
	{
	    scanf("%s",s);
        l = strlen(s);
        for (int i = 0;i < l;i++)
            dp[i] = solve(0,i);
        for (int i = 1;i < l;i++)
            for (int j = 0;j < i;j++)
                dp[i] = min(dp[i],dp[j]+solve(j+1,i));
        printf("%d\n",dp[l-1]);
	}
	return 0;
}
