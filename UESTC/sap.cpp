#include <cstdio>
#define MMax 300000
#define NMax 20020
using namespace std;
#define OPT(_) (epool+(((_)-epool)^1))
struct edge{
	int e,f;
	edge *next;
}epool[MMax+MMax],*etop;
edge *E[NMax];
int N;
int level[NMax];
void addedge(int u,int v,int a,int b){
	etop->e=v;etop->f=a;etop->next=E[u];E[u]=etop;etop++;
	etop->e=u;etop->f=b;etop->next=E[v];E[v]=etop;etop++;
}
int mkLevel(){
	for (int i=(level[0]=0)+1;i<N;i++)level[i]=-1;
	static int Q[NMax],bot;
	Q[(bot=1)-1]=0;
	for (int top=0;top<bot;top++){int x=Q[top];
		for (edge *p=E[x];p;p=p->next)if (level[p->e]==-1 && p->f)
			level[Q[bot++]=p->e]=level[x]+1;
	}
	return level[N-1]!=-1;
}
int extend(int a,int b){
	int r=0,t;
	if (a==N-1)return b;
	for (edge *p=E[a];p && r<b;p=p->next)if (p->f && level[p->e]==level[a]+1){
		t=p->f;if (t>b-r)t=b-r;t=extend(p->e,t);
		r+=t;p->f-=t;OPT(p)->f+=t;
	}
	if (!r)level[a]=-1;
	return r;
}
int Dinic(){int ret=0,t;
	while (mkLevel())while ((t=extend(0,1000000000)))ret+=t;
	return ret;
}
int SAP(){
	static int d[NMax],g[NMax+1],Q[NMax];
	static edge *c[NMax],*pre[NMax];
	int ret=0,x=0,bot;
	for (int i=0;i<N;i++)c[i]=E[i],d[i]=g[i]=0;
	pre[g[N]=0]=NULL;
	Q[(bot=1)-1]=N-1;
	for (int i=0;i<bot;i++)for (edge *p=E[Q[i]];p;p=p->next)
		if (OPT(p)->f && p->e!=N-1 && d[p->e]==0)d[Q[bot++]=p->e]=d[Q[i]]+1;
	for (int i=0;i<N;i++)g[d[i]]++;
	while (d[0]<N){
		while (c[x] && (!c[x]->f || d[c[x]->e]+1!=d[x]))c[x]=c[x]->next;
		if (c[x]){
			pre[c[x]->e]=OPT(c[x]);
			x=c[x]->e;
			if (x==N-1){
				int t=~0u>>1;
				for (edge *p=pre[N-1];p;p=pre[p->e])if (t>OPT(p)->f)t=OPT(p)->f;
				for (edge *p=pre[N-1];p;p=pre[p->e])
					p->f+=t,OPT(p)->f-=t;
				ret+=t;
				x=0;
			}
		}else{
			int od=d[x];
			g[d[x]]--;
			d[x]=N;
			for (edge *p=c[x]=E[x];p;p=p->next)if (p->f && d[x]>d[p->e]+1)d[x]=d[p->e]+1;
			g[d[x]]++;
			if (x)x=pre[x]->e;
			if (!g[od])break;
		}
	}
	return ret;
}

int main()
{
    //需要的改动：N的值为总点数 0为源点 N-1为汇点 头指针清空
    //addedge用法：起点，终点，正向边流量，方向边流量
    //实测sap比dinic快1.7倍左右
	etop=epool;
	int n,m;
	scanf("%d%d",&n,&m);
	N=n+2;
	for (int i=0;i<N;i++)
        E[i]=NULL;
	for (int i=1;i<=n;i++)
	{
	    int x,y;
	    scanf("%d%d",&x,&y);
        addedge(0,i,x,0);
        addedge(i,N-1,y,0);
	}
	for (int i=0;i<m;i++)
	{
	    int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        addedge(x,y,z,z);
	}
	//printf("%d\n",Dinic());
	printf("%d\n",SAP());
	return 0;
}
