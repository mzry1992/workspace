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
    //�ж��޽⣺DFS��������и��޷�����Ľ����ô���޽�
    //��������Ϊroot��
    //0.��cost=0��
    int res = 0;
    for (int i = 0; i < n; i++)
        del[i] = false;
    bool check;
    while (true)
    {
        //1.����̻�����Ao ��һ��������һ������ߣ�
        //��Դ���⣬Ϊ���������ڵ�Vi���ҵ�һ����ViΪ�յ�ıߣ��������뵽����Ao�С�
        //���ӱߵķ��������е㵽Vi�ı���Ȩֵ��С�ı߼�Ϊ�ü���ıߣ���prev[vi]Ϊ�ñߵ���㣬
        //mincost[vi]Ϊ�ñߵ�Ȩֵ��
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
        //2.���Ao�еı��Ƿ���γ�����Ȧ�����򵽲���3�����򵽲���4��
        //���жϷ���������prev���飬ö��Ϊ�����ĵ���Ϊ��������㣬������DFS�Ĳ�����
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
                //3.����������һ���㡣
                //���軷�еĵ��У�Vk1��Vk2���� ��Vki���ܹ�i���������ɵĵ��Vk���������ѹ�����ͼ�У��������в��ڻ��е�v��Vk�ľ��붨�����£�
                //gh[v][Vk]=min { gh[v][Vkj]-mincost[Vkj] } (1<=j<=i)��Vk��v�ľ���Ϊ
                //gh[Vk][v]=min { gh[Vkj][v] }              (1<=j<=i)
                //ͬʱע�����prev[v]��ֵ����if(prev[v]==Vkj) prev[v]=Vk
                //����cost=cost+mincost[Vkj] (1<=j<=i)
                //������1.
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
            //4.cost����Ao��Ȩֵ�ͼ�Ϊ��С����ͼ��Ȩֵ��
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

