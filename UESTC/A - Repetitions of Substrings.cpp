#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100010;
int wx[maxn],wy[maxn],*x,*y,wss[maxn],wv[maxn];

bool cmp(int *r,int n,int a,int b,int l)
{
    return a+l<n && b+l<n && r[a]==r[b]&&r[a+l]==r[b+l];
}
void da(int str[],int sa[],int rank[],int height[],int n,int m)
{
    int *s = str;
    int *x=wx,*y=wy,*t,p;
    int i,j;
    for(i=0; i<m; i++)wss[i]=0;
    for(i=0; i<n; i++)wss[x[i]=s[i]]++;
    for(i=1; i<m; i++)wss[i]+=wss[i-1];
    for(i=n-1; i>=0; i--)sa[--wss[x[i]]]=i;
    for(j=1,p=1; p<n && j<n; j*=2,m=p)
    {
        for(i=n-j,p=0; i<n; i++)y[p++]=i;
        for(i=0; i<n; i++)if(sa[i]-j>=0)y[p++]=sa[i]-j;
        for(i=0; i<n; i++)wv[i]=x[y[i]];
        for(i=0; i<m; i++)wss[i]=0;
        for(i=0; i<n; i++)wss[wv[i]]++;
        for(i=1; i<m; i++)wss[i]+=wss[i-1];
        for(i=n-1; i>=0; i--)sa[--wss[wv[i]]]=y[i];
        for(t=x,x=y,y=t,p=1,i=1,x[sa[0]]=0; i<n; i++)
            x[sa[i]]=cmp(y,n,sa[i-1],sa[i],j)?p-1:p++;
    }
    for(int i=0; i<n; i++) rank[sa[i]]=i;
    for(int i=0,j=0,k=0; i<n; height[rank[i++]]=k)
        if(rank[i]>0)
            for(k?k--:0,j=sa[rank[i]-1]; i+k < n && j+k < n && str[i+k]==str[j+k]; k++);
}

int n,k,a[maxn],sa[maxn],rank[maxn],height[maxn];
char s[maxn];
int f[maxn][20],lent[maxn],mr[maxn];

void init()
{
    int k = 1,l = 0;
    for (int i = 0; i < n; i++)
    {
        f[i][0] = height[i];
        if (i+1 > k*2)
        {
            k *= 2;
            l++;
        }
        lent[i+1] = l;
    }
    for (int j = 1; (1<<j)-1 < n; j++)
        for (int i = 0; i+(1<<j)-1<n; i++)
            f[i][j] = min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
}

int lcp(int x,int y)
{
    x = rank[x];
    y = rank[y];
    if (x > y)  swap(x,y);
    x++;
    int k = lent[y-x+1];
    return min(f[x][k],f[y-(1<<k)+1][k]);
}

int main()
{
    while (scanf("%s%d",s,&k) != EOF)
    {
        n = strlen(s);
        if (k == 1)
        {
            printf("%lld\n",(long long)n*(long long)(n+1)/2);
			continue;
        }
        for (int i = 0; i < n; i++)
            a[i] = s[i];
        da(a,sa,rank,height,n,256);
        init();
        for (int i = 0;i < n;i++)
            mr[i] = 1;
        for (int len = 1;len*k <= n;len++)
            for (int i = len;i < n;i += len)
                if (mr[i-len] == 1)
                    for (int j = 0;j < len && i-len-j >= 0 && s[i-j] == s[i-len-j];j++)
                    {
                        int now = lcp(i-len-j,i-j);
                        if (now >= len)
                            mr[i-len-j] = max(mr[i-len-j],now/len+1);
                        else
                            break;
                    }
        long long res = 0;
        for (int i = 0;i < n;i++)
            if (mr[i] >= k)
                res += mr[i]-k+1;
        printf("%lld\n",res);
    }
    return 0;
}
