#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

struct Poly
{
    int size;
    long long a[60];
};

int n;
Poly p,res;
const long long mm = 999983LL;

long long gcd(long long a, long long b)
{
    return b ? gcd(b, a % b) : a;
}

long long extendGCD(long long a, long long b, long long& x, long long& y)
{
    if(!b) return x = 1, y = 0, a;
    long long res = extendGCD(b, a % b, x, y), tmp = x;
    x = y, y = tmp - (a / b) * y;
    return res;
}

long long modEquation(long long a, long long b, long long m)
{
	long long x, y;
	y = extendGCD(a, m, x, y);
	while(x < 0) x += m;
	return (x * (b / y)) % m;
}

int getsize(Poly a)
{
    int res = a.size;
    while (a.a[res] == 0)
    {
        res--;
        if (res < 0) break;
    }
    return res;
}

Poly mod(Poly a,Poly b)
{
    Poly res = a;
    long long tgcd,fa,fb;
    while (res.size >= b.size)
    {
        fb = modEquation(b.a[b.size],res.a[res.size],mm);
        for (int i = 0;i <= b.size;i++)
            res.a[i+res.size-b.size] = ((res.a[i+res.size-b.size]-b.a[i]*fb)%mm+mm)%mm;
        res.size = getsize(res);
    }
    return res;
}

Poly gcd(Poly a,Poly b)
{
    return (b.size == -1)?a:gcd(b,mod(a,b));
}

bool flag;

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        flag = true;
        for (int i = 0;i < n;i++)
        {
            scanf("%d",&p.size);
            for (int j = p.size;j >= 0;j--)
            {
                scanf("%lld",&p.a[j]);
                p.a[j] %= mm;
            }
            if (flag == false)  continue;
            if (i == 0)
                res = p;
            else
            {
                res = gcd(res,p);
                if (res.size == 0)  flag = false;
            }
        }
        if (res.size == 0)  printf("NO\n");
        else    printf("YES\n");
    }
}
