#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

map<int,int> mp;
char s[10001];
int b,p,n,res;

long long power(long long x,int y)
{
    long long ret = 1;
    for (long long a = x%p; y; y>>=1,a=a*a%p)
        if (y&1)
            ret = ret*a%p;
    return ret;
}

long long getInv(long long x)
{
    return power(x,p-2);
}

int main()
{
    int totcas;
    scanf("%d",&totcas);
    while (totcas--)
    {
        gets(s);
        gets(s);
        scanf("%d%d%d",&b,&p,&n);
        res = 0;
        if (b == 0)
        {
            for (int i = 0; s[i] != 0; i++)
                if (s[i]%p == n)
                    res += i+1;
            printf("%d\n",res);
        }
        else
        {
            long long a = 0,bi = 1,tt,ta;
            mp.clear();
            mp[0] = 1;
            for (int i = 0; s[i] != 0; i++)
            {
                long long inv=getInv(bi);
                a = (a*b+s[i])%p;
                tt = (n-a+p)*inv%p;
                res += mp[tt];

                //printf("%d %d\n",i,mp[tt]);
                ta = a*inv%p;
                mp[ta]++;
                bi = bi*b%p;
            }
            printf("%d\n",res);
        }
    }
    return 0;
}
