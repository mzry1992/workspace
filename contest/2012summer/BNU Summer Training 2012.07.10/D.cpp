#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int f,s,g,u,d,dis[1000001];

int BFS()
{
    queue<int> Q;
    memset(dis,-1,sizeof(dis));
    dis[s] = 0;
    Q.push(s);
    while (!Q.empty())
    {
        int now = Q.front();
        Q.pop();
        if (now == g)
            return dis[g];
        if (now-d >= 1 && dis[now-d] == -1)
        {
            dis[now-d] = dis[now]+1;
            Q.push(now-d);
        }
        if (now+u <= f && dis[now+u] == -1)
        {
            dis[now+u] = dis[now]+1;
            Q.push(now+u);
        }
    }
    return -1;
}

int main()
{
    while (scanf("%d%d%d%d%d",&f,&s,&g,&u,&d) != EOF)
    {
        int res = BFS();
        if (res == -1)
            puts("use the stairs");
        else
            printf("%d\n",res);
    }
	return 0;
}
