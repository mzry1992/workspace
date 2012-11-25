#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;
int n;
int head[505],e;
bool vis[505];
stack<int> st;
queue<int> q;
struct M
{
    int v,next;
} edge[505*505],neg[505*505];
void addedge(int u,int v)
{
    edge[e].v=v;
    edge[e].next=head[u];
    head[u]=e++;
}
int h[505],ee;
bool mp[505][505];
void addneg(int u,int v)
{
    neg[ee].v=v;
    neg[ee].next=h[u];
    h[u]=ee++;
}
struct N
{
    int a,b;
    bool flag;
} peo[505];
int qlt[505],dfn[505],low[505];
int ti,num,sum[505],ind[505];
int val[505],dp[505];
void tarjan(int s)
{
    dfn[s]=low[s]=ti++;
    vis[s]=true;
    st.push(s);
    int i,v;
    for(i=head[s]; i!=-1; i=edge[i].next)
    {
        v=edge[i].v;
        if(dfn[v]==-1)
        {
            tarjan(v);
            low[s]=min(low[s],low[v]);
        }
        else if(vis[v])
            low[s]=min(low[s],dfn[v]);
    }
    if(dfn[s]==low[s])
    {
        num++;
        do
        {
            v=st.top();
            st.pop();
            qlt[v]=num;
            val[num]++;
            vis[v]=false;
        }
        while(v!=s);
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        int i,j;
        memset(head,-1,sizeof(head));
        e=0;
        for(i=0; i<n; i++)
        {
            scanf("%d%d",&peo[i].a,&peo[i].b);
            peo[i].flag=true;
            if(peo[i].a+peo[i].b+1>n)
                peo[i].flag=false;
            if(peo[i].flag)
                for(j=0; j<i; j++)
                    if(peo[j].flag)
                    {
                        if(n-peo[i].b<=peo[j].a&&peo[i].b>=n-peo[j].a)
                            addedge(j,i);
                        else if(peo[i].a>=n-peo[j].b&&n-peo[i].a<=peo[j].b)
                            addedge(i,j);
                        else if(peo[i].a==peo[j].a&&peo[i].b==peo[j].b)
                        {
                            addedge(i,j);
                            addedge(j,i);
                        }
                    }
        }
        memset(dfn,-1,sizeof(dfn));
        memset(low,0,sizeof(low));
        memset(qlt,0,sizeof(0));
        memset(vis,false,sizeof(vis));
        memset(val,0,sizeof(val));
        ti=1;
        num=0;
        for(i=0; i<n; i++)
            if(dfn[i]==-1)
                tarjan(i);
        memset(h,-1,sizeof(h));
        ee=0;
        memset(mp,false,sizeof(mp));
        memset(ind,0,sizeof(ind));
        for(i=0; i<n; i++)
        {
            if(peo[i].flag)
            {
                int tmp=n-peo[i].a-peo[i].b;
                val[qlt[i]]=min(val[qlt[i]],tmp);
                int j,v;
                for(j=head[i]; j!=-1; j=edge[j].next)
                {
                    v=edge[j].v;
                    if(qlt[i]!=qlt[v]&&!mp[qlt[i]][qlt[v]])
                    {
                        addneg(qlt[v],qlt[i]);
                        ind[qlt[i]]++;
                        mp[qlt[v]][qlt[i]]=true;
                    }
                }
            }
            else val[qlt[i]]=0;
        }
        for(i=1; i<=num; i++)
            if(ind[i]==0)
                q.push(i);
        int ans=0;
        memset(dp,0,sizeof(dp));
        while(!q.empty())
        {
            int now=q.front();
            q.pop();
            int j,v;
            dp[now]+=val[now];
            ans=max(ans,dp[now]);
            for(j=h[now]; j!=-1; j=neg[j].next)
            {
                v=neg[j].v;
                dp[v]=max(dp[v],dp[now]);
                ind[v]--;
                if(ind[v]==0)
                    q.push(v);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
