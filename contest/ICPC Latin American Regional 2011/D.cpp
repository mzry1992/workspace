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

int n,m,len,tree[100001][26],L,cur,l;
char tmp[1001],s[maxn];
int sa[maxn],rank[maxn],height[maxn],dif[26],dis[maxn];
bool end[26];

int main()
{
    while (true)
    {
        scanf("%d%d",&n,&m);
        if (n == 0 && m == 0)   break;
        L = 1;
        for (int i = 0; i < 26; i++)
            tree[0][i] = -1;
        for (int i = 0; i < n; i++)
        {
            scanf("%s",tmp);
            len = strlen(tmp);
            cur = 0;
            for (int j = 0; j < len; j++)
            {
                if (tree[cur][tmp[j]-'a'] == -1)
                {
                    for (int k = 0; k < 26; k++)
                        tree[L][k] = -1;
                    tree[cur][tmp[j]-'a'] = L++;
                }
                cur = tree[cur][tmp[j]-'a'];
            }
        }
        memset(end,false,sizeof(end));
        l = 0;
        for (int i = 0; i < m; i++)
        {
            scanf("%s",tmp);
            len = strlen(tmp);
            end[tmp[len-1]-'a'] = true;
            for (int j = 0; j < len; j++)
            {
                dis[l] = len-j;
                s[l++] = tmp[j];
            }
            s[l++] = '#';
        }
        s[l] = 0;
        da(s,sa,rank,height,l,128);
        for (int i = 0; i < 26; i++)
            dif[i] = 0;
        for (int i = 1; i < l; i++)
            if (s[sa[i]]-'a' != '#')
            {
                dif[s[sa[i]]-'a']++;
                if (dis[sa[i]] == dis[sa[i-1]] && height[i] > dis[sa[i]])
                    dif[s[sa[i]]-'a']--;
            }
        long long res = 0;
        for (int i = 1;i < L;i++)
        {
            for (int j = 0;j < 26;j++)
            {
                if (tree[i][j] == -1)
                    res += dif[j];
                else if (end[j] == true)
                    res ++;
            }
        }
        printf("%lld\n",res);
    }
    return 0;
}
