#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int step[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
bool can[256][3][3];
char g[3][3];

void DFS(int sta,int x,int y)
{
    can[sta][x][y] = true;
    for (int i = 0;i < 4;i++)
    {
        int tx = x+step[i][0];
        int ty = y+step[i][1];
        if (tx < 0 || tx > 2 || ty < 0 || ty > 2)   continue;
        if (g[tx][ty] == '#')
            can[sta][tx][ty] = true;
        else
        {
            if (can[sta][tx][ty] == false)
                DFS(sta,tx,ty);
        }
    }
}

int arr[2000][10],arrlen[2000],arrtot;
int tmp[10];

void DFS2(int ful,int sta,int tot)
{
    if (sta == 0)
    {
        int id = arrtot;
        arrlen[id] = tot;
        for (int i = 0;i < tot;i++)
            arr[id][i] = tmp[i];
        arrtot++;
        return;
    }
    for (int i = 0;i < 3;i++)
        for (int j = 0;j < 3;j++)
            if (((sta>>(i*3+j-1))&1) == 1)
                if (can[sta][i][j] == true)
                {
                    tmp[tot] = i*3+j-1;
                    DFS2(ful,sta-(1<<(i*3+j-1)),tot+1);
                }
}

bool flag[256];
int res[256][256];
int tid[8];

void Gao()
{
    memset(can,false,sizeof(can));
    for (int i = 0;i < (1<<8);i++)
    {
        g[0][0] = '.';
        for (int x = 0;x < 3;x++)
            for (int y = 0;y < 3;y++)
                if (x != 0 || y != 0)
                {
                    if (((i>>(x*3+y-1))&1) == 1)
                        g[x][y] = '#';
                    else
                        g[x][y] = '.';
                }
        DFS(i,0,0);
    }

    memset(res,0,sizeof(res));

    for (int i = 0;i < (1<<8);i++)
    {
        arrtot = 0;
        DFS2(i,i,0);
        int ttid = 0;
        for (int x = 0;x < 3;x++)
            for (int y = 0;y < 3;y++)
                if (x != 0 || y != 0)
                    if (((i>>(x*3+y-1))&1) == 1)
                        tid[x*3+y-1] = ttid++;
        int len = arrlen[0];
        for (int j = 0;j < (1<<len);j++)
        {
            memset(flag,false,sizeof(flag));
            for (int k = 0;k < arrtot;k++)
            {
                int v = 0;
                for (int q = 0;q < len;q++)
                    if (((j>>tid[arr[k][q]])&1) == 1)
                        v = (v<<1)|1;
                    else
                        v = v<<1;
                if (flag[v] == false)
                    res[i][j]++;
                flag[v] = true;
            }
            /*if (j == 0 || j == (1<<len)-1)
                printf("%d %d %d\n",i,j,res[i][j]);*/
        }
    }

    //printf("%d\n",res[255][254]);
    //printf("%d\n",arrtot[255]);
}

char mp[3][4];

int main()
{
    Gao();
    int cas = 0;
    while (scanf("%s",mp[0]) != EOF)
    {
        for (int i = 1;i < 3;i++)
            scanf("%s",mp[i]);
        int sta = 0;
        for (int x = 2;x >= 0;x--)
            for (int y = 2;y >= 0;y--)
                if (x != 0 || y != 0)
                {
                    if (mp[x][y] == '*')
                        sta = sta<<1;
                    else
                        sta = (sta<<1)|1;
                }
        int col = 0;
        for (int x = 2;x >= 0;x--)
            for (int y = 2;y >= 0;y--)
                if (x != 0 || y != 0)
                {
                    if (mp[x][y] == 'G')
                        col = col<<1;
                    else if (mp[x][y] == 'B')
                        col = (col<<1)|1;
                }
        printf("Case %d: %d\n",++cas,res[sta][col]);
    }
	return 0;
}
