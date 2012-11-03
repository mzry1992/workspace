#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 600;
int b[maxn][maxn];
int n;

struct Edge
{
	int to,next;
}edge[1000000];
int head[2000],L;

void addedge(int ui,int uv,int vi,int vv)
{
	int u = ui*2+uv;
	int v = vi*2+vv;

	edge[L].to = v;
	edge[L].next = head[u];
	head[u] = L++;
}

void init()
{
	for (int i = 0;i < n*2;i++)
		head[i] = -1;
	L = 0;
}

int dfsnum[2000];
int low[2000];
int stack[2000];
int top,ans,an;
int be[2000];
int flag[2000];
void dfs(int x)
{
	dfsnum[x] = low[x] = ans++;
	stack[++top] = x;
	flag[x] = 1;
	for (int i = head[x];i != -1;i = edge[i].next)
	{
		int y = edge[i].to;
		if (dfsnum[y] == -1)
		{
			dfs(y);
			low[x] = min(low[x],low[y]);
		}
		else if (flag[y] == 1)
			low[x] = min(low[x],dfsnum[y]);
	}
	if (dfsnum[x] == low[x])
	{
		while (stack[top] != x)
		{
			flag[stack[top]] = 0;
			be[stack[top]] = an;
			top--;
		}
		flag[x] = 0;
		be[x] = an++;
		top--;
	}
}

bool SC()
{
	memset(dfsnum,-1,sizeof(dfsnum));
	memset(flag,0,sizeof(flag));
	top = an = ans = 0;
	for (int i = 0;i < n*2;i++)
		if (dfsnum[i] == -1)
			dfs(i);
	for (int i = 0;i < n;i++)
		if (be[i*2] == be[i*2+1])
			return false;
	return true;
}

bool check()
{
	for (int k = 0; k < 31; k++)
	{
		init();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
            {
            	int bb = (b[i][j]>>k)&1;
                if (i == j)
                {
                    if (bb != 0)	return false;
                }
                else if (i%2 == 1 && j%2 == 1)
                {
                    //b[i][j] = a[i] | a[j];
                    if (bb == 0)
                    {
                    	addedge(i,1,i,0);
                    	addedge(j,1,j,0);
                    }
                    else
                    {
                    	addedge(i,0,j,1);
                    	addedge(j,0,i,1);
                    }
                }
                else if (i%2 == 0 && j%2 == 0)
                {
                    //b[i][j] = a[i] & a[j];
                    if (bb == 0)
                    {
                    	addedge(i,1,j,0);
                    	addedge(j,1,i,0);
                    }
                    else
                    {
                    	addedge(i,0,i,1);
                    	addedge(j,0,j,1);
                    }
                }
                else
                {
                    //b[i][j] = a[i] ^ a[j];
					if (bb == 0)
					{
						addedge(i,1,j,1);
						addedge(j,1,i,1);
						addedge(i,0,j,0);
						addedge(j,0,i,0);
					}
					else
					{
						addedge(i,1,j,0);
						addedge(j,1,i,0);
						addedge(i,0,j,1);
						addedge(j,0,i,1);
					}
                }
            }
		if (SC() == false)
			return false;
	}
	return true;
}

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                scanf("%d",&b[i][j]);

        if (check())
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}

