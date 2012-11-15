#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int h,w,d;
int map[600][600];
int tot;
bool flag;
int ttot;
const int step[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};
bool use[600][600];
bool visit[600][600];
struct point
{
    int h,x,y;
}p[260000];

void DFS(int x,int y,int top)
{
    if (flag == false)
        return;
    if (x < 1) return;
    if (y < 1) return;
    if (x > h) return;
    if (y > w) return;
    if (visit[x][y] == true)    return;
    visit[x][y] = true;
    if (map[x][y] <= top-d) return;
    if (map[x][y] > top)
    {
        flag = false;
        return;
    }
    if (map[x][y] == top)   ttot++;
    for (int i = 0;i < 4;i++)
        DFS(x+step[i][0],y+step[i][1],top);
}

bool cmp(point a,point b)
{
    return a.h > b.h;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d%d",&h,&w,&d);
        int totp = 0;
        for (int i = 1;i <= h;i++)
            for (int j = 1;j <= w;j++)
            {
                scanf("%d",&map[i][j]);
                totp++;
                p[totp].x = i;
                p[totp].y = j;
                p[totp].h = map[i][j];
            }
        sort(p+1,p+totp+1,cmp);
        tot = 0;
        memset(use,false,sizeof(use));
        for (int k = 1;k <= totp;k++)
        {
            int i = p[k].x;
            int j = p[k].y;
            if (use[i][j] == false)
            {
                ttot = 0;
                flag = true;
                memset(visit,false,sizeof(visit));
                DFS(i,j,map[i][j]);
                if (flag == true)
                {
                    tot += ttot;
                    memset(visit,false,sizeof(visit));
                    BFS(i,j,map[i][j]);
                }
            }
        }
        printf("%d\n",tot);
    }
}
