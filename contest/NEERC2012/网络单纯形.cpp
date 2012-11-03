#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 20020;
const int M = 300000;
struct Node
{
    int depth,pot,id;
    Node *parent,*thread,*prev,*last;
};
struct Arc
{
    int tail,head,u,c;
};
Arc arc[M];
int cnt_arc;
Node nnode[N],*rec[N];
int cr;
const int inf = 1000000000;
void dfs(Node *n)
{
    cr=0;
    rec[cr++]=n;
    while(cr)
    {
        Node *nn=n->thread;
        nn->prev=n;
        n=nn;
        int d=n->depth;
        if(d<=rec[cr-1]->depth)
        {
            Node *l=rec[cr-1];
            while(cr&&d<=rec[cr-1]->depth)
            {
                rec[--cr]->last=l;
            }
        }
        if(cr) rec[cr++]=n;
    }
}
Node*pivot(Node*n1,Node*n2,Node*n3,Node*n4)
{
    dfs(n1);
    Node *n1l=n1->last,*n3l,*n3p,*end;
    if(n1l->thread==n2)
    {
        n2->parent=n1;
        dfs(n3);
        return n3->last->thread;
    }
    if(n1l->thread!=n3)
    {
        dfs(n4);
        n3p=n3->prev;
        n3l=n3->last;
        n3p->thread=n3l->thread;
        if(n3l==n1l)
            n3l->thread=n1->thread,n1->thread=n2;
        else
            n3l->thread=n1l->thread,n1l->thread=n2;
    }
    else
    {
        dfs(n3);
        n3l=n3->last;
        n1l->thread=n2;
    }
    end=n3l->thread;
    Node *n2l=n2->last,*n2lp=NULL,*p2=n1,*pp=NULL;
    int pid;
    int first=0;
    while(n2!=n3)
    {
        n2l=n2->last;
        Node *xp=pp;
        if(n2l!=n2lp) xp=n2l,n2lp=n2l;
        pp=n2->prev;
        pp->thread=xp->thread;
        xp->thread=n2->parent;
        Node *n2n=n2->parent;
        int ppid=n2->id;
        if(first) n2->id=pid^1;
        pid=ppid;
        first++;
        n2->parent=p2;
        p2=n2;
        n2=n2n;
    }
    if(first) n2->id=pid^1;
    n2->parent=p2;
    return end;
}
void update(Node *n1,Node *n2)
{
    n1=n1->thread;
    while(n1!=n2)
    {
        Node *n1p=n1->parent;
        n1->depth=n1p->depth+1;
        n1->pot = n1p->pot - arc[n1->id].c;
        n1=n1->thread;
    }
}
void pivot(int id)
{
    int tail=arc[id].tail,head=arc[id].head;
    int u=arc[id].u,c=arc[id].c;
    Node *uu=nnode+tail,*vv=nnode+head;
    Node *mu=0,*mv=0;
    int mn_f = u;
    while(uu!=vv)
    {
        int nid;
        if(uu->depth>vv->depth)
            nid=uu->id,uu=uu->parent;
        else nid=vv->id^1,vv=vv->parent;
        if(arc[nid].u<mn_f) mn_f=arc[nid].u;
    }
    uu=nnode+tail,vv=nnode+head;
    arc[id].u-=mn_f;
    arc[id^1].u+=mn_f;
    while(uu!=vv)
    {
        int nid;
        if(uu->depth>vv->depth)
        {
            nid=uu->id;
            arc[nid].u-=mn_f;
            arc[nid^1].u+=mn_f;
            if(arc[nid].u==0&&mu==0)
                mu=uu,mv=0;
            uu=uu->parent;
        }
        else
        {
            nid=vv->id^1;
            arc[nid].u-=mn_f;
            arc[nid^1].u+=mn_f;
            if(arc[nid].u==0&&mu==0)
                mv=vv;
            vv=vv->parent;
        }
    }
    if(arc[id].u)
    {
        if(mv)
        {
            int n3=mv-nnode,n4=mv->parent-nnode;
            Node *nx=pivot(nnode+tail,nnode+head,mv,mv->parent);
            nnode[head].id=id;
            update(nnode+tail,nx);
        }
        else
        {
            int n3=mu-nnode,n4=mu->parent-nnode;
            Node *nx=pivot(nnode+head,nnode+tail,mu,mu->parent);
            nnode[tail].id=id^1;
            update(nnode+head,nx);
        }
    }
}
struct List
{
    int v;
    List *R;
};
List lst[M],*cl,*hd;
pair<int,int> cost(int s,int t,int cnt_node)
{
    int tmp_arc=cnt_arc;
    int i;
    int sid=-1;
    nnode[cnt_node].depth=0;
    nnode[cnt_node].parent=nnode+cnt_node;
    nnode[cnt_node].pot=0;
    nnode[cnt_node].thread=nnode;
    for(i=0; i<cnt_node; i++)
    {
        nnode[i].depth=1;
        nnode[i].parent=nnode+cnt_node;
        nnode[i].thread=nnode+(i+1);
        nnode[i].id=tmp_arc;
        int pot=-inf,u=0,tot=0;
        if(i==s)
            pot=-pot,tot=inf,u=inf,sid=tmp_arc+1;
        if(i==t) tot=inf;
        nnode[i].pot=pot;
        arc[tmp_arc].tail=cnt_node;
        arc[tmp_arc].head=i;
        arc[tmp_arc].u=u;
        arc[tmp_arc].c=-pot;
        tmp_arc++;
        arc[tmp_arc].tail=i;
        arc[tmp_arc].head=cnt_node;
        arc[tmp_arc].u=tot-u;
        arc[tmp_arc].c=pot;
        tmp_arc++;
    }
    while(1)
    {
        bool fd=false;
        int i,tot=0;
        hd=cl=lst;
        cl->R=cl++;
        int tail,head,c,cc;
        const int MAXQ = cnt_node/4+5;
        const int MINQ = cnt_node/10+2;
        for(i=0; i<cnt_arc; i++)
        {
            if(arc[i].u==0) continue;
            tail=arc[i].tail;
            head=arc[i].head,c=arc[i].c;
            cc=c-nnode[tail].pot+nnode[head].pot;
            if(cc<0)
            {
                fd=true;
                cl->v=i;
                cl->R=hd->R;
                hd->R=cl;
                cl++;
                tot++;
                if(tot>=MAXQ)
                {
                    while(tot>MINQ)
                    {
                        List *mj=NULL,*mjp,*it=hd->R,*itp=hd;
                        int mp=0;
                        while(it!=hd)
                        {
                            int id=it->v;
                            tail=arc[id].tail,head=arc[id].head,c=arc[id].c;
                            cc=c-nnode[tail].pot+nnode[head].pot;
                            if(cc>=0)
                            {
                                itp->R=it->R;
                                tot--;
                            }
                            else if(cc<mp)
                                mp=cc,mj=it,mjp=itp;
                            if(itp->R==it) itp=it;
                            it=it->R;
                        }
                        if(mj==NULL) break;
                        pivot(mj->v);
                        mjp->R=mj->R;
                        tot--;
                    }
                }
            }
        }
        while(tot)
        {
            List *it=hd->R,*itp=hd;
            while(it!=hd)
            {
                int id=it->v;
                tail=arc[id].tail,head=arc[id].head;
                c=arc[id].c;
                cc=c-nnode[tail].pot+nnode[head].pot;
                if(cc<0) pivot(id);
                itp->R=it->R;
                tot--;
                it=it->R;
            }
        }
        if(!fd) break;
    }
    int sum=0;
    for(i=0; i<cnt_arc; i+=2)
    {
        sum+=arc[i].c*arc[i^1].u;
    }
    return pair<int,int>(arc[sid].u,sum);
}
void add_arc(int tail,int head,int u,int c)
{
    arc[cnt_arc].tail=tail;
    arc[cnt_arc].head=head;
    arc[cnt_arc].u=u;
    arc[cnt_arc].c=c;
    cnt_arc++;
}

