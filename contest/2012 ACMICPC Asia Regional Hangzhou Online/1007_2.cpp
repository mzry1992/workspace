#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
const int CHAR = 26;
const int MAXN = 150000;
struct SAM_Node
{
    SAM_Node *fa;
    map<int,SAM_Node*> next;
    int len;
    int id;
    int flag;
    SAM_Node() {}
    SAM_Node(int _len)
    {
        fa = 0;
        len = _len;
        flag=0;
        next.clear();
    }
};
SAM_Node SAM_node[MAXN * 2], *SAM_root, *SAM_last;
int SAM_size;
SAM_Node *newSAM_Node(int len)
{
    SAM_node[SAM_size] = SAM_Node(len);
    SAM_node[SAM_size].id = SAM_size;
    return &SAM_node[SAM_size++];
}
SAM_Node *newSAM_Node(SAM_Node *p)
{
    SAM_node[SAM_size] = *p;
    SAM_node[SAM_size].id = SAM_size;
    return &SAM_node[SAM_size++];
}
void SAM_init()
{
    SAM_size = 0;
    SAM_root = SAM_last = newSAM_Node(0);
}
SAM_Node * SAM_add(SAM_Node *p, int x, bool flag)
{
    SAM_Node *np = newSAM_Node(p->len + 1);
    np->flag=1<<flag;
    SAM_last = np;
    for (; p && !p->next[x]; p = p->fa)
        p->next[x] = np;
    if (!p)
    {
        np->fa = SAM_root;
        return np;
    }
    SAM_Node *q = p->next[x];
    if (q->len == p->len + 1)
    {
        np->fa = q;
        return np;
    }
    SAM_Node *nq = newSAM_Node(q);
    nq->len = p->len + 1;
    q->fa = nq;
    np->fa = nq;
    for (; p && p->next[x] == q; p = p->fa)
        p->next[x] = nq;
    return np;
}
void SAM_build(char *s,bool flag)
{
    int l = strlen(s);
    SAM_Node *p = SAM_root;
    for (int i = 0; i < l; i++)
    {
        if (!p->next[s[i] - 'a'] || !(p->next[s[i] - 'a']->len == i + 1))
            p=SAM_add(p,s[i] - 'a',flag);
        else
        {
            p = p->next[s[i] - 'a'];
            p->flag|=1<<flag;
        }
    }
}
int head[MAXN<<1];
struct Edge
{
    int to,next;
} edge[MAXN<<1];
int L;
void add_edge(int u,int v)
{
    edge[L].to=v;
    edge[L].next=head[u];
    head[u]=L++;
}
void build()
{
    L=0;
    memset(head,-1,4*SAM_size);
    for (int i=1; i<SAM_size; i++)
        add_edge(SAM_node[i].fa->id,SAM_node[i].id);
}
long long dfs(int u,int len)
{
    long long ret=0;
    for (int i=head[u]; i!=-1; i=edge[i].next)
    {
        int v=edge[i].to;
        ret+=dfs(v,SAM_node[u].len);
        SAM_node[u].flag|=SAM_node[v].flag;
    }
    if (SAM_node[u].flag==1)
        ret+=SAM_node[u].len-len;
    return ret;
}
char s[100001];
int main()
{
    freopen("data.in","r",stdin);
    freopen("data2.out","w",stdout);
    int t;
    scanf("%d",&t);
    for (int cas=1; cas<=t; cas++)
    {
        SAM_init();
        int n;
        scanf("%d",&n);
        scanf("%s",s);
        SAM_build(s,0);
        while (n--)
        {
            scanf("%s",s);
            SAM_build(s,1);
        }
        build();
        printf("Case %d: %I64d\n",cas,dfs(0,0));
    }
    return 0;
}
