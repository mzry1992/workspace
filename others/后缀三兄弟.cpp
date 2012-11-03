#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int CHAR = 27;
const int MAXN = 200001;
struct SAM_Node
{
    SAM_Node *fa,*next[CHAR];
    int len;
    int id,pos;
    SAM_Node() {}
    SAM_Node(int _len)
    {
        fa = 0;
        len = _len;
        memset(next,0,sizeof(next));
    }
};
SAM_Node SAM_node[MAXN * 2], *SAM_root, *SAM_last;
int size;
SAM_Node *newSAM_Node(int len)
{
    SAM_node[size] = SAM_Node(len);
    SAM_node[size].id=size;
    return &SAM_node[size++];
}
SAM_Node *newSAM_Node(SAM_Node *p)
{
    SAM_node[size] = *p;
    SAM_node[size].id=size;
    return &SAM_node[size++];
}
void SAM_init()
{
    size = 0;
    SAM_root = SAM_last = newSAM_Node(0);
    SAM_node[0].pos=0;
}
void SAM_add(int x,int len)
{
    SAM_Node *p = SAM_last, *np = newSAM_Node(p->len + 1);
    np->pos=len;
    SAM_last = np;
    for (; p && !p->next[x]; p = p->fa)
        p->next[x] = np;
    if (!p)
    {
        np->fa = SAM_root;
        return ;
    }
    SAM_Node *q = p->next[x];
    if (q->len == p->len + 1)
    {
        np->fa = q;
        return ;
    }
    SAM_Node *nq = newSAM_Node(q);
    nq->len = p->len + 1;
    q->fa = nq;
    np->fa = nq;
    for (; p && p->next[x] == q; p = p->fa)
        p->next[x] = nq;
}
void SAM_build(char *s)
{
    SAM_init();
    int l = strlen(s);
    for (int i = 0; i < l; i++)
        SAM_add(s[i] - 'a',i+1);
}
struct ST_Node
{
    ST_Node *next[CHAR],*fa;
    int len,pos;
}ST_node[MAXN*2],*ST_root;
int Sufpos[MAXN];
void ST_add(int u,int v,int chr,int len)
{
    ST_node[u].next[chr]=&ST_node[v];
    ST_node[v].len=len;
}
void init(int n)
{
    for (int i=0;i<n;i++)
    {
        ST_node[i].pos=-1;
        ST_node[i].fa=0;
        memset(ST_node[i].next,0,sizeof(ST_node[i].next));
    }
    ST_node[0].pos=0;
    ST_root=&ST_node[0];
}
void ST_build(char *s)
{
    int n=strlen(s);
    reverse(s,s+n);
    SAM_build(s);
    init(size);
    for (int i=1;i<size;i++)
    {
        ST_add(SAM_node[i].fa->id,SAM_node[i].id,s[SAM_node[i].pos-SAM_node[i].fa->len-1]-'a',SAM_node[i].len-SAM_node[i].fa->len);
        if (SAM_node[i].pos==SAM_node[i].len)
        {
            Sufpos[n-SAM_node[i].pos+1]=i;
            ST_node[i].pos=n-SAM_node[i].pos+1;
        }
    }
}
int rank[MAXN+1],L;
void ST_dfs(ST_Node *p)
{
    if (p->pos!=-1)
        rank[L++]=p->pos;
    for (int i=0;i<CHAR;i++)
        if (p->next[i])
            ST_dfs(p->next[i]);
}
char s[MAXN+1],t[100001];
int height[MAXN];
int sa[MAXN];
int main()
{
    gets(s);
    int n=strlen(s);
    ST_build(s);
    L=0;
    ST_dfs(ST_root);
    for (int i=0;i<n;i++)
        rank[i]=rank[i+1]-1;
    for (int i=0;i<n;i++)
        sa[rank[i]]=i;
    reverse(s,s+n);
    for (int i=0,j=0,k=0;i<n;height[rank[i++]]=k)
        if (rank[i])
            for (k?k--:0,j=sa[rank[i]-1];s[i+k]==s[j+k];k++);
    for (int i=0;i<n;i++)
        puts(s+rank[i]);
    for (int i=0;i<n;i++)
        printf("%d %d\n",rank[i],height[i]);
    int ans=0;
    for (int i=1;i<n;i++)
        ans=max(ans,height[i]);
    printf("%d\n",ans);
}