void init()
{
    cnt_arc = 0;
}

void add_edge(int x,int y,int cap,int cost)
{
    add_arc(x,y,cap,cost);
    add_arc(y,x,0,-cost);
}

int hash[100005];
struct{
    int st, ed, w;
}inl[405];

int main()
{
    int t, i, N, K,k,n;
    scanf("%d", &t);
    while(t --)
    {
        memset(hash, 0, sizeof(hash));
        scanf("%d%d", &N, &K);
        for(i = 0; i < N; i ++)
        {
            scanf("%d%d%d", &inl[i].st, &inl[i].ed, &inl[i].w);
            hash[inl[i].st] = hash[inl[i].ed] = 1;
        }
        for(k = 1, i = 0; i <= 100000; i ++)     //  由于100000不大，所以我用hash离散化。
            if(hash[i] == 1)
                hash[i] = k ++;
        for(i = 0; i < N; i ++)                  //  线段的端点值，改为离散后的下标号。
        {
            inl[i].st = hash[inl[i].st];
            inl[i].ed = hash[inl[i].ed];
        }
        n = k;
        k = 0;
        for(i = 0; i < n; i ++)                  //  建图。
            add_edge(i, i+1, K, 0);
        for(i = 0; i < N; i ++)
            add_edge(inl[i].st, inl[i].ed, 1, inl[i].w);
        printf("%d\n", cost(0,n,n+1).second);
    }
    return 0;
}
