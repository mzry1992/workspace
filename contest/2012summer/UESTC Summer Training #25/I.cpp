#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct Edge
{
    int to,next;
    char val;
}edge[2][30000];
int L[2],head[2][2000],nxt[2000][26];
int n[2],s[2],m[2];

void addedge(int id,int u,int v,char val)
{
    edge[id][L[id]].to = v;
    edge[id][L[id]].val = val;
    edge[id][L[id]].next = head[id][u];
    head[id][u] = L[id]++;
}

bool visit[2000][2000];

bool BFS()
{
    queue<pair<int,int> > Q;
    memset(visit,false,sizeof(visit));
    visit[s[0]][s[1]] = true;
    Q.push(make_pair(s[0],s[1]));
    while (!Q.empty())
    {
        pair<int,int> now = Q.front();
        Q.pop();
        if (now.second == n[1]-1)
            return false;
        for (int i = head[0][now.first];i != -1;i = edge[0][i].next)
        {
            pair<int,int> nn = make_pair(edge[0][i].to,nxt[now.second][edge[0][i].val-'a']);
            if (visit[nn.first][nn.second] == false)
            {
                visit[nn.first][nn.second] = true;
                Q.push(nn);
            }
        }
    }
    return true;
}

int main()
{
	int totcas;
	scanf("%d",&totcas);
	while (totcas--)
	{
	    for (int i = 0;i < 2;i++)
	    {
	        scanf("%d%d%d",&n[i],&m[i],&s[i]);
	        s[i]--;
	        if (i == 1)
                n[i]++;
	        for (int j = 0;j < n[i];j++)
                head[i][j] = -1;
            L[i] = 0;
            for (int j = 0;j < m[i];j++)
            {
                int u,v;
                char val;
                scanf("%d %c%d",&u,&val,&v);
                while (u < 1 || u > n[i] || (v != -1 && (v < 1 || v > n[i])))
                    puts("fuck");
                u--,v--;
                if (v == -2)
                    v = n[i]-1;
                addedge(i,u,v,val);
            }
	    }

	    for (int i = 0;i < n[1];i++)
	    {
	        for (int j = 0;j < 26;j++)
                nxt[i][j] = i;
            for (int j = head[1][i];j != -1;j = edge[1][j].next)
                nxt[i][edge[1][j].val-'a'] = edge[1][j].to;
	    }
	    if (BFS())
            puts("satisfied");
        else
            puts("violated");
	}
	return 0;
}
