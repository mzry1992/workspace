#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

long long ra,rb;
int n,bit;

long long gcd(long long a,long long b)
{
    if (b == 0) return a;
    return gcd(b,a%b);
}

struct fs
{
    long long a,b;
    fs(){}
    void easy()
        {
            long long tgcd = gcd(a,b);
            a /= tgcd;
            b /= tgcd;
        }
    fs(long long _a,long long _b)
        {
            a = _a;
            b = _b;
            easy();
        }
    fs operator *(const fs& p)
        {
            fs res;
            res.a = a*p.a;
            res.b = b*p.b;
            res.easy();
            return res;
        }
    fs operator +(const fs& p)
        {
            fs res = fs(a*p.b+b*p.a,b*p.b);
            res.easy();
            return res;
        }
    fs operator /(const fs& p)
        {
            fs res = fs(a*p.b,b*p.a);
            res.easy();
            return res;
        }
};

fs r0,r1,r2,tmp;
int l,r,mid,len;

bool check(long long a)
{
    long long tmp = (long long)(sqrt((double)a));
    if (tmp*tmp != a)   return false;
    return true;
}

fs sqrt2(fs now)
{
    fs res;
    long long tmp = (long long)(sqrt((double)now.a));
    res.a = tmp*2;
    tmp = (long long)(sqrt((double)now.b));
    res.b = tmp;
    res.easy();
    return res;
}

int main()
{
    while (scanf("%I64d%I64d%d%d",&ra,&rb,&n,&bit) != EOF)
    {
        if (bit == 1)
        {
            printf("%I64d/1\n",ra);
            continue;
        }
        if (bit == (1<<n)+1)
        {
            printf("%I64d/1\n",rb);
            continue;
        }
        r1 = fs(ra,1);
        r2 = fs(rb,1);
        bit -= 1;
        l = 0;
        r = (1<<n);
        bool hasres = false;
        for (int i = 1;i <= n;i++)
        {
            mid = (l+r)/2;
            tmp = r1*r2;
            if (check(tmp.a) == false || check(tmp.b) == false)  break;
            r0 = (r1*r2)/((r1*r1)+(r2*r2)+sqrt2(r1*r2));
            if (mid == bit)
            {
                printf("%I64d/%I64d\n",r0.a,r0.b);
                hasres = true;
                break;
            }
            if (bit < mid)
            {
                r = mid;
                r2 = r0;
            }
            else
            {
                l = mid;
                r1 = r0;
            }
        }
        if (hasres == false)    printf("Irrational\n");
    }
}
