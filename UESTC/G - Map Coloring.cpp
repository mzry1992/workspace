#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int step[4][2] = {{-1,0},{0,1},{0,-1},{1,0}};
const int step2[8][2] = {{-1,0},{0,1},{0,-1},{1,0},{-1,-1},{-1,1},{1,-1},{1,1}};
int n,m;
char map[100][100];
char tmap[100][100];
int kmap[100][100];
bool visit[100][100];
int tot;
bool g[3000][3000];
int color[3000];
bool flag;

void DFS(int x,int y)
{
    if (x < 0)  return;
    if (y < 0)  return;
    if (x >= n) return;
    if (y >= m) return;
    if (tmap[x][y] != '.')  return;
    tmap[x][y] = '#';
    for (int i = 0;i < 8;i++)
        DFS(x+step2[i][0],y+step2[i][1]);
}

void DFS2(int x,int y,int now,char ch)
{
    if (x < 0)  return;
    if (y < 0)  return;
    if (x >= n) return;
    if (y >= m) return;
    if (map[x][y] != ch)  return;
    if (visit[x][y] == true)    return;
    visit[x][y] = true;
    kmap[x][y] = now;
    for (int i = 0;i < 4;i++)
        DFS2(x+step[i][0],y+step[i][1],now,ch);
}

bool adj[10];

void DFS3(int now,int tot,int col)
{
    if (now == tot+1)   flag = true;
    if (flag == true)   return;
    for (int i = 1;i <= col;i++)
        adj[i] = false;
    for (int i = 1;i <= tot;i++)
    if (g[now][i] == true)
        adj[color[i]] = true;
    for (int i = 1;i <= col;i++)
    if (adj[i] == false)
    {
        color[now] = i;
        DFS3(now+1,tot,col);
        color[now] = 0;
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&n,&m);
        for (int i = 0;i < n;i++)
            scanf("%s",map[i]);
        for (int c = 'A';c <= 'Z';c++)
        {
            for (int i = 0;i < n;i++)
            for (int j = 0;j < m;j++)
            if (map[i][j] == c)
                tmap[i][j] = c;
            else
                tmap[i][j] = '.';
            for (int i = 0;i < n;i++)
                DFS(i,0);
            for (int i = 0;i < n;i++)
                DFS(i,m-1);
            for (int i = 0;i < m;i++)
                DFS(0,i);
            for (int i = 0;i < m;i++)
                DFS(n-1,i);
            for (int i = 0;i < n;i++)
            for (int j = 0;j < m;j++)
            if (tmap[i][j] == '.')
                map[i][j] = c;
        }
        memset(visit,false,sizeof(visit));
        memset(kmap,0,sizeof(kmap));
        tot = 0;
        for (int i = 0;i < n;i++)
        for (int j = 0;j < m;j++)
        if (map[i][j] != '.' && visit[i][j] == false)
        {
            tot++;
            DFS2(i,j,tot,map[i][j]);
        }
        memset(g,false,sizeof(g));
        for (int i = 0;i < n;i++)
        for (int j = 0;j < m;j++)
        {
            for (int k = 0;k < 4;k++)
            {
                int tx,ty;
                tx = i+step[k][0];
                ty = j+step[k][1];
                if (tx >= 0 && tx < n && ty >= 0 && ty < m)
                if (map[tx][ty] != '.')
                {
                    if (kmap[i][j] != kmap[tx][ty])
                        g[kmap[i][j]][kmap[tx][ty]] = g[kmap[tx][ty]][kmap[i][j]] = true;
                }
            }
        }
        int col = 0;
        for (col = 0;col <= 4;col++)
        {
            memset(color,0,sizeof(color));
            flag = false;
            DFS3(1,tot,col);
            if (flag == true)   break;
        }
        printf("Case %d: %d\n",ft,col);
        for (int i = 0;i < n;i++)
            printf("%s\n",map[i]);
    }
}
