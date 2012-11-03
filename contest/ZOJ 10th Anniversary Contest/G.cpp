#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 200100;
int wx[maxn],wy[maxn],*x,*y,wss[maxn],wv[maxn];

bool cmp(int *r,int n,int a,int b,int l)
{
    return a+l<n && b+l<n && r[a]==r[b]&&r[a+l]==r[b+l];
}
void da(char str[],int sa[],int rank[],int height[],int n,int m)
{
    char *s = str;
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

char s[100100],t[100100],a[200100];
int totlen,lens,lent,pos,pl,pr,cnt,ll,lr;
int sa[maxn],rank[maxn],height[maxn];
int sum[100100];

int main()
{
    int tt;
    scanf("%d",&tt);
    for (int ft = 1;ft <= tt;ft++)
    {
        scanf("%s",s);
        scanf("%s",t);
        lens = strlen(s);
        lent = strlen(t);
        for (int i = 0;i < lens;i++)
            a[i] = s[i];
        a[lens] = '#';
        for (int i = 0;i < lent;i++)
            a[lens+1+i] = t[i];
        a[lens+1+lent] = 0;
        totlen = lens+1+lent;
        da(a,sa,rank,height,totlen,128);
        //for (int i = 0;i < totlen;i++)
        //    printf("sa = %4d, rank = %4d, height = %4d, s = %s\n",sa[i],rank[sa[i]],height[i],a+sa[i]);
        for (int i = 0;i < totlen;i++)
            if (sa[i] == lens+1)
                pos = i;
        pl = pr = pos;
        ll = lr = lent;
        cnt = 0;
        for (int i = lent-1;i >= 1;i--)
        {
            while (pl > 0 && height[pl] >= i)
            {
                ll = min(ll,height[pl]);
                pl--;
                if (sa[pl] < lens)  cnt++;
            }
            while (pr+1 < totlen && height[pr+1] >= i)
            {
                lr = min(lr,height[pr+1]);
                pr++;
                if (sa[pr] < lens)  cnt++;
            }
            sum[i] = cnt;
            //printf("pl = %4d ,pr = %4d ,cnt = %4d\n",pl,pr,cnt);
        }

        for (int i = 0;i < lens;i++)
            a[i] = s[lens-1-i];
        a[lens] = '#';
        for (int i = 0;i < lent;i++)
            a[lens+1+i] = t[lent-1-i];
        a[lens+1+lent] = 0;
        totlen = lens+1+lent;
        da(a,sa,rank,height,totlen,128);
        //for (int i = 0;i < totlen;i++)
        //    printf("sa = %4d, rank = %4d, height = %4d, s = %s\n",sa[i],rank[sa[i]],height[i],a+sa[i]);
        for (int i = 0;i < totlen;i++)
            if (sa[i] == lens+1)
                pos = i;
        pl = pr = pos;
        ll = lr = lent;
        cnt = 0;
        long long res = 0;
        for (int i = lent-1;i >= 1;i--)
        {
            while (pl > 0 && height[pl] >= i)
            {
                ll = min(ll,height[pl]);
                pl--;
                if (sa[pl] < lens)  cnt++;
            }
            while (pr+1 < totlen && height[pr+1] >= i)
            {
                lr = min(lr,height[pr+1]);
                pr++;
                if (sa[pr] < lens)  cnt++;
            }
            res += (long long)cnt*sum[lent-i];
            //sum[i] = cnt;
            //printf("pl = %4d ,pr = %4d ,cnt = %4d\n",pl,pr,cnt);
        }
        printf("%lld\n",res);
    }
	return 0;
}
