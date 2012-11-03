#include<cstdio>
#include<cstring>
#include<algorithm>
#include<time.h>
using namespace std;
struct kind
{
	int p,am;
	int c[1005],w[1005];
};
int f[51][100005];
int ff[100005];
bool can[52][12];
struct kind g[70];
int main()
{
	int n,v;
	while (scanf("%d%d",&n,&v)>0)
	{   
		memset(can,true,sizeof(can));
		for (int i=0;i<n;i++) 
		{
			scanf("%d%d",&g[i].p,&g[i].am);
			for (int j=0;j<g[i].am;j++)
				scanf("%d%d",&g[i].c[j],&g[i].w[j]);
			for (int j=0;j<g[i].am-1;j++)
				for (int k=j+1;k<g[i].am;k++)
				{
					if (g[i].c[j]<=g[i].c[k] && g[i].w[j]>=g[i].w[k])
						can[i][k]=false;
				}
		}
		/*memset(ff,0,sizeof(ff));
		memset(f,0,sizeof(f));*/
		for (int i=0;i<n;i++)
		    for (int j=0;j<v-g[i].p;j++)
		        f[i][j]=0;
        for (int i=0;i<v;i++) ff[i]=0;
		for (int i=0;i<n;i++)
			for (int j=0;j<g[i].am;j++)
			{
				if (can[i][j])
				{
					for (int k=v-g[i].p;k>=g[i].c[j];k--)
						f[i][k]=max(f[i][k],f[i][k-g[i].c[j]]+g[i].w[j]);
				}
			}
		for (int i=0;i<n;i++)
			for (int j=v;j>=g[i].p;j--)
				for (int k=0;k<=j-g[i].p;k++)
					ff[j]=max(ff[j],ff[j-g[i].p-k]+f[i][k]);
		printf("%d\n",ff[v]);
	}
}
