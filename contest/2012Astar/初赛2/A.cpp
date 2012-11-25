#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn=64,maxm=100000+1;

long long a[maxm];

int gaus(int n,const int m=64)
{
    int i,j,k;
    j=0;
    for (i=m-1; i>=0; i--)
    {
        for (k=j; k<n; k++)
            if ( (a[k]>>i)&1 )
                break;
        if (k<n)
        {
            swap(a[k],a[j]);
            for (k=0; k<n; k++)
                if (k!=j && ( (a[k]>>i)&1 ))
                    a[k]^=a[j];
            j++;
        }
    }
    return j;
}

int n,k;

long long Gao(long long ask)
{
    if (k<n)
        if (ask==1)
            return 0;
        else
            ask=ask-1;
    long long res=0;
    for (int i=0; i<k; i++)
        if ((ask>>i)&1)
            res^=a[k-i-1];
    return res;
}

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i=0; i<n; i++)
            scanf("%lld",&a[i]);
        k=gaus(n);
        if (k < n)
            printf("%lld %lld\n",Gao((1LL<<k)),Gao((1LL<<k)-1));
        else
            printf("%lld %lld\n",Gao((1LL<<k)-1),Gao((1LL<<k)-2));
    }
    return 0;
}

