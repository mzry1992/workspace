#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const double pi = acos(-1.0);
int n,m;
char mp[110][110];
bool visit[210][210];
int way[210*210][2],tot;
double area,aaaa[210][210];

void DFS(int x,int y)
{
    if (x < 0 || x >= 2*n || y < 0 || y >= 2*m) return;
    if (visit[x][y] == true)    return;
    visit[x][y] = true;
    way[tot][0] = x;
    way[tot++][1] = y;
    if (mp[x/2][y/2] == '0')
    {
        if (x%2 == 0 && y%2 == 0)
        {
            area += pi/4;
            DFS(x,y-1);
            DFS(x-1,y);
        }
        else if (x%2 == 1 && y%2 == 1)
        {
            area += pi/4;
            DFS(x,y+1);
            DFS(x+1,y);
        }
        else if (x%2 == 0 && y%2 == 1)
        {
            area += 2-pi/4;
            DFS(x-1,y);
            DFS(x,y+1);
            DFS(x+1,y-1);
        }
        else
        {
            area += 2-pi/4;
            DFS(x+1,y);
            DFS(x,y-1);
            DFS(x-1,y+1);
        }
    }
    else
    {
        if (x%2 == 0 && y%2 == 1)
        {
            area += pi/4;
            DFS(x,y+1);
            DFS(x-1,y);
        }
        else if (x%2 == 1 && y%2 == 0)
        {
            area += pi/4;
            DFS(x,y-1);
            DFS(x+1,y);
        }
        else if (x%2 == 0 && y%2 == 0)
        {
            area += 2-pi/4;
            DFS(x-1,y);
            DFS(x,y-1);
            DFS(x+1,y+1);
        }
        else
        {
            area += 2-pi/4;
            DFS(x+1,y);
            DFS(x,y+1);
            DFS(x-1,y-1);
        }
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
            scanf("%s",mp[i]);
        memset(visit,false,sizeof(visit));
        for (int i = 0;i < 2*n;i++)
            for (int j = 0;j < 2*m;j++)
                if (visit[i][j] == false)
                {
                    tot = 0;
                    area = 0;
                    DFS(i,j);
                    for (int k = 0;k < tot;k++)
                        aaaa[way[k][0]][way[k][1]] = area;
                    /*printf("area = %.4f ,",area);
                    for (int k = 0;k < tot;k++)
                        printf("[%d,%d] ",way[k][0],way[k][1]);
                    printf("\n");*/
                }
        int q;
        scanf("%d",&q);
        printf("Case %d:\n",ft);
        for (int i = 0;i < q;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            double res;
            if (x%2 == 0 && y%2 == 1)
                res = 0;
            else if (x%2 == 1 && y%2 == 0)
                res = 0;
            else if (x%2 == 1 && y%2 == 1)
            {
                if (mp[x/2][y/2] == '0')
                    y--;
                res = aaaa[x][y];
            }
            else
            {
                if (x == 2*n)   x--;
                if (y == 2*m)   y--;
                res = aaaa[x][y];
            }
            printf("%.4f\n",res);
        }
    }
	return 0;
}
