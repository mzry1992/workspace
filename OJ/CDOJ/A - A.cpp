#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

long long s,b;

int main()
{
    int ft = 0;
    while (true)
    {
        scanf("%lld%lld",&b,&s);
        if (b == 0 && s == 0)   break;
        if (s > b)
            s = b;
        ft++;
        printf("Case %d: ",ft);
        if (b == 1)
            printf(":-\\\n");
        else if (b < s)
            printf(":-)\n");
        else if (b == s)
            printf(":-|\n");
        else
            printf(":-(\n");
    }
    return 0;
}
