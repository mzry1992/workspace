#include <iostream>
#include <cstdio>
#include <cstring>
#include <deque>
#include <map>
using namespace std;

char table[30],g[50000];
int n,m,sx,sy,ex,ey,nx,ny;
struct node
{
    int max,x,y,step;
}now;
bool visit[50000][30];
deque<node> Q;
map<char,int> id;
const int step[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

node getnode(int max,int x,int y,int step)
{
    node res;
    res.max = max;
    res.x = x;
    res.y = y;
    res.step = step;
    return res;
}

int BFS()
{
    memset(visit,false,sizeof(visit));
    Q.clear();
    visit[sx*m+sy][0] = true;
    Q.push_back(getnode(0,sx,sy,0));
    while (!Q.empty())
    {
        now = Q.front();
        Q.pop_front();
        if (now.x == ex && now.y == ey) return now.step;
        for (int i = 0;i < 4;i++)
        {
            nx = now.x+step[i][0];
            ny = now.y+step[i][1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                if (g[nx*m+ny] == 'x')    continue;
                if (g[nx*m+ny] >= 'A' && g[nx*m+ny] <= 'Z')
                {
                    if (id[g[nx*m+ny]] <= now.max)    continue;
                    if (visit[nx*m+ny][id[g[nx*m+ny]]] == false)
                    {
                        visit[nx*m+ny][id[g[nx*m+ny]]] = true;
                        Q.push_back(getnode(id[g[nx*m+ny]],nx,ny,now.step+1));
                    }
                }
                if (g[nx*m+ny] == 'o')
                    if (visit[nx*m+ny][now.max] == false)
                    {
                        visit[nx*m+ny][now.max] = true;
                        Q.push_back(getnode(now.max,nx,ny,now.step+1));
                    }
            }
        }
    }
    return -1;
}

int main()
{
    while (scanf("%s",table) != EOF)
    {
        id.clear();
        for (int i = 0;i < strlen(table);i++)
            id[table[i]] = i+1;
        scanf("%d%d",&m,&n);
        for (int i = 0;i < n;i++)
            for (int j = 0;j < m;j++)
                scanf(" %c",&g[i*m+j]);
        scanf("%d%d",&sy,&sx);
        scanf("%d%d",&ey,&ex);
        int res = BFS();
        if (res == -1)  printf("IMPOSSIBLE\n");
        else printf("%d\n",res);
    }
}
