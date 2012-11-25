#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n,tn,m;
char cmp[20];
const int mod = 100000007;
int val[20];

int power(int x,int y)
{
    int ret = 1;
    for (int a = x%mod;y;y>>=1,a=(long long)a*a%mod)
        if (y&1)
            ret = (long long)ret*a%mod;
    return ret;
}

int getInv(int x)
{
    return power(x,mod-2);
}

int fac[10001001];

int C(int n,int m)
{
    return (long long)fac[n]*getInv(fac[n-m])%mod*getInv(fac[m])%mod;
}

int mut(int sta)
{
    int cnt = 0;
    for (int i = 0;i < n;i++)
        if (((sta>>i)&1) == 0)
            cnt++;
    if (cnt%2 == 0)
        return 1;
    return -1;
}

int calc(int sta)
{
    int nowm = m;
    for (int i = 0;i < n;i++)
        if (((sta>>i)&1) == 0)
            nowm -= (val[i]);
    if (nowm < 0)   return 0;
    return C(tn+nowm-1,tn-1);
}

char buf[1000];

int main()
{
    fac[0] = 1;
    for (int i = 1;i <= 10001000;i++)
        fac[i] = (long long)fac[i-1]*i%mod;
    //freopen("F.in","r",stdin);
    //freopen("F2.out","w",stdout);
    while (scanf("%d%d",&n,&m),n)
    {
        tn = n;
        n = 0;
        gets(buf);
        while (true)
        {
            gets(buf);
            if (strlen(buf) == 0)   break;
            sscanf(buf,"%*s%s%*s%d",cmp,&val[n]);
            if (strcmp(cmp,"less") == 0)
                n++;
            else
                m -= val[n]+1;
        }
        if (m < 0)
        {
            puts("0");
            continue;
        }
        int res = 0;
        for (int i = 0;i < (1<<n);i++)
            res = ((res+calc(i)*mut(i))%mod+mod)%mod;
        printf("%d\n",res);
    }
    return 0;
}

