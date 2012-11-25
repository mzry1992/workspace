#include<cstdio>
#include<algorithm>
using namespace std;
int N;
int fac[100],num[100];
void getFactor(int x)
{
    N=0;
    for (int i=2;i<=x;i++)
        if (x%i==0)
        {
            fac[N]=i;
            num[N]=0;
            while (x%i==0)
            {
                num[N]++;
                x/=i;
            }
            N++;
        }
}

char ts[1000];

int getval(char ch)
{
    if (ch >= '0' && ch <= '9') return ch-'0';
    if (ch >= 'A' && ch <= 'Z') return ch-'A'+10;
    if (ch >= 'a' && ch <= 'z')
        return ch-'a'+36;
}

long long gao(int k)
{
    long long res = 0;
    for (int i = 0;ts[i] != 0;i++)
        res = res*k+getval(ts[i]);
    return res;
}

int main()
{
    long long s;
    int k;
    while (scanf("%s%d",ts,&k)!=EOF)
    {
        getFactor(k);
        int mx=0;
        long long ans=0x7fffffffffffffffLL;
        s = gao(k);
        //printf("%lld\n",s);
        for (int i=0;i<N;i++)
        {
            long long tot=0;
            for (long long t=s;t;t/=fac[i])
                tot+=t/fac[i];
            ans=min(ans,tot/num[i]);
        }
        printf("%lld\n",ans);
    }
    return 0;

}
