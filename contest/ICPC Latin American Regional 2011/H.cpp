#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

const int MAXN = 10000;
const int MAXM = 100000;

struct Edge
{
    int to,next;
    bool visit;
}edge[MAXM<<1];

int head[MAXN],low[MAXN],dpt[MAXN],L;
int visit[MAXN];
bool cut[MAXN];

void init(int n)
{
    L = 0;
    memset(head,-1,4*n);
    memset(visit,-1,4*n);
}

void add_edge(int u,int v)
{
    edge[L].visit = 0;
    edge[L].to = v;
    edge[L].next = head[u];
    head[u] = L++;
}

int idx,cid;
stack<int> st;
int bcc[MAXM];

void dfs(int u,int fu,int deg)
{
    cut[u] = 0;
    visit[u] = cid;
    low[u] = dpt[u] = deg;
    int tot = 0;
    for (int i = head[u];i != -1;i = edge[i].next)
    {
        int v = edge[i].to;
        if (edge[i].visit)
            continue;
        st.push(i/2);
        edge[i].visit = edge[i^1].visit = 1;
        if (visit[v] != -1)
        {
            low[u] = dpt[v]>low[u]?low[u]:dpt[v];
            continue;
        }
        dfs(v,u,deg+1);
        if (u != fu)
            cut[u] = low[v]>=dpt[u]?1:cut[u];
        if (low[v] >= dpt[u] || u == fu)
        {
            while (st.top() != i/2)
            {
                bcc[st.top()] = idx;
                st.pop();
            }
            bcc[i/2] = idx++;
            st.pop();
        }
        low[u] = low[v]>low[u]?low[u]:low[v];
        tot++;
    }
    if (u == fu && tot > 1) cut[u] = 1;
}

int n,m,q;

int main()
{
    while (true)
    {
        scanf("%d%d%d",&n,&m,&q);
        if (n == 0 && m == 0 && q == 0) break;
        init(n);
        for (int i = 0;i < m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            u--;
            v--;
            add_edge(u,v);
            add_edge(v,u);
        }
        idx = cid = 0;
        for (int i = 0;i < n;i++)
            if (visit[i] == -1)
            {
                dfs(i,i,0);
                cid++;
            }
        puts("");
        for (int i = 0;i < L/2;i++)
            printf("%d ",bcc[i]);
        printf("\n");
        for (int i = 0;i < n;i++)
            printf("%d ",cut[i]);
        printf("\n");
        for (int i = 0;i < q;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            u--;
            v--;
            bool flag = true;
            /*if (!cut[u] || !cut[v])
                flag = false;
            if (visit[u] != visit[v])
                flag = false;
            for (int j = head[u];j != -1 && flag;j = edge[j].next)
                for (int k = head[v];k != -1 && flag;k = edge[k].next)
                    if (bcc[j/2] == bcc[k/2])
                        flag = false;
            if (flag)
                puts("Y");
            else
                puts("N");
        }
        printf("-\n");
    }
	return 0;
}
