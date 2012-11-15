#include<stdio.h>
#include<string.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
#define Max 2139062143
using namespace std;

int head[3500],L,pre[3500],dis[3500],visit[3500];
struct Maps{
	int to,flow,capacity,cost,next;
}Map[1005000];
int T;

void add_edge(int x,int y,int f,int c){
	L++;
	Map[L].to=y;
	Map[L].capacity=f;
	Map[L].cost=c;
	Map[L].flow=0;
	Map[L].next=head[x];
	head[x]=L;
	L++;
	Map[L].to=x;
	Map[L].capacity=0;
	Map[L].cost=-c;
	Map[L].flow=0;
	Map[L].next=head[y];
	head[y]=L;
}

int q[123456];
int qtail,qhead;

void spfa(int s){
	int u,i;
	memset(dis,127,sizeof(dis));
	memset(visit,0,sizeof(visit));
	memset(pre,255,sizeof(pre));
	qhead = qtail = 10000;
	q[qhead] = s;
	dis[s]=0;
	visit[s]=1;
	int totd = 0;
	int td;
	while (qtail >= 0){
	    u = q[qtail];
	    qtail--;
		visit[u]=0;
		totd -= dis[u];
		for (i=head[u];i!=-1;i=Map[i].next)
			if (dis[Map[i].to]>dis[u]+Map[i].cost && Map[i].capacity>Map[i].flow){
				dis[Map[i].to]=dis[u]+Map[i].cost;
				pre[Map[i].to]=i;
				if (!visit[Map[i].to]) {
					visit[Map[i].to]=1;
					{
                        qtail++;
                        q[qtail] = Map[i].to;
                        totd += q[qtail];
					}
				}
			}
	}
}
int mcmf(int s,int t,int &cost){
	int i,ans=0,max;
	T = t;
	for (int jj = 1;jj <= 2;jj++)
	{
		spfa(s);
		max=Max;
		for (i=pre[t];i!=-1;i=pre[Map[i^1].to])
			if (max>Map[i].capacity-Map[i].flow)
				max=Map[i].capacity-Map[i].flow;
		for (i=pre[t];i!=-1;i=pre[Map[i^1].to]){
			Map[i].flow+=max;
			Map[i^1].flow-=max;
			cost+=Map[i].cost*max;
		}
		ans+=max;
	}
	return ans;
}

int n,a[1200];

int main(){
    int t;
    //freopen("Dout.txt","w",stdout);
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        for (int i=0;i<=2+3*n+n*n;i++)
            Map[i].next=-1;
        for (int i=0;i<=2*n+4;i++)
            head[i]=-1;
        L=-1;
        for (int i = 1;i <= n;i++)
            scanf("%d",&a[i]);
        add_edge(2*n+2,0,2,0);
        add_edge(2*n+1,2*n+3,2,0);
        for (int i = 1;i <= n;i++)
        {
            add_edge(0,i*2-1,1,0);
            add_edge(i*2,2*n+1,1,0);
            add_edge(i*2-1,i*2,1,-1);
        }
        for (int i = 1;i <= n;i++)
        for (int j = i+1;j <= n;j++)
        {
            if (a[i] < a[j])
                add_edge(i*2,j*2-1,1,0);
        }
        int ans = 0;
        mcmf(2*n+2,2*n+3,ans);
        printf("Case #%d: %d\n",ft,-ans);
    }
}
