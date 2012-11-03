#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

int t,ft;
int n,m,xi,yi,ti;
int ind[500],outd[500],map[500][500],b[500][500],c[500][500],pre[500],d[500];
int fullf,maxf;

bool test()
{
	int i;
	for (i = 1;i <= n;i++)
		if (abs(ind[i]-outd[i])%2 == 1)	return false;
	return true;
}

bool find()
{
	int i,j,head,tail;
	bool visit[500];
	memset(visit,false,sizeof(visit));
	head = tail = 1;
	d[1] = 0;
	while (head <= tail)
	{
		for (i = 0;i <= n+1;i++)
			if (visit[i] == false)
				if (c[d[head]][i] > 0)
				{
					visit[i] = true;
					pre[i] = d[head];
					if (i == n+1)
							return true;
					tail++;
					d[tail] = i;
				}
		head++;
	}
	return false;
}

void solve()
{
	int i,min;
	while (find() == true)
	{
		min = 0x7fffffff;
		for (i = n+1;i != 0;i = pre[i])
			if (min > c[pre[i]][i])
				min = c[pre[i]][i];
		for (i = n+1;i != 0;i = pre[i])
		{
			b[pre[i]][i] += min;
			b[i][pre[i]] = -b[pre[i]][i];
			c[pre[i]][i] = map[pre[i]][i]-b[pre[i]][i];
			c[i][pre[i]] = b[pre[i]][i];
		}
	}
	maxf = 0;
	for (i = 1;i <= n;i++)
	if (b[0][i] > 0)
		maxf += b[0][i];
}

int main()
{
	int i;
	scanf("%d",&t);
	for (ft = 1;ft <= t;ft++)
	{
		scanf("%d%d",&n,&m);
		memset(ind,0,sizeof(ind));
		memset(outd,0,sizeof(outd));
		memset(map,0,sizeof(map));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		for (i = 1;i <= m;i++)
		{
			scanf("%d%d%d",&xi,&yi,&ti);
			if (ti == 0)
			{
				map[xi][yi]++;
				c[xi][yi] = map[xi][yi];
			}
			ind[yi]++;
			outd[xi]++;
		}
		if (test() == false)	
		{
			printf("impossible\n");
			continue;
		}
		fullf = 0;
		for (i = 1;i <= n;i++)
			if (ind[i] > outd[i])
				c[i][n+1] = map[i][n+1] = (ind[i]-outd[i])/2;
			else
			{
				c[0][i] = map[0][i] = (outd[i]-ind[i])/2;
				fullf += c[0][i];
			}
		solve();
		if (maxf == fullf)
			printf("possible\n");
		else
			printf("impossible\n");
	}
	return 0;
}
