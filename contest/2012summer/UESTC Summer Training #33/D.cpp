#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int CHAR = 4;
const int MAXN = 2000000;

struct SAM_Node
{
    SAM_Node *fa,*next[CHAR];
    int len;
    int id,pos;
    int mat[6];
    SAM_Node(){}
    SAM_Node(int _len)
    {
        fa = 0;
        len = _len;
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
    SAM_node[0].pos = 0;
}
void SAM_add(int x,int len)
{
    SAM_Node *p = SAM_last,*np = newSAM_Node(p->len+1);
    np->pos = len;
    SAM_last = np;
    for (;p&&!p->next[x];p=p->fa)
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
    for (;p&&p->next[x] == q;p = p->fa)
        p->next[x] = nq;
}
int getid(char ch)
{
    if (ch == 'A')  return 0;
    else if (ch == 'C') return 1;
    else if (ch == 'G') return 2;
    return 3;
}
void SAM_build(char *s)
{
    SAM_init();
    int l = strlen(s);
    for (int i = 0;i < l;i++)
        SAM_add(getid(s[i]),i+1);
}
char s[MAXN+1];
int mat[6][MAXN*2];
int ans;
int head[MAXN*2];
struct Edge
{
    int to,next;
}edge[MAXN*2];
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
    int tmp=0x7fffffff;
    for (int i=0;i<n-1;i++)
        tmp=min(tmp,mat[i][u]);
    ans=max(ans,tmp);
    for (int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        for (int j=0;j<n-1;j++)
            mat[j][v]=max(mat[j][v],mat[j][u]);
        dfs(v);
    }
}
int main()
{
	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
	    ans=M=0;
	    scanf("%d",&n);
	    scanf("%s",s);
	    int L=strlen(s);
	    SAM_build(s);
	    for (int j=1;j<n;j++)
	    {
	        scanf("%s",s);
	        int l=strlen(s),len=0;
	        SAM_Node *p=SAM_root;
	        for (int i=0;i<l;i++)
                if (p->next[getid(s[i])])
                {
                    p=p->next[getid(s[i])];
                    p->mat[j-1]=++len;
                }
                else
                {
                    while (p!=SAM_root && p->next[getid(s[i])]==0)
                        p=p->fa;
                    if (p->next[getid(s[i])])
                    {
                        p=p->next[getid(s[i])];
                        len=min(p->len,i+1);
                    }
                    p->mat[j-1]=len;
                }
	    }
	    memset(head,-1,4*SAM_size);
	    for (int i=1;i<SAM_size;i++)
	    {
            add_edge(SAM_node[i].fa->id,SAM_node[i].id);
            for (int j=0;j+1<n;j++)
                mat[j][i]=SAM_node[i].mat[j];
	    }
	    dfs(0);
	    printf("%d\n",ans);
	}
	return 0;
}
