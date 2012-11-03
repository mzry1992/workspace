#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int CHAR = 26;
const int MAXN = 100000;

struct SAM_Node
{
    SAM_Node *fa,*next[CHAR];
    int len;
    int id;
    int mat[9];
    SAM_Node() {}
    SAM_Node(int _len)
    {
        fa = 0;
        len = _len;
        memset(mat,0,sizeof(mat));
        memset(next,0,sizeof(next));
    }
};
SAM_Node SAM_node[MAXN*2],*SAM_root,*SAM_last;
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
void SAM_add(int x,int len)
{
    SAM_Node *p = SAM_last,*np = newSAM_Node(p->len+1);
    SAM_last = np;
    for (; p&&!p->next[x]; p=p->fa)
        p->next[x] = np;
    if (!p)
    {
        np->fa = SAM_root;
        return;
    }
    SAM_Node *q = p->next[x];
    if (q->len == p->len+1)
    {
        np->fa = q;
        return;
    }
    SAM_Node *nq = newSAM_Node(q);
    nq->len = p->len+1;
    q->fa = nq;
    np->fa = nq;
    for (; p&&p->next[x] == q; p = p->fa)
        p->next[x] = nq;
}
int getid(char ch)
{
    return ch-'a';
}
void SAM_build(char *s)
{
    SAM_init();
    int l = strlen(s);
    for (int i = 0; i < l; i++)
        SAM_add(getid(s[i]),i+1);
}
char s[10][MAXN+1];
int ans;
int head[MAXN*2];
struct Edge
{
    int to,next;
} edge[MAXN*2];
int M;
int n;
void add_edge(int u,int v)
{
    edge[M].to=v;
    edge[M].next=head[u];
    head[u]=M++;
}
void dfs(int u)
{
    for (int i=head[u]; i!=-1; i=edge[i].next)
    {
        int v=edge[i].to;
        dfs(v);
        for (int j=0; j<n-1; j++)
            SAM_node[u].mat[j]=max(SAM_node[v].mat[j],SAM_node[u].mat[j]);
    }
    int tmp=SAM_node[u].len;
    for (int i=0; i<n-1; i++)
        tmp=min(tmp,SAM_node[u].mat[i]);
    ans=max(ans,tmp);
}
int main()
{

    while (scanf("%s",s[n])!=EOF)
        n++;
    int L=strlen(s[0]);
    ans=M=0;
    SAM_build(s[0]);
    for (int j=1; j<n; j++)
    {
        int l=strlen(s[j]),len=0;
        SAM_Node *p=SAM_root;
        for (int i=0; i<l; i++)
        {
            if (p->next[getid(s[j][i])])
            {
                p=p->next[getid(s[j][i])];
                p->mat[j-1]=max(p->mat[j-1],++len);
            }
            else
            {
                while (p && !p->next[getid(s[j][i])])
                    p=p->fa;
                if (!p)
                {
                    p=SAM_root;
                    len=0;
                }
                else
                {
                    len=p->len+1;
                    p=p->next[getid(s[j][i])];
                }
                p->mat[j-1]=max(p->mat[j-1],len);
            }
        }
    }
    memset(head,-1,4*SAM_size);
    for (int i=1; i<SAM_size; i++)
        add_edge(SAM_node[i].fa->id,i);
    dfs(0);
    printf("%d\n",ans);
    return 0;
}
