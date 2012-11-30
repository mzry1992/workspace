#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct Edge
{
    int to,next;
};
Edge edge[200000];
int fa[100000][20],deg[100000];
int head[100000],L;
int val[100000];
int n,m;

void addedge(int u,int v)
{
    edge[L].to = v;
    edge[L].next = head[u];
    head[u] = L++;
}

const int MaxN = 100000;
int tree[MaxN+1];
int read(int k)
{
    int sum = 0;
    for (; k; k^=k&-k)
        sum += tree[k];
    return sum;
}
void update(int k,int v)
{
    for (; k <= MaxN; k += k&-k)
        tree[k] += v;
}

struct states
{
    int u,fu,deg;
};
void BFS_LCA(int s)
{
    queue<states> que;
    states st;
    st.deg = 0;
    st.fu = st.u = s;
    que.push(st);
    while (!que.empty())
    {
        states st = que.front();
        que.pop();
        deg[st.u] = st.deg;
        fa[st.u][0] = st.fu;
        for (int i = 1; i < 20; i++)
            fa[st.u][i] = s;
        for (int tmp = st.fu,num = 1; deg[tmp]; tmp=fa[st.u][num++])
            fa[st.u][num] = fa[tmp][num-1];
        for (int i = head[st.u]; i != -1; i = edge[i].next)
        {
            int v = edge[i].to;
            if (v == st.fu)	continue;
            states nst;
            nst.u = v;
            nst.fu = st.u;
            nst.deg = st.deg+1;
            que.push(nst);
        }
    }
}
int LCA(int x,int y)
{
    if (deg[x] > deg[y])
        swap(x,y);
    int hx = deg[x],hy = deg[y];
    int tx = x,ty = y;
    for (int det = hy-hx,i = 0; det; det >>= 1,i++)
        if (det&1)
            ty = fa[ty][i];
    if (tx == ty)	return tx;
    for (int i = 19; i >= 0; i--)
    {
        if (fa[tx][i] == fa[ty][i])
            continue;
        tx = fa[tx][i];
        ty = fa[ty][i];
    }
    return fa[tx][0];
}
int Jump(int s,int dis)
{
    for (int i = 19; i >= 0; i--)
        if (((dis>>i)&1) == 1)
            s = fa[s][i];
    return s;
}

struct Query
{
    int s,t,a,b,kth,lca;
    int diss,dist,l,r,mid,res;
    int sid,tid,lid;
    int targetpos;
};
Query q[100000];

struct Task
{
    int a,b;
    int res;
    int next;
};
Task task[300000];
int tL,thead[100000];
int addTask(int pos,int a,int b)
{
    task[tL].a = a;
    task[tL].b = b;
    task[tL].next = thead[pos];
    thead[pos] = tL;
    return tL++;
}

void taskDFS(int u,int fa)
{
    update(val[u],1);
    for (int i = thead[u]; i != -1; i = task[i].next)
    {
        int a = task[i].a;
        int b = task[i].b;
        task[i].res = read(b)-read(a-1);
    }

    for (int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v == fa)
            continue;
        taskDFS(v,u);
    }
    update(val[u],-1);
}

int getRes(int lid,int rid,int rpos)
{
    int res = task[lid].res-task[rid].res;
    if (val[rpos] >= task[rid].a && val[rpos] <= task[rid].b)
        res++;
    return res;
}

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        for (int i = 0; i < n; i++)
            head[i] = -1;
        L = 0;

        for (int i = 0; i < n; i++)
            scanf("%d",&val[i]);
        for (int i = 0; i < n-1; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            u--;
            v--;
            addedge(u,v);
            addedge(v,u);
        }

        BFS_LCA(0);

        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%d%d%d",&q[i].s,&q[i].t,&q[i].a,&q[i].b,&q[i].kth);
            q[i].s--;
            q[i].t--;
            q[i].lca = LCA(q[i].s,q[i].t);
            q[i].diss = deg[q[i].s]-deg[q[i].lca];
            q[i].dist = deg[q[i].t]-deg[q[i].lca];
//			二分的左右区间
            q[i].l = 0;
            q[i].r = q[i].diss+q[i].dist;
        }

//		二分的次数
        for (int tim = 0; tim < 20; tim++)
        {
            for (int i = 0; i < n; i++)
                thead[i] = -1;
            tL = 0;

            for (int i = 0; i < m; i++)
            {
                q[i].mid = (q[i].l+q[i].r)>>1;
                int startpos,jumpdist;
                if (q[i].mid > q[i].diss)
                {
                    startpos = q[i].t;
                    jumpdist = q[i].diss+q[i].dist-q[i].mid;
                }
                else
                {
                    startpos = q[i].s;
                    jumpdist = q[i].mid;
                }
                q[i].targetpos = Jump(startpos,jumpdist);
//				确定需要求解的任务
                q[i].sid = addTask(q[i].s,q[i].a,q[i].b);
                q[i].tid = addTask(q[i].targetpos,q[i].a,q[i].b);
                if (q[i].mid > q[i].diss)
                    q[i].lid = addTask(q[i].lca,q[i].a,q[i].b);
            }

//			DFS
            taskDFS(0,0);

            for (int i = 0; i < m; i++)
            {
                int res;
                if (q[i].mid > q[i].diss)
                {
                    res  = getRes(q[i].sid,q[i].lid,q[i].lca);
                    res += getRes(q[i].tid,q[i].lid,q[i].lca);
                    res -= getRes(q[i].lid,q[i].lid,q[i].lca);
                }
                else
                    res  = getRes(q[i].sid,q[i].tid,q[i].targetpos);

//				分别更新区间
                if (res < q[i].kth)
                    q[i].l = q[i].mid+1;
                else
                    q[i].r = q[i].mid;
            }
        }

        for (int i = 0; i < m; i++)
        {
            int res;
            if (q[i].kth <= 0 || q[i].l > q[i].diss+q[i].dist)
                res = -1;
            else
                res = q[i].targetpos+1;
            printf("%d\n",res);
        }
    }
    return 0;
}
