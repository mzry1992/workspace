#include <cstdio>
#include <algorithm>
using namespace std;
int n;
bool con[400000][2];
bool col[400000][2];
bool row[400000];
struct Tree
{
    bool con[2][2];
}tree[400000];
void build(int x,int l,int r)
{
    if (l<r)
    {
        col[x][0]=col[x][1]=con[x][0]=con[x][1]=0;
        tree[x].con[0][0]=tree[x].con[0][1]=tree[x].con[1][0]=tree[x].con[1][1]=0;
        int mid=l+r>>1;
        build(x*2,l,mid);
        build(x*2+1,mid+1,r);
    }
    else
    {
        row[x]=0;
        col[x][0]=col[x][1]=1;
        tree[x].con[0][0]=tree[x].con[1][1]=1;
        tree[x].con[0][1]=tree[x].con[1][0]=0;
    }
}
Tree up(Tree a,Tree b,bool flag0,bool flag1)
{
    Tree ret;
    for (int i=0; i<2; i++)
        for (int j=0; j<2; j++)
            ret.con[i][j]=(a.con[i][0]&&b.con[0][j]&&flag0)||(a.con[i][1]&&b.con[1][j]&&flag1);
    return ret;
}
void update(int x,int l,int r,int p,bool v)
{
    if (l==r)
    {
        tree[x].con[0][1]=tree[x].con[1][0]=v;
        row[x]=v;
        return ;
    }
    int mid=l+r>>1;
    if (p<=mid)
        update(x*2,l,mid,p,v);
    else
        update(x*2+1,mid+1,r,p,v);
    tree[x]=up(tree[x*2],tree[x*2+1],con[x][0],con[x][1]);
    row[x]=row[x*2]||row[x*2+1];
}
void update(int x,int l,int r,int p,bool pos,bool v)
{
    int mid=l+r>>1;
    if (p==mid)
        con[x][pos]=v;
    else if (p<mid)
        update(x*2,l,mid,p,pos,v);
    else
        update(x*2+1,mid+1,r,p,pos,v);
    tree[x]=up(tree[x*2],tree[x*2+1],con[x][0],con[x][1]);
    col[x][pos]=con[x][pos]&&col[x*2][pos]&&col[x*2+1][pos];
}
Tree query(int x,int l,int r,int s,int t)
{
    if (s<=l && r<=t)
        return tree[x];
    int mid=l+r>>1;
    if (t<=mid)
        return query(x*2,l,mid,s,t);
    else if (s>mid)
        return query(x*2+1,mid+1,r,s,t);
    else
        return up(query(x*2,l,mid,s,t),query(x*2+1,mid+1,r,s,t),con[x][0],con[x][1]);
}
int getLeft(int x,int l,int r,int p)
{
    if (col[x][0] && col[x][1])
        return l;
    int mid=l+r>>1;
    if (p<=mid)
        return getLeft(x*2,l,mid,p);
    else
    {
        int ret=getLeft(x*2+1,mid+1,r,p);
        if (ret==mid+1 && con[x][0] && con[x][1])
            return getLeft(x*2,l,mid,mid);
        else
            return ret;
    }
}
int getRight(int x,int l,int r,int p)
{
    if (col[x][0] && col[x][1])
        return r;
    int mid=l+r>>1;
    if (p>mid)
        return getRight(x*2+1,mid+1,r,p);
    else
    {
        int ret=getRight(x*2,l,mid,p);
        if (ret==mid && con[x][0] && con[x][1])
            return getLeft(x*2+1,mid+1,r,mid+1);
        else
            return ret;
    }
}
bool getRow(int x,int l,int r,int s,int t)
{
    if (s<=l && r<=t)
        return row[x];
    int mid=l+r>>1;
    bool flag=0;
    if (s<=mid)
        flag=getRow(x*2,l,mid,s,t);
    if (t>mid)
        flag|=getRow(x*2+1,mid+1,r,s,t);
    return flag;
}
bool query(int r1,int c1,int r2,int c2)
{
    if (c1>c2)
    {
        swap(c1,c2);
        swap(r1,r2);
    }
    Tree ret=query(1,1,n,c1,c2);
    bool flag0,flag1;
    int idx=getLeft(1,1,n,c1);
    flag0=getRow(1,1,n,idx,c1);
    idx=getRight(1,1,n,c2);
    flag1=getRow(1,1,n,c2,idx);
    for (int i=0;i<2;i++)
        for (int j=0;j<2;j++)
            if ((i==r1-1 || flag0)&&(j==r2-1 || flag1) && ret.con[i][j])
                return 1;
    return 0;
}
char s[5];
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        build(1,1,n);
        while (scanf("%s",s),s[0]!='E')
        {
            int r1,c1,r2,c2;
            scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
            if (s[0]=='O')
            {
                if (c1==c2)
                    update(1,1,n,c1,1);
                else
                    update(1,1,n,min(c1,c2),r1-1,1);
            }
            else if (s[0]=='C')
            {
                if (c1==c2)
                    update(1,1,n,c1,0);
                else
                    update(1,1,n,min(c1,c2),r1-1,0);
            }
            else
                if (query(r1,c1,r2,c2))
                    puts("Y");
                else
                    puts("N");
        }
    }
    return 0;
}

