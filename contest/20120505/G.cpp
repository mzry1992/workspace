#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

struct Edge
{
    int to,next,cost;
};
Edge edge[160000];
int head[50000],L;
int n,m;

void addedge(int u,int v,int w)
{
    edge[L].to = v;
    edge[L].cost = w;
    edge[L].next = head[u];
    head[u] = L++;
}

int col[50000];
bool res;

void DFS(int now,int c,int mx)
{
    col[now] = c;
    for (int i = head[now];i != -1;i = edge[i].next)
        if (edge[i].cost < mx)
            if (col[edge[i].to] == 0)
            {
                if (c == 1)
                    DFS(edge[i].to,2,mx);
                else
                    DFS(edge[i].to,1,mx);
            }
            else
                if (col[edge[i].to] == c)
                    res = false;
}

bool check(int mid)
{
    for (int i = 0;i < n;i++)
        col[i] = 0;
    res = true;
    for (int i = 0;i < n;i++)
        if (col[i] == 0)
            DFS(i,1,mid);
    return res;
}

int main()
{
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1;cas <= totcas;cas++)
    {
        scanf("%d%d",&n,&m);
        for (int i = 0;i < n;i++)
            head[i] = -1;
        L = 0;
        int minw = 2147483647;
        int maxw = 0;
        for (int i = 0;i < m;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            minw = min(minw,w);
            maxw = max(maxw,w);
            addedge(u-1,v-1,w);
            addedge(v-1,u-1,w);
        }
        long long l,r,mid;
        l = 1;
        r = 2147483647;
        while (l < r)
        {
            mid = l+r+1>>1;
            if (check(mid) == true)
                l = mid;
            else
                r = mid-1;
        }
        if (l <= minw)  l = -1;
        if (l >= maxw)  l = 0;
        printf("%lld\n",l);
    }
	return 0;
}
