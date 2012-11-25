#include<cstdio>
int a[20000000];
int main()
{
    int n,l,d,a,mod;
    while (scanf("%d%d%d%d%d",&n,&l,&d,&b,&mod)!=EOF)
    {
        a[0]=b+d;
        if (a[0]>=mod)
            a[0]-=mod;
        for (int i=1;i<n;i++)
        {
            a[i]=a[i-1]+d;
            if (a[i]>=mod)
                a[i]-=mod;
        }
        sort(a,a+n);
        for (int i=0,p=0;i<n;i++)
        {
            while (i<p && a[p]<=a[i] && a[p]<=L-a[i])
                p++;
            while (p && a[p]>L-a[i])
                p--;
            p++;
            ans=max(ans,p);
        }
        printf("%d\n",ans);
    }
}
