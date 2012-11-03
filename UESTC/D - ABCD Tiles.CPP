#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

int n,m;
char map[20][20];
const int step[5][2] = {{0,0},{-1,0},{1,0},{0,1},{0,-1}};
const int near[16][2] = {{-2,-1},{-2,0},{-2,1},{-1,-2},{-1,-1},{-1,1},{-1,2},{0,-2},{0,2},{1,-2},{1,-1},{1,1},{1,2},{2,-1},{2,0},{2,1}};
bool flag;
const string color = "BCD";

bool check(int x,int y,char c)
{
    if (x < 0)  return true;
    if (y < 0)  return true;
    if (x >= n) return true;
    if (y >= n) return true;
    if (map[x][y] == 'A')   return true;
    if (map[x][y] == '.')   return true;
    if (map[x][y] == c) return false;
    else return true;
}

bool can(int x,int y,int col)
{
    if (x <= 0) return false;
    if (y <= 0) return false;
    if (x >= n-1) return false;
    if (y >= n-1) return false;
    for (int k = 0;k < 5;k++)
    if (map[x+step[k][0]][y+step[k][1]] != '.') return false;
    char c = color[col];
    for (int k = 0;k < 16;k++)
    if (check(x+near[k][0],y+near[k][1],c) == false)    return false;
    return true;
}

void DFS(int x,int y)
{
    if (flag == true)   return;
    if (x == n)
    {
        printf("\n");
        for (int i = 0;i < n;i++)
            puts(map[i]);
        flag = true;
        return;
    }
    int tx,ty;
    tx = x;
    ty = y;
    ty++;
    if (ty == n)
    {
        tx++;
        ty = 0;
    }
    if (map[x][y] == '.')
    {
        for (int col = 0;col < 3;col++)
        if (can(x+1,y,col) == true)
        {
            for (int i = 0;i < 5;i++)
                map[x+1+step[i][0]][y+step[i][1]] = color[col];
            DFS(tx,ty);
            for (int i = 0;i < 5;i++)
                map[x+1+step[i][0]][y+step[i][1]] = '.';
        }
    }
    else
        DFS(tx,ty);
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int ft = 1;ft <= T;ft++)
    {
        scanf("%d",&n);
        for (int i = 0;i < n;i++)
            scanf("%s",map[i]);
        int totb;
        totb = 0;
        for (int i = 0;i < n;i++)
        for (int j = 0;j < n;j++)
        if (map[i][j] == '.')
            totb++;
        printf("Case %d:",ft);
        if (totb%5 != 0)
        {
            printf(" Not Possible!\n");
            continue;
        }
        m = totb/5;
        flag = false;
        DFS(0,0);
        if (flag == false)
        {
            printf(" Not Possible!\n");
            continue;
        }
    }
}
