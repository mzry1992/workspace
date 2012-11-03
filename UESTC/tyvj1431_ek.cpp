#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAX=200000000;
int n,m;
int map[205][205],prev[205],visit[205],queue[3000],f[205];
int BFS()
{
	memset(visit,false,sizeof(visit));
	memset(prev,-1,sizeof(prev));
	for (int i=1;i<=m;i++)
		f[i]=MAX;
	int head=0,tail=1;
	queue[head]=1;
	visit[1]=true;
	prev[1]=0;
	bool flag=false;
	while (head<tail)
	{
		int tmp=queue[head];
		head++;
		for (int i=1;i<=m;i++)
		{
			if (map[tmp][i]>0 && !visit[i])
			{
				visit[i]=true;
				prev[i]=tmp;
				f[i]=min(f[tmp],map[tmp][i]);
				if (i==m)
				{
					flag=true;break;
				}
				queue[tail++]=i;
			}
		}
		if (flag) break;
	}
	if (f[m]>=MAX) return -1;
	else return f[m];
}

int Edmonds_Karp()
{
	int ans=0;
	while (1)
	{
		int tmp=BFS();
		if (tmp==-1) break;
		ans+=tmp;
		int now=m;
		while (prev[now]>0)
		{
			map[prev[now]][now]-=tmp;
			map[now][prev[now]]+=tmp;
			now=prev[now];
		}
	}
	return ans;
}
int main()
{
	while (scanf("%d%d",&n,&m)>0)
	{
		memset(map,0,sizeof(map));
		for (int i=1;i<=n;i++)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			map[x][y]+=z;
		}
		int res=Edmonds_Karp();
		printf("%d\n",res);
	}

