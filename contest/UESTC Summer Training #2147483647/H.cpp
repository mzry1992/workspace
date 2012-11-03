#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
long long a[251],b[250*251/2],c[250],d[250*251/2],e[250*251/2];
int main()
{
    int n;
    while (scanf("%d",&n),n)
    {
        int m=n*(n+1)/2;
        int p=0,q=0;
        for (int i=0;i<m;i++)
        {
            scanf("%lld",&b[i]);
            if (b[i]&1)
                d[q++]=b[i];
            else
                c[p++]=b[i];
        }
        sort(d,d+q);
        long long g=0;
        for (int i=0;i<p;i++)
            g=__gcd(g,c[i]);
        for (int i=0;i<p;i++)
            c[i]/=g;
        int r=0;
        for (int i=0;i<p;i++)
            for (int j=i+1;j<p;j++)
                e[r++]=c[i]*c[j];
        sort(e,e+r);
        long long tmp = (long long)sqrt((double)(d[0]/e[0]));
        for (int i=0;i<p;i++)
            c[i]*=tmp;
        sort(c,c+p);
        g/=tmp;

        //printf("%lld\n",tmp);

        printf("%lld\n%lld",g,c[0]);
        for (int i=1;i<p;i++)
            printf(" %lld",c[i]);
        puts("");
    }
}
