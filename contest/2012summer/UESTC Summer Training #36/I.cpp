#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 10000;
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
    for (i=0;i < m;i++) wss[i] = 0;
    for (i=0;i < n;i++) wss[x[i]=s[i]]++;
    for (i=1;i < m;i++) wss[i] += wss[i-1];
    for (i=n-1;i >= 0;i--)  sa[--wss[x[i]]] = i;
    for (j=1,p=1;p<n&&j<n;j*=2,m=p)
    {
        for (i=n-j,p=0;i < n;i++)   y[p++] = i;
        for (i=0;i < n;i++) if (sa[i]-j >= 0)   y[p++] = sa[i]-j;
        for (i=0;i < n;i++) wv[i] = x[y[i]];
        for (i=0;i < m;i++) wss[i] = 0;
        for (i=0;i < n;i++) wss[wv[i]]++;
        for (i=1;i < m;i++) wss[i] += wss[i-1];
        for (i=n-1;i >= 0;i--)  sa[--wss[wv[i]]] = y[i];
        for (t=x,x=y,y=t,p=1,i=1,x[sa[0]]=0;i < n;i++)
            x[sa[i]] = cmp(y,n,sa[i-1],sa[i],j)?p-1:p++;
    }
    for (int i = 0;i < n;i++)
        rank[sa[i]] = i;
    for (int i = 0,j = 0,k = 0;i < n;height[rank[i++]]=k)
        if (rank[i] > 0)
            for (k?k--:0,j=sa[rank[i]-1];i+k < n && j+k < n && str[i+k] == str[j+k];k++);
}

char ma[maxn];
void Manacher(char s[],int len,int p[])
{
    int l = 0;
    ma[l++] = '.';
    ma[l++] = ',';
    for (int i = 0;i < len;i++)
    {
        ma[l++] = s[i];
        ma[l++] = ',';
    }
    int pnow = 0;
    int pid = 0;
    for (int i = 1;i < l;i++)
    {
        if (pnow > i)
            p[i] = min(p[2*pid-i],pnow-i);
        else
            p[i] = 1;
        for (;ma[i-p[i]] == ma[i+p[i]];p[i]++);
        if (i+p[i] > pnow)
        {
            pnow = i+p[i];
            pid = i;
        }
    }
//    printf("%d %d\n",len,l);
//    puts(ma);
//    for (int i = 0;i < l;i++)
//        printf("%d",p[i]);
//    printf("\n");
}

char a[maxn],b[maxn];
int str[maxn],sa[maxn],rank[maxn],height[maxn],la,lb,len;
int pa[maxn],pb[maxn];

int f[maxn][20],lent[maxn];
void init()
{
    int i,j;
    int k = 1,l = 0;
    for (int i = 0;i < len;i++)
    {
        f[i][0] = height[i];
        if (i+1 > k*2)
        {
            k *= 2;
            l++;
        }
        lent[i+1] = l;
    }
    for (int j = 1;(1<<j)-1 < len;j++)
        for (int i = 0;i+(1<<j)-1 < len;i++)
            f[i][j] = min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
}

int lcp(int x,int y)
{
    if (x > y)
        swap(x,y);
    x++;
    int k = lent[y-x+1];
    return min(f[x][k],f[y-(1<<k)+1][k]);
}

int main()
{
    scanf("%s%s",a,b);
    la = strlen(a);
    lb = strlen(b);
    len = 0;

    str[len++] = '.';
    str[len++] = ',';
    for (int i = 0;i < la;i++)
    {
        str[len++] = a[i];
        str[len++] = ',';
    }

    str[len++] = '#';
    int mid = len;

    str[len++] = '.';
    str[len++] = ',';
    for (int i = 0;i < lb;i++)
    {
        str[len++] = b[i];
        str[len++] = ',';
    }
    str[len] = 0;
    da(str,sa,rank,height,len,256);
    init();

//    for (int i = 0;i < len;i++)
//    {
//        printf("sa = %3d, rank = %3d, height = %3d :",sa[i],rank[i],height[i]);
//        for (int j = sa[i];j < len;j++)
//            printf("%c",str[j]);
//        puts("");
//    }

    Manacher(a,la,pa);
    Manacher(b,lb,pb);

    int reslen = 0,resposa,resposb;

    for (int i = 0;i < (la+1)*2;i++)
        for (int j = 0;j < (lb+1)*2;j++)
        {
            int comlen = min(lcp(rank[i],rank[mid+j]),min(pa[i],pb[j]));
            if (comlen > reslen)
            {
                reslen = comlen;
                resposa = i;
                resposb = j;
            }
        }
    //printf("%d\n",reslen);
    for (int i = resposa-reslen+2;i < resposa+reslen-1;i += 2)
        putchar(str[i]);
    puts("");
	return 0;
}
