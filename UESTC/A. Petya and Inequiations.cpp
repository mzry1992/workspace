#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
long long x,y;
long long tx;

int main()
{
    while (scanf("%d%I64d%I64d",&n,&x,&y) != EOF)
    {
        if (y < n)
        {
            printf("-1\n");
            continue;
        }
        tx = n-1+(y-(long long)n+1)*(y-(long long)n+1);
        if (tx < x)
        {
            printf("-1\n");
            continue;
        }
        printf("%I64d\n",y-(long long)n+1);
        for (int i = 1;i <= n-1;i++)
            printf("1\n");
    }
    return 0;
}
