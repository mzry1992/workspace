#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 60*10003;
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

int n,l,len[60];
char dic[60][10001],s[60*10003];
int sa[maxn],rank[maxn],height[maxn],id[maxn],dis[maxn],op[maxn],p[61][10000][60],f[61][10000][60];
struct Ele
{
    int key,id;
    bool operator<(const Ele &a)const
    {
        return key>a.key;
    }
}ele[60];
long long ans[maxn*60];
int main()
{
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        l = 0;
        for (int i = 0;i < n;i++)
        {
            scanf("%s",dic[i]);
            len[i] = strlen(dic[i]);
            for (int j = 0;j < len[i];j++)
            {
                id[l] = i;
                dis[l] = len[i]-j;
                op[l] = j;
                s[l++] = dic[i][j];
            }
            id[l] = n;
            op[l] = 0;
            s[l++] = '#';
        }
        s[l] = 0;
        da(s,sa,rank,height,l,128);
        for (int i = 0;i < n;i++)
            f[id[sa[n-1]]][op[sa[n-1]]][i] = 0;
        for (int i = n;i < l;i++)
        {
            printf("height = %d, %s\n",height[i],s+sa[i]);
            for (int j = 0;j < n;j++)
                f[id[sa[i]]][op[sa[i]]][j] = min(f[id[sa[i-1]]][op[sa[i-1]]][j],min(height[i],dis[sa[i]]));//注意不要发生匹配长度大于串长的情况
            f[id[sa[i]]][op[sa[i]]][id[sa[i]]] = dis[sa[i]];//id[sa[i]]表示i属于原来的哪个串，dis记录这个后缀在原串中的长度
        }
        sa[l] = l;
        id[l] = n;
        op[l] = 0;
        height[l] = 0;
        for (int i = 0;i < n;i++)
            p[id[sa[l]]][op[sa[l]]][i] = 0;
        for (int i = l-1;i >= n;i--)
        {
            for (int j = 0;j < n;j++)
                p[id[sa[i]]][op[sa[i]]][j] = min(p[id[sa[i+1]]][op[sa[i+1]]][j],min(height[i+1],dis[sa[i]]));
            p[id[sa[i]]][op[sa[i]]][id[sa[i]]] = dis[sa[i]];
            for (int j = 0;j < n;j++)
                f[id[sa[i]]][op[sa[i]]][j] = max(p[id[sa[i]]][op[sa[i]]][j],f[id[sa[i]]][op[sa[i]]][j]);
        }
        int l=0;
        for (int i=0;i<n;i++)
            for (int j=0;j<len[i];j++)
            {
                ans[l]=0;
                for (int k=0;k<n;k++)
                {
                    ele[k].id=k;
                    ele[k].key=f[i][j][k];
                }
                sort(ele,ele+n);
                for (int k=0;k<n;k++)
                {
                    if (ele[k].key==0)
                        break;
                    while (k+1<n && ele[k+1].key==ele[k].key)
                        ans[l]|=(1LL<<ele[k++].id);
                    if (k < n)
                        ans[l++]|=(1LL<<ele[k].id);
                    else
                        break;
                    ans[l]=ans[l-1];
                }
            }
        sort(ans,ans+l);
        printf("%d\n",unique(ans,ans+l)-ans);
    }
	return 0;
}
