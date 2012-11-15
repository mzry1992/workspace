#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;

struct Matrix
{
    int a[3][3];
}a[30005];
int n,m,r;
struct node
{
    int left,right;
    Matrix a;
}tree[130000];

Matrix mult(Matrix a,Matrix b)
{
    Matrix c;
    for (int i=0;i<2;i++)
        for (int j=0;j<2;j++) c.a[i][j]=0;
    for (int i=0;i<2;i++)
        for (int j=0;j<2;j++)
            for (int k=0;k<2;k++)
                c.a[i][j]=(c.a[i][j]+a.a[i][k]*b.a[k][j])%r;
    return c;
}

void build(int l,int r,int k)
{
    tree[k].left=l;tree[k].right=r;
    if (l==r)
    {
        tree[k].a=a[l];
        return;
    }
    else
    {
        int m=(l+r)>>1;
        build(l,m,k*2);
        build(m+1,r,k*2+1);
        tree[k].a=mult(tree[k*2].a,tree[k*2+1].a);
    }
}

Matrix query(int l,int r,int k)
{
    if (tree[k].left>=l && tree[k].right<=r)
        return tree[k].a;
    else
    {
        int m=(tree[k].left+tree[k].right)/2;
        if (r<=m) return query(l,r,k*2);
        else if (l>m) return query(l,r,k*2+1);
        else  return mult(query(l,m,k*2),query(m+1,r,k*2+1));
    }
}
int main()
{
    bool flag=true;
    while (scanf("%d%d%d",&r,&n,&m)>0)
    {
        if (flag) flag=false;else puts("");
        for (int i=1;i<=n;i++)
            for (int j=0;j<2;j++)
                for (int k=0;k<2;k++) scanf("%d",&a[i].a[j][k]);
        build(1,n,1);
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            Matrix ans=query(x,y,1);
            printf("%d %d\n",ans.a[0][0],ans.a[0][1]);
            printf("%d %d\n",ans.a[1][0],ans.a[1][1]);
            if (i<m) puts("");
        }
    }
}

