#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

char s[1000100],mp[1100][1100];
int n,m,l,sx,sy,ex,ey,next[1000100][2],pos[4],dir[1000100],dist[1100][1100][4];
const int step[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
/*
 0
3 1
 2
*/

vector<pair<int,int> > Q[1000100];

bool BFS()
{
    for (int i = 0;i <= l;i++)
        Q[i].clear();
    for (int i = 0;i < n;i++)
        for (int j = 0;j < m;j++)
            for (int k = 0;k < 4;k++)
                dist[i][j][k] = 2*l;
    Q[0].push_back(make_pair(sx,sy));
    dist[sx][sy][0] = 0;
    for (int dis = 0;dis <= l;dis++)
        for (int pi = 0;pi < Q[dis].size();pi++)
        {
            pair<int,int> now = Q[dis][pi];

            if (now.first == ex && now.second == ey)    return true;

            for (int i = 0;i < 2;i++)
                if (next[dis][i] != -1)
                {
                    if (dist[now.first][now.second][dir[next[dis][i]]] == 2*l)
                    {
                        dist[now.first][now.second][dir[next[dis][i]]] = next[dis][i];
                        Q[next[dis][i]].push_back(now);
                    }
                }

            int v = dir[dis];
            pair<int,int> nxt = make_pair(now.first+step[v][0],now.second+step[v][1]);
            if (nxt.first < 0 || nxt.first >= n || nxt.second < 0 || nxt.second >= m || mp[nxt.first][nxt.second] == '#')
                continue;
            if (dist[nxt.first][nxt.second][v] == 2*l)
            {
                dist[nxt.first][nxt.second][v] = dis;
                Q[dis].push_back(nxt);
            }
        }
    return false;
}

void calcnext()
{
    dir[0] = 0;
    for (int i = 1;i <= l;i++)
        if (s[i-1] == 'L')
            dir[i] = (dir[i-1]+3)%4;
        else
            dir[i] = (dir[i-1]+1)%4;
    for (int i = 0;i < 4;i++)
        pos[i] = -1;
    pos[dir[l]] = l;
    for (int i = l-1;i >= 0;i--)
    {
        pos[dir[i]] = i;
        next[i][0] = pos[(dir[i]+3)%4];
        next[i][1] = pos[(dir[i]+1)%4];
    }
}

int main()
{
    freopen("1006.in","r",stdin);
    freopen("1006_2.out","w",stdout);
    while (scanf("%d%d%d",&n,&m,&l) != EOF)
    {
        scanf("%s",s);
        calcnext();
        for (int i = 0; i < n; i++)
        {
            scanf("%s",mp[i]);
            for (int j = 0; j < m; j++)
                if (mp[i][j] == 'S')
                    sx = i,sy = j;
                else if (mp[i][j] == 'E')
                    ex = i,ey = j;
        }
        if (BFS())
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}
