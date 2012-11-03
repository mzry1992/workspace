#include <stdio.h>
int n,a[1000001],i,ft,t;

int main()
{
    for(i=a[1]=1;i<=500000;i++)a[2*i+1]=a[2*i]=(a[2*i-1]+a[i])%1000000000;
    scanf("%d",&t);
    for(ft=1;ft<=t;ft++){scanf("%d",&n);printf("%d\n",a[n]);}
}
