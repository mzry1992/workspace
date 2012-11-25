#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1000001;
int rank[maxn],sml[maxn],num[maxn],r[maxn];
bool isprime[maxn];
struct node
{
    node *l,*r;
    int sum;
}tree[maxn*4+maxn*20*2],*root[maxn+1];
int N;
node *newnode()
{
    tree[N].l=tree[N].r=NULL;
    tree[N].sum=0;
    return &tree[N++];
}
node *newnode(node *x)
{
    tree[N].l=x->l;
    tree[N].r=x->r;
    tree[N].sum=x->sum;
    return &tree[N++];
}
node *build(int l,int r)
{
    node *x=newnode();
    if (l<r)
    {
        int mid=l+r>>1;
        x->l=build(l,mid);
        x->r=build(mid+1,r);
        x->sum=x->l->sum+x->r->sum;
    }
    else
        x->sum=0;
    return x;
}
node *update(node *x,int l,int r,int p,int v)
{
    if (l<r)
    {
        int mid=l+r>>1;
        node *nx=newnode(x);
        if (p<=mid)
            nx->l=update(x->l,l,mid,p,v);
        else
            nx->r=update(x->r,mid+1,r,p,v);
        nx->sum=nx->l->sum+nx->r->sum;
        return nx;
    }
    else
    {
        node *nx=newnode(x);
        nx->sum+=v;
        return nx;
    }
}
int query(node *x1,node *x2,int l,int r,int k)
{
    if (l<r)
    {
        int mid=l+r>>1;
        int lsum=x2->l->sum-x1->l->sum;
        if (lsum>=k)
            return query(x1->l,x2->l,l,mid,k);
        else
            return query(x1->r,x2->r,mid+1,r,k-lsum);
    }
    else
        return l;
}
void getPrime()
{
    memset(isprime,1,sizeof(isprime));
    memset(sml,-1,sizeof(sml));
    for (int i=2;i<maxn;i++)
        if (isprime[i])
        {
            for (int j=i+i;j<maxn;j+=i)
            {
                isprime[j]=0;
                if (sml[j]==-1)
                    sml[j]=i;
            }
            sml[i]=i,num[i] = 1;
        }
    for (int i = 2;i < maxn;i++)
        if (!isprime[i])
            num[i] = 1+num[i/sml[i]];
}

bool cmp1(const int& a,const int& b)
{
    if (num[a] == num[b])
        return a < b;
    return num[a] < num[b];
}

bool cmp2(const int& a,const int& b)
{
    if (sml[a] == sml[b])
        return r[a/sml[a]] < r[b/sml[b]];
    return sml[a] < sml[b];
}

void getRank()
{
    for (int i = 0;i < maxn;i++)
        rank[i] = r[i] = i;
    sort(rank+2,rank+maxn,cmp1);
    int pre = 2;
    for (int i = 3;i <= maxn;i++)
        if (i == maxn || num[rank[i]] != num[rank[i-1]])
        {
            if (pre != 2)
                sort(rank+pre,rank+i,cmp2);
            for (int j = pre;j < i;j++)
                r[rank[j]] = j;
            pre = i;
        }
}

int main()
{
    getPrime();
    getRank();
    N=0;
    root[0]=build(0,maxn-1);
    for (int i=1;i<=maxn;i++)
        root[i]=update(root[i-1],0,maxn-1,r[i-1],1);
	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
        int a,b,k;
        scanf("%d%d%d",&a,&b,&k);
        int res = rank[query(root[a],root[b+1],0,maxn-1,k)];
        printf("Case %d:",cas);
        while (res > 1)
        {
            printf(" %d",sml[res]);
            res /= sml[res];
        }
        printf("\n");
	}
	return 0;
}