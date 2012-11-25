#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

long long a,b,c,d;

long long gcd(long long a,long long b)
{
    if (b == 0) return a;
    return gcd(b,a%b);
}

long long lcm(long long a,long long b)
{
    return a/gcd(a,b)*b;
}

long long ex_gcd(long long a,long long b,long long &x,long long &y)
{
    if (b)
    {
        long long ret = ex_gcd(b,a%b,x,y),tmp = x;
        x = y;
        y = tmp-(a/b)*y;
        return ret;
    }
    else
    {
        x = 1;
        y = 0;
        return a;
    }
}

bool check(long long a,long long b,long long c)
{
    long long g = gcd(a,b);
    if (c%g != 0)   return false;
    long long l = lcm(a,b),x,y;
    ex_gcd(a,b,x,y);
    x *= c/g;
    x %= l/a;
    if (x < 0)  x += l/a;
    y = (c-a*x)/b;
    if (y >= 0)  return true;
    return false;
}

int main()
{
    int totcas;
    scanf("%d",&totcas);
    while (totcas--)
    {
        scanf("%I64d%I64d%I64d%I64d",&a,&b,&c,&d);
        if ((c%lcm(a,b) == 0 && check(a,b,d)) ||
            (d%lcm(a,b) == 0 && check(a,b,c)) ||
            (c%a == 0 && d%b == 0) ||
            (d%a == 0 && c%b == 0))
                puts("YES");
        else
            puts("NO");
    }
	return 0;
}
