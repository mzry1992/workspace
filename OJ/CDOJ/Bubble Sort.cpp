#include<stdio.h>
#include<string.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
long long a,b;
long long fact[1000006];
long long power(long long a,int b)
{
    long long ans=1,bas=a%20100713;
    while (b>0)
    {
        if (b&1)
            ans=(ans*bas)%20100713;
        b>>=1;
        bas=(bas*bas)%20100713;
    }
    return ans;
}
int main()
{
    int n,m,sum,T,i,j;
    fact[1]=1;
    for (i=2;i<=1000000;i++)
        fact[i]=(fact[i-1]*i)%20100713;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&n,&m);
        a=fact[m];
        b=fact[m+1];
        a=(a*power(m,(n-m))%20100713)%20100713;
        if (n==m)
        {
            cout<<a<<endl;
            continue;
        }
        b=(b*power(m+1,(n-m-1))%20100713)%20100713;
        cout<<(b-a+20100713)%20100713<<endl;
    }
}
