#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;

const int inf=0x3f3f3f3f;
int n,m,v[50],g[50];
int tot;
set<int> a,b;
set<int>::iterator it;

const int MAXN=50;
const int MAX=(1<<27);
bool visx[MAXN],visy[MAXN];
int w[MAXN][MAXN],lx[MAXN],ly[MAXN],pre[MAXN];
int slack[MAXN];
bool dfs(int x)
{
    int t;
    visx[x]=1;
    for(int i=0; i<n; i++)
    {
        if (visy[i]) continue ;
        t=lx[x]+ly[i]-w[x][i];
        if (t==0)
        {
            visy[i]=1;
            if (pre[i]==-1||dfs(pre[i]))
            {
                pre[i]=x;
                return 1;
            }
        }
        else if (slack[i]>t) slack[i]=t;
    }
    return false;
}
void nowpre()
{
    int d=MAX;
    for(int i=0; i<n; i++)
        if (slack[i]<d&&!visy[i]) d=slack[i];
    for(int j=0; j<n; j++)
        if (visx[j]) lx[j]-=d;
    for(int j=0; j<n; j++)
    {
        if (visy[j]) ly[j]+=d;
        else slack[j]-=d;
    }
}
void KM()
{
    for(int i=0; i<n; i++) ly[i]=0;
    for(int i=0; i<n; i++)
    {
        lx[i]=w[i][0];
        for(int j=1; j<n; j++)
            if (w[i][j]>lx[i]) lx[i]=w[i][j];
    }
    for(int i=0; i<n; i++) pre[i]=-1;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++) slack[j]=MAX;
        while(1)
        {
            for(int j=0; j<n; j++) visx[j]=visy[j]=0;
            if (dfs(i)) break;
            nowpre();
        }
    }
}
void output()
{
    int res=0;
    for(int j=0; j<n; ++j)
    {
        res+=w[pre[j]][j];
    }
    printf("%d\n",res);
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1; ft <= t; ft++)
    {
        scanf("%d%d",&n,&m);
        for (int i = 0; i < n; i++)
            scanf("%d",&v[i]);
        memset(w,0,sizeof(w));
        for (int i = 0; i < m; i++)
        {
            int xi;
            scanf("%d",&xi);
            for (int j = 0; j < xi; j++)
                scanf("%d",&g[j]);
            int l,r;
            l = xi/2;
            r = xi-l;
            a.clear();
            for (int j = 0; j < (1<<l); j++)
            {
                tot = 0;
                for (int k = 0; k < l; k++)
                    if (((j>>k)&1) == 1)
                        tot += g[k];
                a.insert(tot);
            }
            b.clear();
            for (int j = 0; j < (1<<r); j++)
            {
                tot = 0;
                for (int k = 0; k < r; k++)
                    if (((j>>k)&1) == 1)
                        tot += g[l+k];
                b.insert(tot);
            }
            for (int j = 0; j < n; j++)
                for (it = a.begin(); it != a.end(); it++)
                    if (b.find(v[j]-*it) != b.end())
                        w[j][i] = v[j];
        }
        n = max(n,m);
        KM();
        output();
    }
    return 0;
}
