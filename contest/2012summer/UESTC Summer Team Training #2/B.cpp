#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int step[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
const int pos[8][2] = {{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2}};
char mp[3][4],g[3][3];
int a[10];
bool res[1<<8],can[1<<8][3][3];

void DFS(int sta,int x,int y)
{
    can[sta][x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int tx = x+step[i][0];
        int ty = y+step[i][1];
        if (tx < 0 || tx > 2 || ty < 0 || ty > 2)   continue;
        if (g[tx][ty] == '#')
        {
            can[sta][tx][ty] = true;
            continue;
        }
        if (can[sta][tx][ty] == false)
            DFS(sta,tx,ty);
    }
}

int p[10],go[1<<8][2000][9],totgo[1<<8],tgo[1<<8];

void Gao(int ful,int sta,int tot)
{
    if (sta == 0)
    {
        for (int i = 0; i < tot; i++)
            go[ful][totgo[ful]][i] = p[i];
        tgo[ful] = tot;
        totgo[ful]++;
        return;
    }
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (i != 0 || j != 0)
                if (((sta>>(i*3+j-1))&1) == 1)
                    if (can[sta][i][j] == true)
                    {
                        p[tot] = i*3+j-1;
                        Gao(ful,sta-(1<<(i*3+j-1)),tot+1);
                    }
}

int fuck[1<<8][1<<8];

int main()
{
    memset(can,false,sizeof(can));
    for (int sta = 0; sta < (1<<8); sta++)
    {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if ((i == 0 && j == 0) ||
                        (((sta>>(i*3+j-1))&1) == 0))
                    g[i][j] = '.';
                else
                    g[i][j] = '#';
        DFS(sta,0,0);
    }
    for (int i = 0; i < (1<<8); i++)
    {
        totgo[i] = 0;
        Gao(i,i,0);
        //cout << i << ' ' << totgo[i] << ' ' << tgo[i] << endl;
    }
    for (int emp = 0; emp < (1<<8); emp++)
    {
        //cout << tgo[emp] << endl;
        for (int sta = 0; sta < (1<<tgo[emp]); sta++)
        {
            memset(res,false,sizeof(res));
            for (int i = 0; i < totgo[emp]; i++)
            {
                int v = 0;
                for (int j = 0; j < tgo[emp]; j++)
                {
                    int pp = go[emp][i][j];
                    if (((sta>>pp)&1) == 1)
                        v = (v<<1)|1;
                    else
                        v = v<<1;
                }
                //if (emp == 255)
                //cout << v << endl;
                res[v] = true;
            }
            int cnt = 0;
            for (int i = 0; i < (1<<8); i++)
                if (res[i] == true)
                    cnt++;
            fuck[emp][sta] = cnt;
            //if (emp == 255)
            //cout << emp << ' ' << sta << ' ' << fuck[emp][sta] << endl;
        }
    }
    int cas = 0;
    while (scanf("%s",mp[0]) != EOF)
    {
        for (int i = 1; i < 3; i++)
            scanf("%s",mp[i]);
        int emp = 0;
        for (int i = 0;i < 3;i++)
            for (int j = 0;j < 3;j++)
                if (i != 0 || j != 0)
                    if (mp[i][j] == '*')
                        emp = emp<<1;
                    else
                        emp = (emp<<1)|1;
        int v = 0;
        for (int i = 2; i >= 0; i--)
            for (int j = 2; j >= 0; j--)
                if (i != 0 || j != 0)
                {
                    if (mp[i][j] == 'B')
                        v = (v<<1)|1;
                    else if (mp[i][j] == 'G')
                        v = v<<1;
                }
        printf("Case %d: %d\n",++cas,fuck[emp][v]);
    }
    return 0;
}
