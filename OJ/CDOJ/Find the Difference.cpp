#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m,a[50][50],b[50][50],totres;
struct rect
{
    int xa,ya,xb,yb;
    rect(){}
    rect(int _xa,int _ya,int _xb,int _yb)
        {
            xa = _xa;
            ya = _ya;
            xb = _xb;
            yb = _yb;
        }
}res[3000];

void Gao(int xa,int ya,int xb,int yb)
{
    while (true)
    {
        bool flag = true;
        for (int i = ya;i <= yb;i++)
            if (a[xa][i] != b[xa][i])
            {
                flag = false;
                break;
            }
        if (flag == true)   xa++;
        else    break;
        if (xa == n)    break;
    }
    while (true)
    {
        bool flag = true;
        for (int i = ya;i <= yb;i++)
            if (a[xb][i] != b[xb][i])
            {
                flag = false;
                break;
            }
        if (flag == true)   xb--;
        else    break;
        if (xb == -1)    break;
    }
    if (xa > xb)    return;
    while (true)
    {
        bool flag = true;
        for (int i = xa;i <= xb;i++)
            if (a[i][ya] != b[i][ya])
            {
                flag = false;
                break;
            }
        if (flag == true)   ya++;
        else    break;
        if (ya == m)    break;
    }
    while (true)
    {
        bool flag = true;
        for (int i = xa;i <= xb;i++)
            if (a[i][yb] != b[i][yb])
            {
                flag = false;
                break;
            }
        if (flag == true)   yb--;
        else    break;
        if (yb == -1)    break;
    }
    if (ya > yb)    return;
    bool hasdiv = false;
    for (int i = xa+1;i < xb;i++)
    {
        bool flag = true;
        for (int j = ya;j <= yb;j++)
            if (a[i][j] != b[i][j])
            {
                flag = false;
                break;
            }
        if (flag == true)
        {
            hasdiv = true;
            Gao(xa,ya,i-1,yb);
            Gao(i+1,ya,xb,yb);
            break;
        }
    }
    if (hasdiv == true) return;
    for (int i = ya+1;i < yb;i++)
    {
        bool flag = true;
        for (int j = xa;j <= xb;j++)
            if (a[j][i] != b[j][i])
            {
                flag = false;
                break;
            }
        if (flag == true)
        {
            hasdiv = true;
            Gao(xa,ya,xb,i-1);
            Gao(xa,i+1,xb,yb);
            break;
        }
    }
    if (hasdiv == true) return;
    res[totres++] = rect(xa,ya,xb,yb);
}

bool cmp(const rect& a,const rect& b)
{
    if (a.xa == b.xa)
        return a.ya < b.ya;
    return a.xa < b.xa;
}

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        for (int i = 0;i < n;i++)
            for (int j = 0;j < m;j++)
                scanf("%d",&a[i][j]);
        for (int i = 0;i < n;i++)
            for (int j = 0;j < m;j++)
                scanf("%d",&b[i][j]);
        totres = 0;
        Gao(0,0,n-1,m-1);
        sort(res,res+totres,cmp);
        printf("%d\n",totres);
        for (int i = 0;i < totres;i++)
            printf("%d %d %d %d\n",res[i].xa+1,res[i].ya+1,res[i].xb+1,res[i].yb+1);
    }
}
