#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m,t;
int a[30],b[30];

int main()
{
    while (true)
    {
        scanf("%d%d",&n,&m);
        if (n == 0 && m == 0)   break;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for (int i = 1;i <= n;i++)
        {
            scanf("%d",&t);
            a[t]++;
        }
        for (int i = 1;i <= m;i++)
        {
            scanf("%d",&t);
            b[t]++;
        }
        int res = 0;
        for (int i = 1;i <= 20;i++)
            res += i*max(a[i],b[i]);
        printf("%d\n",res);
    }
}
