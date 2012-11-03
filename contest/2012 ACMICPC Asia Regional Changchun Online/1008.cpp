#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int inf = 0x3fffffff;
struct Edge
{
    int to,next;
}edge[10000];
int head[10000],L;
int n,l[10000],r[10000];

void addedge(int u,int v)
{
    edge[L].to = v;
    edge[L].next = head[u];
    head[u] = L++;
}

bool merge(int pos,int s,int t)
{
    l[pos]=max(l[pos],s);
    r[pos]=min(r[pos],t);
    return l[pos]<=r[pos];
}

bool DFS(int now)
{
    int s=1;
    for (int i = head[now];i != -1;i = edge[i].next)
    {
        if (!DFS(edge[i].to))
            return 0;
        s+=l[edge[i].to];
    }
    //printf("%d %d\n",now,s);
    return merge(now,s,inf);
}

int main()
{
	while (scanf("%d",&n) != EOF)
	{
	    L = 0;
	    for (int i = 0;i < n;i++)
	    {
	        l[i] = 1;
	        r[i] = inf;
            head[i] = -1;
	    }
	    for (int i = 1;i < n;i++)
	    {
	        int fa;
	        scanf("%d",&fa);
	        fa--;
	        addedge(fa,i);
	    }
	    int m;
	    scanf("%d",&m);
	    bool flag = true;
	    for (int i = 0;i < m;i++)
	    {
            int x,w;
            char y;
            scanf("%d %c%d",&x,&y,&w);
            x--;
            if (y == '=')
                flag &= merge(x,w,w);
            else if (y == '<')
                flag &= merge(x,1,w-1);
            else
                flag &= merge(x,w+1,inf);
	    }
	    if (flag && DFS(0))
            puts("True");
        else
            puts("Lie");
	}
	return 0;
}
