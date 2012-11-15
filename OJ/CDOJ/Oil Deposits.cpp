#include <iostream>
#include <cstdio>
#include <cstring>
#include <deque>
using namespace std;

int n,m;
const int step[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
char map[120][120];

void DFS(int x,int y)
{
    if (x < 0)  return; if (x >= n) return;
    if (y < 0)  return; if (y >= m) return;
    if (map[x][y] == '*')   return;
    map[x][y] = '*';
    for (int i = 0;i < 8;i++)
        DFS(x+step[i][0],y+step[i][1]);
}

int main()
{
    while (true)
    {
        scanf("%d%d",&n,&m);
        if (n == 0 && m == 0)   break;
        for (int i = 0;i < n;i++)
            scanf("%s",map[i]);
        int res = 0;
        for (int i = 0;i < n;i++)
        for (int j = 0;j < m;j++)
        if (map[i][j] == '@')
        {
            res++;
            DFS(i,j);
        }
        printf("%d\n",res);
    }
}
