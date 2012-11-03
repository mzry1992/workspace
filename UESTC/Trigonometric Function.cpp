#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

long long a,b,c;
struct fs
{
    long long a,b;
    fs(){}
    fs(long long _a,long long _b)
        {
            a = _a;
            b = _b;
        }
};

fs ca,cb,cc,c0,c1;

long long gcd(long long a,long long b)
{
    return (b == 0)?a:gcd(b,a%b);
}

fs easy(fs a)
{
    long long tgcd = gcd(a.a,a.b);
    return fs(a.a/tgcd,a.b/tgcd);
}

bool check1(long long a)
{
    long long ta = (long long)sqrt((double)a);
    return (ta*ta == a);
}

bool check(fs a)
{
    long long tgcd = gcd(a.a,a.b);
    a.a /= tgcd;
    a.b /= tgcd;
    return (check1(a.a) == true && check1(a.b) == true);
}

fs add(fs a,fs b)
{
    return easy(fs(a.a*b.b+b.a*a.b,a.b*b.b));
}

fs mul(fs a,fs b)
{
    return easy(fs(a.a*b.a,a.b*b.b));
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%lld%lld%lld%*d%*d%*d",&a,&b,&c);
        ca = easy(fs(b*b+c*c-a*a,2*b*c));
        cb = easy(fs(a*a+c*c-b*b,2*a*c));
        cc = easy(fs(a*a+b*b-c*c,2*a*b));
        c1 = add(fs(1,1),fs(-cc.a*cc.a,cc.b*cc.b));
        c0 = mul(add(fs(1,1),fs(-ca.a*ca.a,ca.b*ca.b)),add(fs(1,1),fs(-cb.a*cb.a,cb.b*cb.b)));
        if (check(c1) == true && check(c0) == true)
            printf("YES\n");
        else
            printf("NO\n");
    }
}
