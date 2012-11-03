/*
ID: muziriy3
PROG: castle
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m;
int map[100][100];
bool visit[100][100];
int totnum,maxsize,thissize;
const int step[5][2] = {{0,0},{0,-1},{-1,0},{0,1},{1,0}};
const int cc[4] = {1,4,2,3};
const int rcc[4] = {3,2,4,1};
const char ff[4] = {'W','N','E','S'};

void DFS(int x,int y)
{
    if (x == 0) return;
    if (x == n+1)   return;
    if (y == 0) return;
    if (y == m+1)   return;
    if (visit[x][y] == true)    return;
    thissize++;
    visit[x][y] = true;
    for (int i = 1;i <= 4;i++)
    if ((((map[x][y])>>(i-1))&1) == 0)
    {
        DFS(x+step[i][0],y+step[i][1]);
    }
}

void solve()
{
    memset(visit,false,sizeof(visit));
    totnum = maxsize = 0;
    for (int i = 1;i <= n;i++)
    for (int j = 1;j <= m;j++)
    if (visit[i][j] == false)
    {
        thissize = 0;
        totnum++;
        DFS(i,j);
        if (thissize > maxsize)
            maxsize = thissize;
    }
}

int main()
{
    freopen("castle.in","r",stdin);
    freopen("castle.out","w",stdout);
    scanf("%d%d",&m,&n);
    for (int i = 1;i <= n;i++)
    for (int j = 1;j <= m;j++)
        scanf("%d",&map[i][j]);
    solve();
    printf("%d\n%d\n",totnum,maxsize);
    int maxres,maxx,maxy,maxf;
    maxres = 0;
    for (int j = 1;j <= m;j++)
    for (int i = n;i >= 1;i--)
    for (int k = 2;k <= 3;k++)
    if ((((map[i][j])>>(cc[k]-1))&1) == 1)
    {
        if (i+step[cc[k]][0] == 0)  continue;
        if (i+step[cc[k]][0] == n+1)  continue;
        if (j+step[cc[k]][1] == 0)  continue;
        if (j+step[cc[k]][1] == m+1)  continue;
        int temp1 = map[i][j];
        int temp2 = map[i+step[cc[k]][0]][j+step[cc[k]][1]];
        map[i][j] = (map[i][j])^(1<<(cc[k]-1));
        map[i+step[cc[k]][0]][j+step[cc[k]][1]] = (map[i+step[cc[k]][0]][j+step[cc[k]][1]])^(1<<(rcc[k]-1));
        solve();
        if (maxsize > maxres)
        {
            maxres = maxsize;
            maxx = i;
            maxy = j;
            maxf = cc[k];
        }
        map[i][j] = temp1;
        map[i+step[cc[k]][0]][j+step[cc[k]][1]] = temp2;
    }
    printf("%d\n%d %d %c\n",maxres,maxx,maxy,ff[maxf-1]);
}
