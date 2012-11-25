#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
const int inf=0x7fffffff;
int L,N;
int head[50000];
struct edge
{
    int to,next;
}edge[50000-1];
int l[100000],r[100000];
int tree[400000];
struct person
{
    int a,l,id,q;
    bool operator<(const person &x)const
    {
        if (a!=x.a)
            return a>x.a;
        else
            return q>x.q;
    }
}per[100000];
void init(int n)
{
    L=N=0;
    memset(head,-1,4*n);
}
void add_edge(int u,int v)
{
    edge[L].to=v;
    edge[L].next=head[u];
    head[u]=L++;
}
void dfs(int u,int deep,int num)
{
	//printf("%d %d %d\n",u,deep,num);
	//if (num == 50000)
	//	printf("%d %d\n",u,deep);
    l[u]=N++;
    for (int i=head[u];i!=-1;i=edge[i].next)
        dfs(edge[i].to,deep+1,num);
    r[u]=N++;
}
int maxs(int a,int b)
{
    if (a==-1)
        return b;
    if (b==-1)
        return a;
    if (per[a].l<per[b].l)
        return b;
    else
        return a;
}
void update(int x,int l,int r,int p,int v)
{
    if (l==r)
    {
        tree[x]=v;
        return ;
    }
    int mid=l+r>>1;
    if (p<=mid)
        update(x*2,l,mid,p,v);
    else
        update(x*2+1,mid+1,r,p,v);
    tree[x]=maxs(tree[x*2],tree[x*2+1]);
}
int query(int x,int l,int r,int s,int t)
{
    if (s<=l && r<=t)
        return tree[x];
    int mid=l+r>>1,ret=-1;
    if (s<=mid)
        ret=query(x*2,l,mid,s,t);
    if (t>mid)
        ret=maxs(ret,query(x*2+1,mid+1,r,s,t));
    return ret;
}
int ans[50000];
int main()
{
    freopen("4366.in","r",stdin);
    freopen("4366_2.out","w",stdout);
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        //printf("%d %d\n",n,m);
        init(n);
        per[0].id=0;
        per[0].q=-1;
        per[0].a=per[0].l=0;
        memset(tree,-1,sizeof(tree));
        for (int i=1;i<n;i++)
        {
            int x;
            scanf("%d%d%d",&x,&per[i].l,&per[i].a);
            add_edge(x,i);
            per[i].id=i;
            per[i].q=-1;
        }
        for (int i=0;i<m;i++)
        {
            int x;
            scanf("%d",&x);
			//if (n == 50000)
			//	printf("%d %d\n",n+i,x);
            per[n+i]=per[x];
            per[n+i].q=i;
        }
		//printf("hi\n");
        dfs(0,0,n);
        sort(per,per+n+m);
        for (int i=0;i<n+m;i++)
        {
            if (per[i].q==-1)
                update(1,0,n*2,l[per[i].id],i);
            else
                ans[per[i].q]=query(1,0,n*2,l[per[i].id],r[per[i].id]);
        }
        for (int i=0;i<m;i++)
        {
            if (ans[i]!=-1)
                ans[i]=per[ans[i]].id;
            printf("%d\n",ans[i]);
        }
    }
    return 0;
}
