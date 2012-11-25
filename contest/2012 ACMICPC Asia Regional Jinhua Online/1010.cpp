#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

const int maxn = 1860100;
int wx[maxn],wy[maxn],*x,*y,wss[maxn],wv[maxn];

bool cmp(int *r,int n,int a,int b,int l)
{
    return a+l<n && b+l<n && r[a]==r[b]&&r[a+l]==r[b+l];
}
void da(int str[],int sa[],int rank[],int n,int m)
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
}

int n,q;
char buf[100],name[30000][70];
int gen[30000],fa[30000],rk[30000];
int stack[30000],pos[30000],top;
int str[maxn],sa[maxn],rank[maxn],slen;
vector<int> ch[30000];

bool cmp1(const int& a,const int& b)
{
    return rk[a] < rk[b];
}

void output(int pos,int dep)
{
    for (int i = 0;i < dep;i++)
        printf(".");
    printf("%s\n",name[pos]);
    for (int i = 0;i < ch[pos].size();i++)
        output(ch[pos][i],dep+1);
}

map<pair<int,int>, int> namelist;
const int mut[2] = {127,131};
const int mod[2] = {1000000007,1000000009};

pair<int,int> calchash(char s[])
{
    pair<int,int> res = make_pair(0,0);
    for (int i = 0;s[i] != 0;i++)
    {
        res.first = ((long long)res.first*mut[0]+s[i])%mod[0];
        res.second = ((long long)res.second*mut[1]+s[i])%mod[1];
    }
    return res;
}

int getid(char s[])
{
    return namelist[calchash(s)];
}

int f[30000][20];
void dfs(int u)
{
    f[u][0]=fa[0];
    for (int i=1;i<20;i++)
        f[u][i]=0;
    for (int tmp=fa[u],num=1;gen[tmp];tmp=f[u][num++])
        f[u][num]=f[tmp][num-1];
    for (int i=0;i<ch[u].size();i++)
    {
        int v=ch[u][i];
        dfs(v);
    }
}
int lca(int a,int b)
{
    if (gen[a]>gen[b])
        swap(a,b);
    int ga=gen[a],gb=gen[b];
    for (int det=gb-ga,i=0;det;det>>=1,i++)
        if (det&1)
            b=f[b][i];
    if (a==b)
        return a;
    for (int i=19;i>=0;i--)
    {
        if (f[a][i]==f[b][i])
            continue;
        a=f[a][i];
        b=f[b][i];
    }
    return fa[a];
}
int main()
{
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        top = 0;
        slen = 0;
        namelist.clear();
        for (int i = 0;i < n;i++)
        {
            ch[i].clear();
            scanf("%s",buf);
            gen[i] = 0;
            for (;buf[gen[i]] == '.';gen[i]++);
            sscanf(buf+gen[i],"%s",name[i]);
            namelist[calchash(name[i])] = i;
            while (top > 0 && gen[stack[top-1]] >= gen[i])
                top--;
            if (top == 0)
                fa[i] = -1;
            else
                fa[i] = stack[top-1];
            stack[top++] = i;

            pos[i] = slen;
            for (int j = 0;name[i][j] != 0;j++)
                str[slen++] = name[i][j];
            str[slen++] = '#';
        }
        str[slen] = 0;
        da(str,sa,rank,slen,128);

        for (int i = 0;i < n;i++)
        {
            rk[i] = rank[pos[i]];
            if (fa[i] != -1)
                ch[fa[i]].push_back(i);
        }
        for (int i = 0;i < n;i++)
            sort(ch[i].begin(),ch[i].end(),cmp1);
        fa[0]=0;
        dfs(0);
        scanf("%d",&q);
        for (int i = 0;i < q;i++)
        {
            scanf("%s",buf);
            if (strcmp(buf,"L") == 0)
                output(0,0);
            else if (strcmp(buf,"b") == 0)
            {
                scanf("%s",buf);
                int id = getid(buf);
                if (id==0)
                {
                    puts("1");
                    continue;
                }
                printf("%d\n",ch[fa[id]].size());
            }
            else if (strcmp(buf,"c") == 0)
            {
                scanf("%s",buf);
                int ida = getid(buf);
                scanf("%s",buf);
                int idb = getid(buf);
                int L=lca(ida,idb);
                if (L==ida)
                    L=fa[ida];
                else if (L==idb)
                    L=fa[idb];
                printf("%s\n",name[L]);
            }
        }
    }
	return 0;
}
