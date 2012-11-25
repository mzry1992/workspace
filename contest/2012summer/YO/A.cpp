#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int prime[10000],tot,res[10001];

int main()
{
    tot = 0;
    for (int i = 2;i < 10000;i++)
    {
        bool flag = true;
        for (int j = 2;j*j <= i;j++)
            if (i%j == 0)
                flag = false;
        if (flag)
            prime[tot++] = i;
    }
    memset(res,0,sizeof(res));
    for (int i = 0;i < tot;i++)
    {
        int sum = 0;
        for (int j = i;j < tot;j++)
        {
            sum += prime[j];
            if (sum > 10000)    break;
            res[sum]++;
        }
    }
    int n;
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        printf("%d\n",res[n]);
    }
	return 0;
}
