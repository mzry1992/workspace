#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 5000;
int wx[maxn],wy[maxn],*x,*y,wss[maxn],wv[maxn];

bool cmp(int *r,int n,int a,int b,int l)
{
    return a+l < n && b+l < n && r[a] == r[b] && r[a+l] == r[b+l];
}
void da(int str[],int sa[],int rank[],int n,int m)
{
    int *s = str;
    int *x = wx,*y = wy,*t,p;
    int i,j;
    for (i = 0; i < m; i++)   wss[i] = 0;
    for (i = 0; i < n; i++)   wss[x[i] = s[i]]++;
    for (i = 1; i < m; i++)   wss[i] += wss[i-1];
    for (i = n-1; i >= 0; i--)    sa[--wss[x[i]]] = i;
    for (j = 1,p = 1; p < n && j < n; j *= 2,m = p)
    {
        for (i = n-j,p = 0; i < n; i++)
            y[p++] = i;
        for (i = 0; i < n; i++)
            if (sa[i]-j >= 0)
                y[p++] = sa[i]-j;
        for (i = 0; i < n; i++)
            wv[i] = x[y[i]];
        for (i = 0; i < m; i++)
            wss[i] = 0;
        for (i = 0; i < n; i++)
            wss[wv[i]]++;
        for (i = 1; i < m; i++)
            wss[i] += wss[i-1];
        for (i = n-1; i >= 0; i--)
            sa[--wss[wv[i]]] = y[i];
        for (t=x,x=y,y=t,p=1,i=1,x[sa[0]]=0; i < n; i++)
            x[sa[i]] = cmp(y,n,sa[i-1],sa[i],j)?p-1:p++;
    }
    for (i = 0; i < n; i++)
        rank[sa[i]] = i;
}

char s[maxn];
int str[maxn],sa[maxn],rank[maxn];
int a[maxn],sum[maxn];
int main()
{
    int k;
    scanf("%d",&k);
    scanf("%s",s);
    int n=strlen(s);
    for (int i=0; i<n; i++)
        s[n+i]=s[i];
    for (int i = 0; i < 2*n; i++)
        str[i] = s[i];
    da(str,sa,rank,2*n,128);
    int ans=0,pos;
    for (int l=1; l<=n/2; l++)
    {
        for (int j=0; j<n; j++)
            a[j]=s[j]!=s[l+j];
        for (int j=n; j<n+n; j++)
            a[j]=a[j-n];
        sum[0]=a[0];
        for (int j=1; j<n*2; j++)
            sum[j]=sum[j-1]+a[j];
        for (int j=0; j<n; j++)
            if (sum[j+l-1]-sum[j]+a[j]<=k)
                if ((ans==l&&rank[j]<rank[pos])||ans<l)
                {
                    ans=l;
                    pos=j;
                }
    }
    for (int i=pos; i<ans*2+pos; i++)
        putchar(s[i]);
    puts("");
    return 0;
}
