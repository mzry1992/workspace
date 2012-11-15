#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,a,b;

int gcd(int a,int b)
{
    return (b == 0)?a:gcd(a,b);
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&a,&b);
        a = gcd(a,b);

    }
    return 0;
}
