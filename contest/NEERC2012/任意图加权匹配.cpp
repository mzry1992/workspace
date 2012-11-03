#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;
#define N 229
int G[N][N];
int cnt_node;
int dist[N];
int rec[N],cr,M[N],P[N];
bool vst[N];
const int inf = 0x3f3f3f3f;
bool spfa(int u)
{
    rec[cr++]=u;
    if(vst[u]) return true;
    vst[u]=true;
    int v;
    for(v=0; v<cnt_node; v++)
    {
        if(v!=u&&M[u]!=v&&!vst[v])
        {
            int w=M[v];
            if(dist[w]<dist[u]+G[u][v]-G[v][w])
            {
                dist[w]=dist[u]+G[u][v]-G[v][w];
                if(spfa(w))
                {
                    return true;
                }
            }
        }
    }
    cr--;
    vst[u]=false;
    return false;
}
int match()
{
    int i;
    for(i=0; i<cnt_node; i++) P[i]=i;
    for(i=0; i<cnt_node; i+=2) M[i]=i+1,M[i+1]=i;
    int cnt=0;
    while(1)
    {
        memset(dist,0,sizeof(dist));
        cr=0;
        int i;
        bool fd=false;
        memset(vst,0,sizeof(vst));
        for(i=0; i<cnt_node; i++)
        {
            if(spfa(P[i]))
            {
                fd=true;
                int j;
                int nx=M[rec[cr-1]];
                for(j=cr-2; rec[j]!=rec[cr-1]; j--)
                {
                    M[nx]=rec[j];
                    int tmp=nx;
                    nx=M[rec[j]];
                    M[rec[j]]=tmp;
                }
                M[nx]=rec[j];
                M[rec[j]]=nx;
                break;
            }
        }
        if(!fd)
        {
            cnt++;
            if(cnt>=3) break;
            random_shuffle(P,P+cnt_node);
        }
    }
    int sum=0;
    for(i=0; i<cnt_node; i++)
    {
        int v=M[i];
        if(i<v)
        {
            sum+=G[i][v];
        }
    }
    return sum;
}

char mp[120][120];
int id[120][120];

int main()
{
	int n,m;
	while (true)
	{
		scanf("%d%d",&n,&m);
		if (n == 0 && m == 0)	break;
		for (int i = 0;i < n;i++)
			scanf("%s",mp[i]);
		cnt_node = 0;
		for (int i = 0;i < n;i++)
			for (int j = 0;j < m;j++)
				if (mp[i][j] == 'H' || mp[i][j] == 'm')
					id[i][j] = cnt_node++;

		for (int i = 0;i < cnt_node;i++)
			for (int j = 0;j < cnt_node;j++)
				G[i][j] = -100000000;

		for (int i = 0;i < n;i++)
			for (int j = 0;j < m;j++)
				if (mp[i][j] == 'H' || mp[i][j] == 'm')
					for (int x = 0;x < n;x++)
						for (int y = 0;y < m;y++)
							if (mp[x][y] == 'H' || mp[x][y] == 'm')
								if (mp[x][y] != mp[i][j])
									G[id[i][j]][id[x][y]] = G[id[x][y]][id[i][j]] = -(abs(x-i)+abs(y-j));

//		for (int i = 0;i < cnt_node;i++)
//		{
//			for (int j = 0;j < cnt_node;j++)
//				printf("%d ",G[i][j]);
//			printf("\n");
//		}
		printf("%d\n",-match());
	}
	return 0;
}
