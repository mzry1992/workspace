#include<cstdio>
#include<cstring>
struct edges
{
    int to,next;
}edge[19998];
int reb[10000],exi[10000],num[10000];
int head[10000],L;
double out(double x)
{
    if (x*0!=0)
        puts("impossible");
    else
        printf("%f\n",x);
}
struct rets
{
    double root,fu,con;
};
void init(int n)
{
    L=0;
    memset(head,-1,4*n);
    memset(num,0,4*n);
}
void add_edge(int u,int v)
{
    edge[L].to=v;
    edge[L].next=head[u];
    head[u]=L++;
}
rets dfs(int u,int fu)
{
    rets ret;
    ret.fu=1-reb[u]/100.0-exi[u]/100.0;
    ret.root=reb[u]/100.0;
    ret.con=ret.fu;
    ret.fu/=num[u]*1.0;
    rets tot;
    tot.fu=tot.con=tot.root=0;
    for (int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        if (v==fu) continue;
        rets tmp=dfs(v,u);
        tot.fu+=tmp.fu;
        tot.root+=tmp.root;
        tot.con+=tmp.con;
    }
    tot.fu*=ret.con/num[u];
    tot.root*=ret.con/num[u];
    tot.con*=ret.con/num[u];
    ret.root+=tot.root;
    ret.con+=tot.con;
    ret.root/=1-tot.fu;
    ret.fu/=1-tot.fu;
    ret.con/=1-tot.fu;
    if (fu==-1)
        ret.con/=(1-ret.root);
    return ret;
}
int main()
{
    int t;
    scanf("%d",&t);
    for (int cas=1;cas<=t;cas++)
    {
        int n;
        scanf("%d",&n);
        init(n);
        for (int i=1;i<n;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            num[--u]++;
            num[--v]++;
            add_edge(u,v);
            add_edge(v,u);
        }
        for (int i=0;i<n;i++)
            scanf("%d%d",&reb[i],&exi[i]);
        printf("Case %d: ",cas);
        out(dfs(0,-1).con);
    }
    return 0;
}
