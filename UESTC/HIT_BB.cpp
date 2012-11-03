#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct graph
{
	int next,to,cost;
}g[1400000];
int n,m,tot,totm,gs,gt;
int ha[1234567];
char aa[500],bb[500];

unsigned int ELFHash(char *str)
{
         unsigned int hash  = 0;
         unsigned int x     = 0;

         while (*str)
         {
                 hash = (hash << 4) + (*str++);
                 if ((x = hash & 0xF0000000L) != 0)
                 {
                         hash ^= (x >> 24);
                         hash &= ~x;
                 }
         }

         return (hash & 0x7FFFFFFF);
}

void addEdge(int u,int v,int c)
{
	totm++;
	g[totm+n].next = g[u].next;
	g[totm+n].to = v;
	g[totm+n].cost = c;
	g[u].next = totm+n;
}

struct two
{
	int now,use;
};

long long dis[123456][2];
queue<two> d;
bool visit[123456][2];
	
long long SPFA()
{
	while (!d.empty())
	      d.pop();
	for (int i = 1;i <= n;i++)
		dis[i][0] = dis[i][1] = 123456789101LL;
	memset(visit,false,sizeof(visit));
	two tt;
	tt.now = gs;	tt.use = 0;
	d.push(tt);
	visit[gs][0] = true;
	dis[gs][0] = 0;
	while (!d.empty())
	{
		two tt = d.front();
		int u = tt.now;
		int us = tt.use;
		//cout << '<' << u << ' ' << us << '>' << endl;
		//cout << dis[u][us] << endl;
		d.pop();
		visit[u][us] = false;
		for (int nex = g[u].next;nex != 0;nex = g[nex].next)
		{
			int v = g[nex].to;
			int c = g[nex].cost;
			if (us == 0)
			{
				if (dis[v][0] > dis[u][0]+c)
				{
					dis[v][0] = dis[u][0]+c;
					if (visit[v][0] == false)
					{
						visit[v][0] = true;
						two temp;
						temp.now = v;	temp.use = 0;
						d.push(temp);
					}
				}
				if (dis[v][1] > dis[u][0]+c/2)
				{
					dis[v][1] = dis[u][0]+c/2;
					if (visit[v][1] == false)
					{
						visit[v][1] = true;
						two temp;
						temp.now = v;	temp.use = 1;
						d.push(temp);
					}
				}
			}
			else
			if (dis[v][1] > dis[u][1]+c)
			{
				dis[v][1] = dis[u][1]+c;
				if (visit[v][1] == false)
				{
					visit[v][1] = true;
					two temp;
					temp.now = v;	temp.use = 1;
					d.push(temp);
				}
			}
		}
	}
	if (dis[gt][1] == 123456789101LL)
		dis[gt][1] = -1;
	return dis[gt][1];
}

int main()
{
	while (scanf("%d%d",&n,&m) != EOF)
	{
		memset(ha,0,sizeof(ha));
		memset(g,0,sizeof(g));
		tot = totm = 0;
		for (int i = 1;i <= m;i++)
		{
			char s1[500],s2[500];
			int price;
			scanf("%s%s%d",&s1,&s2,&price);
			int u,v;
			int temp = ELFHash(s1);
			temp %= 1000007;
			if (ha[temp] == 0)
			{
				tot++;
				ha[temp] = tot;
				u = tot;
				g[u].cost = g[u].next = g[u].to = 0;
			}
			else	u = ha[temp];
			temp = ELFHash(s2);
			temp %= 1000007;
			if (ha[temp] == 0)
			{
				tot++;
				ha[temp] = tot;
				v = tot;
				g[v].cost = g[v].next = g[v].to = 0;
			}
			else
				v = ha[temp];
			if (u != v)
			{
    			addEdge(u,v,price);
    			//addEdge(v,u,price);
            }
		}
		scanf("%s%s",&aa,&bb);
		bool flag = true;
		int temp = ELFHash(aa);
		temp %= 1000007;
		if (ha[temp] == 0)
		{
			tot++;
			ha[temp] = tot;
			g[tot].cost = g[tot].next = g[tot].to = 0;
			gs = tot;
			flag = false;
		}
		else	gs = ha[temp];
		temp = ELFHash(bb);
		temp %= 1000007;
		if (ha[temp] == 0)
		{
			tot++;
			ha[temp] = tot;
			g[tot].cost = g[tot].next = g[tot].to = 0;
			gt = tot;
			flag = false;
		}
		else	gt = ha[temp];
		if (flag == true)
		{
           if (gs != gt)      
	 	      printf("%I64d\n",SPFA());
           else
              printf("0\n");
        }
        else
        {
           if (gs != gt) 
              printf("-1\n");
           else
              printf("0\n");  
        }
	}
}
