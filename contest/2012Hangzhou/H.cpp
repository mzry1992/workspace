#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

struct Edge
{
    int to,next;
};
Edge edge[20000];
int head[1000],L;
map<string,int> mps;
int n,m;
char buf[20];

int getid(char buf[])
{
    if (mps.find(buf) == mps.end())
    {
        int sz = mps.size();
        mps[buf] = sz;
    }
    return mps[buf];
}

void addedge(int u,int v)
{
    edge[L].to = v;
    edge[L].next = head[u];
    head[u] = L++;
}

int dis[1000];
int SPFA(int s)
{
    memset(dis,-1,sizeof(dis));
    queue<int> Q;
    Q.push(s);
    dis[s] = 0;
    while (!Q.empty())
    {
        int now = Q.front();
        Q.pop();
        for (int i = head[now];i != -1;i = edge[i].next)
            if (dis[edge[i].to] == -1 || dis[edge[i].to] > dis[now]+1)
            {
                dis[edge[i].to] = dis[now]+1;
                Q.push(edge[i].to);
            }
    }
    int ret = 0;
    for (int i = 0;i < n;i++)
    {
        if (dis[i] == -1)
            return -1;
        ret = max(ret,dis[i]);
    }
    return ret;
}

int main()
{
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;

        mps.clear();
        for (int i = 0;i < n;i++)
        {
            scanf("%s",buf);
            int id = getid(buf);
            head[i] = -1;
        }
        L = 0;
        scanf("%d",&m);
        for (int i = 0;i < m;i++)
        {
            scanf("%s",buf);
            int ida = getid(buf);
            scanf("%s",buf);
            int idb = getid(buf);
            addedge(ida,idb);
            addedge(idb,ida);
        }

        int ans = 0;
        for (int i = 0;i < n;i++)
        {
            int ret = SPFA(i);
            if (ret == -1)
            {
                ans = -1;
                break;
            }
            ans = max(ans,ret);
        }
        printf("%d\n",ans);
    }
    return 0;
}

