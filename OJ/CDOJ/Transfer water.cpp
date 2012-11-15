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
        //1.����̻�����Ao ��һ��������һ������ߣ�
        //��Դ���⣬Ϊ���������ڵ�Vi���ҵ�һ����ViΪ�յ�ıߣ��������뵽����Ao�С�
        //���ӱߵķ��������е㵽Vi�ı���Ȩֵ��С�ı߼�Ϊ�ü���ıߣ���pre[vi]Ϊ�ñߵ���㣬
        //in[vi]Ϊ�ñߵ�Ȩֵ��
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
                if (in[i] == inf)   return -1;//���˸������е�û�����,����޷�����������ô�޽�
        //2.���Ao�еı��Ƿ���γ�����Ȧ�����򵽲���3�����򵽲���4��
        //���жϷ���������pre���飬ö��Ϊ�����ĵ���Ϊ��������㣬������DFS�Ĳ�����
        int tn = 0;
        memset(id,-1,sizeof(id));
        memset(visit,-1,sizeof(visit));
        in[root] = 0;
        for (int i = 0; i < n; i++)
        {
            //���ÿ����
            //4.cost����Ao��Ȩֵ�ͼ�Ϊ��С����ͼ��Ȩֵ��
            res += in[i];
            v = i;
            while (visit[v] != i && id[v] == -1 && v != root)
            {
                visit[v] = i;
                v = pre[v];
            }
            //3.����������һ���㡣
            //���軷�еĵ��У�Vk1��Vk2���� ��Vki���ܹ�i���������ɵĵ��Vk���������ѹ�����ͼ�У��������в��ڻ��е�v��Vk�ľ��붨�����£�
            //gh[v][Vk]=min { gh[v][Vkj]-mincost[Vkj] } (1<=j<=i)��Vk��v�ľ���Ϊ
            //gh[Vk][v]=min { gh[Vkj][v] }              (1<=j<=i)
            //ͬʱע�����prev[v]��ֵ����if(prev[v]==Vkj) prev[v]=Vk
            //����cost=cost+mincost[Vkj] (1<=j<=i)
            //������1.
            if(v != root && id[v] == -1)
            {
                for(int u = pre[v] ; u != v ; u = pre[u])
                    id[u] = tn;
                id[v] = tn++;
            }
        }
        if(tn == 0)    break;//�޻�
        for (int i = 0; i < n; i++)
            if (id[i] == -1)
                id[i] = tn++;
        //3.����,���±��
        for (int i = 0; i < m;)
        {
            int v = e[i].v;
            e[i].u = id[e[i].u];
            e[i].v = id[e[i].v];
            if (e[i].u != e[i].v)
                e[i++].cost -= in[v];
            else
                //����Ӧ��ɾ��һЩ�ߡ�
                //�򵥵İѱ߻��������ȥ�ˡ�
                //ֻ��ɾ����һ����ͨ��ıߣ�ò��ûʲôʵ�����á�
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
