#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int a[1000000];
int r,c,q;

inline int readint()
{
    char ch;
    bool ng;

    ch = getchar();
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-')
    {
        ng = true;
        ch = getchar();
    }
    else
        ng = false;

    int wg = ch-'0';
    ch = getchar();
    while (ch >= '0' && ch <= '9')
    {
        wg = wg*10+ch-'0';
        ch = getchar();
    }
    if (ng == true) wg = -wg;
    return wg;
}
vector<int> tree[1000];
bool flag=0;
void build(int pos,int x,int l,int r)
{
    if (l<r)
    {
        int mid=l+r>>1;
        build(pos,x*2,l,mid);
        build(pos,x*2+1,mid+1,r);
        tree[pos][x]=min(tree[pos][x*2],tree[pos][x*2+1]);
    }
    else if (!flag)
        tree[pos][x]=a[pos*c+l];
    else
        tree[pos][x]=a[l*c+pos];
}
int query(int pos,int x,int l,int r,int s,int t)
{
    if (s<=l && r<=t)
        return tree[pos][x];
    int mid=l+r>>1,res=0x7fffffff;
    if (s<=mid)
        res=query(pos,x*2,l,mid,s,t);
    if (t>mid)
        res=min(res,query(pos,x*2+1,mid+1,r,s,t));
    return res;
}
int main()
{
    while (true)
    {
        scanf("%d%d%d",&r,&c,&q);
        if (r == 0 && c == 0 && q == 0) break;
        if (r>c)
            flag=1;
        int spos = 0;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                a[spos++] = readint();
        if (!flag)
            for (int i=0; i<r; i++)
            {
                tree[i].resize(c*4);
                build(i,1,0,c-1);
            }
        else
            for (int i=0; i<c; i++)
            {
                tree[i].resize(r*4);
                build(i,1,0,r-1);
            }
        for (int i = 0; i < q; i++)
        {
            int xa,xb,ya,yb;
            scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
            if (!flag)
            {
                int res = 0x7fffffff;
                for (int x = xa; x <= xb; x++)
                    res=min(res,query(x,1,0,c-1,ya,yb));
                printf("%d\n",res);
            }
            else
            {
                int res = 0x7fffffff;
                for (int y = ya; y <= yb; y++)
                    res=min(res,query(y,1,0,r-1,xa,xb));
                printf("%d\n",res);
            }
        }
    }
    return 0;
}
