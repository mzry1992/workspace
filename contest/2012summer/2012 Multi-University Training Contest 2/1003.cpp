#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

struct Point
{
    int x,y,idy,id,idxy0,idxy1;
};

bool cmp(Point a,Point b)
{
    if (a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}

bool cmp2(Point a,Point b)
{
    if (a.x == b.x)
        return a.y > b.y;
    return a.x > b.x;
}

Point p[100000];
int n,sy[100000],sxy0[100000],sxy1[100000],my,mxy0,mxy1,m;
long long tree[9][100001],sum[8][100001];

void update(int id,int x,int v)
{
    for (;x <= m;x+=x&-x)
        tree[id][x] += v;
}

long long read(int id,int x)
{
    long long res = 0;
    for (;x > 0;x^=x&-x)
        res += tree[id][x];
    return res;
}

long long read(int id,int x,int y)
{
    if (x > y)  return 0;
    return read(id,y)-read(id,x-1);
}

int wg;
char ch;
bool ng;

inline int readint()
{
    ch = getchar();
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-')
    {
        ng = true;
        ch = getchar();
    }
    else
        ng = false;
    wg = ch-'0';
    ch = getchar();
    while (ch >= '0' && ch <= '9')
    {
        wg = wg*10+ch-'0';
        ch = getchar();
    }
    if (ng == true) wg = -wg;
    return wg;
}

int main()
{
    int totcas;
    scanf("%d",&totcas);
    while (totcas--)
    {
        scanf("%d",&n);
        for (int i = 0;i < n;i++)
        {
            p[i].x = readint();
            p[i].y = readint();
            sy[i] = p[i].y;
            sxy0[i] = p[i].x-p[i].y;
            sxy1[i] = p[i].x+p[i].y;
            p[i].id = i;
        }
        sort(sy,sy+n);
        sort(sxy0,sxy0+n);
        sort(sxy1,sxy1+n);
        my = unique(sy,sy+n)-sy;
        mxy0 = unique(sxy0,sxy0+n)-sxy0;
        mxy1 = unique(sxy1,sxy1+n)-sxy1;
        for (int i = 0;i < n;i++)
        {
            p[i].idy = lower_bound(sy,sy+my,p[i].y)-sy+1;
            p[i].idxy0 = lower_bound(sxy0,sxy0+mxy0,p[i].x-p[i].y)-sxy0+1;
            p[i].idxy1 = lower_bound(sxy1,sxy1+mxy1,p[i].x+p[i].y)-sxy1+1;
        }
        m = max(m,max(mxy0,mxy1));

        sort(p,p+n,cmp);
        memset(tree,0,sizeof(tree));
        for (int i = 0;i < n;i++)
        {
            sum[0][p[i].id] = p[i].y*(read(2,1,m)-read(5,1,p[i].idxy0))-(read(1,1,m)-read(4,1,p[i].idxy0));
            sum[1][p[i].id] = p[i].x*(read(5,1,p[i].idxy0)-read(2,p[i].idy,m))-(read(3,1,p[i].idxy0)-read(0,p[i].idy,m));
            sum[2][p[i].id] = p[i].x*(read(8,1,p[i].idxy1)-read(2,1,p[i].idy-1))-(read(6,1,p[i].idxy1)-read(0,1,p[i].idy-1));
            sum[3][p[i].id] = -p[i].y*(read(2,1,m)-read(8,1,p[i].idxy1))+(read(1,1,m)-read(7,1,p[i].idxy1));

            update(0,p[i].idy,p[i].x);
            update(1,p[i].idy,p[i].y);
            update(2,p[i].idy,1);
            update(3,p[i].idxy0,p[i].x);
            update(4,p[i].idxy0,p[i].y);
            update(5,p[i].idxy0,1);
            update(6,p[i].idxy1,p[i].x);
            update(7,p[i].idxy1,p[i].y);
            update(8,p[i].idxy1,1);
        }

        sort(p,p+n,cmp2);
        memset(tree,0,sizeof(tree));
        for (int i = 0;i < n;i++)
        {
            sum[4][p[i].id] = -p[i].y*(read(2,1,m)-read(8,p[i].idxy0,m))+read(1,1,m)-read(7,p[i].idxy0,m);
            sum[5][p[i].id] = -p[i].x*(read(8,p[i].idxy0,m)-read(2,1,p[i].idy))+read(6,p[i].idxy0,m)-read(0,1,p[i].idy);
            sum[6][p[i].id] = -p[i].x*(read(5,p[i].idxy1,m)-read(2,p[i].idy+1,m))+read(3,p[i].idxy1,m)-read(0,p[i].idy+1,m);
            sum[7][p[i].id] = p[i].y*(read(2,1,m)-read(5,p[i].idxy1,m))-read(1,1,m)+read(4,p[i].idxy1,m);

            update(0,p[i].idy,p[i].x);
            update(1,p[i].idy,p[i].y);
            update(2,p[i].idy,1);
            update(3,p[i].idxy1,p[i].x);
            update(4,p[i].idxy1,p[i].y);
            update(5,p[i].idxy1,1);
            update(6,p[i].idxy0,p[i].x);
            update(7,p[i].idxy0,p[i].y);
            update(8,p[i].idxy0,1);
        }

        long long res = 0x7fffffffffffffffLL;
        for (int i = 0;i < n;i++)
        {
            long long tmp = 0;
            for (int j = 0;j < 8;j++)
                tmp += sum[j][i];
            res = min(res,tmp);
        }
        printf("%I64d\n",res);
    }
	return 0;
}
