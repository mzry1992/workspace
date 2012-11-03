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

int tree[100000][26],ch[100000],fa[100000],L,sl;
bool end[26];
int n,m;
char tmp[1001],s[maxn];
int sa[maxn],rank[maxn],height[maxn],dis[maxn],dif[26];

void add0()
{
    int now = 0;
    int len = strlen(tmp);
    for (int i = 0; i < len; i++)
    {
        if (tree[now][tmp[i]-'a'] == -1)
        {
            ch[L] = tmp[i]-'a';
            fa[L] = now;
            for (int j = 0; j < 26; j++)
                tree[L][j] = -1;
            tree[now][tmp[i]-'a'] = L++;
        }
        now = tree[now][tmp[i]-'a'];
    }
}

void add1()
{
    int len = strlen(tmp);
    end[tmp[len-1]-'a'] = true;
    for (int j = 0; j < len; j++)
    {
        dis[sl] = len-j;
        s[sl++] = tmp[j];
    }
    dis[sl] = 0;
    s[sl++] = '#';
    s[sl] = 0;
}


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
            add0();
        }
        sl = 0;
        for (int i = 0;i < 26;i++)
            end[i] = false;
        for (int i = 0; i < m; i++)
        {
            scanf("%s",tmp);
            add1();
        }
        da(s,sa,rank,height,sl,128);
        for (int i = 0; i < 26; i++)
            dif[i] = 0;
        for (int i = 1; i < sl; i++)
            if (s[sa[i]]-'a' != '#')
            {
                dif[s[sa[i]]-'a']++;
                if (dis[sa[i]] == dis[sa[i-1]] && height[i] > dis[sa[i]])
                    dif[s[sa[i]]-'a']--;
            }
        long long res = 0;
        for (int i = 1;i < L;i++)
        {
            bool add = false;
            for (int j = 0;j < 26;j++)
                if (tree[i][j] == -1)
                    res += dif[j];
                else
                    add = true;
            if (fa[i] != 0 && add == false && end[ch[i]] == true)
                res++;
        }
        printf("%lld\n",res);
    }
    return 0;
}
