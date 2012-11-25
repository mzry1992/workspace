#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 3000100;
int wx[maxn],wy[maxn],*x,*y,wss[maxn],wv[maxn];

bool cmp(int *r,int n,int a,int b,int l)
{
    return a+l < n && b+l < n && r[a] == r[b] && r[a+l] == r[b+l];
}
void da(int str[],int sa[],int rank[],int height[],int n,int m)
{
    int *s = str;
    int *x = wx,*y = wy,*t,p;
    int i,j,k;
    for (i = 0; i < m; i++)   wss[i] = 0;
    for (i = 0; i < n; i++)   wss[x[i]=s[i]]++;
    for (i = 1; i < m; i++)   wss[i] += wss[i-1];
    for (i = n-1; i >= 0; i--)    sa[--wss[x[i]]] = i;
    for (j = 1,p = 1; p < n && j < n; j *= 2,m = p)
    {
        for (i = n-j,p = 0; i < n; i++)   y[p++] = i;
        for (i = 0; i < n; i++)if (sa[i]-j >= 0)y[p++] = sa[i]-j;
        for (i = 0; i < n; i++)   wv[i] = x[y[i]];
        for (i = 0; i < m; i++)   wss[i] = 0;
        for (i = 0; i < n; i++)   wss[wv[i]]++;
        for (i = 1; i < m; i++)   wss[i] += wss[i-1];
        for (i = n-1; i >= 0; i--)    sa[--wss[wv[i]]] = y[i];
        for (t = x,x = y,y = t,p = 1,i = 1,x[sa[0]] = 0; i < n; i++)
            x[sa[i]] = cmp(y,n,sa[i-1],sa[i],j)?p-1:p++;
    }
    for (i = 0; i < n; i++)   rank[sa[i]] = i;
    for (i = 0,j = 0,k = 0; i < n; height[rank[i++]] = k)
        if (rank[i] > 0)
            for (k?k--:0,j = sa[rank[i]-1]; i+k < n && j+k < n && str[i+k]==str[j+k]; k++);
}

int n,m;
char a[maxn],b[maxn];
int sa[maxn],rank[maxn],height[maxn],ts[maxn];
int pa[maxn],pb[maxn];

void doit(int pa[])
{
    int len = 0;
    for (int i = 0; i < m; i++)
        ts[len++] = b[i];
    ts[len++] = '#';
    for (int i = 0; i < 2*n; i++)
        ts[len++] = a[i];
    da(ts,sa,rank,height,len,256);
    for (int i = 0; i < len; i++)
        if (sa[i] == 0)
        {
            int lcp = m;
            for (int j = i+1; j < len; j++)
            {
                lcp = min(lcp,height[j]);
                if (sa[j] > m)
                    pa[sa[j]-m-1] = lcp;
            }
            lcp = m;
            for (int j = i-1; j >= 0; j--)
            {
                lcp = min(lcp,height[j+1]);
                if (sa[j] > m)
                    pa[sa[j]-m-1] = lcp;
            }
            break;
        }
}

int main()
{

    //scanf("%d%d",&n,&m);
    //scanf("%s%s",a,b);
    n = 1000000;
    m = n-1;
    for (int i = 0;i < n;i++)
        a[i] = 'A';
    for (int i = 0;i < m;i++)
        b[i] = 'A';
    memset(ts,0,sizeof(ts));
    for (int i = 0; i < m; i++)
        ts[i] = ts[m+i] = b[i];
    for (int i = 0; i < n; i++)
        a[n+i] = a[i];
    a[2*n] = 0;
    da(ts,sa,rank,height,2*m,256);
    for (int i = 0; i < 2*m; i++)
        if (sa[i] < m)
        {
            for (int j = sa[i]; j < sa[i]+m; j++)
                b[j-sa[i]] = ts[j];
            break;
        }
    //puts(b);

    //puts(a);

    doit(pa);

    std::reverse(b,b+m);
    std::reverse(a,a+2*n);

    doit(pb);
    std::reverse(pb,pb+2*n);
    std::reverse(a,a+2*n);

    int respos = 0,restim = n+1;
    for (int i = 0; i < n; i++)
        if (pa[i]+pb[i+m-1] >= m-1)
        {
            if (i < restim || n-i < restim)
            {
                respos = i;
                restim = min(i,n-i);
            }
        }
    //while (restim == n+1)   puts("fuck");
    //int diff = 0;
    //for (int j = 0;j < m;j++)
    //    if (a[respos+j] != b[j])
    //        diff++;
    //if (diff < m-1)
    //    printf("%d\n",pa[-50000000]);
    //for (int j = 0; j < n; j++)
    //    putchar(a[respos+j]);
    //puts("");
    return 0;
}
