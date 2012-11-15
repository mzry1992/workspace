#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,f[2000],deep[2000],res;

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 0;i < n;i++)
            scanf("%d",&f[i]);
        for (int i = 0;i < n;i++)
            if (f[i] > 0)
                f[i]--;
        res = 0;
        for (int i = 0;i < n;i++)
        {
            deep[i] = 0;
            for (int cur = i;cur != -1;cur = f[cur])
                deep[i]++;
            res = max(res,deep[i]);
        }
        printf("%d\n",res);
    }
    return 0;
}
