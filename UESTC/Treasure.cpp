#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m,res;
char map[1200][1200];
bool visit[1200][1200];
const int step[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};

void DFS(int x,int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m)  return;
    if (map[x][y] == '#')   return;
    if (visit[x][y] == true)    return;
    if (map[x][y] == '*')   res++;
    visit[x][y] = true;
    for (int i = 0;i < 4;i++)   DFS(x+step[i][0],y+step[i][1]);
}

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        for (int i = 0;i < n;i++)   scanf("%s",map[i]);
        int sx,sy;
        for (int i = 0;i < n;i++)
            for (int j = 0;j < m;j++)
                if (map[i][j] == 'X')
                {
                    sx = i;
                    sy = j;
                }
        memset(visit,false,sizeof(visit));
        res = 0;
        DFS(sx,sy);
        printf("%d\n",res);
    }
}
