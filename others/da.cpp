#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1000;
int wa[maxn],wb[maxn],wv[maxn],wss[maxn];
int cmp(int *r,int a,int b,int l)
{
    return r[a]==r[b]&&r[a+l]==r[b+l];
}
void da2(char *r,int *sa,int n,int m)
{
    int i,j,p,*x=wa,*y=wb,*t;
    for(i=0; i<m; i++) wss[i]=0;
    for(i=0; i<n; i++) wss[x[i]=r[i]]++;
    for(i=1; i<m; i++) wss[i]+=wss[i-1];
    for(i=n-1; i>=0; i--) sa[--wss[x[i]]]=i;
    for(j=1,p=1; p<n; j*=2,m=p)
    {
        for(p=0,i=n-j; i<n; i++) y[p++]=i;
        for(i=0; i<n; i++) if(sa[i]>=j) y[p++]=sa[i]-j;
        /*cout << "===================" << endl;
        for (i = 0;i < p;i++)
            printf("%d ",y[i]);
        printf("\n");
        for (i = 0;i < p;i++)
            printf("%d ",x[i]);
        printf("\n");*/
        for(i=0; i<n; i++) wv[i]=x[y[i]];
        for(i=0; i<m; i++) wss[i]=0;
        for(i=0; i<n; i++) wss[wv[i]]++;
        for(i=1; i<m; i++) wss[i]+=wss[i-1];
        for(i=n-1; i>=0; i--) sa[--wss[wv[i]]]=y[i];
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1; i<n; i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
    return;
}

char s[1010];
int len,sa[1010],sx[1010],sy[1010],rk[1010],cnt[1010];

void xysort(int n,int x[],int y[],int rk[])
{
    for (int i = 0;i < n;i++)
        printf("(%d %d) ",x[i],y[i]);
    printf("\n");
    for (int i = 0;i <= n;i++)   cnt[i] = 0;
    for (int i = 0;i < n;i++)   cnt[y[i]] = 1;
    for (int i = 1;i <= n;i++)   cnt[i] += cnt[i-1];
    for (int i = 0;i < n;i++)   rk[i] = cnt[y[i]];
    for (int i = 0;i < n;i++)
        printf("%d ",rk[i]);
    printf("\n");
}

void da(char s[],int n,int sa[])
{
    for (int i = 0;i < n;i++)
    {
        sx[i] = s[i];
        sy[i] = 0;
    }
    xysort(n,sx,sy,rk);
    for (int i = 1;i < n;i <<= 1)
    {
        for (int j = 0;j < n;j++)
        {
            sx[j] = rk[j];
            sy[j] = (j+i < n)?rk[j+i]:0;
        }
        xysort(n,sx,sy,rk);
    }
}

int main()
{
    scanf("%s",s);
    len = strlen(s);
    da(s,len,sa);
    da2(s,sa,len,128);
    return 0;
}
