#include<stdio.h>
#include<iostream>
using namespace std;
#define ll __int64
const ll maxn=500005;
ll  a[maxn],sum[maxn];
ll  num[maxn],dp[maxn];
ll head,tail;
ll n,m;
ll g(ll a,ll b)
{
    return dp[a]-dp[b]+sum[a]*sum[a]-sum[b]*sum[b];
}
ll s(ll a,ll b)
{
    return 2*(sum[a]-sum[b]);
}
ll front(ll t)
{
    while(head-tail>0&&g(a[tail],a[tail+1])>=t*s(a[tail],a[tail+1]))
        tail++;
    return a[tail];
}
void push(ll t)
{
    while(head-tail>0 && g(t,a[head])*s(a[head],a[head-1]) <=s(t,a[head])*g(a[head],a[head-1]))
        head--;
    a[++head]=t;
}
int main()
{
    ll i,j;
    while(scanf("%I64d%I64d",&n,&m)!=-1)
    {
        sum[0]=0;
        head=0;
        tail=1;
        for(i=1; i<=n; i++)
        {
            scanf("%I64d",&a[i]);
            sum[i]=sum[i-1]+a[i];
        }
        push(0);
        for(i=1; i<=n; i++)
        {
            j=front(sum[i]);
            dp[i]=dp[j]+(sum[i]-sum[j])*(sum[i]-sum[j])+m;
            push(i);
        }
        printf("%I64d\n",dp[n]);
    }
}
