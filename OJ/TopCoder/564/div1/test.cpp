#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int step[8][2] = {{-2,-1},{-2,1},{2,-1},{2,1},{1,-2},{1,2},{-1,-2},{-1,2}};
bool visit[5000][5000];
int w,h;
int tot;

void DFS(int x,int y)
{
    if (x < 0 || x >= w || y < 0 || y >= h) return;
    if (visit[x][y] == true)    return;
    visit[x][y] = true;
    tot++;
    for (int i = 0;i < 8;i++)
        DFS(x+step[i][0],y+step[i][1]);
}

int calc(int w,int h)
{
    if (w > h)  swap(w,h);
    if (w == 1)
        return 1;
    if (w == 2)
        return (h+1)/2;
    if (w == 3 && h == 3)   return 8;
    return h*w;
}

int main()
{
    for (w = 1;w <= 500;w++)
    {
        for (h = 1;h <= 500;h++)
        {
            int res = 0;
            memset(visit,false,sizeof(visit));
            for (int i = 0;i < w;i++)
                for (int j = 0;j < h;j++)
                {
                    tot = 0;
                    DFS(i,j);
                    res = max(res,tot);
                }
            if (res != calc(w,h))
                puts("fuck");
        }
    }
    return 0;
}

