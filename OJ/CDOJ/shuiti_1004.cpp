#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int t;
    int m,n,b;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d%d",&m,&n,&b);
        if (m%b == 0)
        {
            printf("YES\n");
            continue;
        }
        if (n%b == 0)
        {
            printf("YES\n");
            continue;
        }
        printf("NO\n");
    }
}
