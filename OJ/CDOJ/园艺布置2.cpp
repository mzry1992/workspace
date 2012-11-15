#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m;
long long a[1000001],resa,resb,cura,curb,head,tail,tgcd;
int s[1000001];

long long gcd(long long a,long long b)
{
    if (b == 0) return a;
    return gcd(b,a%b);
}

bool is_left(long long x1,long long y1,long long x2,long long y2,long long x3,long long y3)
{
    return (x2-x1)*(y3-y1)-(x3-x1)*(y2-y1) > 0;
}

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        a[0] = 0;
        for (int i = 1;i <= n;i++)
        {
            scanf("%lld",&a[i]);
            a[i] += a[i-1];
        }
        resa = 0;
        resb = 1;
        head = tail = 0;
        for (int i = 1;i < m;i++)
        {
            while (head < tail && is_left(s[tail-1],a[s[tail-1]],s[tail],a[s[tail]],i,a[i]) == true)    tail--;
            tail++;
            s[tail] = i;
        }
        for (int i = m;i <= n;i++)
        {
            while (head < tail && i-s[head] >= m && is_left(s[head+1],a[s[head+1]],s[head],a[s[head]],i,a[i]) == false) head++;
            while (head < tail && is_left(s[tail-1],a[s[tail-1]],s[tail],a[s[tail]],i,a[i]) == true)    tail--;
            tail++;
            s[tail] = i;
            if (i-s[head] >= m)
            {
                cura = a[i]-a[s[head]];
                curb = i-s[head];
                if (resa*curb < resb*cura)
                {
                    resa = cura;
                    resb = curb;
                }
            }
        }
        tgcd = gcd(resa,resb);
        resa /= tgcd;
        resb /= tgcd;
        if (resb == 1)
            printf("%lld\n",resa);
        else printf("%lld/%lld\n",resa,resb);
    }
}
