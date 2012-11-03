#include <iostream>
#include <cstdio>
using namespace std;

int n,m;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&n,&m);
        if (n < 2*m)
        {
            puts("NO");
            continue;
        }
        if (n%2 == 1)
        {
            puts("NO");
            continue;
        }
        puts("YES");
    }
}
