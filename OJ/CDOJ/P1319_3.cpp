#include <iostream>
#include <queue>
using namespace std;

#define N 1001
#define M 10001
#define INF 0x7fffffff
#define clear(a) memset(a,0,sizeof(a))
struct Edge
{
    int v;
    int len;
    int ref;
    Edge *link;
    Edge new_E(int v1,int l,int r) {v = v1,len = l,ref = r;return *this;}
}*E[N],mempool[M];
bool operator < (Edge a,Edge b)
{
    return a.len > b.len;
}
int dist[N][2],used[N][2],cnt[N][2];
int n,m,memh,S,T;

void AddEdge(int u,int v,int len)
{
    Edge *e = &mempool[memh++];
    e->v = v;
    e->len = len;
    e->link = E[u];
    E[u] = e;
}
priority_queue<Edge,vector<Edge> >Q;

void InitData()
{
    int i,u,v,len;
    memh = 0;
    scanf("%d%d",&n,&m);
    clear(E);
    for (i = 1;i <= m;i++)
    {
        scanf("%d%d%d",&u,&v,&len);
        AddEdge(u,v,len);
    }
    scanf("%d%d",&S,&T);
}

int Dijstra()
{
    Edge D,P;
    clear(cnt);
    clear(used);
    for (int i = 1;i <= n;i++)
        dist[i][0] = dist[i][1] = INF;
    dist[S][0] = 0;
    cnt[S][0] = 1;
    while (!Q.empty())   Q.pop();
    Q.push(D.new_E(S,0,0));
    while (!Q.empty())
    {
        P = Q.top();
        Q.pop();
        if (!used[P.v][P.ref])
        {
            used[P.v][P.ref] = 1;
            for (Edge *e = E[P.v];e;e = e->link)
            {
                int tmp = P.len+e->len;
                if (tmp < dist[e->v][0])
                {
                    if (dist[e->v][0] != INF)
                    {
                        dist[e->v][1] = dist[e->v][0];
                        cnt[e->v][1] = cnt[e->v][0];
                        Q.push(D.new_E(e->v,dist[e->v][0],1));
                    }
                    dist[e->v][0] = tmp;
                    cnt[e->v][0] = cnt[P.v][P.ref];
                    Q.push(D.new_E(e->v,tmp,0));
                }
                else if (tmp == dist[e->v][0])  cnt[e->v][0] += cnt[P.v][P.ref];
                else if (tmp < dist[e->v][1])
                {
                    dist[e->v][1] = tmp;
                    cnt[e->v][1] = cnt[P.v][P.ref];
                    Q.push(D.new_E(e->v,tmp,1));
                }
                else if(dist[e->v][1] == tmp){
                    cnt[e->v][1] += cnt[P.v][P.ref];
                }
            }
        }
    }
    if(dist[T][1]-1 == dist[T][0])
        cnt[T][0] += cnt[T][1];
    return cnt[T][0];
}

int main()
{
    int cs;
    for (scanf("%d",&cs);cs;cs--)
    {
        InitData();
        printf("%d\n",Dijstra());
    }
    return 0;
}
