#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

struct Query
{
    int l,r,id;
    Query() {}
    Query(int _l,int _r,int _id)
    {
        l = _l;
        r = _r;
        id = _id;
    }
};

struct Node
{
    int l,r,d,tim;
    Node* f;
    vector<Node*> ch;
    vector<Query> q;
};

Node* ti[1000001];
Node node[1000000];
int L;

Node* newNode(int _l,int _r,int _d,int _tim,Node* _f)
{
    Node* res = &node[L++];
    res->l = _l;
    res->r = _r;
    res->d = _d;
    res->tim = _tim;
    res->f = _f;
    res->ch.clear();
    res->q.clear();
    ti[_tim] = res;
    return res;
}

int n,m,a[1000000];
long long ans[1000000];
char buf[5];
struct Tree
{
    long long sum;
    long long lazy;
} tree[4000000];
void up(int x)
{
    tree[x].sum=tree[x*2].sum+tree[x*2+1].sum;
}
void down(int x,int l,int r)
{
    tree[x].sum+=(long long)(r-l+1)*tree[x].lazy;
    if (l<r)
    {
        tree[x*2].lazy+=tree[x].lazy;
        tree[x*2+1].lazy+=tree[x].lazy;
    }
    tree[x].lazy=0;
}
void build(int x,int l,int r)
{
    tree[x].lazy=0;
    if (l<r)
    {
        int mid=l+r>>1;
        build(x*2,l,mid);
        build(x*2+1,mid+1,r);
        up(x);
    }
    else
        tree[x].sum=a[l];
}
void update(int x,int l,int r,int s,int t,int d)
{
    down(x,l,r);
    if (s<=l && r<=t)
    {
        tree[x].lazy=d;
        down(x,l,r);
        return ;
    }
    int mid=l+r>>1;
    if (s<=mid)
        update(x*2,l,mid,s,t,d);
    else
        down(x*2,l,mid);
    if (t>mid)
        update(x*2+1,mid+1,r,s,t,d);
    else
        down(x*2+1,mid+1,r);
    up(x);
}
long long query(int x,int l,int r,int s,int t)
{
    down(x,l,r);
    if (s<=l && r<=t)
        return tree[x].sum;
    int mid=l+r>>1;
    long long ret=0;
    if (s<=mid)
        ret=query(x*2,l,mid,s,t);
    if (t>mid)
        ret+=query(x*2+1,mid+1,r,s,t);
    return ret;
}
void dfs(Node *u)
{
    update(1,0,n-1,u->l,u->r,u->d);
    for (int i=0; i<u->q.size(); i++)
       ans[u->q[i].id]=query(1,0,n-1,u->q[i].l,u->q[i].r);
    for (int i=0; i<u->ch.size(); i++)
        dfs(u->ch[i]);
    update(1,0,n-1,u->l,u->r,-u->d);
}
int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        for (int i = 0; i < n; i++)
            scanf("%d",&a[i]);
        L = 0;
        Node* cur = newNode(0,n-1,0,0,0);
        int tim = 0,qid=0;
        for (int i = 0; i < m; i++)
        {
            int l,r,d,t;
            scanf("%s",buf);
            if (buf[0] == 'C')
            {
                scanf("%d%d%d",&l,&r,&d);
                cur->ch.push_back(newNode(l-1,r-1,d,++tim,cur));
                cur=cur->ch.back();
            }
            else if (buf[0] == 'Q')
            {
                scanf("%d%d",&l,&r);
                cur->q.push_back(Query(l-1,r-1,qid++));
            }
            else if (buf[0] == 'H')
            {
                scanf("%d%d%d",&l,&r,&t);
                ti[t]->q.push_back(Query(l-1,r-1,qid++));
            }
            else
            {
                scanf("%d",&tim);
                cur = ti[tim];
            }
        }
        build(1,0,n-1);
        dfs(ti[0]);
        for (int i=0; i<qid; i++)
            printf("%I64d\n",ans[i]);
    }
    return 0;
}
