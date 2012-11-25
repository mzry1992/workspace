#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 400000;
int wx[maxn],wy[maxn],*x,*y,wss[maxn],wv[maxn];

bool cmp(int *r,int n,int a,int b,int l)
{
    return a+l < n && b+l < n && r[a] == r[b] && r[a+l] == r[b+l];
}

void da(int str[],int sa[],int rank[],int height[],int n,int m)
{
    int *s = str;
    int *x = wx,*y = wy,*t,p;
    int i,j;
    for (i = 0;i < m;i++)   wss[i] = 0;
    for (i = 0;i < n;i++)   wss[x[i]=s[i]]++;
    for (i = 1;i < m;i++)   wss[i] += wss[i-1];
    for (i = n-1;i >= 0;i--)    sa[--wss[x[i]]] = i;
    for (j = 1,p = 1;p < n && j < n;j *= 2,m = p)
    {
        for (i = n-j,p = 0;i < n;i++)   y[p++] = i;
        for (i = 0;i < n;i++)   if (sa[i]-j >= 0)   y[p++] = sa[i]-j;
        for (i = 0;i < n;i++)   wv[i] = x[y[i]];
        for (i = 0;i < m;i++)   wss[i] = 0;
        for (i = 0;i < n;i++)   wss[wv[i]]++;
        for (i = 1;i < m;i++)   wss[i] += wss[i-1];
        for (i = n-1;i >= 0;i--)    sa[--wss[wv[i]]] = y[i];
        for (t = x,x = y,y = t,p = 1,i = 1,x[sa[0]] = 0;i < n;i++)
            x[sa[i]] = cmp(y,n,sa[i-1],sa[i],j)?p-1:p++;
    }
    for (int i = 0;i < n;i++)   rank[sa[i]]=i;
    for (int i = 0,j = 0,k = 0;i < n;height[rank[i++]] = k)
        if (rank[i] > 0)
            for (k?k--:0,j = sa[rank[i]-1];i+k < n && j+k < n && str[i+k] == str[j+k];k++);
}

int str[maxn],sa[maxn],rank[maxn],height[maxn],len,typ[maxn],dist[maxn],tlen;
int lcpb[maxn];
char a[100010],b[100010];
int n;

int main()
{
    freopen("data.in","r",stdin);
    freopen("data1.out","w",stdout);
	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
        scanf("%d",&n);
        len = 0;
//        for (int i = 0;i < 100000;i++)
//            a[i] = rand()%26+'a';
//        a[100000] = 0;
        scanf("%s",a);
        tlen = strlen(a);
        for (int i = 0;a[i] != 0;i++)
        {
            typ[len] = 0;
            dist[len] = tlen-i;
            str[len++] = a[i];
        }
        typ[len] = -1;
        str[len++] = '#';
        for (int i = 0;i < n;i++)
        {
            scanf("%s",b);
            tlen = strlen(b);
            for (int j = 0;b[j] != 0;j++)
            {
                typ[len] = 1;
                dist[len] = tlen-j;
                str[len++] = b[j];
            }
            typ[len] = -1;
            str[len++] = '#';
        }
        str[len] = 0;
        da(str,sa,rank,height,len,128);
        int lcp = 0;
        for (int i = 1;i < len;i++)
        {
            lcp = min(lcp,height[i]);
            if (typ[sa[i]] == 0)
                lcpb[i] = lcp;
            else if (typ[sa[i]] == 1)
                lcp = height[i+1];
        }
        lcp = 0;
        for (int i = len-1;i >= 0;i--)
        {
            if (typ[sa[i]] == 0)
                lcpb[i] = max(lcpb[i],lcp);
            else if (typ[sa[i]] == 1)
                lcp = height[i];
            lcp = min(lcp,height[i]);
        }

        long long ans = 0;
        lcp = 0;
        for (int i = 1;i < len;i++)
        {
            lcp = min(lcp,height[i]);
            if (typ[sa[i]] == 0)
            {
                int mx = max(lcpb[i]+1,lcp+1);
                if (mx <= dist[sa[i]])
                {
                    //printf("i = %d, dist[sa[i]] = %d, mx = %d\n",i,dist[sa[i]],mx);
                    ans += dist[sa[i]]-mx+1;
                }
                lcp = height[i+1];
            }
        }
        printf("Case %d: %I64d\n",cas,ans);

//        for (int i = 0;i < len;i++)
//        {
//            printf("%2d %2d %2d %2d %2d : ",typ[sa[i]],dist[sa[i]],lcpb[i],sa[i],height[i]);
//            for (int j = sa[i];j < len;j++)
//                printf("%c",str[j]);
//            printf("\n");
//        }
	}
	return 0;
}
