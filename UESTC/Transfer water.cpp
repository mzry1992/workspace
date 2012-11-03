#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int inf = 19921005;

struct Point
{
    int x,y,z;
};

Point p[1010];
int n,X,Y,Z,L,dis[1010][1010];

int DIS(Point a,Point b)
{
    return abs(a.x-b.x)+abs(a.y-b.y)+abs(a.z-b.z);
}

void init(int n)
{
    L = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dis[i][j] = inf;
}

struct Edge
{
    int u,v,cost;
};

Edge e[1001*1001];

int pre[1001],id[1001],visit[1001],in[1001];

int zhuliu(int root,int n,int m,Edge e[])
{
    int res = 0,u,v;
    while (true)
    {
        //1.求最短弧集合Ao （一条弧就是一条有向边）
        //除源点外，为所有其他节点Vi，找到一条以Vi为终点的边，把它加入到集合Ao中。
        //（加边的方法：所有点到Vi的边中权值最小的边即为该加入的边，记pre[vi]为该边的起点，
        //in[vi]为该边的权值）
        for (int i = 0; i < n; i++)
            in[i] = inf;
        for (int i = 0; i < m; i++)
            if (e[i].u != e[i].v && e[i].cost < in[e[i].v])
            {
                pre[e[i].v] = e[i].u;
                in[e[i].v] = e[i].cost;
            }
        for (int i = 0; i < n; i++)
            if (i != root)
                if (in[i] == inf)   return -1;//除了跟以外有点没有入边,则根无法到达它，那么无解
        //2.检查Ao中的边是否会形成有向圈，有则到步骤3，无则到步骤4。
        //（判断方法：利用pre数组，枚举为检查过的点作为搜索的起点，做类似DFS的操作）
        int tn = 0;
        memset(id,-1,sizeof(id));
        memset(visit,-1,sizeof(visit));
        in[root] = 0;
        for (int i = 0; i < n; i++)
        {
            //标记每个环
            //4.cost加上Ao的权值和即为最小树形图总权值。
            res += in[i];
            v = i;
            while (visit[v] != i && id[v] == -1 && v != root)
            {
                visit[v] = i;
                v = pre[v];
            }
            //3.将有向环缩成一个点。
            //假设环中的点有（Vk1，Vk2，… ，Vki）总共i个，用缩成的点叫Vk替代，则在压缩后的图中，其他所有不在环中点v到Vk的距离定义如下：
            //gh[v][Vk]=min { gh[v][Vkj]-mincost[Vkj] } (1<=j<=i)而Vk到v的距离为
            //gh[Vk][v]=min { gh[Vkj][v] }              (1<=j<=i)
            //同时注意更新prev[v]的值，即if(prev[v]==Vkj) prev[v]=Vk
            //另外cost=cost+mincost[Vkj] (1<=j<=i)
            //到步骤1.
            if(v != root && id[v] == -1)
            {
                for(int u = pre[v] ; u != v ; u = pre[u])
                    id[u] = tn;
                id[v] = tn++;
            }
        }
        if(tn == 0)    break;//无环
        for (int i = 0; i < n; i++)
            if (id[i] == -1)
                id[i] = tn++;
        //3.缩点,重新标记
        for (int i = 0; i < m;)
        {
            int v = e[i].v;
            e[i].u = id[e[i].u];
            e[i].v = id[e[i].v];
            if (e[i].u != e[i].v)
                e[i++].cost -= in[v];
            else
                //这里应该删除一些边。
                //简单的把边换到最后面去了。
                //只能删除在一个联通快的边，貌似没什么实际作用。
                swap(e[i],e[--m]);
        }
        n = tn;
        root = id[root];
    }
    return res;
}

int main()
{
    while (true)
    {
        scanf("%d%d%d%d",&n,&X,&Y,&Z);
        if (n == 0 && X == 0 && Y == 0 && Z == 0)   break;
        for (int i = 1; i <= n; i++)
            scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].z);
        init(n+1);
        for (int i = 1; i <= n; i++)
            dis[0][i] = min(dis[0][i],p[i].z*X);
        for (int i = 1; i <= n; i++)
        {
            int k,to;
            scanf("%d",&k);
            for (int j = 0; j < k; j++)
            {
                scanf("%d",&to);
                if (i == to)    continue;
                if (p[i].z >= p[to].z)
                    dis[i][to] = min(dis[i][to],DIS(p[i],p[to])*Y);
                else
                    dis[i][to] = min(dis[i][to],DIS(p[i],p[to])*Y+Z);
            }
        }
        n++;
        L = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dis[i][j] != inf)
                {
                    e[L].u = i;
                    e[L].v = j;
                    e[L++].cost = dis[i][j];
                }
        printf("%d\n",zhuliu(0,n,L,e));
    }
    return 0;
}
