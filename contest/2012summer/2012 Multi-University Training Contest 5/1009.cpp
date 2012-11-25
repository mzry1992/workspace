#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int MaxN = 50000;

struct Point
{
    int x[5];
} a[MaxN];
int n,m,q;

bool cmp0(const Point &a, const Point &b)
{
    return a.x[0] < b.x[0];
}
bool cmp1(const Point &a, const Point &b)
{
    return a.x[1] < b.x[1];
}
bool cmp2(const Point &a, const Point &b)
{
    return a.x[2] < b.x[2];
}
bool cmp3(const Point &a, const Point &b)
{
    return a.x[3] < b.x[3];
}
bool cmp4(const Point &a, const Point &b)
{
    return a.x[4] < b.x[4];
}

void BuildKD(int l,int r,Point p[],int div)
{
    if (l > r)  return;
    int mid = l+r>>1;
    if (div == 0)
        nth_element(p+l,p+mid,p+r+1,cmp0);
    else if (div == 1)
        nth_element(p+l,p+mid,p+r+1,cmp1);
    else if (div == 2)
        nth_element(p+l,p+mid,p+r+1,cmp2);
    else if (div == 3)
        nth_element(p+l,p+mid,p+r+1,cmp3);
    else if (div == 4)
        nth_element(p+l,p+mid,p+r+1,cmp4);
    BuildKD(l,mid-1,p,(div+1)%m);
    BuildKD(mid+1,r,p,(div+1)%m);
}

Point b;
int dis[11],rescnt,cnt;
int res[11][5];

void update(int dist,int px[])
{
    for (int i = 0; i < rescnt; i++)
        if (dis[i] > dist)
        {
            for (int j = rescnt; j >= i; j--)
            {
                dis[j] = dis[j-1];
                for (int k = 0; k < m; k++)
                    res[j][k] = res[j-1][k];
            }
            dis[i] = dist;
            for (int k = 0; k < m; k++)
                res[i][k] = px[k];
            if (rescnt < cnt)
                rescnt++;
            return;
        }
    if (rescnt < cnt)
    {
        dis[rescnt] = dist;
        for (int k = 0; k < m; k++)
            res[rescnt][k] = px[k];
        rescnt++;
    }
}

int dist2(Point a,Point b)
{
    int res = 0;
    for (int i = 0; i < m; i++)
        res += (a.x[i]-b.x[i])*(a.x[i]-b.x[i]);
    return res;
}

void Find(int l,int r,Point a,Point p[],int div)
{
    if (l > r)  return;
    int mid = l+r>>1;
    int dist = dist2(a,p[mid]);
    update(dist,p[mid].x);
    int d = a.x[div]-p[mid].x[div];
    int l1, l2, r1, r2;
    l1 = l, l2 = mid + 1;
    r1 = mid - 1, r2 = r;
    if (d > 0)
        swap(l1, l2), swap(r1, r2);
    Find(l1, r1, a, p,(div+1)%m);
    if (rescnt < cnt)
        Find(l2,r2,a,p,(div+1)%m);
    else if (d * d < dis[cnt-1])
        Find(l2, r2, a, p,(div+1)%m);
}

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                scanf("%d",&a[i].x[j]);
        BuildKD(0,n-1,a,0);
        scanf("%d",&q);
        for (int i = 0; i < q; i++)
        {
            for (int j = 0; j < m; j++)
                scanf("%d",&b.x[j]);
            scanf("%d",&cnt);

            rescnt = 0;
            Find(0,n-1,b,a,0);

            printf("the closest %d points are:\n",cnt);
            for (int j = 0;j < cnt;j++)
            {
                //printf("dist = %d : ",dis[j]);
                printf("%d",res[j][0]);
                for (int k = 1;k < m;k++)
                    printf(" %d",res[j][k]);
                printf("\n");
            }
        }
    }
    return 0;
}
