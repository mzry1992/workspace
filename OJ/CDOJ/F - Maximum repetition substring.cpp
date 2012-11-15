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

int n,res,ress,reslen,tres,len0,len1,a[maxn],sa[maxn],rank0[maxn],height0[maxn],rank1[maxn],height1[maxn];
char s[maxn];

int f0[maxn][30],lent0[maxn],f1[maxn][30],lent1[maxn];

void init(int height[maxn],int f[maxn][30],int lent[maxn])
{
    int k = 1,l = 0;
    for (int i = 0;i < n;i++)
    {
        f[i][0] = height[i];
        if (i+1 > k*2)
        {
            k <<= 1;
            l++;
        }
        lent[i+1] = l;
    }
    for (int j = 1;(1<<j)-1 < n;j++)
        for (int i = 0;i+(1<<j)-1 < n;i++)
            f[i][j] = min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
}

int fint(int x,int y,int rank[maxn],int f[maxn][30],int lent[maxn])
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
    int ft = 0;
    while (true)
    {
        scanf("%s",s);
        if (strcmp(s,"#") == 0) break;
        n = strlen(s);
        for (int i = 0;i < n;i++)
            a[i] = s[n-1-i];
        da(a,sa,rank1,height1,n,256);
        init(height1,f1,lent1);
        for (int i = 0;i < n;i++)
            a[i] = s[i];
        da(a,sa,rank0,height0,n,256);
        init(height0,f0,lent0);
        res = 1;
        ress = 0;
        reslen = 1;
        for (int i = 0;i < n;i++)
            if (s[ress] > s[i])
                ress = i;
        for (int len = 1;len < n;len++)
        {
            for (int i = len;i < n;i += len)
            {
                len0 = fint(i-len,i,rank0,f0,lent0);
                len1 = fint(n-1-(i-len),n-1-i,rank1,f1,lent1);
                tres = len0+len1-1;
                if (tres >= len)
                {
                    tres = tres/len+1;
                    if (res < tres)
                    {
                        res = tres;
                        ress = i-len-len1+1;
                        reslen = len*tres;
                    }
                    else if (res == tres)
                    {
                        for (int j = i-len-len1+1;j+len*tres-1 <= i+len0-1;j++)
                            if (rank0[j] < rank0[ress])
                            {
                                ress = j;
                                reslen = len*tres;
                            }
                    }
                }
            }
        }
        printf("Case %d: ",++ft);
        for (int i = ress;i < ress+reslen;i++)
            printf("%c",s[i]);
        printf("\n");
    }
    return 0;
}

