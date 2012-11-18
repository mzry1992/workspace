#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int dist[100001];

int main()
{
	/*for (int i = 1;i <= 10000;i++)
	{
		int cnt = 0;
		for (int j = 1;j*j <= i;j++)
			if (i%j == 0)
			{
				cnt++;
				if (j*j < i)
					cnt++;
			}
		printf("i = %5d, cnt = %5d\n",i,cnt);
	}*/
	int a,b;
	scanf("%d%d",&a,&b);
	memset(dist,-1,sizeof(dist));
	dist[a] = 0;
	queue<int> Q;
	Q.push(a);
	while (!Q.empty())
	{
		int now = Q.front();
		Q.pop();
		for (int i = 1;i*i <= now;i++)
			if (now%i == 0)
			{
				if (now+i <= b && dist[now+i] == -1)
				{
					dist[now+i] = dist[now]+1;
					Q.push(now+i);
				}
				if (i*i < now)
				{
					if (now+now/i <= b && dist[now+now/i] == -1)
					{
						dist[now+now/i] = dist[now]+1;
						Q.push(now+now/i);
					}
				}
			}
	}
	printf("%d\n",dist[b]);
	return 0;
}
