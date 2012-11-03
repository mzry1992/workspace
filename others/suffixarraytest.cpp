#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 200010;
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

char s[maxn];
int str[maxn],sa[maxn],rank[maxn],height[maxn];
int len;

int f[maxn][20];
int lent[maxn];
void lcpinit()
{
    int i,j;
    int n = len,k = 1,l = 0;
    for (i = 0; i < n; i++)
    {
        f[i][0] = height[i];
        if (i+1 > k*2)
        {
            k *= 2;
            l++;
        }
        lent[i+1] = l;
    }
    for (j = 1; (1<<j)-1<n; j++)
        for (i = 0; i+(1<<j)-1<n; i++)
            f[i][j] = min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
}
int lcp(int x,int y)
{
    if (x > y)	swap(x,y);
    if (x == y)
        return x-sa[x];//自己和自己lcp当然是自己的长度啦
    x++;
    int k = lent[y-x+1];
    return min(f[x][k],f[y-(1<<k)+1][k]);
}

void getinterv(int pos,int comlen,int& pl,int& pr)
{
    int l,r,mid,cp;
    l = 0;
    r = pos;
    while (l < r)
    {
        mid = l+r>>1;
        cp = lcp(mid,pos);
        if (cp < comlen)
            l = mid+1;
        else
            r = mid;
    }
    pl = l;

    l = pos;
    r = len-1;
    while (l < r)
    {
        mid = l+r+1>>1;
        cp = lcp(pos,mid);
        if (cp < comlen)
            r = mid-1;
        else
            l = mid;
    }
    pr = l;
}

int main()
{
    for (int cas = 0; cas <= 1000; cas++)
    {
        //scanf("%s",s);
        //len = strlen(s);

        len = 100000;
        for (int i = 0; i < len; i++)
            str[i] = rand()%26+'a';
        str[len] = 0;
        da(str,sa,rank,height,len,128);

        //for (int i = 0; i < len; i++)
        //{
        //    printf("%3d : sa = %3d, height = %3d, s = %s\n",i,sa[i],height[i],s+sa[i]);
        //}

        lcpinit();
        int pos,comlen;
        //while (scanf("%d%d",&pos,&comlen) != EOF)
        printf("test %d\n",cas);
        for (int kk = 0; kk < 1000; kk++)
        {
            pos = rand()%len;
            comlen = rand()%(len-sa[pos]);

            int pl,pr,cp;
            cp = len-sa[pos];
            for (pl = pos; pl > 0; pl--)
            {
                cp = min(cp,height[pl]);
                if (cp < comlen)	break;
            }
            cp = len-sa[pos];
            for (pr = pos+1; pr < len; pr++)
            {
                cp = min(cp,height[pr]);
                if (cp < comlen)	break;
            }
            pr--;

            //printf("%d %d\n",pl,pr);

            int tpl,tpr;
            getinterv(pos,comlen,tpl,tpr);
            if (pl != tpl || pr != tpr)
            {
                puts("Fuck");
                return 0;
            }
            //printf("%d %d\n",pl,pr);
        }
    }
    return 0;
}
