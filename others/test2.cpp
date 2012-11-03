#include <iostream>
#include <cstdio>
using namespace std;

const int maxn=64,maxm=10000+1;
typedef unsigned __int64 lld;

lld a[maxm];
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

int n;

int main()
{
    int cas=0,cass;
    for (scanf("%d",&cass); cass--;)
    {
        scanf("%d",&n);
        int i,j,k;
        for (i=0; i<n; i++)
            scanf("%I64u",a+i);
        cas++;
        printf("Case #%d:\n",cas);
        k=gaus(n);
        int q;
        for (scanf("%d",&q); q--;)
        {
            lld ask;
            scanf("%I64u",&ask);
            if (k<n)
                if (ask==1)
                {
                    puts("0");
                    continue;
                }
                else
                    ask=ask-1;
            if (ask>=((lld)1<<k))
            {
                puts("-1");
                continue;
            }
            lld res=0;
            for (i=0; i<k; i++)
                if ((ask>>i)&1)
                    res^=a[k-i-1];
            printf("%I64u\n",res);
        }
    }
    return 0;
}

