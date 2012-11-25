#include<cstdio>
int c[20][20];
long long mod;
long long prod(long long x,long long y)
{
    long long ret=0;
    for (;y;x=x*2%mod,y/=2)
        if (y&1)
            ret=(ret+x)%mod;
    return ret;
}
long long power(long long x,int y)
{
    long long ret=1;
    for (;y;x=prod(x,x),y/=2)
        if (y&1)
            ret=prod(ret,x);
    return ret;
}
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    mod=2007;
    for (int i=2;i<=k;i++)
        mod*=i;
    bool flag=1;
    long long ans=0;
    for (int i=0;i<=10;i++)
        c[0][i]=c[i][i]=1;
    for (int i=1;i<=10;i++)
        for (int j=1;j<i;j++)
            c[j][i]=c[j][i-1]+c[j-1][i-1];
    for (int i=k;i;i--,flag=!flag)
        if (flag)
            ans=(ans+prod(c[i][k],power(i,n)))%mod;
        else
            ans=(ans-prod(c[i][k],power(i,n))+mod)%mod;
    printf("%I64d\n",ans/(mod/2007));
    return 0;
}
