#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int n,m;
struct point
{
    int x,y,z;
    double dist1,dist2;
};
struct dpoint
{
    double x,y,z;
};
point so[10100],cr[10100],v;
double dist[10100],dist2[10100];
int pre[10100],las[10100];
const double EPS = 1e-6;
int cnt;

bool cmp1(point a,point b)
{
    return a.dist1+EPS < b.dist1;
}

bool cmp2(point a,point b)
{
    return a.dist2+EPS < b.dist2;
}

double distofline(point a,point b,point v)
{
    if (v.x == 0)
        return fabs(a.x*1.0-b.x*1.0);
    double k = (double)v.y/(double)v.x;
    double b1,b2;
    b1 = (double)a.y-k*(double)a.x;
    b2 = (double)b.y-k*(double)b.x;
    k = sqrt(k*k+1);
    return ((b2-b1)/k);
}

double distofline2(point a,point b,point v)
{
    if (v.y == 0)
        return fabs(a.y*1.0-b.y*1.0);
    double k = (double)v.z/(double)v.y;
    double b1,b2;
    b1 = (double)a.z-k*(double)a.y;
    b2 = (double)b.z-k*(double)b.y;
    k = sqrt(k*k+1);
    return ((b2-b1)/k);
}

int b_search(double a[],double x,int l,int r)
{
    int i = l,j = r;
    while (i <= j)
    {
        int mid = (i+j)/2;
        if (x >= a[mid]+EPS) i = mid+1;
        else j = mid-1;
    }
    return i;
}

bool cmpone(point a,point b,point c)
{
    point d;
    d.x = a.x-b.x;
    d.y = a.y-b.y;
    d.z = a.z-b.z;
    double k[5];
    bool h[5];
    h[1] = h[2] = h[3] = false;
    if ((c.x == 0) && (d.x != 0))   return false;
    if (c.x != 0)
    {
        k[1] = (double)d.x/(double)c.x;
        h[1] = true;
    }
    if ((c.y == 0) && (d.y != 0))   return false;
    if (c.y != 0)
    {
        k[2] = (double)d.y/(double)c.y;
        h[2] = true;
    }
    if ((c.z == 0) && (d.z != 0))   return false;
    if (c.z != 0)
    {
        k[3] = (double)d.z/(double)c.z;
        h[3] = true;
    }
    for (int i = 1;i <= 3;i++)
        for (int j = 1;j <= 3;j++)
            if (h[i] == true)
                if (h[j] == true)
                    if (fabs(k[i]-k[j]) >= EPS)
                        return false;
    return true;
}

bool online(point a,point b,point c)
{
    dpoint d,e;
    d.x = (double)a.x-(double)b.x;
    d.y = (double)a.y-(double)b.y;
    d.z = (double)a.z-(double)b.z;
    e.x = (double)c.x;
    e.y = (double)c.y;
    e.z = (double)c.z;
    if (d.x*e.x+d.y*e.y+d.z*e.z >= -EPS)
        return true;
    return false;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&n,&m);
        for (int i = 1;i <= n;i++)
            scanf("%d%d%d",&so[i].x,&so[i].y,&so[i].z);
        for (int i = 1;i <= m;i++)
            scanf("%d%d%d",&cr[i].x,&cr[i].y,&cr[i].z);
        scanf("%d%d%d",&v.x,&v.y,&v.z);
        cr[1].dist1 = 0.0;
        for (int i = 2;i <= m;i++)
            cr[i].dist1 = distofline(cr[1],cr[i],v);
        sort(cr+1,cr+m+1,cmp1);
        for (int i = 2;i <= m;i++)
            cr[i].dist1 = cr[i].dist1-cr[1].dist1;
        cr[1].dist1 = 0.0;
        pre[1] = 1;
        for (int i = 2;i <= m;i++)
            if (fabs(cr[i].dist1-cr[i-1].dist1) < EPS)
                pre[i] = pre[i-1];
            else
                pre[i] = i;
        las[m] = m;
        for (int i = m-1;i >= 1;i--)
            if (pre[i] == pre[i+1])
                las[i] = las[i+1];
            else
                las[i] = i;
        int kl,kr;
        kl = pre[1];
        kr = las[1];
        while (true)
        {
            cr[kl].dist2 = 0.0;
            for (int i = kl+1;i <= kr;i++)
                cr[i].dist2 = distofline2(cr[kl],cr[i],v);
            sort(cr+kl,cr+kr+1,cmp2);
            for (int i = kl+1;i <= kr;i++)
                cr[i].dist2 = cr[i].dist2-cr[kl].dist2;
            cr[kl].dist2 = 0;
            if (kr == m)
                break;
            kl = pre[kr+1];
            kr = las[kl];
        }
        for (int i = 1;i <= m;i++)
        {
            dist[i] = cr[i].dist1;
            dist2[i] = cr[i].dist2;
        }
        cnt = 0;
        for (int i = 1;i <= n;i++)
        {
            double dis = distofline(cr[1],so[i],v);
            int pos1 = b_search(dist,dis,1,m);
            if (fabs(dis-dist[pos1]) >= EPS)
                continue;
            int tl,tr,pos2;
            tl = pre[pos1];
            tr = las[pos1];
            double dis2 = distofline2(cr[tl],so[i],v);
            pos2 = b_search(dist2,dis2,tl,tr);
            if (fabs(dis2-dist2[pos2]) >= EPS)
                continue;
            while (true)
            {
                if (cmpone(so[i],cr[pos2],v))
                if (online(so[i],cr[pos2],v))
                {
                    cnt++;
                    break;
                }
                if (pos2 == las[pos2])
                    break;
                if (fabs(dis2-dist2[pos2]) >= EPS)
                    break;
                pos2++;
            }
        }
        printf("Case %d: %d\n",ft,cnt);
    }
}
