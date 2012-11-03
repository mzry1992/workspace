#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

struct Edge
{
    int to,c,next;
};
struct Node
{
    int pos;
    vector<int> res;
    Node(){}
    Node(int _pos,vector<int> _res)
    {
        pos = _pos;
        res = _res;
    }
};

Edge edge[400000];
queue<Node> Q;
int head[100000],L,n,m,u,v,c;
vector<int> res,dis[100000];
bool inq[100000];

void init(int n)
{
    L = 0;
    for (int i = 0; i < n; i++)
        head[i] = -1;
}

void addedge(int u,int v,int c)
{
    edge[L].to = v;
    edge[L].c = c;
    edge[L].next = head[u];
    head[u] = L++;
}

vector<int> BFS()
{
    for (int i = 0;i < n;i++)
    {
        dis[i].clear();
        inq[i] = false;
    }
    dis[0].push_back(0);
    Q.push(Node(0,dis[0]));
    inq[0] = true;
    Node now;
    Node upd;
    while (!Q.empty())
    {
        upd = now = Q.front();
        Q.pop();
        inq[now.pos] = false;
        upd.res.push_back(0);
        for (int i = head[now.pos];i != -1;i = edge[i].next)
        {
            upd.pos = edge[i].to;
            upd.res[upd.res.size()-1] = edge[i].c;
            if (dis[upd.pos].size() == 0 || (dis[upd.pos].size() == upd.res.size() && dis[upd.pos] > upd.res))
            {
                dis[upd.pos] = upd.res;
                if (inq[upd.pos] == false)
                {
                    inq[upd.pos] = true;
                    Q.push(upd);
                }
            }
        }
    }
    return dis[n-1];
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&n,&m);
        init(n);
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%d",&u,&v,&c);
            u--;
            v--;
            addedge(u,v,c);
            addedge(v,u,c);
        }
        res = BFS();
        printf("%d\n",res.size()-1);
        for (int i = 1;i < res.size();i++)
            printf("%d ",res[i]);
        printf("\n");
    }
    return 0;
}
