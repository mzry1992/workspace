#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXEDGE = 80000;
const int MAXN = 30000;
const int inf = 0x3fffffff;
struct edges
{
    int cap,to,next,flow,opid;
} edge[MAXEDGE];
struct nodes
{
    int head,label,pre,cur;
} node[MAXN];
int L,N;
int gap[MAXN];

void init(int n)
{
    L = 0;
    N = n;
    for (int i = 0; i < N; i++)
        node[i].head = -1;
}

void add_edge(int x,int y,int z,int w,int opid)
{
    edge[L].opid = opid;
    edge[L].cap = z;
    edge[L].flow = 0;
    edge[L].to = y;
    edge[L].next = node[x].head;
    node[x].head = L++;

    edge[L].opid = opid;
    edge[L].cap = w;
    edge[L].flow = 0;
    edge[L].to = x;
    edge[L].next = node[y].head;
    node[y].head = L++;
}

int maxflow(int s,int t)
{
    memset(gap,0,sizeof(gap));
    gap[0] = N;
    int u,ans = 0;
    for (int i = 0; i < N; i++)
    {
        node[i].cur = node[i].head;
        node[i].label = 0;
    }
    u = s;
    node[u].pre = -1;
    while (node[s].label < N)
    {
        if (u == t)
        {
            int min = inf;
            for (int i = node[u].pre; i != -1; i = node[edge[i^1].to].pre)
                if (min > edge[i].cap-edge[i].flow)
                    min = edge[i].cap-edge[i].flow;
            for (int i = node[u].pre; i != -1; i = node[edge[i^1].to].pre)
            {
                edge[i].flow += min;
                edge[i^1].flow -= min;
            }
            u = s;
            ans += min;
            continue;
        }
        bool flag = false;
        int v;
        for (int i = node[u].cur; i != -1; i = edge[i].next)
        {
            v = edge[i].to;
            if (edge[i].cap-edge[i].flow && node[v].label+1 == node[u].label)
            {
                flag = true;
                node[u].cur = node[v].pre = i;
                break;
            }
        }
        if (flag)
        {
            u = v;
            continue;
        }
        node[u].cur = node[u].head;
        int min = N;
        for (int i = node[u].head; i != -1; i = edge[i].next)
            if (edge[i].cap-edge[i].flow && node[edge[i].to].label < min)
                min = node[edge[i].to].label;
        gap[node[u].label]--;
        if (!gap[node[u].label])    return ans;
        node[u].label = min+1;
        gap[node[u].label]++;
        if (u != s) u = edge[node[u].pre^1].to;
    }
    return ans;
}

struct oper
{
    int typ,xa,ya,xb,yb;
    char col;
    oper() {}
    oper(int _typ,int _xa,int _ya,int _xb,int _yb,char _col)
    {
        typ = _typ;
        xa = _xa;
        ya = _ya;
        xb = _xb;
        yb = _yb;
        col = _col;
    }
} op[60000];

int totop;
int n,m,h,v,s;
char mp[40][40];
bool flag[60000],visit[MAXN];

void DFS(int now)
{
    visit[now] = 1;
    for (int i = node[now].head; i != -1; i = edge[i].next)
        if (visit[edge[i].to] == 0)
            if (edge[i].cap-edge[i].flow)
                DFS(edge[i].to);
}

int main()
{
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1; cas <= totcas; cas++)
    {
        scanf("%d%d%d%d%d",&n,&m,&h,&v,&s);
        for (int i = 0; i < n; i++)
            scanf("%s",mp[i]);
        totop = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0,pre = 0; j <= m; j++)
                if (j == m || mp[i][j] != mp[i][pre])
                {
                    //0 - h
                    op[totop++] = oper(0,i,pre,i,j-1,mp[i][pre]);
                    pre = j;
                }
        int pos = totop;
        for (int i = 0; i < m; i++)
            for (int j = 0,pre = 0; j <= n; j++)
                if (j == n || mp[j][i] != mp[pre][i])
                {
                    //0 - v
                    op[totop++] = oper(1,pre,i,j-1,i,mp[pre][i]);
                    pre = j;
                }
        init(2+totop);
        for (int i = 0; i < pos; i++)
            add_edge(N-2,i,h,0,i);
        for (int i = pos; i < totop; i++)
            add_edge(i,N-1,v,0,i);
        int pretotop = totop;
        for (int i = 0; i < pos; i++)
            for (int j = pos; j < pretotop; j++)
                if (op[i].xa >= op[j].xa && op[i].xa <= op[j].xb && op[j].ya >= op[i].ya && op[j].ya <= op[i].yb)
                {
                    op[totop++] = oper(2,op[i].xa,op[j].ya,0,0,mp[op[i].xa][op[j].ya]);
                    add_edge(i,j,s,0,totop-1);
                }
        //for (int i = 0;i < totop;i++)
        //{
        //    printf("%d %d %d %d %d %c\n",op[i].typ,op[i].xa,op[i].ya,op[i].xb,op[i].yb,op[i].col);
        //}
        int res = maxflow(N-2,N-1);
        memset(visit,0,sizeof(visit));
        DFS(N-2);
        memset(flag,false,sizeof(flag));
        for (int i = 0;i < N;i++)
            if (visit[i] == 1)
                for (int j = node[i].head;j != -1;j = edge[j].next)
                    if (visit[edge[j].to] == 0 && edge[j].cap)
                        flag[edge[j].opid] = true;
        int cnt = 0;
        for (int i = 0; i < totop; i++)
            if (flag[i] == true)
                cnt++;
        printf("%d %d\n",res,cnt);
        for (int i = 0; i < totop; i++)
            if (flag[i] == true)
            {
                if (op[i].typ == 2)
                    printf("s %d %d %c\n",op[i].xa+1,op[i].ya+1,op[i].col);
                else
                {
                    if (op[i].typ == 0)
                        printf("h ");
                    else
                        printf("v ");
                    printf("%d %d %d %d %c\n",op[i].xa+1,op[i].ya+1,op[i].xb+1,op[i].yb+1,op[i].col);
                }
            }
    }
    return 0;
}
