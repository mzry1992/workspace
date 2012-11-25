#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int a[20],tot;

int main()
{
    for (int n = 1;n <= 25;n++)
    {
        int res = 0;
        for (int i = 1;i < (1<<n);i++)
        {
            tot = 0;
            for (int j = 0;j < n;j++)
                if (((i>>j)&1) == 1)
                    a[tot++] = j+1;
            bool flag = true;
            for (int j = 0;j < tot && flag;j++)
                for (int k = j+1;k < tot && flag;k++)
                    if (__gcd(a[j],a[k]) != 1)
                        flag = false;
            if (flag == true)
            {
                int ans = 0;
                for (int j = 0;j < tot;j++)
                    ans += a[j];
                if (n == 17 && ans == 80)
                {
                    for (int j = 0;j < tot;j++)
                        printf("%d ",a[j]);
                    printf("\n");
                }
                res = max(res,ans);
            }
        }
        printf("%d %d\n",n,res);
    }
	return 0;
}
