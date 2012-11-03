#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a[2],n,now,flag;

int gcd(int a,int b)
{
    return (b == 0)?a:gcd(b,a%b);
}

int main()
{
    while (scanf("%d%d%d",&a[0],&a[1],&n) != EOF)
    {
        flag = 0;
        for (;;flag = !flag)
        {
            now = gcd(a[flag],n);
            if (now > n)    break;
            n -= now;
        }
        printf("%d\n",!flag);
    }
    return 0;
}
