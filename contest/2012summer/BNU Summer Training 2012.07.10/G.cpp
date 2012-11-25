#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct Edge
{
    int to,next;
};

Edge edge[1000000],redge[1000000];
int head[1000],L,rhead[1000],rL;
int n,id[1000];
bool visit[1000];

void addedge(int u,int v)
{
    //printf("addedge %d %d\n",u,v);
    edge[L].to = v;
    edge[L].next = head[u];
    head[u] = L++;
}

void raddedge(int u,int v)
{
    //printf("raddedge %d %d\n",u,v);
    redge[rL].to = v;
    redge[rL].next = rhead[u];
    rhead[u] = rL++;
}

void BFS()
{
    queue<int> Q;
    memset(visit,false,sizeof(visit));
    Q.push(0);
    visit[0] = true;
    while (!Q.empty())
    {
        int now = Q.front();
        Q.pop();
        for (int i = head[now];i != -1;i = edge[i].next)
            if (visit[edge[i].to] == false)
            {
                visit[edge[i].to] = true;
                Q.push(edge[i].to);
            }
    }
}

void rBFS()
{
    queue<int> Q;
    memset(visit,false,sizeof(visit));
    Q.push(0);
    visit[0] = true;
    while (!Q.empty())
    {
        int now = Q.front();
        Q.pop();
        for (int i = rhead[now];i != -1;i = redge[i].next)
            if (visit[redge[i].to] == false)
            {
                visit[redge[i].to] = true;
                Q.push(redge[i].to);
            }
    }
}

int main()
{
	while (scanf("%d",&n) != EOF)
	{
	    for (int i = 0;i < 1000;i++)
            head[i] = -1;
        L = 0;
	    for (int i = 0;i < n;i++)
	    {
	        int cnt;
	        scanf("%d%d",&id[i],&cnt);
	        for (int j = 0;j < cnt;j++)
	        {
	            int tid;
	            scanf("%d",&tid);
                addedge(tid,id[i]);
	        }
	    }
	    BFS();
	    bool flag = false;
	    for (int i = 0;i < n;i++)
            if (visit[id[i]] == false)
            {
                printf("TRAPPED %d\n",id[i]);
                flag = true;
            }
	    for (int i = 0;i < 1000;i++)
            rhead[i] = -1;
        rL = 0;
        for (int i = 0;i < 1000;i++)
            for (int j = head[i];j != -1;j = edge[j].next)
                raddedge(edge[j].to,i);
        rBFS();
	    for (int i = 0;i < n;i++)
            if (visit[id[i]] == false)
            {
                printf("UNREACHABLE %d\n",id[i]);
                flag = true;
            }
        if (flag == false)
            puts("NO PROBLEMS");
	}
	return 0;
}
