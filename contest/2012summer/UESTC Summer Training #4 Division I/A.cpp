#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
long long f[41][41];
void init()
{
    for (int i=0; i<=40; i++)
        f[i][1]=f[i][0]=1;
    for (int i=2; i<=40; i++)
        for (int j=2; j<=i; j++)
        {
            f[i][j]=0;
            for (int k=1; k<=j; k++)
                f[i][j]+=f[i-k][min(i-k,k)];
        }
}
bool isPrime[1000001];
int prime[1000001];
int L,N;
void getPrime()
{
    L=0;
    memset(isPrime,1,sizeof(isPrime));
    for (int i = 2; i <= 1000000; i++)
        if (isPrime[i])
        {
            prime[L++]=i;
            for (int j = i+i; j <= 1000000; j += i)
                isPrime[j] = 0;
        }
}
long long fac[40];
int num[40];
void getFactor(long long x)
{
    N=0;
    for (int i=0; i<L && (long long)prime[i]*prime[i]<=x; i++)
        if (x%prime[i]==0)
        {
            fac[N]=i;
            num[N]=0;
            while (x%prime[i]==0)
            {
                num[N]++;
                x/=prime[i];
            }
            N++;
        }
    if (x>1)
    {
        num[N]=1;
        fac[N++]=x;
    }
}
int main()
{
    long long n;
    scanf("%I64d",&n);
    init();
    //printf("%I64d\n",f[2][2]);
    getPrime();
    getFactor(n);
    long long ans=1;
    for (int i=0; i<N; i++)
        ans=ans*f[num[i]][num[i]];
    printf("%I64d\n",ans);
    return 0;
}
