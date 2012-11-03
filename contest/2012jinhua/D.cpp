#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m,k,a[200000],tree[4*200000],lazy[4*200000],b[200000];
int p,x,y;

void build(int root,int l,int r)
{
    lazy[root] = 0;
    if (l == r)
    {
        tree[root] = b[l];
        return;
    }
    int mid = (l+r)>>1;
    build(root*2,l,mid);
    build(root*2+1,mid+1,r);
    tree[root] = max(tree[root*2],tree[root*2+1]);
}

void clear(int root,int l,int r)
{
    tree[root]+=lazy[root];
    if (l<r)
    {
        lazy[root*2]+=lazy[root];
        lazy[root*2+1]+=lazy[root];
    }
    lazy[root]=0;
}

void updata(int root,int l,int r,int s,int t,int val)
{
    clear(root,l,r);
    if (s <= l && r <= t)
    {
        lazy[root] = val;
        clear(root,l,r);
        return;
    }
    int mid = (l+r)>>1;
    if (s<=mid)
        updata(root*2,l,mid,s,t,val);
    else
        clear(root*2,l,mid);
    if (t>mid)
        updata(root*2+1,mid+1,r,s,t,val);
    else
        clear(root*2+1,mid+1,r);
    int x=root;
    tree[x]=max(tree[x*2],tree[x*2+1]);
}

int query(int root,int l,int r,int ql,int qr)
{
    //cout << root << ' ' << l << ' ' << r << endl;
    clear(root,l,r);
    if (ql <= l && r <= qr) return tree[root];
    int mid = (l+r)>>1;
    int ret=-1000000000;
    if (ql<=mid)
        ret=query(root*2,l,mid,ql,qr);
    if (qr>mid)
        ret=max(ret,query(root*2+1,mid+1,r,ql,qr));
    return ret;
}

int main()
{
	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
        scanf("%d%d%d",&n,&m,&k);
        for (int i = 0;i < n;i++)
            scanf("%d",&a[i]);
        int tmp = 0;
        for (int i = 0;i < n;i++)
        {
            tmp += a[i];
            if (i >= k-1)
            {
                b[i-k+1] = tmp;
                tmp -= a[i-k+1];
            }
        }
        n = n-k+1;
        //for (int i = 0;i < n;i++)
        //    printf("%d ",b[i]);
        //printf("\n");
        build(1,0,n-1);
        for (int i = 0;i < m;i++)
        {
            scanf("%d%d%d",&p,&x,&y);
            if (p == 0)
            {
                x--;
                updata(1,0,n-1,max(0,x-k+1),x,y-a[x]);
                a[x] = y;
            }
            else if (p == 1)
            {
                x--;y--;
                int ax = a[x];
                int ay = a[y];
                //cout << max(0,x-k+1) << ' ' << x << ' ' << ay-ax << endl;
                updata(1,0,n-1,max(0,x-k+1),x,ay-ax);
                //cout << max(0,y-k+1) << ' ' << y << ' ' << ax-ay << endl;
                updata(1,0,n-1,max(0,y-k+1),y,ax-ay);
                a[x] = ay;
                a[y] = ax;
            }
            else
            {
                x--;y--;
                printf("%d\n",query(1,0,n-1,x,y-k+1));
            }
        }
	}
	return 0;
}
