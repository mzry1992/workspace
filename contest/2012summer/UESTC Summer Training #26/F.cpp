#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int id[10][10],cnt[25],cid;
bool mp[10][10];
int n;
long long m;

void DFS(int x,int y,long long m)
{
    if (y == n)
    {
        x++;
        y = 0;
    }
    if (x == n)
        return;
    long long rest = 1;
    memset(cnt,0,sizeof(cnt));
    for (int i = 0;i < x;i++)
        for (int j = 0;j < n;j++)
            if (mp[i][j] == 1)
                cnt[id[i][j]] = -1;
            else if (cnt[id[i][j]] != -1)
                cnt[id[i][j]]++;
    mp[x][y] = 0;
    for (int j = 0;j <= y;j++)
        if (mp[x][j] == 1)
            cnt[id[x][j]] = -1;
        else if (cnt[id[x][j]] != -1)
            cnt[id[x][j]]++;
    if (cnt[id[x][y]] == -1)
        DFS(x,y+1,m);
    else
    {
        for (int i = 0;i < cid;i++)
            if (cnt[i] != -1)
                rest *= 4-cnt[i];
        if (rest < m)
        {
            mp[x][y] = 1;
            m -= rest;
        }
        DFS(x,y+1,m);
    }
}

int main()
{
    scanf("%d%I64d",&n,&m);
    cid = 0;
    for (int i = 0;i < n/2;i++)
        for (int j = 0;j < n/2;j++)
        {
            int x = i,y = j;
            for (int k = 0;k < 4;k++)
            {
                id[x][y] = cid;
                int tx = y;
                int ty = n-1-x;
                x = tx,y = ty;
            }
            cid++;
        }
    DFS(0,0,m);
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++)
            printf("%d",mp[i][j]);
        printf("\n");
    }
	return 0;
}
