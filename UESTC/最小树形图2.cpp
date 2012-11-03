#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m,u,v,cost;

struct Edge
{
    int to,next;
};

int head[1000],rhead[1000],L,dis[1000][1000];
Edge g[1000000],rg[1000000];

void init(int n)
{
    for (int i = 0; i < n; i++)
        rhead[i] = head[i] = -1;
    L = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dis[i][j] = 19921005;
}

void addedge(int u,int v)
{
    g[L].to = v;
    g[L].next = head[u];
    head[u] = L;
    rg[L].to = u;
    rg[L].next = rhead[v];
    rhead[v] = L++;
}

int pre[1000];
bool del[1000],visit[1000];

int zhuliu(int root)
{
    //判断无解：DFS如果发现有根无法到达的结点那么就无解
    //这里假设根为root。
    //0.置cost=0。
    int res = 0;
    for (int i = 0; i < n; i++)
        del[i] = false;
    bool check;
    while (true)
    {
        //1.求最短弧集合Ao （一条弧就是一条有向边）
        //除源点外，为所有其他节点Vi，找到一条以Vi为终点的边，把它加入到集合Ao中。
        //（加边的方法：所有点到Vi的边中权值最小的边即为该加入的边，记prev[vi]为该边的起点，
        //mincost[vi]为该边的权值）
        for (int i = 0; i < n; i++)
            if (i != root && del[i] == false)
            {
                pre[i] = i;
                dis[pre[i]][i] = 19921005;
                for (int j = rhead[i]; j != -1; j = rg[j].next)
                    if (del[rg[j].to] == false)
                        if (dis[pre[i]][i] > dis[rg[j].to][i])
                            pre[i] = rg[j].to;
            }
        //2.检查Ao中的边是否会形成有向圈，有则到步骤3，无则到步骤4。
        //（判断方法：利用prev数组，枚举为检查过的点作为搜索的起点，做类似DFS的操作）
        check = false;
        for (int i = 0; i < n; i++)
            if (i != root && del[i] == false)
            {
                for (int j = 0;j < n;j++)
                    visit[j] = false;
                int cur = i;
                for (;cur != root && visit[cur] == false;cur = pre[cur])
                    visit[cur] = true;
                if (cur == root ) continue;
                //3.将有向环缩成一个点。
                //假设环中的点有（Vk1，Vk2，… ，Vki）总共i个，用缩成的点叫Vk替代，则在压缩后的图中，其他所有不在环中点v到Vk的距离定义如下：
                //gh[v][Vk]=min { gh[v][Vkj]-mincost[Vkj] } (1<=j<=i)而Vk到v的距离为
                //gh[Vk][v]=min { gh[Vkj][v] }              (1<=j<=i)
                //同时注意更新prev[v]的值，即if(prev[v]==Vkj) prev[v]=Vk
                //另外cost=cost+mincost[Vkj] (1<=j<=i)
                //到步骤1.
                int Vk = cur;
                for (int j = 0;j < n;j++)
                    visit[j] = false;
                for (;cur != root && visit[cur] == false;cur = pre[cur])
                {
                    visit[cur] = true;
                    for (int j = rhead[cur];j != -1;j = rg[j].next)

                }
            }

        if (check == false)
        {
            //4.cost加上Ao的权值和即为最小树形图总权值。
            for (int i = 0; i < n; i++)
                if (i != root && del[i] == false)
                    res += dis[pre[i]][i];
            return res;
        }
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    while (scanf("%d%d",&n,&m) != EOF)
    {
        init(n);
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%d",&u,&v,&cost);
            if (u == v) continue;
            dis[u][v] = min(dis[u][v],cost);
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dis[i][j] != 19921005)
                    addedge(i,j);
        printf("%d\n",zhuliu(0));
    }
    return 0;
}

