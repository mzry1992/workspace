#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100000;
struct Edge
{
	int to,next;
};
Edge edge[2*maxn];
int head[maxn],L;
int n;

void addedge(int u,int v)
{
	edge[L].to = v;
	edge[L].next = head[u];
	head[u] = L++;
}

typedef unsigned int uint;

struct hash_map
{
    const static int mod = 3000007;
    int head[mod];
    struct hash_tables
    {
        uint key1;
        int key2;
        int next;
    }ele[maxn*10];
    int N;
    void init()
    {
        memset(head,-1,sizeof(head));
        N = 0;
    }
    int find(uint x,int len)
    {
        int hashcode = x%mod;
        for (int i = head[hashcode];i != -1;i = ele[i].next)
            if (ele[i].key1 == x && ele[i].key2 == len)
                return i;
        return -1;
    }
    void insert(uint x,int len)
    {
        int tmp = x%mod;
        ele[N].key1 = x;
        ele[N].key2 = len;
        ele[N].next = head[tmp];
        head[tmp] = N++;
    }
};
 
hash_map hash;
uint ind[maxn];
int len;
uint s[maxn],mutpower[maxn+10],muts;

void DFS(int u,int fa,uint hashval)
{
	hashval = hashval*muts+ind[u];
	s[len++] = ind[u];
	uint tmp = hashval;
//	printf("u = %d, fa = %d, hashval = %u\n",u,fa,hashval);
	for (int i = 0;i < len;i++)
	{
		if (hash.find(tmp,len-i) != -1)
			break;
//		printf("    val = %u , len = %d\n",tmp,len-i);
		hash.insert(tmp,len-i);
		tmp -= s[i]*mutpower[len-i-1];
	}
	for (int i = head[u];i != -1;i = edge[i].next)
	{
		int v = edge[i].to;
		if (v != fa)
			DFS(v,u,hashval);
	}
	len--;
}

uint diffind[maxn];

int main()
{
	scanf("%d",&n);
	for (int i = 0;i < n;i++)
	{
		head[i] = -1;
		ind[i] = 0;
	}
	L = 0;
	for (int i = 0;i < n-1;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		u--;
		v--;
//		u = i;
//		v = i+1;
		addedge(u,v);
		addedge(v,u);
		ind[u]++;
		ind[v]++;
	}
	for (int i = 0;i < n;i++)
		diffind[i] = ind[i];
	sort(diffind,diffind+n);
	muts = unique(diffind,diffind+n)-diffind+1;
	for (int i = 0;i < n;i++)
		ind[i] = lower_bound(diffind,diffind+muts,ind[i])-diffind+1;
	hash.init();
	mutpower[0] = 1;
	for (int i = 1;i <= n;i++)
		mutpower[i] = mutpower[i-1]*muts;
	len = 0;
	DFS(0,0,0);
	printf("%d\n",hash.N);
	return 0;
}
