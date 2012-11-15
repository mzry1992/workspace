#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int N = 500;
const int INFI = 19930703;
bool visx[N],visy[N];
int lx[N],ly[N];
int matchy[N];
int map[N][N];
int xcnt,ycnt;
int lack;
int s[20][20],t[20][20];
int n;

bool find(int x)
{
    visx[x] = true;
    int t;
    for (int y = 0;y < ycnt;y++)
    {
        if (!visy[y])
        {
            t = lx[x]+ly[y]-map[x][y];
            if (t == 0)
            {
                visy[y] = true;
                if (matchy[y] == -1 || find(matchy[y]))
                {
                    matchy[y] = x;
                    return true;
                }
            }
            else if (lack > t)  lack = t;
        }
    }
    return false;
}

int KM()
{
    memset(lx,0,sizeof(lx));
    memset(ly,0,sizeof(ly));
    memset(matchy,-1,sizeof(matchy));
    for (int i = 0;i < xcnt;i++)
        for (int j = 0;j < ycnt;j++)
            if (map[i][j] > lx[i])
                lx[i] = map[i][j];
    for (int x = 0;x < xcnt;x++)
    {
        while (true)
        {
            memset(visx,false,sizeof(visx));
            memset(visy,false,sizeof(visy));
            lack = INFI;
            if (find(x)) break;
            for (int i = 0;i < xcnt;i++)
            {
                if (visx[i]) lx[i] -= lack;
                if (visy[i]) ly[i] += lack;
            }
        }
    }
    int cost = 0;
    for (int i = 0;i < ycnt;i++)
        cost += map[matchy[i]][i];
    return cost;
}

int abs(int a)
{
    if (a < 0)  a = -a;
    return a;
}

int main()
{
    while (true)
    {
        scanf("%d",&n);
        if (n == 0)
            break;
        memset(s,0,sizeof(s));
        memset(t,0,sizeof(t));
        int sums,sumt;
        sums = sumt = 0;
        for (int i = 1;i <= n;i++)
        {
            int ta;
            scanf("%d",&ta);
            for (int j = 1;j <= 12;j++)
            {
                s[i][j] = ta%2;
                ta /= 2;
                sums += s[i][j];
            }
        }
        for (int i = 1;i <= n;i++)
        {
            int ta;
            scanf("%d",&ta);
            for (int j = 1;j <= 12;j++)
            {
                t[i][j] = ta%2;
                ta /= 2;
                sumt += t[i][j];
            }
        }
        xcnt = ycnt = n*12;
        for (int i = 0;i <= xcnt;i++)
        for (int j = 0;j <= ycnt;j++)
            map[i][j] = -1993070300;
        for (int i = 1;i <= n;i++)
        for (int j = 1;j <= 12;j++)
        for (int k = 1;k <= n;k++)
        for (int q = 1;q <= 12;q++)
       //if (!(i == k && j == q))
        if (s[i][j] == t[k][q])
            map[(i-1)*12+j-1][(k-1)*12+q-1] = -(abs(i-k)+abs(j-q));
        if (sums != sumt)
            printf("Impossible\n");
        else
            printf("%d\n",-KM()/2);
    }
}
