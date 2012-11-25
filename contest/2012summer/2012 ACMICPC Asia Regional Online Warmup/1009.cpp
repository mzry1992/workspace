#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int n;
char mp[84][84];
int head[205],e,S,T;
vector<int> num[80];
struct N
{
    int u,v,next;
    int c;
} edge[80*80*2+80*4];
void addedge(int u,int v,int c)
{
    edge[e].u=u;
    edge[e].v=v;
    edge[e].c=c;
    edge[e].next=head[u];
    head[u]=e++;

    edge[e].u=v;
    edge[e].v=u;
    edge[e].c=0;
    edge[e].next=head[v];
    head[v]=e++;
}
const int inf = 1<<29;
int gap[205],low[205],d[205],pre[205],cur[205],pree[205];
int sap(int ss,int tt,int all)
{
    int ret=0;
    bool fail;
    all+=ss;
    memset(low,0,sizeof(low));
    memset(gap,0,sizeof(gap));
    memset(d,0,sizeof(d));
    for(int i=ss; i<all; i++)
        cur[i]=head[i];
    low[ss]=inf;
    gap[ss]=all;
    int u=ss;
    while(d[ss]<all)
    {
        fail=true;
        for(int i=cur[u]; i!=-1; i=edge[i].next)
        {
            int v=edge[i].v;
            cur[u]=i;
            if(edge[i].c&&d[u]==d[v]+1)
            {
                pre[v]=u;
                pree[v]=i;
                low[v]=min(low[u],edge[i].c);
                u=v;
                if(u==tt)
                {
                    do
                    {
                        edge[pree[u]].c-=low[tt];
                        edge[pree[u]^1].c+=low[tt];
                        u=pre[u];
                    }
                    while(u!=ss);
                    ret+=low[tt];
                }
                fail=false;
                break;
            }
        }
        if(fail)
        {
            gap[d[u]]--;
            if(!gap[d[u]])
                return ret;
            d[u]=all;
            for(int i=head[u]; i!=-1; i=edge[i].next)
                if(edge[i].c)
                    d[u]=min(d[u],d[edge[i].v]+1);
            gap[d[u]]++;
            cur[u]=head[u];
            if(u!=ss)
                u=pre[u];
        }
    }
    return ret;
}
bool build(int k)
{
    int i,j;
    memset(head,-1,sizeof(head));
    e=0;
    S=0;
    T=n*2+1;
    for(i=0; i<n; i++)
    {
        addedge(S,i+1,k);
        addedge(i+1+n,T,k);
    }
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            if(mp[i][j]=='Y')
                addedge(i+1,j+1+n,1);
    int res=sap(S,T,n*2+2);
    if(res==n*k)
        return true;
    return false;
}
int ans[82][82];
bool vis[82][82],visrow[82][82];
bool DFS(int x,int y,int res)
{
    if (y == n)
    {
        y = 0;
        x++;
    }
    if (x == res)
        return true;
    for (int i = 0;i < n;i++)
        if (mp[i][y] == 'Y' && vis[y][i] == false && visrow[x][i] == false)
        {
            visrow[x][i] = vis[y][i] = true;

            ans[x][y] = i;
            if (DFS(x,y+1,res)) return true;
            return true;
            visrow[x][i] = vis[y][i] = false;
        }
    return false;
}
int main()
{
    while(scanf("%d",&n)&&n)
    //n = 80;
    {
        memset(mp,0,sizeof(mp));
        int i,j,k;
        for(i=0; i<n; i++)
        {
            num[i].clear();
            //scanf("%s",mp[i]);
            for (j = 0;j < n;j++)
                mp[i][j] = 'Y';
        }

        int l,r,mid;
        l=0;
        r=n;
        while(l<r)
        {
            mid=l+r+1>>1;
            if(build(mid))
                l=mid;
            else
                r=mid-1;
        }
        printf("%d\n",l);
        if(l>0)
        {
            for(i=0; i<n; i++)
                for(j=0; j<n; j++)
                    mp[i][j]='N';
            for(i=0; i<e; i++)
                if(edge[i].u>0&&edge[i].u<=n&&edge[i].v>n&&edge[i].v<=n*2&&edge[i].c==0)
                    mp[edge[i].u-1][edge[i].v-n-1]='Y';
            memset(vis,false,sizeof(vis));
            memset(visrow,false,sizeof(visrow));
            memset(ans,0,sizeof(ans));
            DFS(0,0,l);
            for (i=0; i < l; i++)
            {
                printf("%d",ans[i][0]+1);
                for (j=1; j<n; j++)
                    printf(" %d",ans[i][j]+1);
                printf("\n");
            }
        }
    }
    return 0;
}
