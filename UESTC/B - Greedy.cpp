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
}Map[1000800];
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
void spfa(int s){
	int u,i;
	memset(dis,127,sizeof(dis));
	memset(visit,0,sizeof(visit));
	memset(pre,255,sizeof(pre));
	queue <int> q;
	q.push(s);
	dis[s]=0;
	visit[s]=1;
	while (!q.empty()){
		u=q.front();
		//cout<<"u="<<u<<endl;
		q.pop();
		visit[u]=0;
		for (i=head[u];i!=-1;i=Map[i].next)//{cout<<i<<" "<<Map[i].to<<endl;
			//cout<<dis[Map[i].to]<<" "<<dis[u]<<" "<<Map[i].cost<<endl;
			if (dis[Map[i].to]>dis[u]+Map[i].cost && Map[i].capacity>Map[i].flow){
				dis[Map[i].to]=dis[u]+Map[i].cost;
				pre[Map[i].to]=i;
				//cout<<"A"<<i<<endl;
				if (!visit[Map[i].to]) {
					//cout<<"B"<<i<<endl;
					visit[Map[i].to]=1;
					q.push(Map[i].to);
				}
			}//}
	}
}
int mcmf(int s,int t,int &cost){
	int i,ans=0,max;
	while (1){
		//cout<<'a'<<endl;
		spfa(s);
		//if (pre[t]==-1 || ans==Tot) return ans;
		if (pre[t]==-1) return ans;
		max=Max;
		//cout<<max<<endl;
		for (i=pre[t];i!=-1;i=pre[Map[i^1].to])
			if (max>Map[i].capacity-Map[i].flow)
				max=Map[i].capacity-Map[i].flow;
		for (i=pre[t];i!=-1;i=pre[Map[i^1].to]){
			Map[i].flow+=max;
			Map[i^1].flow-=max;
			cost+=Map[i].cost*max;
		}
		//cout<<max<<endl;
		ans+=max;
	}
}

int n,m,q;
int v[1200];

int main(){
    while (scanf("%d",&n) != EOF)
    {
        L = -1;
        for (int i = 1;i <= n;i++)
            scanf("%d",&v[i]);
        scanf("%d",&m);
        for (int i=0;i<=m*8;i++)
            Map[i].next=-1;
        for (int i=0;i<=n*2;i++)
            head[i]=-1;
        for (int i = 1;i <= n;i++)
        {
            add_edge(i*2-1,i*2,1,-v[i]);
            add_edge(i*2-1,i*2,Max,0);
        }
        for (int i = 1;i <= m;i++)
        {
            int tu,tv;
            scanf("%d%d",&tu,&tv);
            add_edge(tu*2,tv*2-1,Max,0);
        }
        scanf("%d",&q);
        add_edge(0,1,q,0);
        int ans=0;
        mcmf(0,n*2,ans);
        printf("%d\n",-ans);
    }
}
