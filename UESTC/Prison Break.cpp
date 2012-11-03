#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m,N;
char mp[15][15];
int id[15][15];

struct Edge
{
    int to,next,cost;
};

int typ[16],head[16],L,s;
int pos[16][2];
Edge edge[16*16];
//typ : 0-F 1-G 2-Y
const int step[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};

int Q[15*15][2],dis[15*15];
bool visit[15][15];

void addedge(int u,int v,int cost)
{
    edge[L].to = v;
    edge[L].cost = cost;
    edge[L].next = head[u];
    head[u] = L++;
}

void BFS(int s)
{
    int head,tail,nowx,nowy,nowstep,tx,ty;
    head = tail = 0;
    Q[tail][0] = pos[s][0];
    Q[tail][1] = pos[s][1];
    dis[tail++] = 0;
    memset(visit,false,sizeof(visit));
    visit[pos[s][0]][pos[s][1]] = true;
    while (head < tail)
    {
        nowx = Q[head][0];
        nowy = Q[head][1];
        nowstep = dis[head++];
        if (id[nowx][nowy] != s)
            if (mp[nowx][nowy] != 'S')
                addedge(s,id[nowx][nowy],nowstep);
        for (int i = 0;i < 4;i++)
        {
            tx = nowx+step[i][0];
            ty = nowy+step[i][1];
            if (tx < 0 || tx >= n || ty < 0 || ty >= m) continue;
            if (mp[tx][ty] == 'D')  continue;
            if (visit[tx][ty] == true)  continue;
            visit[tx][ty] = true;
            Q[tail][0] = tx;
            Q[tail][1] = ty;
            dis[tail++] = nowstep+1;
        }
    }
}

int main()
{
    while (true)
    {
        scanf("%d%d",&n,&m);
        if (n == 0 && m == 0)   break;
        for (int i = 0;i < n;i++)
            scanf("%s",mp[i]);
        L = 0;
        for (int i = 0;i < n;i++)
            for (int j = 0;j < m;j++)
                if (mp[i][j] != 'S' && mp[i][j] != 'D')
                {
                    id[i][j] = L;
                    pos[L][0] = i;
                    pos[L][1] = j;
                    if (mp[i][j] == 'F')
                    {
                        s = id[i][j];
                        typ[L] = 0;
                        mp[i][j] = 'S';
                    }
                    else if (mp[i][j] == 'G')
                        typ[L] = 1;
                    else
                        typ[L] = 2;
                    L++;
                }
        N = L;
        L = 0;
        for (int i = 0;i < N;i++)
        {
            head[i] = -1;
            BFS(i);
        }
        for (int i = 0;i < N;i++)
            cout << i << ' ' << pos[i][0] << ' ' << pos[i][1] << ' ' << typ[i] << endl;
        for (int i = 0;i < N;i++)
        {
            cout << i << " : " << endl;
            for (int j = head[i];j != -1;j = edge[j].next)
                cout << "\t--> " << edge[j].to << ' ' << edge[j].cost << endl;
            cout << endl;
        }
    }
    return 0;
}
