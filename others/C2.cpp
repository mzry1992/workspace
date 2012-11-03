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

const int MAXN=100;
bool visitx[MAXN],visity[MAXN];
int labx[MAXN],laby[MAXN],matx[MAXN],maty[MAXN],slack[MAXN];
int ma[MAXN][MAXN];
bool check(int x,int n)
{
    visitx[x]=1;
    for (int i=0; i<n; i++)
        if (!visity[i])
            if (labx[x]+laby[i]==ma[x][i])
            {
                visity[i]=1;
                if (maty[i]==-1 || check(maty[i],n))
                {
                    matx[x]=i;
                    maty[i]=x;
                    return 1;
                }
            }
            else
                slack[i]=min(slack[i],labx[x]+laby[i]-ma[x][i]);

    return 0;
}
void maintain(int n)
{
    int diff=inf;
    for (int i=0; i<n; i++)
        if (!visity[i])
            diff=min(diff,slack[i]);
    for (int i=0; i<n; i++)
    {
        if (visitx[i])
            labx[i]-=diff;
        if (visity[i])
            laby[i]+=diff;
        else
            slack[i]-=diff;
    }
}
int Kuhn_Munkras(int n)
{
    for (int i=0; i<n; i++)
    {
        labx[i]=-inf;
        for (int j=0; j<n; j++)
            labx[i]=max(labx[i],ma[i][j]);
    }
    memset(laby,0,4*n);
    memset(matx,-1,4*n);
    memset(maty,-1,4*n);
    for (int i=0; i<n; i++)
    {
        memset(visitx,0,n);
        memset(visity,0,n);
        memset(slack,63,4*n);
        while (!check(i,n))
        {
            maintain(n);
            memset(visitx,0,n);
            memset(visity,0,n);
        }
    }
    int ret=0;
    for (int i=0;i<n;i++)
        ret+=labx[i]+laby[i];
    return ret;
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
        memset(ma,0,sizeof(ma));
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
                        ma[j][i] = v[j];
        }
        n = max(n,m);
        printf("%d\n",Kuhn_Munkras(n));
    }
    return 0;
}
