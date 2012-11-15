#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXNODE 2000
#define MAXEDGE MAXNODE*MAXNODE
#define MIN(a,b) ((a)<(b)?(a):(b))
#define OPPOSITE(x) (((x)&1)?((x)+1):((x)-1))
#define INFINIT ~0U>>1
using namespace std;

int n,m;
int N,S,T;
int begin[MAXNODE+1],end[MAXEDGE+1],next[MAXEDGE+1],c[MAXEDGE+1],cost[MAXEDGE+1],d[MAXNODE+1],cur[MAXNODE+1],isf[MAXNODE+1];
bool hash[MAXNODE+1];
int Count = 0;
int aug(int u,int f){
    if (u == T) return f;
    hash[u] = true;
    for (int now = cur[u]; now; now = next[now])
        if (c[now]&&!hash[end[now]]&&d[u] == d[end[now]]+cost[now])
            if (int tmp = aug(end[now],MIN(f,c[now])))
                return c[now] -= tmp,c[OPPOSITE(now)] += tmp,cur[u] = now,tmp;
    return 0;
}
bool modlabel(){
    int tmp = INFINIT;
    for (int i = 1; i<=N; i++)
        if (hash[i])
            for (int now = begin[i]; now; now = next[now])
                if (c[now]&&!hash[end[now]])
                    tmp = MIN(tmp,d[end[now]]+cost[now]-d[i]);
    if (tmp == INFINIT)
        return true;
    for (int i = 1; i<=N; i++)
        if (hash[i])
            hash[i] = false,d[i] += tmp;
    return false;
}

int q[123456];
int qtail,qhead;
bool visit[3210];

void spfa(int s){
	int u,i;
	memset(d,127,sizeof(d));
	memset(visit,0,sizeof(visit));
	qhead = qtail = 0;
	q[qhead] = s;
	d[s]=0;
	visit[s]=1;
	while (qhead <= qtail){
		u=q[qhead];
		qhead++;
		visit[u]=0;
		for (i=begin[u];i!=0;i=next[i])
			if (d[end[i]]>d[u]+cost[i] && isf[i] == 0){
				d[end[i]]=d[u]+cost[i];
				if (!visit[end[i]]) {
					visit[end[i]]=1;
					qtail++;
					q[qtail] = end[i];
				}
			}
	}
}
int CostFlow(){
    int costflow = 0,tmp;
    spfa(S);
    while (true){
        for (int i = 1; i<=N; i++)
            cur[i] = begin[i];
        while (tmp = aug(S,~0U>>1)){
            cout << tmp << ' ' << d[S] << endl;
            for (int i = 1;i <= N;i++)
                cout << d[i] << ' ';
            cout << endl;
            costflow += tmp*d[S];
            memset(hash,0,sizeof(hash));
        }
        if (modlabel())
            break;
    }
    return costflow;
}
void add_edge(int a,int b,int flow, int v){
    Count++; next[Count] = begin[a]; begin[a] = Count; end[Count] = b; c[Count] = flow; cost[Count] = v; isf[Count] = 0;
    Count++; next[Count] = begin[b]; begin[b] = Count; end[Count] = a; c[Count] = 0; cost[Count] = -v; isf[Count] = 1;
}

int a[1200];

int main(){
    int t;
    //freopen("Dout.txt","w",stdout);
    //freopen("din.txt","r",stdin);
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        Count = 0;
        memset(next,0,sizeof(next));
        memset(begin,0,sizeof(begin));
        memset(end,0,sizeof(end));
        memset(d,0,sizeof(d));
        memset(cur,0,sizeof(cur));
        scanf("%d",&n);
        for (int i = 1;i <= n;i++)
            scanf("%d",&a[i]);
        add_edge(2*n+2+1,0+1,2,0);
        add_edge(2*n+1+1,2*n+3+1,2,0);
        for (int i = 1;i <= n;i++)
        {
            add_edge(0+1,i*2-1+1,1,0);
            add_edge(i*2+1,2*n+1+1,1,0);
            add_edge(i*2-1+1,i*2+1,1,-1);
        }
        for (int i = 1;i <= n;i++)
        for (int j = i+1;j <= n;j++)
        {
            if (a[i] < a[j])
                add_edge(i*2+1,j*2-1+1,1,0);
        }
        S = 2*n+2+1;
        T = 2*n+3+1;
        N = 2*n+3+1;
        printf("Case #%d: %d\n",ft,-CostFlow());
    }
    return 0;
}
